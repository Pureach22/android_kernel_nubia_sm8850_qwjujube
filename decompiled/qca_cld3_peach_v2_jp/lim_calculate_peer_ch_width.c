__int64 __fastcall lim_calculate_peer_ch_width(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x0
  unsigned int max_peer_ch_width; // w20
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x0
  int peer_indicated_ch_width; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  unsigned int v33; // w21
  unsigned int v34; // w9
  __int64 v36; // [xsp+18h] [xbp-28h] BYREF
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  int v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 16);
  v39 = 0;
  v37 = 0;
  v38 = 0;
  v7 = *(_QWORD *)(v6 + 152);
  v36 = 0;
  if ( v7 )
    v8 = *(_QWORD *)(v7 + 80);
  else
    v8 = 0;
  max_peer_ch_width = wlan_mlme_get_max_peer_ch_width(v8, a2);
  qdf_mem_copy(&v36, a2, 6u);
  v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 152LL);
  if ( v18 )
    v19 = *(_QWORD *)(v18 + 80);
  else
    v19 = 0;
  peer_indicated_ch_width = wlan_mlme_get_peer_indicated_ch_width(
                              v19,
                              (unsigned __int8 *)&v36,
                              v10,
                              v11,
                              v12,
                              v13,
                              v14,
                              v15,
                              v16,
                              v17);
  if ( a2 )
  {
    v29 = *a2;
    v30 = a2[1];
    v31 = a2[2];
    v32 = a2[5];
  }
  else
  {
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v32 = 0;
  }
  if ( peer_indicated_ch_width )
    v33 = a3;
  else
    v33 = v38;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Peer: %02x:%02x:%02x:**:**:%02x dot11 max bw %d, peer updated bw %d, new target bw %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "lim_calculate_peer_ch_width",
    v29,
    v30,
    v31,
    v32,
    max_peer_ch_width,
    v33,
    a3,
    v36,
    v37);
  _ReadStatusReg(SP_EL0);
  if ( v33 >= a3 )
    v34 = a3;
  else
    v34 = v33;
  if ( max_peer_ch_width >= v34 )
    return v34;
  else
    return max_peer_ch_width;
}
