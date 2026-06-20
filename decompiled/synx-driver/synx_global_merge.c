__int64 __fastcall synx_global_merge(__int64 a1, int a2, unsigned int a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  __int16 v13; // w11
  __int64 v14; // x5
  __int64 v15; // x5
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x23
  int v19; // w26
  unsigned int v20; // w21
  unsigned int v21; // w28
  __int64 v22; // x4
  __int64 v23; // x5
  int v24; // w0
  __int64 v25; // x8
  unsigned int *v26; // x25
  _WORD *v27; // x8
  __int64 v28; // x27
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x8
  __int64 v32; // x0
  unsigned int v33; // w20
  unsigned int v34; // w0
  __int64 v35; // x8
  __int64 v36; // x8
  int v37; // w10
  __int64 v38; // x5
  __int64 v39; // x8
  __int64 v40; // x0
  _WORD *v41; // x0
  int v42; // w8
  _QWORD v44[2]; // [xsp+10h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44[0] = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_merge", 1013, a5, a6);
    result = 4294967284LL;
    goto LABEL_100;
  }
  if ( a3 - 1 >= 0xFFF )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_28625, &unk_29207, "synx_global_merge", 1018, a3, a6);
    goto LABEL_12;
  }
  if ( !a2 )
    goto LABEL_99;
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    result = ipclite_global_spin_lock_timeout((unsigned __int8)a3, 500, v44);
    if ( (_DWORD)result )
      goto LABEL_100;
    v11 = synx_gmem_2;
    goto LABEL_16;
  }
  if ( !synx_hwlock )
  {
LABEL_84:
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v8, v9);
LABEL_12:
    result = 4294967274LL;
    goto LABEL_100;
  }
  result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v44);
  if ( (_DWORD)result )
    goto LABEL_100;
  v11 = synx_gmem_2;
  *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_16:
  v12 = v11 + glcoredata_size * a3;
  if ( *(_DWORD *)(v12 + 4) && *(_WORD *)(v12 + 8) )
  {
    v13 = *(_WORD *)(v12 + 10);
    ++*(_WORD *)(v12 + 8);
    *(_WORD *)(v12 + 10) = v13 + a2;
  }
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    ipclite_global_spin_unlock((unsigned __int8)a3, v44);
  }
  else
  {
    v16 = synx_gmem_2;
    if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
    {
      printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v14);
      v16 = synx_gmem_2;
    }
    v17 = synx_hwlock;
    *(_WORD *)(v16 + 12) = 8;
    _hwspin_unlock(v17, 1, v44);
  }
  v18 = 0;
  v19 = 0;
  v20 = 1;
  do
  {
    v21 = *(_DWORD *)(a1 + 4 * v18);
    if ( v21 - 1 >= 0xFFF )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_27C7E, &unk_29207, "synx_global_merge", 1039, v21, v15);
      v33 = 0;
      goto LABEL_74;
    }
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      v24 = ipclite_global_spin_lock_timeout((unsigned __int8)v21, 500, v44);
      if ( v24 )
        goto LABEL_72;
      v25 = synx_gmem_2;
      goto LABEL_33;
    }
    if ( !synx_hwlock )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v22, v23);
      v24 = -22;
LABEL_72:
      v33 = v24;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2981B, &unk_29207, "synx_global_merge", 1045, v21, v23);
LABEL_74:
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        result = ipclite_global_spin_lock_timeout((unsigned __int8)a3, 500, v44);
        if ( (_DWORD)result )
          goto LABEL_100;
        v35 = synx_gmem_2;
      }
      else
      {
        if ( !synx_hwlock )
          goto LABEL_84;
        result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v44);
        if ( (_DWORD)result )
          goto LABEL_100;
        v35 = synx_gmem_2;
        *(_WORD *)(synx_gmem_2 + 12) = 0;
      }
      v36 = v35 + glcoredata_size * a3;
      v37 = *(unsigned __int16 *)(v36 + 10);
      *(_DWORD *)v36 = 3;
      *(_WORD *)(v36 + 10) = v37 - (a2 - v18 + v19);
      if ( v37 == (unsigned __int16)(a2 - v18 + v19) )
        --*(_WORD *)(v36 + 8);
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        ipclite_global_spin_unlock((unsigned __int8)a3, v44);
      }
      else
      {
        v39 = synx_gmem_2;
        if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
        {
          printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v38);
          v39 = synx_gmem_2;
        }
        v40 = synx_hwlock;
        *(_WORD *)(v39 + 12) = 8;
        _hwspin_unlock(v40, 1, v44);
      }
      result = v33;
      goto LABEL_100;
    }
    v24 = _hwspin_lock_timeout(synx_hwlock, 500, 1, v44);
    if ( v24 )
      goto LABEL_72;
    v25 = synx_gmem_2;
    *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_33:
    v26 = (unsigned int *)(v25 + glcoredata_size * v21);
    v27 = v26 + 4;
    if ( *((_WORD *)v26 + 8) )
    {
      if ( *((_WORD *)v26 + 9) )
      {
        if ( *((_WORD *)v26 + 10) )
        {
          if ( *((_WORD *)v26 + 11) )
          {
            LODWORD(v28) = 4;
            goto LABEL_43;
          }
          v28 = 3;
        }
        else
        {
          v28 = 2;
        }
      }
      else
      {
        v28 = 1;
      }
      v27[v28] = a3;
    }
    else
    {
      LODWORD(v28) = 0;
      *v27 = a3;
    }
LABEL_43:
    v29 = *v26;
    if ( (_DWORD)v29 != 1 )
    {
      if ( !*((_WORD *)v26 + 5) )
        ++v19;
      if ( (unsigned int)(v29 - 3) >= 0x3E )
      {
        if ( v20 == 1 )
          v20 = *v26;
      }
      else
      {
        v20 = *v26;
      }
    }
    if ( (synx_debug & 0x80) != 0 )
      printk(&unk_2AEB7, &unk_25D36, "synx_global_merge", 1069, v29, v20);
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      ipclite_global_spin_unlock((unsigned __int8)v21, v44);
    }
    else
    {
      v31 = synx_gmem_2;
      if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
      {
        printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v30);
        v31 = synx_gmem_2;
      }
      v32 = synx_hwlock;
      *(_WORD *)(v31 + 12) = 8;
      _hwspin_unlock(v32, 1, v44);
    }
    if ( (unsigned int)v28 >= 4 )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2933E, &unk_29207, "synx_global_merge", 1075, v26[1], v15);
      v33 = -12;
      goto LABEL_74;
    }
    ++v18;
  }
  while ( a2 != v18 );
  v34 = synx_gmem_lock(a3, (__int64)v44);
  if ( v34 )
  {
    v33 = v34;
    LOWORD(v18) = a2;
    goto LABEL_74;
  }
  v41 = (_WORD *)(synx_gmem_2 + glcoredata_size * a3);
  v42 = (unsigned __int16)v41[5];
  v41[5] = v42 - v19;
  if ( v19 && v42 == (unsigned __int16)v19 )
    --v41[4];
  if ( *(_DWORD *)v41 == 1 || v20 - 65 >= 0xFFFFFFC2 && (unsigned int)(*(_DWORD *)v41 - 3) >= 0x3E )
    *(_DWORD *)v41 = v20;
  synx_global_print_data(v41, (__int64)"synx_global_merge");
  synx_gmem_unlock(a3, (__int64)v44);
LABEL_99:
  result = 0;
LABEL_100:
  _ReadStatusReg(SP_EL0);
  return result;
}
