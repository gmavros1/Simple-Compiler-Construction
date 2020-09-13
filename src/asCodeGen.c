void instructionsOut(char* s) {
	fprintf(targetOut, "\t%s\n", s);
}

void dataOut(){
	fprintf(targetOut, ".data\n\tnewLine: .asciiz \"\\n\" \n\tzero:	.float 0.0 \n.text\n\nmain:\n\n\taddi $sp $sp -40\n\n");
}

//dokimiiiiiiiii
void addOut(float a, float b){
}

void declarationOut(char *id){
	char string[100];
	sprintf(string, "\n\taddi $s0, $zero, 0\n\tsw $s0 %d($sp)", stackIndex(id));
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

void assignOut(char *id, int v){
	char string[100];
	sprintf(string, "\n\taddi $s0, $zero, %d\n\tsw $s0 %d($sp)", v, stackIndex(id));
	instructionsOut(string);
}

void elseOut(){
	char string[100];
	sprintf(string, "\n\tElse%d:", ifCount);
	instructionsOut(string);
}

void endif(){
	char string[100];
	sprintf(string, "\n\tEndIf%d:", ifCount);
	instructionsOut(string);
}

void ifOut(int a, int b){
	char string[100];
	sprintf(string, "\n\taddi $t0, $zero, %d\n\taddi $t1, $zero, %d\n\n\t%s $t0, $t1, Else%d",a,b, logicOp, ifCount);
	instructionsOut(string);

}
