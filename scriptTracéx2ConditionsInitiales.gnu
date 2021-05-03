set title "Tracé temporel de x pour 2 conditions initiales"
set xlabel "t"
set ylabel "x(t)"
plot "file.out" using 1:2 linecolor 1 title "Première condition initiale" with lines
replot "file+.out" using 1:2 linecolor 2 title "Condition Initiale Décalée" with lines
set terminal postscript color
set output "TracéTemporelx2Conditions.ps"
replot
set terminal x11