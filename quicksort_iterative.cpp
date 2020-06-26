#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

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
	int first = 0;
	int last = v.size()-1;

	int store_point[last-first+1];
	int point = -1;
	
	store_point[++point] = first;
	store_point[++point] = last;
	
	int x, i, temp;
	
	while(point>=0){
		last = store_point[point--];
		first = store_point[point--];
		x = v[last];
		i = first-1;
		for (int j=first; j<last; j++){
			if(v[j]<=x){
				i++;
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;	
			}
		}
		temp = v[i+1];
		v[i+1] = v[last];
		v[last] = temp;
		int q = i+1;
		
		
		if(q-1>first){
			store_point[++point] = first;
			store_point[++point] = q-1;
		}
		
		if(q+1<last){
			store_point[++point] = q+1;
			store_point[++point] = last;
		}
	}
	
	ofstream writeFile("output.txt");
	
	for(int i=0; i<v.size(); i++){
		writeFile<<v[i]<<" ";		
	}
	writeFile.close();	
}
