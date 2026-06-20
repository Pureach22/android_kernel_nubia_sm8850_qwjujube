__int64 __fastcall cfg_nan_get_ndp_inactivity_timeout(
        __int64 a1,
        _WORD *a2,
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
  __int64 v20; // x8

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( comp_private_obj )
    {
      v20 = comp_private_obj;
      *a2 = *(_WORD *)(v20 + 212);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: PSOC obj null", a3, a4, a5, a6, a7, a8, a9, a10, "cfg_nan_get_priv_obj");
  }
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: NAN obj null",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "cfg_nan_get_ndp_inactivity_timeout");
  return 4;
}
