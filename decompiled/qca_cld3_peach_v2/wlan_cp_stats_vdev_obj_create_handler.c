__int64 __fastcall wlan_cp_stats_vdev_obj_create_handler(
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
  __int64 v21; // x0
  __int64 comp_private_obj; // x0
  __int64 v23; // x21
  unsigned int (__fastcall *v24)(_QWORD); // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  void (__fastcall *v35)(_QWORD); // x8

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x30u, "wlan_cp_stats_vdev_obj_create_handler", 454);
    if ( v10 )
    {
      v19 = *(_QWORD *)(a1 + 216);
      v20 = (_QWORD *)v10;
      if ( v19
        && (v21 = *(_QWORD *)(v19 + 80)) != 0
        && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v21, 0x1Bu)) != 0 )
      {
        *v20 = a1;
        v23 = comp_private_obj;
        v24 = *(unsigned int (__fastcall **)(_QWORD))(comp_private_obj + 112);
        if ( !v24 )
          goto LABEL_16;
        if ( *((_DWORD *)v24 - 1) != 227644975 )
          __break(0x8228u);
        if ( v24(v20) )
        {
          qdf_trace_msg(
            0x62u,
            2u,
            "%s: Failed to initialize vdev handlers",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "wlan_cp_stats_vdev_obj_create_handler");
          v33 = 16;
        }
        else
        {
LABEL_16:
          v33 = wlan_objmgr_vdev_component_obj_attach(a1, 0x1Bu, (__int64)v20, 0);
          if ( !v33 )
            goto LABEL_15;
        }
        v35 = *(void (__fastcall **)(_QWORD))(v23 + 120);
        if ( v35 )
        {
          if ( *((_DWORD *)v35 - 1) != 227644975 )
            __break(0x8228u);
          v35(v20);
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
          "wlan_cp_stats_vdev_obj_create_handler");
        v33 = 4;
      }
      _qdf_mem_free((__int64)v20);
    }
    else
    {
      v33 = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: vdev is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cp_stats_vdev_obj_create_handler");
    v33 = 4;
  }
LABEL_15:
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: vdev cp stats object attach",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wlan_cp_stats_vdev_obj_create_handler");
  return v33;
}
