/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func pairSum(head *ListNode) int {
    var stack *ListNode = nil
    
    cur := head
    fast := head

    for fast != nil {
        fast = fast.Next.Next
        next := cur.Next
        cur.Next = stack
        stack = cur
        cur = next
    }

    mx := 0
    for stack != nil {
        mx = max(mx, stack.Val + cur.Val)
        stack = stack.Next
        cur = cur.Next
    }

    return mx
}
