#include <stdio.h>
#include <stdlib.h>
struct node{
	char l;
	struct node *nxt;
}*head0=NULL,*head1=NULL,*nnode=NULL,*tail1=NULL,*tail0=NULL,*sw;
int main(void) {
	char name1[30],name2[30];
	printf("FLAMES CALCULATOR\n\nname1:");
	gets(name1);
	printf("name2:");
	gets(name2);
	int i=0;
	while(name1[i]!='\0'){
		if(name1[i]==' '){
			i++;
			continue;
		}
		nnode = (struct node*)malloc(sizeof(struct node));
		nnode->nxt=NULL;
		nnode->l=name1[i];
		if(head0==NULL){
			head0=nnode;
			tail0=nnode;
		}else{
			tail0->nxt=nnode;
			tail0=nnode;
		}
		i++;
	}
	i=0;
	while(name2[i]!='\0'){
		if(name2[i]==' '){
			i++;
			continue;
		}
		nnode = (struct node*)malloc(sizeof(struct node));
		nnode->nxt=NULL;
		nnode->l=name2[i];
		if(head1==NULL){
			head1=nnode;
			tail1=nnode;
		}else{
			tail1->nxt=nnode;
			tail1=nnode;
		}
		i++;
	}
	nnode = head0;
	printf("Names without name:\n");
	while(nnode!=NULL){
		printf("%c",nnode->l);
		nnode=nnode->nxt;
	}
	printf("\n");
	nnode = head1;
	while(nnode!=NULL){
		printf("%c",nnode->l);
		nnode=nnode->nxt;
	}
	i=0;
	while(name1[i]!='\0'){
		nnode=head1;
		sw=NULL;
		while(nnode!=NULL && nnode->l!=name1[i]){
			sw=nnode;
			nnode=nnode->nxt;
		}
		if(nnode!=NULL){
			if(nnode==head1)
				head1=nnode->nxt;
			else{
				sw->nxt=nnode->nxt;
			}
		}
		i++;
	}
	i=0;
	while(name2[i]!='\0'){
		nnode=head0;
		sw=NULL;
		while(nnode!=NULL && nnode->l!=name2[i]){
			sw=nnode;
			nnode=nnode->nxt;
		}
		if(nnode!=NULL){
			if(nnode==head0)
				head0=nnode->nxt;
			else{
				sw->nxt=nnode->nxt;
			}
		}
		i++;
	}
	nnode = head0;
	i=0;
	printf("\nNames after removing common letters:\n");
	while(nnode!=NULL){
		printf("%c",nnode->l);
		nnode=nnode->nxt;
		i++;
	}
	printf("\n");
	nnode = head1;
	while(nnode!=NULL){
		printf("%c",nnode->l);
		nnode=nnode->nxt;
		i++;
	}
	printf("\nTotal characters left:%d\n",i);
	struct node *ch,*ct,ar[6],*cl,*al,*lll;
	ar[0].l='F';
	ar[1].l='L';
	ar[2].l='A';
	ar[3].l='M';
	ar[4].l='E';
	ar[5].l='S';
	ch=&ar[0];
	ar[0].nxt=&ar[1];
	ar[1].nxt=&ar[2];
	ar[2].nxt=&ar[3];
	ar[3].nxt=&ar[4];
	ar[4].nxt=&ar[5];
	ar[5].nxt=&ar[0];
	lll=&ar[5];
	ct=ch;
	nnode = NULL;
	for(int z=0;z<5;z++){
		for(int j=0;j<i-1;j++){
			nnode=ct;
			ct=ct->nxt;
		}
		if(ct==ch){
			lll->nxt=ch->nxt;
			ch=ch->nxt;
		}else{
			nnode->nxt=ct->nxt;
			if(ct==lll){
				lll=nnode;
				lll->nxt=ch;
			}
		}
		ct=nnode->nxt;
	}
	printf("Relationship between %s and %s will end up in ",name1,name2);
	switch(ch->l){
		case 'F':
			printf("FRIEND(F)");
			break;
		case 'L':
			printf("LOVE(L)");
			break;
		case 'A':
			printf("AFFECTION(A)");
			break;
		case 'M':
			printf("MARRIAGE(M)");
			break;
		case 'E':
			printf("ENEMY(E)");
			break;
		case 'S':
			printf("SIBLINGS(S)");
			break;
	}
}
