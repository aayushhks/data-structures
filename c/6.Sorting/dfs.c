//
// Created by Aayush Kumar on 11/08/23.
//
def floor(arr, val):
low = 0
high = len(arr)
mid = 0

if val > arr[high-1]:
return high

while low <= high:
mid = low + (high - low) // 2
if arr[mid] == val:
return mid
if arr[mid] > val:
high = mid - 1
else:
low = mid + 1

return low

        def bin_search(arr, val):
low = 0
high = len(arr) - 1
mid = 0

while low <= high:
mid = low + (high - low) // 2
if arr[mid] < val:
low = mid + 1
elif arr[mid] > val:
high = mid - 1
else:
return mid

return -1

class Queue:
def init(self, queue=[]):
self.queue = queue
def show(self):
return self.queue
        def enqueue_node(self, nodes):
self.queue.extend(nodes)
def dequeue(self):
f = self.queue[0]
del self.queue[0]
return f

        class Stack:
def init(self, stack=[]):
self.stack = stack
def show(self):
return self.stack
        def push_nodes(self, node):
self.stack.append(node)
def pop(self):
t = self.stack.pop()
return t

        class Node:
def init(self, val):
self.children = []
self.val = val

def set_children(self, children):
self.children = [Node(i) for i in sorted(children)]

def insert_child(self, val):
node = self.search(self, val)
node_children = []
for child in node.children:
node_children.append(child.val)
if bin_search(node_children, val) == -1:
return 1 # Insertion failed, value already present

node.children.insert(floor(node_children), Node(val))
return 0

def search(self, val, root_node, kind="bfs"):
if kind not in ["bfs", "dfs"]:
return 2 # Not a valid search kind

        match kind:
case "bfs":
Q = Queue()
visited = []

Q.enqueue_node(root_node)
visited.append(root_node)

while 1:
v = Q.dequeue() # 1
if v == None: break
unvisited = v.children
visited.append(unvisited)
Q.enqueue_node(unvisited)
input()

case "dfs":
stack = Stack()
visited = []

visited.append(root_node)
unvisited = root_node.children
stack.push_nodes(unvisited)

def str(self):
return f"Node({self.val})"

def repr(self):
return f"Node({self.val})"


if name == "main":
root = Node(1)
root.set_children([2, 5, 7])
root.children[0].set_children([3, 4])
root.children[0].children[0].set_children([6])

root_node = root

Q = Queue()
visited = []

Q.enqueue_node([root])
visited.append(root)
print(visited)

v = Q.dequeue() # 1
unvisited = v.children
visited.extend(unvisited)
Q.enqueue_node(unvisited)

print(Q.show())

v = Q.dequeue() # 1
if v:
unvisited = v.children
visited.extend(unvisited)
Q.enqueue_node(unvisited)
print(Q.show())
else:
print("done, lol")