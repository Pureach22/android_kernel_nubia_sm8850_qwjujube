bool __fastcall nan_is_disc_active(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v20; // x2
  const char *v21; // x3
  __int64 v22; // x0

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( comp_private_obj )
    {
      if ( *(_DWORD *)(comp_private_obj + 272) == 2 )
        return 1;
    }
    else
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: nan psoc priv object is NULL",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "nan_get_discovery_state");
    }
    v22 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( v22 )
      return *(_DWORD *)(v22 + 272) == 1;
    v20 = "%s: nan psoc priv object is NULL";
    v21 = "nan_get_discovery_state";
  }
  else
  {
    v20 = "%s: psoc object object is NULL";
    v21 = "nan_is_disc_active";
  }
  qdf_trace_msg(0x53u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, v21);
  return 0;
}
