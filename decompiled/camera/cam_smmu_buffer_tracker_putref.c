unsigned int *__fastcall cam_smmu_buffer_tracker_putref(unsigned int *result)
{
  __int64 *v1; // x23
  unsigned int *v2; // x19
  __int64 *v3; // x25
  int v9; // w8
  char v10; // w8
  __int64 **v11; // x8
  __int64 v12; // x9
  __int64 **v13; // x1
  int v14; // [xsp+8h] [xbp-8h]

  if ( result )
  {
    if ( (byte_3940FB & 1) == 0 )
    {
      v1 = *(__int64 **)result;
      v2 = result;
      if ( *(unsigned int **)result != result )
      {
        while ( 1 )
        {
          v3 = (__int64 *)*v1;
          if ( v1 )
          {
            result = (unsigned int *)v1[2];
            if ( result )
              break;
          }
LABEL_7:
          v1 = v3;
          if ( v3 == (__int64 *)v2 )
            return result;
        }
        __asm { PRFM            #0x11, [X0] }
        do
          v9 = __ldxr(result);
        while ( __stlxr(v9 - 1, result) );
        if ( v9 == 1 )
        {
          __dmb(9u);
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, int))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_buffer_tracker_putref",
            2683,
            "[SMMU_BT] Unexpected - buffer reference [fd: 0x%x ino: 0x%x cb: %s] zeroed prior to unmap invocation",
            *((unsigned int *)v1 + 6),
            v1[4],
            v1[5],
            v14);
        }
        else if ( v9 <= 0 )
        {
          refcount_warn_saturate();
          v10 = debug_mdl;
          if ( (debug_mdl & 0x40) != 0 )
          {
LABEL_16:
            if ( !debug_priority )
              ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, _DWORD))cam_print_log)(
                3,
                v10 & 0x40,
                4,
                "cam_smmu_buffer_tracker_putref",
                2689,
                "[SMMU_BT] kref_count after put, [fd: 0x%x ino: 0x%x cb: %s], count: %d",
                *((unsigned int *)v1 + 6),
                v1[4],
                v1[5],
                *(_DWORD *)v1[2]);
          }
        }
        else
        {
          v10 = debug_mdl;
          if ( (debug_mdl & 0x40) != 0 )
            goto LABEL_16;
        }
        v11 = (__int64 **)v1[1];
        if ( *v11 == v1 && (v12 = *v1, *(__int64 **)(*v1 + 8) == v1) )
        {
          *(_QWORD *)(v12 + 8) = v11;
          *v11 = (__int64 *)v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v1);
        }
        *v1 = (__int64)v1;
        v1[1] = (__int64)v1;
        raw_spin_lock_bh(&dword_3940F4);
        v13 = (__int64 **)qword_3940E0;
        if ( v1 == &qword_3940D8 || (__int64 *)qword_3940E0 == v1 || *(__int64 **)qword_3940E0 != &qword_3940D8 )
        {
          _list_add_valid_or_report(v1);
        }
        else
        {
          qword_3940E0 = (__int64)v1;
          *v1 = (__int64)&qword_3940D8;
          v1[1] = (__int64)v13;
          *v13 = v1;
        }
        result = (unsigned int *)raw_spin_unlock_bh(&dword_3940F4);
        goto LABEL_7;
      }
    }
  }
  return result;
}
