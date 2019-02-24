# NOTE

## func call

```
mk_adm_graph
	adm_graph_add
		adm_graph_add_edge
solve
	mk_adm_matrix
	initial
	get_new_ef
	set_ub
	mk_jcb
	solve_func
		inverse_matrix
	get_dlt_ef_max
	cal_ss
	cal_sij
```

## initial

```flow
s=>start: Start
read_base=>operation: read_base
read_bus=>operation: read_bus
read_branch=>operation: read_branch
e=>end

s->read_base->read_bus->read_branch->e
```

