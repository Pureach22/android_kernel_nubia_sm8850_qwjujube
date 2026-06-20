__int64 __fastcall ucfg_tdls_discovery_on_going(
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
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _BOOL4 v20; // w19
  const char *v21; // x2

  if ( !a1 )
  {
    v21 = "%s: NULL vdev";
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v21 = "%s: can't get psoc";
LABEL_8:
    qdf_trace_msg(0, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_get_tdls_soc_obj");
    return 0;
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(v10, 0xAu);
  if ( result )
  {
    v20 = (unsigned __int8)*(_DWORD *)(result + 620) != 0;
    qdf_trace_msg(
      0,
      8u,
      "%s: discovery req timer count %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_tdls_discovery_on_going",
      (unsigned __int8)*(_DWORD *)(result + 620));
    return v20;
  }
  return result;
}
