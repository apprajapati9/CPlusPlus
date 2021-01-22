#include <iostream>
#include<vector>
#include<unordered_map>


using namespace std;
vector<int> nums;

class Solution{
	public:
		unordered_map<int, int> efficientTwoSum(vector<int> &nums, int target){
			//vector<int> answer;
			unordered_map<int, int> umap;

			for(int i=0; i<=nums.size(); i++){
				if(umap.find(target - nums[i]) != umap.end()){
					return umap;
				}else{
					umap[nums[i]] = i;  
					//storing as Value --> index 
				}
			}

			for (auto i : umap){
				cout << i.first << " " << i.second << endl;
			}
			//std::cout << umap;
			return umap;
		}

		vector<int> bruteForceTwoSum(vector<int> &nums, int target){

			//vector<int> answer;

			for(int i = 0; i <= nums.size(); i++){
				if(nums[i] + nums[i+1]== target){
					nums.resize(0);
					nums.push_back(i);
					nums.push_back(i+1);
                    break;
				}
			}

			// for( int x : nums){
			// 	cout << endl<< "numbers: " <<x << " ";
			// }

			// for( int x : answer){
			// 	cout << "answers: " << x << " ";
			// }
		
			return  nums;
		}
};

int main(){

	/* BRUTEFORCE solution
	
	int arraysize = 0;
	int target =0;

	std::cout<<"how many values in array?" << endl;
	std::cin >> arraysize;
	
	std::cout <<"target value?" <<endl;
	std::cin >> target;
	
	int array[arraysize-1]; //for example 6... array[6] = 0, 1, 2, 3, 4, 5
	
	for(int i=0; i < arraysize; i++ ){
		cout << "element=" << i << " ";
		cin >> array[i];
	}
	
	std::cout << "Printing array" <<endl ;
	
	for ( int i = 0; i < arraysize;i ++){
		cout << array[i] << ",";
	}
	
	cout << endl;

    for(int i = 0; i < arraysize; i++){
    	cout << array[i] << "and" << array[i+1] << endl;
        if(array[i] + array[i+1] == target ){
        	
        	cout << "answer:" << array[i] << "and " << array[i+1] <<endl;
        	cout << "answer: element num = [" << i << "," << i+1 << "]" << endl;
        	//break;
		}else{
			//cout << "No target found";
		}
            
    }
    
    */
    
    
    int sizeOfVector = 0;
    
    std::cout << "Enter size of Vector: " << endl;
    std::cin >> sizeOfVector;

	int target= 0;
	std::cout << "target value :" << endl;
	std::cin >> target;
	
    
	// in vector, don't use size-1 because size starts with 1
	int input;

	for(int i=0; i < sizeOfVector; i++){
			std::cin >> input;
			nums.push_back(input);
	}
	
	//to print all elements of vector
	// for ( int x : nums){
	// 	std::cout << x << ", ";
	// }

	Solution mySolution;
	//mySolution.bruteForceTwoSum(nums, target);

	//cout<< "Bruteforce ANSWER:"<<endl;
	//cout << "[" << nums.at(0) << "," << nums.at(1) <<"]";

	mySolution.efficientTwoSum(nums, target);

	

    return 0;
}

