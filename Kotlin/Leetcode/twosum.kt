import java.util.Scanner

fun main(){

    val scan = Scanner(System.`in`)

    print("Enter array size")
    var arraySize = scan.nextInt()
    
    print("Enter ${arraySize} values")
    var array = IntArray(arraySize)
    for(i in 0 until arraySize){
        array[i] = scan.nextInt()
    }


    //findTwoSum()
    
}




// fun  printFormat(array: IntArray){
//     for(i in 0..array.size -1){
//         if(i == 0){
//             print("[")
//         }
//         if(i != array.size -1){
//             print("${i},")
//         }else{
//             print("${i}")
//         }
//         if(i == array.size - 1){
//             print("]")
//         }
//     }
// }