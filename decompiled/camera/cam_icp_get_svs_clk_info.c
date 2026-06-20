__int64 __fastcall cam_icp_get_svs_clk_info(__int64 a1)
{
  int v1; // w9
  unsigned int v2; // w8
  __int64 v3; // x9
  const char *v4; // x5
  __int64 v5; // x6
  __int64 v6; // x4
  __int64 v7; // x9
  __int64 v8; // x10
  int v9; // w9

  v1 = *(_DWORD *)(a1 + 44180);
  if ( (v1 & 4) != 0 )
  {
    v3 = **(_QWORD **)(*(_QWORD *)(a1 + 56) + 584LL * *(char *)(a1 + 70) + 16);
    if ( v3 )
      goto LABEL_7;
    v4 = "[%s] IPE dev intf is invalid";
    v5 = a1 + 112;
    v6 = 919;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_get_svs_clk_info",
      v6,
      v4,
      v5);
    return (unsigned int)-22;
  }
  if ( (v1 & 0x10) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_get_svs_clk_info",
      930,
      "[%s] No supported device to get svs clock info",
      (const char *)(a1 + 112));
    return (unsigned int)-19;
  }
  v3 = **(_QWORD **)(*(_QWORD *)(a1 + 56) + 584LL * *(char *)(a1 + 72) + 16);
  if ( !v3 )
  {
    v4 = "[%s] OFE dev inf is invalid";
    v5 = a1 + 112;
    v6 = 925;
    goto LABEL_14;
  }
LABEL_7:
  v7 = *(_QWORD *)(v3 + 112);
  v8 = *(unsigned int *)(v7 + 2892);
  if ( (unsigned int)v8 <= 0x1F )
  {
    v9 = *(_DWORD *)(v7 + 4 * v8 + 2120);
    if ( !v9 )
      v9 = 400000000;
    *(_QWORD *)(a1 + 44160) = v9;
    v2 = 0;
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_get_svs_clk_info",
        943,
        "[%s] icp_svs_clk = %lld",
        a1 + 112);
      return 0;
    }
    return v2;
  }
  __break(0x5512u);
  return cam_icp_mgr_free_hw_devs(a1);
}
