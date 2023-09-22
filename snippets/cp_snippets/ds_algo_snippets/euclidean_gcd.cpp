// prefix: greatestcommondivisor
// description: greatest common divisor of two numbers
big gcd(big a, big b){
	if (b == 0){
		return a;
	}
	return gcd(b, a % b);
}
