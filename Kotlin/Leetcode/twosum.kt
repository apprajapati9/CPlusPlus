import java.util.Scanner

fun main(){

    val scan = Scanner(System.`in`)

    print("Enter array size: ")
    var arraySize = scan.nextInt()
    
    print("Enter ${arraySize} values: \n")
    var array = IntArray(arraySize)
    for(i in 0 until arraySize){
        array[i] = scan.nextInt()
    }

    //Different ways to print items
    // array.forEach(System.out::print)  //to print all values without any delimiter
    println(array.joinToString(","))  //to seperate items 

    val target:Int 
    print("Enter target Value:")
    target = scan.nextInt()

    //print("$target") //Just to print targt value 

    //Using Array
    // array = twoSumUsingArray(array, target)
    // println("[" + array.joinToString(",") + "]")

    array = twoSumUsingHashMap(array, target)
    println("TwoSum answer: "+"[" + array.joinToString(",") + "]")

}

fun twoSumUsingArray(array: IntArray, target:Int) : IntArray{

    for(i in 0 until array.size){
        for(j in i+1 until array.size){
            if(array[i] + array[j] == target){
                return intArrayOf(i,j)
            }
        }
    }
    return intArrayOf(0,0)
}

fun twoSumUsingHashMap(array: IntArray, target:Int) : IntArray{
    val map = HashMap<Int, Int>() 
    array.forEachIndexed{
        index, item ->    
            val found = map[target-item]
            found?.let{
                return intArrayOf(found, index)
            }
            map.put(item, index)
    }
    return intArrayOf(-1,-1)   
}

fun twoSumwithPair(array: IntArray, target:Int) : Pair<Int, Int>{
    val map = hashMapOf<Int, Int>()
    array.forEachIndexed{
        index, value ->
            if(map.contains(target-value)){
                return Pair(map[target-value]!!, index)
            }
            map.put(value, index)
    }
    return Pair(-1,-1)
}