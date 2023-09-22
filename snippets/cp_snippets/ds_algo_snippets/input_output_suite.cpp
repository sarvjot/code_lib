// prefix: iosuite
// description: fast io and file io
void fastinput(big &number){
	bool negative = false;
	int c;

	number = 0;

	c = getchar();
	if (c == '-'){
		negative = true;
		c = getchar();
	}

	for (; (c > 47 && c < 58); c = getchar())
		number = number * 10 + c - 48;

	if (negative)
		number *= -1;
}

void io_on(){
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}
