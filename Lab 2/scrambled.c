int scrambled( unsigned int a[], unsigned int b[], unsigned int len ){
	int total1=0;
	int total2=0;

	for(int i=0;i<len;i++){
		total1=total1+a[i];
		total2=total2+b[i];
	}
	if (total1==total2){
		return 1;
	}
	else{
		return 0;
	}
}