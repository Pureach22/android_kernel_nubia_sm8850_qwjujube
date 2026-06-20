__int64 __fastcall populate_dot11f_beacon_report(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  char v7; // w9
  char v8; // w8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int16 v17; // w9
  __int16 v18; // w9
  __int16 v19; // w9
  char v20; // w6
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  *(_BYTE *)(a2 + 4) = *(_BYTE *)a3;
  *(_BYTE *)(a2 + 5) = *(_BYTE *)(a3 + 1);
  qdf_mem_copy((void *)(a2 + 8), (const void *)(a3 + 2), 8u);
  v7 = *(_BYTE *)(a2 + 18);
  *(_WORD *)(a2 + 16) = *(unsigned __int8 *)(a3 + 10);
  v8 = *(_BYTE *)(a3 + 11);
  *(_BYTE *)(a2 + 18) = v7 & 0x80 | v8 & 0x7F;
  *(_BYTE *)(a2 + 18) = v8 & 0x7F | ((*(_BYTE *)(a3 + 12) == 0) << 7);
  *(_BYTE *)(a2 + 19) = *(_BYTE *)(a3 + 14);
  *(_BYTE *)(a2 + 20) = *(_BYTE *)(a3 + 13);
  qdf_mem_copy((void *)(a2 + 21), (const void *)(a3 + 15), 6u);
  *(_BYTE *)(a2 + 27) = *(_BYTE *)(a3 + 21);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a3 + 24);
  if ( *(_BYTE *)(a3 + 28) )
  {
    *(_BYTE *)(a2 + 32) = 1;
    qdf_mem_copy((void *)(a2 + 34), (const void *)(a3 + 34), *(unsigned __int8 *)(a3 + 28));
    *(_BYTE *)(a2 + 33) = *(_BYTE *)(a3 + 28);
  }
  if ( *(_BYTE *)(a3 + 29) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Including Last Beacon Report in RRM Frame",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "populate_dot11f_beacon_report");
    v17 = *(unsigned __int8 *)(a2 + 260);
    *(_BYTE *)(a2 + 258) = 1;
    v18 = *(unsigned __int8 *)(a3 + 31) | (unsigned __int16)(v17 << 8);
    *(_WORD *)(a2 + 259) = v18;
    v19 = v18 & 0x80FF | ((*(_BYTE *)(a3 + 32) & 0x7F) << 8);
    *(_WORD *)(a2 + 259) = v19;
    v20 = *(_BYTE *)(a3 + 33);
    *(_BYTE *)(a2 + 262) = 1;
    *(_BYTE *)(a2 + 263) = a4 & 1;
    *(_WORD *)(a2 + 259) = v19 & 0x7FFF | ((v20 & 1) << 15);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: id %d frag_id %d more_frags %d is_last_frame %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "populate_dot11f_beacon_report");
  }
  return 0;
}
