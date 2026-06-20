__int64 secure_system_heap_prefetch_work()
{
  _UNKNOWN **v0; // x24
  __int64 v1; // x9
  _QWORD *v2; // x20
  _QWORD *v3; // x26
  _QWORD *v4; // x8
  _QWORD *v5; // t2
  int v6; // w21
  __int64 **drvdata; // x0
  __int64 **v8; // x27
  __int64 v9; // x22
  unsigned __int64 v10; // x25
  _UNKNOWN **v11; // x21
  __int64 v12; // x24
  __int64 v13; // x0
  __int64 v14; // x1
  unsigned int v15; // w22
  unsigned int v16; // w2
  unsigned __int64 v17; // x28
  __int64 v18; // x0
  _QWORD *v19; // x1
  _QWORD **v20; // x8
  char v21; // w8
  _QWORD *v22; // x9
  __int64 v23; // x0
  unsigned __int64 v24; // x28
  int v25; // w0
  _QWORD *v26; // x22
  __int64 v27; // x0
  unsigned __int64 v28; // x8
  char v29; // w9
  __int64 v30; // x10
  __int64 v31; // x21
  __int64 dev; // x0
  __int64 v33; // x0
  _QWORD *v34; // x8
  int v35; // w0
  __int64 v36; // x2
  __int64 v37; // x3
  __int64 v38; // x4
  int v39; // w8
  _QWORD *v40; // x21
  unsigned int v41; // w22
  __int64 v42; // x1
  _QWORD *v43; // x21
  __int64 v44; // x1
  unsigned __int64 v45; // x0
  _QWORD *v46; // x21
  unsigned int v47; // w22
  __int64 v48; // x8
  unsigned __int64 v49; // x1
  int v50; // w22
  __int64 result; // x0
  __int64 v52; // [xsp+10h] [xbp-20h]
  _QWORD *v53; // [xsp+18h] [xbp-18h] BYREF
  _QWORD **v54; // [xsp+20h] [xbp-10h]
  __int64 v55; // [xsp+28h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = &prefetch_list;
  v1 = raw_spin_lock_irqsave(&work_lock);
  v2 = prefetch_list;
  if ( prefetch_list == (_UNKNOWN *)&prefetch_list )
  {
LABEL_69:
    result = raw_spin_unlock_irqrestore(&work_lock, v1);
    _ReadStatusReg(SP_EL0);
    return result;
  }
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v3 = v2;
    v5 = v2;
    v2 = (_QWORD *)*v2;
    v4 = (_QWORD *)v5[1];
    if ( (_QWORD *)*v4 == v3 && (_QWORD *)v2[1] == v3 )
    {
      v2[1] = v4;
      *v4 = v2;
    }
    else
    {
      _list_del_entry_valid_or_report(v3);
    }
    *v3 = 0xDEAD000000000100LL;
    v3[1] = 0xDEAD000000000122LL;
    raw_spin_unlock_irqrestore(&work_lock, v1);
    v6 = *((unsigned __int8 *)v3 + 32);
    drvdata = (__int64 **)dma_heap_get_drvdata(v3[2]);
    v8 = drvdata;
    if ( v6 != 1 )
      break;
    dynamic_page_pool_shrink_high_and_low(*drvdata, 3, v3[3] >> 12);
LABEL_4:
    kfree(v3);
    v1 = raw_spin_lock_irqsave(&work_lock);
    if ( v2 == v0 )
      goto LABEL_69;
  }
  v9 = v3[2];
  v10 = v3[3];
  v11 = v0;
  v12 = get_sys_heap_page_pool_qcom_sys_heap_pools;
  v53 = &v53;
  v54 = &v53;
  if ( get_sys_heap_page_pool_qcom_sys_heap_pools )
    goto LABEL_12;
  v13 = dma_heap_find("qcom,system");
  if ( v13 )
  {
    v12 = *(_QWORD *)(dma_heap_get_drvdata(v13) + 8);
    get_sys_heap_page_pool_qcom_sys_heap_pools = v12;
    if ( v12 )
      goto LABEL_12;
    goto LABEL_68;
  }
  printk(&unk_DA0D, v14);
  v12 = get_sys_heap_page_pool_qcom_sys_heap_pools;
  if ( !get_sys_heap_page_pool_qcom_sys_heap_pools )
  {
LABEL_68:
    printk(&unk_DCDB, "get_pages");
    v0 = v11;
    goto LABEL_4;
  }
