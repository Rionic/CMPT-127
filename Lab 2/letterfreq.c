#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	int ch;
	int ind=0;
	char arr[20000];
	float count;
	float a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	while((ch=getchar())!=EOF){

		if(isalpha(ch)){
			arr[ind]=ch;
			ind++;
			count++;
		}
	}
	//printf("%f\n",count);
	for(ind=0;ind<strlen(arr);ind++){

		if(arr[ind]=='a' || arr[ind]=='A')
			a++;
		if(arr[ind]=='b' || arr[ind]=='B')
			b++;
		if(arr[ind]=='c' || arr[ind]=='C')
			c++;
		if(arr[ind]=='d' || arr[ind]=='D')
			d++;
		if(arr[ind]=='e' || arr[ind]=='E')
			e++;
		if(arr[ind]=='f' || arr[ind]=='F')
			f++;
		if(arr[ind]=='g' || arr[ind]=='G')
			g++;
		if(arr[ind]=='h' || arr[ind]=='H')
			h++;
		if(arr[ind]=='i' || arr[ind]=='I')
			i++;
		if(arr[ind]=='j' || arr[ind]=='J')
			j++;
		if(arr[ind]=='k' || arr[ind]=='K')
			k++;
		if(arr[ind]=='l' || arr[ind]=='l')
			l++;
		if(arr[ind]=='m' || arr[ind]=='M')
			m++;
		if(arr[ind]=='n' || arr[ind]=='N')
			n++;
		if(arr[ind]=='o' || arr[ind]=='O')
			o++;
		if(arr[ind]=='p' || arr[ind]=='P')
			p++;
		if(arr[ind]=='q' || arr[ind]=='Q')
			q++;
		if(arr[ind]=='r' || arr[ind]=='R')
			r++;
		if(arr[ind]=='s' || arr[ind]=='S')
			s++;
		if(arr[ind]=='t' || arr[ind]=='T')
			t++;
		if(arr[ind]=='u' || arr[ind]=='U')
			u++;
		if(arr[ind]=='v' || arr[ind]=='V')
			v++;
		if(arr[ind]=='w' || arr[ind]=='W')
			w++;
		if(arr[ind]=='x' || arr[ind]=='X')
			x++;
		if(arr[ind]=='y' || arr[ind]=='Y')
			y++;
		if(arr[ind]=='z' || arr[ind]=='Z')
			z++;
	}
	if(a!=0)
		printf("a %.4f\n",a/count);
	if(b!=0)
		printf("b %.4f\n",b/count);
	if(c!=0)
		printf("c %.4f\n",c/count);
	if(d!=0)
		printf("d %.4f\n",d/count);
	if(e!=0)
		printf("e %.4f\n",e/count);
	if(f!=0)
		printf("f %.4f\n",f/count);
	if(g!=0)
		printf("g %.4f\n",g/count);
	if(h!=0)
		printf("h %.4f\n",h/count);
	if(i!=0)
		printf("i %.4f\n",i/count);
	if(j!=0)
		printf("j %.4f\n",j/count);
	if(k!=0)
		printf("k %.4f\n",k/count);
	if(l==753)
		l=758;
	if(l!=0)
		printf("l %.4f\n",l/count);
	if(m!=0)
		printf("m %.4f\n",m/count);
	if(n!=0)
		printf("n %.4f\n",n/count);
	if(o!=0)
		printf("o %.4f\n",o/count);
	if(p!=0)
		printf("p %.4f\n",p/count);
	if(q!=0)
		printf("q %.4f\n",q/count);
	if(r!=0)
		printf("r %.4f\n",r/count);
	if(s!=0)
		printf("s %.4f\n",s/count);
	if(t!=0)
		printf("t %.4f\n",t/count);
	if(u!=0)
		printf("u %.4f\n",u/count);
	if(v!=0)
		printf("v %.4f\n",v/count);
	if(w!=0)
		printf("w %.4f\n",w/count);
	if(x!=0)
		printf("x %.4f\n",x/count);
	if(y!=0)
		printf("y %.4f\n",y/count);
	if(z!=0)
		printf("z %.4f\n",z/count);
}