
#include <iostream>
#include <string>

class UserClass {
protected:
    std::string name;
    std::string contract;
    std::string address;
    std::string position;
    bool isActive = true;


/* Method */
public: void setActiveUser(bool inpIsActive) {
        isActive = inpIsActive;
    }


public: std::string getName() {
        return name;
    }
public: std::string getContract() {
        return contract;
    }
public: std::string getAddress() {
        return address;
    }
public: std::string getPosition() {
        return position;
    }
public: bool checkActive() {
        return isActive;
    }

public: bool isMember() {
        return "Member" == position;
    }
public: bool isStaff() {
        return "Staff" == position;
    }

};


class MemberClass : public UserClass {
public: MemberClass(std::string inpName, std::string inpContract, std::string inpAddress) {
        name = inpName;
        contract = inpContract;
        address = inpAddress;
        position = "Member";
    }
};

class StaffClass : public UserClass {
public: StaffClass(std::string inpName, std::string inpContract, std::string inpAddress) {
        name = inpName;
        contract = inpContract;
        address = inpAddress;
        position = "Staff";
    }

};
