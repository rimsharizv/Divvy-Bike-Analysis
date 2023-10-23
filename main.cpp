//
// Author: Rimsha Rizvi, Spring 2021, CS141
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>


using namespace std;

/*
 * Array of structs to store:
     * 1. Stations: Defining the set of DIVVY Stations
     * 2. Bikes: Defining a set of DIVVY Bike Trips
     * 3. Distances: For command 4 - This array stores values of the station id's and names, along with 
                     the distances between them
     * 4. ListStations: For command 5, 6 - A set of all DIVVY Stations and bike trips
*/

struct Stations
{
    string stationid;
    int capacity;
    double latitude;
    double longitude;
    string name;
};

struct Bikes
{
    string tripid;
    string bikeid;
    string stationid_s;
    string stationid_e;
    int duration; 
    string time;
};

struct Distances
{
    string stationid;
    string name;
    double distance;
};

struct ListStations
{
    string name;
    string stationid;
    double latitude;
    double longitude;
    int capacity;
    int bikeTrips;
};


// To input data from the files into the array of structs respectively
Stations* inputData(string filename, int& N)
{
    ifstream infile;
    infile.open(filename);
    if (!infile.good())
    {
        N = 0;
        return nullptr;
    }
    infile >> N;
    Stations* station;
    station = new Stations[N];
    
    for (int i = 0; i < N; i++)
    {
        string name_temp;
        infile >> station[i].stationid;
        infile >> station[i].capacity;
        infile >> station[i].latitude;
        infile >> station[i].longitude;
        getline(infile, name_temp);
        name_temp.erase(0,1);
        station[i].name = name_temp;
    }
    
   infile.close();

   return station;
}

Bikes* inputData2(string filename, int& N)
{
    ifstream infile2;
    infile2.open(filename);
    if (!infile2.good())
    {
        N = 0;
        return nullptr;
    }
    infile2 >> N;
    Bikes* bike;
    bike = new Bikes[N];
    
    int i2 = 0;
    while (!infile2.eof() && i2 < N)
    {
        infile2 >> bike[i2].tripid >> bike[i2].bikeid >>
            bike[i2].stationid_s >> bike[i2].stationid_e >>
            bike[i2].duration >> bike[i2].time;
        ++i2;
    }  
    
   infile2.close();

   return bike;
}


/*
// command 1 - statsFunction
//
// Outputs the total # of stations, the total # of trips, and the total capacity across all the stations
*/
void statsFunction(Stations station[], int s, int s2){
    
    cout << "  stations: " << s << endl;
    cout << "  trips: " << s2 << endl;
    
    int total = 0;
    
    for (int i=0; i<s; i++){
        total += station[i].capacity;  
    }
    
    cout << "  total bike capacity: " << total << endl;
}


/*
// command 2 - bikeDuration
//
// Analyzes the bike trips, and then categorizes the trips into 1 of 5 categories using durations
*/

void bikeDuration(Bikes bike[], int s2){
    
    int trip1 = 0; int trip2 = 0; int trip3 = 0; int trip4 = 0; int trip5 = 0;
    for (int i = 0; i<s2; ++i){
        
        //t<=30 mins / 1800 seconds
        if(bike[i].duration <= 1800){
            trip1 += 1;
        }
        //30<t<=60 mins / 1800<t<=3600 seconds
        else if(bike[i].duration > 1800 && bike[i].duration <= 3600){
            trip2 += 1;
        }
        //60<t<=120 mins / 3600<t<=7200 seconds
        else if(bike[i].duration > 3600 && bike[i].duration <= 7200){
            trip3 += 1;
        }
        //120<t<=300 mins // 7200<t<=18000 seconds
        else if(bike[i].duration > 7200 && bike[i].duration <= 18000){
            trip4 += 1;
        }
        //t>300 mins // t >18000 seconds
        else{
            trip5 += 1;
        }
    }
    
    cout << "  trips <= 30 mins: " << trip1 << endl;
    cout << "  trips 30..60 mins: " << trip2 << endl;
    cout << "  trips 1-2 hrs: " << trip3 << endl;
    cout << "  trips 2-5 hrs: " << trip4 << endl;
    cout << "  trips > 5 hrs: " << trip5 << endl;
    
}


