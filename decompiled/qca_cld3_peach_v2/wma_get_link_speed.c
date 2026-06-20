__int64 __fastcall wma_get_link_speed(__int64 *a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  bool v30; // zf
  int v31; // w13
  unsigned int v32; // w12
  __int64 v33; // x6
  __int64 v34; // x5
  __int64 v35; // x4
  int v36; // w10
  unsigned int v37; // w11
  __int64 v38; // x20
  __int64 v39; // x21
  __int64 v40; // x7

  if ( (unsigned int)_wma_validate_handle(a1, "wma_get_link_speed") )
    return 4;
  v12 = *a1;
  if ( (unsigned int)_wmi_validate_handle(v12, (__int64)"wma_get_link_speed", v4, v5, v6, v7, v8, v9, v10, v11) )
    return 4;
  if ( (wmi_service_enabled(v12, 0x45u, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0 )
  {
    v30 = a2 == nullptr;
    v31 = a2[4];
    v32 = *a2;
    if ( a2 )
      v33 = a2[2];
    else
      v33 = 0;
    if ( a2 )
      v34 = a2[1];
    else
      v34 = 0;
    if ( a2 )
      v35 = *a2;
    else
      v35 = 0;
    v36 = (a2[2] << 16) | (a2[1] << 8) | (a2[3] << 24);
    v37 = a2[5];
    v38 = v31 | (v37 << 8);
    v39 = v36 | v32;
    if ( v30 )
      v40 = 0;
    else
      v40 = v37;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: pLinkSpeed->peerMacAddr: %02x:%02x:%02x:**:**:%02x, peer_macaddr.mac_addr31to0: 0x%x, peer_macaddr.mac_addr47to32: 0x%x",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_get_link_speed",
      v35,
      v34,
      v33,
      v40,
      v36 | v32,
      v31 | (v37 << 8));
    return 16 * (unsigned int)((unsigned int)wmi_unified_get_link_speed_cmd(v12, v39 | (v38 << 32)) != 0);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Linkspeed feature bit not enabled Sending value 0 as link speed",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_get_link_speed");
    wma_send_link_speed(0);
    return 16;
  }
}
