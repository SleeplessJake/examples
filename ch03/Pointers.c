int main() {
	int userAge = 15;

	int* numberPtr = &userAge;

	if (age > 18) {
		puts("");
	}
	else {
		puts("%i? Get a job!", *numberPtr);
	}
}