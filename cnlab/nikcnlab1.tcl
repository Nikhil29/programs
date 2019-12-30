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
$ns simplex-link $n0 $n1 2Mbps 2ms DropTail
#source and destination agents
set src [new Agent/UDP]
$ns attach-agent $n0 $src
set dest [new Agent/Null]
$ns attach-agent $n1 $dest
$ns connect $src $dest
set traffic [new Application/Traffic/CBR]
$traffic attach-agent $src
$traffic set packetSize_ 500B
$traffic set interval_ 2ms
#finish function
proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam namfile1.nam
exit 0
}
#scheduling of tasks
$ns at 1.0 "$traffic start"
$ns at 2.0 "$traffic stop"
$ns at 2.5 "finish"
$ns run

