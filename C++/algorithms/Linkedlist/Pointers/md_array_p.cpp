#include <iostream>

// MULTI dimentional array with pointers.

using namespace std;



int main(){

    int m_a[2][3] = {{211,311,411},{511,611,711}};
    
    int (*p)[3] = m_a; 
    // p will return us an one dimnentional array of m_a[0] or m_a[1] .. m_a[n]

    //cout<< *(*p) + 2 << endl;
    
    // cout << (int)m_a <<endl;
    // cout << (int)m_a +1 << endl;
    // cout << (int)m_a + 2 <<endl;

    for(int i =0; i < 2; i++){
        for(int j = 0; j <3; j++){
            cout << "Value= " << m_a[i][j] << ", Address= " << &m_a[i][j] << " Address in Int= " <<  (int)&m_a[i][j] << endl;;
        }
    }
    cout << "------- POINTER Values -----------" << endl;

    cout << "== Addresses ==" <<endl;
    cout << *p <<endl; // address of value
    cout << *p+1 <<endl;
    cout << *p+2 << endl;
    cout << *p +3 << endl;
    cout << *p +4 << endl;
    cout << *p +5 << endl;

    // uncomment to experiment.
    // cout << "== p+n.. values==" <<endl;
    // //this is just literraly adding for example, p = 123, p+1 = 124. Literraly adding 1 to address.
    // cout << p  << " Int val = " << (int) p << endl; 
    // cout << p+1 << " Int val = " << (int)p+1  <<endl;  
    // cout << p+2 << " Int val = " << (int)p+2  <<endl;
    // cout << p +3 << " Int val = " << (int)p+3  <<endl;
    // cout << p +4 << " Int val = " << (int)p+4  <<endl;
    // cout << p +5 << " Int val = " << (int)p+5  <<endl;

    cout << "== Values ==" <<endl;
    cout << *(*p) << endl;
    cout << **p << endl;  // Recommended to use brackets to know order.

    cout << *(*p+1) << endl; 
    cout << *(*p+2) << endl;
    cout << *(*p+3) << endl;
    cout << *(*p+4) << endl;
    cout << *(*p+5) << endl;

    cout << "-----why brackets are important ? --------" <<endl;
    cout << "*(*p+1) = " << *(*p+1) <<endl;
    cout << "**p+1 = " << **p+1 <<endl;

    cout << "------- Array Values -----------" << endl;

    cout << *(*m_a) << endl;
    cout << *(*m_a+1) <<endl;
    cout << *(*m_a + 2) <<endl;
    cout << *(*m_a +3 ) << endl;
    cout << *(*m_a + 4) <<endl;
    cout << *(*m_a+5) <<endl;

    cout << *(*m_a+1) <<endl; //311
    cout << **(m_a+1) <<endl; //511

    cout << "-------- address --------------" <<endl;

    cout << *(m_a+1) + 2 <<endl; // 711 address
    cout << *(*(m_a + 1)+2) << endl; // 711 value

    cout << (int)m_a <<endl;
    cout << (int) m_a + 4 << endl;

    cout << (int) (*m_a + 4) <<endl; //address
    cout << *(*m_a + 4) << endl; // deref

    
    cout << **(m_a+1) << endl; //511 , address + (int)1 jump, then deref. 
    cout << *(*m_a+3) <<endl; //511

    cout << *(*(m_a+1)+1) <<endl; // 611 , jumping 1 block m_a[0] to m_a[1] + 1
    cout << *(*m_a+4) <<endl; //611 , going from start till 4th block to get it.

    cout << *(*m_a+1) + 1 << endl; //312
    cout << *(*m_a+2) <<endl; //411

    cout << **(m_a+1) + 1 <<endl;  //512
    cout << *(*(m_a+1) + 1) <<endl; //611
    cout << *(*m_a+4) <<endl; //611

    return 0;
}