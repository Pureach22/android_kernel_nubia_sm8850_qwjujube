__int64 __fastcall wlan_twt_peer_obj_create_handler(
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
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2

  if ( !a1 )
  {
    v20 = "%s: peer is NULL";
    goto LABEL_6;
  }
  v10 = _qdf_mem_malloc(0x60u, "wlan_twt_peer_obj_create_handler", 160);
  if ( !v10 )
    return 2;
  v11 = v10;
  qdf_mutex_create(v10);
  if ( (unsigned int)wlan_objmgr_peer_component_obj_attach(a1, 0x2Cu, v11, 0) )
  {
    qdf_mutex_destroy(v11);
    _qdf_mem_free(v11);
    v20 = "%s: peer twt object attach failed";
LABEL_6:
    qdf_trace_msg(0x96u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_twt_peer_obj_create_handler");
    return 16;
  }
  qdf_trace_msg(
    0x96u,
    8u,
    "%s: twt peer priv obj attach successful",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_twt_peer_obj_create_handler");
  return 0;
}
