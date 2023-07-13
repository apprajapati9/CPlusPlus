fun main() {

    val lamda = { name: String -> println("hello $name") }
    val names = listOf("a", "b", "c")

    val sum = { a: Int, b: Int ->
        println(a + b)
        println(a * b)
    }

    hello(names, lamda)
    sumFun(3, 4, sum)

    names.forEach { n -> println("name" + n) }
}

fun hello(names: List<String>, doSomething: (String) -> Unit) {
    for (name in names) {
                doSomething(name)
    }
}

fun sumFun(a: Int, b: Int, sum: (Int, Int) -> Unit) {
    sum(a, b)
}

fun <T> Iterable<T>.forEach(action: (T) -> Unit): Unit {
    for (element in this) action(element)
}
