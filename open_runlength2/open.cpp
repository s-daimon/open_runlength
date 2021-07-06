#include <iostream>
#include <vector>

int main() {
	const char* input_filename = "output.bin";
	const char* opened_filename = "opened_compressed.bin";
	FILE* read_fp;
	FILE* write_fp;
	fopen_s(&read_fp, input_filename, "rb");
	fopen_s(&write_fp, opened_filename, "wb");
	if (read_fp == NULL || write_fp == NULL) {
		printf("file‚ðŠJ‚¯‚Ü‚¹‚ñ‚Å‚µ‚½");
		exit(1);
	}
	char continuous = 0;
	bool compressed = false;
	int current_letter;
	while ((current_letter = fgetc(read_fp)) != EOF) {
		//printf("%d\n", current_letter);
		if (!compressed) {
			compressed = true;
			continuous = (char)current_letter;
		}
		else {
			if (continuous > 0) {
				for (int i = 0; i < continuous; i++) {
					fputc(current_letter, write_fp);
				}
			}
			else {
				fputc(current_letter, write_fp);
				printf("continuous = %d\n", continuous);
				for (int i = 0; i > continuous + 1; i--) {
					fputc(fgetc(read_fp), write_fp);
					printf("int i = %d", i);
				}
			}
			compressed = false;
			continuous = 0;
		}
	}
   
}