LABEL_12:
  v52 = v9;
  v15 = 0;
  if ( v10 )
  {
    v16 = 9;
    v17 = v10;
    do
    {
      v18 = qcom_sys_heap_alloc_largest_available(v12, v17, v16, 0);
      if ( !v18 )
      {
        printk(&unk_E106, "get_pages");
        v24 = -12;
        v0 = v11;
        goto LABEL_37;
      }
      v19 = v54;
      v20 = (_QWORD **)(v18 + 8);
      if ( (_QWORD **)(v18 + 8) == &v53 || v54 == v20 || *v54 != &v53 )
      {
        _list_add_valid_or_report(v18 + 8);
        v18 = (__int64)v22;
        if ( (*v22 & 0x40) == 0 )
        {
LABEL_21:
          v21 = 0;
          if ( (*(_QWORD *)v18 & 0x40) != 0 )
            goto LABEL_25;
          goto LABEL_14;
        }
      }
      else
      {
        v54 = (_QWORD **)(v18 + 8);
        *(_QWORD *)(v18 + 8) = &v53;
        *(_QWORD *)(v18 + 16) = v19;
        *v19 = v20;
        if ( (*(_QWORD *)v18 & 0x40) == 0 )
          goto LABEL_21;
      }
      v21 = *(_BYTE *)(v18 + 64);
      if ( (*(_QWORD *)v18 & 0x40) != 0 )
      {
LABEL_25:
        v16 = *(unsigned __int8 *)(v18 + 64);
        goto LABEL_15;
      }
LABEL_14:
      v16 = 0;
LABEL_15:
      ++v15;
      v17 += -4096LL << v21;
    }
    while ( v17 );
  }
  v23 = _kmalloc_cache_noprof(of_find_property, 3520, 16);
  v24 = v23;
  v0 = v11;
  if ( !v23 )
  {
    v24 = -12;
LABEL_37:
    v34 = v53;
    if ( v53 != &v53 )
    {
      do
      {
        v43 = (_QWORD *)*v34;
        if ( (*(v34 - 1) & 0x40) != 0 )
          v42 = *((unsigned __int8 *)v34 + 56);
        else
          v42 = 0;
        _free_pages(v34 - 1, v42);
        v34 = v43;
      }
      while ( v43 != &v53 );
    }
    goto LABEL_38;
  }
  v25 = sg_alloc_table(v23, v15, 3264);
  if ( v25 )
  {
    v50 = v25;
    printk(&unk_DC2C, "get_pages");
    kfree(v24);
    v24 = v50;
    goto LABEL_37;
  }
  v26 = v53;
  if ( v53 == &v53 )
  {
LABEL_35:
    v31 = v52;
    dev = dma_heap_get_dev(v52);
    dma_map_sgtable(dev, v24, 0, 0);
    v33 = dma_heap_get_dev(v31);
    dma_unmap_sg_attrs(v33, *(_QWORD *)v24, *(unsigned int *)(v24 + 12), 0, 0);
LABEL_38:
    if ( v24 <= 0xFFFFFFFFFFFFF000LL )
    {
      v35 = hyp_assign_sg_from_flags(v24, *((int *)v8 + 2), 1);
      v39 = *(_DWORD *)(v24 + 12);
      if ( v35 )
      {
        if ( v39 )
        {
          v40 = *(_QWORD **)v24;
          v41 = 0;
          do
          {
            v45 = *v40 & 0xFFFFFFFFFFFFFFFCLL;
            if ( (*(_QWORD *)v45 & 0x40) != 0 )
              v44 = *(unsigned __int8 *)(v45 + 64);
            else
              v44 = 0;
            _free_pages(v45, v44);
            ++v41;
            v40 = (_QWORD *)sg_next(v40);
          }
          while ( v41 < *(_DWORD *)(v24 + 12) );
        }
      }
      else if ( v39 )
      {
        v46 = *(_QWORD **)v24;
        v47 = 0;
        do
        {
          v49 = *v46 & 0xFFFFFFFFFFFFFFFCLL;
          if ( (*(_QWORD *)v49 & 0x40) != 0 && *(_BYTE *)(v49 + 64) == 9 )
          {
            v48 = 0;
          }
          else if ( (*(_QWORD *)v49 & 0x40) != 0 && *(_BYTE *)(v49 + 64) == 4 )
          {
            v48 = 1;
          }
          else if ( (*(_QWORD *)v49 & 0x40) != 0 )
          {
            v48 = 2;
            if ( *(_BYTE *)(v49 + 64) )
              v48 = 3;
          }
          else
          {
            v48 = 2;
          }
          dynamic_page_pool_free((*v8)[v48], v49, v36, v37, v38);
          ++v47;
          v46 = (_QWORD *)sg_next(v46);
        }
        while ( v47 < *(_DWORD *)(v24 + 12) );
      }
      sg_free_table(v24);
    }
    goto LABEL_4;
  }
  v27 = *(_QWORD *)v24;
  while ( 1 )
  {
    v28 = (unsigned __int64)(v26 - 1);
    v29 = (*(v26 - 1) & 0x40) != 0 ? *((_BYTE *)v26 + 56) : 0;
    if ( (v28 & 3) != 0 )
      break;
    v30 = *(_QWORD *)v27 & 3LL;
    *(_DWORD *)(v27 + 8) = 0;
    *(_DWORD *)(v27 + 12) = 4096LL << v29;
    *(_QWORD *)v27 = v30 | v28;
    v27 = sg_next(v27);
    v26 = (_QWORD *)*v26;
    if ( v26 == &v53 )
      goto LABEL_35;
  }
  __break(0x800u);
  return system_heap_allocate_0(v27);
}
