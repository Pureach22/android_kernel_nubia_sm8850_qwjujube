const char *__fastcall ucfg_get_scan_requester_name(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x9
  __int64 v21; // x8
  const char *result; // x0
  __int64 v23; // x8
  int v24; // w9
  __int64 v25; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: null psoc", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_get_scan_requester_name");
    return "null";
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_get_scan_requester_name",
      632);
    return "null";
  }
  v20 = a2 & 0x1FFF;
  v21 = comp_private_obj;
  result = "unknown";
  if ( (unsigned int)v20 <= 0xC7 )
  {
    v23 = v21 + (v20 << 6);
    v24 = *(unsigned __int16 *)(v23 + 1824);
    v25 = v23 + 1826;
    if ( v24 == a2 )
      return (const char *)v25;
  }
  return result;
}
