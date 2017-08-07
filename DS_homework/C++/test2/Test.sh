echo
./CaseGenerator
echo
make
echo
echo "Testing Compress ... "
./huffman <I >O1
./huffman_ref <I >O2
diff O1 O2
echo "Done"
echo "Testing Decompress ... "
./huffman -d <O2 >I1
./huffman_ref -d <O2 >I2
diff I1 I2
echo "Done"
echo
rm I1 I2 O1 O2 huffman
echo "EastCompare Terminated"
echo "/*DataCorrupted Presented*/"
echo