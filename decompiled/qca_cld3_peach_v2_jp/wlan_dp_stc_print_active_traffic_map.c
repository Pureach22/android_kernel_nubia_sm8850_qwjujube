__int64 __fastcall wlan_dp_stc_print_active_traffic_map(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 v10; // x22
  __int64 v11; // x23
  __int64 v12; // [xsp+0h] [xbp-30h]
  __int64 v13; // [xsp+8h] [xbp-28h]
  __int64 v14; // [xsp+10h] [xbp-20h]
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]

  v9 = *(_QWORD *)(result + 2936);
  if ( v9 )
  {
    v10 = 64;
    v11 = *(_QWORD *)(result + 2936);
    do
    {
      if ( *(_BYTE *)(v11 + 262) )
      {
        if ( (*(_BYTE *)(v9 + 148) & 4) != 0 )
        {
          LODWORD(v13) = *(_DWORD *)(v11 + 320);
          LODWORD(v14) = *(_DWORD *)(v11 + 324);
          LODWORD(v12) = *(_DWORD *)(v11 + 316);
          LODWORD(v15) = ((unsigned int)*(_QWORD *)(v11 + 336) >> 2) & 1;
          LODWORD(v16) = ((unsigned int)*(_QWORD *)(v11 + 336) >> 1) & 1;
          result = qdf_trace_msg(
                     0x45u,
                     5u,
                     "%s: STC: peer_id %u bursty traffic: [%u %u %u] RT traffic: [%u %u %u] non flow traffic: [%u %u]",
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     "wlan_dp_stc_print_peer_active_traffic_map",
                     *(unsigned __int16 *)(v11 + 266),
                     *(unsigned int *)(v11 + 312),
                     *(unsigned int *)(v11 + 328),
                     *(unsigned int *)(v11 + 332),
                     v12,
                     v13,
                     v14,
                     v15,
                     v16);
        }
      }
      --v10;
      v11 += 96;
    }
    while ( v10 );
  }
  return result;
}
