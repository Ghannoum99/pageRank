class Graphe:

    def __init__(self, liste_adjacence: dict = {}):
        self.liste_adjacence = liste_adjacence

    # Fonction permettant de calculer le nombre de sommets d'un graphe
    def get_nombre_sommet(self):
        return len(self.liste_adjacence.keys())

    # Fonction permettant de calculer le nombre d'aretes dans un graphe
    def get_nombre_aretes(self):
        aretes = 0
        for sommet in self.liste_adjacence.values():
            aretes += sum([len(sommet)])

        return aretes / 2

    # Fonction permettant de calculer le degré d'un graphe représenté par sa liste d'adjacence
    # ( somme de degrées de chaque sommet du graphe)
    def get_somme_degres(self, liste_adjacence):
        somme_degres = 0
        for sommet in liste_adjacence.values():
            somme_degres += sum([len(sommet)])

        return somme_degres

    # Fonction permettant d'initialiser la liste d'adjacence
    # Entrée : le nombre de sommet (n)
    # Cette fonction permet de créer une liste d'adjacence de n sommets
    # En premier temps chaque sommet est de degré 0
    # Elle sera utilisée dans la fonction de génération des graphes aléatoires
    def initialiser_liste_adjacence(self, nombre_sommet):
        liste_adjacence = {}
        for sommet in range(1, nombre_sommet + 1):
            liste_adjacence[sommet] = []

        return liste_adjacence

    # Fonction permettant d'afficher la liste d'adjacence de chaque sommet
    def afficher_graphe(self):
        for sommet, voisin in self.liste_adjacence.items():
            print("L(" + str(sommet) + ") = " + str(self.liste_adjacence[sommet]))

    # Fonction permettant de dessiner un graphe
    def dessiner_graphe(self):
        # creation d'un graphe G vide
        G = nx.DiGraph()

        for sommet in self.liste_adjacence.keys():
            # ajouter le sommet en cours au graphe G
            G.add_node(sommet)

            # parcourir la liste de voisins du sommet en cours
            for voisin in range(0, len(self.liste_adjacence[sommet])):
                # ajouter une arete (sommet,voisin)
                G.add_edge(sommet, self.liste_adjacence[sommet][voisin])

        # Positionner les nœuds en utilisant l'algorithme Fruchterman-Reingold force-directed.
        pos = nx.spring_layout(G)

        # dessiner les noeuds du graphe G
        nx.draw_networkx_nodes(G, pos)
        # dessiner les étiquettes des nœuds sur le graphe G.
        nx.draw_networkx_labels(G, pos)
        # dessiner les aretes du graphe G
        nx.draw_networkx_edges(G, pos, edge_color='r', arrows=False)
        # afficher le graphe
        plt.show()

    # Fonction permettant d'avoir la liste de voisins d'un sommet donné
    def get_voisins(self, sommet):
        return self.liste_adjacence[sommet]

    """
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %
    %   PREMIERE PARTIE : GENERER DES GRAPHES ALEATOIRES
    %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    """

    # Partie 1.1

    # Algorithme pour générer un graphe aléatoire
    def graphe_aleatoire(self, nombre_sommet):
        liste_adjacence = {}

        # Initialisation de la liste d'adjascence
        liste_adjacence = self.initialiser_liste_adjacence(nombre_sommet)

        for sommet in liste_adjacence.keys():

            # Mise à jour de la liste d'adjascence pour obtenir les mêmes
            # sommets dans la liste d'adjacence du sommet voisin et la liste d'adjascence du sommet en cours
            if sommet > 1:
                for voisin_possible in liste_adjacence.keys():
                    if sommet in liste_adjacence[voisin_possible]:
                        liste_adjacence[sommet].append(voisin_possible)

            # L'ajout aléatoire d'une arête dans le graphe
            for sommet_voisin in range(sommet + 1, len(liste_adjacence) + 1):
                if sommet_voisin not in liste_adjacence[sommet]:
                    probabilite = random.gauss(0, 2)
                    if (probabilite > 0) and (probabilite < 1):
                        # Il faut ajouter l'arete selon l'ordre
                        # premiere arete du sommet 1 c'est l'arete qui relie le sommet 1 et le sommet 2
                        liste_adjacence[sommet].append(sommet_voisin)

        return Graphe(liste_adjacence)
