#include <iostream>
class Fraction{
	int gcd(int a,int b){
		return b?gcd(b,a%b):a;
	}
	int abs(int n){
		return n<0?-n:n;
	}
	void reduction(int newUp,int newDown){
		this->up=newUp;
		this->down=newDown;
		reduction();
	}
	void reduction(){
		if(this->down<0){
			this->down=-this->down;
			this->up=-this->up;
		}
		if(this->up==0){
			this->down=0;
		}else{
			int g=gcd(abs(this->up),abs(this->down));
			this->up/=g;
			this->down/=g;
		}
	}
	public:
		int up,down;
		Fraction(int up,int down){
			reduction(up,down);	
		}
//		Fraction(const Fraction& tar):Fraction(tar.up,tar.down){}
		Fraction& Add(Fraction tar){
			reduction(up*tar.down+down*tar.up,down*tar.down);
			return *this;
		}
		Fraction& Minus(Fraction tar){
			reduction(up*tar.down-down*tar.up,down*tar.down);
			return *this;	
		}
		Fraction& Muti(Fraction tar){
			reduction(up*tar.up,down*tar.down);
			return *this;	
		}
		Fraction& Div(Fraction tar){
			reduction(up*tar.down,down*tar.up);
			return *this;	
		}
};
int main(int argc, char** argv) {
	Fraction a(1,2);
	Fraction b(1,2);
	Fraction c=a.Add(b).Muti(b).Muti(b).Div(b);
	printf("%d/%d",c.up,c.down);
	return 0;
}
