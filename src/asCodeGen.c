void instructionsOut(char* s) {
	fprintf(targetOut, "\t%s\n", s);
}

void dataOut(){
	fprintf(targetOut, ".data\n\tnewLine: .ascizz \"\\n\" \n\tzero:	.float 0.0 \n.text\n\nmain:\n");
}

//dokimiiiiiiiii
void addOut(float a, float b){
		char string[100];
		sprintf(string, "\n%f + %f\n", a, b);
		instructionsOut(string);
}

void declarationOut(char *id){
		char string[100];
		sprintf(string, "\n\taddi $s0, $zero, 0 \n\taddi $sp $sp -4\n\tsw $s0 %d($sp)", stackIndex(id));
		instructionsOut(string);
}

int stackIndex(char *s){
		int indx = returnIndex(s);
		return 4*indx;
}

void printOut(char *id){
		char string[100];
		sprintf(string, "\n\tlw $s0, %d($sp) \n\tjal printl", stackIndex(id));
		instructionsOut(string);
}
