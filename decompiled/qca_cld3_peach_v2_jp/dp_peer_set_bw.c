__int64 __fastcall dp_peer_set_bw(
        __int64 result,
        __int64 a2,
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
  __int64 v12; // x20
  __int64 v13; // x21
  __int64 v14; // x4
  __int64 v15; // x8

  if ( a2 )
  {
    if ( *(_DWORD *)(*(_QWORD *)a2 + 32LL) == 6 && *(_BYTE *)(*(_QWORD *)(result + 40) + 834LL) == 1 )
    {
      v12 = result;
      v13 = a2;
      dp_tx_ndp_update_bw_thresholds(a2, *(unsigned int *)(a2 + 2216), a3);
      result = v12;
      a2 = v13;
    }
    *(_DWORD *)(a2 + 2216) = a3;
    v14 = *(unsigned __int16 *)(a2 + 8);
    v15 = 809;
    if ( a3 - 3 < 2 )
      v15 = 810;
    *(_BYTE *)(a2 + 2220) = *(_BYTE *)(*(_QWORD *)(result + 40) + v15);
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: Peer id: %u: BW: %u, mpdu retry threshold: %u",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "dp_peer_set_bw",
             v14,
             a3);
  }
  return result;
}
