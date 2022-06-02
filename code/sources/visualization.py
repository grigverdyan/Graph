import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

# get matrix from input file
matrix = np.loadtxt("data/out.txt")

G = nx.from_numpy_matrix(np.array(matrix))  
node_size = 1600
node_alpha = 0.5
graph_pos = nx.spring_layout(G)
node_color = 'blue'
edge_color = 'magenta'
edge_tickness = 1
edge_alpha = 0.3
text_font = 'sans-serif'
node_text_size=12

nx.draw_networkx_nodes(G, graph_pos, node_size=node_size, alpha=node_alpha, node_color=node_color)
nx.draw_networkx_edges(G, graph_pos, width=edge_tickness, alpha=edge_alpha,edge_color=edge_color)
nx.draw_networkx_labels(G, graph_pos,font_size=node_text_size, font_family=text_font)

# draw graph 
plt.show()

plt.rcParams["figure.figsize"] = [7.50, 3.50]
plt.rcParams["figure.autolayout"] = True

fig, ax = plt.subplots()
ax.matshow(matrix, cmap='ocean')

rows = len(matrix)
columns = len(matrix[0])
for i in range(rows):
   for j in range(columns):
      c = matrix[j, i]
      ax.text(i, j, str(c), va='center', ha='center')

# draw adjacency matrix
plt.show()
