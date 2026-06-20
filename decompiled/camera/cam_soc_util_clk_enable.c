__int64 __fastcall cam_soc_util_clk_enable(__int64 result, unsigned int a2, char a3, __int64 a4, unsigned int a5)
{
  const char *v5; // x19
  int v7; // w22
  __int64 v8; // x9
  __int64 v9; // x21
  __int64 v10; // x23
  __int64 v11; // x9
  __int64 v12; // x24
  unsigned int v14; // w0
  unsigned int v15; // w19
  unsigned int v16; // w0
  int v17; // w0
  unsigned int v18; // w19
  unsigned int v19; // w22
  unsigned int v20; // w20
  unsigned int v21; // w20
  unsigned __int64 StatusReg; // x21
  __int64 v23; // x8
  _QWORD v24[2]; // [xsp+18h] [xbp-28h] BYREF
  _QWORD v25[3]; // [xsp+28h] [xbp-18h] BYREF

  v7 = a4;
  v25[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result || (a4 & 0x80000000) != 0 || (int)a5 >= 10 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_clk_enable",
      2532,
      "Invalid param %d %d",
      a4,
      a5);
    result = 4294967274LL;
    goto LABEL_48;
  }
  if ( (a3 & 1) != 0 )
  {
    if ( (unsigned int)a4 < 7 )
    {
      v8 = result + 8LL * (unsigned int)a4;
      v9 = *(_QWORD *)(v8 + 3072);
      if ( a5 != -1 )
      {
        v10 = *(int *)(result + 4LL * (unsigned int)a4 + 3128);
        if ( !v9 )
          goto LABEL_23;
        goto LABEL_16;
      }
      v10 = 0;
      if ( v9 )
      {
LABEL_16:
        v5 = *(const char **)(v8 + 3016);
        goto LABEL_24;
      }
LABEL_23:
      result = 0;
      goto LABEL_48;
    }
  }
  else if ( (unsigned int)a4 <= 0x1F )
  {
    v11 = result + 8LL * (unsigned int)a4;
    v9 = *(_QWORD *)(v11 + 1128);
    v5 = *(const char **)(v11 + 872);
    if ( a5 == -1 )
    {
      v10 = 0;
      if ( !v9 )
        goto LABEL_23;
    }
    else
    {
      if ( a5 > 9 )
        goto LABEL_49;
      v10 = *(int *)(result + ((unsigned __int64)a5 << 7) + 4LL * (unsigned int)a4 + 1384);
      if ( !v9 )
        goto LABEL_23;
    }
    if ( *(_DWORD *)(result + 2796) == (_DWORD)a4 && a2 <= 2 && (*(_BYTE *)(result + 3200) & 1) != 0 )
    {
      v12 = result;
      v14 = cam_soc_util_set_cesta_clk_rate(
              result,
              a2,
              v10,
              v10,
              (__int64 *)(result + 16LL * a2 + 2808),
              (__int64 *)(result + 16LL * a2 + 2816));
      if ( v14 )
      {
        v15 = v14;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, unsigned int, unsigned int))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_clk_enable",
          2563,
          "[%s] Failed in setting cesta clk rates[high low]:[%ld %ld] client_idx:%d rc:%d",
          *(_QWORD *)(v12 + 24),
          v10,
          v10,
          a2,
          v14);
LABEL_26:
        result = v15;
        goto LABEL_48;
      }
      v17 = cam_soc_util_cesta_channel_switch(a2, *(const char **)(v12 + 24));
      if ( v17 )
      {
        v18 = v17;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_clk_enable",
          2571,
          "[%s] Failed to apply power states for cesta client:%d rc:%d",
          *(const char **)(v12 + 24),
          a2,
          v17);
        result = v18;
        goto LABEL_48;
      }
      if ( clk_ops_profiling_hw_and_sw_voting != 1 )
        goto LABEL_31;
      result = v12;
    }
LABEL_24:
    v12 = result;
    v16 = ((__int64 (__fastcall *)(__int64))cam_soc_util_set_clk_rate)(result);
    if ( v16 )
    {
      v15 = v16;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_enable",
        2583,
        "[%s] Failed in setting clk rate %ld rc:%d",
        *(_QWORD *)(v12 + 24),
        v10,
        v16);
      goto LABEL_26;
    }
LABEL_31:
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_enable",
        2588,
        "[%s] : clk enable %s",
        *(const char **)(v12 + 24),
        v5);
    if ( *(_DWORD *)(v12 + 2796) == v7 && *(_BYTE *)(v12 + 3309) == 1 )
      *(_DWORD *)(v12 + 2856) = a5;
    v25[0] = 0;
    v25[1] = 0;
    v24[0] = 0;
    v24[1] = 0;
    if ( (debug_bypass_drivers & 4) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x20000,
        2,
        "cam_wrapper_clk_prepare_enable",
        406,
        "Bypass clk prepare enable");
      result = 0;
      goto LABEL_48;
    }
    if ( clk_rgltr_bus_ops_profiling == 1 )
      ktime_get_real_ts64(v25);
    result = clk_prepare(v9);
    if ( !(_DWORD)result )
    {
      result = clk_enable(v9);
      if ( (_DWORD)result )
      {
        v19 = result;
        clk_unprepare(v9);
        result = v19;
      }
    }
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v20 = result;
      ktime_get_real_ts64(v24);
      result = v20;
    }
    goto LABEL_46;
  }
LABEL_49:
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    result = _traceiter_cam_log_event(0, "ClkRegBusOpsProfile: clk_prepare_enable (name, time taken in usec)", v5, a4);
    v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v23;
    if ( !v23 || (result = a5, !*(_QWORD *)(StatusReg + 16)) )
    {
      preempt_schedule_notrace(result);
      result = a5;
    }
  }
LABEL_46:
  if ( (_DWORD)result )
  {
    v21 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_clk_enable",
      2595,
      "enable failed for %s: rc(%d)",
      v5,
      result);
    result = v21;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
