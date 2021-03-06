//3. Definirati strukturu kruznica i strukturu pravokutnik koja predstavlja
//pravokutnik èije su stranice paralelne sa osima apscisa i ordinata. Napisati
//check_intersectionsciju koja prima niz pravokutnika i jednu kruznicu i vraæa broj pravokutnika koji sijeku kružnicu. Niz pravokutnika i kružnica šalju se u check_intersectionsciju
//pomoæu const referenci.
//
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct rectangle
{
    int x1;
    int x2;
    int y1;
    int y2;
};

struct circle
{
    int x;
    int y;
    int r;
};

int check_intersections(rectangle *arr_rectangle, circle &kr,int num_rec)
{
    float distance_first_point;
    float distance_second_point;
    float distance_third_point;
    float distance_fourth_point;
    int counter=0;
    for(int i=0; i<num_rec; i++)
    {

        distance_first_point = sqrt(fabsf(pow(arr_rectangle->x1-kr.x, 2) + pow(arr_rectangle->y1-kr.y, 2)));
        distance_second_point = sqrt(fabsf(pow(arr_rectangle->x2-kr.x, 2) + pow(arr_rectangle->y2-kr.y, 2)));
        distance_third_point= sqrt(fabsf(pow(arr_rectangle->x2-kr.x, 2) + pow(arr_rectangle->y1-kr.y, 2)));
        distance_fourth_point = sqrt(fabsf(pow(arr_rectangle->x1-kr.x, 2) + pow(arr_rectangle->y2-kr.y, 2)));
        if(((min(distance_first_point, distance_second_point) <= kr.r )&&(max(distance_first_point, distance_second_point) >= kr.r)) || ((min(distance_third_point, distance_fourth_point) <= kr.r )&&(max(distance_third_point, distance_fourth_point) >= kr.r)))
            counter++;
    }
    return counter;
}

int main(void)
{
    int num_rec;
    cout << "unesite broj pravokutnika: " << endl;
    cin >> num_rec;
    rectangle* arr_rectangle = new rectangle[num_rec];
    circle kr;
    for(int i=0; i<num_rec; i++)
    {
        cout <<"Unesite x1:";
        cin >> arr_rectangle->x1;
        cout << "Unesite y1:";
        cin >> arr_rectangle->y1;

        cout <<"Unesite x2:";
        cin >> arr_rectangle->x2;
        cout <<"Unesite y2:";
        cin >> arr_rectangle->y2;
    }
    cout << "Unesite x kordinatu sredista kruznice: ";
    cin >> kr.x;
    cout << "Unesite y kordinatu sredista kruznice:";
    cin >> kr.y;
    cout << "Unesite radijus:";
    cin >> kr.r;
    cout<<check_intersections(arr_rectangle, kr,num_rec);
    return 0;
}
