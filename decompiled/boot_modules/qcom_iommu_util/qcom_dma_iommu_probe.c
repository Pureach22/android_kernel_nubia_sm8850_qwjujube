__int64 __fastcall qcom_dma_iommu_probe(__int64 a1)
{
  __int64 v1; // x19
  char v2; // w8
  __int64 result; // x0
  __int64 v5; // x8
  unsigned __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x21
  void *v11; // x0
  unsigned __int64 dir; // x0
  unsigned __int64 v13; // x2
  unsigned int v14; // w0
  unsigned int v15; // w20

  v1 = a1 + 16;
  _ReadStatusReg(SP_EL0);
  v2 = *(_BYTE *)(a1 + 860);
  qcom_dma_iommu_dev = a1 + 16;
  if ( (v2 & 0x20) != 0 )
  {
    dev_err(v1, "Cannot be dma-coherent\n");
LABEL_13:
    result = 4294967274LL;
    goto LABEL_14;
  }
  result = of_reserved_mem_device_init_by_idx(a1 + 16, *(_QWORD *)(a1 + 760), 0);
  if ( (_DWORD)result )
    goto LABEL_14;
  qcom_dma_contiguous_default_area = *(_QWORD *)(a1 + 720);
  if ( !qcom_dma_contiguous_default_area )
  {
    dev_err(v1, "Unable to find cma area\n");
    goto LABEL_13;
  }
  v5 = totalram_pages >> 13;
  if ( totalram_pages >> 13 >= 0x400u )
    v5 = 1024;
  v6 = v5 << 12;
  atomic_pool_work = 0xFFFFFFFE00000LL;
  if ( v6 <= 0x20000 )
    v7 = 0x20000;
  else
    v7 = v6;
  atomic_pool_size = v7;
  qword_11EF0 = (__int64)&qword_11EF0;
  qword_11EF8 = (__int64)&qword_11EF0;
  qword_11F00 = (__int64)atomic_pool_work_fn;
  v8 = gen_pool_create(12, 0xFFFFFFFFLL);
  if ( v8 )
  {
    v9 = v8;
    gen_pool_set_algo(v8, &gen_pool_first_fit_order_align, 0);
    v10 = v9;
    if ( (unsigned int)atomic_pool_expand(v9, v7, 3264) )
    {
      gen_pool_destroy(v9);
      v10 = 0;
      v11 = &unk_118DA;
    }
    else
    {
      gen_pool_size(v9);
      v11 = &unk_11C47;
    }
    printk(v11);
    atomic_pool = v10;
    if ( v10 )
    {
      dir = debugfs_create_dir("qcom_dma_pools", 0);
      if ( dir )
      {
        v13 = dir;
        if ( dir <= 0xFFFFFFFFFFFFF000LL )
          debugfs_create_ulong("pool_size", 256, dir, &current_pool_size);
      }
      v14 = dma_set_mask(v1, -1, v13);
      if ( v14 )
      {
        v15 = v14;
        qcom_dma_atomic_pool_exit(v1);
        result = v15;
      }
      else
      {
        dma_set_coherent_mask(v1, -1);
        result = 0;
        probe_finished = 1;
      }
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967284LL;
    atomic_pool = 0;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
