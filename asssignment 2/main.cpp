#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Umur dalam tahun
int yearsOld(tm* inputTgl, tm* currentTgl);
// Umur dalam bulan
int monthsOld(tm* inputTgl, tm* currentTgl);
// Hari dalam seminggu (Minggu, Senin, ..., Sabtu)
string dayOfDate(tm* inputTgl);

int main(int argc, char ** argv) 
{
    // time_t -> data structure untuk waktu
    time_t currentTime;

    // set variable currentTime ke data sekarang
    time(&currentTime);

    // ubah ke localtime (UTC+7)
    tm* currentTgl = localtime(&currentTime);

    // print tanggal sekarang (di comment)
    cout    <<" year:" << currentTgl -> tm_year+1900 <<" month:"<< currentTgl -> tm_mon+1 <<" day:" << currentTgl->tm_mday <<endl;

    int yearnow = currentTgl->tm_year+1900;    
    int monthnow = currentTgl->tm_mon+1;
    int daynow = currentTgl->tm_mday;
    int dayofweek = currentTgl->tm_wday;       // <-- start dari hari minggu

    // input tanggal lahir
    int yearinput, monthinput, dayinput;
    string inputstr;
    char ch;
    // silahkan uncomment kode dibawah untuk debugging
    cout << "Input tanggal dalam format DD/MM/YYYY:";
    cin >> inputstr;
    stringstream ss(inputstr);
    ss >> dayinput >> ch >> monthinput >> ch >> yearinput;

    // silahkan uncomment untuk debugging
    cout << "Tanggal Input: " << dayinput << "/" << monthinput << "/" << yearinput << endl;
    
    // buat tm* untuk tanggal input
    tm* inputTgl = new tm();
    inputTgl->tm_year = yearinput-1900;
    inputTgl->tm_mon = monthinput-1;
    inputTgl->tm_mday = dayinput;

    // ----------------------------------------------------------------------------------------------------------------
    inputTgl -> tm_hour = 0;
    inputTgl -> tm_min = 0;
    inputTgl -> tm_sec = 0;
    currentTgl -> tm_hour = 0;
    currentTgl -> tm_min = 0;
    currentTgl -> tm_sec = 0;
    // ----------------------------------------------------------------------------------------------------------------

    int ageOfYear = yearsOld(inputTgl, currentTgl);
    int ageOfMonth = monthsOld(inputTgl, currentTgl);
    string dayName = dayOfDate(inputTgl);

    cout << ageOfYear << " " << ageOfMonth << " " << dayName;
    // ----------------------------------------------------------------------------------------------------------------

    return 0;
}

//*********************************************************************************************************************
//*********************************************************************************************************************

//*********************************************************************************************************************
int yearsOld(tm* inputTgl, tm* currentTgl) {
    
    int year = currentTgl->tm_year - inputTgl->tm_year;
    if (currentTgl->tm_mon < inputTgl->tm_mon ||
        (currentTgl->tm_mon == inputTgl->tm_mon && currentTgl->tm_mday < inputTgl->tm_mday)) {
            year--;
        }
        return year;
    }
//*********************************************************************************************************************

//*********************************************************************************************************************
int monthsOld(tm* inputTgl, tm* currentTgl) {
    int month = (currentTgl->tm_year - inputTgl->tm_year) * 12 + (currentTgl->tm_mon - inputTgl->tm_mon);
    if (currentTgl->tm_mday < inputTgl->tm_mday) {
        month--;
    }
    return month;
}
//*********************************************************************************************************************

//*********************************************************************************************************************
string dayOfDate(tm* inputTgl) {
    mktime (inputTgl); 
    string days [] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    return days[inputTgl -> tm_wday];
}

//*********************************************************************************************************************