__int64 __fastcall lim_populate_mac_header(__int64 a1, __int64 a2, char a3, char a4, const void *a5, _BYTE *a6)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w9
  __int16 v19; // w9
  __int64 v20; // x5

  *(_BYTE *)a2 = (4 * (a3 & 3)) | (16 * a4);
  qdf_mem_copy((void *)(a2 + 4), a5, 6u);
  *(_BYTE *)(a2 + 10) = *a6;
  *(_BYTE *)(a2 + 11) = a6[1];
  *(_BYTE *)(a2 + 12) = a6[2];
  *(_BYTE *)(a2 + 13) = a6[3];
  *(_BYTE *)(a2 + 14) = a6[4];
  *(_BYTE *)(a2 + 15) = a6[5];
  qdf_mem_copy((void *)(a2 + 16), a5, 6u);
  v18 = *(unsigned __int16 *)(a1 + 21532);
  if ( v18 <= 0xFFE )
    v19 = v18 + 1;
  else
    v19 = 2048;
  *(_WORD *)(a1 + 21532) = v19;
  *(_WORD *)(a2 + 22) = (16 * (v19 & 0xF)) | *(_WORD *)(a2 + 22) & 0xFF0F;
  v20 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
  *(_WORD *)(a2 + 22) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v19 & 0xF));
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           "lim_populate_mac_header",
           v19 & 0xF,
           v20,
           *(unsigned __int16 *)(a1 + 21532),
           0);
}
