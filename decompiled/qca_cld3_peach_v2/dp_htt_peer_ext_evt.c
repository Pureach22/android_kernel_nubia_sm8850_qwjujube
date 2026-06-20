__int64 __fastcall dp_htt_peer_ext_evt(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // w9
  unsigned int v12; // w8
  unsigned int v13; // w21
  unsigned int v14; // w20
  __int64 v15; // x4
  int v16; // w8
  int v17; // w11
  int v18; // w10
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  _QWORD v28[3]; // [xsp+28h] [xbp-18h] BYREF

  v11 = (_DWORD)a2 + 4;
  v28[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a2;
  v13 = a2[2];
  v28[1] = a2 + 1;
  v14 = HIWORD(v13) & 7;
  v15 = (unsigned __int16)(v12 >> 8);
  v28[0] = v15;
  BYTE2(v28[0]) = HIBYTE(v12);
  BYTE3(v28[0]) = BYTE2(v13) & 7;
  BYTE4(v28[0]) = (v13 & 0x80000) != 0;
  if ( a2 == (unsigned int *)-4LL )
  {
    v18 = 0;
    v16 = 0;
    v17 = 0;
  }
  else
  {
    v16 = *((unsigned __int8 *)a2 + 4);
    v11 = *((unsigned __int8 *)a2 + 5);
    v17 = BYTE1(v13);
    v18 = *((unsigned __int8 *)a2 + 6);
  }
  qdf_trace_msg(
    0x80u,
    5u,
    "%s: peer id %u, vdev id %u, link id %u, valid %u,peer_mac %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_htt_peer_ext_evt",
    v15,
    v16,
    v11,
    v18,
    v17);
  if ( (v13 & 0x80000) != 0 && v14 >= 4 )
    result = qdf_trace_msg(
               0x80u,
               2u,
               "%s: Invalid link_id %d, ignore PEER_EXTENDED_EVENT",
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               "dp_htt_peer_ext_evt",
               v14);
  else
    result = dp_rx_peer_ext_evt(*(_QWORD *)(a1 + 8), v28);
  _ReadStatusReg(SP_EL0);
  return result;
}
