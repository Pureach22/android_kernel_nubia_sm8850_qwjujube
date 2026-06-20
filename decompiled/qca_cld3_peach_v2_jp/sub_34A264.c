void __usercall sub_34A264(atomic_uint *a1@<X8>)
{
  unsigned int v1; // w11
  unsigned int v2; // w12
  unsigned int v3; // w20
  unsigned int v4; // w22
  unsigned int v5; // w23
  unsigned int v6; // w24
  unsigned int v7; // w25
  unsigned int v8; // w26
  unsigned int v9; // w27
  unsigned int v10; // w28
  atomic_uint *StatusReg; // x9
  atomic_uint *v12; // x9
  atomic_uint *v13; // x9
  atomic_uint *v14; // x9
  atomic_uint *v15; // x9
  atomic_uint *v16; // x9
  atomic_uint *v17; // x9
  atomic_uint *v18; // x9
  atomic_uint *v19; // x9
  atomic_uint *v20; // x9
  atomic_uint *v21; // x9
  atomic_uint *v22; // x9
  atomic_uint *v23; // x9
  atomic_uint *v24; // x9
  atomic_uint *v25; // x9
  atomic_uint *v26; // x9
  atomic_uint *v27; // x9
  atomic_uint *v28; // x9
  atomic_uint *v29; // x9
  atomic_uint *v30; // x9
  atomic_uint *v31; // x9
  atomic_uint *v32; // x9
  atomic_uint *v33; // x9
  atomic_uint *v34; // x9
  atomic_uint *v35; // x9
  atomic_uint *v36; // x9
  atomic_uint *v37; // x9
  atomic_uint *v38; // x9
  atomic_uint *v39; // x9
  atomic_uint *v40; // x9
  atomic_uint *v41; // x9
  atomic_uint *v42; // x9
  atomic_uint *v43; // x9
  atomic_uint *v44; // x9
  atomic_uint *v45; // x9
  atomic_uint *v46; // x9

  StatusReg = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v10, memory_order_relaxed);
  atomic_fetch_add_explicit(StatusReg, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(StatusReg, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v12 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v9, memory_order_relaxed);
  atomic_fetch_add_explicit(v12, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v12, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v13 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v1, memory_order_relaxed);
  atomic_fetch_add_explicit(v13, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v13, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v14 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v9, memory_order_relaxed);
  atomic_fetch_add_explicit(v14, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v14, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v15 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v8, memory_order_relaxed);
  atomic_fetch_add_explicit(v15, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v15, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v15, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v15, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v16 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v5, memory_order_relaxed);
  atomic_fetch_add_explicit(v16, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v16, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v17 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v1, memory_order_relaxed);
  atomic_fetch_add_explicit(v17, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v17, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v18 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v10, memory_order_relaxed);
  atomic_fetch_add_explicit(v18, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v18, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v19 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v10, memory_order_relaxed);
  atomic_fetch_add_explicit(v19, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v19, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v20 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v7, memory_order_relaxed);
  atomic_fetch_add_explicit(v20, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v20, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v21 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v9, memory_order_relaxed);
  atomic_fetch_add_explicit(v21, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v21, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v22 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v2, memory_order_relaxed);
  atomic_fetch_add_explicit(v22, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v22, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v23 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v7, memory_order_relaxed);
  atomic_fetch_add_explicit(v23, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v23, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v23, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v23, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  _ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v4, memory_order_relaxed);
  v24 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v8, memory_order_relaxed);
  atomic_fetch_add_explicit(v24, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v24, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v25 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v10, memory_order_relaxed);
  atomic_fetch_add_explicit(v25, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v25, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v26 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v1, memory_order_relaxed);
  atomic_fetch_add_explicit(v26, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v27 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v9, memory_order_relaxed);
  atomic_fetch_add_explicit(v27, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v27, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v27, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v27, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v28 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v7, memory_order_relaxed);
  atomic_fetch_add_explicit(v28, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v28, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v29 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v1, memory_order_relaxed);
  atomic_fetch_add_explicit(v29, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v29, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v30 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v10, memory_order_relaxed);
  atomic_fetch_add_explicit(v30, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v30, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v31 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v10, memory_order_relaxed);
  atomic_fetch_add_explicit(v31, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v31, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v32 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v9, memory_order_relaxed);
  atomic_fetch_add_explicit(v32, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v32, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v33 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v9, memory_order_relaxed);
  atomic_fetch_add_explicit(v33, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v33, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v34 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v6, memory_order_relaxed);
  atomic_fetch_add_explicit(v34, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v34, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v35 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v6, memory_order_relaxed);
  atomic_fetch_add_explicit(v35, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v35, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v36 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v8, memory_order_relaxed);
  atomic_fetch_add_explicit(v36, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v36, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v37 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v3, memory_order_relaxed);
  atomic_fetch_add_explicit(v37, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v37, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v38 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v2, memory_order_relaxed);
  atomic_fetch_add_explicit(v38, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v38, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v39 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v8, memory_order_relaxed);
  atomic_fetch_add_explicit(v39, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v39, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v40 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v9, memory_order_relaxed);
  atomic_fetch_add_explicit(v40, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v40, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  _ReadStatusReg(CNTVCTSS_EL0);
  v41 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v5, memory_order_relaxed);
  atomic_fetch_add_explicit(v41, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v41, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  _ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v8, memory_order_relaxed);
  v42 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v2, memory_order_relaxed);
  atomic_fetch_add_explicit(v42, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v42, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v42, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v42, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v43 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v1, memory_order_relaxed);
  atomic_fetch_add_explicit(v43, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v43, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v44 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v1, memory_order_relaxed);
  atomic_fetch_add_explicit(v44, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v44, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v45 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v6, memory_order_relaxed);
  atomic_fetch_add_explicit(v45, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v45, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  v46 = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v10, memory_order_relaxed);
  atomic_fetch_add_explicit(v46, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(v46, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  JUMPOUT(0x342B20);
}
