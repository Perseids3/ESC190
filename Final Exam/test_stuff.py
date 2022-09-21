def height(node):
    if node == None:
        return -1
    if node.left == None and node.right == None:
        return 0
    return 1 + max(height(node.left), height(node.right))

class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        '''
        node.insert(5) is the same as BST.insert(node, 5)
        We use this when recursively calling, e.g. self.left.insert
        '''
        if value < self.value:
            if self.left == None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right == None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = BST(4)
        print(a) # prints 4
        '''
        return str(self.value)

        
def third_largest(node):
    h = height(node)
    cur_node = node
    if h < 2:
        return None
    while(cur_node.right!= None):
        identifier_1 = (cur_node != None)
        identifier_2 = (cur_node.right != None)
        identifier_3 = (cur_node.right.right != None)
        identifier_4 = (cur_node.right.right.right == None)
        if(identifier_1 and identifier_2 and identifier_3 and identifier_4):
            return cur_node.value
        else:
            cur_node = cur_node.right
    
root = BST(1)
root.insert(-1)
root.insert(0)
root.insert(0.89)
root.insert(2)
root.insert(3)
root.insert(4)
root.insert(5)
root.insert(6)

print(third_largest(root))
