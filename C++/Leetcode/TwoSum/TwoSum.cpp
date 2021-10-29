	#include <iostream>
	#include<vector>
	#include<map>
	#include <unordered_map>


	using namespace std;
	vector<int> nums;

	class Solution{
		public:
			void printVector(vector<int> &v, string methodName){
				cout << endl;
				cout << methodName << "answer:";
				for ( int x : v){
					std::cout << x << ", ";
				}
			}

			void printAnswerFormat(vector<int> &v){ //assuming only have to print two indexes
				//for (int i =0; i < v.size(); i++){
				cout << endl;
				cout << "answer: element num = [" << v[0] << "," << v[1] << "]" << endl;
				
			}

			void printMap(map<int, int> &m){
				cout << "Printing Map....";
				cout << endl;
				for (auto i : m){
					cout << "key: " << i.first << " value: " << i.second << endl;
				}
			}


			vector<int> efficientTwoSum(vector<int> &nums, int target){
				//vector<int> answer;
				map<int, int> umap;

				for(int i=0; i < nums.size(); i++){

					if(umap.find(target - nums[i]) != umap.end()){
						
						nums.resize(0);
						nums.push_back(umap[target-nums[i]]); //umap[id] gives value
						nums.push_back(i);
						return nums;
						//
					}
					else{
						umap[nums[i]] = i; // value -> index
						// index - > value (of vector[i])
						// ideally idex is unique which should be preferred to store as KEY
						//, however, hashmap automatically removes duplicates key, 
						// so value would be fine as well.
						// eg. 2 2 2 7 so hashmap won't store 2 - 0 , 2 - 1, 2 - 2
						// instead it will remove duplicate and store the latest which is
						// 2 -> 2, 7->3, if target is 9, then [2,3] is the answer

						//hashmap also automatically sorts <int> keys into sorted order.
					}
				}

				printMap(umap);
				printVector(nums, "efficientTwoSum");
				//printVector(nums);
				printAnswerFormat(nums);
				return nums;
			}

			vector<int> bruteForceTwoSum(vector<int> &nums, int target){

				//printVector()

				for(int i = 0; i <= nums.size(); i++){
					if(nums[i] + nums[i+1]== target){
						nums.resize(0);
						nums.push_back(i);
						nums.push_back(i+1);
						break;
					}
				}
				
				printVector(nums, "BruteForceTwoSum");
				printAnswerFormat(nums);
				return  nums;
			}

			void bruteForceTwoSumUsingArray(){
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
						break;
					}else{
					//cout << "No target found";
					}
				
				}
			
			}
	};

	int main(){
		
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
		
		Solution mySolution;

		mySolution.efficientTwoSum(nums, target);
		mySolution.bruteForceTwoSum(nums, target);		

		return 0;
	}