__int64 __fastcall cam_icp_soc_update_clk_rate(__int64 a1, unsigned int a2, unsigned int a3)
{
  const char *v3; // x5
  __int64 v4; // x4
  __int64 v5; // x8
  __int64 result; // x0
  unsigned int v7; // w19
  int v8; // w7
  unsigned int v9; // w20
  __int64 v10; // x6
  __int64 v11; // x19
  __int64 v12; // x21
  __int64 v13; // [xsp+18h] [xbp+18h]

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_soc_update_clk_rate",
      298,
      "Invalid soc_info");
    return 4294967274LL;
  }
  if ( a2 >= 0xA )
  {
    v3 = "clock level %d is not valid";
    v4 = 304;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_soc_update_clk_rate",
      v4,
      v3,
      a2);
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(a1 + a2 + 2860) & 1) == 0 )
  {
    v3 = "Clock level %d not supported";
    v4 = 311;
    goto LABEL_9;
  }
  v5 = *(unsigned int *)(a1 + 2796);
  if ( (unsigned int)v5 >= 0x20 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      2,
      "cam_icp_soc_update_clk_rate",
      318,
      "src_clk not defined for %s",
      *(const char **)(a1 + 24));
    return 4294967274LL;
  }
  v7 = *(_DWORD *)(a1 + ((unsigned __int64)a2 << 7) + 4 * v5 + 1384);
  if ( *(_BYTE *)(a1 + 2869) == 1 && (v8 = *(_DWORD *)(a1 + 2536 + 4 * v5)) != 0 && (int)v7 > v8 )
  {
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      v9 = a3;
      v13 = a1;
      v10 = v7;
      v11 = *(unsigned int *)(a1 + 2796);
      v12 = a1 + 2536;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_soc_update_clk_rate",
        328,
        "clk_rate %d greater than max, reset to %d",
        v10);
      a1 = v13;
      v7 = *(_DWORD *)(v12 + 4 * v11);
    }
    else
    {
      v9 = a3;
      v7 = *(_DWORD *)(a1 + 2536 + 4 * v5);
    }
  }
  else
  {
    v9 = a3;
  }
  result = cam_soc_util_set_src_clk_rate(a1, 0xFFFFFFFF, (int)v7, 0);
  if ( !(_DWORD)result )
  {
    hfi_send_freq_info(v9, v7);
    return 0;
  }
  return result;
}
