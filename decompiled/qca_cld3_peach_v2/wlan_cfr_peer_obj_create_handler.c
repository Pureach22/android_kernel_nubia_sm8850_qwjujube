__int64 __fastcall wlan_cfr_peer_obj_create_handler(
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
  __int64 v10; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v21; // x2
  _QWORD *v22; // x0

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 96);
    if ( v9 && (v10 = *(_QWORD *)(v9 + 216)) != 0 )
    {
      if ( (wlan_cfr_is_feature_disabled(v10) & 1) != 0 )
      {
        qdf_trace_msg(
          0x6Au,
          8u,
          "%s: cfr is disabled",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wlan_cfr_peer_obj_create_handler");
        return 11;
      }
      v22 = (_QWORD *)_qdf_mem_malloc(0x18u, "wlan_cfr_peer_obj_create_handler", 434);
      if ( v22 )
      {
        *v22 = a1;
        wlan_objmgr_peer_component_obj_attach(a1, 0x1Eu, (__int64)v22, 0);
        return 0;
      }
      v21 = "%s: Failed to allocate peer_cfr object\n";
    }
    else
    {
      v21 = "%s: PDEV is NULL\n";
    }
  }
  else
  {
    v21 = "%s: PEER is NULL\n";
  }
  qdf_trace_msg(0x6Au, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfr_peer_obj_create_handler");
  return 16;
}
