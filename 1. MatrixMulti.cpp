#include<iostream>
#include<stdlib.h>

using namespace std;

class matrix
{
    private:
        int m;
        int n;
        int** mat;
    public:
        // Default constructor
        matrix()
        {
            m=0;
            n=0;
            mat=NULL;
        }
        // Allocates memory on basis of passed argument and initializes the matrix to 0
        matrix(int a, int b)
        {
            m=a;
            n=b;
            mat=new(nothrow) int*[m];
            for(int i=0; i<m && mat!=NULL; i++)
            {
                mat[i]=new(nothrow) int[n];
                if(mat[i]==NULL)
                {
                    for(int j=0; j<i; j++)
                    {
                        delete[] mat[j];
                    }
                    delete[] mat;
                    m=0;
                    n=0;
                    mat=NULL;
                    break;
                }
            }
            if(mat==NULL)
            {
                cout << "Unable to create matrix. Try again later...!\n\n";
                system("pause");
                return;
            }
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    mat[i][j]=0;
                }
            }
        }
        // Copy constructor
        matrix(const matrix &obj)
        {
            m=obj.m;
            n=obj.n;
            mat=new int*[m];
            for(int i=0; i<m && mat!=NULL; i++)
            {
                mat[i]=new int[n];
            }
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    mat[i][j]=obj.mat[i][j];
                }
            }
        }
        // Destructor-Frees up memory
        ~matrix()
        {
            if(!(m==0 && n==0))
            {
                for(int i=0; i<m; i++)
                {
                    delete[] mat[i];
                }
                delete[] mat;
            }
        }
        // Returns number of rows. Cannot alter the value.
        int return_row() const
        {
            return m;
        }
        // Returns number of columns. Cannot alter the value.
        int return_col() const
        {
            return n;
        }
        // Returns matrix address. Cannot alter the value.
        int** return_matrix_add() const
        {
            return mat;
        }
        // Creates matrix of the passed argument size and initializes it to zero.
        void creatematrix(int a, int b)
        {
            if(a<=0 || b<=0)
            {
                cout << "Invalid values entered. Must be greater than 0..!\n\n";
                system("pause");
                return;
            }
            else if(m==0 && n==0)
            {
                m=a;
                n=b;
                mat=new(nothrow) int*[m];
                for(int i=0; i<m && mat!=NULL; i++)
                {
                    mat[i]=new(nothrow) int[n];
                    if(mat[i]==NULL)
                    {
                        for(int j=0; j<i; j++)
                        {
                            delete[] mat[j];
                        }
                        delete[] mat;
                        m=0;
                        n=0;
                        mat=NULL;
                        break;
                    }
                }
                if(mat==NULL)
                {
                    cout << "Unable to create matrix. Try again later...!\n\n";
                    system("pause");
                    return;
                }
                for(int i=0; i<m; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        mat[i][j]=0;
                    }
                }
            }
        }
        // Deletes the matrix and frees up memory.
        void delete_matrix()
        {
            char ch='n';
            if(!(m==0 && n==0))
            {
                cout << "Deleting the matrix may lead to loss of data. Do you want to continue(Y/N): ";
                cin >> ch;
                if(!(ch=='Y'||ch=='y'))
                {
                    cout << "\nMatrix not deleted...!\n\n";
                    system("pause");
                    return;
                }
                for(int i=0; i<m; i++)
                {
                    delete[] mat[i];
                }
                delete[] mat;
                m=0;
                n=0;
                mat=NULL;
                cout << "\nMatrix deleted successfully...!\n\n";
                system("pause");
            }
            else
            {
                cout << "Matrix not created. Create a matrix first..!\n\n";
                system("pause");
            }
        }
        // Input values in the matrix. If matrix is not created then create a matrix first.
        void input_matrix()
        {
            if(!(m<=0 || n<=0))
            {
                for(int i=0; i<m; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        cout << "Enter element " << i+1 << ", " << j+1 << ": ";
                        cin >> mat[i][j];
                    }
                }
            }
            else
            {
                char ch;
                cout << "No matrix created. Do you want to create one?(Y/N) ";
                cin >> ch;
                if(!(ch=='y'||ch=='Y'))
                {
                    return;
                }
                else
                {
                    int a, b;
                    cout << "Enter number of rows: ";
                    cin >> a;
                    cout << "Enter number of columns: ";
                    cin >> b;
                    creatematrix(a,b);
                    if(mat==NULL)
                    {
                        return;
                    }
                    else
                    {
                        for(int i=0; i<m; i++)
                        {
                            for(int j=0; j<n; j++)
                            {
                                cout << "Enter element " << i+1 << ", " << j+1 << ": ";
                                cin >> mat[i][j];
                            }
                        }
                    }
                }
            }
        }
        // Output the matrix in square format
        void display_matrix()
        {
            for(int i=0; i<m; i++)
            {
                cout << " [";
                for(int j=0; j<n; j++)
                {
                    cout << mat[i][j];
                    (j==n-1)?cout << " ":cout << "\t";
                }
                cout << "]\n";
            }
        }
        // Update matrix element by element.
        void update_matrix()
        {
            int a, b;
            char ch;
            do
            {
                system("cls");
                display_matrix();
                cout << "Enter position of element to update:\n Row: ";
                cin >> a;
                cout << " Column: ";
                cin >> b;
                if(a>m || a<=0 || b<=0 || b>n)
                {
                    cout << "Invalid value entered. Canceling operation...!\n\n";
                    system("pause");
                    return;
                }
                cout << "Enter new value: ";
                cin >> mat[a-1][b-1];
                cout << "\nContinue updation(Y/N): ";
                cin >> ch;
                if(!(ch=='Y'||ch=='y'))
                {
                    ch='n';
                }
            }while(ch!='n');
        }
        // Add values of two matrix objects and return a matrix object. Copy constructor required.
        matrix operator +(const matrix &obj)
        {
            matrix res(m,n);
            while(res.mat==NULL)
            {
                res.creatematrix(m,n);
            }
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    res.mat[i][j]=mat[i][j]+obj.mat[i][j];
                }
            }
            return res;
        }
        // Subtract values of two matrix objects and return a matrix object. Copy constructor required.
        matrix operator -(const matrix &obj)
        {
            matrix res(m,n);
            while(res.mat==NULL)
            {
                res.creatematrix(m,n);
            }
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    res.mat[i][j]=mat[i][j]-obj.mat[i][j];
                }
            }
            return res;
        }
        // Performs scalar multiplication on matrix with an integer and return a matrix object. Copy constructor required.
        matrix operator *(const int &obj)
        {
            matrix res(m,n);
            while(res.mat==NULL)
            {
                res.creatematrix(m,n);
            }
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    res.mat[i][j]=mat[i][j]*obj;
                }
            }
            return res;
        }
        // Performs matrix multiplication on two matrix and return a matrix object. Copy constructor required.
        matrix operator *(const matrix &obj)
        {
            matrix res(m,obj.n);
            while(res.mat==NULL)
            {
                res.creatematrix(m,obj.n);
            }
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<obj.n; j++)
                {
                    for(int k=0; k<n; k++)
                    {
                        res.mat[i][j]+=mat[i][k]*obj.mat[k][j];
                    }
                }
            }
            return res;
        }
};

