__int64 __fastcall ipahal_fltrt_allocate_hw_sys_tbl(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  int v3; // w8
  __int64 v4; // x9
  unsigned int v5; // w20
  char *v6; // x21
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipahal_fltrt_allocate_hw_sys_tbl", 5273);
  }
  if ( !a1 )
  {
    printk(&unk_3EB3A3, "ipahal_fltrt_allocate_hw_sys_tbl");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d Input err\n", "ipahal_fltrt_allocate_hw_sys_tbl", 5276);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v12, "ipahal %s:%d Input err\n", "ipahal_fltrt_allocate_hw_sys_tbl", 5276);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v3 = *(_DWORD *)(a1 + 16);
  if ( !v3 )
  {
    printk(&unk_3FD07B, "ipahal_fltrt_allocate_hw_sys_tbl");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipahal %s:%d Input err: zero table size\n", "ipahal_fltrt_allocate_hw_sys_tbl", 5281);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipahal %s:%d Input err: zero table size\n", "ipahal_fltrt_allocate_hw_sys_tbl", 5281);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v4 = ipahal_ctx;
  v5 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Bu )
  {
LABEL_34:
    __break(0x5512u);
    JUMPOUT(0x18AE90);
  }
  if ( ((152LL * v5) | 4uLL) > 0xF70 )
  {
LABEL_33:
    __break(1u);
    goto LABEL_34;
  }
  v6 = (char *)&ipahal_fltrt_objs + 152 * v5;
  v7 = (unsigned int)(*((_DWORD *)v6 + 1) + v3);
  *(_DWORD *)(a1 + 16) = v7;
  v8 = dma_alloc_attrs(*(_QWORD *)(v4 + 32), v7, a1 + 8, 3264, 0);
  *(_QWORD *)a1 = v8;
  if ( v8
    || (v9 = dma_alloc_attrs(*(_QWORD *)(ipahal_ctx + 32), *(unsigned int *)(a1 + 16), a1 + 8, 2080, 0),
        (*(_QWORD *)a1 = v9) != 0) )
  {
    if ( v5 != 26 )
    {
      if ( (*(_QWORD *)(a1 + 8) & *((unsigned int *)v6 + 2)) != 0 )
      {
        printk(&unk_3BA229, "ipahal_fltrt_allocate_hw_sys_tbl");
        if ( ipa3_get_ipc_logbuf() )
        {
          v15 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v15,
            "ipahal %s:%d sys rt tbl address is not aligned\n",
            "ipahal_fltrt_allocate_hw_sys_tbl",
            5302);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v16 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v16,
            "ipahal %s:%d sys rt tbl address is not aligned\n",
            "ipahal_fltrt_allocate_hw_sys_tbl",
            5302);
        }
        ipahal_free_dma_mem(a1);
        return 0xFFFFFFFFLL;
      }
      else
      {
        memset(*(void **)a1, 0, *(unsigned int *)(a1 + 16));
        return 0;
      }
    }
    goto LABEL_33;
  }
  printk(&unk_3BFB74, "ipahal_fltrt_allocate_hw_sys_tbl");
  if ( ipa3_get_ipc_logbuf() )
  {
    v17 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v17,
      "ipahal %s:%d fail to alloc DMA buf of size %d\n",
      "ipahal_fltrt_allocate_hw_sys_tbl",
      5298,
      *(_DWORD *)(a1 + 16));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v18 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v18,
      "ipahal %s:%d fail to alloc DMA buf of size %d\n",
      "ipahal_fltrt_allocate_hw_sys_tbl",
      5298,
      *(_DWORD *)(a1 + 16));
  }
  return 4294967284LL;
}
