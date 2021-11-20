fun main(){

    /* 
    val node1 = Node(value = 1)
    val node2 = Node(value = 2)
    val node3 = Node(value = 3)

    node1.next = node2
    node2.next = node3

    println(node1)
    
    //Inefficient way to add / remove node, 
    //so check below implmentation
    */

    val myList = LinkedList<Int>()
    myList.push(3)
    myList.push(2)
    myList.push(1)
    myList.push(5)
    println(myList) //5,1,2,3
    
   // myList.popFirst()
    println(myList) //5, 1, 2, 3

    myList.append(10) // 5,1,2,3,10
    myList.insertAfterValue(5,99) //            //11,5 broke the code, fix. 
    println(myList)

    //val node = myList.nodeAt(5);

    myList.insert(100,myList.nodeAt(0)!!)
    println(myList)
    

}