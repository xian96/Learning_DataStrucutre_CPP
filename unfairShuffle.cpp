class iterator{

}
int main(){

for(vector<int>::iterator i = a.begin(); i != a.end(); ++i){
    cout<< *i<<" ";
}
for(auto x : a){
    cout << x<< " ";
}
}