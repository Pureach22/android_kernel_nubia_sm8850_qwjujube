__int64 __fastcall extract_peer_adv_stats_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x8
  unsigned int v12; // w9
  __int64 v13; // x12
  __int64 v14; // x13

  v11 = *(_QWORD *)(a10 + 80);
  if ( v11 )
  {
    if ( *(_DWORD *)(a10 + 88) )
    {
      v12 = 0;
      do
      {
        v13 = v11 + 44LL * (int)v12;
        v14 = a11 + 24LL * (int)v12++;
        *(_WORD *)v14 = *(_DWORD *)(v13 + 4);
        *(_BYTE *)(v14 + 2) = *(_WORD *)(v13 + 6);
        *(_BYTE *)(v14 + 3) = *(_BYTE *)(v13 + 7);
        *(_WORD *)(v14 + 4) = *(_DWORD *)(v13 + 8);
        *(_DWORD *)(v14 + 8) = *(_DWORD *)(v13 + 20);
        *(_QWORD *)(v14 + 16) = *(_QWORD *)(v13 + 12);
        *(_DWORD *)(v14 + 12) = *(_DWORD *)(v13 + 24);
      }
      while ( v12 < *(_DWORD *)(a10 + 88) );
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: no peer_adv stats in event buffer",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_peer_adv_stats_tlv");
    return 4;
  }
}
