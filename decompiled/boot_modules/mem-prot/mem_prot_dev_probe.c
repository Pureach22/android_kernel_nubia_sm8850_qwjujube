__int64 __fastcall mem_prot_dev_probe(__int64 a1)
{
  const char **v2; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  unsigned int v5; // w0
  __int64 result; // x0
  unsigned int v7; // w0
  unsigned int v8; // w20
  unsigned int v9; // w22
  __int64 v10; // x0
  char *v11; // x21
  __int64 v12; // x8
  const char *v13; // x8
  void *v14; // x2
  const char *v15; // x3
  _QWORD v16[11]; // [xsp+8h] [xbp-58h] BYREF

  v2 = (const char **)(a1 + 16);
  v16[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 760);
  memset(v16, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v3, "memory-region", 0, 0, 0, v16) || (v4 = v16[0]) == 0 )
  {
    result = dev_err_probe(v2, 4294967274LL, "Error reading \"memory-region\" from DT.\n");
    goto LABEL_25;
  }
  v5 = dma_set_mask(v2, -1);
  if ( v5 )
  {
    result = dev_err_probe(v2, v5, "dma_set_mask_and_coherent failed.");
    goto LABEL_25;
  }
  dma_set_coherent_mask(v2, -1);
  v7 = of_reserved_mem_device_init_by_idx(v2, *(_QWORD *)(a1 + 760), 0);
  if ( v7 )
  {
    v8 = v7;
    dev_err_probe(v2, v7, "Failed to initialize cma memory.\n");
LABEL_8:
    of_reserved_mem_device_release(v2);
    result = v8;
    goto LABEL_25;
  }
  if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,lcp-dare", 0) )
  {
    v9 = 4;
  }
  else if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,lcp-dae", 0) )
  {
    v9 = 3;
  }
  else
  {
    if ( !of_find_property(*(_QWORD *)(a1 + 760), "qcom,lcp-de", 0) )
    {
      dev_err(v2, "Invalid memory protection type specified in DT.\n");
      goto LABEL_27;
    }
    v9 = 2;
  }
  v10 = of_reserved_mem_lookup(v4);
  if ( !v10 )
  {
LABEL_27:
    v15 = *(const char **)(a1 + 128);
    if ( !v15 )
      v15 = *v2;
    v8 = -22;
    dev_err_probe(v2, 4294967274LL, "Failed to create pool for %s.\n", v15);
    goto LABEL_8;
  }
  v11 = (char *)&mem_prot_pools + 120 * v9;
  *((_DWORD *)v11 + 8) = v9;
  v12 = *(_QWORD *)(v10 + 32);
  v11[48] = 0;
  *((_QWORD *)v11 + 7) = v2;
  *((_QWORD *)v11 + 5) = v12;
  v13 = *(const char **)(a1 + 128);
  if ( !v13 )
    v13 = *v2;
  *((_QWORD *)v11 + 8) = v13;
  _mutex_init(v11 + 72, "&prot_pool->lock", &mem_prot_pool_create___key);
  if ( v11 )
  {
    mutex_lock(&debugfs_pool_mutex);
    v14 = debugfs_pool_list;
    if ( debugfs_pool_list == (_UNKNOWN *)v11
      || v11 == (char *)&debugfs_pool_list
      || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)debugfs_pool_list) != &debugfs_pool_list )
    {
      _list_add_valid_or_report((char *)&mem_prot_pools + 120 * v9, &debugfs_pool_list);
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)debugfs_pool_list) = v11;
      *(_QWORD *)v11 = v14;
      *((_QWORD *)v11 + 1) = &debugfs_pool_list;
      debugfs_pool_list = (_UNKNOWN *)((char *)&mem_prot_pools + 120 * v9);
    }
    mutex_unlock(&debugfs_pool_mutex);
  }
  result = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
