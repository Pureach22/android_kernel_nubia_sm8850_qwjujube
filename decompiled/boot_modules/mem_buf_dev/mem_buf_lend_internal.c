__int64 __fastcall mem_buf_lend_internal(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 (*v4)(void); // x8
  __int64 v5; // x22
  unsigned int v7; // w21
  unsigned __int64 v8; // x19
  __int64 v9; // x19
  __int64 v10; // x2
  int v12; // w12
  __int64 v13; // x1
  __int64 v14; // x2
  void *v15; // x0
  int v16; // w8
  int v17; // w0
  unsigned int v18; // w20
  __int64 v19; // x1
  __int64 v20; // x2
  void *v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned int v24; // w0
  __int64 v25; // x2

  if ( !*a2 || !*((_QWORD *)a2 + 1) || !*((_QWORD *)a2 + 2) )
    return 4294967274LL;
  if ( !mem_buf_dev )
  {
    printk(&unk_13090, "mem_buf_lend_internal", a3);
    return 4294967277LL;
  }
  v3 = *(_QWORD *)(a1 + 32);
  if ( *(__int64 (__fastcall **)(__int64))(v3 + 8) != mem_buf_dma_buf_attach )
    goto LABEL_9;
  v4 = *(__int64 (**)(void))(v3 - 16);
  v5 = a1;
  v7 = a3;
  if ( *((_DWORD *)v4 - 1) != -1540668827 )
    __break(0x8228u);
  v8 = v4();
  a1 = v5;
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_9:
    v9 = a1;
    if ( (unsigned int)__ratelimit(&mem_buf_lend_internal__rs, "mem_buf_lend_internal") )
      printk(&unk_1322F, *(_QWORD *)(v9 + 32), v10);
    return 4294967274LL;
  }
  if ( *a2 )
  {
    v12 = 0;
    while ( *(_DWORD *)(*((_QWORD *)a2 + 1) + 4LL * v12) != current_vmid )
    {
      if ( *a2 == ++v12 )
        goto LABEL_17;
    }
    if ( v7 == 1 )
    {
      if ( (unsigned int)__ratelimit(&validate_lend_vmids__rs, "validate_lend_vmids") )
      {
        v15 = &unk_1326F;
        goto LABEL_24;
      }
      return 4294967274LL;
    }
  }
  else
  {
LABEL_17:
    if ( v7 == 2 )
    {
      if ( (unsigned int)__ratelimit(&validate_lend_vmids__rs_45, "validate_lend_vmids") )
      {
        v15 = &unk_1372D;
LABEL_24:
        printk(v15, v13, v14);
      }
      return 4294967274LL;
    }
  }
  mutex_lock(v8 + 88);
  v16 = *(_DWORD *)(v8 + 16);
  if ( (v16 & 8) != 0 )
  {
    if ( !(unsigned int)__ratelimit(&mem_buf_lend_internal__rs_36, "mem_buf_lend_internal") )
      goto LABEL_42;
    v21 = &unk_134BD;
LABEL_41:
    printk(v21, v19, v20);
    goto LABEL_42;
  }
  if ( (v16 & 1) != 0 )
  {
    if ( !(unsigned int)__ratelimit(&mem_buf_lend_internal__rs_38, "mem_buf_lend_internal") )
      goto LABEL_42;
    v21 = &unk_13BF3;
    goto LABEL_41;
  }
  if ( (v16 & 2) != 0 )
  {
    if ( !(unsigned int)__ratelimit(&mem_buf_lend_internal__rs_39, "mem_buf_lend_internal") )
      goto LABEL_42;
    v21 = &unk_134F2;
    goto LABEL_41;
  }
  if ( (v16 & 4) != 0 )
  {
    if ( !(unsigned int)__ratelimit(&mem_buf_lend_internal__rs_41, "mem_buf_lend_internal") )
      goto LABEL_42;
    v21 = &unk_135CC;
    goto LABEL_41;
  }
  if ( (validate_lend_mapcount(v8, a2) & 1) == 0 )
  {
LABEL_42:
    mutex_unlock(v8 + 88);
    return 4294967274LL;
  }
  dma_map_sgtable(mem_buf_dev, *(_QWORD *)(v8 + 64), 1, 0);
  dma_unmap_sg_attrs(mem_buf_dev, **(_QWORD **)(v8 + 64), *(unsigned int *)(*(_QWORD *)(v8 + 64) + 12LL), 1, 0);
  v17 = mem_buf_vmperm_resize(v8, *a2);
  if ( v17 )
  {
LABEL_31:
    v18 = v17;
    mutex_unlock(v8 + 88);
    return v18;
  }
  v17 = mem_buf_assign_mem(v7, *(_QWORD *)(v8 + 64), a2);
  if ( v17 )
  {
    if ( v17 == -99 )
    {
      kref_get(*(_QWORD *)(v8 + 160));
      v17 = -99;
      *(_DWORD *)(v8 + 16) |= 8u;
    }
    goto LABEL_31;
  }
  mem_buf_vmperm_update_state(v8, *((void **)a2 + 1));
  v22 = *(_QWORD *)(v8 + 160);
  *(_DWORD *)(v8 + 16) |= 2u;
  *(_DWORD *)(v8 + 80) = a2[6];
  kref_get(v22);
  mutex_unlock(v8 + 88);
  v23 = *(unsigned int *)(v8 + 80);
  if ( (_DWORD)v23 == -1 )
    return 0;
  v24 = xa_insert(v23, v8);
  if ( v24 )
  {
    v18 = v24;
    if ( (unsigned int)__ratelimit(&mem_buf_lend_internal__rs_42, "mem_buf_lend_internal") )
      printk(&unk_132B8, *(unsigned int *)(v8 + 80), v25);
    mem_buf_vmperm_try_reclaim(v8, 0);
    return v18;
  }
  mem_buf_lend_notify(v8);
  return 0;
}
