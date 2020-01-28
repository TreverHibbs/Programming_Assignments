import org.junit.Test;
import org.junit.jupiter.api.AfterEach;

import static org.junit.Assert.*;


public class StackTestBasic {
    private Stack myStack = new Stack();
    /** == STEP 1 ==
     * Test 1: test the isEmpty method
     * When there are no values in the stack class the isEmpty method and check
     * if it is true.
     */
    @Test
    public void testIsEmpty() {
        assertEquals(true, myStack.isEmpty());
        myStack.reset();
    }

    /** == STEP 3 ==
     * Test 3: test the pop method
     * When you push a number and then pop a number this should result
     * in the stack being empty. Check if this is true using the push method
     * pop method and isEmpty method.
     */
    @Test
    public void testPop(){
        myStack.push( 1);
        myStack.pop();
        assertEquals(true, myStack.isEmpty());
        myStack.reset();
    }

    /** == STEP 4 ==
     * Test 4: test the return value of pop
     * When push is called it should store the given integer in the stack array.
     * pop should then return this integer. Check if pop returns the same integer that
     * stack stored in the array.
     */
    @Test
    public void testPopReturn(){
        myStack.push( 1);
        int returnValue = myStack.pop();
        assertEquals(1, returnValue);
        myStack.reset();
    }

    /** == STEP 5 ==
     * Test 5: test that pop and push can handle several numbers in the stack.
     * Store three numbers in the stack at once and then pop each number and see
     * if they are returned.
     */
    @Test
    public void testPopReturnAdvanced(){
        //test if pop will return the same three values loaded into stack by push.
        myStack.push( 1);
        myStack.push( 2);
        myStack.push( 3);
        assertEquals(3, myStack.pop());
        assertEquals(2, myStack.pop());
        assertEquals(1, myStack.pop());
        myStack.reset();
    }

    /** == STEP 6 ==
     * Test 6: test pop no element when stack empty
     * WHen stack is empty pop should not attempt to
     * access an index out of bounds of the stack array.
     */
    @Test
    public void testPopNoElements(){
        myStack.pop();
        myStack.reset();
    }

    /** == STEP 7 ==
     * Test 7: test if top doesnt effect the contents of the stack.
     * Top should not effect the contents of the stack. If we
     * check the isEmpty for false this will confirm for us that
     * top has not effected the contents after a push.
     */
    @Test
    public void testTop(){
        myStack.push( 1);
        myStack.Top();
        assertEquals(false, myStack.isEmpty());
        myStack.reset();
    }

    /** == STEP 8 ==
     * Test 8: test that top returns the last value pushed on stack.
     * This test will confirm that top returns the last value pushed on
     * the stack.
     */
    @Test
    public void testTopAdvanced(){
        myStack.push( 1);
        assertEquals(1, myStack.Top());
        myStack.reset();
    }
}