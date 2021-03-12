#include<iostream>
#include<vector>
using namespace std;
#define NMAX 100

/////////////////////////
// class stack 
class stack{
	int top;
	int data[NMAX];
	public:
		stack(){
			top = 0;
		}
		int gettop(){
			return data[top];
		}
		// kiem tra ngan xep rong
		bool isempty(){
			return (top==0);
		}
		//kiem tra ngan xep day
		bool isfull(){
			return(top==NMAX);
		}
		// ham them phan tu vao dau ngan xep
		void push(int x){
			if(this->isfull()){
				cout<<"\nNgan xep day!"<<endl;
			}else{
				top++;
				data[top]=x;
			}
		}
		//ham lay phan tu ra khoi dau danh sach
		int pop(){
			if(this->isempty()){
				cout<<"\nNgan xep rong!"<<endl;
			}else{
				int x = data[top];
				top--;
				return x;
			}
		}
		// Ham Nhap
		void input(){
    	cout<<"\nNhap gia tri cho Stack \nNhap 0 de ket thuc "<<endl;
    	int x;
    	do{
        	cin>>x;
        	if(x!=0)
           		push(x);
    	}
    	while(x!=0);
		}
 
		//Ham xuat
		void output(){
    	while(top!=0)
        	cout<<"  "<<pop();
		}
};
////////////////////////////////////////////////////////
// class dung de luu cac gia gia tri cua 1 dinh cua do thi
class node{
// bien: key(ten dinh),value(gia tri h),rode(duong di)
	int key,value,rode;
	
	public:
	node(){key=0;value = 0;rode=0;}
	node(int k){ this->key = k;this->value = 0;this->rode=0;}
	node(int k,int v,int r){
		this->key = k;this->value = v;this->rode = r;
	}
	int getkey (){
		return this->key;
	}
	int getvalue(){
		return this->value;
	}
	int getrode (){
		return this->rode;
	}
	
	int setrode(int r){
		return this->rode = r;
	}
	
	int setkey(int k){
		return this->key = k;
	}
	
	int setvalue(int v){
		return this->value = v;
	}
// tao ra de test(hoi thua thi phai :)))	
	node operator++(int){
		node N(key,value,rode);
		++key;
		return N;
	}  

};
////////////////////////////////////////
// ham phu xuat cac dinh ra man hinh
// ko hieu tai sao no khong cho chay trong main (~~>_<~~) 
void show(int n){
	for(int k = 1; k<=n;k++) {cout<<k<<" ";}cout<<endl;
}
node a[NMAX+1][NMAX+1];
int n, m, Free[101], u, v, s,s1,s2,f;
//////////////////////////////////
/// xap xep
// ham doi cho
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
// ham sap xep phan tu them ham danh gia
void Sort(vector<int> &arr, int n,int t)
{
    int i, j, max_idx;

    for (i = 0; i < n-1; i++)
    {

    max_idx = i;
    for (j = i+1; j < n; j++){
	
    	cout<<"\ngia tri cua "<<arr[j]<<": "<<a[arr[j]][t].getvalue()<<endl;
		cout<<"\ngia tri cua "<<arr[max_idx]<<": "<<a[arr[max_idx]][t].getvalue()<<endl;  
		cout<<"\ngia tri cua min_idx :"<<max_idx<<endl;
		// sap xem theo chieu giam dan cua ham danh gia
		// de tien cho viec append vao stack
        if (a[arr[j]][t].getvalue() > a[arr[max_idx]][t].getvalue()){
		  
		max_idx = j;
		}}

        swap(arr[max_idx], arr[i]);
    }
}

////////////////////////////////////
// ham tim chieu sau ban goc
void DFS(int u, int e)
{
    cout << u << endl; // xuat ra nut bat dau
    if(e==u){
    	cout<<"dich la:"<<e;
    	return;
	}
    Free[u] = false; // tap da duyet
    for (int v = 1; v <= n; v++){

        if (a[u][v].getrode() == 1 && Free[v]){ // neu nhu u co duong di den v va v chua duyet
            cout<<"dinh duoc xet"<<v<<endl; 
			DFS(v,e);} // thi tien hanh duyet v
	}
}
///////////////////////////////
//tim chieu sau ban moi
void NDFS(int u,int e){
	// khoi tao stack
	stack st;
	st.push(u);
	int temp;
	// khoi tao L 
	vector<int> L;
	while(true){
		// neu stack rong thi ket thuc
		if(st.isempty()){
		cout<<"tim kiem that bai!";return;	
		}
		temp=st.gettop(); // luu lai vi tri top cua stack
		
		
		// them dinh da xet vao tap da duyet
		Free[st.gettop()] = false; // tap da duyet
		
		// xoa phan tu da duyet do di khoi stack
		st.pop();
		
		// kiem tra xem diem do co phai diem dich hay ko, neu dung thi ket thuc
		if(e==temp){
    	cout<<"tim thay dich la:"<<e;
    	return;
		}
		
		//duyet dinh va cho vao L
		for (int v = 1; v <= n; v++){
        if (a[temp][v].getrode() == 1 && Free[v]){ // neu nhu u co duong di den v va v chua duyet
            
			L.push_back(v);
			} // thi tien hanh duyet v
		}
		// sap xep lai L
		Sort(L,L.size(),temp);
		for(int i=0;i<L.size();i++){
	 		cout<<"element in vector: "<<L[i]<<" ";}
	 	// them cac dinh trong L vao stack
	 	for(int i=0;i<L.size();i++){
	 		st.push(L[i]);
		 }
		 // xoa trong danh sach L
		 L.clear();
		
	}
}

int main(){
	
cout<<"nhap vao so dinh cua do thi: ";
cin >> n;
cout<<"nhap vao so canh cua do thi: ";
cin >> m;
cout<<"dinh xuat phat: ";
	cin>> s;
cout<<"dinh ket thuc: ";
	cin>> f;
/// khoi tao do thi
for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++)
      {  a[i][j].setrode(0);} // Ðau tiên chúng ta coi do thi không có canh nào ca
}
// tien hanh nhap du lieu
for (int i=1; i<=m; i++)
{	cout<<"canh thu : "<<i<<endl;
    cin >> u;
    cout<<"nhap vao ham danh gia cua dinh 1: ";
    cin>>s1;
	cout<<"nhap vao dinh 2:";
	cin >> v;
	cout<<"nhap vao ham danh gia cua dinh 2: ";
    cin>>s2;
    a[u][v].setrode(1);a[u][v].setvalue(s1);
    a[v][u].setrode(1);a[v][u].setvalue(s2);
}
// hien thi duong di cua do thi
cout<<"duong di:"<<endl;
cout<<"  |";show(n);
for(int i= 1; i<=n;i++)
{	 
	cout<<i<<" |";
	for (int j=1; j<=n; j++){
		cout<<a[i][j].getrode()<<" ";
	}
	
	cout<<endl;
}
// hien thi ham danh gia cua cac dinh tren do thi
cout<<"gia tri ham danh gia:"<<endl;
cout<<"  |";show(n);
for(int i= 1; i<=n;i++)
{	 
	cout<<i<<" |";
	for (int j=1; j<=n; j++){
		cout<<a[i][j].getvalue()<<" ";
	}
	
	cout<<endl;
}
// khoi tao list check
for (int i = 1; i <= n; i++)
        Free[i] = 1;
   //DFS(s,f);

NDFS(s,f);
    return 0;

}
