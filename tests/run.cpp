#include <utils.h>
#include <physics.h>
#include <grid.h>
#include <omp.h>

#include <fstream>
#include <iostream>
#include <string>

using T = double;

const T DOMAIN_SIZE = 10000.0f; // 10km
const int SAMPLES = 500;
const T DX = DOMAIN_SIZE / SAMPLES;

void
saveData(const GridData<T>& gridData, std::string fileName)
{
    std::ofstream file;
    file.open(fileName.append(".dat"));
    for (int i = 0; i < gridData.size(); i++) {
        file << gridData.position(i) << " " << gridData[i] << std::endl;
    }
    file.close();
}

int
main()
{
#pragma omp parallel
#pragma omp master
    std::cout << "Running on " << omp_get_num_threads() << " threads" << std::endl;

    const Grid<T> grid(DOMAIN_SIZE, SAMPLES);
    GridData<T> ambientTemperatureData(grid);
    GridData<T> ambientPressureData(grid);
    GridData<T> adiabaticDryTemperatureData(grid);
    GridData<T> adiabaticWetTemperatureData(grid);

#pragma omp parallel for
    for (int i = 0; i < grid.samples(); ++i) {
        const T height = grid.position(i);
        ambientTemperatureData[i] = sampleTemperature(height) / SEA_LEVEL_TEMPERATURE;
        ambientPressureData[i] = samplePressure(height) / SEA_LEVEL_PRESSURE;
        adiabaticDryTemperatureData[i] = sampleAdiabaticTemperature(height, AIR_GAMMA) / SEA_LEVEL_TEMPERATURE;
        adiabaticWetTemperatureData[i] = sampleAdiabaticTemperature(height, VAPOR_GAMMA) / SEA_LEVEL_TEMPERATURE;
    }

    saveData(ambientTemperatureData, "ambientTemperature");
    saveData(ambientPressureData, "ambientPressure");
    saveData(adiabaticDryTemperatureData, "adiabaticDryTemperature");
    saveData(adiabaticWetTemperatureData, "adiabaticWetTemperature");

    return 0;
}
