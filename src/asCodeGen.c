void instructionsOut(char* s) {
	fprintf(targetOut, "\t%s\n", s);
}

void dataOut(){
	fprintf(targetOut, ".data\n\tnewLine: .asciiz \"\\n\" \n\tzero:	.float 0.0 \n.text\n\nmain:\n\n\taddi $sp $sp -40\n\n");
}

//DECALRE
void declarationOut(char *id){
	instructionsOut("\n\t#declare variable");
	char string[100];
	sprintf(string, "\n\taddi $s0, $zero, 0\n\tsw $s0 %d($sp)", stackIndex(id));
	instructionsOut(string);
}

//FIND VARIABLE TO STACK
int stackIndex(char *s){
	int indx = returnIndex(s);
	return 4*indx;
}

//PRINT
void printOut(char *id){
	instructionsOut("\n\t#print");
	char string[100];
	sprintf(string, "\n\tlw $s0, %d($sp) \n\tjal printl", stackIndex(id));
	instructionsOut(string);
}

//ASSIGN
int indxVars(int v){
	if (v == -1)
		return 7;
	else if(v == -2)
		return 6;
	else
		return v;
}

void factorOutNum(int v){
	char string[100];
	sprintf(string, "\n\taddi $t%d, $zero, %d", varsCount%8, v);
	instructionsOut(string);
}
void factorOutId(char *id, int v){
	char string[100];
	sprintf(string, "\n\tlw $t%d, %d($sp)", varsCount%8, stackIndex(id));
	instructionsOut(string);
}

void assignOut(char *id){
	instructionsOut("\n\t#assign value");
	char string[100];
	sprintf(string, "\n\tsw $t%d %d($sp)", indxVars((varsCount%8)-1), stackIndex(id));
	instructionsOut(string);
}

//IFS
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

void 	ifBoolOut(int a, int b){
	char string[100];
	sprintf(string, "\n\n\t%s $t%d, $t%d, Else%d", logicOp, indxVars((varsCount%8)-1), indxVars((varsCount%8)-2) ,ifCount);
	instructionsOut(string);

}

//LOOPS
void 	whileBoolOut(int a, int b){
	char string[100];
	sprintf(string, "\n\n\t%s $t%d, $t%d, Exit%d", logicOp, indxVars((varsCount%8)-2), indxVars((varsCount%8)-1) ,loopCount);
	instructionsOut(string);

}

void 	forBoolOut(int a, int b){
	char string[100];
	sprintf(string, "\n\n\t%s $t%d, $t%d, Exit%d", logicOp, indxVars((varsCount%8)-2), indxVars((varsCount%8)-1) ,loopCount);
	instructionsOut(string);

}

//ARITHMETICS
void addOut(){
	instructionsOut("#ADD");
	char string[100];
	sprintf(string, "\n\tadd $t%d, $t%d, $t%d", indxVars((varsCount%8)-1), indxVars((varsCount%8)-1), indxVars((varsCount%8)-2));
	instructionsOut(string);

}

void multOut(){
	instructionsOut("#MULT");
	char string[100];
	sprintf(string, "\n\tmul $t%d, $t%d, $t%d", indxVars((varsCount%8)-1), indxVars((varsCount%8)-1), indxVars((varsCount%8)-2));
	instructionsOut(string);
}

void divOut(){
	instructionsOut("#DIV");
	char string[100];
	sprintf(string, "\n\tdiv $t%d, $t%d, $t%d", indxVars((varsCount%8)-1), indxVars((varsCount%8)-2), indxVars((varsCount%8)-1));
	instructionsOut(string);
}

void substractOut(){
	instructionsOut("#SUB");
	char string[100];
	sprintf(string, "\n\tsub $t%d, $t%d, $t%d", indxVars((varsCount%8)-1), indxVars((varsCount%8)-2), indxVars((varsCount%8)-1));
	instructionsOut(string);

}

void negative(){
	instructionsOut("#NEG");
	char string[100];
	sprintf(string, "\n\tmul $t%d, $t%d, -1", indxVars((varsCount%8)-1), indxVars((varsCount%8)-1));
	instructionsOut(string);
}
