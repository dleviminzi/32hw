#include <iostream>

bool somePredicate(double x)
{
    return x == -3;
}


bool anyFalse(const double a[], int n) 
{
    bool result(0);
    if (n==0) return 0;
    if (n==1)
    {
        if (!somePredicate(a[0])) result = 1;
    }
    else 
    {
        result = anyFalse(a, n/2);
        result = anyFalse(a+n/2, n - n/2);
    }
    return result;
}

int countTrue(const double a[], int n)
{
    int count(0);
    if (n==0) return count;
    if (n==1)
    {
        if (somePredicate(a[0])) count++;
    }
    else
    {
        count += countTrue(a, n/2);
        count += countTrue(a+n/2, n - n/2);
    }
    return count;
}

int firstTrue(const double a[], int n)
{
    const double* ptr = a;
    int d = n;
    if (n==0) return -1;
    if (n==1) 
    {
        if (somePredicate(a[0])) return (*ptr - a[0]);
    }
    else 
    {
        d -= firstTrue(a, n/2);
        d -= firstTrue(a+n/2, n-n/2);
    }
    return d;
}


int main() 
{
    double arr[5] = {-1, -2, -3, -4, -5};
    std::cout << anyFalse(arr, 5) << std::endl;
    std::cout << countTrue(arr, 5) << std::endl;
    std::cout << firstTrue(arr, 5) << std::endl;
}

