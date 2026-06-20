__int64 __fastcall msm_geni_serial_config_baud_rate(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x22
  unsigned __int64 v7; // x20
  int v8; // w8
  int v9; // w8
  unsigned __int64 v10; // x24
  int v11; // w0
  __int64 v12; // x5
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x8
  __int64 v15; // x0
  int v16; // w0
  __int64 v17; // x24
  __int64 v18; // x0
  int v19; // w23
  int v20; // w24
  int v21; // w25
  int v22; // w0
  unsigned int v23; // w8
  unsigned int v24; // w9
  unsigned int v25; // w23
  unsigned int v26; // w25
  unsigned int v27; // w24
  unsigned int v28; // w11
  unsigned int v29; // w10
  int v30; // w11
  int v31; // w10
  unsigned int v32; // w26
  unsigned int v33; // w27
  int v34; // w28
  unsigned int v35; // w0
  int v36; // w10
  _DWORD *v37; // x9
  int v38; // w8
  __int64 v39; // x21
  __int64 result; // x0
  __int64 v41; // x0
  int v42; // w24
  __int64 v43; // x0
  int v44; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v45[2]; // [xsp+10h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 968);
  v45[0] = 0;
  v44 = 0;
  if ( v6 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v7 = sched_clock(a1);
      ipc_log_string(v6, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_config_baud_rate", v7, v7 / 0x3E8);
    }
    else
    {
      v7 = 0;
    }
  }
  else
  {
    v7 = -22;
  }
  v8 = *(_DWORD *)(a1 + 1012);
  if ( v8 > 2 || v8 == 2 && *(int *)(a1 + 1016) >= 5 )
    v9 = 16;
  else
    v9 = 32;
  v10 = v9 * a3;
  v11 = geni_se_clk_freq_match(a1 + 712, v10, &v44, v45, 0);
  if ( v11 )
  {
    dev_err(
      *(_QWORD *)(a1 + 344),
      "%s: Failed(%d) to find src clk for 0x%x\n",
      "msm_geni_serial_config_baud_rate",
      v11,
      a3);
    if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
    {
      v43 = *(_QWORD *)(a1 + 960);
      *(_DWORD *)(a1 + 1120) = 3;
      ipc_log_string(v43, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 3);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
      result = 4294967274LL;
      goto LABEL_43;
    }
    goto LABEL_42;
  }
  v12 = v45[0];
  v13 = (v10 + v45[0] - 1) / v10;
  if ( (int)v13 < 1 )
  {
LABEL_42:
    result = 4294967274LL;
    goto LABEL_43;
  }
  v14 = v45[0] / (((v10 + v45[0] - 1) / v10) & 0x7FFFFFFF);
  if ( (_DWORD)v10 != (_DWORD)v14 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 960),
      "%s src_clk freq_diff:%d baud:%d clk_rate:%lu clk_div:%d\n",
      "msm_geni_serial_config_baud_rate",
      v10 - v14,
      a3,
      v45[0],
      v13);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s src_clk freq_diff:%d baud:%d clk_rate:%lu clk_div:%d\n");
    v12 = v45[0];
  }
  v15 = *(_QWORD *)(a1 + 648);
  *(_DWORD *)(a1 + 184) = v12;
  v16 = clk_set_rate(v15, v12);
  if ( v16 )
  {
    v42 = v16;
    dev_err(*(_QWORD *)(a1 + 344), "Error setting clock rate\n");
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: SE clock set_rate error:%d\n", "msm_geni_serial_config_baud_rate", v42);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: SE clock set_rate error:%d\n");
  }
  v17 = (int)((16 * v13) | 1);
  if ( a3 )
    uart_update_timeout(a1, *(unsigned int *)(a2 + 8), a3);
  v18 = *(_QWORD *)(a1 + 960);
  *(_QWORD *)(a1 + 1128) = v17;
  ipc_log_string(v18, "%s: enable:%d ser_clk_cfg:%lu\n", "msm_geni_enable_disable_se_clk", 1, v17);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: enable:%d ser_clk_cfg:%lu\n");
  writel_relaxed(*(_DWORD *)(a1 + 1128), (unsigned int *)(*(_QWORD *)(a1 + 16) + 72LL));
  writel_relaxed(*(_DWORD *)(a1 + 1128), (unsigned int *)(*(_QWORD *)(a1 + 16) + 76LL));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 72LL));
  v19 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 604LL));
  v20 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 676LL));
  v21 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 640LL));
  v22 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 680LL));
  v23 = *(_DWORD *)(a2 + 8);
  if ( (v23 & 0x100) != 0 )
  {
    v24 = v19 | 1;
    v25 = v21 | 0x10;
    v28 = v20 & 0xFFFFFFF8;
    v29 = v22 & 0xFFFFFFF8;
    if ( (v23 & 0x200) != 0 )
    {
      v26 = v28 | 3;
      v27 = v29 | 3;
    }
    else if ( (v23 & 0x40000000) != 0 )
    {
      v26 = v28 | 5;
      v27 = v29 | 5;
    }
    else
    {
      v27 = v29 | 1;
      v26 = v28 | 1;
    }
  }
  else
  {
    v24 = v19 & 0xFFFFFFFE;
    v25 = v21 & 0xFFFFFFEF;
    v26 = v20 & 0xFFFFFFFE;
    v27 = v22 & 0xFFFFFFFE;
  }
  v30 = *(_DWORD *)(a1 + 280);
  *(_DWORD *)(a1 + 280) = v30 & 0xFFFFFFF7;
  v31 = *(_DWORD *)(a2 + 8);
  v32 = ((unsigned int)v31 >> 5) & 2;
  if ( v31 < 0 )
  {
    v33 = v24 & 0xFFFFFFFD;
    *(_DWORD *)(a1 + 280) = v30 | 8;
  }
  else
  {
    v33 = v24 | 2;
  }
  v34 = (v23 >> 4) & 3;
  msm_geni_serial_set_manual_flow(v31 < 0, a1);
  v35 = *(_DWORD *)(a1 + 912);
  if ( *(_BYTE *)(a1 + 1136) == 1 )
  {
    v36 = *(_DWORD *)(a1 + 560);
    v37 = *(_DWORD **)(a1 + 1144);
    v37[6] = v13;
    v37[7] = 2228225;
    v38 = ((v35 & 1) << 8) | (8 * v32) | v34 | 0x1000480;
    v37[10] = v13;
    v37[11] = 2228225;
    v37[4] = v38;
    v37[5] = 0;
    v37[8] = v38;
    v37[9] = (v36 << 24) - 33554272;
    *(_QWORD *)(*(_QWORD *)(a1 + 1144) + 640LL) = a1;
    *(_QWORD *)(*(_QWORD *)(a1 + 1144) + 688LL) = a1;
    if ( (*(_DWORD *)(a2 + 8) & 0x80000000) == 0 )
      goto LABEL_34;
  }
  else
  {
    writel_relaxed(v35, (unsigned int *)(*(_QWORD *)(a1 + 16) + 556LL));
    writel_relaxed(v33, (unsigned int *)(*(_QWORD *)(a1 + 16) + 604LL));
    writel_relaxed(v26, (unsigned int *)(*(_QWORD *)(a1 + 16) + 676LL));
    writel_relaxed(v25, (unsigned int *)(*(_QWORD *)(a1 + 16) + 640LL));
    writel_relaxed(v27, (unsigned int *)(*(_QWORD *)(a1 + 16) + 680LL));
    writel_relaxed(v34 + 5, (unsigned int *)(*(_QWORD *)(a1 + 16) + 616LL));
    writel_relaxed(v34 + 5, (unsigned int *)(*(_QWORD *)(a1 + 16) + 652LL));
    writel_relaxed(v32, (unsigned int *)(*(_QWORD *)(a1 + 16) + 620LL));
    geni_se_config_packing(a1 + 712, (unsigned int)(v34 + 5), 4, 0, 1, 0);
    geni_se_config_packing(a1 + 712, (unsigned int)(v34 + 5), 4, 0, 0, 1);
    if ( (*(_DWORD *)(a2 + 8) & 0x80000000) == 0 )
      goto LABEL_34;
  }
  writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 16) + 684LL));
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Manual flow Disabled, HW Flow ON\n", "msm_geni_serial_termios_cfg");
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Manual flow Disabled, HW Flow ON\n");
LABEL_34:
  ipc_log_string(*(_QWORD *)(a1 + 960), "Tx: trans_cfg%d parity %d\n", v33, v26);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "Tx: trans_cfg%d parity %d\n");
  ipc_log_string(*(_QWORD *)(a1 + 960), "Rx: trans_cfg%d parity %d\n", v25, v27);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "Rx: trans_cfg%d parity %d\n");
  ipc_log_string(*(_QWORD *)(a1 + 960), "BitsChar%d stop bit%d\n", v34 + 5, v32);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "BitsChar%d stop bit%d\n");
  if ( (v33 & 2) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "Check : MSM CTS line signal is being ignored during Tx\n");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "Check : MSM CTS line signal is being ignored during Tx\n");
  }
  v39 = *(_QWORD *)(a1 + 968);
  if ( !v39 )
    goto LABEL_40;
  result = 0;
  if ( v7 && *(_DWORD *)(a1 + 916) )
  {
    v41 = sched_clock(0);
    ipc_log_string(
      v39,
      "%s:took %llu nsec(%llu usec)\n",
      "msm_geni_serial_config_baud_rate",
      v41 - v7,
      (v41 - v7) / 0x3E8);
LABEL_40:
    result = 0;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
