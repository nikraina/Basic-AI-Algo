/*
    Name :: Nikhil Raina
    UnityID :: nraina
    StudentID :: 200105282
*/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<math.h>

#define pi 3.141593

using namespace std;


struct city_node{
	string city_name;
    double latitude;
    double longitude;
};

struct city_roads{
    string city1;
    string city2;
    bool visited;
    double distance;
};

struct que_node{
    string city_name;
    double weight;
    double path_cost;
    que_node *next;
};

city_roads* fill_data(string city1, string city2, double distance){
    city_roads *current_road = new city_roads;
    current_road->city1 = city1;
    current_road->city2 = city2;
    current_road->distance = distance;
    current_road->visited = false;
    return current_road;
}

city_node* fill_data(string city_name, double latitude, double longitude){
    city_node *current_city = new city_node;
    current_city->city_name = city_name;
    current_city->latitude = latitude;
    current_city->longitude = longitude;
    return current_city;
}

void fill_city_data(city_node **city_list){

    for(int i = 0; i<112; i++){
		city_list[i] = new city_node;
    }
	int current = 0;
       city_list[current] = fill_data("albanyGA", 31.58, 84.17);
       current++;
       city_list[current] = fill_data("albanyNY", 42.66, 73.78);
       current++;
       city_list[current] = fill_data("albuquerque", 35.11, 106.61);
       current++;
       city_list[current] = fill_data("atlanta", 33.76, 84.40);
       current++;
       city_list[current] = fill_data("augusta", 33.43, 82.02);
       current++;
       city_list[current] = fill_data("austin", 30.30, 97.75);
       current++;
       city_list[current] = fill_data("bakersfield", 35.36, 119.03);
       current++;
       city_list[current] = fill_data("baltimore", 39.31, 76.62);
       current++;
       city_list[current] = fill_data("batonRouge", 30.46, 91.14);
       current++;
       city_list[current] = fill_data("beaumont", 30.08, 94.13);
       current++;
       city_list[current] = fill_data("boise", 43.61, 116.24);
       current++;
       city_list[current] = fill_data("boston", 42.32, 71.09);
       current++;
       city_list[current] = fill_data("buffalo", 42.90, 78.85);
       current++;
       city_list[current] = fill_data("calgary", 51.00, 114.00);
       current++;
       city_list[current] = fill_data("charlotte", 35.21, 80.83);
       current++;
       city_list[current] = fill_data("chattanooga", 35.05, 85.27);
       current++;
       city_list[current] = fill_data("chicago", 41.84, 87.68);
       current++;
       city_list[current] = fill_data("cincinnati", 39.14, 84.50);
       current++;
       city_list[current] = fill_data("cleveland", 41.48, 81.67);
       current++;
       city_list[current] = fill_data("coloradoSprings", 38.86, 104.79);
       current++;
       city_list[current] = fill_data("columbus", 39.99, 82.99);
       current++;
       city_list[current] = fill_data("dallas", 32.80, 96.79);
       current++;
       city_list[current] = fill_data("dayton", 39.76, 84.20);
       current++;
       city_list[current] = fill_data("daytonaBeach", 29.21, 81.04);
       current++;
       city_list[current] = fill_data("denver", 39.73, 104.97);
       current++;
       city_list[current] = fill_data("desMoines", 41.59, 93.62);
       current++;
       city_list[current] = fill_data("elPaso", 31.79, 106.42);
       current++;
       city_list[current] = fill_data("eugene", 44.06, 123.11);
       current++;
       city_list[current] = fill_data("europe", 48.87, 2.33);
       current++;
       city_list[current] = fill_data("ftWorth", 32.74, 97.33);
       current++;
       city_list[current] = fill_data("fresno", 36.78, 119.79);
       current++;
       city_list[current] = fill_data("grandJunction", 39.08, 108.56);
       current++;
       city_list[current] = fill_data("greenBay", 44.51, 88.02);
       current++;
       city_list[current] = fill_data("greensboro", 36.08, 79.82);
       current++;
       city_list[current] = fill_data("houston", 29.76, 95.38);
       current++;
       city_list[current] = fill_data("indianapolis", 39.79, 86.15);
       current++;
       city_list[current] = fill_data("jacksonville", 30.32, 81.66);
       current++;
       city_list[current] = fill_data("japan", 35.68, 220.23);
       current++;
       city_list[current] = fill_data("kansasCity", 39.08, 94.56);
       current++;
       city_list[current] = fill_data("keyWest", 24.56, 81.78);
       current++;
       city_list[current] = fill_data("lafayette", 30.21, 92.03);
       current++;
       city_list[current] = fill_data("lakeCity", 30.19, 82.64);
       current++;
       city_list[current] = fill_data("laredo", 27.52, 99.49);
       current++;
       city_list[current] = fill_data("lasVegas", 36.19, 115.22);
       current++;
       city_list[current] = fill_data("lincoln", 40.81, 96.68);
       current++;
       city_list[current] = fill_data("littleRock", 34.74, 92.33);
       current++;
       city_list[current] = fill_data("losAngeles", 34.03, 118.17);
       current++;
       city_list[current] = fill_data("macon", 32.83, 83.65);
       current++;
       city_list[current] = fill_data("medford", 42.33, 122.86);
       current++;
       city_list[current] = fill_data("memphis", 35.12, 89.97);
       current++;
       city_list[current] = fill_data("mexia", 31.68, 96.48);
       current++;
       city_list[current] = fill_data("mexico", 19.40, 99.12);
       current++;
       city_list[current] = fill_data("miami", 25.79, 80.22);
       current++;
       city_list[current] = fill_data("midland", 43.62, 84.23);
       current++;
       city_list[current] = fill_data("milwaukee", 43.05, 87.96);
       current++;
       city_list[current] = fill_data("minneapolis", 44.96, 93.27);
       current++;
       city_list[current] = fill_data("modesto", 37.66, 120.99);
       current++;
       city_list[current] = fill_data("montreal", 45.50, 73.67);
       current++;
       city_list[current] = fill_data("nashville", 36.15, 86.76);
       current++;
       city_list[current] = fill_data("newHaven", 41.31, 72.92);
       current++;
       city_list[current] = fill_data("newOrleans", 29.97, 90.06);
       current++;
       city_list[current] = fill_data("newYork", 40.70, 73.92);
       current++;
       city_list[current] = fill_data("norfolk", 36.89, 76.26);
       current++;
       city_list[current] = fill_data("oakland", 37.80, 122.23);
       current++;
       city_list[current] = fill_data("oklahomaCity", 35.48, 97.53);
       current++;
       city_list[current] = fill_data("omaha", 41.26, 96.01);
       current++;
       city_list[current] = fill_data("orlando", 28.53, 81.38);
       current++;
       city_list[current] = fill_data("ottawa", 45.42, 75.69);
       current++;
       city_list[current] = fill_data("pensacola", 30.44, 87.21);
       current++;
       city_list[current] = fill_data("philadelphia", 40.72, 76.12);
       current++;
       city_list[current] = fill_data("phoenix", 33.53, 112.08);
       current++;
       city_list[current] = fill_data("pittsburgh", 40.40, 79.84);
       current++;
       city_list[current] = fill_data("pointReyes", 38.07, 122.81);
       current++;
       city_list[current] = fill_data("portland", 45.52, 122.64);
       current++;
       city_list[current] = fill_data("providence", 41.80, 71.36);
       current++;
       city_list[current] = fill_data("provo", 40.24, 111.66);
       current++;
       city_list[current] = fill_data("raleigh", 35.82, 78.64);
       current++;
       city_list[current] = fill_data("redding", 40.58, 122.37);
       current++;
       city_list[current] = fill_data("reno", 39.53, 119.82);
       current++;
       city_list[current] = fill_data("richmond", 37.54, 77.46);
       current++;
       city_list[current] = fill_data("rochester", 43.17, 77.61);
       current++;
       city_list[current] = fill_data("sacramento", 38.56, 121.47);
       current++;
       city_list[current] = fill_data("salem", 44.93, 123.03);
       current++;
       city_list[current] = fill_data("salinas", 36.68, 121.64);
       current++;
       city_list[current] = fill_data("saltLakeCity", 40.75, 111.89);
       current++;
       city_list[current] = fill_data("sanAntonio", 29.45, 98.51);
       current++;
       city_list[current] = fill_data("sanDiego", 32.78, 117.15);
       current++;
       city_list[current] = fill_data("sanFrancisco", 37.76, 122.44);
       current++;
       city_list[current] = fill_data("sanJose", 37.30, 121.87);
       current++;
       city_list[current] = fill_data("sanLuisObispo", 35.27, 120.66);
       current++;
       city_list[current] = fill_data("santaFe", 35.67, 105.96);
       current++;
       city_list[current] = fill_data("saultSteMarie", 46.49, 84.35);
       current++;
       city_list[current] = fill_data("savannah", 32.05, 81.10);
       current++;
       city_list[current] = fill_data("seattle", 47.63, 122.33);
       current++;
       city_list[current] = fill_data("stLouis", 38.63, 90.24);
       current++;
       city_list[current] = fill_data("stamford", 41.07, 73.54);
       current++;
       city_list[current] = fill_data("stockton", 37.98, 121.30);
       current++;
       city_list[current] = fill_data("tallahassee", 30.45, 84.27);
       current++;
       city_list[current] = fill_data("tampa", 27.97, 82.46);
       current++;
       city_list[current] = fill_data("thunderBay", 48.38, 89.25);
       current++;
       city_list[current] = fill_data("toledo", 41.67, 83.58);
       current++;
       city_list[current] = fill_data("toronto", 43.65, 79.38);
       current++;
       city_list[current] = fill_data("tucson", 32.21, 110.92);
       current++;
       city_list[current] = fill_data("tulsa", 36.13, 95.94);
       current++;
       city_list[current] = fill_data("uk1", 51.30, 0.00);
       current++;
       city_list[current] = fill_data("uk2", 51.30, 0.00);
       current++;
       city_list[current] = fill_data("vancouver", 49.25, 123.10);
       current++;
       city_list[current] = fill_data("washington", 38.91, 77.01);
       current++;
       city_list[current] = fill_data("westPalmBeach", 26.43, 80.03);
       current++;
       city_list[current] = fill_data("wichita", 37.69, 97.34);
       current++;
       city_list[current] = fill_data("winnipeg", 49.90, 97.13);
       current++;
       city_list[current] = fill_data("yuma", 32.69, 114.62);

}


