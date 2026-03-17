int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
if(numOnes>=k){
return k;
}else if(k>numOnes && k<=numOnes+numZeros){
return numOnes;
}else{
return numOnes-(k-(numOnes+numZeros));
}
}