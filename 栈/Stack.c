#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*N);
	ps->_capacity = N;
	ps->_top = -1;

}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = -1;
}
void ExtendMemory(Stack* ps)
{
	STDataType* cur;
	cur = (STDataType*)realloc(ps->_a, sizeof(STDataType)*ps->_capacity * 2);
	if (cur)
	{
		ps->_a = cur;
		ps->_capacity *= 2;
	}
	else
		printf("À©ÈÝÊ§°Ü");
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity - 1)
		ExtendMemory(ps);
	ps->_a[ps->_top + 1] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == -1)
		return 1;
	else
		return 0;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top + 1;
}
void TestStack()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));

	printf("%d\n", StackSize(&ps));
	StackDestory(&ps);
}