/*���͂��ꂽ���̂���񕪖؂𐶐����\������v���O����*/
#include<stdio.h>
struct node {
	int value;
	struct node *left;
	struct node *right;
};
/*�~�����������T�C�Y�������Ŏw�肷��֐�
 *�����͗~�����������T�C�Y
 *�߂�l�͂��̃������ւ̃|�C���^
���e�X�g:main�ɖ߂�l��p�Ƃ��ĕ\���������B
	*malloc�i100�j��3��Ăяo���ƁCp�Ƃ���7409000,7409112,7409224���\�����ꂽ�B
�ȏ���A�~�����������T�C�Y���w��ł��Ă��邱�Ƃ��m�F�ł����B*/
void*malloc(unsigned int size);

/*�\����node�����֐�
 *������left,value,right
 *�߂�l�͐V���ɍ�����\����node�ւ̃|�C���^
���e�X�g:main�Ɋ֐����Ăяo���A�߂�l��\�������B
	*�񕪖؂�create_node�ō쐬
		n1��left��0,value��10,right��0�̍\���̂ւ̃|�C���^
		n2��left��0,value��30,right��0�̍\���̂ւ̃|�C���^
		n3��left��n1,value��20,right��n2�̍\���̂ւ̃|�C���^
	n1,n2,n3�̒l�Ƃ���200040,200064,200088���\�����ꂽ�B
�ȏ���A�\���̂̑傫���̃��������m�ۂł��Ă���A�\����node������Ă��邱�Ƃ��m�F�ł����B*/
struct node *create_node(struct node *left,int value,struct node *right)
{
	struct node*olditem;
	olditem=(struct node*)malloc(sizeof(struct node));
	olditem->value=value;
	olditem->left=left;
	olditem->right=right;
	return olditem;
}

/*�񕪖؂�\������֐�print_tree
 *������node�ւ̃|�C���^�v
 *�߂�l�͂Ȃ�
���e�X�g:main��create_node���Ăяo���Aprint_tree�ŕ\�������B
	*�񕪖؂�create_node�ō쐬
		n4��left��0,value��25,right��0�̍\���̂ւ̃|�C���^
		n1��left��0,value��10,right��0�̍\���̂ւ̃|�C���^
		n2��left��n4,value��30,right��0�̍\���̂ւ̃|�C���^
		n3��left��n1,value��20,right��n2�̍\���̂ւ̃|�C���^
	print_tree�̈�����n3�������ĕ\��������ƁA<<-,10,->,20,<<-,25,->,30,->>���\�����ꂽ�B
	*�񕪖؂�create_node�ō쐬
		n1��left��0,value��10,right��0�̍\���̂ւ̃|�C���^
		n2��left��0,value��30,right��0�̍\���̂ւ̃|�C���^
		n3��left��n1,value��20,right��n2�̍\���̂ւ̃|�C���^
	print_tree�̈�����n3�������ĕ\��������ƁA<<-,10,->,20,<-,30,->>���\�����ꂽ�B
�ȏ���A�񕪖؂�\�����Ă��邱�Ƃ��m�F�ł����B*/
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

/*���͂��ꂽ���̂�񕪖؂ɂ���֐�
 *�����͂Ȃ�
 *�߂�l��node�ւ̃|�C���^
���e�X�g:main�œ��͂������A�֐����Ăяo���Aprint_tree�ŕ\�������B
	*<<-,10,->,20,<-,30,->>�Ɠ��͂��Aread_tree���Ăяo�����̖߂�l��print_tree�̈����ɑ������ƁA<<-,10,->,20,<-,30,->>���\�����ꂽ�B
	*10,10,->�Ɠ��͂��Aread_tree���Ăяo�����̖߂�l��print_tree�̈����ɑ������ƁAERROR1-���\�����ꂽ�B
	*<-,10->�Ɠ��͂��Aread_tree���Ăяo�����̖߂�l��print_tree�̈����ɑ������ƁAERROR2-���\�����ꂽ�B
	*<-,,->�Ɠ��͂��Aread_tree���Ăяo�����̖߂�l��print_tree�̈����ɑ������ƁAERROR3-���\�����ꂽ�B
	*<-10,->�Ɠ��͂��Aread_tree���Ăяo�����̖߂�l��print_tree�̈����ɑ������ƁAERROR4-���\�����ꂽ�B
	*<-,10,-�Ɠ��͂��Aread_tree���Ăяo�����̖߂�l��print_tree�̈����ɑ������ƁAERROR5-���\�����ꂽ�B
�ȏ���A���͂��ꂽ���̂�񕪖؂ɂ���(���͂��������Ȃ��Ƃ��̓G���[���b�Z�[�W��\������)���Ƃ��m�F�ł����B
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
/*��main�̃e�X�g:���͂������Aread_tree���Ăяo�����̖߂�l��print_tree�̈����ɑ�����\�������B
	*<<-,10,->,20,<-,30,->>�Ɠ��͂���ƁA<<-,10,->,20,<-,30,->>���\�����ꂽ�B
	*<-,10->�Ɠ��͂���ƁAERROR2-���\�����ꂽ�B
	*<-,,->�Ɠ��͂���ƁAERROR3-���\�����ꂽ�B
	*<-10,->�Ɠ��͂���ƁAERROR4-���\�����ꂽ�B
	*<-,10,-�Ɠ��͂���ƁAERROR5-���\�����ꂽ�B
	*<<-,10,->,20,<<-,25,->,30,->>�Ɠ��͂���ƁA<<-,10,->,20,<<-,25,->,30,->>���\�����ꂽ�B
�ȏ���A���͂��ꂽ���̂���񕪖؂𐶐����\������(���͂��������Ȃ��Ƃ��̓G���[���b�Z�[�W��\������)���Ƃ��m�F�ł����B
*/
int main()
{
	struct node *p;
	//malloc�̊m�F
	//p=malloc(100);
	//printf("%d\n",p);
	//p=malloc(100);
	//printf("%d\n",p);
	//p=malloc(100);
	//printf("%d\n",p);
	
	struct node *n1, *n2, *n3, *n4;
	//create_node�̊m�F
	//�؂��쐬
	//n1 = create_node(0, 10, 0);
	//n2 = create_node(0, 30, 0);
	//n3 = create_node(n1, 20, n2);
	//printf("%d,%d,%d",n1,n2,n3);

	//�؂��쐬
	//n4 = create_node(0,25,0);
	//n1 = create_node(0, 10, 0);
	//n2 = create_node(n4, 30, 0);
	//n3 = create_node(n1, 20, n2);
	
	//print_tree�̊m�F
	//�񕪖؂�\��
	//print_tree(n3);
	
	
	struct node *n;
	printf("���͂��Ă�������\n");
	n = read_tree();
	print_tree(n);

	return 0;
}