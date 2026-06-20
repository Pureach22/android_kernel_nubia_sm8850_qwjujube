__int64 __fastcall cam_smmu_add_buf_to_track_list(int a1, __int64 a2, unsigned int **a3, __int64 *a4, int a5)
{
  __int64 v10; // x20
  _QWORD *v11; // x8
  __int64 v12; // x9
  unsigned int *v14; // x9
  __int64 v15; // x8
  const char *v16; // x10
  char v17; // w8
  __int64 v18; // x2
  unsigned int v25; // w8

  if ( (byte_3940FB & 1) == 0 )
  {
    raw_spin_lock_bh(&dword_3940F4);
    v10 = qword_3940D8;
    if ( (__int64 *)qword_3940D8 == &qword_3940D8 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        2,
        "cam_smmu_util_get_free_map_entry",
        3051,
        "[SMMU_BT] Not enough mem to track buffer");
      raw_spin_unlock_bh(&dword_3940F4);
    }
    else
    {
      v11 = *(_QWORD **)(qword_3940D8 + 8);
      if ( *v11 == qword_3940D8
        && (v12 = *(_QWORD *)qword_3940D8, *(_QWORD *)(*(_QWORD *)qword_3940D8 + 8LL) == qword_3940D8) )
      {
        *(_QWORD *)(v12 + 8) = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(qword_3940D8);
      }
      *(_QWORD *)v10 = v10;
      *(_QWORD *)(v10 + 8) = v10;
      raw_spin_unlock_bh(&dword_3940F4);
      _X0 = *a3;
      __asm { PRFM            #0x11, [X0] }
      do
        v25 = __ldxr(_X0);
      while ( __stxr(v25 + 1, _X0) );
      if ( !v25 || (((v25 + 1) | v25) & 0x80000000) != 0 )
        refcount_warn_saturate();
      *(_DWORD *)(v10 + 24) = a1;
      *(_QWORD *)(v10 + 32) = a2;
      v14 = *a3;
      v15 = iommu_cb_set + 14280LL * a5;
      *(_QWORD *)(v10 + 16) = *a3;
      v16 = *(const char **)(v15 + 32);
      v17 = debug_mdl;
      *(_QWORD *)(v10 + 40) = v16;
      if ( (v17 & 0x40) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v17 & 0x40,
          4,
          "cam_smmu_add_buf_to_track_list",
          3089,
          "[SMMU_BT] ref_cnt increased for fd 0x%x, ino 0x%x: %d, cb: %s",
          a1,
          a2,
          *v14,
          v16);
      v18 = *a4;
      if ( *(__int64 **)(*a4 + 8) != a4 || (__int64 *)v10 == a4 || v18 == v10 )
      {
        _list_add_valid_or_report(v10);
      }
      else
      {
        *(_QWORD *)(v18 + 8) = v10;
        *(_QWORD *)v10 = v18;
        *(_QWORD *)(v10 + 8) = a4;
        *a4 = v10;
      }
    }
  }
  return 0;
}
