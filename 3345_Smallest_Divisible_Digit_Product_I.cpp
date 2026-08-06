class Solution {
public:

    int digitProduct(int n){
        int product = 1;
        while(n > 0){   
            product *= n % 10;
            n /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        
        while(true){
            int product = digitProduct(n);
            if(product % t == 0)
                return n;
            else
                n++;
        }

        return n;
    }
};
