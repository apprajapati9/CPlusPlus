
#include <iostream>

using namespace std;

/*
   fib series 0,1,1,2,3,5,8,13,21,..
   0+1 = 1
   1+1 = 2
   2+1 = 3
   3+2 = 5
   5+3 = 8
   fib ( n-1) + fib(n-2)

   callstack                       2+1 = 3
                                  fib(5)
                            1+1=2           1+0=1
			   fib(4)            fib(3)

		     fib(3)     fib(2)     fib(2)  fib(1)

		 fib(2) fib(1)     1          1      0

                  1      0

   */

static int arr[100] = {0,1,0};

int fib_rec(int n) // 3
{
    if(n == 1) {
//        cout << 0 << endl;

        arr[n] = 0;
        return arr[0];

    } else if(n == 2) {
        arr[n] = 1;
        //      cout << 1 << endl;
        return arr[n];
    } else {
        //    cout << n - 1 << " - " << n - 2 << " = " << n-1+n-2<< endl;
	if(arr[n-1] != 0 && arr[n-2] != 0) {
	    cout << "exists " << arr[n-1] << " and " << arr[n-2] << endl;
	    arr[n] = arr[n-1] + arr[n-2];
	}else{
            arr[n] =  fib_rec(n-1) + fib_rec(n-2);
	 } 
        return arr[n];

    }
}

void fib()
{

    int first = 0;
    int second = 1;
    int sum = 0;

    cout << first << ", ";
    cout << second << ", ";
    for(int i = 0; i < 10; i++) {
        sum = first + second;
        cout << sum << ", ";

        first = second;
        second = sum;
    }

}

int main()
{

    cout << "Printing Fibonacci series using recursion " << endl;

    //fib();
    int n = 10;
    int ans = fib_rec(n);
    cout << "Answer: " << ans << endl;
    for(int i = 0; i < n ; i++) {
        cout << arr[i] << ",";
    }
    return 0;
}
