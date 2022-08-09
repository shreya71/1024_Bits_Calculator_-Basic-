#include <bits/stdc++.h>
using namespace std;
int bigger(string s1, string s2);
int check(string s)
{
    string max = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216" ;
    if(s.size() > 309)
    return -1;
    else if(s.size() < 309)
    return 1;
    else
    {
        for(int i = 0; i < 309; i++)
        {
            if( s[0] == 1)
            continue;
            if(s[i] < max[i])
            return 1;
            else if(s[i] == max[i])
            continue;
            else
            return -1;
        }
    }
    return -1;
}
int bigger(string s1, string s2)
{
    int i = 0, j = 0, big = 0, n1 = s1.size(), n2 = s2.size();
         while(s1[i] == s2[j])
        {
            i++; j++;
        }
        if(s1[i] >= s2[j])
        big = 1;
        else
        big = 2;
    return big;
}
string addition(string s1, string s2)
{
    int n;
     reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if(s1.size() > s2.size())
    {
        n = s1.size();
       int z = s1.size() - s2.size();
        for(int i = 0; i< z; i++)
        {
            s2.append("0");
        }
    }
    else
    {
        n = s2.size();
       int z = s2.size() - s1.size();
        for(int i = 0; i< z; i++)
        {
            s1.append("0");
        }
    }
    string f = "";
    int carry = 0;
    for(int i = 0; i<=n-2; i++)
    {
        int x = s1[i]-'0', y =s2[i]-'0';
        int t = x+y;
        if(t <= 9)
        {
        if(carry == 1 && t == 9)
        {
        f.append("0");
        carry = 1;
        }
        else
        {
            if(carry == 0)
        f.append(to_string(t));
        else
        {
            t++;
            f.append(to_string(t));
        }
        carry = 0;
        }
        }
        else
        {
            int g = 0;
            if(carry == 1)
            g = t-10+1;
            else
            g = t-10;
            string st = to_string(g);
            f.append(st);
            carry = 1;
        }
    }
    int x =s1[n-1]-'0', y = s2[n-1]-'0', t = 0;
    if(carry == 1)
        t = x+y+1;
        else
        t = x+y;
        string stri = to_string(t);
        reverse(stri.begin(), stri.end());
        f.append(stri);
        reverse(f.begin(), f.end());
        int ans_check = check(f) ;
        if(ans_check == -1)
           return "Not under range of 1024 bits, run the program again" ;
        else if(n >1)
        return f;
        else
        {
        reverse(f.begin(), f.end());
        return f;
        }
}
void substraction(string s1, string s2)
{
    int n, sign = 0;
    string sub1, sub2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
     if(s1.size() > s2.size() )
    {
        n = s1.size();
       int z = s1.size() - s2.size();
        for(int i = 0; i< z; i++)
        {
            s2.append("0");
        }
        sub1 = s1;
        sub2 = s2;
    }
    else if(s1.size() < s2.size())
    {
        n = s2.size();
       int z = s2.size() - s1.size();
        for(int i = 0; i< z; i++)
        {
            s1.append("0");
        }
        sub1 = s2;
        sub2 = s1;
        sign = 1;
    }
    else
    {
        n = s1.size();
        int big = bigger(s1, s2) ;
        if(big == 1)
    {
        sub1 = s1;
        sub2 = s2;
    }
    else if(big == 2)
    {
        sub1 = s2;
        sub2 = s1;
        sign = 1;
    }
    }
    string f = "";
    int carry = 0;
    for(int i = 0 ; i< n; i++)
    {
        int x = sub1[i]-'0', y = sub2[i]-'0';
        if(x >= y && carry != -1)
        {
            int t = x-y ;
        f.append(to_string(t));
        }
        else if(x > y && carry == -1)
        {
            carry = 0;
            int t = x-1-y ;
            f.append(to_string(t));
        }
        else if(x == y && carry == -1 )
        {
            x += 10;
            int t = x-1-y ;
            f.append(to_string(t));
        }
        else if( x < y && carry != -1)
        {
            carry = -1;
            x += 10;
            int t = x-y ;
            f.append(to_string(t));
        }
        else
        {
            x += 10;
            int t = x-y-1 ;
            f.append(to_string(t));
        }
    }
    reverse(f.begin(), f.end());
     if(s1.compare(s2) == 0)
     cout << "0" << endl;
     else if(sign != 1)
     {
         if(f[0] == '0')
        {
            f[0] = '\0' ;
            cout << f << endl;
        }
        else
        cout << f << endl;
     }
    else
    {
        if(f[0] == '0')
        {
            f[0] = '-' ;
            cout << f << endl;
        }
        else
        cout << "-" << f << endl;
    }
}
void product(string s1, string s2)
{
    string product_result = "0";
    int n2 = s2.length(), n1 = s1.length(), p = 0, sum = 0;
    while(n2 > 0)
    {
        int t = (s2[n2-1] - '0' ) * pow(10, p) ;
        for(int i = 0; i < n1 ; i++)
        {
            int temp =  (s1[n1-1-i]-'0') * pow(10, i) * t ;
            string tem = to_string(temp) ;
            product_result = addition(product_result, tem) ;
        }
        n2--; p++;
    }
    cout << product_result << endl;
}
int main()
{
    string s1, s2;
    cin >> s1;
    int c1 = check(s1);
    if( c1 !=1 )
    {
    cout << "Not under range of 1024 bits, invalid input" << endl;
    cin >> s1;
    int c1 = check(s1);
    }
    cin >> s2;
    int c2 = check(s2);
     if( c2 !=1 )
     {
    cout << "Not under range of 1024 bits, invalid input" << endl;
    cin >> s2;
    int c2 = check(s2);
     }
   cout << addition(s1, s2) << endl;
   substraction(s1, s2);
   product(s1,s2) ;
}
