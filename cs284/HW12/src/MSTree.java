import java.util.HashSet;
import java.util.Set;

public class MSTree extends Graph {
	protected int source;
	// protected double[] [] weights;
	protected int[] edges;
	protected double[] edgeWeights;
	protected Set<Integer> vNew;
	protected Set<Integer> v;
	protected Set<Pair> e;
	protected Set<Pair> eNew;

	private class Pair {
		public int u;
		public int w;
		public double weight;

		public boolean equals(Object o) {
			return (u == ((Pair) o).u && ((Pair) o).w == w)
					|| (w == ((Pair) o).u && ((Pair) o).w == u);

		}

		public int hashCode() {
			return u + w;
		}

		public String toString() {
			return "(" + u + "," + w + ") = " + weight;
		}
	}

	public MSTree()
	// Default constructor
	{
		super();
		// weights = new double[maxSize][maxSize];
		edges = new int[maxSize];
		edgeWeights = new double[maxSize];
		vNew = new HashSet();
		v = new HashSet();
		e = new HashSet();
		eNew = new HashSet();

	}

	public MSTree(int size)
	// Constructor with parameter

	{
		super(size);
		// weights = new double[maxSize][maxSize];
		vNew = new HashSet();
		v = new HashSet();
		e = new HashSet();
		eNew = new HashSet();

		edges = new int[maxSize];
		edgeWeights = new double[maxSize];
	}

	// public void setGraph(Graph graph)
	// {}
	public void createSpanningGraph() // ToDo
	// Method to create the graph and the weight matrix
	{
		// Graph gr= new Graph();
		this.createGraph();
	}

	public void minimalSpanning(int sVertex)
	// Method to create the edges of the minimal
	// spanning tree. The weight of the edges is also
	// saved in the array edgeWeights.
	{
		// ToDo

		for (int i = 0; i < edges.length; i++) {
			v.add((Integer) i);
		}
		vNew.add(sVertex);
		for (int i = 0; i < graph.length; i++) {
			LinkedListClass.LinkedListIterator it = graph[i].iterator();
			while (it.hasNext()) {
				Pair p = new Pair();
				p.u = i;
				p.w = (Integer) it.next();
				p.weight = weights[p.u][p.w];
				e.add(p);
			}
		}

		while (eNew.size() < v.size() - 1) {
			Pair smallestEdge = new Pair();
			smallestEdge.weight = Double.MAX_VALUE;
			for (Pair edge : e) {
				if (!eNew.contains(edge)
						&& ((vNew.contains(edge.u) && !vNew.contains(edge.w) || vNew
								.contains(edge.w) && !vNew.contains(edge.u)))) {
					if (edge.weight < smallestEdge.weight) {
						smallestEdge = edge;
					}
				}
			}

			eNew.add(smallestEdge);
			if (vNew.contains(smallestEdge.u)) {
				vNew.add(smallestEdge.w);
			} else {
				vNew.add(smallestEdge.u);
			}
		}
		for (Pair edge : eNew) {

			edges[edge.u] = edge.w;
			edgeWeights[edge.u] = edge.weight;

		}
	} // end minimalSpanning

	public void printTreeAndWeight()
	// Method to output the edges of the minimal spanning
	// tree and the weight of the minimal spanning tree

	{
		double treeWeight = 0;
		System.out.println("Source Vertex: " + source);
		System.out.println("Edges    Weight");
		for (Pair edge : eNew) {
			treeWeight = treeWeight + edge.weight;
			System.out.print("(" + edge.u + ", " + edge.w + ")     ");
			System.out.printf("%.2f \n", edge.weight);
		}
		System.out.println();
		System.out.print("Minimal Spanning Tree Weight: ");
		System.out.printf("%.2f \n", treeWeight);
	} // end printTreeAndWeight
		// ToDo main

	public static void main(String[] args) {
		MSTree mstree = new MSTree(7);
		mstree.createSpanningGraph();
		mstree.minimalSpanning(0);
		mstree.printTreeAndWeight();

	}
}
