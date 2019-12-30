set ns [new Simulator]
#tell that we are using multicating.
$ns multicast

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

#link
$ns duplex-link $n0 $n1 2.5Mbps 10ms DropTail
$ns duplex-link-op $n1 $n0 orient right-up
$ns duplex-link $n0 $n3 2.5Mbps 10ms DropTail
$ns duplex-link-op $n0 $n3 orient right-down
$ns duplex-link $n1 $n2 2.5Mbps 10ms DropTail
$ns duplex-link-op $n1 $n2 orient right-down
$ns duplex-link $n3 $n2 2.5Mbps 10ms DropTail
$ns duplex-link-op $n3 $n2 orient left-down
$ns duplex-link $n2 $n4 2.5Mbps 10ms DropTail
$ns duplex-link-op $n2 $n4 orient right
$ns duplex-link $n4 $n5 2.5Mbps 10ms DropTail
$ns duplex-link-op $n4 $n5 orient up

#srcAgents
set src1 [new Agent/UDP]
set src2 [new Agent/UDP]

#Groups
set group1 [Node allocaddr]
set group2 [Node allocaddr]

#protocols
#PIM:prorocol independent multicast:- DM:Dense mode, SM:Soft mode are 2 protocols
set mproto DM
set mrthandle [$ns mrtproto $mproto]

#prune: these packet is used to remove a node from shortest path tree i.e. group thus green color for prune packets
$ns color 30 red
#graft: these packet is used to add a node to shortest path tree i.e. group thus purple color for graft packets
$ns color 31 green

#destAgents
set dest1 [new Agent/Null]

#set the dest agent of src1 to group1
$src1 set dst_addr_ $group1	
$src2 set dst_addr_ $group2	

#set the data member dst_port_
$src1 set dst_port_ 1
$src2 set dst_port_ 2

#Attach Agents
$ns attach-agent $n0 $src1
$ns attach-agent $n5 $src2

#create traffic
set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src1
$traffic1 set packetSize_ 50B
$traffic1 set interval_ 1.5ms
set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src2
$traffic2 set packetsize_ 100B
$traffic2 set interval_ 2.5ms

#finish procedure
proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam namfile1.nam
exit 0
}

#scheduling of tasks
#the $dest1 given in the below commands can be any null agent 
$ns at 1.0 "$traffic1 start"
$ns at 1.0 "$n2 join-group $dest1 $group1"
$ns at 2.0 "$n2 leave-group $dest1 $group1"
$ns at 3.0 "$n3 join-group $dest1 $group1"
$ns at 4.0 "$n4 join-group $dest1 $group1"
$ns at 5.0 "$traffic1 stop"
$ns at 6.0 "finish"
$ns run