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
#link establish
$ns duplex-link $n0 $n1 2Mbps 2ms DropTail
#source and destination agents 
set src [new Agent/UDP]
$ns attach-agent $n0 $src
set dest [new Agent/Null]
$ns attach-agent $n1 $dest
$ns connect $src $dest
#create traffic from source
set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src
$traffic1 set packetSize_ 500B
$traffic1 set interval_ 2ms
#source and destination agents
set src1 [new Agent/UDP]
$ns attach-agent $n1 $src1
set dest1 [new Agent/Null]
$ns attach-agent $n0 $dest1
$ns connect $src1 $dest1
#create traffic from dest
set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src1
$traffic2 set packetSize_ 500B
$traffic2 set interval_ 2ms
#finish function
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

