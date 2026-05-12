#include <iostream>
#include <string>
#include <vector>
using namespace std;

class user {
public:
    static int globalId;
    int id;
    string nama;
    string email;

    user(string pNama, string pEmail) : nama(pNama), email(pEmail) {
        id = generateId();
    }

    int generateId() {
        globalId++;
        return globalId;
    }
};

int user::globalId = 0;

class member : public user {
public:
    bool status; 

    
    member(string pNama, string pEmail) : user(pNama, pEmail), status(true) {
        cout << "Member \"" << nama << "\" dibuat (ID: " << id << ")\n";
    }

    void showProfile() {
        cout << "ID     : " << id << "\n";
        cout << "Nama   : " << nama << "\n";
        cout << "Email  : " << email << "\n";
        cout << "Status : " << (status ? "Aktif" : "Non-Aktif") << "\n";
        cout << "-----------------------\n";
    }
};


class admin : public user {
public:
    admin(string pNama, string pEmail) : user(pNama, pEmail) {
        cout << "Admin \"" << nama << "\" dibuat (ID: " << id << ")\n";
    }

    
    void showAllMember(vector<member*> daftar_member) {
        cout << "\n=== DAFTAR SEMUA MEMBER ===\n";
        for (int i = 0; i < daftar_member.size(); i++) {
            daftar_member[i]->showProfile();
        }
    }

    void toggleActivationMember(member* pMember) {
        pMember->status = !pMember->status; 
        cout << "\n[!] Status member \"" << pMember->nama << "\" diubah menjadi: "
             << (pMember->status ? "Aktif" : "Non-Aktif") << "\n";
    }
};


int main() {
    
    admin* varAdmin = new admin("Andi", "admin.andi@domain.com");
    cout << endl;

    member* m1 = new member("Khalid", "khalid@domain.com");
    member* m2 = new member("Hanif", "hanif@domain.com");
    member* m3 = new member("Hanifah", "hanifah@domain.com");

    vector<member*> daftar_member;
    daftar_member.push_back(m1);
    daftar_member.push_back(m2);
    daftar_member.push_back(m3);

    varAdmin->showAllMember(daftar_member);

    varAdmin->toggleActivationMember(m2);

    varAdmin->showAllMember(daftar_member);

    delete varAdmin;
    delete m1;
    delete m2;
    delete m3;

    return 0;
}