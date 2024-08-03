#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int t_size;
    int u_size;
    int *ptr;
};
void createArray(struct myArray *a, int tsize,int usize);
void setVal(struct myArray *a);
void Display(struct myArray *a);

int main(){
    struct myArray marks;
    createArray(&marks,10,2);
    printf("we setting the marks here\n");
    setVal(&marks);
    printf("we showing the marks here\n");
    Display(&marks);
    return 0;

}

void createArray(struct myArray *a, int tsize,int usize){
    (*a).t_size= tsize;
    (*a).u_size= usize;
    (*a).ptr= (int*)malloc(tsize * sizeof(int));

    // a->t_size = tsize;
    // a->u_size = usize;
    // a->ptr = (int*)malloc(tsize * sizeof(int));
}

void Display(struct myArray *a){                //show
    for(int i=0; i<a->u_size; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}

void setVal(struct myArray *a){
    int n;
    for(int i=0;i<a->u_size; i++)
    {
        printf("enter the elememt at %d : ",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
