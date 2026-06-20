__int64 __fastcall synx_global_test_status_set_parent_child_wait(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v8; // x4
  __int64 v9; // x8
  void *v10; // x0
  __int64 v11; // x3
  __int64 v12; // x22
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x5
  __int64 result; // x0
  unsigned int v19; // w21
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x5
  __int64 v25; // x4
  __int64 v26; // x4
  __int64 v27; // x4
  __int64 v28; // x4
  __int64 v29; // [xsp+0h] [xbp-20h] BYREF
  __int64 v30; // [xsp+8h] [xbp-18h] BYREF
  __int64 v31; // [xsp+10h] [xbp-10h]
  __int64 v32; // [xsp+18h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v31 = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_test_status_set_parent_child_wait", 710, a5, a6);
    goto LABEL_22;
  }
  if ( a2 > 7 || a1 - 1 >= 0xFFF )
  {
    if ( (synx_debug & 1) == 0 )
    {
LABEL_22:
      result = 0;
      goto LABEL_23;
    }
    v10 = &unk_27C7E;
    v11 = 715;
LABEL_37:
    printk(v10, &unk_29207, "synx_global_test_status_set_parent_child_wait", v11, a1, a6);
    goto LABEL_22;
  }
  if ( (get_ipclite_feature(4) & 1) != 0 )
  {
    if ( !(unsigned int)ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, &v29) )
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
  if ( (unsigned int)_hwspin_lock_timeout(synx_hwlock, 500, 1, &v29) )
  {
LABEL_21:
    if ( (synx_debug & 1) == 0 )
      goto LABEL_22;
    v10 = &unk_2981B;
    v11 = 721;
    goto LABEL_37;
  }
  v9 = synx_gmem_2;
  *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_14:
  v12 = v9 + glcoredata_size * a1;
  synx_global_print_data((_WORD *)v12, (__int64)"synx_global_test_status_set_parent_child_wait");
  if ( *(_WORD *)(v12 + 10) )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2A0C0, &unk_29207, "synx_global_test_status_set_parent_child_wait", 729, v15, v16);
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      ipclite_global_spin_unlock((unsigned __int8)a1, &v29);
      result = 4294967274LL;
    }
    else
    {
      v20 = synx_gmem_2;
      if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
      {
        printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v17);
        v20 = synx_gmem_2;
      }
      v21 = synx_hwlock;
      *(_WORD *)(v20 + 12) = 8;
      _hwspin_unlock(v21, 1, &v29);
      result = 4294967274LL;
    }
    goto LABEL_23;
  }
  v19 = *(_DWORD *)v12;
  if ( *(_DWORD *)v12 != 1 )
  {
    if ( (synx_debug & 8) != 0 )
      printk(
        &unk_2BA78,
        &unk_2A972,
        "synx_global_test_status_set_parent_child_wait",
        765,
        *(unsigned int *)(v12 + 4),
        v19);
    goto LABEL_35;
  }
  synx_global_get_parents_locked((unsigned __int16 *)v12, &v30, v13, v14, v15, v16);
  if ( !(_DWORD)v30 && !HIDWORD(v30) && __PAIR64__(v31, 0) == HIDWORD(v31) )
  {
    *(_WORD *)(v12 + 14) |= 1LL << a2;
LABEL_35:
    synx_gmem_unlock(a1, (__int64)&v29);
    result = v19;
    goto LABEL_23;
  }
  synx_gmem_unlock(a1, (__int64)&v29);
  v25 = (unsigned int)v30;
  if ( (_DWORD)v30 )
  {
    if ( (synx_debug & 8) != 0 )
    {
      printk(&unk_27EDF, &unk_2A972, "synx_global_test_status_set_parent_child_wait", 757, (unsigned int)v30, v24);
      v25 = (unsigned int)v30;
    }
    synx_global_set_waiting_core(v25, a2, v22, v23, v25, v24);
  }
  v26 = HIDWORD(v30);
  if ( HIDWORD(v30) )
  {
    if ( (synx_debug & 8) != 0 )
    {
      printk(&unk_27EDF, &unk_2A972, "synx_global_test_status_set_parent_child_wait", 757, HIDWORD(v30), v24);
      v26 = HIDWORD(v30);
    }
    synx_global_set_waiting_core(v26, a2, v22, v23, v26, v24);
  }
  v27 = (unsigned int)v31;
  if ( (_DWORD)v31 )
  {
    if ( (synx_debug & 8) != 0 )
    {
      printk(&unk_27EDF, &unk_2A972, "synx_global_test_status_set_parent_child_wait", 757, (unsigned int)v31, v24);
      v27 = (unsigned int)v31;
    }
    synx_global_set_waiting_core(v27, a2, v22, v23, v27, v24);
  }
  v28 = HIDWORD(v31);
  if ( HIDWORD(v31) )
  {
    if ( (synx_debug & 8) != 0 )
    {
      printk(&unk_27EDF, &unk_2A972, "synx_global_test_status_set_parent_child_wait", 757, HIDWORD(v31), v24);
      v28 = HIDWORD(v31);
    }
    synx_global_set_waiting_core(v28, a2, v22, v23, v28, v24);
    result = 1;
  }
  else
  {
    result = 1;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
