__int64 __fastcall wlan_coex_config_updated(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x2
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 (__fastcall *v23)(_QWORD); // x8

  if ( !a1 )
  {
    v10 = "%s: NULL vdev";
LABEL_13:
    qdf_trace_msg(0x70u, 2u, v10, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_coex_config_updated");
    return 4;
  }
  if ( a2 )
  {
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: config type out of range: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_coex_config_updated",
      a2);
    return 4;
  }
  v11 = *(_QWORD *)(a1 + 216);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v10 = "%s: NULL psoc";
    goto LABEL_13;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v12, 0x21u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: %s:%u, Failed to get coex psoc object",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_psoc_get_coex_obj_fl",
      "wlan_coex_config_updated",
      162);
    return 4;
  }
  v23 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 8);
  if ( !v23 )
    return 0;
  if ( *((_DWORD *)v23 - 1) != 1263140689 )
    __break(0x8228u);
  return v23(a1);
}
