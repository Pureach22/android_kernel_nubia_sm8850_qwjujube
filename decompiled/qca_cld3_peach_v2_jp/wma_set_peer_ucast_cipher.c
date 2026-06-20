_QWORD *__fastcall wma_set_peer_ucast_cipher(
        unsigned __int8 *a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *result; // x0
  __int64 peer; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x6
  __int64 v34; // x7
  int v35; // w8
  int v36; // w9
  __int64 v37; // x4
  __int64 v38; // x5
  const char *v39; // x2
  unsigned int v40; // w1
  int v41; // [xsp+0h] [xbp-10h]
  int v42; // [xsp+8h] [xbp-8h]

  result = _cds_get_context(54, (__int64)"wma_set_peer_ucast_cipher", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( result )
  {
    peer = wlan_objmgr_get_peer(result[3], *(_BYTE *)(result[4] + 40LL), a1, 8u);
    if ( peer )
    {
      v24 = peer;
      wlan_crypto_set_peer_param(peer, 4, a3);
      wlan_crypto_set_peer_param(v24, 1, a2);
      wlan_objmgr_peer_release_ref(v24, 8u, v25, v26, v27, v28, v29, v30, v31, v32);
      if ( a1 )
      {
        v33 = *a1;
        v34 = a1[1];
        v35 = a1[2];
        v36 = a1[5];
      }
      else
      {
        v35 = 0;
        v33 = 0;
        v34 = 0;
        v36 = 0;
      }
      v39 = "%s: Set unicast cipher %x and cap %x for %02x:%02x:%02x:**:**:%02x";
      v40 = 8;
      v37 = a2;
      v38 = a3;
      v42 = v36;
      v41 = v35;
    }
    else
    {
      if ( a1 )
      {
        v37 = *a1;
        v38 = a1[1];
        v33 = a1[2];
        v34 = a1[5];
      }
      else
      {
        v33 = 0;
        v37 = 0;
        v38 = 0;
        v34 = 0;
      }
      v39 = "%s: Peer of peer_mac %02x:%02x:%02x:**:**:%02x not found";
      v40 = 2;
    }
    return (_QWORD *)qdf_trace_msg(
                       0x36u,
                       v40,
                       v39,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       "wma_set_peer_ucast_cipher",
                       v37,
                       v38,
                       v33,
                       v34,
                       v41,
                       v42);
  }
  return result;
}
