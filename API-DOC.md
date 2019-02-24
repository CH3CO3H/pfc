# PFC API DOC

## initial

### type

- `pfc_bus`
- `pfc_sysinfo`

### func

`pfc_read_base(pfc_sysinfo* sysinfo, FILE* f)`

`pfc_read_bus(pfc_bus* bs[], pfc_sysinfo* sysinfo, FILE* f)`

`pfc_read_branch(pfc_branch* branch[], pfc_sysinfo* sysinfo, FILE* f)`

## admittance matrix

### type

- `pfc_adm_graph`
- `pfc_adm_node`
- `pfc_adm_matrix`

### func

#### `pfc_adm_matrix* pfc_mk_adm_matrix(pfc_adm_graph* g)`

make admittance matrix from admittance graph.

#### `pfc_adm_graph* pfc_mk_adm_graph(FILE* f)`

make admittance graph from input file

#### `bool pfc_adm_graph_add(pfc_adm_graph* g, size_t ni, size_t nj, double complex y)`

#### `double complex pfc_adm_graph_get(pfc_adm_graph* g, size_t ni, size_t nj)`

## matrix handle

### type

- `pfc_matrix`

### func

#### `pfc_matrix* inverse_matrix(pfc_matrix*)`

inverse a matrix and return it

#### `void pfc_matrix_add(pfc_matrix* j, size_t r1, size_t r2, double k)`
#### `void pfc_matrix_swap(pfc_matrix* j, size_t r1, size_t r2)`
#### `void pfc_matrix_row_mult(pfc_matrix* j, size_t r, double k)`
#### `void pfc_matrix_set_e(pfc_matrix*)`
#### `void pfc_matrix_set_1(pfc_matrix* j, pfc_matrix* v_j, size_t r)`

## solve

### type

- `pfc_vector`

### func

#### `pfc_initial(pfc_vector** pq, pfc_vector** ef, FILE* f)`

#### `void pfc_set_ub(pfc_vector* pq, pfc_vector* ub, pfc_vector* ef,pfc_adm_matrix* adm)`

#### `pfc_matrix* pfc_mk_jcb(pfc_adm_matrix* adm, pfc_vector* ef)`

#### `void pfc_solve_func(pfc_vector* ub, pfc_matrix* jcb, pfc_vector* dlt_ef)`

#### `double pfc_get_dlt_ef_max(pfc_vector* dlt_ef)`

#### `void pfc_get_new_ef(pfc_vector* ef, pfc_vector* dlt_ef)`

#### `double complex pfc_cal_ss(pfc_adm_matrix*, pfc_vector* ef)`

#### `void pfc_cal_sij(pfc_adm_matrix* adm, pfc_vector* ef, double complex s_ij[][])`

#### `void pfc_save_rlt(pfc_vector* ef, double complex s_s, double complex s_ij[][])`

#### `double pfc_get_e(pfc_vector* ef, size_t i)`

#### `double pfc_get_p(size_t i, pfc_vector*)`