/*
// command 3 - countStart, histogram
//
// Analyzes the bike trips, and then categorizes the trips into 1 of 24 categories using starting hour
*/
    // countStart - updates time values depending on the hour
void countStart(int hour,
                int& time1, int& time2, int& time3, int& time4, int& time5, int& time6,
                int& time7, int& time8, int& time9, int& time10, int& time11, int& time12,
                int& time13, int& time14, int& time15, int& time16, int& time17, int& time18,
                int& time19, int& time20, int& time21, int& time22, int& time23, int& time24){
    
    if (hour == 0){
        time1 += 1;}
    else if (hour == 1){
        time2 += 1;}
    else if (hour == 2){
        time3 += 1;}
    else if (hour == 3){
        time4 += 1;}
    else if (hour == 4){
        time5 += 1;}
    else if (hour == 5){
        time6 += 1;}
    else if (hour == 6){
        time7 += 1;}
    else if (hour == 7){
        time8 += 1;}
    else if (hour == 8){
        time9 += 1;}
    else if (hour == 9){
        time10 += 1;}
    else if (hour == 10){
        time11 += 1;}
    else if (hour == 11){
        time12 += 1;}
    else if (hour == 12){
        time13 += 1;}
    else if (hour == 13){
        time14 += 1;}
    else if (hour == 14){
        time15 += 1;}
    else if (hour == 15){
        time16 += 1;}
    else if (hour == 16){
        time17 += 1;}
    else if (hour == 17){
        time18 += 1;}
    else if (hour == 18){
        time19 += 1;}
    else if (hour == 19){
        time20 += 1;}
    else if (hour == 20){
        time21 += 1;}
    else if (hour == 21){
        time22 += 1;}
    else if (hour == 22){
        time23 += 1;}
    else if (hour == 23){
        time24 += 1;}
}

    // histogram - main function for command 3: 
    //             converts time in bike data into integers by splitting the string 
void histogram(Bikes bike[], int s2){
    
    int time1 = 0 ; int time2 = 0; int time3 = 0 ; int time4 = 0; int time5 = 0 ; int time6 = 0;
    int time7 = 0 ; int time8 = 0; int time9 = 0 ; int time10 = 0; int time11 = 0 ; int time12 = 0;
    int time13 = 0 ; int time14 = 0; int time15 = 0 ; int time16 = 0; int time17 = 0 ; int time18 = 0;
    int time19 = 0 ; int time20 = 0; int time21 = 0 ; int time22 = 0; int time23 = 0 ; int time24 = 0;
    
    string hour; string hour_first; string hour_second; string temp;
    int hour_int;
    for (int i=0; i<s2; ++i){
        temp = bike[i].time;
        
        hour_first = temp.substr(0,1);
        hour_second = temp.substr(1,1);
        
        if (hour_second == ":"){ //checking if hour is two digit;
            hour = hour_first;
        }
        else{
            hour = hour_first+hour_second;
        }
        hour_int = stoi(hour);
        
        countStart(hour_int, time1, time2, time3, time4, time5, time6,
                   time7, time8, time9, time10, time11, time12,
                   time13, time14, time15, time16, time17, time18,
                   time19, time20, time21, time22, time23, time24);
        
    }
    cout << "  0: " << time1 << endl;
        cout << "  1: " << time2 << endl;
        cout << "  2: " << time3 << endl;
        cout << "  3: " << time4 << endl;
        cout << "  4: " << time5 << endl;
        cout << "  5: " << time6 << endl;
        cout << "  6: " << time7 << endl;
        cout << "  7: " << time8 << endl;
        cout << "  8: " << time9 << endl;
        cout << "  9: " << time10 << endl;
        cout << "  10: " << time11 << endl;
        cout << "  11: " << time12 << endl;
        cout << "  12: " << time13 << endl;
        cout << "  13: " << time14 << endl;
        cout << "  14: " << time15 << endl;
        cout << "  15: " << time16 << endl;
        cout << "  16: " << time17 << endl;
        cout << "  17: " << time18 << endl;
        cout << "  18: " << time19 << endl;
        cout << "  19: " << time20 << endl;
        cout << "  20: " << time21 << endl;
        cout << "  21: " << time22 << endl;
        cout << "  22: " << time23 << endl;
        cout << "  23: " << time24 << endl;
    
}


