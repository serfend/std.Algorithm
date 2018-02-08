#include <iostream>
#include <string.h>
class BigDecimal{
	public:
	const static unsigned short capacity=1023;
	char value[capacity];
	unsigned short length;
	BigDecimal(){
		Change();
	}
	BigDecimal(char value[]){
		Change(value);
	}
	BigDecimal(const BigDecimal& tar){
		Change();
		this->length=tar.length;
		for(int i=0;i<tar.length;i++){
			this->value[i]=tar.value[i];
		}
	}
	void Change(){
		memset(value,0,sizeof(value));
		length=0;
	}
	void Change(char value[]){
		Change();
		this->length=strlen(value);
		for(int i=0;i<length;i++){
			this->value[length-i-1]=value[i]-'0';
		}
	}
	BigDecimal operator +(const BigDecimal tar){
		BigDecimal c(*this);
		int carry=0;
		for(int i=0;i<this->length||i<tar.length;i++){
			int tmp=this->value[i]+tar.value[i]+carry;
			c.value[i]=tmp%10;
			carry=tmp/10;
		}
		/*if(carry!=0){
			c.value[c.length++]=carry;
		}*/
		return c;
	}
	BigDecimal operator -(const BigDecimal tar){
		BigDecimal c(*this);
		int carry=0;
		for(int i=0;i<this->length||i<tar.length;i++){
			if(this->value[i]<tar.value[i]){
				this->value[i+1]--;
				this->value[i]+=10;
			}
			c.value[i]=this->value[i]-tar.value[i];
		}
		if(carry!=0){
			c.value[c.length++]=carry;
		}
		return c;
	}
	void ShowValue(){
		for(int i=length-1;i>=0;i--){
			printf("%d",value[i]);
		}
	}
};
int main(int argc, char** argv) {
	char str[1024];
	scanf("%s",str);
	BigDecimal m=str,n=str;
	for(int i=0;i<10;i++){
		n=n+m;
		n.ShowValue();	
		printf("\n");
	}

	return 0;
}
