void bheap_insert(bheap *h, int priority, void(*node_operation)()) {
    node *tmp = (node *)malloc(sizeof(node));
    tmp->priority = priority;
    tmp->right = NULL;
    tmp->left = NULL;

    if(h->root_node == NULL){
        h->root_node = tmp;
        printf("test: %d", h->root_node->priority);
    }else{
        if(priority > (h->root_node)->priority){
            if((h->root_node)->left == NULL){
                bheap_insert((h->root_node)->left, priority, NULL);
            }else{
                bheap_insert((h->root_node)->right, priority, NULL);
            }
        }else if(priority <= (h->root_node)->priority){
            
            printf("h->root_node ---> %d \n", (h->root_node)->priority);
            printf("priority ---> %d \n", tmp->priority);

            tmp->priority = (h->root_node)->priority;
            (h->root_node)->priority = priority;
            bheap_insert((h->root_node), tmp->priority, NULL);
        }
    }

}