class Solution {
    public int evalRPN(String[] tokens) 
    {
        Stack<Integer> stack = new Stack<>();
        int a,b;
        
        for(String s: tokens)
        {
            if(s.equals("+"))
               stack.push(stack.pop()+stack.pop());
            
            else if(s.equals("-"))
               {
                   a = stack.pop();
                   b = stack.pop();
                   stack.push(b-a);
               }
            else if(s.equals("*"))
               stack.push(stack.pop() * stack.pop());
            
            else if(s.equals("/"))
               {
                   a = stack.pop();
                   b = stack.pop();
                   stack.push(b/a);
               }
            else
               stack.push(Integer.parseInt(s));
        }
        
        return stack.pop();
    }
}
