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

    The HCF or GCD of two integers is the largest integer that can exactly divide both numbers (without a remainder).

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
   print("gcd = ${gcd(high, low)}\n")
   
   print("gcdBySub = ${gcdUsingSubstraction(high, low)}")
}

/*
Example : 45 - 1,3,5,9,15,45
          60 - 1,2,3,4,5,6,10,12,15,20,30,60
    GCD = 15
*/

fun gcdUsingSubstraction(num1: Int, num2: Int) : Int {

    var gcd = 0 
    if(num1 == num2) {
        gcd = num1
    }

    var number1 = num1
    var number2 = num2

    while(number1 != number2){
        if(number1 > number2){
            number1 = number1 - number2
            gcd = number1 
        }else{
            number2 = number2 - number1
            gcd = number2
        }
    }


    return gcd
}


fun gcd (num1: Int, num2: Int) :Int {
    var gcd:Int
    var high = num1
    var low = num2
    do{
        var remeinder = high % low
        //println("R : ${remeinder}")
        high = low
        low = remeinder
        if(remeinder != 0){
            gcd = remeinder
        }else{
            gcd = high

        }

    }while(remeinder != 0)

    return gcd
}

