__int64 __fastcall synx_global_update_status(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned int v13; // w20
  __int64 v14; // x5
  __int64 v15; // x5
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_update_status", 900, a5, a6);
    result = 4294967284LL;
    goto LABEL_34;
  }
  if ( a2 < 2 || a1 - 1 >= 0xFFF )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_29DB1, &unk_29207, "synx_global_update_status", 906, a2, a1);
    result = 4294967274LL;
    goto LABEL_34;
  }
  if ( (get_ipclite_feature(4) & 1) == 0 )
  {
    if ( synx_hwlock )
    {
      result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v20);
      if ( !(_DWORD)result )
      {
        v11 = synx_gmem_2;
        *(_WORD *)(synx_gmem_2 + 12) = 0;
        goto LABEL_16;
      }
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v8, v9);
      result = 4294967274LL;
    }
LABEL_21:
    if ( (synx_debug & 1) != 0 )
    {
      v13 = result;
      printk(&unk_2981B, &unk_29207, "synx_global_update_status", 912, a1, v9);
LABEL_33:
      result = v13;
      goto LABEL_34;
    }
    goto LABEL_34;
  }
  result = ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v20);
  if ( (_DWORD)result )
    goto LABEL_21;
  v11 = synx_gmem_2;
LABEL_16:
  v12 = v11 + glcoredata_size * a1;
  if ( *(_WORD *)(v12 + 10) )
  {
    v13 = 0;
    goto LABEL_27;
  }
  if ( *(_DWORD *)v12 != 1 )
  {
    v13 = -114;
LABEL_27:
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      ipclite_global_spin_unlock((unsigned __int8)a1, v20);
    }
    else
    {
      v16 = synx_gmem_2;
      if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
      {
        printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v15);
        v16 = synx_gmem_2;
      }
      v17 = synx_hwlock;
      *(_WORD *)(v16 + 12) = 8;
      _hwspin_unlock(v17, 1, v20);
    }
    goto LABEL_33;
  }
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    ipclite_global_spin_unlock((unsigned __int8)a1, v20);
  }
  else
  {
    v18 = synx_gmem_2;
    if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
    {
      printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v14);
      v18 = synx_gmem_2;
    }
    v19 = synx_hwlock;
    *(_WORD *)(v18 + 12) = 8;
    _hwspin_unlock(v19, 1, v20);
  }
  result = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))synx_global_update_status_core)(a1, a2, 0);
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
