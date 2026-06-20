__int64 __fastcall wlan_twt_peer_obj_destroy_handler(
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
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v29; // x2

  if ( !a1 )
  {
    v29 = "%s: peer is NULL";
LABEL_8:
    qdf_trace_msg(0x96u, 2u, v29, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_twt_peer_obj_destroy_handler");
    return 4;
  }
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, 0x2Cu);
  if ( !comp_private_obj )
  {
    v29 = "%s: twt_peer_obj is NULL";
    goto LABEL_8;
  }
  v11 = comp_private_obj;
  qdf_mutex_destroy(comp_private_obj);
  if ( (unsigned int)wlan_objmgr_peer_component_obj_detach(a1, 0x2Cu, v11) )
    qdf_trace_msg(
      0x96u,
      3u,
      "%s: Failed to detach twt peer priv object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_twt_peer_obj_destroy_handler");
  _qdf_mem_free(v11);
  qdf_trace_msg(
    0x96u,
    8u,
    "%s: peer twt object detached",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "wlan_twt_peer_obj_destroy_handler");
  return 0;
}
