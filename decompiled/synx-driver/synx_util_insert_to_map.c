__int64 __fastcall synx_util_insert_to_map(__int64 a1, unsigned int a2, int a3, unsigned __int8 a4)
{
  unsigned __int64 v8; // x0
  __int64 v9; // x4
  __int64 v10; // x5
  unsigned __int64 v11; // x20
  __int64 v12; // x8
  unsigned int v13; // w23
  __int64 v14; // x8
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x10
  __int64 v21; // x9
  __int64 v22; // x8
  int v23; // w12
  __int64 v24; // x8
  unsigned __int64 *v25; // x8
  unsigned __int64 v26; // x11
  void *v27; // x0
  __int64 v28; // x3
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x10
  __int64 v35; // x9
  __int64 v36; // x8
  int v37; // w12
  __int64 v38; // x8
  unsigned __int64 *v39; // x8
  unsigned __int64 v40; // x11
  void *v43; // x0
  __int64 v44; // x3
  __int64 v46; // x21
  __int64 v47; // x3
  __int64 v48; // x1
  __int64 v49; // x1
  unsigned int v55; // w9
  __int64 v56; // x22
  unsigned int v58; // w9

  v8 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  v11 = v8;
  if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2624B, &unk_29207, "synx_util_insert_to_map", 999, v9, v10);
    return -12;
  }
  *(_DWORD *)(v8 + 8) = 1;
  v12 = synx_dev;
  *(_QWORD *)v8 = a1;
  *(_DWORD *)(v8 + 12) = a3;
  *(_DWORD *)(v8 + 16) = a2;
  v13 = 1640531527 * a2;
  v14 = *(_QWORD *)(v12 + 152);
  if ( (a2 & 0x100000) == 0 )
  {
    raw_spin_lock_bh(v14 + 18456);
    v20 = *(_QWORD *)(synx_dev + 152) + 8LL * HIBYTE(v13);
    v21 = *(_QWORD *)(v20 + 18464);
    if ( v21 )
    {
      v22 = v21 - 56;
      if ( v21 != 56 )
      {
        while ( 1 )
        {
          v23 = *(_DWORD *)(v22 + 16);
          if ( !((v23 != a2) | (a4 ^ 1) & 1) )
            break;
          if ( v23 == a2 && (a4 & 1) == 0 )
          {
            v46 = v22;
            kfree(v11);
            raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 18456LL);
            if ( (synx_debug & 1) == 0 )
              return -22;
            v47 = 1052;
LABEL_43:
            printk(&unk_26509, &unk_29207, "synx_util_insert_to_map", v47, v46, a2);
            return -22;
          }
          v24 = *(_QWORD *)(v22 + 56);
          if ( v24 )
          {
            v22 = v24 - 56;
            if ( v22 )
              continue;
          }
          goto LABEL_11;
        }
        _X0 = (unsigned int *)(v22 + 8);
        __asm { PRFM            #0x11, [X0] }
        do
          v55 = __ldxr(_X0);
        while ( __stxr(v55 + 1, _X0) );
        v56 = v22;
        if ( v55 )
        {
          if ( (((v55 + 1) | v55) & 0x80000000) == 0 )
          {
LABEL_28:
            synx_util_put_object(a1, v15, v16, v17, v18, v19);
            kfree(v11);
            raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 18456LL);
            if ( (synx_debug & 0x80) == 0 )
              return v56;
            v43 = &unk_298AB;
            v44 = 1046;
            goto LABEL_41;
          }
          v48 = 1;
        }
        else
        {
          v48 = 2;
        }
        refcount_warn_saturate(_X0, v48);
        goto LABEL_28;
      }
    }
LABEL_11:
    v25 = (unsigned __int64 *)(v20 + 18464);
    *(_QWORD *)(v11 + 56) = v21;
    v26 = v11 + 56;
    if ( v21 )
      *(_QWORD *)(v21 + 8) = v26;
    *v25 = v26;
    *(_QWORD *)(v11 + 64) = v25;
    raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 18456LL);
    if ( (synx_debug & 0x80) == 0 )
      return v11;
    v27 = &unk_255E9;
    v28 = 1061;
LABEL_39:
    printk(v27, &unk_25D36, "synx_util_insert_to_map", v28, a2, v11);
    return v11;
  }
  raw_spin_lock_bh(v14 + 10256);
  v34 = *(_QWORD *)(synx_dev + 152) + 8LL * (v13 >> 22);
  v35 = *(_QWORD *)(v34 + 10264);
  if ( !v35 || (v36 = v35 - 56, v35 == 56) )
  {
LABEL_22:
    v39 = (unsigned __int64 *)(v34 + 10264);
    *(_QWORD *)(v11 + 56) = v35;
    v40 = v11 + 56;
    if ( v35 )
      *(_QWORD *)(v35 + 8) = v40;
    *v39 = v40;
    *(_QWORD *)(v11 + 64) = v39;
    raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 10256LL);
    if ( (synx_debug & 0x80) == 0 )
      return v11;
    v27 = &unk_2A44F;
    v28 = 1034;
    goto LABEL_39;
  }
  while ( 1 )
  {
    v37 = *(_DWORD *)(v36 + 16);
    if ( !((v37 != a2) | (a4 ^ 1) & 1) )
    {
      _X0 = (unsigned int *)(v36 + 8);
      __asm { PRFM            #0x11, [X0] }
      do
        v58 = __ldxr(_X0);
      while ( __stxr(v58 + 1, _X0) );
      v56 = v36;
      if ( v58 )
      {
        if ( (((v58 + 1) | v58) & 0x80000000) == 0 )
          goto LABEL_32;
        v49 = 1;
      }
      else
      {
        v49 = 2;
      }
      refcount_warn_saturate(_X0, v49);
LABEL_32:
      synx_util_put_object(a1, v29, v30, v31, v32, v33);
      kfree(v11);
      raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 10256LL);
      if ( (synx_debug & 0x80) == 0 )
        return v56;
      v43 = &unk_2B740;
      v44 = 1019;
LABEL_41:
      printk(v43, &unk_25D36, "synx_util_insert_to_map", v44, v56, a2);
      return v56;
    }
    if ( v37 == a2 && (a4 & 1) == 0 )
      break;
    v38 = *(_QWORD *)(v36 + 56);
    if ( v38 )
    {
      v36 = v38 - 56;
      if ( v36 )
        continue;
    }
    goto LABEL_22;
  }
  v46 = v36;
  kfree(v11);
  raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 10256LL);
  if ( (synx_debug & 1) != 0 )
  {
    v47 = 1025;
    goto LABEL_43;
  }
  return -22;
}
