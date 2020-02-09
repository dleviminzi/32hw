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
    if (n==0) return -1;
    if (somePredicate(a[0])) return 0; 
    else
    {
        int x = firstTrue(a+1, n-1);
        if (x == -1) return -1;
        else return 1 + x;
    }
}

/* fails on none true
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
}*/

int positionOfSmallest(const double a[], int n) 
{
    if (n==0) return -1;
    if (n==1) return 0;
    else
    {
        int i1 = n;
        int i2 = positionOfSmallest(a, n-1);
        if (a[i2] <= a[i1]) i1 = i2;
        return i1;
    }
}

bool contains(const double a1[], int n1, const double a2[], int n2)
{
    bool result(false);
    if (n2 > n1) return false;
    if (a1[0] == a2[0]) 
    {
        result = true;
        if (n2 > 1) result = contains(a1+1, n1-1, a2+1, n2-1);
        return result;
    }
    else
    {
        return contains(a1+1, n1-1, a2, n2);
    }
}

int main() 
{
    double arr[6] = {-1, -3, -10, -1, -1, -10000};
    std::cout << anyFalse(arr, 5) << std::endl;
    std::cout << countTrue(arr, 6) << std::endl;
    std::cout << firstTrue(arr, 6) << std::endl;
    std::cout << positionOfSmallest(arr, 6) << std::endl;
    double R[7] = {10, 50, 40, 20, 50, 40, 30};
    double Z[3] = {40, 20, 50};
    std::cout << contains(R, 7, Z, 3) << std::endl;
}

