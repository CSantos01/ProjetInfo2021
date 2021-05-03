set title "Tracé de la distance au cours du temps entre 2 conditions initiales"
set xlabel "t"
set ylabel "distance"
plot "distance.out" using 1:2 with lines title "Courbe de la distance"
set terminal postscript color
set output "TracéTemporelDistance.ps"
replot
set terminal x11