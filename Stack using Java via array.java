import java.util.Scanner;
class Java{
    int top=-1;int max=6;
    int[] arr=new int[max];
    Java()
    {
        System.out.println("Welcome to the stack operation!");
        System.out.println("\n");
    }
    boolean isFull()
    {
        return top==max-1;
    }
    boolean isEmpty()
    {
        return top==-1;
    }
    
    void push(int element)
    {
        if(isFull())
        {
            System.out.println("Cannot push an element!");
            System.out.println("\n");
        }
        else
        {
            System.out.printf("%d pushed to the stack\n",element);
            arr[++top]=element;
            System.out.println("\n");
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            System.out.println("Cannot pop an empty stack");
            System.out.println("\n");
        }
        else{
            System.out.printf("%d was removed\n",arr[top]);
            top--;
            System.out.println("\n");
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            System.out.println("Cannot give top element");
            System.out.println("\n");
        }
        return arr[top];
    }
    void disp()
    {
        if(isEmpty())
        {
            System.out.println("Display invalid!");
            System.out.println("\n");
        }
        else{
            System.out.println("Elements are");
            for (int i=top ; i>=0 ; i-- ) 
            {
                System.out.println(arr[i]);
            }
            System.out.println("\n");
        }
    }
    public static void main (String[] args) 
    {
        Java ob=new Java();
        Scanner input=new Scanner(System.in);
        int choice;
        do
        {
            System.out.println("Operations:\n\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Display\n\t5.Exit");
            System.out.print("Enter Choice:");
            choice=input.nextInt();
            
            System.out.println("\n");
            switch(choice)
            {
                case 1:
                    System.out.print("Enter element for insert:");
                    int ele=input.nextInt();
                    ob.push(ele);
                break;
                
                case 2:
                    ob.pop();
                break;
                
                case 3:
                    int e=ob.peek();
                    System.out.printf("Peek is %d\n\n",e );
                break;
                
                case 4:
                    ob.disp();
                break;
                
                default:
                   if(choice!=5)
                   {
                       System.out.println("Invalid Choice!\n");
                   }
                   else{
                       System.out.println("Program Stopped...\n");
                   }
                break;
            }
        }while(choice!=5);
        
        input.close();
    }
}