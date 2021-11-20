class LinkedList<T> {
    private var head : Node<T>? = null
    private var tail : Node<T>? = null
    private var size = 0

    fun isEmpty(): Boolean {
        return size == 0
    }

    override fun toString(): String{
        if(isEmpty()){
            return "Empty List"
        }else{
            return head.toString()
        }
    }

    fun push(value : T): LinkedList<T>{
        head = Node(value = value, next = head)
        if(tail == null){
            tail = head
        }
        size++
        return this
    }

    fun popFirst(): LinkedList<T>{
       
        if(head != null && head?.next != null){
            head = head?.next
            size--
        }

        //in case of only one item.
        if(head?.next == null){
            head = null;
            size = 0
        }
        
        return this
    }

    fun append(value : T) : LinkedList<T>{
        /* 
        var new_node = Node(value, null)
        // if(tail == null || head == null){
        //     head = new_node
        //     tail = head
        //     size++
        
        //above code can be replaced by
        
        if(isEmpty()){
            push(value)
        
        }else{
            var prev_node = head
            while(prev_node != tail){
                prev_node = prev_node?.next
                // println(prev_node)
            }
            prev_node?.next = new_node
            tail = new_node
            size++
        }
        */
        if(isEmpty()){
            push(value)
        }
        
        tail?.next = Node(value = value)
        tail = tail?.next
        size++

        return this;
    }

    //Not covering case of two occurance of same value. 
    fun insertAfterValue(Gvalue : T, Ivalue :T) : LinkedList<T>{

        // if(isEmpty()){
        //     push(Ivalue)
        // }
        
        var new_node = Node(value = Ivalue)
        var prev_node = head
        
        //println("prenode= ${prev_node?.value}")
        
        while(prev_node?.value != Gvalue 
                && prev_node?.next != null){
                    
            prev_node = prev_node.next
        }

        if(prev_node?.value == Gvalue){
            new_node.next = prev_node?.next 
            prev_node?.next = new_node
        }else{
            println("No value $Gvalue found!")
        }
        
        return this;
    }

    // fun nodeFromValue(value:T) : Node<T>? {
    //     var node = head

    //     while(node.value != value){
    //         node = node.next
    //     }
    // }

    fun insert(value : T, afterNode: Node<T>) : Node<T>{
        
        if(tail == afterNode){
            append(value)
            return tail!!
        }

        val new_node = Node(value = value,next = afterNode.next)
        afterNode.next = new_node
        size++
        return new_node
    }


    fun nodeAt(index : Int) : Node<T>? {
        var currentNode= head
        var currentIndex = 0

        while(currentIndex != index && index <= size){
            currentNode = currentNode?.next
            currentIndex++
        }
        return currentNode
    }
}