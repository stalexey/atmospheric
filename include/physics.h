#pragma once

#include <cmath>

static constexpr double SEA_LEVEL_TEMPERATURE = 288.15; // [K]
static constexpr double SEA_LEVEL_PRESSURE = 101325;    // [Pa]

static constexpr double L = 0.0065;    // lapse rate [K/m]
static constexpr double R = 8.31447;   // universal gas constant [J/(mol*K)]
static constexpr double M = 0.0289644; // molar mass of dry air [kg/mol]
static constexpr double g = 9.8;       // gravity [m/s^2]

static constexpr double AIR_GAMMA = 1.4;    // dry air heat capacity ratio
static constexpr double VAPOR_GAMMA = 1.33; // water vapor heat capacity ratio

template <class T>
T
sampleTemperature(const T height)
{
    return SEA_LEVEL_TEMPERATURE - height * L;
}

template <class T>
T
samplePressure(const T height)
{
    return SEA_LEVEL_PRESSURE * std::pow(1.0f - L * height / SEA_LEVEL_TEMPERATURE, g * M / (R * L));
}

template <class T>
T
sampleAdiabaticTemperature(const T height, const T gamma)
{
    const T pressureScale = samplePressure(height) / SEA_LEVEL_PRESSURE;
    return SEA_LEVEL_TEMPERATURE * std::pow(pressureScale, (gamma - 1.0f) / gamma);
}
