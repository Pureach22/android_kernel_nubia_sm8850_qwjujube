__int64 __fastcall wlan_cp_stats_psoc_obj_destroy_handler(
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
  __int64 *v19; // x19
  void (__fastcall *v20)(_QWORD); // x8
  __int64 v21; // x0
  void (__fastcall *v22)(_QWORD); // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w19

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu);
    if ( comp_private_obj )
    {
      v19 = (__int64 *)comp_private_obj;
      wlan_cp_stats_cstats_deinit();
      wlan_objmgr_psoc_component_obj_detach(a1, 0x1Bu, (__int64)v19);
      v20 = (void (__fastcall *)(_QWORD))v19[11];
      if ( v20 )
      {
        v21 = v19[3];
        if ( *((_DWORD *)v20 - 1) != -1169049694 )
          __break(0x8228u);
        v20(v21);
      }
      _qdf_mem_free(v19[3]);
      v22 = (void (__fastcall *)(_QWORD))v19[9];
      if ( v22 )
      {
        if ( *((_DWORD *)v22 - 1) != -709288359 )
          __break(0x8228u);
        v22(v19);
      }
      _qdf_mem_free((__int64)v19);
      qdf_trace_msg(
        0x62u,
        8u,
        "%s: cp stats context detached at psoc",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_cp_stats_psoc_obj_destroy_handler");
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: cp_stats context is NULL!",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_cp_stats_psoc_obj_destroy_handler");
      return 4;
    }
  }
  else
  {
    v31 = 2;
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: PSOC is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cp_stats_psoc_obj_destroy_handler");
  }
  return v31;
}
