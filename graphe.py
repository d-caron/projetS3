import networkx as nx
from networkx.algorithms import tournament
import numpy as np
import matplotlib.pyplot as plt
import pylab

G = nx.DiGraph()

G.add_edges_from([4, 3], weight=5)
G.add_edges_from([2, 4], weight=5)
G.add_edges_from([2, 3], weight=5)
G.add_edges_from([1, 4], weight=6)
G.add_edges_from([1, 3], weight=6)
G.add_edges_from([1, 2], weight=4)
G.add_edges_from([0, 4], weight=6)
G.add_edges_from([0, 3], weight=7)
G.add_edges_from([0, 2], weight=6)
G.add_edges_from([0, 1], weight=5)


print(tournament.is_tournament(G))

edge_labels=dict([((u,v,),d['weight'])
                 for u,v,d in G.edges(data=True)])

pos=nx.circular_layout(G)

nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels)
nx.draw_networkx(G,pos, node_size=200)
pylab.show()
