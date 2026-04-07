# Laporan Programming Assignment 1: Basic C++
Tujuan dari program ini adalah untuk menghitung umur seseorang dalam tahun, bulan, dan hari dalam minggu dari tanggal lahir orang tersebut.
Program ini menggunakan:
- Library ``<ctime>`` untuk memanipulasikan waktu
- Struktur data ``tm`` untuk menyimpan tanggal
- Fungsi ``mktime()`` untuk menentukan hari dan tanggal
- ``stringstream`` untuk menguraikan input tanggal

## Kode
```cpp
int yearsOld(tm* inputTgl, tm* currentTgl) {
    
    int year = currentTgl->tm_year - inputTgl->tm_year;
    if (currentTgl->tm_mon < inputTgl->tm_mon ||
        (currentTgl->tm_mon == inputTgl->tm_mon && currentTgl->tm_mday < inputTgl->tm_mday)) {
            year--;
        }
        return year;
    }
```
untuk menghitung selisih tahun input dengan tahun lahir dan dikurangi satu jika ulang tahun di tahun ini belum terjadi

```cpp
int monthsOld(tm* inputTgl, tm* currentTgl) {
    int month = (currentTgl->tm_year - inputTgl->tm_year) * 12 + (currentTgl->tm_mon - inputTgl->tm_mon);
    if (currentTgl->tm_mday < inputTgl->tm_mday) {
        month--;
    }
    return month;
}
```
untuk menghitung total bulan lahir dan dikurangi jika tanggal input belum melewati tanggal lahir

```cpp
string dayOfDate(tm* inputTgl) {
    mktime (inputTgl); 
    string days [] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    return days[inputTgl -> tm_wday];
}
```
untuk menghitung hari dan menentukan hari lahir


