#include <iostream>


int main() {

	int N;
	int K;

	std::cin >> N;
	std::cin >> K;
	

	int *ALL_PTR = new  int[N];

	for (int i = 0; i < N; i++) {
		ALL_PTR[i] = i+1;
	}

	int **str_ptr = new int *[K];//строки по 4
	

	for (int i = 0; i < K; i++) {
		str_ptr[i] = new int[4];//по 4
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> str_ptr[i][j];
		}
	}

	int *vrptr = new  int[N];//новый масссив
	int k = 0;
	int z3 = 0;//флаг для 3
	int z4 = 0;//флаг для 4
	for (int j = 0; j < K; j++) {
		for (int i = 0; i < N; i++) {

			if (str_ptr[j][0] > str_ptr[j][1]) {//если первое число больше второго
				if (ALL_PTR[i] >= str_ptr[j][0] || ALL_PTR[i] <= str_ptr[j][1]) {
					vrptr[k] = ALL_PTR[i];
					k++;
				}
			}
			else if (str_ptr[j][0] < str_ptr[j][1]) {//если второе число больше первого
				if (ALL_PTR[i] <= str_ptr[j][0] || ALL_PTR[i] >= str_ptr[j][1]) {
					vrptr[k] = ALL_PTR[i];
					k++;
				}
			}

		}

		

		for (int l = 0; l < k; l++) {
			if ((vrptr[l] == str_ptr[j][2])&& (str_ptr[j][0] != str_ptr[j][3]) && (str_ptr[j][1] != str_ptr[j][3])) {
				z3 = 1;
			}
		    if ((vrptr[l] == str_ptr[j][3]) && (str_ptr[j][0] != str_ptr[j][2]) && (str_ptr[j][1] != str_ptr[j][2])) {
				z4 = 1;
				
			}
		}
	
		if (z3==z4) {
			std::cout << "NO" << std::endl;
		}
		else {
			std::cout << "YES" << std::endl;
		}

		k = 0;
		z3 = 0;
		z4 = 0;

	}




	return 0;
}