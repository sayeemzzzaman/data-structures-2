#include<iostream>
#include<algorithm>
using namespace std;


struct Emp{
    int id, age;
    int salary;
};

bool sort_salperage_asc(Emp e1, Emp e2){
    return (double)e1.salary/e1.age < (double)e2.salary/e2.age;
}

bool sort_sal_asc(Emp e1, Emp e2){
//    if (e1.salary < e2.salary)
//        return true;
//    else
//        return false;
    return e1.salary < e2.salary;
}

bool sort_age_then_sal_asc(Emp e1, Emp e2){
    if (e1.age < e2.age)
        return true;
    else if (e1.age > e2.age)
        return false;
    else /// e1.age == e2.age
        return e1.salary < e2.salary;
}

bool sort_sal_desc(Emp e1, Emp e2){
    return e1.salary > e2.salary;
}

void print(Emp emps[], int n){
    cout<<"\nEmployees\n";
    for (int i=0;i<n;i++){
        cout << emps[i].id << " "
            << emps[i].age << " "
            << emps[i].salary << "\n";
    }
}

int main(){
    int n;
    cin >> n;
    Emp emps[n];
    for (int i=0;i<n;i++){
        cin >> emps[i].id
            >> emps[i].age
            >> emps[i].salary;
    }
    /// sort by salary
    sort(emps, emps+n, sort_sal_asc);
    print(emps, n);

    /// sort by salary desc
    sort(emps, emps+n, sort_sal_desc);
    print(emps, n);
    /// sort by salary
    sort(emps, emps+n, sort_sal_asc);
    print(emps, n);

    /// sort by salary per age desc
    sort(emps, emps+n, sort_salperage_asc);
    print(emps, n);
}

/**
4
4 23 5454
1 45 2345
2 34 23657
6 24 8634
*/