import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BinTree {
public int nodeCountHelper(Node node, int k) {
        if (node == null) {return k;}
        k = 1;
        k += nodeCountHelper(node.left, 0);
        k += nodeCountHelper(node.right, 0);
        return k;
    }

    public void inOrder(Node node) {
        if (node == null) {return;}
        inOrder(node.left);
        System.out.printf("%d ", node.val);
        inOrder(node.right);
    }

    public void preOrder(Node node) {
        if (node == null) {return;}
        System.out.printf("%d ", node.val);
        preOrder(node.left);
        preOrder(node.right);
    }

    public void postOrder(Node node) {
        if (node == null) {return;}
        postOrder(node.left);
        postOrder(node.right);
        System.out.printf("%d ", node.val);
    }

    public Node getMinimumNode(Node node) {
        if (node == null) {return node;}
        Node left = node.left;
        while (left != null) {
            node = left;
        }
        return node;
    }

    public Node getMaximumNode(Node node) {
        if (node == null) {return node;}
        Node right = node.right;
        while (right != null) {
            node = right;
        }
        return node;
    }

    public int[] getLeafNodes(Node node) {
        List<Integer> leaves = new ArrayList<Integer>();
        getLeafNodesHelper(node, leaves);
        return leaves.stream().mapToInt(i -> i).toArray();
    }

    public void getLeafNodesHelper(Node node, List<Integer> results) {
        if (node == null) {return;}
        if (node.left == null && node.right == null) {
            results.add(node.val);
        } else {
            getLeafNodesHelper(node.left, results);
            getLeafNodesHelper(node.right, results);
        }
    }

    public int maxDepth(Node node) {
        if (node == null) return 0;
        int lDepth = maxDepth(node.left);
        int rDepth = maxDepth(node.right);
        return Math.max(lDepth, rDepth) + 1;
    }

    public int insertNode(Node root, Node inNode) {
        Node node = root;
        int v = inNode.val;
        while (true) {
            if (v < node.val) {
                if (node.left != null)
                    node = node.left;
                else {
                    node.left = inNode;
                    break;
                }
            }
            else if (v > node.val) {
                if (node.right != null)
                    node = node.right;
                else {
                    node.right = inNode;
                    break;
                }
            }
            else {
                System.out.println("Value already present");
                return -1;
            }
        }
        return 0;
    }

    public int[] findValuePath(Node root, int val) {
        int[] path = new int[maxDepth(root)];
        int k = 0;

        Node node = root;

        while (true) {
            // System.out.println(node.val);
            if (val < node.val) {
                if (node.left != null) {
                    node = node.left;
                    path[k++] = 1;
                }
                else {return null;}
            }
            else if (val > node.val) {
                if (node.right != null) {
                    node = node.right;
                    path[k++] = 2;
                }
                else {return null;}
            }
            else {return path;}
        }
    }

    public Node getNode(Node root, int val) {
        Node node = root;

        while (true) {
            // System.out.println(node.val);
            if (val < node.val) {
                if (node.left != null) {
                    node = node.left;
                }
                else {return null;}
            }
            else if (val > node.val) {
                if (node.right != null) {
                    node = node.right;
                }
                else {return null;}
            }
            else {return node;}
        }
    }
}
    public static void main(String[] args) {
        /*
                    10
                   /  \
                  8    12
                 /       \
                4         14
               / \         \
              2   5         15
             /               \
            1                 20
                                \
                                 31
        */

        Node root = new Node(41);

        Node node1 = new Node(20);
        Node node2 = new Node(52);
        Node node3 = new Node(19);
        Node node4 = new Node(2);
        Node node5 = new Node(1);
        Node node6 = new Node(54);
        Node node7 = new Node(25);
        Node node8 = new Node(22);
        Node node9 = new Node(23);
        Node node10 = new Node(24);
        Node node11 = new Node(30);
        Node node12 = new Node(32);
        Node node13 = new Node(55);
        Node node14 = new Node(60);
        Node node15 = new Node(71);
        Node node16 = new Node(57);
        Node node17 = new Node(21);

        root.insertNode(root, node1);
        root.insertNode(root, node2);
        root.insertNode(root, node3);
        root.insertNode(root, node4);
        root.insertNode(root, node5);
        root.insertNode(root, node6);
        root.insertNode(root, node7);
        root.insertNode(root, node8);
        root.insertNode(root, node9);
        root.insertNode(root, node10);
        root.insertNode(root, node11);
        root.insertNode(root, node12);
        root.insertNode(root, node13);
        root.insertNode(root, node14);
        root.insertNode(root, node15);
        root.insertNode(root, node16);
        root.insertNode(root, node17);

        int targetElement = 5;

        int[] pathToTarget = root.findValuePath(root, targetElement);
        System.out.println(Arrays.toString(pathToTarget));

        int[] leaves = new int[15];
        System.out.println(Arrays.toString(root.getLeafNodes(root)));

        // System.out.printf("Node Count: %d\n", root.nodeCount(root));
        // root.inOrder(root);
        // System.out.printf("\n");
        // root.preOrder(root);
        // System.out.printf("\n");

        // System.out.printf("\n%d\n", root.val);
        // root.removeNode(root, root.val);
        // root.inOrder(root);

        // System.out.printf("\n\n%d\n", node4.val);
        // root.removeNode(root, node4.val);
        // root.inOrder(root);

        // System.out.printf("\n\n%d\n", node3.val);
        // root.removeNode(root, node3.val);
        // root.inOrder(root);

        // System.out.printf("\n\n%d\n", node7.val);
        // root.removeNode(root, node7.val);

        root.inOrder(root);
        System.out.println();
        System.out.println(root.val);
        System.out.println();

        System.out.println("Removing Nodes now...");
        System.out.println(1);
        root.removeNode(root, 1);
        root.inOrder(root);
        System.out.println();

        System.out.println(2);
        root.removeNode(root, 2);
        root.inOrder(root);
        System.out.println();

        System.out.println(19);
        root.removeNode(root, 19);
        root.inOrder(root);
        System.out.println();

        System.out.println(20);
        root.removeNode(root, 20);
        root.inOrder(root);
        System.out.println();

        System.out.println(22);
        root.removeNode(root, 22);
        root.inOrder(root);
        System.out.println();

        System.out.println(23);
        root.removeNode(root, 23);
        root.inOrder(root);
        System.out.println();

        System.out.println(21);
        root.removeNode(root, 21);
        root.inOrder(root);
        System.out.println();

        System.out.println(30);
        root.removeNode(root, 30);
        root.inOrder(root);
        System.out.println();

        System.out.println(32);
        root.removeNode(root, 32);
        root.inOrder(root);
        System.out.println();

        System.out.println(24);
        root.removeNode(root, 24);
        root.inOrder(root);
        System.out.println();

        System.out.println(25);
        root.removeNode(root, 25);
        root.inOrder(root);
        System.out.println();

        System.out.println(2);
        root.removeNode(root, 2);
        root.inOrder(root);
        System.out.println();
    }
}

