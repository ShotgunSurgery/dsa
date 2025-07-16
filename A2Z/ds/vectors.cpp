#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int>& v){
	for(auto x: v){
		cout<< x <<' ';
	};
	cout<< endl;
}
	
int main(){
	vector<int> v1;
	vector<int> v2 = {1,2,3,4,6,34,23};
	vector<int> v3{3,1};
	print_vector(v2);
	print_vector(v3);

	v2.insert(v2.begin() + 2, 7);
	print_vector(v2);
	
	v2.push_back(0);
	print_vector(v2);

	cout<<"Accessing and updating elements of a vector \n";

	cout<< v2[3] <<'\n';
	cout<< v2[8] <<'\n';
	cout<< v2[90] <<'\n';

	cout<<"Finding vector size \n";
	cout<< v2.size() <<'\n';

	cout<<"Traversing through a vector \n";
	for(int i = 0; i <= v2.size(); i++){
		cout<< v2[i] <<'-'<<' ';
	}
	cout<<'\n';
	
	cout<<"Deleting elements form a vector"<<endl;
	v2.pop_back();
	print_vector(v2);
	
}
