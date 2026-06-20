__int64 __fastcall synx_fetch_global_shared_memory_handle_details(
        unsigned __int16 a1,
        void *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned int v6; // w19
  unsigned __int8 v7; // w22
  __int64 v9; // x4
  __int64 v10; // x8
  void *v11; // x0
  __int64 v12; // x3
  __int64 v13; // x5
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_fetch_global_shared_memory_handle_details", 104, a5, a6);
    goto LABEL_18;
  }
  v6 = a1;
  if ( (unsigned int)a1 - 1 >= 0xFFF )
  {
    if ( (synx_debug & 1) == 0 )
    {
LABEL_18:
      result = 0;
      goto LABEL_19;
    }
    v11 = &unk_27C7E;
    v12 = 109;
LABEL_26:
    printk(v11, &unk_29207, "synx_fetch_global_shared_memory_handle_details", v12, v6, a6);
    goto LABEL_18;
  }
  v7 = a1;
  if ( (get_ipclite_feature(4) & 1) == 0 )
  {
    if ( synx_hwlock )
    {
      if ( !(unsigned int)_hwspin_lock_timeout(synx_hwlock, 500, 1, v17) )
      {
        v10 = synx_gmem_2;
        *(_WORD *)(synx_gmem_2 + 12) = 0;
        goto LABEL_13;
      }
    }
    else if ( (synx_debug & 1) != 0 )
    {
      printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v9, a6);
    }
    goto LABEL_17;
  }
  if ( (unsigned int)ipclite_global_spin_lock_timeout(v7, 500, v17) )
  {
LABEL_17:
    if ( (synx_debug & 1) == 0 )
      goto LABEL_18;
    v11 = &unk_2981B;
    v12 = 114;
    goto LABEL_26;
  }
  v10 = synx_gmem_2;
LABEL_13:
  memcpy(a2, (const void *)(v10 + glcoredata_size * v6), (unsigned int)glcoredata_size);
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    ipclite_global_spin_unlock(v7, v17);
  }
  else
  {
    v15 = synx_gmem_2;
    if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
    {
      printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v13);
      v15 = synx_gmem_2;
    }
    v16 = synx_hwlock;
    *(_WORD *)(v15 + 12) = 8;
    _hwspin_unlock(v16, 1, v17);
  }
  result = 1;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
