import org.junit.Test;

import static org.junit.Assert.*;


public class StackTestAdvanced2 {
    private Stack myStack = new Stack();

    /** == STEP 10 ==
     * Test 10: Test push when stack is full
     * push 100 values into stack to fill stack. Stack should then throw
     * exception on push 101.
     */
    @Test(expected = IndexOutOfBoundsException.class)
    public void pushOnFullStack(){
        int i = 0;
        while(i < 101){
            myStack.push(1);
        }
        myStack.reset();
    }
}