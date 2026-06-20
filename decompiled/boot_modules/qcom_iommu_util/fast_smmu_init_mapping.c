__int64 __fastcall fast_smmu_init_mapping(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  __int64 lock_irqsave; // x0
  __int64 v7; // x22
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x24
  __int64 v12; // x0
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 *v21; // x9
  __int64 v22; // x20
  __int64 v23; // x10
  unsigned __int64 v24; // x9
  __int64 v25; // x11
  __int64 v26; // x8
  unsigned __int64 v27; // x10

  lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
  v7 = mappings;
  if ( mappings )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = *(_QWORD *)(v7 - 128);
        if ( v8 <= a2 )
          break;
        v7 = *(_QWORD *)(v7 + 16);
        if ( !v7 )
          goto LABEL_7;
      }
      if ( v8 >= a2 )
        break;
      v7 = *(_QWORD *)(v7 + 8);
      if ( !v7 )
        goto LABEL_7;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
    if ( v7 != 136 )
    {
      dev_err(a1, "Iova cookie already present\n");
      return 4294967274LL;
    }
  }
  else
  {
LABEL_7:
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
  }
  if ( !a3 )
    return 4294967274LL;
  v10 = *(_QWORD *)(a2 + 40);
  v9 = *(_QWORD *)(a2 + 48);
  if ( v9 >= 0xFFFFFFFF )
    v9 = 0xFFFFFFFFLL;
  v11 = v9 - v10;
  if ( v9 <= v10 )
  {
    dev_err(a1, "Invalid domain geometry\n");
    return 4294967274LL;
  }
  v12 = _kmalloc_cache_noprof(memset, 3520, 208);
  v13 = v12;
  if ( !v12 )
    return 4294967284LL;
  *(_QWORD *)(v12 + 24) = v10;
  *(_QWORD *)(v12 + 32) = v11 + 1;
  v14 = (v11 + 1) >> 12;
  *(_QWORD *)(v12 + 40) = v14;
  *(_DWORD *)(v12 + 48) = ((v14 + 63) >> 3) & 0xFFFFFFF8;
  v15 = _kmalloc_noprof(*(unsigned int *)(v12 + 48), 77248);
  *(_QWORD *)(v13 + 56) = v15;
  if ( !v15 )
  {
    v16 = vzalloc_noprof(*(unsigned int *)(v13 + 48));
    *(_QWORD *)(v13 + 56) = v16;
    if ( !v16 )
    {
LABEL_36:
      kfree(v13);
      return 4294967284LL;
    }
  }
  v17 = _kmalloc_noprof(*(unsigned int *)(v13 + 48), 77248);
  *(_QWORD *)(v13 + 64) = v17;
  if ( !v17 )
  {
    v18 = vzalloc_noprof(*(unsigned int *)(v13 + 48));
    *(_QWORD *)(v13 + 64) = v18;
    if ( !v18 )
    {
LABEL_35:
      kvfree(*(_QWORD *)(v13 + 56));
      goto LABEL_36;
    }
  }
  *(_DWORD *)(v13 + 104) = 0;
  _mutex_init(v13 + 160, "&fast->msi_cookie_init_lock", &_fast_smmu_create_mapping_sized___key);
  v19 = _kmalloc_cache_noprof(vmap, 3520, 136);
  *(_QWORD *)(v13 + 16) = v19;
  if ( !v19 )
  {
    kvfree(*(_QWORD *)(v13 + 64));
    goto LABEL_35;
  }
  init_iova_domain(v19, 4096, v10 >> 12);
  if ( v13 > 0xFFFFFFFFFFFFF000LL )
    return 4294967284LL;
  *(_QWORD *)v13 = a1;
  *(_QWORD *)(v13 + 8) = a2;
  v20 = raw_write_lock_irqsave(&mappings_lock);
  v21 = &mappings;
  v22 = v20;
  v23 = mappings;
  if ( mappings )
  {
    v24 = *(_QWORD *)(v13 + 8);
    do
    {
      while ( 1 )
      {
        v26 = v23;
        v27 = *(_QWORD *)(v23 - 128);
        if ( v24 >= v27 )
          break;
        v25 = 16;
        v23 = *(_QWORD *)(v26 + 16);
        if ( !v23 )
          goto LABEL_26;
      }
      if ( v24 <= v27 )
        goto LABEL_31;
      v25 = 8;
      v23 = *(_QWORD *)(v26 + 8);
    }
    while ( v23 );
LABEL_26:
    v21 = (__int64 *)(v26 + v25);
  }
  else
  {
    v26 = 0;
  }
  *(_QWORD *)(v13 + 136) = v26;
  *(_QWORD *)(v13 + 144) = 0;
  *(_QWORD *)(v13 + 152) = 0;
  *v21 = v13 + 136;
  rb_insert_color(v13 + 136);
LABEL_31:
  raw_write_unlock_irqrestore(&mappings_lock, v22);
  *(_QWORD *)(v13 + 96) = a3;
  *(_QWORD *)(v13 + 112) = fast_smmu_notify;
  return 0;
}