void fill_city_road(city_roads **city_road_list){
    for(int i = 0; i<123; i++){
		city_road_list[i] = new city_roads;
	}
	int current = 0;
       city_road_list[current] = fill_data("albanyNY", "montreal", 226);
       current++;
       city_road_list[current] = fill_data("albanyNY", "boston", 166);
       current++;
       city_road_list[current] = fill_data("albanyNY", "rochester", 148);
       current++;
       city_road_list[current] = fill_data("albanyGA", "tallahassee", 120);
       current++;
       city_road_list[current] = fill_data("albanyGA", "macon", 106);
       current++;
       city_road_list[current] = fill_data("albuquerque", "elPaso", 267);
       current++;
       city_road_list[current] = fill_data("albuquerque", "santaFe", 61);
       current++;
       city_road_list[current] = fill_data("atlanta", "macon", 82);
       current++;
       city_road_list[current] = fill_data("atlanta", "chattanooga", 117);
       current++;
       city_road_list[current] = fill_data("augusta", "charlotte", 161);
       current++;
       city_road_list[current] = fill_data("augusta", "savannah", 131);
       current++;
       city_road_list[current] = fill_data("austin", "houston", 186);
       current++;
       city_road_list[current] = fill_data("austin", "sanAntonio", 79);
       current++;
       city_road_list[current] = fill_data("bakersfield", "losAngeles", 112);
       current++;
       city_road_list[current] = fill_data("bakersfield", "fresno", 107);
       current++;
       city_road_list[current] = fill_data("baltimore", "philadelphia", 102);
       current++;
       city_road_list[current] = fill_data("baltimore", "washington", 45);
       current++;
       city_road_list[current] = fill_data("batonRouge", "lafayette", 50);
       current++;
       city_road_list[current] = fill_data("batonRouge", "newOrleans", 80);
       current++;
       city_road_list[current] = fill_data("beaumont", "houston", 69);
       current++;
       city_road_list[current] = fill_data("beaumont", "lafayette", 122);
       current++;
       city_road_list[current] = fill_data("boise", "saltLakeCity", 349);
       current++;
       city_road_list[current] = fill_data("boise", "portland", 428);
       current++;
       city_road_list[current] = fill_data("boston", "providence", 51);
       current++;
       city_road_list[current] = fill_data("buffalo", "toronto", 105);
       current++;
       city_road_list[current] = fill_data("buffalo", "rochester", 64);
       current++;
       city_road_list[current] = fill_data("buffalo", "cleveland", 191);
       current++;
       city_road_list[current] = fill_data("calgary", "vancouver", 605);
       current++;
       city_road_list[current] = fill_data("calgary", "winnipeg", 829);
       current++;
       city_road_list[current] = fill_data("charlotte", "greensboro", 91);
       current++;
       city_road_list[current] = fill_data("chattanooga", "nashville", 129);
       current++;
       city_road_list[current] = fill_data("chicago", "milwaukee", 90);
       current++;
       city_road_list[current] = fill_data("chicago", "midland", 279);
       current++;
       city_road_list[current] = fill_data("cincinnati", "indianapolis", 110);
       current++;
       city_road_list[current] = fill_data("cincinnati", "dayton", 56);
       current++;
       city_road_list[current] = fill_data("cleveland", "pittsburgh", 157);
       current++;
       city_road_list[current] = fill_data("cleveland", "columbus", 142);
       current++;
       city_road_list[current] = fill_data("coloradoSprings", "denver", 70);
       current++;
       city_road_list[current] = fill_data("coloradoSprings", "santaFe", 316);
       current++;
       city_road_list[current] = fill_data("columbus", "dayton", 72);
       current++;
       city_road_list[current] = fill_data("dallas", "denver", 792);
       current++;
       city_road_list[current] = fill_data("dallas", "mexia", 83);
       current++;
       city_road_list[current] = fill_data("daytonaBeach", "jacksonville", 92);
       current++;
       city_road_list[current] = fill_data("daytonaBeach", "orlando", 54);
       current++;
       city_road_list[current] = fill_data("denver", "wichita", 523);
       current++;
       city_road_list[current] = fill_data("denver", "grandJunction", 246);
       current++;
       city_road_list[current] = fill_data("desMoines", "omaha", 135);
       current++;
       city_road_list[current] = fill_data("desMoines", "minneapolis", 246);
       current++;
       city_road_list[current] = fill_data("elPaso", "sanAntonio", 580);
       current++;
       city_road_list[current] = fill_data("elPaso", "tucson", 320);
       current++;
       city_road_list[current] = fill_data("eugene", "salem", 63);
       current++;
       city_road_list[current] = fill_data("eugene", "medford", 165);
       current++;
       city_road_list[current] = fill_data("europe", "philadelphia", 3939);
       current++;
       city_road_list[current] = fill_data("ftWorth", "oklahomaCity", 209);
       current++;
       city_road_list[current] = fill_data("fresno", "modesto", 109);
       current++;
       city_road_list[current] = fill_data("grandJunction", "provo", 220);
       current++;
       city_road_list[current] = fill_data("greenBay", "minneapolis", 304);
       current++;
       city_road_list[current] = fill_data("greenBay", "milwaukee", 117);
       current++;
       city_road_list[current] = fill_data("greensboro", "raleigh", 74);
       current++;
       city_road_list[current] = fill_data("houston", "mexia", 165);
       current++;
       city_road_list[current] = fill_data("indianapolis", "stLouis", 246);
       current++;
       city_road_list[current] = fill_data("jacksonville", "savannah", 140);
       current++;
       city_road_list[current] = fill_data("jacksonville", "lakeCity", 113);
       current++;
       city_road_list[current] = fill_data("japan", "pointReyes", 5131);
       current++;
       city_road_list[current] = fill_data("japan", "sanLuisObispo", 5451);
       current++;
       city_road_list[current] = fill_data("kansasCity", "tulsa", 249);
       current++;
       city_road_list[current] = fill_data("kansasCity", "stLouis", 256);
       current++;
       city_road_list[current] = fill_data("kansasCity", "wichita", 190);
       current++;
       city_road_list[current] = fill_data("keyWest", "tampa", 446);
       current++;
       city_road_list[current] = fill_data("lakeCity", "tampa", 169);
       current++;
       city_road_list[current] = fill_data("lakeCity", "tallahassee", 104);
       current++;
       city_road_list[current] = fill_data("laredo", "sanAntonio", 154);
       current++;
       city_road_list[current] = fill_data("laredo", "mexico", 741);
       current++;
       city_road_list[current] = fill_data("lasVegas", "losAngeles", 275);
       current++;
       city_road_list[current] = fill_data("lasVegas", "saltLakeCity", 486);
       current++;
       city_road_list[current] = fill_data("lincoln", "wichita", 277);
       current++;
       city_road_list[current] = fill_data("lincoln", "omaha", 58);
       current++;
       city_road_list[current] = fill_data("littleRock", "memphis", 137);
       current++;
       city_road_list[current] = fill_data("littleRock", "tulsa", 276);
       current++;
       city_road_list[current] = fill_data("losAngeles", "sanDiego", 124);
       current++;
       city_road_list[current] = fill_data("losAngeles", "sanLuisObispo", 182);
       current++;
       city_road_list[current] = fill_data("medford", "redding", 150);
       current++;
       city_road_list[current] = fill_data("memphis", "nashville", 210);
       current++;
       city_road_list[current] = fill_data("miami", "westPalmBeach", 67);
       current++;
       city_road_list[current] = fill_data("midland", "toledo", 82);
       current++;
       city_road_list[current] = fill_data("minneapolis", "winnipeg", 463);
       current++;
       city_road_list[current] = fill_data("modesto", "stockton", 29);
       current++;
       city_road_list[current] = fill_data("montreal", "ottawa", 132);
       current++;
       city_road_list[current] = fill_data("newHaven", "providence", 110);
       current++;
       city_road_list[current] = fill_data("newHaven", "stamford", 92);
       current++;
       city_road_list[current] = fill_data("newOrleans", "pensacola", 268);
       current++;
       city_road_list[current] = fill_data("newYork", "philadelphia", 101);
       current++;
       city_road_list[current] = fill_data("norfolk", "richmond", 92);
       current++;
       city_road_list[current] = fill_data("norfolk", "raleigh", 174);
       current++;
       city_road_list[current] = fill_data("oakland", "sanFrancisco", 8);
       current++;
       city_road_list[current] = fill_data("oakland", "sanJose", 42);
       current++;
       city_road_list[current] = fill_data("oklahomaCity", "tulsa", 105);
       current++;
       city_road_list[current] = fill_data("orlando", "westPalmBeach", 168);
       current++;
       city_road_list[current] = fill_data("orlando", "tampa", 84);
       current++;
       city_road_list[current] = fill_data("ottawa", "toronto", 269);
       current++;
       city_road_list[current] = fill_data("pensacola", "tallahassee", 120);
       current++;
       city_road_list[current] = fill_data("philadelphia", "pittsburgh", 319);
       current++;
       city_road_list[current] = fill_data("philadelphia", "newYork", 101);
       current++;
       city_road_list[current] = fill_data("philadelphia", "uk1", 3548);
       current++;
       city_road_list[current] = fill_data("philadelphia", "uk2", 3548);
       current++;
       city_road_list[current] = fill_data("phoenix", "tucson", 117);
       current++;
       city_road_list[current] = fill_data("phoenix", "yuma", 178);
       current++;
       city_road_list[current] = fill_data("pointReyes", "redding", 215);
       current++;
       city_road_list[current] = fill_data("pointReyes", "sacramento", 115);
       current++;
       city_road_list[current] = fill_data("portland", "seattle", 174);
       current++;
       city_road_list[current] = fill_data("portland", "salem", 47);
       current++;
       city_road_list[current] = fill_data("reno", "saltLakeCity", 520);
       current++;
       city_road_list[current] = fill_data("reno", "sacramento", 133);
       current++;
       city_road_list[current] = fill_data("richmond", "washington", 105);
       current++;
       city_road_list[current] = fill_data("sacramento", "sanFrancisco", 95);
       current++;
       city_road_list[current] = fill_data("sacramento", "stockton", 51);
       current++;
       city_road_list[current] = fill_data("salinas", "sanJose", 31);
       current++;
       city_road_list[current] = fill_data("salinas", "sanLuisObispo", 137);
       current++;
       city_road_list[current] = fill_data("sanDiego", "yuma", 172);
       current++;
       city_road_list[current] = fill_data("saultSteMarie", "thunderBay", 442);
       current++;
       city_road_list[current] = fill_data("saultSteMarie", "toronto", 436);
       current++;
       city_road_list[current] = fill_data("seattle", "vancouver", 115);
       current++;
       city_road_list[current] = fill_data("thunderBay", "winnipeg", 440);
}

