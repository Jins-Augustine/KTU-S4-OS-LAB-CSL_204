read -p "Enter the number of elements: " n
echo "Enter the $n elements"
read -a arr
largest=${arr[0]}
for((i=0;i<n;i++))
do
    if [ ${arr[i]} -gt $largest ]
    then 
        largest=${arr[i]}
    fi
done
echo largest is $largest
