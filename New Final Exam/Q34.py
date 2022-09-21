class BST_w_sz:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.size = 1
    
    def insert(self, value):
        '''Assume that value is not in the tree.'''
        if value < self.value:
            if self.left == None:
                self.left = BST_w_sz(value)
                self.size += 1
            else:
                self.left.insert(value)
                self.size += 1
        else:
            if self.right == None:
                self.right = BST_w_sz(value)
                self.size += 1
            else:
                self.right.insert(value)
                self.size += 1

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = BST(4)
        print(a) # prints 4
        '''
        return str(self.value)


def delete_value(root, value):
    '''Remove the value of value from a BST_w_sz tree rooted at node 
    root. Return the root of the modified valid BST_w_sz tree.
    The function must run in O(h) time, where h is the height of the tree'''
    cur_node = root
    while (root.value != value):
        if value < cur_node.value:
            cur_node.size -= 1
            cur_node = cur_node.left
        else:
            cur_node.size -= 1
            cur_node = cur_node.left
    if cur_node.left == cur_node.right == None:
        cur_node = None
        cur_node.size = 0
    elif (cur_node.left != None) and (cur_node.right == None):
        cur_node = cur_node.left
        cur_node.size -= 1
    elif (cur_node.left == None) and (cur_node.right != None):
        cur_node = cur_node.right
        cur_node.size -= 1
    else:
        cur_node.size -= 1
        cur_node = cur_node.right
        while cur_node.left != None:
            cur_node = cur_node.left
            cur_node.size -= 1
    return root
    


def median_bst(root):
    if root.left.size == root.right.size:
        return root.value 
    elif root.left.size > root.right.size:
        return median_bst(root.left)
    else:
        return median_bst(root.right)
    