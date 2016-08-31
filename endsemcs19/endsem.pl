#!/user/bin/perl


sub usage
{
	print "format : perl q2.pl [Dir] [USR]\n" ;
}

sub get_files()
{
	my ($directory , $user) = @_ ;
	$ls  = `ls -ld $directory | cut -c1-1` ;
	chomp $ls ;
	if($ls -eq "-")
	{
		usage();
	}
	else
	{
		 my @listing  = split("\n" , `ls -ld $directory\`);
		 	foreach(@listing)
		 	{
		 		my @parts  = split(" ",$_) ;
		 		if(($parts[0] neq "total" ) &&  )
		 	}
	}
}

sub count_lines()
{

}
my $dir = $ARGV[0] ;
my $user = $ARGV[1] ;
