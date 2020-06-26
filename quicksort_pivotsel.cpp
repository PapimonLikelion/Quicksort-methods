#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int PivotSelect(vector<int> &v, int p, int r){
	int middle = (p+r)/2;
	int first_val = v[p];
	int middle_val = v[middle];
	int last_val = v[r];
//	cout<<"Pivot select! "<<p<<" "<<middle<<" "<<r<<endl;
//	cout<<"pivot value! "<<first_val<<" "<<middle_val<<" "<<last_val<<endl;
	if(first_val >= middle_val){
		if(middle_val >= last_val){
			return middle;
		}
		else{
			if(first_val >= last_val){
				return r;
			}
			else{
				return p;
			}
		}
	}
	else{
		if(middle_val < last_val){
			return middle;
		}
		else{
			if(first_val > last_val){
				return p;
			}
			else{
				return r;
			}
		}
	}
}

int Partition(vector<int> &v, int p, int r){
	int pivot = PivotSelect(v,p,r);
//	cout<<"pivot: "<<pivot<<" "<<"pivot value: "<<v[pivot]<<endl;
//	int check = v[pivot];
	if(pivot != r){
		int temp = v[pivot];
		v[pivot] = v[r];
		v[r] = temp;
	}
	int x = v[r];
//	cout<<"pivot index : "<<r<<" "<<"pivot value : "<<v[r]<<endl;
	int i = p-1;
	int temp;
	for(int j=p; j<r; j++){
		if(v[j]<=x){
			i++;
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	temp = v[i+1];
	v[i+1] = v[r];
	v[r] = temp;
	return (i+1);
}

void QuickSort(vector<int> &v, int p, int r){
	if(p<r){
		int q = Partition(v,p,r);
//		cout<<"PARTITION! "<<v[q]<<endl;
//		for(int i=0; i<v.size(); i++){
//			cout<<v[i]<<" ";
//		}
//		cout<<endl;
		QuickSort(v, p, q-1);
		QuickSort(v, q+1, r);
	}
}


int main()
{
	vector<int> v;
	int num;
	ifstream readFile;
	readFile.open("input.txt");
	while(!readFile.eof() && readFile>>num)
	{
		v.push_back(num);
	}	
	
	QuickSort(v, 0, v.size()-1);

	ofstream writeFile("output.txt");
	
	for(int i=0; i<v.size(); i++){
		writeFile<<v[i]<<" ";		
	}
	writeFile.close();
	
}