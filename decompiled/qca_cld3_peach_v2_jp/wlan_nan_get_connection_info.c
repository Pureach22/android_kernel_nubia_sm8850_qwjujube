__int64 __fastcall wlan_nan_get_connection_info(
        __int64 a1,
        _DWORD *a2,
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  int v23; // w8
  const char *v24; // x2

  if ( !a1 )
  {
    v24 = "%s: psoc obj is NULL";
LABEL_7:
    qdf_trace_msg(0x53u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_nan_get_connection_info");
    return 29;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( comp_private_obj )
  {
    if ( *(_DWORD *)(comp_private_obj + 272) == 2 )
    {
      v21 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
      if ( v21 )
      {
        a2[3] = *(_DWORD *)(v21 + 276);
        v23 = *(unsigned __int8 *)(v21 + 284);
        a2[4] = 0;
        a2[5] = v23;
        return 0;
      }
      v24 = "%s: psoc_nan_obj is null";
      goto LABEL_7;
    }
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "nan_get_discovery_state");
  }
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: NAN State needs to be Enabled",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wlan_nan_get_connection_info");
  return 4;
}
