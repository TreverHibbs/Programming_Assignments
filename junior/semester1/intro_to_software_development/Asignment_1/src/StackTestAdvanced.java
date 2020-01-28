import org.junit.Test;

import static org.junit.Assert.*;


public class StackTestAdvanced {
    private Stack myStack = new Stack();
    /** == STEP 9 ==
     * Test 9: test the top function when stack is empty
     * When there are no values in the stack Top method should return
     * a value symbolizing an empty stack (NaN).
     */
    @Test
    public void testTopEmptyStack(){
        assertEquals(-1, myStack.Top());
        myStack.reset();
    }

    /** == STEP 11 ==
     * Test 11: test the reset function
     * When reset function is called the stack is effectively
     * deleted. Therefore we test if the stack is empty after reset.
     */
    @Test
    public void resetTest(){
        myStack.push(1);
        myStack.reset();
        assertEquals(true, myStack.isEmpty());
    }
}
