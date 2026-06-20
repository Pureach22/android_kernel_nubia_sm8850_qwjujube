__int64 __fastcall cam_wrapper_clk_set_rate(__int64 a1, __int64 a2, char *s1, __int64 a4)
{
  __int64 v7; // x23
  __int64 v8; // x8
  __int64 v9; // x23
  int v10; // w8
  __int64 result; // x0
  const char *v12; // x6
  unsigned int v13; // w21
  unsigned __int64 StatusReg; // x21
  __int64 v15; // x0
  __int64 v16; // x8
  _QWORD v17[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v18[3]; // [xsp+18h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v18[1] = 0;
  v17[0] = 0;
  v17[1] = 0;
  if ( (debug_bypass_drivers & 4) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_clk_set_rate",
      264,
      "Bypass clk set rate");
    result = 0;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v7 = a1;
      ktime_get_real_ts64(v18);
      a1 = v7;
    }
    if ( *(_BYTE *)(a4 + 3309) != 1 )
      goto LABEL_7;
    v8 = *(unsigned int *)(a4 + 2796);
    if ( (unsigned int)v8 >= 0x20 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v15 = _traceiter_cam_log_event(0, "ClkRegBusOpsProfile: clk_set_rate (name, time taken in usec)", s1, a4);
        v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v16;
        if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v15);
      }
      goto LABEL_10;
    }
    v9 = a1;
    v10 = strcmp(s1, *(const char **)(a4 + 8 * v8 + 872));
    a1 = v9;
    if ( !v10 )
    {
      result = dev_pm_opp_set_rate(*(_QWORD *)(a4 + 8), a2);
      if ( (_DWORD)result )
      {
        v12 = *(const char **)(a4 + 24);
        v13 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_wrapper_clk_set_rate",
          286,
          "%s: Failed to set rate (%ul) to %s through OPP",
          v12,
          a2,
          s1);
        result = v13;
      }
      if ( clk_rgltr_bus_ops_profiling == 1 )
        goto LABEL_8;
    }
    else
    {
LABEL_7:
      result = clk_set_rate(a1, a2);
      if ( clk_rgltr_bus_ops_profiling == 1 )
      {
LABEL_8:
        LODWORD(a2) = result;
        ktime_get_real_ts64(v17);
LABEL_10:
        result = (unsigned int)a2;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
