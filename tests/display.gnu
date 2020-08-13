#!/usr/bin/gnuplot
set style data lines
set xrange [0:10000]
set yrange [-0.1:1.1]
plot 'ambientPressure.dat' lw 1
replot 'ambientTemperature.dat' lw 1
replot 'adiabaticDryTemperature.dat' lw 1
replot 'adiabaticWetTemperature.dat' lw 1
pause -1