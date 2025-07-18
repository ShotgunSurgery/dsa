#include <iostream>
#include <vector>
using namespace std;

int search (vector<int>& v, int target){
	int low = 0, high = (v.size() - 1), avg = 0;
avg = (((low+high)/2) - 1);
	while(low < high){
		
		if (v[avg] == target)
            return avg;
        else if (v[avg] < target)
            low = avg + 1;
        else
            high = avg - 1;

	}
	return(low);
};

int main(){
	vector<int> vm = {1,2,3,4,5,6,7};
	cout<<"Index of the required element is: "<<search(vm, 3)<<endl;
	return 0;
}
