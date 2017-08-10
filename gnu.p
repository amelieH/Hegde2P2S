set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Example"
set xlabel "Player 1"
set ylabel "Player 2"
set xr [0.0:1.0]
set yr [0.0:1.0]
plot "out-s28925691.dat" using 1:2 with linespoints,\
"out-s66433441.dat" using 1:2 with linespoints,\
"out-s68362598.dat" using 1:2 with linespoints, \
"out-s145532761.dat" using 1:2 with linespoints,\
"out-s247074805.dat" using 1:2 with linespoints, \
"out-s400151788.dat" using 1:2 with linespoints,\
"out-s520932930.dat" using 1:2 with linespoints, \
"out-s763654014.dat" using 1:2 with linespoints,\
"out-s822784415.dat" using 1:2 with linespoints,\
"out-s890459872.dat" using 1:2 with linespoints,\
"out-s1028169396.dat" using 1:2 with linespoints,\
"out-s1040043610.dat" using 1:2 with linespoints, \
"out-s1269870926.dat" using 1:2 with linespoints,\
"out-s1500357984.dat" using 1:2 with linespoints, \
"out-s1579802159.dat" using 1:2 with linespoints,\
"out-s1643550337.dat" using 1:2 with linespoints, \
"out-s1789614810.dat" using 1:2 with linespoints,\
"out-s1906706780.dat" using 1:2 with linespoints, \
"out-s2002830094.dat" using 1:2 with linespoints,\
"out-s2132723841.dat" using 1:2 with linespoints

plot "out-s1643550337.dat" using 1:2 with linespoints
