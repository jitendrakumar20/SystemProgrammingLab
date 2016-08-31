
if [ $# -ne '1' ];
then
	echo "error"
	exit 1
fi

get_files(){
list=`ls -F`
}

count_lines(){
count=0
for file in $list
do
	while read line
	do
		count=$(($count+1))
done < $file

done
}
if cd $1
then
	get_files
	count_lines
	count = count/4 ;
	printf "\n no of lines    : %d\n" $count
fi