/*
// command 4
//
// Finds all stations that are <= D miles away near a given position (lat,long)
*/


//
// distBetween2Points
//
// Returns the distance in miles between 2 points (lat1, long1) and 
// (lat2, long2).  Latitudes are positive above the equator and 
// negative below; longitudes are positive heading east of Greenwich 
// and negative heading west.  Example: Chicago is (41.88, -87.63).
//
// NOTE: you may get slightly different results depending on which 
// (lat, long) pair is passed as the first parameter.
// 
// Originally written by: Prof. Hummel, U. of Illinois, Chicago, Spring 2021
// Reference: http://www8.nau.edu/cvm/latlon_formula.html
//
double distBetween2Points(double lat1, double long1, double lat2, double long2)
{
  double PI = 3.14159265;
  double earth_rad = 3963.1;  // statue miles:

  double lat1_rad = lat1 * PI / 180.0;
  double long1_rad = long1 * PI / 180.0;
  double lat2_rad = lat2 * PI / 180.0;
  double long2_rad = long2 * PI / 180.0;

  double dist = earth_rad * acos(
    (cos(lat1_rad) * cos(long1_rad) * cos(lat2_rad) * cos(long2_rad))
    +
    (cos(lat1_rad) * sin(long1_rad) * cos(lat2_rad) * sin(long2_rad))
    +
    (sin(lat1_rad) * sin(lat2_rad))
  );

  return dist;
}

    // sortByDist - sorts the array based on ascending distance values
void sortByDist(Distances compare_dist[], int count){
    for(int i=0; i<count-1; i++){
        
        int minIndex = i;
        for(int j=i+1; j<count; j++){
            if(compare_dist[j].distance < compare_dist[minIndex].distance){
                minIndex = j;
            }
        }
        
        Distances temp;
        temp = compare_dist[i];
        compare_dist[i] = compare_dist[minIndex];
        compare_dist[minIndex] = temp;
        
    }
}

    // stationsNear - main function for command 4
    //                compares bike trips distance and outputs if it is <= D miles
void stationsNear(Stations station[], int s, double lat1, double long1, double D){
    
    cout << "  The following stations are within " << D << " miles of (" << lat1 <<", " << long1 << "):" << endl;
    int count = 0;
    
    for(int i = 0; i<s; i++){
        double dist;
        dist = distBetween2Points(lat1, long1, station[i].latitude, station[i].longitude);
        if (dist <= D){
            count += 1;
        }
    }
    
    if (count == 0){
        cout << "  none found" << endl;
    }
    else{
        Distances* distArray;
        distArray = new Distances[count];

        int index = 0;

        for (int i = 0; i<s; i++){
            double dist2;
            dist2 = distBetween2Points(lat1, long1, station[i].latitude, station[i].longitude);
            if (dist2  <= D){
                distArray[index].stationid = station[i].stationid;
                distArray[index].name = station[i].name;
                distArray[index].distance = dist2;
                index++;
            }
        }
        
        sortByDist(distArray, count);

        for (int i = 0; i<count; ++i){
            cout << "  station " << distArray[i].stationid << " (" << distArray[i].name << "): " << 
                distArray[i].distance << " miles" << endl;
        }
        delete[] distArray;
    }
}


/*
// command 5
//
// Lists all stations alphabetically by station name
*/

    // sortByName - sorts the array by ascending station names
void sortByName(ListStations orderingStations[], int s){
    for(int i=0; i<s-1; i++){
        
        int minIndex = i;
        for(int j=i+1; j<s; j++){
            if(orderingStations[j].name < orderingStations[minIndex].name){
                minIndex = j;
            }
        }
        
        ListStations temp;
        temp = orderingStations[i];
        orderingStations[i] = orderingStations[minIndex];
        orderingStations[minIndex] = temp;
        
    }
}

    // returningListStations - outputs the array
void returningListStations(ListStations orderingStations[], int s){
    for(int i = 0; i<s; ++i){
        cout << orderingStations[i].name <<" (" 
            << orderingStations[i].stationid << ") " << "@ ("
            << orderingStations[i].latitude << ", "
            << orderingStations[i].longitude << "), "
            << orderingStations[i].capacity << " capacity, "
            << orderingStations[i].bikeTrips << " trips" << endl;
    }
}
    
            // allStations - function for command 5 and 6
            // creates an array of struct for station array's values + bike trips
