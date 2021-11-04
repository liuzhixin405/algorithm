using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NoPowerGraph
{
    class Program
    {
        static void Main(string[] args)
        {
            CruNode node1 = new CruNode("A");
            CruNode node2 = new CruNode("B");
            CruNode node3 = new CruNode("C");
            CruNode node4 = new CruNode("D");

            Border border1 = new Border(node1, node3);
            Border border2 = new Border(node2, node4);

            CruNode []nodes ={node1,node2,node3,node4};
            Border []borders={border1,border2};
            Graph graph = new Graph(nodes, borders);

            graph.printAdjMat();
            Console.Read();

        }
    }
}
