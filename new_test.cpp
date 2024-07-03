char * getmemory(void){
	char p[] = "hello";
	return p;
}
void test(void){
	char *str = NULL;
	str = getmemory();
	printf("%sn", str);
}