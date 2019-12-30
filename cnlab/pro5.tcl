set ns [ new Simulator ]
set nt [open demo3.tr w ]
$ns trace-all $nt
set nf [open namfile.nam w]
$ns namtrace-all $nf
set n0 [ $ns node ]
set n1 [ $ns node ]
set n2 [ $ns node ]
set n3 [ $ns node ]
set n4 [ $ns node ]
set n5 [ $ns node ]
$ns simplex-link $n0 $n2 3Mbps 3ms DropTail
$ns queue-limit $n0 $n2 5

$ns duplex-link $n1 $n2 1.5Mbps 1ms DropTail


$ns duplex-link $n2 $n3 2Mbps 1ms DropTail
$ns duplex-link $n5 $n3 2Mbps 1ms DropTail
$ns duplex-link $n3 $n4 2Mbps 1ms DropTail


set src [ new Agent/UDP ]
$ns attach-agent $n0 $src
set src1 [ new Agent/TCP ]
$ns attach-agent $n1 $src1
set src2 [ new Agent/TCP ]
$ns attach-agent $n5 $src2


set fdest [ new Agent/TCPSink ]
set fdestudp [ new Agent/Null ]
set fdest1 [ new Agent/TCPSink ]
$ns attach-agent $n4 $fdest
$ns attach-agent $n4 $fdestudp
$ns attach-agent $n4 $fdest1
$ns connect $src $fdestudp


set traffic [ new Application/Traffic/CBR ]
$traffic attach-agent $src
$traffic set packetSize_ 50B
$traffic set interval_ 1.5ms


set traffic2 [ new Application/FTP ]
$traffic2 attach-agent $src1
$traffic2 set packetSize_ 50B
$traffic2 set interval_ 2ms

set traffic3 [ new Application/FTP ]
$traffic2 attach-agent $src2
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

$ns connect $src1 $fdest
$ns at 5.3 "$traffic2 start"
$ns at 7.0 "$traffic2 stop"

$ns connect $src2 $fdest1
$ns at 7.5 "$traffic3 start"

$ns at 9.0 "$traffic3 stop"

$ns at 9.5 "finish"
$ns run