int main()
{
    char cont='y';
    matrix m1, m2;
    int count=0;
    do
    {
        int ch;
        system("cls");
        cout << "\t\t\t\tMatrix Operations\n";
        cout << "What do you want to do?\n";
        cout << " 1.Input Matrix\n";
        cout << " 2.Display Matrix\n";
        cout << " 3.Matrix Operations\n";
        cout << " 4.Exit\n";
        cout << "Enter your choice(1-4): ";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1: if(count==0)
                    {
                        m1.input_matrix();
                        if(m1.return_matrix_add()!=NULL)
                        {
                            count++;
                        }
                    }
                    else if(count==1)
                    {
                        m2.input_matrix();
                        if(m2.return_matrix_add()!=NULL)
                        {
                            count++;
                        }
                    }
                    else
                    {
                        char cuch;
                        int match;
                        cout << "Two Matrix already created...!\n";
                        cout << "First:\n";
                        m1.display_matrix();
                        cout << "Second:\n";
                        m2.display_matrix();
                        cout << "Do you want to create a new one or update one of the above?(c/u): ";
                        cin >> cuch;
                        switch(cuch)
                        {
                            case 'U':
                            case 'u':   cout << "Which matrix to update?(1/2):";
                                        cin >> match;
                                        switch(match)
                                        {
                                            case 1: m1.update_matrix();
                                                    break;
                                            case 2: m2.update_matrix();
                                                    break;
                                            default:cout << "Invalid Input\n\n";
                                                    system("pause");
                                        }
                                        break;
                            case 'C':
                            case 'c':   cout << "Which matrix to change?(1/2):";
                                        cin >> match;
                                        switch(match)
                                        {
                                            case 1: m1.delete_matrix();
                                                    m1.input_matrix();
                                                    break;
                                            case 2: m2.delete_matrix();
                                                    m2.input_matrix();
                                                    break;
                                            default:cout << "Invalid Input\n\n";
                                                    system("pause");
                                        }
                                        break;
                            default:    cout << "Invalid Input\n\n";
                                        system("pause");
                        }
                    }
                    break;
            case 2: if(count==0)
                    {
                        cout << "Create a matrix first...!";
                    }
                    else
                    {
                        cout << "First:\n";
                        m1.display_matrix();
                        if(count==2)
                        {
                            cout << "Second:\n";
                            m2.display_matrix();
                        }
                    }
                    cout << "\n\n";
                    system("pause");
                    break;
            case 3: int opr;
                    if(count==0)
                    {
                        cout << "Create a matrix first...!";
                    }
                    else if(count==1)
                    {
                        cout << "Possible operations:\n";
                        cout << " 1.Matrix Scalar Multiplication\n";
                        cout << " 2.Exit\n";
                        cout << "Do you want to continue?(1/2): ";
                        cin >> opr;
                        if(opr==1)
                        {
                            int factor;
                            cout << "Matrix is:\n";
                            m1.display_matrix();
                            cout << "Enter multiplication factor: ";
                            cin >> factor;
                            matrix m3=m1*factor;
                            cout << "\nNew array is:\n";
                            m3.display_matrix();
                        }
                    }
                    else
                    {
                        cout << "Possible operations:\n";
                        cout << " 1.Matrix Addition\n";
                        cout << " 2.Matrix Subtraction\n";
                        cout << " 3.Matrix Scalar Multiplication\n";
                        cout << " 4.Matrix Multiplication\n";
                        cout << " 5.Exit\n";
                        cout << "Do you want to continue?(1-5): ";
                        cin >> opr;
                        system("cls");
                        cout << "Matrices are:\n";
                        m1.display_matrix();
                        cout << "\n";
                        m2.display_matrix();
                        switch(opr)
                        {
                            case 1: if(m1.return_row()==m2.return_row() && m1.return_col()==m2.return_col())
                                    {
                                        matrix m3=m1+m2;
                                        cout << "\nResultant Matrix is:\n";
                                        m3.display_matrix();
                                    }
                                    else
                                    {
                                        cout << "Matrices are incompatible...!";
                                    }
                                    break;
                            case 2: if(m1.return_row()==m2.return_row() && m1.return_col()==m2.return_col())
                                    {
                                        matrix m3=m1-m2;
                                        cout << "\nResultant Matrix is:\n";
                                        m3.display_matrix();
                                    }
                                    else
                                    {
                                        cout << "Matrices are incompatible...!";
                                    }
                                    break;
                            case 3: int factor, match;
                                    cout << "Which matrix to multiply(1/2): ";
                                    cin >>  match;
                                    if(!(match==1 || match==2))
                                    {
                                        cout << "Invalid Input...!\n\n";
                                        system("pause");
                                    }
                                    else
                                    {
                                        cout << "Enter multiplication factor: ";
                                        cin >> factor;
                                        if(match==1)
                                        {
                                            matrix m3=m1*factor;
                                            cout << "\nNew array is:\n";
                                            m3.display_matrix();
                                        }
                                        else
                                        {
                                            matrix m3=m2*factor;
                                            cout << "\nNew array is:\n";
                                            m3.display_matrix();
                                        }
                                    }
                                    break;
                            case 4: if(m1.return_col()==m2.return_row())
                                    {
                                        matrix m3=m1*m2;
                                        cout << "\nResultant Matrix is:\n";
                                        m3.display_matrix();
                                    }
                                    else
                                    {
                                        cout << "Matrices are incompatible...!";
                                    }
                                    break;
                            case 5:
                                    break;
                            default:cout << "Invalid Input...!";
                        }
                    }
                    cout << "\n\n";
                    system("pause");
                    break;
            case 4: cont='n';
                    break;
            default:;
        }
    }while(cont!='n');
    return 0;
}
