void ft_swap(t_stack **head, int abr) {
    t_stack *tmp1; // Pointeur vers le premier élément de la pile
    t_stack *tmp2; // Pointeur vers le deuxième élément de la pile

    tmp1 = *head; // Initialisation du pointeur sur le premier élément
    tmp2 = (*head)->next; // Initialisation du pointeur sur le deuxième élément
    tmp1->next = tmp2->next; // Le premier élément pointe maintenant sur le troisième
    tmp2->next = tmp1; // Inversion : le deuxième élément pointe sur le premier
    *head = tmp2; // Mise à jour du sommet de la pile pour qu'il pointe sur le nouvel élément de tête (anciennement deuxième)

    // Affichage de l'opération effectuée en fonction du paramètre abr
    if (abr == 1) ft_putstr_fd("sa\n", 1); // Opération swap sur la pile A
    if (abr == 2) ft_putstr_fd("sb\n", 1); // Opération swap sur la pile B
}
int ft_push(t_stack **a, t_stack **b, int ab) {
    t_stack *pushed; // Nouvel élément à pousser sur l'autre pile
    t_stack *tmp; // Pointeur temporaire pour le premier élément de la pile source

    tmp = *a; // Sauvegarde du sommet de la pile source
    pushed = ft_snew((*a)->argvalue); // Création d'un nouvel élément avec la valeur du sommet de la pile source
    if (!pushed) return (-1); // Gestion d'erreur si la création de l'élément échoue

    // Ajout de l'élément au sommet de la pile destination
    if (*b == NULL) *b = pushed; // Si la pile destination est vide
    else {
        pushed->next = *b; // Sinon, insertion au sommet
        *b = pushed;
    }

    *a = (*a)->next; // Déplacement du sommet de la pile source vers l'élément suivant
    free(tmp); // Libération de la mémoire de l'ancien sommet de la pile source

    // Affichage de l'opération effectuée
    if (ab == 1) ft_putstr_fd("pa\n", 1); // Push vers la pile A
    if (ab == 2) ft_putstr_fd("pb\n", 1); // Push vers la pile B

    return (0); // Succès de l'opération
}
void ft_rotate(t_stack **head, int abr) {
    t_stack *tail; // Pointeur pour parcourir jusqu'au dernier élément

    tail = *head; // Initialisation au sommet de la pile
    while (tail->next != NULL) tail = tail->next; // Parcours jusqu'au dernier élément
    tail->next = *head; // Le dernier élément pointe sur l'ancien premier
    *head = (*head)->next; // Le deuxième élément devient le nouveau sommet de la pile
    tail->next->next = NULL; // L'ancien premier élément est maintenant le dernier et ne pointe sur rien

    // Affichage de l'opération effectuée
    if (abr == 1) ft_putstr_fd("ra\n", 1); // Rotate sur la pile A
    if (abr == 2) ft_putstr_fd("rb\n", 1); // Rotate sur la pile B
}


void ft_rev_rotate(t_stack **head, int abr) {
    t_stack *tail; // Pointeur pour le dernier élément
    t_stack *futuretail; // Pointeur pour l'avant-dernier élément

    tail = *head;
    futuretail = NULL;
    while (tail->next != NULL) {
        futuretail = tail; // Sauvegarde de l'avant-dernier élément
        tail = tail->next; // Déplacement au dernier élément
    }
    futuretail->next = NULL; // L'avant-dernier élément devient le dernier
    tail->next = *head; // Le dernier élément
