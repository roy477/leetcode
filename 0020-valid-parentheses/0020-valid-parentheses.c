bool isValid(char *s) {

    char stack[10000];
    int top = -1;

    for(int i=0; s[i]; i++){
        if(s[i]=='(') stack[++top]=')';
        else if(s[i]=='{') stack[++top]='}';
        else if(s[i]=='[') stack[++top]=']';
        else if(top<0 || stack[top--]!=s[i]) return false;
    }

    return top==-1;
}