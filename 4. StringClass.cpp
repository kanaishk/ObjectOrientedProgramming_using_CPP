#include<iostream>
#include<stdlib.h>

using namespace std;

class custstr
{
    private:
        int len;
        char* str;
    public:
        // Default Constructor
        custstr()
        {
            len=0;
            str=NULL;
        }
        // Constructor initializes the member with string literal
        custstr(const char* ch)
        {
            len=0;
            for(int i=0; ch[i]!='\0'; i++, len++);
            str=new(nothrow) char[len];
            if(str==NULL)
            {
                cout << "Cannot initialize memory...!";
                len=0;
                return;
            }
            for(int i=0; i<=len; i++)
            {
                str[i]=ch[i];
            }
        }
        // Copy constructor
        custstr(const custstr &ch)
        {
            len=ch.len;
            str=new(nothrow) char[len];
            if(str==NULL)
            {
                cout << "Cannot initialize memory...!";
                len=0;
                return;
            }
            for(int i=0; i<=len; i++)
            {
                str[i]=ch.str[i];
            }
        }
        // Destructor-Frees up memory
        ~custstr()
        {
            len=0;
            delete[] str;
            str=NULL;
        }
        // Input string. Size can be variable, by default, it is 4kB.
        void input_string(int ssize=4096)
        {
            char* tmp=new(nothrow) char[ssize];
            if(tmp==NULL)
            {
                cout << "Cannot initialize memory...!";
                return;
            }
            cout << "Input (Max Length-" << ssize << "): ";
            cin.get(tmp,ssize);
            for(int i=0; tmp[i]!='\0'; i++, len++);
            str=new(nothrow) char[len];
            while(str==NULL)
            {
                str=new(nothrow) char[len];
            }
            for(int i=0; i<=len; i++)
            {
                str[i]=tmp[i];
            }
            delete tmp;
        }
        // Print the string length and content
        void output_string()
        {
            cout << "Length: " << len << endl;
            cout << "String: " << str << endl;
        }
        // Returns string value
        char* return_str() const
        {
            return str;
        }
        // Returns string length
        int return_len() const
        {
            return len;
        }
        // Converts string to lower case
        void tolower()
        {
            for(int i=0; i<len; i++)
            {
                if(str[i]>=65 || str[i]<=90)
                {
                    str[i]+=32;
                }
            }
        }
        // Converts string to upper case
        void toupper()
        {
            for(int i=0; i<len; i++)
            {
                if(str[i]>=97 || str[i]<=122)
                {
                    str[i]-=32;
                }
            }
        }
        // Returns the object with concatenated string. Copy constructor required else information is lost
        custstr operator +(const custstr &ch)
        {
            custstr res;
            res.len=len+ch.len;
            res.str=new(nothrow) char[res.len];
            if(res.str==NULL)
            {
                res.str=new(nothrow) char[res.len];
            }
            for(int i=0, j=0, flag=0; i<=res.len; i++, j++)
            {
                if(i<len)
                {
                    res.str[i]=str[j];
                }
                else
                {
                    if(flag==0)
                    {
                        j=0;
                        flag++;
                    }
                    res.str[i]=ch.str[j];
                }
            }
            return res;
        }
        // Copies the source string to destination string. Does not append only replace.
        void operator =(const custstr &ch)
        {
            len=ch.len;
            delete[] str;
            str=NULL;
            str=new(nothrow) char[len];
            if(str==NULL)
            {
                str=new(nothrow) char[len];
            }
            for(int i=0; i<=len; i++)
            {
                str[i]=ch.str[i];
            }
        }
        // Compares the value of two strings and return 0 if equal -1 if first is bigger and 1 if second is bigger.
        // If both string has same character upto one's end then the other string which has more character is considered bigger
        int operator <=(const custstr &ch)
        {
            int res=0;
            if(len<ch.len)
            {
                for(int i=0; i<len; i++)
                {
                    if(str[i]<ch.str[i])
                    {
                        res=1;
                        break;
                    }
                    else if(str[i]>ch.str[i])
                    {
                        res=-1;
                        break;
                    }
                    else
                    {
                        res=0;
                    }
                }
                if(res==0)
                {
                    res=1;
                }
            }
            else if(len>ch.len)
            {
                for(int i=0; i<ch.len; i++)
                {
                    if(str[i]<ch.str[i])
                    {
                        res=1;
                        break;
                    }
                    else if(str[i]>ch.str[i])
                    {
                        res=-1;
                        break;
                    }
                    else
                    {
                        res=0;
                    }
                }
                if(res==0)
                {
                    res=-1;
                }
            }
            else
            {
                for(int i=0; i<ch.len; i++)
                {
                    if(str[i]<ch.str[i])
                    {
                        res=1;
                        break;
                    }
                    else if(str[i]>ch.str[i])
                    {
                        res=-1;
                        break;
                    }
                    else
                    {
                        res=0;
                    }
                }
            }
            return res;
        }
};

int main()
{
    custstr ch("hello"), ch1("ABC");
    system("cls");
    ch.output_string();
    ch.toupper();
    ch.output_string();
    ch.tolower();
    ch.output_string();
    ch1.output_string();
    ch1=ch+ch;
    ch1.output_string();
    if((ch<=ch1)==0)
    {
        cout << "Equal";
    }
    else if((ch<=ch1)==-1)
    {
        cout << "First is bigger";
    }
    else
    {
        cout << "Second is bigger";
    }
    return 0;
}
