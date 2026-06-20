__int64 __fastcall icnss_hw_power_off(_QWORD *a1)
{
  __int64 v1; // x2
  __int64 i; // x24
  __int64 v5; // x22
  unsigned __int64 v6; // x8
  const char *v7; // x2
  _QWORD *v8; // x20
  _QWORD *v9; // x19
  unsigned __int64 v10; // x8
  unsigned __int64 v17; // x10

  if ( (a1[41] & 1) == 0 )
  {
    v1 = a1[229];
    if ( (v1 & 0x2000) == 0 )
    {
      ipc_log_string(icnss_ipc_log_context, "HW Power off: 0x%lx\n", v1);
      raw_spin_lock(a1 + 269);
      if ( (a1[229] & 2) != 0 )
      {
        _X8 = a1 + 229;
        __asm { PRFM            #0x11, [X8] }
        do
          v17 = __ldxr(_X8);
        while ( __stxr(v17 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        raw_spin_unlock(a1 + 269);
        for ( i = a1[30]; (_QWORD *)i != a1 + 29; i = *(_QWORD *)(i + 8) )
        {
          v6 = *(_QWORD *)(i + 16);
          if ( v6 && v6 <= 0xFFFFFFFFFFFFF000LL )
          {
            v7 = *(const char **)(i + 24);
            if ( *(_DWORD *)(i + 40) )
            {
              ipc_log_string(icnss_ipc_log_context, "Clock %s is being disabled\n", v7);
              v5 = *(_QWORD *)(i + 16);
              clk_disable(v5);
              clk_unprepare(v5);
              *(_DWORD *)(i + 40) = 0;
            }
            else
            {
              ipc_log_string(icnss_ipc_log_context, "Clock %s is already disabled\n", v7);
            }
          }
        }
        v8 = (_QWORD *)a1[28];
        v9 = a1 + 27;
        while ( v8 != v9 )
        {
          v10 = v8[2];
          if ( v10 && v10 <= 0xFFFFFFFFFFFFF000LL )
            icnss_vreg_off_single(v8);
          v8 = (_QWORD *)v8[1];
        }
      }
      else
      {
        raw_spin_unlock(a1 + 269);
      }
    }
  }
  return 0;
}
