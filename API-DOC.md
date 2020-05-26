# PFC API DOC

## global

### type

#### `pfc_sysinfo`

```c
struct pfc_sysinfo {
	double b;	// System base(MVA)
	size_t all;	// Nomber of all buses
	size_t br;	// Nomber of branches
	size_t pq;	// Nomber of PQ buses
};
```

## initial

### type

#### `pfc_bus`

```c
struct pfc_bus {
	size_t no;  // No.
	unsigned char type; /*  1 - Load bus (no generation)
		2 - Generator or plant bus
		3 - Swing bus
		4 - Islolated bus
		*/
	double pl;  // load MW
	double ql;  // load MVAR
	double pg;  // Generation MW
	double qg;  // Generation MVAR
	double v;   // Voltage magnitude, per unit
	double va;  // Voltage angle, degrees
	double bv;  // Base voltage, KV
};
```

#### `pfc_branch`

```c
struct pfc_branch {
	size_t from;
	size_t to;
	double r;
	double x;
	double b;
};
```

### func

#### `pfc_read_base(pfc_sysinfo* sysinfo, FILE* f)`

Read system information from input file, store them in `sysinfo`.

#### `pfc_read_bus(pfc_bus* bs[], pfc_sysinfo* sysinfo, FILE* f)`

Read bus info.

#### `pfc_read_branch(pfc_branch* branch[], pfc_sysinfo* sysinfo, FILE* f)`

Read branch info.

## admittance matrix

### type

#### `pfc_adm_matrix`

`double complex[PFC_MAX_N][PFC_MAX_N]`

### func

#### `pfc_adm_matrix* pfc_mk_adm_matrix(pfc_branch* br[PFC_MAX_BRANCH], pfc_sysinfo* sys, pfc_bus* bs[PFC_MAX_N]);`

Make admittance matrix, in bus data order.

#### `double complex pfc_adm_get_y(pfc_adm_matrix* adm, int i, int j)`

#### `double pfc_adm_get_b(pfc_adm_matrix* adm, int i, int j)`

#### `double pfc_adm_get_g(pfc_adm_matrix* adm, int i, int j)`

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