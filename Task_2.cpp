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
        if (search(temp) != -1) {
            std::cout << "\nThat number alredy addet !";
            return true;
        }
        per_number[i].num = temp;
        return false;
    }

    bool add_name() {       
        int i = per_number.size();
        std::string buffer_name;
        std::cout << "\nEnter name : ";
        std::cin >> buffer_name;
        for (int i = 0; i < buffer_name.length(); ++i) {
            if (!((buffer_name[i] >= 'a' && buffer_name[i] <= 'z') || (buffer_name[i] >= 'A' && buffer_name[i] <= 'Z'))) {
                std::cout << "\nInvalid name !";
                return true;
            }
        }
        per_number.resize(per_number.size() + 1);
        per_number[i].name = buffer_name;
        return false;
    }

    int search(std::string& str) const {
        bool its_num = false;
        if (str[0] == '+' && str[1] == '7') {
            its_num = true;
        }
        if (its_num) {
            for (int i = 0; i < per_number.size(); ++i) {
                if (per_number[i].num == str) {
                    return i;
                }
            }
        }
        else {
            for (int i = 0; i < per_number.size(); ++i) {
                if (per_number[i].name == str) {
                    return i;
                }
            }
        }
        return -1;
    }

public:

    void add() {
        while (add_name());
        while (add_number());
    }

    void call() {
        std::string str;
        std::cout << "\nEnter a name or number like (+71234567890) to search : ";
        std::cin >> str;
        int i = search(str);
        if (i == -1) {
            std::cout << "\nNot find enything"<<std::endl;
        }
        else {
            if (str[0] == '+') {
                std::cout << "\nBy number \"" << str << "\" found : " << per_number[i].name;
            }
            else {
                std::cout << "\nBy name \"" << str << "\" found : " << per_number[i].num;
            }
            std::cout << "\nCalling ......" << std::endl;;
        }
    }

    void sms() {
        std::string str;
        std::cout << "\nEnter a name or number like (+71234567890) to search : ";
        int i = search(str);
        if (i == -1) {
            std::cout << "\nNot find enything" << std::endl;
        }
        else {
            if (str[0] == '+') {
                std::cout << "\nBy number \"" << str << "\" found : " << per_number[i].name;
            }
            else {
                std::cout << "\nBy name \"" << str << "\" found : " << per_number[i].num;
            }
            std::string temp;
            std::cout << "\nWriete sms : ";
            std::cin >> temp;
            std::cout << "\nSMS \"" << temp << "\" was sent successfully"<<std::endl;
        }
    }

    void deleteNumber() {
        std::string temp;
        std::cout << "\nEnter what number you want delete : ";
        std::cin >> temp;
        int i = search(temp);
        if (i != -1) {
            std::cout << "\nFount number : " << per_number[i].num << " name : " << per_number[i].name << std::endl;
            std::cout << "You want delete this number (yes/no) : ";
            std::cin >> temp;
            if (temp == "yes") {
                std::vector<PhoneBook>::iterator iter = per_number.begin()+i;
                per_number.erase(iter);
                std::cout << "\nNumber has successfully deleted " << std::endl;
            }
        }
        else {
            std::cout << "\nNot find enything" << std::endl;
        }
    }
};

int main() {
    Phone pers_numbers;
    std::string choice;
    while (choice != "exit") {
        std::cout << "\nMake choice\nadd\ncall\nsms\nexit\ndelete\nEnter : ";
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
        else if (choice == "delete") {
            pers_numbers.deleteNumber();
        }
        else if (choice != "exit") {
            std::cout << "\nInvalid option!";
        }
    }
}