ListStations* allStations(Stations station[], int s, Bikes bike[], int s2, ListStations orderingStations[]){
    
    int* tripArray;
    tripArray = new int[s];
    
    int tripindex = 0; //counting trips to add to the array 
    
    //looping through all stations array
    for (int j = 0; j<s; j++){
        int tripcount = 0;
        //looping through bike array
        for (int i = 0; i<s2; i++){
            if((station[j].stationid == bike[i].stationid_s) or 
               (station[j].stationid == bike[i].stationid_e)){

                tripcount += 1;
            }
        }
        tripArray[tripindex] = tripcount;
        tripindex++;
    }
    
    for (int i = 0; i<s; i++){
        orderingStations[i].name = station[i].name;
        orderingStations[i].stationid = station[i].stationid;
        orderingStations[i].latitude = station[i].latitude;
        orderingStations[i].longitude = station[i].longitude;
        orderingStations[i].capacity = station[i].capacity;
        orderingStations[i].bikeTrips = tripArray[i];
    }
    
    sortByName(orderingStations, s);
    delete[] tripArray;
    return orderingStations;
    
}


/*
// command 6
//
// Performs a case sensitive search of the stations whose name includes the word input by the user
*/

    // findStation - compares the array station names to the userinput string 
void findStation(ListStations orderingStations[], int s, string userInput){
    
    string finding;
    int found_index = 0;
    for(int i=0; i<s; ++i){
        finding = orderingStations[i].name;
        if (finding.find(userInput)!= string::npos){
            cout << orderingStations[i].name <<" (" 
                << orderingStations[i].stationid << ") " << "@ ("
                << orderingStations[i].latitude << ", "
                << orderingStations[i].longitude << "), "
                << orderingStations[i].capacity << " capacity, "
                << orderingStations[i].bikeTrips << " trips" << endl;
            found_index += 1;
        }
    }
    if (found_index == 0){
        cout << "  none found" << endl;
    }
    
}


/*
// command 7
//
// Searches the bike trips for all trips with a start time that falls within the given timespan
*/

    // splitHour - splitting the hour part from the time and converting into an integer 
int splitHour(string time){
    
    string hour; string hour_first; string hour_second;
    int hour_int;
    
    hour_first = time.substr(0,1);
    hour_second = time.substr(1,1);

    if (hour_second == ":"){ //checking if hour is two digit;
        hour = hour_first;
    }
    else{
        hour = hour_first+hour_second;
    }
    hour_int = stoi(hour);
    return hour_int;
}

    // splitMins - splitting the minutes part from the time and converting into an integer
int splitMins(string time){
    
    string mins; string hour_second;
    int mins_int;
    
    hour_second = time.substr(1,1);

    if (hour_second == ":"){ //checking if hour is two digit;
        mins = time.substr(2,3);
    }
    else{
        mins = time.substr(3,4);
    }
    mins_int = stoi(mins);
    return mins_int;
}

    // searchFunct - splitting the minutes part from the time and converting into an integer
string searchFunct(Stations station[], int s, string searchingStat){
    string statname;
    string notfound = "no"; //a random string if not found
    for (int i = 0; i<s; i++){
        if(station[i].stationid == searchingStat){
            statname = station[i].name;
            return statname;
        }
    }
    return notfound;
}

    // sortByName2 - sorting the array of strings alphabetically
void sortByName2(string nameArray[], int amtTrips){
    for(int i=0; i<amtTrips-1; i++){
        
        int minIndex = i;
        for(int j=i+1; j<amtTrips; j++){
            if(nameArray[j] < nameArray[minIndex]){
                minIndex = j;
            }
        }
        
        string temp;
        temp = nameArray[i];
        nameArray[i] = nameArray[minIndex];
        nameArray[minIndex] = temp;
    }
}

    // Third line of command 7

    // midnightName - called from function finalStatement
        // if timespan crosses midnight, this function compares station id to bike id
        // if it is the same, it stores the station name into an array of strings
