__int64 __fastcall synx_global_test_status_set_wait(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  char v6; // w21
  __int64 v8; // x4
  __int64 v9; // x8
  void *v10; // x0
  __int64 v11; // x3
  __int64 v12; // x22
  unsigned int v13; // w20
  __int64 v14; // x5
  __int64 v16; // x8
  __int64 v17; // x0
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_test_status_set_wait", 668, a5, a6);
    goto LABEL_22;
  }
  v6 = a2;
  if ( a2 > 7 || a1 - 1 >= 0xFFF )
  {
    if ( (synx_debug & 1) == 0 )
    {
LABEL_22:
      v13 = 0;
      goto LABEL_23;
    }
    v10 = &unk_27C7E;
    v11 = 673;
LABEL_31:
    printk(v10, &unk_29207, "synx_global_test_status_set_wait", v11, a1, a6);
    goto LABEL_22;
  }
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    if ( !(unsigned int)ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v18) )
    {
      v9 = synx_gmem_2;
      goto LABEL_14;
    }
    goto LABEL_21;
  }
  if ( !synx_hwlock )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v8, a6);
    goto LABEL_21;
  }
  if ( (unsigned int)_hwspin_lock_timeout(synx_hwlock, 500, 1, v18) )
  {
LABEL_21:
    if ( (synx_debug & 1) == 0 )
      goto LABEL_22;
    v10 = &unk_2981B;
    v11 = 679;
    goto LABEL_31;
  }
  v9 = synx_gmem_2;
  *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_14:
  v12 = v9 + glcoredata_size * a1;
  synx_global_print_data((_WORD *)v12, (__int64)"synx_global_test_status_set_wait");
  v13 = *(_DWORD *)v12;
  if ( *(_DWORD *)v12 == 1 || *(_WORD *)(v12 + 10) )
  {
    v13 = 1;
    *(_WORD *)(v12 + 14) |= 1LL << v6;
  }
  else if ( (synx_debug & 8) != 0 )
  {
    printk(&unk_2AE84, &unk_2A972, "synx_global_test_status_set_wait", 692, *(unsigned int *)(v12 + 4), v13);
  }
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    ipclite_global_spin_unlock((unsigned __int8)a1, v18);
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
    _hwspin_unlock(v17, 1, v18);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v13;
}
