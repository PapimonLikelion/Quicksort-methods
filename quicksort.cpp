#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int Partition(vector<int> &v, int p, int r){
	int x = v[r];
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