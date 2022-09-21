import math
import random
# Lab 6

#
# We'll define a node of a binary tree and introduce some features of Python
# classes along the way


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
        a = Node(4)
        print(a) # prints 4
        '''
        return str(self.value)



a = BST(4)
a.insert(2)
a.insert(5)
a.insert(10)
a.insert(3)
a.insert(15)



# Problem 1
# Draw (manually) the binary tree rooted in a.

#         4
# 2              5
#     3                10
#                             15


# Problem 2
# Write code to find the height of a Binary Search Tree

def find_height(root):
    if root == None:
        return 0
    else:
        left_height = find_height(root.left)
        right_height = find_height(root.right)
        return max(left_height, right_height)+1


# a.insert(9)
# a.insert(8)
# a.insert(7)
print("height is",find_height(a))


# Problem 3

# Write code to print out the nodes of the BST using
# Breadth-First Search. How would you get the Breadth-First Traversal
# from the tree you've drawn?
# (Modify the BFS function from lecture for this problem)

def BFS_tree(node):
# The BF traversal of a tree prints nodes level-by-level
    if node == None:
        return -1
    q = [node]
    while (len(q) > 0):
        cur = q.pop(0)
        print(cur.value)
        if cur.left != None:
            q.append(cur.left)
        if cur.right != None:
            q.append(cur.right)



# Problem 4

# Empirically investigate the relationship between the number of nodes in the
# tree and the height of the tree when inserting nodes with values generated
# using random.random()


def make_random_tree(n_nodes):
    '''Make a tree with n_nodes nodes by inserting nodes with values
    drawn using random.random()
    '''
    n = n_nodes
    if(n < 1):
        return
    else:
        root = BST(random.random())
        n -= 1
        while(n > 0):
            root.insert(random.random())
            n -= 1
    return root


print(BFS_tree(make_random_tree(5)))


def height_random_tree(n_nodes):
    '''Generate a random tree with n_nodes nodes, and return its height'''
    return find_height(make_random_tree(n_nodes))

print("height of random tree is",height_random_tree(8))

def make_data(max_nodes):
    '''Make two lists representing the empirical relationship between
    the number of nodes in a random tree and the height of the tree.
    Generate N_TREES = 40 trees with each of
    n_nodes = 5, int(1.2*5), int(1.2^2*5), .....

    return n (a list of values of n_nodes) and h (a list of heights)

    '''
    N_TREES = 40
    n_nodes = 5
    a = 40
    n = []
    h = []
    while(a > 0):
        n.append(int(pow(1.2, 40-a)*5))
        a -= 1
    for i in range(len(n)):
        height = find_height(make_random_tree(n[i]))
        h.append(height)
    return n, h

make_data(10000)
n, h = make_data(10000)
import matplotlib.pyplot as plt
plt.scatter(n, h)
plt.show()
# plt.savefig("trees.png") can save the data to disk