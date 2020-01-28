primeGen = function() {
  for (j = 1; i < num; i++) {
    if(isPrime(i)){
      //add to list
    }
  }
    //return list
  }

}

isPrime = function(num){
  for(i = 2; i < num; i++) {
    if(num % i == 0){
      return false
    }
  }
  return true;
}