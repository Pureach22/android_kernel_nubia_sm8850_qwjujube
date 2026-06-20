__int64 __fastcall populate_dot11f_chan_load_report(__int64 a1, __int64 a2, __int64 a3)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8
  int v15; // [xsp+0h] [xbp-10h]

  *(_BYTE *)(a2 + 4) = *(_BYTE *)a3;
  *(_BYTE *)(a2 + 5) = *(_BYTE *)(a3 + 1);
  qdf_mem_copy((void *)(a2 + 8), (const void *)(a3 + 8), 8u);
  *(_WORD *)(a2 + 16) = *(_WORD *)(a3 + 16);
  v13 = *(unsigned __int8 *)(a3 + 18);
  *(_BYTE *)(a2 + 18) = v13;
  if ( *(_BYTE *)(a3 + 23) )
  {
    *(_BYTE *)(a2 + 19) = 1;
    *(_BYTE *)(a2 + 20) = *(_BYTE *)(a3 + 24);
    *(_BYTE *)(a2 + 21) = *(_BYTE *)(a3 + 25);
    *(_BYTE *)(a2 + 22) = *(_BYTE *)(a3 + 26);
  }
  if ( *(_BYTE *)(a3 + 19) == 1 )
  {
    *(_BYTE *)(a2 + 23) = 1;
    *(_WORD *)(a2 + 24) = *(_WORD *)(a2 + 24) & 0xF8FF | ((*(_BYTE *)(a3 + 20) & 7) << 8);
    *(_BYTE *)(a2 + 26) = *(_BYTE *)(a3 + 21);
    *(_BYTE *)(a2 + 27) = *(_BYTE *)(a3 + 22);
  }
  v15 = v13;
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: regClass %d chan %d meas_time %lu meas_dur %d, chan_load %d",
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           "populate_dot11f_chan_load_report",
           *(unsigned __int8 *)(a2 + 4),
           *(unsigned __int8 *)(a2 + 5),
           *(_QWORD *)(a3 + 8),
           v15);
}
