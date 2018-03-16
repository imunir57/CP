#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cassert>
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 100007
#define EPS 1e-9

/// Creates a line with equation ax + by + c = 0
struct line
{
    double a, b, c;
    line() {}
    line( pii p1,pii p2 )
    {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};

/// Distance: points to point
inline double Distance(pii a,pii b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

/// Dot Product : ab.bc
inline int dot(pii a,pii b,pii c)
{
    return (b.x-a.x)*(c.x-b.x)+(b.y-a.y)*(c.y-b.y);
}
/// Cross Product : ab x ac
inline int cross(pii a, pii b, pii c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
///Distance : Line ab to Point c
inline double lpd(pii a,pii b,pii c)
{
    double dist=cross(a,b,c)/Distance(a,b);
    return fabs(dist);
}
/// Distance : Line Segment ab to Point c
inline double lspd(pii a,pii b,pii c)
{
    //for double value points set dot()>-EPS
    if(dot(a,b,c)>0)return Distance(b,c);
    if(dot(b,a,c)>0)return Distance(a,c);
    double dist=cross(a,b,c)/Distance(a,b);
    return fabs(dist);
}

///If a circle intersect ab line segment or not
inline bool CLintersect(pii c,double r,pii a,pii b)
{
    if(lspd(a,b,c)>r+EPS)return false;
    return true;
}

///Line - Line Intersection (points)
inline bool LLInter(pii a,pii b,pii c,pii d,pdd &r)
{
    int a1,a2,b1,b2,c1,c2;
    a1=a.y-b.y;
    b1=b.x-a.x;
    c1=a.x*b.y-a.y*b.x;
    a2=c.y-d.y;
    b2=d.x-c.x;
    c2=c.x*d.y-c.y*d.x;
    double det=a1*b2-a2*b1;
    if(det==0)return false;
    r.x=(b1*c2-b2*c1)/det;
    r.y=(c1*a2-c2*a1)/det;
    return true;
}
///Line - Line Intersection (Lines)
inline bool LLInter(line p,line q,pdd &r)
{
    double det=p.a*q.b-q.a*p.b;
    if(det==0)return false;
    r.x=(p.b*q.c-q.b*p.c)/det;
    r.y=(p.c*q.a-q.c*p.a)/det;
    return true;
}
///Line Segment-Segment Intersection
inline bool LSI(pii a,pii b,pii c,pii d,pdd &r)
{
    ///can lie on another, just check their equations, and check overlap
    if(!LLInter(a,b,c,d,r))
        return false;
    return fabs(Distance(a,b)-Distance(a,r)-Distance(b,r))<EPS &&
           fabs(Distance(c,d)-Distance(c,r)-Distance(d,r))<EPS;
}

///Perpendicular Line of a Given Line Through a Point
inline line PerLine(line L,pdd p)
{
    line r;
    r.a=L.b, r.b=-L.a;
    r.c=-r.a*p.x-r.b*p.y;
    return r;
}

///Polygon Area
inline double pArea(vpii p)
{
    double area=0;
    int n=p.size();
    for(int i=0;i<n;++i)
        area+=p[i].x*p[(i+1)%n].y-p[i].y*p[(i+1)%n].x;
    return fabs(area/2.0);
}

/// Counter Clockwise Test
inline int ccw(pii a,pii b,pii c)
{
    int r=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    if(r<0)return -1;   /// a->b->c is a right turn
    if(r>0)return 1;    /// a->b->c is a left  turn
    return 0;           /// a->b->c is a straight line/collinear
}

/// Convex Test CCW/CW
inline bool convext(vpii p)
{
    int n=p.size(),left=0;
    for(int i=0;i<n;++i)
        if(ccw(p[i],p[(i+1)%n],p[(i+2)%n])>0)left++;
    if(left==n||left==0)return true;
}
/// Point k is in Segment Point i to j
inline bool onsegment(pii i,pii j,pii k)
{
    return (min(i.x,j.x)<=k.x&&k.x<=max(i.x,j.x)&&
            min(i.y,j.y)<=k.y&&k.y<=max(i.y,j.y));
}

///Point inside a polygon(with Boundry Case) r always double
bool PIP(vpii p,pdd r)
{
    int n=p.size();
    bool c=false;
    for (int i = 0, j = n-1; i < n; j = i++)
    {
        if(onsegment(p[i],p[j],r)&&!cross(p[i],p[j],r)) return true;//For the boundry case
        if (((p[i].y>r.y) != (p[j].y>r.y))&&
            (r.x<((p[j].x-p[i].x)*(r.y-p[i].y)/(p[j].y-p[i].y)*1.+p[i].x)) )
            c = !c;
    }
    return c;
}

/// Circle Through 3 Points (Multiple function used)
pdd circleTP(pii a, pii b,pii c)
{
    line p(a,b), q(b,c);
    pdd e=mp((a.x+b.x)/2.0,(a.y+b.y)/2.0);
    pdd f=mp((c.x+b.x)/2.0,(c.y+b.y)/2.0),centre;
    line pp=PerLine(p,e);
    line qq=PerLine(q,f);
    LLInter(pp,qq,centre);
    return centre;
}
///Rotate a point CCW alpha radian w.r.t. origin
inline pdd rotatePoint(double alpha , pdd a)
{
    if(fabs(alpha)<EPS)alpha=0.0;
    pdd r;
    r.x=a.x*cos(alpha)-a.y*sin(alpha);
    r.y=a.x*sin(alpha)+a.y*cos(alpha);
    return r;
}
///Rotate point a CCW alpha radian w.r.t. b
inline pdd rotatePointByB(double alpha , pdd a,pdd b)
{
    if(fabs(alpha)<EPS)alpha=0.0;
    pdd r;
    a.x-=b.x;
    a.y-=b.y;
    r.x=b.x+a.x*cos(alpha)-a.y*sin(alpha);
    r.y=b.y+a.x*sin(alpha)+a.y*cos(alpha);
    return r;
}
/// Rotate a line CCW alpha radian
inline void rotateLine(double alpha,pdd a,pdd b,pdd &c,pdd &d)
{
    pdd m;
    m.x=(a.x+b.x)/2;
    m.y=(a.y+b.y)/2;
    a.x-=m.x,a.y-=m.y;
    b.x-=m.x,b.y-=m.y;
    c=rotatePoint(alpha,a);
    d=rotatePoint(alpha,b);
    c.x+=m.x,c.y+=m.y;
    d.x+=m.x,d.y+=m.y;
}

///given triangle three sides a,b,c then angle between a,b
inline double coslow(double a,double b,double c)
{
    return acos((a*a+b*b-c*c)/(2*a*b));
}
///Points (x1,y1), (x2,y2), (x3,y3) are on the same line, if (x2-x1)(y3-y1)=(x3-x1)(y2-y1).

/// Center of mass of a convex/concave polygon
inline pdd centerofM(vpii p,int n)
{
    double A=0;
    for(int i=0;i<n;++i)
        A+=p[i].x*p[(i+1)%n].y-p[i].y*p[(i+1)%n].x;
    A=fabs(A/2.0);
    ///also used as A=pArea(p);
    pdd c=mp(0,0);
    for(int i=0;i<n;++i)
        c.x+=(p[i].x+p[(i+1)%n].x)*(p[i].x*p[(i+1)%n].y-p[i].y*p[(i+1)%n].x);
    for(int i=0;i<n;++i)
        c.y+=(p[i].y+p[(i+1)%n].y)*(p[i].x*p[(i+1)%n].y-p[i].y*p[(i+1)%n].x);
    c.x=c.x/6/A;
    c.y=c.y/6/A;
    return c;
}
/// Convex Hull ( Monotone Chain )
pii res[100005];
void convexHull(vpii pnt,int np,int &nc)
{
    Sort(pnt);
    int j=0;
    //use <= to remove colinear points
    FOR(i,0,np-1){
       while(j>=2&&cross(res[j-2],res[j-1],pnt[i])<=0)j--;
       res[j++]=pnt[i];
    }
    int t=j+1;
    FORR(i,np-2,0){
       while(j>=t&&cross(res[j-2],res[j-1],pnt[i])<=0)j--;
       res[j++]=pnt[i];
    }
    nc=j-1;
}
/// angle from line ab to  x-axis(on point a) CCW
double angleofLine(pdd a,pdd b)
{
    return atan2(b.y-a.y,b.x-a.x);
}

/// Circle - Circle Intersection
/// Circle - Circle Intersection
long double ccIntersection(pll c1,ll r1,pll c2,ll r2)
{
     if(r1<r2){swap(c1,c2);swap(r1,r2);}
     ll cd =(c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y);
     ll sd =(r1+r2)*(r1+r2);
     ll sdd =(r1-r2)*(r1-r2);
     if(cd>sd) return 0;
     if(sdd>=cd) return PI*r2*r2;
     long double cdroot=sqrt((long double)cd);
     long double alpha=acos((long double)(r2*r2+cd-r1*r1)/(2*r2*cdroot));
     long double ans=(r2*r2)*(alpha - sin(alpha)*cos(alpha));
     alpha=acos((long double)(r1*r1+cd-r2*r2)/(2*r1*cdroot));
     ans+=(r1*r1)*(alpha - sin(alpha)*cos(alpha));
     return ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    return 0;
}
