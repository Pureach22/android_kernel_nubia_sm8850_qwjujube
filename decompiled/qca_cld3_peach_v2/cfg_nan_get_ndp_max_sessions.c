__int64 __fastcall cfg_nan_get_ndp_max_sessions(
        __int64 a1,
        int *a2,
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
  int v20; // w8
  __int64 result; // x0

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: PSOC obj null", a3, a4, a5, a6, a7, a8, a9, a10, "cfg_nan_get_priv_obj");
    goto LABEL_5;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_5:
    qdf_trace_msg(0x53u, 2u, "%s: NAN obj null", v12, v13, v14, v15, v16, v17, v18, v19, "cfg_nan_get_ndp_max_sessions");
    result = 4;
    v20 = 8;
    goto LABEL_6;
  }
  v20 = *(_DWORD *)(comp_private_obj + 216);
  result = 0;
LABEL_6:
  *a2 = v20;
  return result;
}
