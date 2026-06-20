__int64 __fastcall mlme_get_peer_mic_len(
        __int64 a1,
        char a2,
        unsigned __int8 *a3,
        _BYTE *a4,
        unsigned __int8 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 peer; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  int peer_param; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8

  if ( !a3 || !a1 || !a4 || !a5 )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: psoc/mic_len/mic_hdr_len/peer_mac null",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "mlme_get_peer_mic_len");
    return 29;
  }
  peer = wlan_objmgr_get_peer(a1, a2, a3, 7u);
  if ( !peer )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: Peer of peer_mac %02x:%02x:%02x:**:**:%02x not found",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "mlme_get_peer_mic_len",
      *a3,
      a3[1],
      a3[2],
      a3[5]);
    return 4;
  }
  v25 = peer;
  peer_param = wlan_crypto_get_peer_param(peer, 1);
  wlan_objmgr_peer_release_ref(v25, 7u, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( peer_param < 0 )
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: Invalid mgmt cipher", v35, v36, v37, v38, v39, v40, v41, v42, "mlme_get_peer_mic_len");
    return 4;
  }
  *a5 = 8;
  if ( (peer_param & 0x600) != 0 )
    v43 = 16;
  else
    v43 = 8;
  *a4 = v43;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: peer %02x:%02x:%02x:**:**:%02x hdr_len %d mic_len %d key_cipher 0x%x",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "mlme_get_peer_mic_len",
    *a3,
    a3[1],
    a3[2],
    a3[5],
    *a5,
    v43,
    peer_param);
  return 0;
}