void midnightName(int& min_hour, int& min_mins, int& max_hour, int& max_mins, int bikeStart_hour, int bikeStart_mins,
                  int& ind_name, Stations station[], int s, Bikes bike[], string& searchingStat, string& statName, 
                 string nameArray[], int& i, string max_time){
    
    //case 1
    max_hour = 23;
    max_mins = 59;
    if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
        if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
            searchingStat = bike[i].stationid_s;
            statName = searchFunct(station, s, searchingStat);
            nameArray[ind_name] = statName;
            ind_name++;
        }
        else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){} // skips
        else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){} // skips
        else{
            searchingStat = bike[i].stationid_s;
            statName = searchFunct(station, s, searchingStat);
            nameArray[ind_name] = statName;
            ind_name++;

        }
    }
    
    //case 2
    min_hour = 0;
    min_mins = 0;
    max_hour = splitHour(max_time);
    max_mins = splitMins(max_time);
    if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
        if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
            searchingStat = bike[i].stationid_s;
            statName = searchFunct(station, s, searchingStat);
            nameArray[ind_name] = statName;
            ind_name++;}
        else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){} // skips
        else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){} // skips
        else{
            searchingStat = bike[i].stationid_s;
            statName = searchFunct(station, s, searchingStat);
            nameArray[ind_name] = statName;
            ind_name++;}
    }
}

        // removeDuplicate - compares the array and skips the duplicate station names while restoring
string* removeDuplicate(int& amtTrips, string nameArray[]){
    
    int tempAmt = amtTrips; // stores the original amount trips so it can be used later
    
    for(int i = 0; i< tempAmt; i++){
        //int j;
        for (int j=0; j<i; j++){
            if (nameArray[i] == nameArray[j]){
                amtTrips = amtTrips-1; // decrements array-size if duplicate found
                break;
            }
        }
    }
    
    string* NewArray;
    NewArray = new string[amtTrips]; // uses the new array-size value for a new array of string
    int newIndex = 0;
    int x = 0;
    while (x < tempAmt){
        int j = 0;
        while (j<x){
            if (nameArray[x] == nameArray[j]){
                break;
            }
            j++;
        }
        if (x == j){
            NewArray[newIndex] = nameArray[x];
            newIndex++;
        }
        x++;
    }

    return NewArray;
}

    // finalStatement - this function compares station id to bike id
    // if it is the same, it stores the station name into an array of strings

void finalStatement(Stations station[], int s, Bikes bike[], int s2, int& amtTrips, 
                     int min_hour, int min_mins, int max_hour, int max_mins, 
                     int& bikeStart_hour, int& bikeStart_mins, string min_time, string max_time){
    
    string searchingStat; //what you're trying to find (bike array -> start station id)
    string statName; // name of the bike statation using their id
    
    string* nameArray; //going to store names in an array so it can be printed out in order later
    nameArray = new string[amtTrips];
    
    int ind_name = 0;

    for (int i=0; i<s2; i++){

        bikeStart_hour = splitHour(bike[i].time);
        bikeStart_mins = splitMins(bike[i].time);
        
        //trip that doesn't fall into midnight
        if ((max_hour > min_hour) or ((max_hour == min_hour) && (min_mins <= max_mins))){
            if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
                if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
                    searchingStat = bike[i].stationid_s;
                    statName = searchFunct(station, s, searchingStat);
                    nameArray[ind_name] = statName;
                    ind_name++;
                }
                else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){} // skips
                else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){} // skips
                else{
                    searchingStat = bike[i].stationid_s;
                    statName = searchFunct(station, s, searchingStat);
                    nameArray[ind_name] = statName;
                    ind_name++;
                }
            }
        }   
        //trip that falls into midnight
        else{
            midnightName(min_hour, min_mins, max_hour, max_mins, bikeStart_hour, bikeStart_mins,
                         ind_name, station, s, bike, searchingStat, statName, nameArray, i, max_time);
        }        
    }
    
    
    cout << "  stations where trip started: ";
    sortByName2(nameArray, amtTrips);
    
    // if amout of trips found == 1, prints the only value stored 
    if (amtTrips == 1){
        cout << nameArray[0];
    }
    else{
        // if amout of trips > 1, it checks the array for duplicates 
        string* NewArray = removeDuplicate(amtTrips, nameArray);
        
        // outputs the array till the second last element in order for the ',' to be printed
        for (int i = 0; i< amtTrips-1; i++){
            if (NewArray[i] != ""){
                cout << NewArray[i] << ", ";
            }
        }
        // prints the last element
        cout << NewArray[amtTrips-1];
        delete[] NewArray;
    }
    cout << endl;
    delete[] nameArray;
}
    
    // Second line of command 7

    // compareStatBike - calculates the average duration of the trips found
