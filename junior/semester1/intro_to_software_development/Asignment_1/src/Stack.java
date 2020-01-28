import java.util.ArrayList;

public class Stack {


    private int[] array = new int[100];
    private static int index = 0;

    public static boolean isEmpty(){
        //check if the stack is empty by checking what the index is currently set to.
        if(index == 0) {
            return (true);
        } else{
            return(false);
        }
    }

    public void push(int input) {
        //every time a value is added to stack the
        //stack pointer is incremented so that
        //it always points toward the spot above the top
        //of the stack.
        array[index++] = input;
        return;
    }

    public int pop() {
        //If the index is zero then the stack is empty
        //in that case return -1
        if(index != 0)
            return(array[--index]);
        else
            return(-1);
    }

    public int Top(){
        if(index > 0)
            return(array[index - 1]);
        else
            return(-1);
    }

    public void reset(){
        index = 0;
        return;
    }
}
