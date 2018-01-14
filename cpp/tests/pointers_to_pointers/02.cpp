struct list {
	int item;
	struct list *next;
};

int main() {
	struct list **lpp;
	int i = 0; //delete node containing i from list pointed to by lp
	for (lpp = &list; *lpp != NULL; lpp = &(*lpp)->next) {
		if ((*lpp)->item == i) {
			*lpp = (*lpp)->next;
			break;
		}
	}
	return 0;
}
