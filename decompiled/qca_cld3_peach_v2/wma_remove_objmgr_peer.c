__int64 __fastcall wma_remove_objmgr_peer(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x0
  _QWORD *peer; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6

  v11 = *(_QWORD *)(a1 + 24);
  if ( !v11 )
    return qdf_trace_msg(0x36u, 2u, "%s: PSOC is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "wma_remove_objmgr_peer");
  peer = wlan_objmgr_get_peer(v11, *(_BYTE *)(*(_QWORD *)(a2 + 216) + 40LL), a3, 8u);
  if ( peer )
  {
    v22 = (__int64)peer;
    wlan_objmgr_peer_obj_delete((__int64)peer, v14, v15, v16, v17, v18, v19, v20, v21);
    return wlan_objmgr_peer_release_ref(v22, 8u, v23, v24, v25, v26, v27, v28, v29, v30);
  }
  else
  {
    if ( a3 )
    {
      v32 = *a3;
      v33 = a3[1];
      v34 = a3[2];
      v35 = a3[5];
    }
    else
    {
      v34 = 0;
      v32 = 0;
      v33 = 0;
      v35 = 0;
    }
    return qdf_trace_msg(
             0x36u,
             2u,
             "Peer %02x:%02x:%02x:**:**:%02x not found",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v32,
             v33,
             v34,
             v35);
  }
}