void compareStatBike(Stations station[], int s, Bikes bike[], int s2, int& amtTrips, 
                     int& min_hour, int& min_mins, int& max_hour, int& max_mins, 
                     int& bikeStart_hour, int& bikeStart_mins, string min_time, string max_time){

    double avgDurations = 0.0; int calc = 0; double avg = 0.0;
    //avgDurations sums up bike durations, calc converts seconds to mins, avg finds avg durations
    
    for (int i=0; i<s2; i++){

        bikeStart_hour = splitHour(bike[i].time);
        bikeStart_mins = splitMins(bike[i].time);
        
        // if the time span doesn't cross midnight
        if ((max_hour > min_hour) or ((max_hour == min_hour) && (min_mins <= max_mins))){
            if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
                if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
                    avgDurations += bike[i].duration;  

                }
                //7:00 - 9:00 and comparing 9:01
                else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:45 - 9:00 and comparing 7:30
                else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:00 - 9:00 and comparing 8:30
                else{
                    avgDurations += bike[i].duration;

                }
            }
        }
        
        //trip that crosses midnight
        // past midnight 23:30 - 0:30 and comparing 0:15 
        else{
            //case 1
            //23:00 - 23:59      
            max_hour = 23;
            max_mins = 59;
            if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
                if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
                    avgDurations += bike[i].duration; 
                }
                //7:00 - 9:00 and comparing 9:01
                else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:45 - 9:00 and comparing 7:30
                else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:00 - 9:00 and comparing 8:30
                else{
                    avgDurations += bike[i].duration;
                }
            }
            //case 2
            //00:00 - max_time
            min_hour = 0;
            min_mins = 0;
            max_hour = splitHour(max_time);
            max_mins = splitMins(max_time);
            if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
                if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
                    avgDurations += bike[i].duration;
                }
                //7:00 - 9:00 and comparing 9:01
                else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:45 - 9:00 and comparing 7:30
                else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:00 - 9:00 and comparing 8:30
                else{
                    avgDurations += bike[i].duration;
                }
            }
            min_hour = splitHour(min_time);
            min_mins = splitMins(min_time); 
            max_hour = splitHour(max_time);
            max_mins = splitMins(max_time);
            
        }
        
    }
    
    calc = avgDurations/60;
    avg = calc/amtTrips;
    
    cout << "  avg duration: " << avg << " minutes" << endl;
}


    // First line of command 7

    // timeSpan - calculates the amount of trips found
void timeSpan(Bikes bike[], int s2, string min_time, string max_time, int& amtTrips, 
             int& min_hour, int& min_mins, int& max_hour, int& max_mins, int& bikeStart_hour, int& bikeStart_mins){
    
    min_hour = splitHour(min_time);
    min_mins = splitMins(min_time);
    
    max_hour = splitHour(max_time);
    max_mins = splitMins(max_time);

    for (int i=0; i<s2; i++){
        bikeStart_hour = splitHour(bike[i].time);
        bikeStart_mins = splitMins(bike[i].time);

        //trip that doesn't cross midnight
        if ((max_hour > min_hour) or ((max_hour == min_hour) && (min_mins <= max_mins))){
            
            if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
                if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
                    amtTrips += 1;
                }
                //7:00 - 9:00 and comparing 9:01
                else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:45 - 9:00 and comparing 7:30
                else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:00 - 9:00 and comparing 8:30
                else{
                    amtTrips += 1;
                }
            }
        }
        
        //trip that crosses midnight
        //23:30 - 1:30 -> 23:30-0:00 + 0:00-1:30
        else{
            //case 1
            //23:00 - 23:59
            
            max_hour = 23;
            max_mins = 59;
            if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
                if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
                    amtTrips += 1;
                }
                //7:00 - 9:00 and comparing 9:01
                else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:45 - 9:00 and comparing 7:30
                else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:00 - 9:00 and comparing 8:30
                else{
                    amtTrips += 1;
                }
            }
            //case 2
            min_hour = 0;
            min_mins = 0;
            max_hour = splitHour(max_time);
            max_mins = splitMins(max_time);
            if(bikeStart_hour >= min_hour && bikeStart_hour <= max_hour){
                if(bikeStart_mins == min_mins && bikeStart_mins == max_mins){
                    amtTrips += 1;
                }
                //7:00 - 9:00 and comparing 9:01
                else if(bikeStart_hour == max_hour && bikeStart_mins > max_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:45 - 9:00 and comparing 7:30
                else if(bikeStart_hour == min_hour && bikeStart_mins < min_mins){
                    amtTrips = amtTrips; // amtTrips stays the same
                }
                //7:00 - 9:00 and comparing 8:30
                else{
                    amtTrips += 1;
                }
            }
            min_hour = splitHour(min_time);
            min_mins = splitMins(min_time); 
            max_hour = splitHour(max_time);
            max_mins = splitMins(max_time);
        }
    }

}


