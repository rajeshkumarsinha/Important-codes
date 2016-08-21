#include<bits/stdc++.h>
using namespace std;

struct node{
    bool mark;
    node* ch[26];
};

node* getnode(){
    node* temp=new node;
    temp->mark=false;
    for(int i=0;i<26;i++)temp->ch[i]=NULL;
    return temp;
}

void Insert(node* root,string s){
    node* crawl=root;
    for(int i=0;i<s.length();i++){
        if(crawl->ch[s[i]-'a']==NULL)crawl->ch[s[i]-'a']=getnode();
        crawl=crawl->ch[s[i]-'a'];
    }
    crawl->mark=true;
}

void print(node* root,string temp){
    if(root){
        if(root->mark){
            cout<<temp<<endl;
        }

        for(int i=0;i<26;i++){
            if(root->ch[i]){
                char ch=i+'a';
                print(root->ch[i],temp+ch);
            }
        }
    }
}

bool isLeaf(node* root){
    for(int i=0;i<26;i++){
        if(root->ch[i])return false;
    }
    return true;
}
#define ii pair<node*,int>
void Delete(node* root,string s){
    stack<ii>st;
    node* crawl=root;
    st.push(ii(crawl,-1));
    for(int i=0;i<s.length();i++){
        if(crawl->ch[s[i]-'a']){
            st.push(ii(crawl->ch[s[i]-'a'],s[i]-'a'));
            crawl=crawl->ch[s[i]-'a'];
        }
        else return;
    }
    if(crawl->mark){
        crawl->mark=false;
        while(true){
            if(st.size()<=1)break;
            node* temp=(st.top()).first;
            int V=(st.top()).second;st.pop();
            node* temp1=(st.top()).first;
            if(isLeaf(temp)){
                free(temp1->ch[V]);
                temp1->ch[V]=NULL;
            }
            else break;
        }
    }
}

int main(){
    node* root=getnode();

    while(true){
        int t;cin>>t;
        string s;cin>>s;
        if(t==1){//Insert
            Insert(root,s);
        }
        else{
            Delete(root,s);
        }
        print(root,"");
    }
}
