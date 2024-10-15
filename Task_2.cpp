#include<iostream>
#include<vector>

class Phone {

    class PhoneBook {
        std::string num;
        std::string name;
        friend Phone;
    };

    std::vector<PhoneBook> per_number;

    bool add_number() {
        int i = per_number.size() - 1;
        std::string buffer_number;
        std::cout << "\nEnter a number 10 digits long, like (1234567890) : ";
        std::cin >> buffer_number;
        if (buffer_number.length() > 10) {
            std::cout << "Invalid number !";
            return true;
        }
        for (int i = 0; i < 10; ++i) {
            if (buffer_number[i] < '0' || buffer_number[i] > '9') {
                std::cout << "\nIts not a number !";
                return true;
            }
        }
        std::string temp = "+7";
        temp += buffer_number;
        per_number[i].num = temp;
        return false;
    }

    bool add_name() {
        per_number.resize(per_number.size() + 1);
        int i = per_number.size() - 1;
        std::string buffer_name;
        std::cout << "\nEnter name : ";
        std::cin >> buffer_name;
        for (int i = 0; i < buffer_name.length(); ++i) {
            if (!((buffer_name[i] >= 'a' && buffer_name[i] <= 'z') || (buffer_name[i] >= 'A' && buffer_name[i] <= 'Z'))) {
                std::cout << "\nInvalid name !";
                return true;
            }
        }
        per_number[i].name = buffer_name;
        return false;
    }

    bool search(std::string& str) const {
        bool its_num = false;
        if (str[0] == '+' && str[1] == '7') {
            its_num = true;
        }
        if (its_num) {
            for (int i = 0; i < per_number.size(); ++i) {
                if (per_number[i].num == str) {
                    std::cout << "\nBy number \"" << str << "\" found : " << per_number[i].name;
                    return true;
                }
            }
        }
        else {
            for (int i = 0; i < per_number.size(); ++i) {
                if (per_number[i].name == str) {
                    std::cout << "\nBy name \"" << str << "\" found : " << per_number[i].num;
                    return true;
                }
            }
        }
        return false;
    }

public:

    void add() {
        while (add_name());
        while (add_number());
    }

    void call() {
        std::string str;
        std::cout << "\nEnter a name or number to search : ";
        std::cin >> str;
        if (!search(str)) {
            std::cout << "\nNot find enything";
        }
        else {
            std::cout << "\nCalling ......";
        }
    }

    void sms() {
        std::string str;
        std::cout << "\nEnter a name or number like (+71234567890) to search : ";
        std::cin >> str;
        if (!search(str)) {
            std::cout << "\nNot find enything";
        }
        else {
            std::string temp;
            std::cout << "\nWriete sms : ";
            std::cin >> temp;
            std::cout << "\nSMS \"" << temp << "\" was sent successfully";
        }
    }
};

int main() {
    Phone pers_numbers;
    std::string choice;
    while (choice != "exit") {
        std::cout << "\nMake choice\nadd\ncall\nsms\nexit\nEnter : ";
        std::cin >> choice;
        if (choice == "add") {
            pers_numbers.add();
        }
        else if (choice == "call") {
            pers_numbers.call();
        }
        else if (choice == "sms") {
            pers_numbers.sms();
        }
        else if (choice != "exit") {
            std::cout << "\nInvalid option!";
        }
    }
}