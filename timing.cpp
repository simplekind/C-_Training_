#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<int> pi;
#define floop(i,a,b) for(int i=a;i<b;i++)
#define test int t; cin>>t;while(t--)
#define endll '\n'
#define ll long long 
#define ld long double
#include <typeinfo>
#define pb push_back
#define mp make_pair
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
#include <ctime>

class TimedSection {
    char const *d_name;
    timespec d_start;
    public:
        TimedSection(char const *name) :
            d_name(name)
        {
            clock_gettime(CLOCK_REALTIME, &d_start);
        }
        ~TimedSection() {
            timespec end;
            clock_gettime(CLOCK_REALTIME, &end);
            double duration = 1e3 * (end.tv_sec - d_start.tv_sec) +
                              1e-6 * (end.tv_nsec - d_start.tv_nsec);
            std::cerr << d_name << '\t' << std::fixed << duration << " ms\n"; 
        }
};

int main() {
	
    const int iters = 10;
    char const *text = "01234567890123456789";
    {
        TimedSection s("cout with only endl");
        for (int i = 0; i < iters; ++i)
            std::cout << std::endl;
    }
    {
        TimedSection s("cout with only '\\n'");
        for (int i = 0; i < iters; ++i)
            std::cout << '\n';
    }
//    {
//        TimedSection s("printf with only '\\n'");
//        for (int i = 0; i < iters; ++i)
//            printf("\n");
//    }
    {
        TimedSection s("cout with string constant and endl");
        for (int i = 0; i < iters; ++i)
            std::cout << "01234567890123456789" << std::endl;
    }
    {
        TimedSection s("cout with string constant and '\\n'");
        for (int i = 0; i < iters; ++i)
            std::cout << "01234567890123456789\n";
    }
//    {
//        TimedSection s("printf with string constant and '\\n'");
//        for (int i = 0; i < iters; ++i)
//            printf("01234567890123456789\n");
//    }
    {
        TimedSection s("cout with some stuff and endl");
        for (int i = 0; i < iters; ++i)
            std::cout << text << "01234567890123456789" << i << std::endl;
    }
    {
        TimedSection s("cout with some stuff and '\\n'");
        for (int i = 0; i < iters; ++i)
            std::cout << text << "01234567890123456789" << i << '\n';
    }
//    {
//        TimedSection s("printf with some stuff and '\\n'");
//        for (int i = 0; i < iters; ++i)
//            printf("%s01234567890123456789%i\n", text, i);
//    }
}
