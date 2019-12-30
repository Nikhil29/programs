#create simulator class object
set ns [new Simulator]
#opening files such as trace and nam file always do it in starting
set nt [open demo1.tr w]
$ns trace-all $nt
set nf [open namfile1.nam w]
$ns namtrace-all $nf
#create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
$n0 color "blue"
$n1 color "red"
$n0 shape "square"
$n1 shape "square"
$n4 shape "square"
$n5 shape "square"
$n3 shape "circle"
$n2 shape "circle"
#links 
$ns simplex-link $n0 $n2 1.5Mbps 8ms DropTail
$ns simplex-link-op $n0 $n2 color green
$ns simplex-link-op $n0 $n2 orient right-down
$ns queue-limit $n0 $n2 5
$ns duplex-link $n1 $n2 2.5Mbps 10ms DropTail
$ns duplex-link-op $n1 $n2 color green
$ns duplex-link-op $n1 $n2 orient right-up
$ns queue-limit $n1 $n2 7
$ns duplex-link $n2 $n3 2.5Mbps 5ms DropTail
$ns duplex-link-op $n2 $n3 color green
$ns duplex-link-op $n2 $n3 orient right
$ns queue-limit $n2 $n3 5
$ns duplex-link $n3 $n4 2.5Mbps 5ms DropTail
$ns duplex-link-op $n3 $n4 color green
$ns duplex-link-op $n3 $n4 orient right-down
$ns queue-limit $n3 $n4 5
$ns duplex-link $n3 $n5 2.5Mbps 5ms DropTail
$ns duplex-link-op $n3 $n5 color green
$ns duplex-link-op $n3 $n5 orient right-up
$ns queue-limit $n3 $n5 5
#agents
set udpsrc1 [new Agent/UDP]
set tcpsrc1 [new Agent/TCP]
set tcpsrc2 [new Agent/TCP]
set udpdest [new Agent/Null]
set tcpdest1 [new Agent/TCPSink]
set tcpdest2 [new Agent/TCPSink]
#attach agents
$ns attach-agent $n0 $udpsrc1
$ns attach-agent $n1 $tcpsrc1
$ns attach-agent $n4 $tcpsrc2
$ns attach-agent $n5 $udpdest
$ns attach-agent $n5 $tcpdest1
$ns attach-agent $n5 $tcpdest2
$ns connect $udpsrc1 $udpdest
$ns connect $tcpsrc1 $tcpdest1
$ns connect $tcpsrc2 $tcpdest2
#create traffic
set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $udpsrc1
$traffic1 set packetSize_ 50B
$traffic1 set interval_ 1.5ms
set traffic2 [new Application/FTP]
$traffic2 attach-agent $tcpsrc1
$traffic2 set packetsize_ 100B
$traffic2 set interval_ 2.5ms
set traffic3 [new Application/FTP]
$traffic3 attach-agent $tcpsrc2
$traffic3 set packetsize_ 100B
$traffic3 set interval_ 2.5ms
proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam namfile1.nam
exit 0
}
#scheduling of tasks
$ns at 1.0 "$traffic1 start"
$ns at 2.0 "$traffic2 start"
$ns at 0.5 "$traffic3 start"
$ns at 3.0 "$traffic1 stop"
$ns at 3.5 "$traffic2 stop"
$ns at 4.0 "$traffic3 stop"
$ns at 4.5 "finish"
$ns run

