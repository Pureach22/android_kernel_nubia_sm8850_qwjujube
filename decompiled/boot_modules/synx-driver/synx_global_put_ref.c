__int64 __fastcall synx_global_put_ref(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w19
  __int64 v7; // x4
  __int64 v8; // x8
  void *v9; // x0
  void *v10; // x1
  __int64 v11; // x3
  size_t v12; // x2
  _WORD *v13; // x0
  __int16 v14; // w8
  __int64 v15; // x5
  __int64 v16; // x5
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
      result = printk(&unk_267BF, &unk_29207, "synx_global_put_ref", 972, a5, a6);
    goto LABEL_19;
  }
  v6 = result;
  if ( (unsigned int)(result - 1) >= 0xFFF )
  {
    if ( (synx_debug & 1) == 0 )
      goto LABEL_19;
    v9 = &unk_27C7E;
    v10 = &unk_29207;
    v11 = 977;
LABEL_33:
    result = printk(v9, v10, "synx_global_put_ref", v11, v6, a6);
    goto LABEL_19;
  }
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    result = ipclite_global_spin_lock_timeout((unsigned __int8)v6, 500, v21);
    if ( !(_DWORD)result )
    {
      v8 = synx_gmem_2;
      goto LABEL_13;
    }
    goto LABEL_18;
  }
  result = synx_hwlock;
  if ( !synx_hwlock )
  {
    if ( (synx_debug & 1) != 0 )
      result = printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v7, a6);
    goto LABEL_18;
  }
  result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v21);
  if ( (_DWORD)result )
  {
LABEL_18:
    if ( (synx_debug & 1) == 0 )
      goto LABEL_19;
    v9 = &unk_2981B;
    v10 = &unk_29207;
    v11 = 983;
    goto LABEL_33;
  }
  v8 = synx_gmem_2;
  *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_13:
  v12 = (unsigned int)glcoredata_size;
  v13 = (_WORD *)(v8 + glcoredata_size * v6);
  v14 = v13[4] - 1;
  v13[4] = v14;
  if ( v14 )
  {
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      result = ipclite_global_spin_unlock((unsigned __int8)v6, v21);
    }
    else
    {
      v17 = synx_gmem_2;
      if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
      {
        printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v15);
        v17 = synx_gmem_2;
      }
      v18 = synx_hwlock;
      *(_WORD *)(v17 + 12) = 8;
      result = _hwspin_unlock(v18, 1, v21);
    }
    goto LABEL_19;
  }
  memset(v13, 0, v12);
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    ipclite_global_spin_unlock((unsigned __int8)v6, v21);
  }
  else
  {
    v19 = synx_gmem_2;
    if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
    {
      printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v16);
      v19 = synx_gmem_2;
    }
    v20 = synx_hwlock;
    *(_WORD *)(v19 + 12) = 8;
    _hwspin_unlock(v20, 1, v21);
  }
  result = ipclite_global_test_and_clear_bit(v6 & 0x1F, synx_gmem_0 + 4LL * (v6 >> 5));
  if ( (synx_debug & 0x80) != 0 )
  {
    v9 = &unk_285E7;
    v10 = &unk_25D36;
    v11 = 997;
    goto LABEL_33;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
