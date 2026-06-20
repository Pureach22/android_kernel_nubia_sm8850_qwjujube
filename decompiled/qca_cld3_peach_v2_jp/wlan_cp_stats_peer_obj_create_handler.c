__int64 __fastcall wlan_cp_stats_peer_obj_create_handler(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  _QWORD *v20; // x19
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 comp_private_obj; // x0
  __int64 v24; // x21
  unsigned int (__fastcall *v25)(_QWORD); // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  void (__fastcall *v36)(_QWORD); // x8

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x68u, "wlan_cp_stats_peer_obj_create_handler", 541);
    if ( v10 )
    {
      v19 = *(_QWORD *)(a1 + 88);
      v20 = (_QWORD *)v10;
      if ( v19
        && (v21 = *(_QWORD *)(v19 + 152)) != 0
        && (v22 = *(_QWORD *)(v21 + 80)) != 0
        && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v22, 0x1Bu)) != 0 )
      {
        *v20 = a1;
        v24 = comp_private_obj;
        v25 = *(unsigned int (__fastcall **)(_QWORD))(comp_private_obj + 128);
        if ( !v25 )
          goto LABEL_17;
        if ( *((_DWORD *)v25 - 1) != 1742559037 )
          __break(0x8228u);
        if ( v25(v20) )
        {
          qdf_trace_msg(
            0x62u,
            2u,
            "%s: Failed to initialize peer handlers",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "wlan_cp_stats_peer_obj_create_handler");
          v34 = 16;
        }
        else
        {
LABEL_17:
          v34 = wlan_objmgr_peer_component_obj_attach(a1, 0x1Bu, (__int64)v20, 0);
          if ( !v34 )
            goto LABEL_16;
        }
        v36 = *(void (__fastcall **)(_QWORD))(v24 + 136);
        if ( v36 )
        {
          if ( *((_DWORD *)v36 - 1) != 1742559037 )
            __break(0x8228u);
          v36(v20);
        }
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
          "wlan_cp_stats_peer_obj_create_handler");
        v34 = 4;
      }
      _qdf_mem_free((__int64)v20);
    }
    else
    {
      v34 = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: peer is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cp_stats_peer_obj_create_handler");
    v34 = 4;
  }
LABEL_16:
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: peer cp stats object attach",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wlan_cp_stats_peer_obj_create_handler");
  return v34;
}
