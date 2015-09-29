
public interface GraphADT 
{
	public boolean isEmpty();
	   //Method to determine if the graph is empty.
	   //Postcondition: Returns true if the graph is empty;
	   //               otherwise, returns false.
	public void createGraph();
	//Method to create the graph.
	//Postcondition: The graph is created using the 
	//adjacency list representation.
	public void clearGraph();
	//Method to clear the graph.
	//Postcondition: Graph is empty.
	public void printGraph();
	//Method to print the graph.
	//Postcondition: For each vertex, the vertex and the 
	//               vertices adjacent to the vertex are 
	//               output.
	public void depthFirstTraversal();
	//Method to perform a depth first traversal of the 
	//entire graph.
	//Postcondition: The vertices of the graph in the depth 
	//               first traversal order are output
	public void dftAtVertex (int vertex);
	//Method to perform a depth first traversal at a
	//given vertex.
	//Postcondition: The vertices of the graph in the depth
	//               first traversal order are output.
	public void breadthFirstTraversal();
	//Method to perform a breadth first traversal of the 
	//graph.
	//Postcondition: The vertices of the graph in the breadth
	//               first traversal order are output.
}
