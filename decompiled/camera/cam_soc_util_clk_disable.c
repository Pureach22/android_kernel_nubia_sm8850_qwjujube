__int64 __fastcall cam_soc_util_clk_disable(__int64 a1, unsigned int a2, char a3, __int64 a4)
{
  const char *v4; // x21
  __int64 v5; // x23
  unsigned int v6; // w24
  _DWORD *v7; // x25
  _QWORD *v8; // x26
  int v9; // w27
  unsigned int v10; // w20
  __int64 v13; // x10
  int *v14; // x8
  __int64 *v15; // x9
  const char **v16; // x10
  unsigned int *v17; // x11
  __int64 result; // x0
  __int64 v19; // x10
  unsigned int v20; // w0
  const char *v21; // x5
  unsigned int v22; // w19
  __int64 v23; // x1
  __int64 v24; // x4
  unsigned int v25; // w0
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x9
  unsigned __int64 StatusReg; // x28
  __int64 v31; // x0
  __int64 v32; // x8
  _QWORD v33[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v34[3]; // [xsp+18h] [xbp-18h] BYREF

  v10 = a4;
  v34[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (a4 & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_clk_disable",
      2612,
      "Invalid param %d",
      a4);
    result = 4294967274LL;
    goto LABEL_41;
  }
  if ( (a3 & 1) != 0 )
  {
    if ( (unsigned int)a4 < 7 )
    {
      v13 = a1 + 8LL * (unsigned int)a4;
      v14 = (int *)(a1 + 3184);
      v15 = (__int64 *)(v13 + 3072);
      v16 = (const char **)(v13 + 3016);
      v17 = (unsigned int *)(a1 + 4LL * (unsigned int)a4 + 3156);
      goto LABEL_9;
    }
  }
  else if ( (unsigned int)a4 <= 0x1F )
  {
    v19 = a1 + 8LL * (unsigned int)a4;
    v14 = (int *)(a1 + 2792);
    v15 = (__int64 *)(v19 + 1128);
    v16 = (const char **)(v19 + 872);
    v17 = (unsigned int *)(a1 + 4LL * (unsigned int)a4 + 2664);
LABEL_9:
    v8 = &unk_393000;
    v5 = *v15;
    v6 = *v17;
    v9 = *v14;
    v7 = &unk_393000;
    v4 = *v16;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_disable",
        2628,
        "disable %s",
        *v16);
      if ( !v5 )
        goto LABEL_40;
    }
    else if ( !v5 )
    {
      goto LABEL_40;
    }
    if ( *(_DWORD *)(a1 + 2796) == v10 && *(_BYTE *)(a1 + 3309) == 1 )
      dev_pm_opp_set_rate(*(_QWORD *)(a1 + 8), 0);
    v34[0] = 0;
    v34[1] = 0;
    v33[0] = 0;
    v33[1] = 0;
    if ( (debug_bypass_drivers & 4) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x20000,
        2,
        "cam_wrapper_clk_disable_unprepare",
        426,
        "Bypass clk disable unprepare");
    }
    else
    {
      if ( clk_rgltr_bus_ops_profiling == 1 )
        ktime_get_real_ts64(v34);
      clk_disable(v5);
      clk_unprepare(v5);
      if ( clk_rgltr_bus_ops_profiling == 1 )
        ktime_get_real_ts64(v33);
    }
    goto LABEL_21;
  }
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v31 = _traceiter_cam_log_event(0, "ClkRegBusOpsProfile: clk_disable_unprepare (name, time taken in usec)", v4, a4);
    v32 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v32;
    if ( !v32 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v31);
  }
LABEL_21:
  if ( *(_DWORD *)(a1 + 2796) == v10 && a2 <= 2 && (*(_BYTE *)(a1 + 3200) & 1) != 0 )
  {
    v20 = cam_soc_util_set_cesta_clk_rate(
            a1,
            a2,
            0,
            0,
            (__int64 *)(a1 + 16LL * a2 + 2808),
            (__int64 *)(a1 + 16LL * a2 + 2816));
    if ( v20 )
    {
      v21 = "Failed in setting cesta clk rates[high low]:[0 0] client_idx:%d rc:%d";
      v22 = v20;
      v23 = 0x20000;
      v24 = 2651;
LABEL_28:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
        3,
        v23,
        1,
        "cam_soc_util_clk_disable",
        v24,
        v21,
        a2,
        v22);
      result = v22;
      goto LABEL_41;
    }
    v25 = cam_soc_util_cesta_channel_switch(a2, *(const char **)(a1 + 24));
    if ( v25 )
    {
      v21 = "Failed to apply power states for cesta_client_idx:%d rc:%d";
      v22 = v25;
      v23 = 0x8000;
      v24 = 2659;
      goto LABEL_28;
    }
    if ( clk_ops_profiling_hw_and_sw_voting != 1 )
    {
LABEL_40:
      result = 0;
      goto LABEL_41;
    }
  }
  if ( (v9 & (1 << v10)) != 0 )
  {
    v26 = v8[458];
    if ( (v26 & 0x20000) != 0 && !v7[919] )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v26 & 0x20000,
        4,
        "cam_soc_util_clk_disable",
        2669,
        "Dev %s clk %s Disabling Shared clk, set 0 rate",
        *(const char **)(a1 + 24),
        v4);
    cam_soc_util_clk_wrapper_set_clk_rate(v6, a1, v5, 0);
    goto LABEL_40;
  }
  if ( (*(_DWORD *)(a1 + 3568) & (1 << v10)) != 0 )
  {
    v27 = v8[458];
    if ( (v27 & 0x20000) != 0 && !v7[919] )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v27 & 0x20000,
        4,
        "cam_soc_util_clk_disable",
        2674,
        "Dev %s clk %s Disabling Aggregate clk, set 0 rate",
        *(const char **)(a1 + 24),
        v4);
    cam_soc_util_clk_aggregate_set_clk_rate(v6, a1, v5, 0, v10);
    goto LABEL_40;
  }
  v28 = *(_QWORD *)(a1 + 3192);
  result = 0;
  if ( v28 && !skip_mmrm_set_rate )
  {
    if ( *(_DWORD *)(a1 + 2796) == v10 )
    {
      v29 = v8[458];
      if ( (v29 & 0x20000) != 0 && !v7[919] )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v29 & 0x20000,
          4,
          "cam_soc_util_clk_disable",
          2680,
          "Dev %s Disabling %s clk, set 0 rate",
          *(const char **)(a1 + 24),
          v4);
        v28 = *(_QWORD *)(a1 + 3192);
      }
      cam_soc_util_set_sw_client_rate_through_mmrm(v28, *(unsigned __int8 *)(a1 + 32), 0, 0, 1);
    }
    goto LABEL_40;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
