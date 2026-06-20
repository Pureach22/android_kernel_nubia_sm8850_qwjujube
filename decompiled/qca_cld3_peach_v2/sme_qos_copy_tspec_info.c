__int64 __fastcall sme_qos_copy_tspec_info(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  int v12; // w9
  __int16 v13; // w8
  __int16 v14; // w8
  __int16 v15; // w8
  char v16; // w9
  __int16 v17; // w8
  __int16 v18; // w8

  *(_DWORD *)(a2 + 46) = *(_DWORD *)(a1 + 64);
  v12 = *(_DWORD *)(a1 + 36);
  *(_BYTE *)(a2 + 1) = 61;
  *(_DWORD *)(a2 + 18) = v12;
  *(_DWORD *)(a2 + 42) = *(_DWORD *)(a1 + 60);
  *(_WORD *)(a2 + 8) = *(_WORD *)(a1 + 26);
  *(_DWORD *)(a2 + 14) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a2 + 34) = *(_DWORD *)(a1 + 52);
  *(_WORD *)(a2 + 56) = *(_WORD *)(a1 + 74);
  *(_DWORD *)(a2 + 30) = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a2 + 50) = *(_DWORD *)(a1 + 68);
  *(_DWORD *)(a2 + 10) = *(_DWORD *)(a1 + 28);
  *(_WORD *)(a2 + 6) = *(_WORD *)(a1 + 24);
  *(_DWORD *)(a2 + 38) = *(_DWORD *)(a1 + 56);
  *(_WORD *)(a2 + 54) = *(_WORD *)(a1 + 72);
  *(_DWORD *)(a2 + 22) = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a2 + 26) = *(_DWORD *)(a1 + 44);
  v13 = *(_WORD *)(a2 + 3) & 0xFF9F | (32 * (*(_WORD *)(a1 + 16) & 3));
  *(_WORD *)(a2 + 3) = v13;
  if ( *(_BYTE *)(a1 + 12) )
  {
    v14 = v13 & 0xFBFF | ((*(_BYTE *)(a1 + 12) & 1) << 10);
    *(_WORD *)(a2 + 3) = v14;
  }
  else
  {
    *(_WORD *)(a2 + 3) = v13 & 0xFBFF;
    *(_BYTE *)(a1 + 12) = 0;
    v14 = *(_WORD *)(a2 + 3);
  }
  v15 = v14 & 0xFFE1 | (2 * (*(_BYTE *)(a1 + 20) & 0xF));
  *(_WORD *)(a2 + 3) = v15;
  v16 = *(_BYTE *)(a2 + 2);
  v17 = v15 & 0xC67F | ((*(_WORD *)(a1 + 8) & 7) << 11) | 0x80;
  *(_WORD *)(a2 + 3) = v17;
  *(_BYTE *)(a2 + 2) = v16 & 0x7F | (*(_BYTE *)a1 << 7);
  v18 = v17 & 0x3FFF | (*(_WORD *)(a1 + 4) << 14);
  *(_BYTE *)a2 = 2;
  *(_WORD *)(a2 + 3) = v18;
  return qdf_trace_msg(
           0x34u,
           8u,
           "%s: up = %d, tid = %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "sme_qos_copy_tspec_info",
           *(unsigned int *)(a1 + 8),
           *(unsigned __int8 *)(a1 + 20),
           v10,
           v11);
}
