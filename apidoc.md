# PFC API DOC

## admittance matrix

### typedef

```c
pfc_adm_graph
	pfc_adm_node* a[MAX_N]
	size_t len
pfc_adm_node
	size_t nu
	pfc_adm_node* next
	double complex y
pfc_adm_matrix
	double complex y[PFC_MAX_N][PFC_MAX_N]
	size_t n
```

### func

`pfc_adm_matrix* pfc_mk_adm_matrix(pfc_adm_graph* g)`

`pfc_adm_graph* pfc_mk_adm_graph(void)`

`bool pfc_adm_graph_add(pfc_adm_graph* g, size_t ni, size_t nj, double complex y)`

`double complex pfc_adm_graph_get(pfc_adm_graph* g, size_t ni, size_t nj)`

## matrix handle

### typedef

```c
pfc_matrix_t
	double m[PFC_MAX_N][PFC_MAX_N]
	size_t len
```

### func

```c
pfc_matrix_t* inverse_matrix(pfc_matrix_t*);
void pfc_matrix_add(pfc_matrix_t* j, size_t r1, size_t r2, double k);
void pfc_matrix_swap(pfc_matrix_t* j, size_t r1, size_t r2);
void pfc_matrix_mult(pfc_matrix_t* j, size_t r, double k);
void pfc_matrix_set_e(pfc_matrix_t*);
void pfc_matrix_set_1(pfc_matrix_t* j, pfc_matrix_t* v_j, size_t r);
```

