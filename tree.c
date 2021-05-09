/*入力されたものから二分木を生成し表示するプログラム*/
#include<stdio.h>
struct node {
	int value;
	struct node *left;
	struct node *right;
};
/*欲しいメモリサイズを引数で指定する関数
 *引数は欲しいメモリサイズ
 *戻り値はそのメモリへのポインタ
↓テスト:mainに戻り値をpとして表示させた。
	*malloc（100）を3回呼び出すと，pとして7409000,7409112,7409224が表示された。
以上より、欲しいメモリサイズを指定できていることが確認できた。*/
void*malloc(unsigned int size);

/*構造体nodeを作る関数
 *引数はleft,value,right
 *戻り値は新たに作った構造体nodeへのポインタ
↓テスト:mainに関数を呼び出し、戻り値を表示した。
	*二分木をcreate_nodeで作成
		n1はleftが0,valueが10,rightが0の構造体へのポインタ
		n2はleftが0,valueが30,rightが0の構造体へのポインタ
		n3はleftがn1,valueが20,rightがn2の構造体へのポインタ
	n1,n2,n3の値として200040,200064,200088が表示された。
以上より、構造体の大きさのメモリを確保できており、構造体nodeが作られていることが確認できた。*/
struct node *create_node(struct node *left,int value,struct node *right)
{
	struct node*olditem;
	olditem=(struct node*)malloc(sizeof(struct node));
	olditem->value=value;
	olditem->left=left;
	olditem->right=right;
	return olditem;
}

/*二分木を表示する関数print_tree
 *引数はnodeへのポインタ」
 *戻り値はない
↓テスト:mainにcreate_nodeを呼び出し、print_treeで表示した。
	*二分木をcreate_nodeで作成
		n4はleftが0,valueが25,rightが0の構造体へのポインタ
		n1はleftが0,valueが10,rightが0の構造体へのポインタ
		n2はleftがn4,valueが30,rightが0の構造体へのポインタ
		n3はleftがn1,valueが20,rightがn2の構造体へのポインタ
	print_treeの引数にn3を代入して表示させると、<<-,10,->,20,<<-,25,->,30,->>が表示された。
	*二分木をcreate_nodeで作成
		n1はleftが0,valueが10,rightが0の構造体へのポインタ
		n2はleftが0,valueが30,rightが0の構造体へのポインタ
		n3はleftがn1,valueが20,rightがn2の構造体へのポインタ
	print_treeの引数にn3を代入して表示させると、<<-,10,->,20,<-,30,->>が表示された。
以上より、二分木を表示していることが確認できた。*/
void print_tree(struct node *tree)
{
	if(tree==0)printf("-");
	else if(tree!=0){
	printf("<");
	print_tree(tree->left);
	printf(",");
	printf("%d",tree->value);
	printf(",");
	print_tree(tree->right);
	printf(">");
	}
}

/*入力されたものを二分木にする関数
 *引数はない
 *戻り値はnodeへのポインタ
↓テスト:mainで入力をさせ、関数を呼び出し、print_treeで表示した。
	*<<-,10,->,20,<-,30,->>と入力し、read_treeを呼び出しその戻り値をprint_treeの引数に代入すると、<<-,10,->,20,<-,30,->>が表示された。
	*10,10,->と入力し、read_treeを呼び出しその戻り値をprint_treeの引数に代入すると、ERROR1-が表示された。
	*<-,10->と入力し、read_treeを呼び出しその戻り値をprint_treeの引数に代入すると、ERROR2-が表示された。
	*<-,,->と入力し、read_treeを呼び出しその戻り値をprint_treeの引数に代入すると、ERROR3-が表示された。
	*<-10,->と入力し、read_treeを呼び出しその戻り値をprint_treeの引数に代入すると、ERROR4-が表示された。
	*<-,10,-と入力し、read_treeを呼び出しその戻り値をprint_treeの引数に代入すると、ERROR5-が表示された。
以上より、入力されたものを二分木にする(入力が正しくないときはエラーメッセージを表示する)ことが確認できた。
*/
struct node *read_tree()
{
	char tree;
	int a;
	struct node *n,*l,*r;
	scanf("%c",&tree);
	if(tree=='-')return 0;

	if(tree=='<')l=read_tree();
	else{
		printf("ERROR1");
		return 0;
	}
	scanf("%c",&tree);
	if(tree==','){
		if(scanf("%d",&a)==1){
			scanf("%c",&tree);
			if(tree==','){
				r=read_tree();
			}
			else{
				printf("ERROR2");
				return 0;
			}
		}
		else{
			printf("ERROR3");
			return 0;
		}
	}
	else{
		printf("ERROR4");
		return 0;
	}
	scanf("%c",&tree);
	if(tree=='>')n=create_node(l,a,r);
	else{
		printf("ERROR5");
		return 0;
	}
	return n;
}
/*↓mainのテスト:入力をさせ、read_treeを呼び出しその戻り値をprint_treeの引数に代入し表示した。
	*<<-,10,->,20,<-,30,->>と入力すると、<<-,10,->,20,<-,30,->>が表示された。
	*<-,10->と入力すると、ERROR2-が表示された。
	*<-,,->と入力すると、ERROR3-が表示された。
	*<-10,->と入力すると、ERROR4-が表示された。
	*<-,10,-と入力すると、ERROR5-が表示された。
	*<<-,10,->,20,<<-,25,->,30,->>と入力すると、<<-,10,->,20,<<-,25,->,30,->>が表示された。
以上より、入力されたものから二分木を生成し表示する(入力が正しくないときはエラーメッセージを表示する)ことが確認できた。
*/
int main()
{
	struct node *p;
	//mallocの確認
	//p=malloc(100);
	//printf("%d\n",p);
	//p=malloc(100);
	//printf("%d\n",p);
	//p=malloc(100);
	//printf("%d\n",p);
	
	struct node *n1, *n2, *n3, *n4;
	//create_nodeの確認
	//木を作成
	//n1 = create_node(0, 10, 0);
	//n2 = create_node(0, 30, 0);
	//n3 = create_node(n1, 20, n2);
	//printf("%d,%d,%d",n1,n2,n3);

	//木を作成
	//n4 = create_node(0,25,0);
	//n1 = create_node(0, 10, 0);
	//n2 = create_node(n4, 30, 0);
	//n3 = create_node(n1, 20, n2);
	
	//print_treeの確認
	//二分木を表示
	//print_tree(n3);
	
	
	struct node *n;
	printf("入力してください\n");
	n = read_tree();
	print_tree(n);

	return 0;
}