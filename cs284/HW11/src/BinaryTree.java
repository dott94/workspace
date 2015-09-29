import java.util.NoSuchElementException;

public abstract class BinaryTree<T> implements BinaryTreeADT<T> {
	// Definition of the class implementing binary nodes
	protected class BinaryTreeNode<T> {
		public T info;
		public BinaryTreeNode<T> lLink;
		public BinaryTreeNode<T> rLink;

		// Default constructor
		// Postcondition: info = null; lLink = null; rLink = null;
		public BinaryTreeNode() {
			info = null;
			lLink = null;
			rLink = null;
		}

		// Constructor with parameters
		// Sets info to point to the object elem points to and
		// lLink and rLink are set to point to the objects left
		// and right, respectively.
		// Postcondition: info = elem; lLink = left;
		// rLink = right;
		public BinaryTreeNode(T elem, BinaryTreeNode<T> left,
				BinaryTreeNode<T> right) {
			info = elem;
			lLink = left;
			rLink = right;
		}

		// Returns a clone of this binary tree.
		// This method clones only the references stored in the
		// nodes of the binary tree. The objects that binary tree
		// nodes point to are not cloned.
		public Object clone() {
			BinaryTreeNode<T> copy = null;

			try {
				copy = (BinaryTreeNode<T>) super.clone();

			} catch (CloneNotSupportedException e) {
				return null;
			}

			return copy;
		}

		// Method to return the info as a string.
		// Postcondition: info as a String object is returned.
		public String toString() {
			return info.toString();
		}
	}

	protected BinaryTreeNode<T> root;

	// Default constructor
	// Postcondition: root = null;
	public BinaryTree() {
		root = null;
	}

	// Returns a clone of this binary tree.
	// This method clones only the references stored in the nodes
	// of the binary tree. The objects that binary tree nodes
	// point to are not cloned.
	public Object clone() {
		BinaryTree<T> copy = null;

		try {
			copy = (BinaryTree<T>) super.clone();

		} catch (CloneNotSupportedException e) {
			return null;
		}

		if (root != null)
			copy.root = copyTree(root);

		return copy;
	}

	// Method to determine whether the binary tree is empty.
	// Postcondition: Returns true if the binary tree is
	// empty; otherwise, returns false.
	public boolean isEmpty() {
		return (root == null);
	}

	// Method to do an inorder traversal of the binary tree.
	// Postcondition: The nodes of the binary tree are output
	// in the inorder sequence.
	public void inorderTraversal() {
		inorder(root);
	}

	// Method to do a preorder traversal of the binary tree.
	// Postcondition: The nodes of the binary tree are output
	// in the preorder sequence.
	public void preorderTraversal() {
		preorder(root);
	}

	// Method to do a postorder traversal of the binary tree.
	// Postcondition: The nodes of the binary tree are output
	// in the postorder sequence.
	public void postorderTraversal() {
		postorder(root);
	}

	// Method to determine the height of the binary tree.
	// Postcondition: The height of the binary tree is
	// returned.
	public int treeHeight() {
		return height(root);
	}

	// Method to determine the number of nodes in the
	// binary tree.
	// Postcondition: The number of nodes in the binary tree
	// is returned.
	public int treeNodeCount() {
		return nodeCount(root);
	}

	// Method to determine the number of leaves in the
	// binary tree.
	// Postcondition: The number of leaves in the binary tree
	// is returned.
	public int treeLeavesCount() {
		return leavesCount(root);
	}

	// Method to destroy the binary tree.
	// Postcondition: root = null
	public void destroyTree() {
		root = null;
	}

	// Method to determine whether searchItem is in the binary
	// tree.
	// Postcondition: Returns true if searchItem is found
	// in the binary tree;
	// otherwise, returns false.
	public abstract boolean search(T searchItem);

	// Method to insert insertItem in the binary tree.
	// Postcondition: If no node in the binary tree has the same
	// info as insertItem, a node with the info
	// insertItem is created and inserted
	// in the binary tree.
	public abstract void insert(T insertItem);

	// Method to delete deleteItem from the binary tree.
	// Postcondition: If a node with the same info as
	// deleteItem is found, it is deleted
	// from the binary tree.
	public abstract void deleteNode(T deleteItem);

	// Method to do an inorder traversal of the binary
	// tree to which p points.
	// Postcondition: The nodes of the binary tree to which p
	// points are output in the inorder
	// sequence.
	private void inorder(BinaryTreeNode<T> p) {
		if (p != null) {
			inorder(p.lLink);
			System.out.print(p.info + " ");
			inorder(p.rLink);
		}
	}

	// Method to do a preorder traversal of the binary
	// tree to which p points.
	// Postcondition: The nodes of the binary tree to which p
	// points are output in the preorder
	// sequence.
	private void preorder(BinaryTreeNode<T> p) {
		if (p != null) {
			System.out.print(p.info + " ");
			preorder(p.lLink);
			preorder(p.rLink);
		}
	}

	// Method to do a postorder traversal of the binary
	// tree to which p points.
	// Postcondition: The nodes of the binary tree to which p
	// points are output in the postorder
	// sequence.
	private void postorder(BinaryTreeNode<T> p) {
		if (p != null) {
			postorder(p.lLink);
			postorder(p.rLink);
			System.out.print(p.info + " ");
		}
	}

	// Method to determine the height of the binary tree
	// to which p points.
	// Postcondition: The height of the binary tree to
	// which p points is returned.
	private int height(BinaryTreeNode<T> p) {
		if (p == null)
			return 0;
		else
			return 1 + Math.max(height(p.lLink), height(p.rLink));
	}

	// Method to determine the number of nodes in the binary
	// tree to which p points.
	// Postcondition: The number of nodes in the binary tree
	// to which p points is returned.
	private int nodeCount(BinaryTreeNode<T> p) {
		// System.out.println("ToDo nodeCount");
		// ToDo
		if (p == null) {
			return 0;
		} else {
			return 1 + nodeCount(p.lLink) + nodeCount(p.rLink);
		}

	}

	// Method to determine the number of leaves in the binary
	// tree to which p points.
	// Postcondition: The number of leaves in the binary tree
	// to which p points is returned.
	private int leavesCount(BinaryTreeNode<T> p) {
		// System.out.println("ToDo leavesCount");
		// ToDo
		if (p == null) {
			return 0;
		} else if (p.lLink == null && p.rLink == null) {
			return 1;
		} else {
			return leavesCount(p.lLink) + leavesCount(p.rLink);
		}

	}

	// Method to make a copy of the binary tree to which
	// otherTreeRoot points.
	// Postcondition: A copy of the binary tree to which
	// otherTreeRoot is created and the reference of
	// the root node of the copied binary tree
	// is returned.
	private BinaryTreeNode<T> copyTree(BinaryTreeNode<T> otherTreeRoot) {
		BinaryTreeNode<T> temp;

		if (otherTreeRoot == null)
			temp = null;
		else {
			temp = (BinaryTreeNode<T>) otherTreeRoot.clone();
			temp.lLink = copyTree(otherTreeRoot.lLink);
			temp.rLink = copyTree(otherTreeRoot.rLink);
		}

		return temp;
	}// end copyTree

	public int singleParent() {
		return singleP(root);
	}

	private int singleP(BinaryTreeNode<T> p) {
		// System.out.println("ToDo singleP");
		// ToDo
		if (p == null) {

			return 0;
		} else if ((p.lLink == null && p.rLink != null)
				|| (p.lLink != null && p.rLink == null)) {

			return 1 + singleP(p.lLink) + singleP(p.rLink);
		} else {

			return singleP(p.lLink) + singleP(p.rLink);
		}

	}
}