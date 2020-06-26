#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

vector<int> v;

int main()
{
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
	
	int x, i, j, temp, pivot, middle, first_val, last_val, middle_val;
	
	while(point>=0){
		last = store_point[point--];
		first = store_point[point--];

		if(last-first<7){
			//insertion sort
//			cout<<"insertion sort"<<endl;
			for(int i = first; i<last; i++){
				j = i;
				while(j>=0 && v[j]>v[j+1]){
					temp = v[j];
					v[j] = v[j+1];
					v[j+1] = temp;
					j--;
				}
			}
			continue;
		}

		middle = (first+last)/2;
		first_val = v[first];
		middle_val = v[middle];
		last_val = v[last];
		if(first_val >= middle_val){
			if(middle_val >= last_val){
				pivot = middle;
			}
			else{
				if(first_val >= last_val){
					pivot = last;
				}
				else{
					pivot = first;
				}
			}
		}
		else{
			if(middle_val < last_val){
				pivot = middle;
			}
			else{
				if(first_val > last_val){
					pivot = first;
				}
				else{
					pivot = last;
				}
			}
		}

		if(pivot != last){
			int temp = v[pivot];
			v[pivot] = v[last];
			v[last] = temp;
		}		
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