#include <iostream>
#include <string>
using namespace std;

class user {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    user(string pNama, string pEmail) {
        id = generateId();
        nama = pNama;
        email = pEmail;
    }

    int generateId() {
        return ++globalId;
    }
};

int user::globalId = 0;

class member : public user {
private:
    bool status;

public:
    member(string pNama, string pEmail, bool pStatus)
        : user(pNama, pEmail) {
        status = pStatus;
    }

    void showProfile() {
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Nonaktif") << endl;
    }

    void setStatus(bool pStatus) {
        status = pStatus;
    }

    bool getStatus() {
        return status;
    }
};

class admin : public user {
public:
    admin(string pNama, string pEmail)
        : user(pNama, pEmail) {
    }

    void showAllMember(member m1, member m2) {
        cout << "\n=== DATA MEMBER ===" << endl;
        m1.showProfile();
        cout << endl;
        m2.showProfile();
    }

    void toggleActivationMember(member &m) {
        m.setStatus(!m.getStatus());
    }
};

int main() {
    member member1("Khalid", "khalid@gmail.com", true);
    member member2("Hanifah", "hanifah@gmail.com", false);

    admin admin1("Admin", "admin@gmail.com");

    admin1.showAllMember(member1, member2);

    cout << "\nStatus member2 diubah\n" << endl;
    admin1.toggleActivationMember(member2);

    member2.showProfile();

    return 0;
}