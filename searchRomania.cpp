/*      Name:: Nikhil Raina
        UnityID :: nraina
        StudentID:: 200105282
*/
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

struct adj_list{
	string city_name;
	string colour;
	int label;
	bool visited = false;					// initially all white, once visit grey when removed from queue then black
	adj_list *next1 = NULL;				//Since a node is having a max of 4 neighbours
	adj_list *next2 = NULL;
	adj_list *next3 = NULL;
	adj_list *next4 = NULL;
};


void fill_adj_list(adj_list ** adj){

	for(int i = 0; i<20; i++){			//number of towns
		adj[i] = new adj_list;
		adj[i]->colour = "white";
	}

	adj[0]->city_name = "arad";
	adj[1]->city_name = "bucharest";
	adj[2]->city_name = "craiova";
	adj[3]->city_name = "dobreta";
	adj[4]->city_name = "eforie";
	adj[5]->city_name = "fagaras";
	adj[6]->city_name = "giurgiu";
	adj[7]->city_name = "hirsova";
	adj[8]->city_name = "iasi";
	adj[9]->city_name = "lugoj";
	adj[10]->city_name = "mehadia";
	adj[11]->city_name = "neamt";
	adj[12]->city_name = "oradea";
	adj[13]->city_name = "pitesti";
	adj[14]->city_name = "rimnicu_vilcea";
	adj[15]->city_name = "sibiu";
	adj[16]->city_name = "timisoara";
	adj[17]->city_name = "urziceni";
	adj[18]->city_name = "vaslui";
	adj[19]->city_name = "zerind";

	// using the question we manually fill the neighbours in alphabetical order
	adj[0]->next1 = adj[15];
	adj[0]->next2 = adj[16];
	adj[0]->next3 = adj[19];
	adj[1]->next1 = adj[5];
	adj[1]->next2 = adj[6];
	adj[1]->next3 = adj[13];
	adj[1]->next4 = adj[17];
	adj[2]->next1 = adj[3];
	adj[2]->next2 = adj[13];
	adj[2]->next3 = adj[14];
	adj[3]->next1 = adj[2];
	adj[3]->next2 = adj[10];
	adj[4]->next1 = adj[7];
	adj[5]->next1 = adj[1];
	adj[5]->next2 = adj[15];
	adj[6]->next1 = adj[1];
	adj[7]->next1 = adj[4];
	adj[7]->next2 = adj[17];
	adj[8]->next1 = adj[11];
	adj[8]->next2 = adj[18];
	adj[9]->next1 = adj[10];
	adj[9]->next2 = adj[16];
	adj[10]->next1 = adj[3];
	adj[10]->next2 = adj[9];
	adj[11]->next1 = adj[8];
	adj[12]->next1 = adj[15];
	adj[12]->next2 = adj[19];
	adj[13]->next1 = adj[1];
	adj[13]->next2 = adj[2];
	adj[13]->next3 = adj[14];
	adj[14]->next1 = adj[2];
	adj[14]->next2 = adj[13];
	adj[14]->next3 = adj[15];
	adj[15]->next1 = adj[0];
	adj[15]->next2 = adj[5];
	adj[15]->next3 = adj[12];
	adj[15]->next4 = adj[14];
	adj[16]->next1 = adj[0];
	adj[16]->next2 = adj[9];
	adj[17]->next1 = adj[1];
	adj[17]->next2 = adj[7];
	adj[17]->next3 = adj[18];
	adj[18]->next1 = adj[8];
	adj[18]->next2 = adj[17];
	adj[19]->next1 = adj[0];
	adj[19]->next2 = adj[12];
}

struct node{
    string name;
    node *next;
};

class Queue_Stack{
    private:
    node *frnt;
    node *rear;
    public:
    void init();
    bool check_empty();
    void enque(string);
    void dequ();
    void do_BFS(adj_list**, string, string);

    void push(string);
    void pop();
    void do_DFS(adj_list**, string,string);
};

void Queue_Stack :: init(){
    frnt = NULL;
    rear = NULL;
}

bool Queue_Stack :: check_empty(){
    if(frnt == NULL && rear == NULL){
    return true;
    }
    else{
    return false;
    }
}

