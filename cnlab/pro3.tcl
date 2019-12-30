set ns [new Simulator]
set nt [open pro3.txt w]
$ns trace-all $nt
set nf [open pro3nam.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
$ns simplex-link $n0 $n1 2Mbps 1ms DropTail
$ns simplex-link $n0 $n1 2Mbps 1ms Droptail
set src [new Agent/UDP]
$ns attach-agent $n0 $src
set dest [new Agent/UDP]
$ns attach-agent $n1 $dest
$ns connect $src $dest


set traffic [new Application/Traffic/CBR]
$traffic attach-agent $src
$traffic set packetSize_ 500B
$traffic set interval_ 2ms

$ns attach-agent $n1 $src
$ns attach-agent $n0 $dest

set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src
$traffic2 set packetSize_ 500B
$traffic2 set interval_ 2ms
proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam pro3nam.nam
exit 0
}

$ns at 1.0 "$traffic start"
$ns at 4.0 "$traffic stop"

$ns connect $src $dest1
$ns at 5.3 "$traffic2 start"

$ns at 5.7 "$traffic2 stop"

$ns at 6.0 "finish"
$ns run