class priority_que{
    private:
    que_node *frnt;
    que_node *rear;
    public:
    void init();
    bool check_empty();
    void enque(string, double, double);
    string dequ();
    void reheapify();
    double calc_heuristic(city_node*, city_node*);
    void uniform_cost(city_roads **, city_node **,string, string);
    void greedy(city_roads **, city_node **,string, string);
    void astar(city_roads **, city_node **,string, string);
};

void priority_que :: init(){
    frnt = NULL;
    rear = NULL;
}

bool priority_que :: check_empty(){
    if(frnt == NULL){
    return true;
    }
    else{
    return false;
    }
}

void priority_que :: enque(string city, double weight, double path_cost){
    que_node * temp = new que_node;
    temp->city_name = city;
    temp->weight = weight;
    temp->path_cost = path_cost;
    temp->next = NULL;
    if(check_empty() == true){
        frnt = temp;
        rear = frnt;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    reheapify();
}

void priority_que :: reheapify(){
    que_node *temp;
    que_node *smallest;
    que_node *exchange = new que_node;
    temp = frnt;
    smallest = frnt;
    while(temp!=NULL){
        if(smallest->weight > temp->weight){
            smallest = temp;
        }
        temp = temp->next;
    }
    temp = frnt;
    while(temp->next!=NULL){
        if(temp->next->city_name == smallest->city_name){
            exchange->city_name = smallest->city_name;
            exchange->weight = smallest->weight;
            exchange->path_cost = smallest->path_cost;
            temp->next->city_name = frnt->city_name;
            temp->next->weight = frnt->weight;
            temp->next->path_cost = frnt->path_cost;
            frnt->city_name = exchange->city_name;
            frnt->weight = exchange->weight;
            frnt->path_cost = exchange->path_cost;
        }
        temp = temp->next;

    }
}

string priority_que :: dequ(){
    que_node *temp;
    temp = frnt;
    if(frnt->next != NULL){
    frnt = frnt->next;
    }
    else{
    frnt = NULL;
    }
    return (temp->city_name);
}

void priority_que :: uniform_cost(city_roads **city_road_list, city_node **city_list, string src, string trgt){
    double initial_path_cost = 0;
    double path_cost, final_path_cost, temp_path_cost;
    double temp_final_path_cost;
    temp_path_cost = 0;
    bool target_found = false;
    string poped_node;
    string parent [112];
    string path [112];
    string expanded_nodes[200];
    int counter = 0;
    int inc = 0;
    int nodes_expanded = 0;
    int trgt_pos;
    int path_length = 1;

    for(int i = 0; i<112; i++){
		parent[i] = "NULL";
		if(trgt == city_list[i]->city_name){
            trgt_pos = i;
		}
	}

	 for(int i = 0; i<112; i++){
		path[i] = "NULL";
	}

	for(int i = 0; i<200; i++){
		expanded_nodes[i] = "NULL";
	}

	enque(src, initial_path_cost, temp_path_cost);
	while(check_empty() == false && target_found == false){
        path_cost = frnt->weight;
        poped_node = dequ();
        expanded_nodes[counter] = poped_node;
        counter++;
        nodes_expanded++;
        if(poped_node != trgt){
            for(int i = 0; i<123; i++){
                if(city_road_list[i]->city1 == poped_node && city_road_list[i]->visited == false){
                    temp_path_cost = path_cost+city_road_list[i]->distance;
                    enque(city_road_list[i]->city2,(path_cost+city_road_list[i]->distance),(temp_path_cost) );
                    city_road_list[i]->visited = true;
                    for(int j = 0; j<112; j++){
                        if(city_list[j]->city_name == city_road_list[i]->city2){
                            parent[j] = city_road_list[i]->city1;
                        }
                    }
                    if(city_road_list[i]->city1 == trgt|| city_road_list[i]->city2 == trgt){
                        target_found = true;
                        final_path_cost = path_cost+city_road_list[i]->distance;
                    }
                }
                else if(city_road_list[i]->city2 == poped_node && city_road_list[i]->visited == false){
                    temp_path_cost = path_cost+city_road_list[i]->distance;
                    enque(city_road_list[i]->city1,(path_cost+city_road_list[i]->distance), (temp_path_cost));
                    city_road_list[i]->visited = true;
                    for(int j = 0; j<112; j++){
                        if(city_list[j]->city_name == city_road_list[i]->city1){
                            parent[j] = city_road_list[i]->city2;
                        }
                    }
                    if(city_road_list[i]->city1 == trgt|| city_road_list[i]->city2 == trgt){
                        target_found = true;
                        final_path_cost = path_cost+city_road_list[i]->distance;
                    }
                }

            }
        }
	else{
	target_found = true;
	}
	}

	int k = trgt_pos;
	int a = 0;
	while(parent[k] != "NULL"){
        for(int n = 0; n<112; n++){
            if(city_list[n]->city_name == parent[k]){
                path[a]=parent[k];
                k = n;
                a++;
            }
        }

}

    cout<<"The expanded nodes are ::";
    counter = 0;
    while(expanded_nodes[counter]!= "NULL"){
    cout<<expanded_nodes[counter]<< " ";
    counter++;
    }
    cout<<endl;
    cout<<"Path ::"<<trgt;
    for(int incr = 0;incr<112;incr++){
        if(path[incr]!="NULL"){
        cout<<"<-"<<path[incr];
        path_length++;
        }
    }
    cout<<endl;
    cout<<"Number of nodes expanded :"<<nodes_expanded<<endl;
    cout<<"The path cost is : "<<final_path_cost<<endl;
    cout<<"The number of nodes in path is : "<<path_length<<endl;
}

double priority_que :: calc_heuristic(city_node *city1, city_node *city2){
    return (sqrt( pow((69.5 * (city1->latitude - city2->latitude)),2) + (69.5 * cos((city1->latitude + city2->latitude)/360 * pi) * pow((city1->longitude - city2->longitude),2))));
}

void priority_que :: greedy(city_roads **city_road_list, city_node **city_list, string src, string trgt){
    double initial_path_cost = 0;
    double path_cost, final_path_cost, temp_path_cost;
    temp_path_cost = 0;
    bool target_found = false;
    string poped_node;
    string parent [112];
    string path [112];
    string expanded_nodes[112];
    int counter = 0;
    int inc = 0;
    int nodes_expanded = 0;
    int trgt_pos;
    int curr_pos;
    int src_pos;
    int path_length = 1;

    for(int i = 0; i<112; i++){
		parent[i] = "NULL";
		if(trgt == city_list[i]->city_name){
            trgt_pos = i;
		}
		if(src == city_list[i]->city_name){
            src_pos = i;
		}
	}

	 for(int i = 0; i<112; i++){
		path[i] = "NULL";
	}

	for(int i = 0; i<112; i++){
		expanded_nodes[i] = "NULL";
	}

	enque(src, initial_path_cost, temp_path_cost);
	while(check_empty() == false && target_found == false){
        path_cost = frnt->weight;
        temp_path_cost = frnt->path_cost;
        poped_node = dequ();
        expanded_nodes[counter] = poped_node;
        counter++;
        nodes_expanded++;
        if(poped_node != trgt){
            for(int i = 0; i<123; i++){
                if(city_road_list[i]->city1 == poped_node && city_road_list[i]->visited == false){
                    for(int k = 0; k<112; k++){
                        if(city_list[k]->city_name == poped_node){
                            curr_pos = k;
                        }
                    }

                    enque(city_road_list[i]->city2,calc_heuristic(city_list[curr_pos],city_list[trgt_pos]),(temp_path_cost+city_road_list[i]->distance));
                    city_road_list[i]->visited = true;
                                for(int j = 0; j<112; j++){
                        if(city_list[j]->city_name == city_road_list[i]->city2){
                            parent[j] = city_road_list[i]->city1;
                        }
                    }
                    if(city_road_list[i]->city1 == trgt|| city_road_list[i]->city2 == trgt){
                        target_found = true;
                        final_path_cost = temp_path_cost+city_road_list[i]->distance;
                    }
                }
                else if(city_road_list[i]->city2 == poped_node && city_road_list[i]->visited == false){
                        for(int k = 0; k<112; k++){
                            if(city_list[k]->city_name == poped_node){
                                curr_pos = k;
                            }
                    }
                    enque(city_road_list[i]->city1,calc_heuristic(city_list[curr_pos],city_list[trgt_pos]),(temp_path_cost+city_road_list[i]->distance));
                    city_road_list[i]->visited = true;
                    for(int j = 0; j<112; j++){
                        if(city_list[j]->city_name == city_road_list[i]->city1){
                            parent[j] = city_road_list[i]->city2;
                        }
                    }
                    if(city_road_list[i]->city1 == trgt|| city_road_list[i]->city2 == trgt){
                        target_found = true;
                        final_path_cost = temp_path_cost+city_road_list[i]->distance;
                    }
                }
        }
	}
	else{
	target_found = true;
	}
	}

	int k = trgt_pos;
	int a = 0;
	while(parent[k] != "NULL"){
        for(int n = 0; n<112; n++){
        if(city_list[n]->city_name == parent[k]){
            path[a]=parent[k];
            k = n;
            a++;
        }
        }

}
    cout<<"The expanded nodes are ::";
    counter = 0;
    while(expanded_nodes[counter]!= "NULL"){
    cout<<expanded_nodes[counter]<< " ";
    counter++;
    }
    cout<<endl;

    cout<<"Path ::"<<trgt;
    for(int incr = 0;incr<112;incr++){
        if(path[incr]!="NULL"){
        cout<<"<-"<<path[incr];
        path_length++;
        }
    }
    cout<<endl;
    cout<<"Number of nodes expanded :"<<nodes_expanded<<endl;
    cout<<"The path cost is :"<<final_path_cost<<endl;
    cout<<"The number of nodes in path is : "<<path_length<<endl;
}

void priority_que :: astar(city_roads **city_road_list, city_node **city_list, string src, string trgt){

double initial_path_cost = 0;
    double path_cost, final_path_cost, temp_path_cost;
    temp_path_cost = 0;
    bool target_found = false;
    string poped_node;
    string parent [112];
    string path [112];
    string expanded_nodes[112];
    int counter = 0;
    int inc = 0;
    int nodes_expanded = 0;
    int trgt_pos;
    int curr_pos;
    int src_pos;
    int path_length = 1;

    for(int i = 0; i<112; i++){
		parent[i] = "NULL";
		if(trgt == city_list[i]->city_name){
            trgt_pos = i;
		}
		if(src == city_list[i]->city_name){
            src_pos = i;
		}
	}

	 for(int i = 0; i<112; i++){
		path[i] = "NULL";
	}

	for(int i = 0; i<112; i++){
		expanded_nodes[i] = "NULL";
	}

	enque(src, initial_path_cost, temp_path_cost);
	while(check_empty() == false && target_found == false){
        path_cost = frnt->weight;
        temp_path_cost = frnt->path_cost;
        poped_node = dequ();
        expanded_nodes[counter] = poped_node;
        counter++;
        nodes_expanded++;
        if(poped_node != trgt){
            for(int i = 0; i<123; i++){
                if(city_road_list[i]->city1 == poped_node && city_road_list[i]->visited == false){
                    for(int k = 0; k<112; k++){
                        if(city_list[k]->city_name == poped_node){
                            curr_pos = k;
                        }
                    }
                    enque(city_road_list[i]->city2,(calc_heuristic(city_list[curr_pos],city_list[trgt_pos])+path_cost+city_road_list[i]->distance), (temp_path_cost+city_road_list[i]->distance));
                    city_road_list[i]->visited = true;
                                for(int j = 0; j<112; j++){
                                    if(city_list[j]->city_name == city_road_list[i]->city2){
                                        parent[j] = city_road_list[i]->city1;
                                    }
                                }
                    if(city_road_list[i]->city1 == trgt|| city_road_list[i]->city2 == trgt){
                        target_found = true;
                        final_path_cost = temp_path_cost+city_road_list[i]->distance;
                    }
                }
                else if(city_road_list[i]->city2 == poped_node && city_road_list[i]->visited == false){
                        for(int k = 0; k<112; k++){
                            if(city_list[k]->city_name == poped_node){
                                curr_pos = k;
                            }
                        }
                    enque(city_road_list[i]->city1,(calc_heuristic(city_list[curr_pos],city_list[trgt_pos])+path_cost+city_road_list[i]->distance), (temp_path_cost + city_road_list[i]->distance));
                    city_road_list[i]->visited = true;
                    for(int j = 0; j<112; j++){
                        if(city_list[j]->city_name == city_road_list[i]->city1){
                            parent[j] = city_road_list[i]->city2;
                        }
                    }
                    if(city_road_list[i]->city1 == trgt|| city_road_list[i]->city2 == trgt){
                        target_found = true;
                        final_path_cost = temp_path_cost+city_road_list[i]->distance;
                    }
                }
        }
	}
	else{
	target_found = true;
	}
	}

	int k = trgt_pos;
	int a = 0;
	while(parent[k] != "NULL"){
        for(int n = 0; n<112; n++){
        if(city_list[n]->city_name == parent[k]){
            path[a]=parent[k];
            k = n;
            a++;
        }
        }

}

    cout<<"The expanded nodes are ::";
    counter = 0;
    while(expanded_nodes[counter]!= "NULL"){
    cout<<expanded_nodes[counter]<< " ";
    counter++;
    }
    cout<<endl;
    cout<<"Path ::"<<trgt;
    for(int incr = 0;incr<112;incr++){
        if(path[incr]!="NULL"){
        cout<<"<-"<<path[incr];
        path_length++;
        }
    }
    cout<<endl;
    cout<<"Number of nodes expanded :"<<nodes_expanded<<endl;
    cout<<"The path cost is :"<<final_path_cost<<endl;
    cout<<"The number of nodes in path is : "<<path_length<<endl;

}

int main(int argc, char *argv[]){
    city_node **city_list;
    city_list = new city_node*[112];
    fill_city_data(city_list);
    city_roads **city_road_list;
    city_road_list = new city_roads*[123];
    fill_city_road(city_road_list);
    priority_que que;
    que.init();
    string city1, city2;
    string usr_input;
    //cout<<"Give city1"<<endl;
    //cin>>city1;
    //cout<<"Give city2"<<endl;
    //cin>>city2;
    //cout<<"What algo you want to use? :: 1 for uniform, 2 for greedy, 3 for astar"<<endl;
    //cin>>usr_input;
    usr_input = argv[1];
    city1 = argv[2];
    city2 = argv[3];
    if(usr_input == "uniform"){
        que.uniform_cost(city_road_list, city_list,city1, city2);
    }else if(usr_input == "greedy"){
        que.greedy(city_road_list, city_list, city1, city2);
    }
    else if(usr_input == "astar"){
        que.astar(city_road_list, city_list, city1, city2);
    }
    return 0;
}
