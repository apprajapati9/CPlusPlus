import java.util.Scanner
import java.util.Arrays

fun main(){

    val scan = Scanner(System.`in`)

    print("Enter first string: ")
    var s1 = scan.nextLine()

    print("Enter second string: ") 
    var s2 = scan.nextLine()

    if(anagramUsingSorting(s1, s2)){
        print("Anagrams.")
    }else{
        print("Not Anagrams.")
    }
}
/*
    Solution using hashmap, call this function if wamted to test.
 */
fun anagramUsingHashMap(str1: String, str2: String) : Boolean {
    
    if(str1.length != str2.length){
        return false
    }
    else
    {
        var map1 = HashMap<Char, Int>(str1.length)
        var map2 = HashMap<Char, Int>(str1.length)

        str1.forEach{ 
            key ->
                if(map1.containsKey(key)){
                    map1[key] = map1[key]!! + 1
                }else{
                    map1.put(key, 1)
                }
        }

        str2.forEach {
            key ->
                if(map2.containsKey(key)){
                    map2[key] = map2[key]!! + 1
                }else{
                    map2.put(key, 1)
                }
        }   

        return map1.equals(map2)
         
    }
    
}
/*
    Solution using Array equals in Kotlin, call this function if wamted to test.
 */
fun anagramUsingSorting(str1 : String, str2: String): Boolean{
    return Arrays.equals(str1.chars().sorted().toArray(),
                        str2.chars().sorted().toArray())
}