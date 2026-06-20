__int64 __fastcall wlan_cfr_peer_obj_destroy_handler(
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
  __int64 comp_private_obj; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v21; // x0
  __int64 v22; // x21

  if ( !a1 )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: PEER is NULL\n", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfr_peer_obj_destroy_handler");
    return 16;
  }
  v9 = *(_QWORD *)(a1 + 96);
  if ( !v9 )
  {
    comp_private_obj = 0;
    if ( (wlan_cfr_is_feature_disabled(0) & 1) == 0 )
      goto LABEL_9;
LABEL_8:
    qdf_trace_msg(
      0x6Au,
      4u,
      "%s: cfr is disabled",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_cfr_peer_obj_destroy_handler");
    return 11;
  }
  comp_private_obj = *(_QWORD *)(v9 + 216);
  if ( (wlan_cfr_is_feature_disabled(comp_private_obj) & 1) != 0 )
    goto LABEL_8;
  if ( comp_private_obj )
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(comp_private_obj, 0x1Eu);
LABEL_9:
  v21 = wlan_objmgr_peer_get_comp_private_obj(a1, 0x1Eu);
  v22 = v21;
  if ( comp_private_obj && v21 )
  {
    if ( *(_DWORD *)(v21 + 12) )
    {
      if ( *(_BYTE *)(v21 + 8) )
        --*(_WORD *)(comp_private_obj + 42);
    }
    goto LABEL_15;
  }
  if ( v21 )
  {
LABEL_15:
    wlan_objmgr_peer_component_obj_detach(a1, 0x1Eu, v21);
    _qdf_mem_free(v22);
  }
  return 0;
}
