set ns [new Simulator]

set nt [open demo.tr w]
$ns trace-all $nt

set nf [open namfile.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns duplex-link $n0 $n1 2Mbps 2ms DropTail
$ns duplex-link $n1 $n2 2Mbps 2ms DropTail

set src1 [new Agent/TCP]
$ns attach-agent $n0 $src1

set src2 [new Agent/TCP]
$ns attach-agent $n2 $src2

set dest1 [new Agent/TCPSink]
$ns attach-agent $n1 $dest1

set dest2 [new Agent/TCPSink]
$ns attach-agent $n0 $dest2

$ns connect $src1 $dest1
$ns connect $src2 $dest2

set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src1

set traffic2 [new Application/FTP]
$traffic2 attach-agent $src2

proc finish { } {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam namfile.nam
	exit 0
}

$ns at 0.0 "$traffic1 start"
$ns at 0.5 "$traffic2 start"
$ns at 1.0 "$traffic2 stop"
$ns at 1.2 "$traffic1 stop"
$ns at 1.5 "finish"
$ns run