set ns [ new Simulator ]
set nt [ open demo2.tr w ]
$ns trace-all $nt
set nf [open namfile.nam w]
$ns namtrace-all $nf
set n0 [ $ns node ]
set n1 [ $ns node ]
set n2 [ $ns node ]
set n3 [ $ns node ]
$ns simplex-link $n0 $n2 3Mbps 3ms DropTail
$ns queue-limit $n0 $n2 5
$ns simplex-link $n1 $n2 1.5Mbps 1ms DropTail
$ns queue-limit $n1 $n2 7
$ns simplex-link $n2 $n3 2Mbps 1ms DropTail
$ns queue-limit $n2 $n3 5
set src [ new Agent/UDP ]
$ns attach-agent $n0 $src
set src1 [ new Agent/UDP ]
$ns attach-agent $n1 $src1

#set dest [new Agent/UDP]
#$ns attach-agent $n2 $dest
#$ns connect $src $dest
#$ns connect $src1 $dest

set fdest [ new Agent/Null ]
$ns attach-agent $n3 $fdest

$ns connect $src $fdest


set traffic [ new Application/Traffic/CBR ]
$traffic attach-agent $src
$traffic set packetSize_ 50B
$traffic set interval_ 1.5ms


set traffic2 [ new Application/Traffic/CBR ]
$traffic2 attach-agent $src1
$traffic2 set packetSize_ 50B
$traffic2 set interval_ 2ms

set traffic3 [ new Application/Traffic/CBR ]
$traffic3 attach-agent $fdest
$traffic3 set packetSize_ 50B
$traffic3 set interval_ 2ms

proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam namfile.nam
exit 0
}

$ns at 1.0 "$traffic start"
$ns at 4.0 "$traffic stop"

$ns connect $src1 $fdest
$ns at 5.3 "$traffic2 start"

$ns at 6.0 "$traffic2 stop"

$ns at 6.5 "finish"
$ns run


