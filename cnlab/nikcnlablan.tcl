# lan implemntation
# set lan1 [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms Queue/DropTail LL MAC/Csma/Cd Channel]
# By creating lan you donot have to create the links b/w the nodes of the lan
# newLan is a procedure whose arguments are the nodes that will be present in lan
# lan1 is the name of lan


# congestion window take output
# set tcp1 [new Agent/TCP]
# $tcp set window_ 15                					sets the ssthresh value
# proc plotwindow {tcp outp} {							procedure named as plotwindow with 2 argument: tcp as the tcp object and outp as output file
#	global ns											
#	set t1 [$ns now]									assign the current time to t1
#	set cwnd [$tcp set cwnd_]							whenever there is one argument in set then it returns that variables value
#	puts $outp "$t1 $cwnd"                   			 
#	$ns at [expr $t1 + 0.1] "plotwindow $tcp $outp"		
# }
# $ns at 0.0 "plotwindow $tcp $outp"


#create simulator class object
set ns [new Simulator]
#opening files such as trace and nam file always do it in starting
set nt [open demo1.tr w]
$ns trace-all $nt
set nf [open namfile1.nam w]
$ns namtrace-all $nf

#file for the congestion window output
set outp1 [open congestionoutput w]

#create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

#links 
$ns simplex-link $n0 $n2 1.5Mbps 8ms DropTail
$ns simplex-link-op $n0 $n2 orient right-down
$ns queue-limit $n0 $n2 5
$ns duplex-link $n1 $n2 2.5Mbps 10ms DropTail
$ns duplex-link-op $n1 $n2 orient right-up
$ns queue-limit $n1 $n2 7
$ns duplex-link $n2 $n3 2.5Mbps 5ms DropTail
$ns duplex-link-op $n2 $n3 orient right
$ns queue-limit $n2 $n3 5
#$ns duplex-link $n3 $n5 2.5Mbps 5ms DropTail
#$ns duplex-link-op $n3 $n5 orient right-down
#$ns queue-limit $n3 $n5 5
#$ns duplex-link $n4 $n5 2.5Mbps 5ms DropTail
#$ns duplex-link-op $n4 $n5 orient left-down
#$ns queue-limit $n4 $n5 5

set lan1 [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms Queue/DropTail LL MAC/Csma/Cd Channel]

#agents
set udpsrc1 [new Agent/UDP]
set tcpsrc1 [new Agent/TCP]
set udpdest [new Agent/Null]
set tcpdest1 [new Agent/TCPSink]
#attach agents
$ns attach-agent $n0 $udpsrc1
$ns attach-agent $n1 $tcpsrc1
$ns attach-agent $n5 $udpdest
$ns attach-agent $n5 $tcpdest1
$ns connect $udpsrc1 $udpdest
$ns connect $tcpsrc1 $tcpdest1
#create traffic
set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $udpsrc1
$traffic1 set packetSize_ 50B
$traffic1 set interval_ 1.5ms
set traffic2 [new Application/FTP]
$traffic2 attach-agent $tcpsrc1
$traffic2 set packetsize_ 100B
$traffic2 set interval_ 2.5ms
proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam namfile1.nam
exit 0
}

$tcpsrc1 set window_ 15
proc plotwindow {tcp1} {
	global ns outp1
	set t1 [$ns now]
	set cwnd [$tcp1 set cwnd_]
	puts $outp1 "$t1 $cwnd"
	$ns at [expr $t1 + 0.1] "plotwindow $tcp1"
}

$ns at 0.0 "plotwindow $tcpsrc1"

#scheduling of tasks
$ns at 1.0 "$traffic1 start"
$ns at 2.0 "$traffic2 start"
$ns at 3.0 "$traffic1 stop"
$ns at 3.5 "$traffic2 stop"
$ns at 4.5 "finish"
$ns run

