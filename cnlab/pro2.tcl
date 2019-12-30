set ns [new Simulator]
set nt [open demo1.txt w]
$ns trace-all $nt
set nf [open namfile.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 2Mbps 1ms DropTail

set src [new Agent/UDP]
$ns attach-agent $n0 $src


set dest [new Agent/Null]
$ns attach-agent $n1 $dest


$ns connect $src $dest


set traffic [new Application/Traffic/CBR]
$traffic attach-agent $src
$traffic set packetSize_ 50B
$traffic set interval_ 2ms



set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src
$traffic2 set packetSize_ 50B
$traffic2 set interval_ 2ms
proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam namfile.nam
exit 0
}

$ns at 1.0 "$traffic start"
$ns at 4.0 "$traffic stop"
$ns attach-agent $n1 $src1
$ns attach-agent $n0 $dest
$ns connect $src1 $dest
$ns at 5.3 "$traffic2 start"
$ns at 6.7 "$traffic2 stop"
$ns at 7.0 "finish"
$ns run

