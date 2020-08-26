#!/usr/bin/gnuplot
set style data lines
set xrange [0:10000]
set yrange [-0.1:1.1]
plot 'ambientPressure.dat' lw 2
replot 'ambientTemperature.dat' lw 2
replot 'adiabaticDryTemperature.dat' lw 2
replot 'adiabaticWetTemperature.dat' lw 2
replot 'ambientConcentration.dat' lw 2
pause -1