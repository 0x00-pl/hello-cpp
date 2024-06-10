#if 0
#include <string.h>
#include <stdio.h>

int anchor_match(char *anchor_p, char *anchor_endp, char *str_p, char *str_endp)
{
	if (str_endp - str_p < anchor_endp - anchor_p) return 0;
	while (*anchor_p == *str_p && anchor_p != anchor_endp)
	{
		anchor_p++;
		str_p++;
	}
	return anchor_p == anchor_endp ? 1 : 0;
}

int match_pattern(char *pattern, char *str)
{
	char *pattern_p = pattern, *pattern_endp = pattern + strlen(pattern);
	char *anchor_p, *anchor_endp;
	unsigned int anchor_len;
	char *str_p = str, *str_endp = str + strlen(str);
	while (pattern_p != pattern_endp && str_p != str_endp)
	{
		switch (*pattern_p)
		{
			case '*':
				anchor_p = pattern_p;
				do
				{
					anchor_p++;
				} while (*anchor_p == '*');
				anchor_endp = anchor_p;
				if (anchor_p == pattern_endp) return 1;
				while (anchor_endp != pattern_endp && *anchor_endp != '*')
				{
					anchor_endp++;
				}
				anchor_len = anchor_endp - anchor_p;
				while (!anchor_match(anchor_p, anchor_endp, str_p, str_endp))
				{
					str_p++;
					if (str_p == str_endp) return 0;
				}
				pattern_p = anchor_p;
				break;
			case '?':
				str_p++;
				pattern_p++;
				break;
			default:
				if (*str_p == *pattern_p)
				{
					str_p++;
					pattern_p++;
				}
				else
				{
					return 0;
				}
				break;
		}
	}
	if (((pattern_p == pattern_endp) || (*pattern_p == '*' && pattern_p + 1 == pattern_endp)) && str_p == str_endp)
		return 1;
	else
		return 0;
}
struct entry_list{
	entry_list* next;
	char* fmt;
	char* dest;
};
entry_list entry_list_end;
void entry_list_init(){
	entry_list_end.next= &entry_list_end;
}
int entry_list_is_empty(){
	return entry_list_end.next == &entry_list_end;
}
void push_entry_list(char* fmt, char* dest){
	entry_list* new_item= new entry_list;
	new_item->fmt=fmt;
	new_item->dest=dest;
	
	new_item->next= entry_list_end.next;
	entry_list_end.next= new_item;
}
entry_list* pop_entry_list(){
	entry_list* ret= entry_list_end.next;
	entry_list_end.next= ret->next;
	return ret;
}
int pl_match_in_list(){
	char* fmt;
	char* dest;
	if(entry_list_is_empty())
		return 0;

	if(1){
		entry_list* temp= pop_entry_list();
		fmt= temp->fmt;
		dest= temp->dest;
		delete temp;
	}
	for(char* p=dest; *p!='\0'&&dest!='\0'; p++){
		switch(*fmt){
		case '?':
			fmt++;
			break;
		case '*':
			//* as ?
			push_entry_list(fmt, p+1);

			//* as null
			++fmt;
			--p;//for²¹³¥
			break;
		default:
			if(*fmt==*p)
				fmt++;
			else
				return 0;
		}
	}
	//not full match
	if(dest!=0) return 0;

	return 1;
}
int pl_match(char* fmt, char*dest){
	push_entry_list(fmt,dest);
	//or
	while(!entry_list_is_empty())
		if(pl_match_in_list())
			return 1;
	return 0;
}

int test(char *pattern, char *str, int answer)
{
	int ret;
	ret = match_pattern(pattern, str);
	if (ret != answer)
		printf("ERROR: pattern=%s, str=%s\n", pattern, str);
	return 0;
}

void main2()
{
	test("*.exe", "a.exe", 1);
	test("*.exe", "a.pdf", 0);
	test("test.*", "test.abc", 1);
	test("test.*", "test.", 1);
	test("*test.*", "test.", 1);
	test("*.*", ".", 1);
	test("*.*", "a.", 1);
	test("*.*", ".b", 1);
	test("*.*", "a.b", 1);
	test("*.*", "ab", 0);
	test("*23", "1223", 1);
}
#endif