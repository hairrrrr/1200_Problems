#!/xhbin/perl5
# Copyright Michael Van Biesbrouck (ACM ICPC ECNA 98)


$_=<>;
@r = ();
while( <> ){
	chomp;
	%h=();
	$n=0;
	while( /./g ){
		$h{$&}++;
		for $k (keys %h){
			if( $k gt $& ){
				$n += $h{$k};
			}
		}
	}
	#print "$_: $n\n";
	push @r, [ $n, $_ ];
}
#for(@r){
	#print "${$_}[1]: ${$_}[0]\n";
#}

@r = sort { return ${$a}[0] <=> ${$b}[0]; } @r;
for(@r){
	#print "$_\n";
	print ${$_}[1], "\n";
}
0;
