__int64 __fastcall p2p_status_disconnect(
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
  __int64 comp_private_obj; // x0
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w9
  const char *v23; // x2
  const char *v24; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 216);
    if ( v9 && (v10 = *(_QWORD *)(v9 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 5u);
      if ( comp_private_obj )
      {
        if ( *(_DWORD *)(a1 + 16) == 2 )
        {
          v13 = comp_private_obj;
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: connection status:%d",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "p2p_status_disconnect",
            *(unsigned int *)(comp_private_obj + 276));
          v22 = *(_DWORD *)(v13 + 276);
          if ( v22 == 8 )
          {
            v23 = "%s: [P2P State] P2P Client is removed and moved to inactive state";
            *(_DWORD *)(v13 + 276) = 0;
            goto LABEL_15;
          }
          if ( v22 == 5 )
          {
            v23 = "%s: [P2P State] 8 way Handshake completed and moved to disconnected state";
            *(_DWORD *)(v13 + 276) = 6;
LABEL_15:
            qdf_trace_msg(0x4Eu, 8u, v23, v14, v15, v16, v17, v18, v19, v20, v21, "p2p_status_disconnect");
          }
        }
        return 0;
      }
      v24 = "%s: P2P soc context is NULL";
    }
    else
    {
      v24 = "%s: soc context is NULL";
    }
  }
  else
  {
    v24 = "%s: vdev context passed is NULL";
  }
  qdf_trace_msg(0x4Eu, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "get_p2p_soc_obj_by_vdev");
  qdf_trace_msg(
    0x4Eu,
    2u,
    "%s: P2P soc context is NULL",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "p2p_status_disconnect");
  return 16;
}
