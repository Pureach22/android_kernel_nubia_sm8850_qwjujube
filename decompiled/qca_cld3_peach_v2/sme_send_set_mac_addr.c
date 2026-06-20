__int64 __fastcall sme_send_set_mac_addr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w21
  __int64 v14; // x22
  __int64 result; // x0
  int v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2

  if ( !a3 )
  {
    v34 = "%s: Invalid VDEV";
    goto LABEL_10;
  }
  v11 = *(_DWORD *)(a3 + 16);
  if ( v11 != 7 || (v14 = a2, result = wma_p2p_self_peer_remove(a3), a2 = v14, !(_DWORD)result) )
  {
    v16 = wlan_vdev_mlme_send_set_mac_addr(a1 & 0xFFFFFFFFFFFFLL, a2 & 0xFFFFFFFFFFFFLL);
    result = 4 * (unsigned int)(v16 != 0);
    if ( v11 == 7 )
    {
      if ( v16 )
      {
        if ( wlan_vdev_mlme_get_cmpt_obj(a3, v17, v18, v19, v20, v21, v22, v23, v24) )
        {
          v25 = wma_vdev_self_peer_create();
          if ( v25 )
            qdf_trace_msg(
              0x34u,
              2u,
              "Failed to create self peer for P2P device mode. Status:%d",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v25);
          return 4;
        }
        v34 = "%s: Invalid vdev MLME context";
LABEL_10:
        qdf_trace_msg(0x34u, 2u, v34, a4, a5, a6, a7, a8, a9, a10, a11, "sme_send_set_mac_addr");
        return 4;
      }
    }
  }
  return result;
}
