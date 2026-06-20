__int64 __fastcall qcom_geni_i3c_conf(__int64 a1, int a2)
{
  __int64 v3; // x22
  __int64 v4; // x21
  int *v5; // x20
  int v6; // w3
  int v7; // w4
  unsigned int v8; // w20
  int v9; // w8
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a1 + 20480;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v4 = *(_QWORD *)(a1 + 21304);
  else
    v4 = *(_QWORD *)(a1 + 21312);
  v11[0] = 0;
  v5 = (int *)(a1 + 21252);
  if ( (unsigned int)geni_se_clk_freq_match(a1, (unsigned int)(1000 * *(_DWORD *)(v4 + 4)), a1 + 21252, v11, 0) )
  {
    v6 = 0;
    *v5 = 0;
  }
  else
  {
    v6 = *v5;
  }
  v7 = *(_DWORD *)(v3 + 776);
  if ( v6 != v7 )
  {
    if ( *(_DWORD *)(a1 + 108) == 3 )
      *(_BYTE *)(v3 + 761) = 0;
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:dfs index:%d, prev_dfs_idx:%d\n", "qcom_geni_i3c_conf", v6, v7);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  if ( (*(_BYTE *)(v3 + 1172) & 1) != 0 )
    v11[0] = 19200000;
  v8 = clk_set_rate(*(_QWORD *)(a1 + 24));
  if ( v8 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:clock set rate failed:%d\n", "qcom_geni_i3c_conf", v8);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  else
  {
    v9 = *(_DWORD *)(a1 + 108);
    *(_DWORD *)(v3 + 776) = *(_DWORD *)(v3 + 772);
    if ( v9 != 3 )
    {
      ((void (*)(void))writel_relaxed)();
      writel_relaxed((16 * *(unsigned __int8 *)(v4 + 8)) | 1u, *(_QWORD *)a1 + 72LL);
      writel_relaxed(
        *(_DWORD *)(v4 + 16) | (*(unsigned __int8 *)(v4 + 9) << 20) | (*(unsigned __int8 *)(v4 + 10) << 10),
        *(_QWORD *)a1 + 632LL);
      writel_relaxed(*(unsigned __int8 *)(v4 + 12), *(_QWORD *)a1 + 636LL);
      writel_relaxed(*(unsigned __int8 *)(v4 + 11), *(_QWORD *)a1 + 616LL);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
