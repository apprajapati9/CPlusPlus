
interface Observer{
    fun update(subject: Subject)
}

interface Subject {
    fun register(ob : Observer)
    fun unregister(ob : Observer)
    fun notifyAllObs()
}

class Math : Subject {
    val listOfOb =  mutableListOf<Observer>() //MutableList<Observer>
    override fun register(obs : Observer){
        listOfOb.add(obs)
    }
    
    override fun unregister(obs : Observer){
         listOfOb.remove(obs)
    }
    
    override fun notifyAllObs(){
         for(ob in listOfOb) {
             ob.update(this)
         } 
    }
}

class MyObserver(private val name: String) : Observer{
    override fun update(s : Subject){
        println("update-ajay $name  from $s::class.simpleName}")
    }
}


fun main() {
    val math = Math()
    val student1 = MyObserver("Student 1")
    val student2 = MyObserver("Student 2")
    
    math.register(student1)
    math.register(student2)
    
    math.notifyAllObs()
    
    math.unregister(student1)
    println("----")
    math.notifyAllObs()
}