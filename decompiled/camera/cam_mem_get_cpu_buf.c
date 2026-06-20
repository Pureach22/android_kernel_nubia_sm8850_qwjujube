__int64 __fastcall cam_mem_get_cpu_buf(int a1, _QWORD *a2, _QWORD *a3)
{
  __int64 result; // x0
  unsigned int v5; // w19
  int v6; // w22
  char *v7; // x20
  __int64 v10; // x0
  const char *v11; // x5
  __int64 v12; // x4
  unsigned int v13; // w19
  __int64 v14; // x0
  int unless_zero; // w0
  const void *v16; // x6

  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFF0100) != 0 )
  {
    v14 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x400000,
            1,
            "cam_mem_get_cpu_buf",
            1133,
            "Calling from softirq/atomic context");
    dump_stack(v14);
    return 4294967274LL;
  }
  if ( !cam_mem_mgr_state )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_get_cpu_buf",
      1139,
      "failed. mem_mgr not initialized");
    return 4294967274LL;
  }
  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      if ( a3 )
      {
        v5 = a1 & 0x7FFF;
        if ( v5 - 2048 >= 0xFFFFF801 )
        {
          v6 = a1;
          v7 = (char *)&tbl + 296 * (a1 & 0x7FFF);
          v10 = mutex_lock(v7 + 72);
          if ( v5 > 0x7FF )
          {
            __break(1u);
            return kref_get_unless_zero(v10);
          }
          if ( (v7[184] & 1) == 0 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x400000,
              1,
              "cam_mem_get_cpu_buf",
              1154,
              "Buffer at idx=%d is already unmapped,",
              v5);
            v13 = -1;
LABEL_23:
            mutex_unlock(v7 + 72);
            return v13;
          }
          if ( *((_DWORD *)v7 + 34) != v6 )
          {
            v11 = "idx: %d Invalid buf handle %d";
            v12 = 1161;
            goto LABEL_16;
          }
          if ( (*((_DWORD *)v7 + 38) & 8) == 0 )
          {
            v11 = "idx: %d Invalid flag 0x%x";
            v12 = 1168;
LABEL_16:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              0x400000,
              1,
              "cam_mem_get_cpu_buf",
              v12,
              v11,
              v5);
            v13 = -22;
            goto LABEL_23;
          }
          raw_spin_lock_bh(v7 + 352);
          if ( *((_QWORD *)v7 + 20) )
          {
            unless_zero = kref_get_unless_zero(v7 + 208);
            v16 = *((const void **)v7 + 20);
            if ( unless_zero )
            {
              *a2 = v16;
              v13 = 0;
              *a3 = *((_QWORD *)v7 + 18);
LABEL_22:
              raw_spin_unlock_bh(v7 + 352);
              goto LABEL_23;
            }
          }
          else
          {
            v16 = nullptr;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x400000,
            1,
            "cam_mem_get_cpu_buf",
            1179,
            "No KMD access requested, kmdvddr= %p, idx= %d, buf_handle= %d",
            v16,
            v5,
            v6);
          v13 = -22;
          goto LABEL_22;
        }
      }
    }
  }
  return result;
}
