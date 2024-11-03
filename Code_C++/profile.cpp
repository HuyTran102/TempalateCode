#include<bits/stdc++.h>
using namespace std;

struct Profile {
    string full_name, school, email, city, job, relationship_status, hobby;
};

void display_Profile(Profile pf) {
    cout << "Full name: " << pf.full_name << endl;
    cout << "School: " << pf.school << endl;
    cout << "Email: " << pf.email << endl;
    cout << "City: " << pf.city << endl;
    cout << "Job: " << pf.job << endl;
    cout << "Relationship status: " << pf.relationship_status << endl;
    cout << "Hobby: " << pf.hobby << endl;
}

int main() {
    Profile tran_vu_gia_huy;
    tran_vu_gia_huy.full_name = "Trần Vũ Gia Huy";
    tran_vu_gia_huy.school = "Trường THCS Ngô Thì Nhậm";
    tran_vu_gia_huy.email = "huyserver1323@gmail.com";
    tran_vu_gia_huy.city = "Đà Nẵng";
    tran_vu_gia_huy.job = "Sutdent, Freelancer";
    tran_vu_gia_huy.relationship_status = "Single";
    tran_vu_gia_huy.hobby = "Coding, lisening to music, playing sports";
    display_Profile(tran_vu_gia_huy);
    return 0;
}