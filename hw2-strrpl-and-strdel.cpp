#include <stdio.h>
#include <string.h>

void strrpl(char *subject, char *search, char *replace) {
	char *isfind = strstr(subject, search);
	if(isfind == 0) {
		return;
	}
	strcpy(isfind+strlen(replace), isfind+strlen(search));
	strncpy(isfind, replace, strlen(replace));
}
void strdel(char *haystack, char *needle) {
	strrpl(haystack, needle, "");
}
int main(void) {
	char s[100]="1234567890";
	printf("%s\n", s);
	strrpl(s, "3456789", "abcdefghijklmno");
	printf("%s\n", s);
	strdel(s, "ef");
	printf("%s\n", s);
	return 0;
}

