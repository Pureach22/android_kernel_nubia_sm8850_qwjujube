__int64 __fastcall dp_rx_mlo_peer_unmap_handler(
        _DWORD *a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w19
  int v12; // w21
  int v13; // w22
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-10h] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v11 = a2;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a1[3333];
  v13 = a1[3332];
  WORD2(v15) = 0;
  LODWORD(v15) = 0;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: MLO peer_unmap_event (soc:%pK) peer_id %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_rx_mlo_peer_unmap_handler",
    a1,
    a2,
    v15,
    v16);
  if ( a1 )
    ++a1[4394];
  result = dp_rx_peer_unmap_handler((__int64)a1, (1 << v13) | v12 & v11, 0xFFu, (unsigned __int8 *)&v15, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
