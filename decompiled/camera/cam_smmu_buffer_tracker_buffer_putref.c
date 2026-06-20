__int64 __fastcall cam_smmu_buffer_tracker_buffer_putref(__int64 *a1)
{
  int v9; // w8
  __int64 **v10; // x8
  __int64 v11; // x9
  __int64 **v12; // x1

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             2,
             "cam_smmu_buffer_tracker_buffer_putref",
             3930,
             "[SMMU_BT] track buffer entry is NULL");
  _X0 = (unsigned int *)a1[2];
  __asm { PRFM            #0x11, [X0] }
  do
    v9 = __ldxr(_X0);
  while ( __stlxr(v9 - 1, _X0) );
  if ( v9 == 1 )
  {
    __dmb(9u);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_buffer_tracker_buffer_putref",
      3937,
      "[SMMU_BT] Unexpected - buffer reference [fd: 0x%x ino: 0x%x cb: %s] zeroed prior to unmap invocation",
      *((unsigned int *)a1 + 6),
      a1[4],
      a1[5]);
  }
  else
  {
    if ( v9 <= 0 )
      refcount_warn_saturate();
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, _DWORD))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_buffer_tracker_buffer_putref",
        3941,
        "[SMMU_BT] kref_count after put, [fd: 0x%x ino: 0x%x cb: %s], count: %d",
        *((unsigned int *)a1 + 6),
        a1[4],
        a1[5],
        *(_DWORD *)a1[2]);
  }
  v10 = (__int64 **)a1[1];
  if ( *v10 == a1 && (v11 = *a1, *(__int64 **)(*a1 + 8) == a1) )
  {
    *(_QWORD *)(v11 + 8) = v10;
    *v10 = (__int64 *)v11;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  *a1 = (__int64)a1;
  a1[1] = (__int64)a1;
  raw_spin_lock_bh(&dword_3940F4);
  v12 = (__int64 **)qword_3940E0;
  if ( a1 == &qword_3940D8 || (__int64 *)qword_3940E0 == a1 || *(__int64 **)qword_3940E0 != &qword_3940D8 )
  {
    _list_add_valid_or_report(a1);
  }
  else
  {
    qword_3940E0 = (__int64)a1;
    *a1 = (__int64)&qword_3940D8;
    a1[1] = (__int64)v12;
    *v12 = a1;
  }
  return raw_spin_unlock_bh(&dword_3940F4);
}
