__int64 __fastcall synx_global_recover_interop(
        unsigned int a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v7; // x19
  __int64 v8; // x0
  void *v9; // x0
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  unsigned int i; // w22
  __int64 v14; // x1
  __int64 v15; // x8
  __int64 v16; // x0
  unsigned int next_bit; // w22
  __int16 v18; // w25
  __int64 v19; // x26
  bool v20; // cc
  char v21; // w20
  __int64 v22; // x4
  __int64 v23; // x5
  unsigned int v24; // w0
  __int64 v25; // x8
  size_t v26; // x2
  _WORD *v27; // x0
  __int64 v28; // x9
  __int16 v29; // w8
  _BOOL4 v30; // w23
  __int64 v31; // x5
  __int64 v32; // x8
  __int64 v33; // x0
  char v35; // w8
  _DWORD *v36; // x8
  __int64 j; // x22
  __int64 v38; // x5
  unsigned int v39; // w20
  __int64 result; // x0
  unsigned int v41; // [xsp+4h] [xbp-1Ch]
  _QWORD v43[2]; // [xsp+10h] [xbp-10h] BYREF

  v43[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43[0] = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) == 0 )
    {
LABEL_75:
      result = 4294967284LL;
      goto LABEL_76;
    }
    v9 = &unk_267BF;
    v10 = 1129;
LABEL_78:
    printk(v9, &unk_29207, "synx_global_recover_interop", v10, a5, a6);
    goto LABEL_75;
  }
  v7 = _kmalloc_large_noprof(0x4000, 3520);
  if ( !v7 )
  {
    if ( (synx_debug & 1) == 0 )
      goto LABEL_75;
    v9 = &unk_28271;
    v10 = 1136;
    goto LABEL_78;
  }
  if ( a1 >= 8 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_27EB9, &unk_29207, "synx_global_map_core_id", 231, a5, a6);
    v8 = 9;
  }
  else
  {
    v8 = dword_2BF00[a1];
  }
  ipclite_recover(v8);
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    for ( i = 0; i != 256; ++i )
    {
      if ( a1 < 8 )
      {
        v14 = dword_2BF00[a1];
      }
      else
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_27EB9, &unk_29207, "synx_global_map_core_id", 231, v11, v12);
        v14 = 9;
      }
      ipclite_global_spin_bust(i, v14);
    }
  }
  else
  {
    v15 = synx_gmem_2;
    if ( *(unsigned __int16 *)(synx_gmem_2 + 12) == a1 )
    {
      if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
      {
        printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, a1, v12);
        v15 = synx_gmem_2;
      }
      v16 = synx_hwlock;
      *(_WORD *)(v15 + 12) = 8;
      _hwspin_unlock(v16, 3, 0);
    }
  }
  next_bit = find_next_bit(synx_gmem_0, 4096, 1);
  if ( next_bit > 0xFFF )
  {
LABEL_63:
    for ( j = 1; j != 4096; ++j )
    {
      if ( *(_DWORD *)(v7 + 4 * j) )
      {
        ipclite_global_test_and_clear_bit(j & 0x1F, synx_gmem_0 + 4LL * ((unsigned int)j >> 5));
        if ( (synx_debug & 0x80) != 0 )
          printk(&unk_26815, &unk_25D36, "synx_global_recover_interop", 1194, (unsigned int)j, v38);
      }
    }
    v39 = 0;
    goto LABEL_73;
  }
  LOBYTE(v18) = 0;
  v19 = 1LL << a1;
  if ( a2 )
    v20 = a2 > 0xFFFFFFFFFFFFF000LL;
  else
    v20 = 1;
  v21 = v20;
  v41 = 0;
  while ( 1 )
  {
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      v24 = ipclite_global_spin_lock_timeout((unsigned __int8)next_bit, 500, v43);
      if ( v24 )
        goto LABEL_69;
      v25 = synx_gmem_2;
      goto LABEL_38;
    }
    if ( !synx_hwlock )
      break;
    v24 = _hwspin_lock_timeout(synx_hwlock, 500, 1, v43);
    if ( v24 )
    {
LABEL_69:
      v39 = v24;
      goto LABEL_73;
    }
    v25 = synx_gmem_2;
    *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_38:
    v26 = (unsigned int)glcoredata_size;
    v27 = (_WORD *)(v25 + glcoredata_size * next_bit);
    if ( v27[4] && (v28 = (unsigned __int16)v27[6], (v19 & v28) != 0) )
    {
      v29 = v27[4] - 1;
      v18 = v27[7];
      v27[4] = v29;
      v27[6] = v28 & ~(_WORD)v19;
      v41 = *((_DWORD *)v27 + 6);
      if ( v29 )
      {
        v30 = *(_DWORD *)v27 == 1;
      }
      else
      {
        memset(v27, 0, v26);
        v30 = 0;
        *(_DWORD *)(v7 + 4LL * (next_bit & 0xFFF)) = 1;
      }
    }
    else
    {
      v30 = 0;
    }
    if ( (get_ipclite_feature(4) & 1) == 0 )
    {
      v32 = synx_gmem_2;
      if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
      {
        printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v31);
        v32 = synx_gmem_2;
      }
      v33 = synx_hwlock;
      *(_WORD *)(v32 + 12) = 8;
      _hwspin_unlock(v33, 1, v43);
      if ( !v30 )
        goto LABEL_31;
LABEL_50:
      ((void (__fastcall *)(_QWORD, __int64, _QWORD))synx_global_update_status_core)(next_bit, 6, 0);
      if ( (v18 & 0x20) != 0 && a1 == 5 )
        v35 = v21;
      else
        v35 = 1;
      if ( (v35 & 1) == 0 )
      {
        v36 = *(_DWORD **)(a2 + 24);
        if ( v36 )
        {
          if ( (unsigned __int64)v36 <= 0xFFFFFFFFFFFFF000LL )
          {
            if ( *(v36 - 1) != -1328200472 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v36)(5, 1, v41, 6);
          }
        }
      }
      goto LABEL_31;
    }
    ipclite_global_spin_unlock((unsigned __int8)next_bit, v43);
    if ( v30 )
      goto LABEL_50;
LABEL_31:
    next_bit = find_next_bit(synx_gmem_0, 4096, ((_WORD)next_bit + 1) & 0x1FFF);
    if ( next_bit >= 0x1000 )
      goto LABEL_63;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v22, v23);
  v39 = -22;
LABEL_73:
  kfree(v7);
  result = v39;
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
