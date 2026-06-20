__int64 __fastcall synx_get_child_coredata(
        unsigned __int64 a1,
        unsigned __int64 *a2,
        unsigned int *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  unsigned __int64 v8; // x22
  unsigned __int64 v9; // x19
  unsigned int v10; // w25
  unsigned __int64 *v11; // x23
  unsigned int *v12; // x24
  unsigned __int64 v13; // x20
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x28
  __int64 v17; // x8
  __int64 v18; // x10
  __int64 v19; // x9
  bool v20; // zf
  unsigned int v21; // w21
  __int64 v22; // x9
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  unsigned __int64 *map_entry; // x0
  __int64 v29; // x5
  unsigned __int64 v30; // x8
  __int64 v31; // x9
  unsigned __int64 StatusReg; // x21
  __int64 v33; // x25

  result = 4294967274LL;
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL || !a3 || (unsigned __int64)a3 > 0xFFFFFFFFFFFFF000LL )
    return result;
  v8 = *(_QWORD *)(a1 + 64);
  if ( *(_UNKNOWN **)(v8 + 8) != &dma_fence_array_ops )
  {
    v9 = 0;
    goto LABEL_7;
  }
  if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) != 0 )
    {
      printk(&unk_29134, &unk_29207, "synx_get_child_coredata", 1483, a5, a6);
      return 4294967274LL;
    }
    return result;
  }
  v11 = a2;
  v12 = a3;
  v13 = 8LL * *(unsigned int *)(v8 + 68);
  v9 = _kmalloc_noprof(v13, 3520);
  if ( !v9 )
  {
LABEL_41:
    if ( (synx_debug & 1) != 0 )
      printk(&unk_286AE, &unk_29207, "synx_get_child_coredata", 1488, v14, v15);
    return 4294967284LL;
  }
  while ( 2 )
  {
    if ( v9 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_41;
    if ( *(_DWORD *)(v8 + 68) )
    {
      v10 = 0;
      while ( 1 )
      {
        v16 = *(_QWORD *)(*(_QWORD *)(v8 + 80) + 8LL * (int)v10);
        raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
        v17 = *(_QWORD *)(synx_dev + 152);
        v18 = *(_QWORD *)(v17 + 8 * ((unsigned __int64)(0x61C8864680B583EBLL * v16) >> 54) + 2064);
        v19 = v18 - 16;
        if ( v18 )
          v20 = v18 == 16;
        else
          v20 = 1;
        if ( v20 )
        {
          v21 = 0;
        }
        else
        {
          while ( *(_QWORD *)(v19 + 8) != v16 )
          {
            v22 = *(_QWORD *)(v19 + 16);
            v21 = 0;
            if ( v22 )
            {
              v19 = v22 - 16;
              if ( v19 )
                continue;
            }
            goto LABEL_27;
          }
          v21 = *(_DWORD *)v19;
          if ( !*(_DWORD *)v19 )
            v21 = *(_DWORD *)(v19 + 4);
        }
LABEL_27:
        raw_spin_unlock_bh(v17 + 2056);
        map_entry = (unsigned __int64 *)synx_util_get_map_entry(v21, v23, v24, v25, v26, v27);
        if ( !map_entry
          || (unsigned __int64)map_entry > 0xFFFFFFFFFFFFF000LL
          || (v30 = *map_entry) == 0
          || v30 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (synx_debug & 1) != 0 )
            printk(&unk_26E24, &unk_29207, "synx_get_child_coredata", 1497, v21, v29);
          kfree(v9);
          return 4294967294LL;
        }
        v31 = (int)v10;
        if ( v13 <= 8LL * (int)v10 )
          break;
        ++v10;
        *(_QWORD *)(v9 + 8 * v31) = v30;
        synx_util_release_map_entry((unsigned __int64)map_entry);
        if ( v10 >= *(_DWORD *)(v8 + 68) )
        {
          a3 = v12;
          a2 = v11;
          goto LABEL_8;
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v33 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &synx_get_child_coredata__alloc_tag;
      v13 = 8LL * *(unsigned int *)(v8 + 68);
      v9 = _kmalloc_noprof(v13, 3520);
      *(_QWORD *)(StatusReg + 80) = v33;
      if ( v9 )
        continue;
      goto LABEL_41;
    }
    break;
  }
  a3 = v12;
  a2 = v11;
LABEL_7:
  v10 = 0;
LABEL_8:
  *a2 = v9;
  *a3 = v10;
  return 0;
}
