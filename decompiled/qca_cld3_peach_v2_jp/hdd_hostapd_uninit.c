__int64 __fastcall hdd_hostapd_uninit(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  _DWORD *v19; // x19
  const char *v20; // x2
  unsigned int v21; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_hostapd_uninit", a1 + 296);
  if ( *(_DWORD *)(a1 + 2688) != 1885692259 )
  {
    v20 = "%s: Invalid magic";
LABEL_6:
    v21 = 2;
    return qdf_trace_msg(0x33u, v21, v20, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_hostapd_uninit");
  }
  v18 = *(_QWORD *)(a1 + 2712);
  if ( !v18 )
  {
    v20 = "%s: NULL hdd_ctx";
    goto LABEL_6;
  }
  v19 = (_DWORD *)(a1 + 2688);
  hdd_deinit_adapter(v18, v19, 1);
  v20 = "%s: exit";
  v21 = 8;
  *v19 = 0;
  return qdf_trace_msg(0x33u, v21, v20, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_hostapd_uninit");
}
