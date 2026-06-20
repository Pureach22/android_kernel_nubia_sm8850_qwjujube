__int64 __fastcall wlan_find_mlpeer_link_mac_addr(
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x6
  __int64 v23; // x7
  int v24; // w8
  int v25; // w9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v35; // x6
  __int64 v36; // x7
  int v37; // w8
  int v38; // w9
  __int64 v41; // [xsp+0h] [xbp-10h]
  __int64 v42; // [xsp+0h] [xbp-10h]
  __int64 v43; // [xsp+8h] [xbp-8h]

  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: MLD ID %d ML Peer mac %02x:%02x:%02x:**:**:%02x",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_find_mlpeer_link_mac_addr",
    *(unsigned __int8 *)(a1 + 16),
    *(unsigned __int8 *)(a2 + 104),
    *(unsigned __int8 *)(a2 + 105),
    *(unsigned __int8 *)(a2 + 106),
    *(unsigned __int8 *)(a2 + 109));
  if ( a2 == -24 )
  {
    v24 = 0;
    v22 = 0;
    v23 = 0;
    v25 = 0;
  }
  else
  {
    v22 = *(unsigned __int8 *)(a2 + 24);
    v23 = *(unsigned __int8 *)(a2 + 25);
    v24 = *(unsigned __int8 *)(a2 + 26);
    v25 = *(unsigned __int8 *)(a2 + 29);
  }
  LODWORD(v41) = v24;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: MLD ID %d, index %d ML Peer exists with mac %02x:%02x:%02x:**:**:%02x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wlan_find_mlpeer_link_mac_addr",
    0,
    *(unsigned __int8 *)(a1 + 16),
    v22,
    v23,
    v41,
    v25);
  if ( *(_DWORD *)(a3 + 8) != *(_DWORD *)(a2 + 24) || *(unsigned __int16 *)(a3 + 12) != *(unsigned __int16 *)(a2 + 28) )
  {
    if ( a2 == -64 )
    {
      v37 = 0;
      v35 = 0;
      v36 = 0;
      v38 = 0;
    }
    else
    {
      v35 = *(unsigned __int8 *)(a2 + 64);
      v36 = *(unsigned __int8 *)(a2 + 65);
      v37 = *(unsigned __int8 *)(a2 + 66);
      v38 = *(unsigned __int8 *)(a2 + 69);
    }
    LODWORD(v43) = v38;
    LODWORD(v42) = v37;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLD ID %d, index %d ML Peer exists with mac %02x:%02x:%02x:**:**:%02x",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_find_mlpeer_link_mac_addr",
      1,
      *(unsigned __int8 *)(a1 + 16),
      v35,
      v36,
      v42,
      v43);
    if ( *(_DWORD *)(a3 + 8) != *(_DWORD *)(a2 + 64) || *(unsigned __int16 *)(a3 + 12) != *(unsigned __int16 *)(a2 + 68) )
      return 17;
  }
  *(_QWORD *)a3 = a2;
  return 0;
}
