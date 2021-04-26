import java.util.Scanner
import kotlin.math.*

fun main(){
    val read = Scanner(System.`in`)
    
    print("Enter num1 and num2 = ")
    var num1 = read.nextInt()
    var num2 = read.nextInt()

    print("Entered num = ${num1} and ${num2} \n")

   // print("returned : ${gcd(number1, number2)}")

    var high = max(num1, num2)
    var low = min(num1, num2)

   
   /*
    Using Euclid's algorithm to solve this.

    Values num1 , num 2 = 1701 3768

    high = low * q + R (quotient + remeinder)

    R = high/low until R is ZERO. R above Zero is the GCD.

    3768 = 1701 * 2 + 366
    1701 = 366 * 4 + 237
    366 = 237 * 1 + 129
    237 = 129 * 1 + 108
    129 = 108 * 1 + 21
    108 = 21 * 5 + 3  <---- GCD
    21 = 3 * 7 + 0   
   */
   print("gcd = ${gcd(high, low)}")
   
   

}

fun gcd (num1: Int, num2: Int) :Int {
    var gcd = 0
    var high = num1
    var low = num2
    do{
        var remeinder = high % low
        //println("R : ${remeinder}")
        high = low
        low = remeinder
        if(remeinder != 0){
            gcd = remeinder
        }

    }while(remeinder != 0)

    return gcd
}