void Queue_Stack :: enque(string str){
    node *temp = new node;
    temp->name = str;
    temp->next = NULL;
    if(check_empty()){
        frnt = temp;
        rear = frnt;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

void Queue_Stack :: dequ(){
    node *temp = new node;
    if(frnt == NULL){
    //propose error message if possible
    }
    else{
    temp = frnt;
    frnt= frnt->next;
    delete temp;
    }
}


void Queue_Stack :: do_BFS(adj_list ** adjacent_list, string src, string trgt){

    string parent[20];
    string path[20];
    int src_pos, trgt_pos;

    for(int i = 0; i<20; i++){
        if(src == adjacent_list[i]->city_name){
        parent[i] = "NULL";
        src_pos = i;
        }
        if(trgt == adjacent_list[i]->city_name){
        trgt_pos = i;
        }
    }
    for(int i=0; i<20; i++){
        path[i] = "NULL";
    }

    int num_nodes_exp = 0;

    enque(src);
    while(frnt!=NULL && frnt->name!=trgt){
        for(int i = 0; i<20; i++){
            if(frnt->name == adjacent_list[i]->city_name){
                adjacent_list[i]->visited = true;
                if(adjacent_list[i]->next1!=NULL && adjacent_list[i]->next1->visited==false){
                    enque(adjacent_list[i]->next1->city_name);
                    adjacent_list[i]->next1->visited = true;
                    for(int j=0; j<20;j++){
                        if(adjacent_list[i]->next1->city_name == adjacent_list[j]->city_name){
                            if(parent[j]!= "NULL"){
                                parent[j] = adjacent_list[i]->city_name;
                            }
                        }
                    }
                }
                if(adjacent_list[i]->next2!=NULL && adjacent_list[i]->next2->visited==false){
                    enque(adjacent_list[i]->next2->city_name);
                    adjacent_list[i]->next2->visited = true;
                    for(int j=0; j<20;j++){
                        if(adjacent_list[i]->next2->city_name == adjacent_list[j]->city_name){
                            if(parent[j]!= "NULL"){
                                parent[j] = adjacent_list[i]->city_name;
                            }
                        }
                    }
                }
                if(adjacent_list[i]->next3!=NULL && adjacent_list[i]->next3->visited==false){
                    enque(adjacent_list[i]->next3->city_name);
                    adjacent_list[i]->next3->visited = true;
                    for(int j=0; j<20;j++){
                        if(adjacent_list[i]->next3->city_name == adjacent_list[j]->city_name){
                            if(parent[j]!= "NULL"){
                                parent[j] = adjacent_list[i]->city_name;
                            }
                        }
                    }
                }
                if(adjacent_list[i]->next4!=NULL && adjacent_list[i]->next4->visited==false){
                    enque(adjacent_list[i]->next4->city_name);
                    adjacent_list[i]->next4->visited = true;
                    for(int j=0; j<20;j++){
                        if(adjacent_list[i]->next4->city_name == adjacent_list[j]->city_name){
                         if(parent[j]!= "NULL"){
                                parent[j] = adjacent_list[i]->city_name;
                            }
                        }
                    }

                }
        }
    }
        dequ();
        num_nodes_exp++;
    }

    int k,a, path_length;
    a=0;
    path_length = 0;
    k=trgt_pos;
    cout<<"Number of nodes expanded ::"<<num_nodes_exp<<endl;
    cout<<"the path from "<<src <<" to "<< trgt <<" with former as source is "<<endl;

    while(parent[k] != "NULL"){
        for(int n = 0; n<20; n++){
        if(adjacent_list[n]->city_name == parent[k]){
            path[a]=parent[k];
            k = n;
            a++;
            path_length++;
        }
        }
    }
    cout<<"Path ::"<<trgt;
    for(int incr = 0;incr<20;incr++){
        if(path[incr]!="NULL"){
        cout<<"<-"<<path[incr];
        }
    }
    cout<<endl<<"The path length is "<<path_length<<endl;
    cout<<"Number of nodes on the path "<<(path_length +1)<<endl;

}
// DFS
//**********************************************************************************************

void Queue_Stack :: push(string str){
    node *temp = new node;
    temp->name = str;
    temp->next = NULL;
    if(check_empty()){
        frnt = temp;
        rear = frnt;
    }
    else{
        temp->next = frnt;
        frnt = temp;
    }
}

void Queue_Stack :: pop(){
    node *temp = new node;
    if(frnt == NULL){
    // propose error message if possible
    }
    else{
    temp = frnt;
    frnt= frnt->next;
    delete temp;
    }
}

void Queue_Stack :: do_DFS(adj_list ** adjacent_list, string src, string trgt){

    string parent[20];
    string path[20];
    int src_pos, trgt_pos;

    for(int i = 0; i<20; i++){
        if(src == adjacent_list[i]->city_name){
        parent[i] = "NILL";
        src_pos = i;
        }
        if(trgt == adjacent_list[i]->city_name){
        trgt_pos = i;
        }
    }
    for(int i=0; i<20; i++){
        path[i] = "NULL";
    }

    push("Begin");
    push(src);
    int num_nodes_exp = 0;
    while(frnt!=NULL && frnt->name!=trgt){
        for(int i = 0; i<20; i++){
             if(frnt->name!="Begin"){
             if(frnt->name == adjacent_list[i]->city_name){
                    adjacent_list[i]->visited = true;
                if(adjacent_list[i]->next1!=NULL && adjacent_list[i]->next1->visited==false){
                    push(adjacent_list[i]->next1->city_name);
                    num_nodes_exp++;
                    adjacent_list[i]->next1->visited = true;
                    for(int j=0; j<20;j++){
                        if(adjacent_list[i]->next1->city_name == adjacent_list[j]->city_name){

                            if(parent[j]!= "NILL"){
                                parent[j] = adjacent_list[i]->city_name;
                            }
                        }
                    }
                }
                else if(adjacent_list[i]->next2!=NULL && adjacent_list[i]->next2->visited==false){
                    push(adjacent_list[i]->next2->city_name);
                    num_nodes_exp++;
                    adjacent_list[i]->next2->visited = true;
                    for(int j=0; j<20;j++){
                        if(adjacent_list[i]->next2->city_name == adjacent_list[j]->city_name){

                            if(parent[j]!= "NILL"){
                                parent[j] = adjacent_list[i]->city_name;
                            }
                        }
                    }
                }
                else if(adjacent_list[i]->next3!=NULL && adjacent_list[i]->next3->visited==false){
                    push(adjacent_list[i]->next3->city_name);
                    num_nodes_exp++;
                    adjacent_list[i]->next3->visited = true;
                    for(int j=0; j<20;j++){
                        if(adjacent_list[i]->next3->city_name == adjacent_list[j]->city_name){

                            if(parent[j]!= "NILL"){
                                parent[j] = adjacent_list[i]->city_name;
                            }
                        }
                    }
                }
                else if(adjacent_list[i]->next4!=NULL && adjacent_list[i]->next4->visited==false){
                    push(adjacent_list[i]->next4->city_name);
                    num_nodes_exp++;
                    adjacent_list[i]->next4->visited = true;
                    for(int j=0; j<20;j++){
                        if(adjacent_list[i]->next4->city_name == adjacent_list[j]->city_name){

                         if(parent[j]!= "NILL"){
                                parent[j] = adjacent_list[i]->city_name;
                            }
                        }
                    }

                }
                else{
                pop();
                }
        }
    }
    }
        if(frnt->name == "Begin"){
        pop();
    }
    }


    int k,a,path_length;
    a=0;
    path_length = 0;
    k=trgt_pos;
    cout<<"Number of nodes expanded ::"<<num_nodes_exp<<endl;
    cout<<"the path from "<<src <<" to "<< trgt <<" with former as source is "<<endl;
    while(parent[k] != "NILL"){
        for(int n = 0; n<20; n++){
        if(adjacent_list[n]->city_name == parent[k]){
            path[a]=parent[k];
            k = n;
            a++;
            path_length++;
            }
            }
        }
        cout<<"Path ::"<<trgt;
        for(int incr = 0;incr<20;incr++){
            if(path[incr]!="NULL"){
            cout<<"<-"<<path[incr];
            }
        }
    cout<<endl<<"The path length is "<<path_length<<endl;
    cout<<"Number of nodes on the path "<<(path_length +1)<<endl;

}
//**********************************************************************************************




int main( int argc, char *argv[]){
    string src, trgt,search_ty;
    int usr_choice;
    src = argv[2];
    trgt = argv[3];
    adj_list **adj;
	adj = new adj_list*[20];
	fill_adj_list(adj);
	Queue_Stack que;
	que.init();

	Queue_Stack stac;
	stac.init();
	search_ty = argv[1];
	if(search_ty == "BFS"){
        usr_choice = 1;
	}
	else if(search_ty == "DFS"){
        usr_choice = 2;
	}

	switch(usr_choice){
	case 1 :
        que.do_BFS( adj,src,trgt);
        break;
    case 2 :
        stac.do_DFS(adj,src,trgt);
        break;
    default:
        cout<<"You picked a wrong option"<<endl;
	}

}
