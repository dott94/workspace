//import java.util.Scanner;

import java.io.*;
import java.util.*;
public class Graph implements GraphADT
{
	protected int maxSize;  //maximum number of vertices
	protected int gSize;    //current number of vertices
	protected UnorderedLinkedList[] graph; //array of references 
	                        //to create adjacency lists
	protected double[] [] weights;
	public Graph()
	//Default constructor
	//Postcondition: The graph size is set to 0, that is 
	//               gSize=0; maxSize = 100
	{
		maxSize = 100;
		gSize = 0;
		weights = new double[maxSize][maxSize];
		for (int i=0;i<maxSize;i++)
			for(int j=0;j<maxSize;j++)
				weights[i][j]=Integer.MAX_VALUE;
		graph = new UnorderedLinkedList[maxSize];
	    for (int i=0; i< maxSize; i++)
	    {
	    	graph[i]= new UnorderedLinkedList<Integer>();
	    }
	}
	public Graph(int size)
	//Default constructor
	//Postcondition: The graph size is set to 0, that is 
	//               gSize=0; maxSize = size
	{
		maxSize = size;
		gSize = 0;
		weights = new double[maxSize][maxSize]; 
		for (int i=0;i<maxSize;i++)
			for(int j=0;j<maxSize;j++)
				weights[i][j]=Integer.MAX_VALUE;
		graph = new UnorderedLinkedList[maxSize];
	    for (int i=0; i< maxSize; i++)
	    {
	    	graph[i]= new UnorderedLinkedList<Integer>();
	    }
	}
	public boolean isEmpty()
	   //Method to determine if the graph is empty.
	   //Postcondition: Returns true if the graph is empty;
	   //               otherwise, returns false.
	{
		return (gSize == 0);
	}
	public void createGraph()
	//Method to create the graph.
	//Postcondition: The graph is created using the 
	//adjacency list representation.
	{
		Scanner console = new Scanner (System.in);
		String fileName;
		if (gSize != 0)
			clearGraph();
		Scanner infile = null;
		try
		{
			System.out.print("Enter input file name: ");
			fileName = console.nextLine();
			System.out.println();
			infile = new Scanner (new FileReader(fileName));
		}
		catch (FileNotFoundException fnfe)
		{
			System.out.println (fnfe.toString());
			System.exit(0);
		}
		gSize = infile.nextInt(); //get the number of vertices
		int temp=0;
		for (int index = 0; index < gSize; index++)
		{
			int vertex = infile.nextInt();
			int adjacentVertex = infile.nextInt();
			//weights [vertex][adjacentVertex] = infile.nextInt();
			temp=infile.nextInt();
			weights [vertex][adjacentVertex] = temp;
			System.out.println("weights["+vertex+"]["+adjacentVertex+"]="+temp);
			while (true)
			{
				graph[vertex].insertLast(adjacentVertex);
				adjacentVertex = infile.nextInt();
				
				if (adjacentVertex==-999) break;
				temp=infile.nextInt();
				weights [vertex][adjacentVertex] = temp;
				System.out.println("weights["+vertex+"]["+adjacentVertex+"]="+temp);
			
			}  //end while	
		} //end for
	} //end createGraph
	public void clearGraph()
	//Method to clear the graph.
	//Postcondition: Graph is empty.
	{
		int index;
		for (index = 0; index<gSize; index++)
		{
			graph[index]=null;
		}
		gSize = 0;
	}
	
	public void printGraph()
	//Method to print the graph.
	//Postcondition: For each vertex, the vertex and the 
	//               vertices adjacent to the vertex are 
	//               output.
	{
		for (int index=0; index< gSize;index++)
		{
			System.out.print(index + " ");
			graph[index].print();
			System.out.println();
		}
		System.out.println();
	}
	private void dft(int v, boolean[] visited)
	//Method to perform a depth first traversal at a 
	//given vertex.
	//This method is used by the method, depthFirst Traversal
	//and the method dftAtVertex.
	//Postcondition: A depth first search starting at the 
	//               vertex v is performed.
	{ 
		visited[v] = true;
		System.out.print(" " + v + " "); //visit the vertex
		UnorderedLinkedList<Integer>.LinkedListIterator<Integer> graphIt
		                        = graph[v].iterator();
		while (graphIt.hasNext())
		{
			int w = graphIt.next();
			if (!visited[w])
				dft(w, visited);
		} //end while
	}   // end dft
	
	public void depthFirstTraversal()
	//Method to perform a depth first traversal of the 
	//entire graph.
	//Postcondition: The vertices of the graph in the depth 
	//               first traversal order are output
	{
		boolean[] visited; //array to keep track of the 
		                   //visited vertices
		visited = new boolean[gSize];
		for (int index=0; index<gSize; index++)
			visited[index] = false;
		for (int index = 0; index < gSize; index++) //for each 
	         //vertex that has not visited do a depth first traversal
		{
			if (!visited[index])
			{
				dft(index, visited);
			}
		}
	} //end depthFirstTraversal
	
	public void dftAtVertex (int vertex)
	//Method to perform a depth first traversal at a
	//given vertex.
	//Postcondition: The vertices of the graph in the depth
	//               first traversal order are output.
	{
		boolean[] visited;
		visited = new boolean [gSize];
		for (int index = 0; index < gSize; index++)
		{
			visited[index] = false;
		}
		dft(vertex, visited);
	} // end dftAtVertex
	
	public void breadthFirstTraversal()
	//Method to perform a breadth first traversal of the 
	//graph.
	//Postcondition: The vertices of the graph in the breadth
	//               first traversal order are output.
	{
		LinkedQueueClass<Integer> queue = 
				new LinkedQueueClass<Integer>();
		boolean[] visited;
		visited = new boolean[gSize];
		for (int ind = 0; ind < gSize; ind++)
		{
			visited[ind] = false; //initialize the array 
			     //visited to false
		}
		for (int index = 0; index < gSize; index++)
			if (!visited[index])
			{
				queue.addQueue(index);
				visited[index] = true;
				System.out.print(" " + index + " ");
				while (!queue.isEmptyQueue())
				{
					int u = queue.front();
					queue.deleteQueue();
					UnorderedLinkedList<Integer>.LinkedListIterator<Integer> graphIt
					  	= graph[u].iterator();
					while (graphIt.hasNext())
					{
						int w1 = graphIt.next();
						if (!visited[w1])
						{
							queue.addQueue(w1);
							visited[w1]=true;
							System.out.print(" " + w1 + " ");
						}
					} //end while
				}//end while
			}// end if
	}//end breadthFirstTraversal
}
