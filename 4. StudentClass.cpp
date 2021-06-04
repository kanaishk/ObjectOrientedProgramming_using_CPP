#include<iostream>
#include<stdlib.h>

using namespace std;

class marks
{
    private:
        int math;
        int eng;
        int sci;
        int cs;
        int eco;
    public:
        marks()
        {
            math=0;
            eng=0;
            sci=0;
            cs=0;
            eco=0;
        }
        void input_marks()
        {
            cout << "Enter marks for Mathematics(0-100): ";
            do
            {
                if(math<0 || math>100)
                {
                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                }
                cin >> math;
            }while(math<0 || math>100);
            cout << "Enter marks for English(0-100): ";
            do
            {
                if(eng<0 || eng>100)
                {
                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                }
                cin >> eng;
            }while(eng<0 || eng>100);
            cout << "Enter marks for Science(0-100): ";
            do
            {
                if(sci<0 || sci>100)
                {
                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                }
                cin >> sci;
            }while(sci<0 || sci>100);
            cout << "Enter marks for Computer Science(0-100): ";
            do
            {
                if(cs<0 || cs>100)
                {
                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                }
                cin >> cs;
            }while(cs<0 || cs>100);
            cout << "Enter marks for Economics(0-100): ";
            do
            {
                if(eco<0 || eco>100)
                {
                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                }
                cin >> eco;
            }while(eco<0 || eco>100);
        }
        int return_average()
        {
            return (math+eng+sci+cs+eco)/5;
        }
        int update_marks(char ch)
        {
            switch(ch)
            {
                case 'm':   cout << "Enter new marks for Mathematics(0-100): ";
                            do
                            {
                                if(math<0 || math>100)
                                {
                                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                                }
                                cin >> math;
                            }while(math<0 || math>100);
                            break;
                case 'e':   cout << "Enter new marks for English(0-100): ";
                            do
                            {
                                if(eng<0 || eng>100)
                                {
                                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                                }
                                cin >> eng;
                            }while(eng<0 || eng>100);
                            break;
                case 'c':   cout << "Enter new marks for Computer Science(0-100): ";
                            do
                            {
                                if(cs<0 || cs>100)
                                {
                                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                                }
                                cin >> cs;
                            }while(cs<0 || cs>100);
                            break;
                case 's':   cout << "Enter new marks for Science(0-100): ";
                            do
                            {
                                if(sci<0 || sci>100)
                                {
                                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                                }
                                cin >> sci;
                            }while(sci<0 || sci>100);
                            break;
                case 'o':   cout << "Enter new marks for Economics(0-100): ";
                            do
                            {
                                if(eco<0 || eco>100)
                                {
                                    cout << "Invalid input! Enter between 0 and 100. Enter: ";
                                }
                                cin >> eco;
                            }while(eco<0 || eco>100);
                            break;
            }
        }
        void display_marks()
        {
            cout << "\tMathematics:\t" << math << endl;
            cout << "\tEnglish:\t" << eng << endl;
            cout << "\tComputer Science:" << cs << endl;
            cout << "\tScience:\t" << sci << endl;
            cout << "\tEconomics:\t" << eco << endl;
        }
};

class student
{
    private:
        char name[25];
        int rno;
        int clas;
        char sect;
        marks stu_mark;
    public:
        student()
        {
            rno=0;
            clas=0;
        }
        void input_student()
        {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter roll no.: ";
            cin >> rno;
            cout << "Enter class: ";
            cin >> clas;
            cout << "Enter section: ";
            cin >> sect;
            cout << "Enter marks:\n";
            stu_mark.input_marks();
        }
        int display_detail()
        {
            cout << "Name:\t" << name;
            cout << "\nR. No.:\t" << rno;
            cout << "\nClass:\t" << clas << "-" << sect;
            cout << "\nMarks:\n";
            stu_mark.display_marks();
            cout << "\nAverage Marks:\t" << stu_mark.return_average();
        }
};

int main()
{
    student s;
    system("cls");
    s.input_student();
    system("cls");
    s.display_detail();
    return 0;
}