// ######################################################
//
// main
//
int main(){
    cout<< "** Divvy Bike Data Analysis **" << endl;
    string filename; string filename2;
    
    cout << "Please enter name of stations file>" << endl;
    cin >> filename;
    
    ifstream infile;
    infile.open(filename);
    
    if (!infile.good()) 
    {
        cout << "**Error: unable to open input file '" << filename << "'" << endl;
        return 0;
    }
    
    Stations* stationData;
    int s; int s2;
    stationData = inputData(filename, s);
    
    //for function 5,6
    ListStations* orderingStations;
    orderingStations = new ListStations[s];
    
    infile.close();
    cout << "Please enter name of bike trips file>" << endl;
    cin >> filename2;
    
    ifstream infile2;
    infile2.open(filename2);
    if (!infile2.good()) 
    {
        cout << "**Error: unable to open input file '" << filename2 << "'" << endl;
        delete[] orderingStations;
        return 0;
    }
    
    Bikes* bikeData;
    bikeData = inputData2(filename2, s2);
    
    infile2.close();
    string command;
    cout << "Enter command (# to stop)> ";
    cin >> command;
    
    while (command != "#")
   {
        if(command == "stats"){
            statsFunction(stationData, s, s2);
        }
        else if(command == "durations"){
            bikeDuration(bikeData, s2);
        }
        else if(command == "starting"){
            histogram(bikeData, s2);
        }
        else if(command == "nearme"){
            double lat_by_user; double long_by_user; double approx_miles;
            cin >> lat_by_user >> long_by_user >> approx_miles;
            stationsNear(stationData, s, lat_by_user, long_by_user, approx_miles);
        }
        else if(command == "stations"){
            ListStations* looking; 
            looking = allStations(stationData, s, bikeData, s2, orderingStations);
            returningListStations(looking, s);
        }
        else if(command == "find"){
            string userInput;
            cin >> userInput;
            
            ListStations* looking; 
            looking = allStations(stationData, s, bikeData, s2, orderingStations);
            findStation(looking, s, userInput);
        }
        else if(command == "trips"){
            string min_time; string max_time;
            cin >> min_time >> max_time;
            int amtTrips = 0; int min_hour = 0; int min_mins = 0; int max_hour = 0; int max_mins = 0; int bikeStart_hour = 0; int bikeStart_mins = 0;
            //
            // this calculates amount of trips
            timeSpan(bikeData, s2, min_time, max_time, amtTrips, min_hour, min_mins, max_hour, max_mins, bikeStart_hour, bikeStart_mins);
            
            if(amtTrips != 0){
                cout << "  " << amtTrips << " trips found" <<endl;
                // calls the next lines functions
                compareStatBike(stationData, s, bikeData, s2, amtTrips, min_hour, min_mins, max_hour, max_mins, bikeStart_hour, bikeStart_mins, min_time, max_time);
                finalStatement(stationData, s, bikeData, s2, amtTrips, min_hour, min_mins, max_hour, max_mins, bikeStart_hour, bikeStart_mins, min_time, max_time);
            }
            else{
                cout << "  none found" << endl;
            }
        }
        else{
            cout << "** Invalid command, try again..." << endl;
        }
        
        cout << "Enter command (# to stop)> ";
        cin >> command;
    }
    cout << "** Done **" << endl;
    delete[] stationData; delete[] bikeData; delete[] orderingStations;
    return 0;
}