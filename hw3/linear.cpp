#include <iostream>

bool somePredicate(double x)
{
    return x == -3;
}


bool anyFalse(const double a[], int n) 
{
    int c = 0;
    if (n==0) return 0;
    if (n==1)
    {
        if (!somePredicate(a[0])) c++;
    }
    else 
    {
        c += anyFalse(a, n/2);
        c += anyFalse(a+n/2, n - n/2);
    }
    return c > 0;
}

int countTrue(const double a[], int n)
{
    int c = 0;
    if (n==0) return c;
    if (n==1)
    {
        if (somePredicate(a[0])) c++;
    }
    else
    {
        c += countTrue(a, n/2);
        c += countTrue(a+n/2, n - n/2);
    }
    return c;
}

int firstTrue(const double a[], int n)
{
    int d = 0;
    if (n==0) return -1;
    if (n==1) 
    {
        if (!somePredicate(a[0])) return 1;
    }
    else 
    {
        d += firstTrue(a, n/2);
        if (d == n/2) d += firstTrue(a+n/2, n-n/2);
    }
    return d;
}

int positionOfSmallest(const double a[], int n) 
{
    int s_val = a[n-1];
    if (n==0) return -1;
    if (n==1) 
    {
        if (a[0] <= s_val) return a[0];
    }
    else
    {
        int s_val2;
        s_val = positionOfSmallest(a, n/2);
        s_val2 = positionOfSmallest(a+n/2, n-n/2);
        if (s_val2 < s_val) s_val = s_val2;
    }
    return s_val;
}



int main() 
{
    double arr[6] = {-2, -903, -3, -2, -1111, 4};
    std::cout << anyFalse(arr, 5) << std::endl;
    std::cout << countTrue(arr, 5) << std::endl;
    std::cout << firstTrue(arr, 6) << std::endl;
    std::cout << positionOfSmallest(arr, 6) << std::endl;
}

