#include<stdio.h>

int main(void)
{
    int i,j,k,nodes;
    char n[5]={'A','B','C','D','E'};
    int cost[5][5],adj[5][5],inter[5][5];
    
    //read no of nodes and the cost matrix
    printf("Enter number of nodes: ");
    scanf("%d",&nodes);
    
    printf("Enter cost matrix: \n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==999)
            {
                adj[i][j]=0;
                inter[i][j]=999;
            }
            else
            {
                adj[i][j]=1;
                inter[i][j]=i;
            }
        }
    }

    //display all three matrices
    printf("\nCost matrix is: \n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Adjacency matrix is: \n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Intermediate matrix is: \n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            printf("%d\t",inter[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    //bellman-ford algorithm(distance vector)
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            if(adj[i][j]==1)
            {
                for(k=0;k<nodes;k++)
                {
                    if(cost[i][j]+cost[j][k]<cost[i][k])
                    {
                        cost[i][k]=cost[i][j]+cost[j][k];
                        inter[i][k]=j;
                    }
                }
            }
        }
    }
    
    for(i=0;i<nodes;i++)
    {
        printf("From %c : \n",n[i]);
        printf("To\tCost\tNext\n");
        for(j=0;j<nodes;j++)
        {
            if(inter[i][j]==i)
                printf("%c\t%d\t \n",n[j],cost[i][j]);
            else
                printf("%c\t%d\t%c\t \n",n[j],cost[i][j],n[j]);
        }
        printf("\n");
    }
    
    return 0;
}

