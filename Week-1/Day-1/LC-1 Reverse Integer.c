int reverse(int x){
    int result = 0;
    while(x != 0){
     int rem = x % 10;
     if (result > 214748364 || result < -214748364)
            return 0;
     result = result * 10  + rem;
     x = x / 10;
    } 
    return result;
}



