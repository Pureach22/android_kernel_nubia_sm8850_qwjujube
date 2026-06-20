__int64 __fastcall drv_cmd_bt_coex_mode(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w8
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19

  v11 = *(unsigned __int8 *)(a3 + 11);
  if ( v11 == 50 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: BTCOEXMODE %d", a4, a5, a6, a7, a8, a9, a10, a11, "drv_cmd_bt_coex_mode", 50);
    *(_BYTE *)(a2 + 913) = 0;
    return 0;
  }
  else if ( v11 == 49 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: BTCOEXMODE %d", a4, a5, a6, a7, a8, a9, a10, a11, "drv_cmd_bt_coex_mode", 49);
    *(_BYTE *)(a2 + 913) = 1;
    result = wlan_hdd_scan_abort(a1);
    if ( (result & 0x80000000) != 0 )
    {
      v23 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to abort existing scan status: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "drv_cmd_bt_coex_mode",
        (unsigned int)result);
      return v23;
    }
  }
  else
  {
    return 0;
  }
  return result;
}
