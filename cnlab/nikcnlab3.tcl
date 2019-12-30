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
$n0 color "blue"
$n1 color "red"
$n0 shape "square"
$n1 shape "square"
$n3 shape "square"
$n2 shape "circle"
#links 
$ns simplex-link $n0 $n2 1.5Mbps 8ms DropTail
$ns simplex-link-op $n0 $n2 color green
$ns simplex-link-op $n0 $n2 orient right-down
$ns queue-limit $n0 $n2 5
$ns simplex-link $n1 $n2 2.5Mbps 10ms DropTail
$ns simplex-link-op $n1 $n2 color green
$ns simplex-link-op $n1 $n2 orient right-up
$ns queue-limit $n1 $n2 7
$ns simplex-link $n2 $n3 2.5Mbps 5ms DropTail
$ns simplex-link-op $n2 $n3 color green
$ns simplex-link-op $n2 $n3 orient right
$ns queue-limit $n2 $n3 5
#agents
set src1 [new Agent/UDP]
set src2 [new Agent/UDP]
set dest [new Agent/Null]
#attach agents
$ns attach-agent $n0 $src1
$ns attach-agent $n1 $src2
$ns attach-agent $n3 $dest
$ns connect $src1 $dest
$ns connect $src2 $dest
#create traffic
set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src1
$traffic1 set packetSize_ 50B
$traffic1 set interval_ 1.5ms
set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src2
$traffic2 set packetsize_ 100B
$traffic2 set interval_ 2.5ms

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
$ns at 3.0 "$traffic1 stop"
$ns at 4.0 "$traffic2 stop"
$ns at 4.5 "finish"
$ns run

