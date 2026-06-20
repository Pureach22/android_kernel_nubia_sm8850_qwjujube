__int64 __fastcall synx_global_get_parents_num(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 result; // x0
  __int64 v10; // x8
  unsigned __int16 *v11; // x8
  int v12; // w10
  bool v13; // zf
  int v14; // w9
  int v15; // w8
  int v16; // w11
  int v17; // w10
  int v18; // w9
  unsigned int v19; // w21
  __int64 v20; // x5
  unsigned int v21; // w20
  __int64 v22; // x8
  __int64 v23; // x0
  _QWORD v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
    {
      printk(&unk_267BF, &unk_29207, "synx_global_get_parents_num", 561, a5, a6);
      result = 0;
      goto LABEL_37;
    }
LABEL_9:
    result = 0;
    goto LABEL_37;
  }
  if ( a1 - 1 >= 0xFFF )
  {
    if ( (synx_debug & 1) != 0 )
    {
      printk(&unk_27C7E, &unk_29207, "synx_global_get_parents_num", 566, a1, a6);
      result = 0;
      goto LABEL_37;
    }
    goto LABEL_9;
  }
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    result = ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v24);
    if ( !(_DWORD)result )
    {
      v10 = synx_gmem_2;
LABEL_13:
      v11 = (unsigned __int16 *)(v10 + glcoredata_size * a1);
      v12 = v11[8];
      v13 = v11[9] == 0;
      v14 = v11[10];
      v15 = v11[11];
      v16 = !v13;
      if ( v12 )
        v17 = v16 + 1;
      else
        v17 = v16;
      if ( v14 )
        v18 = v17 + 1;
      else
        v18 = v17;
      if ( v15 )
        v19 = v18 + 1;
      else
        v19 = v18;
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        ipclite_global_spin_unlock((unsigned __int8)a1, v24);
      }
      else
      {
        v22 = synx_gmem_2;
        if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
        {
          printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v20);
          v22 = synx_gmem_2;
        }
        v23 = synx_hwlock;
        *(_WORD *)(v22 + 12) = 8;
        _hwspin_unlock(v23, 1, v24);
      }
      result = v19;
      goto LABEL_37;
    }
  }
  else if ( synx_hwlock )
  {
    result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v24);
    if ( !(_DWORD)result )
    {
      v10 = synx_gmem_2;
      *(_WORD *)(synx_gmem_2 + 12) = 0;
      goto LABEL_13;
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v7, v8);
    result = 4294967274LL;
  }
  if ( (synx_debug & 1) != 0 )
  {
    v21 = result;
    printk(&unk_2981B, &unk_29207, "synx_global_get_parents_num", 572, a1, v8);
    result = v21;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
