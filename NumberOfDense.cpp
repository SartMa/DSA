#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL); \
  cout.tie(NULL);

void merge(vector <int> &v, int s, int m, int e, int &c){
  int l = s;
  int r = m+1;
  vector <int> temp;
  
  while(l<m+1 && r<e+1){
    if(v[l] >= v[r]){
      temp.push_back(v[r++]);
    }
    else{
      temp.push_back(v[l++]);
      c += e-r+1;
    }
    
  }
  while(l<m+1){
    temp.push_back(v[l++]);
  }
  
  while(r<e+1){
    temp.push_back(v[r++]);
  }

  for(int i = s; i < e+1; i++){
    v[i] = temp[i-s];
  }
}

void merge_sort(vector <int> &v, int s, int e, int &c){
  int m = s + (e-s)/2;
  if(s>=e)return;

  merge_sort(v,s,m, c);
  merge_sort(v,m+1,e, c);
  merge(v,s,m,e, c);
}


int main(void){
  fast_io;
  string s;
  cin >> s;
  vector <int> v = {0};

  for(int i = 0; i<s.size(); i++){
    int p = s[i] - '0';
    int q = pow(-1, p);
    v.push_back(v[i]-q);
  }
  int c = 0;

  merge_sort(v, 0, v.size()-1, c);

  cout << c << endl;
  
}
