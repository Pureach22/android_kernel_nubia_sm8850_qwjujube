__int64 __fastcall wma_extract_single_phyerr_spectral(
        __int64 a1,
        unsigned __int16 a2,
        unsigned __int16 *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x5
  __int16 v13; // w8
  __int64 v15; // x9
  unsigned int v16; // w8
  int v17; // w8
  __int16 v18; // w8

  v12 = *a3;
  v13 = *a3;
  if ( (unsigned int)v12 < a2 )
  {
    if ( a2 - (unsigned int)v12 <= 0x27 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: not enough space? (datalen=%d, n=%d, hdr=%zu bytes",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wma_extract_single_phyerr_spectral",
        a2);
      return 16;
    }
    v15 = a1 + v12;
    *(_QWORD *)(a4 + 48) = a1 + v12 + 40;
    v16 = *(_DWORD *)(a1 + v12 + 36);
    *(_DWORD *)(a4 + 56) = v16;
    if ( v16 >= 0x7F000001 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: buf_len is garbage? (0x%x)",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wma_extract_single_phyerr_spectral",
        v16);
      return 16;
    }
    if ( v16 + (unsigned int)v12 > a2 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: buf_len exceeds available space n=%d, buf_len=%d, datalen=%d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wma_extract_single_phyerr_spectral",
        (unsigned int)v12,
        v16);
      return 16;
    }
    *(_DWORD *)(a4 + 40) = *(unsigned __int8 *)(v15 + 10);
    *(_DWORD *)(a4 + 44) = *(_DWORD *)v15;
    v17 = *(_DWORD *)(v15 + 36);
    if ( v17 )
    {
      *(_WORD *)(a4 + 18) = *(_DWORD *)(v15 + 28);
      *(_WORD *)(a4 + 20) = *(_WORD *)(v15 + 30);
      *(_WORD *)(a4 + 22) = *(_DWORD *)(v15 + 32);
      *(_WORD *)(a4 + 24) = *(_WORD *)(v15 + 34);
      *(_BYTE *)a4 = *(_DWORD *)(v15 + 8);
      *(_WORD *)(a4 + 1) = *(_DWORD *)(v15 + 12);
      *(_BYTE *)(a4 + 3) = *(_WORD *)(v15 + 14);
      *(_BYTE *)(a4 + 4) = *(_BYTE *)(v15 + 15);
      *(_WORD *)(a4 + 5) = *(_DWORD *)(v15 + 16);
      *(_BYTE *)(a4 + 7) = *(_WORD *)(v15 + 18);
      *(_BYTE *)(a4 + 8) = *(_BYTE *)(v15 + 19);
      *(_WORD *)(a4 + 9) = *(_DWORD *)(v15 + 20);
      *(_BYTE *)(a4 + 11) = *(_WORD *)(v15 + 22);
      *(_BYTE *)(a4 + 12) = *(_BYTE *)(v15 + 23);
      *(_WORD *)(a4 + 13) = *(_DWORD *)(v15 + 24);
      *(_BYTE *)(a4 + 15) = *(_WORD *)(v15 + 26);
      *(_BYTE *)(a4 + 16) = *(_BYTE *)(v15 + 27);
      *(_WORD *)(a4 + 26) = *(_DWORD *)(v15 + 4);
      *(_WORD *)(a4 + 28) = *(_WORD *)(v15 + 6);
      v17 = *(_DWORD *)(v15 + 36);
    }
    v18 = v12 + v17;
    LOWORD(v12) = *a3;
    v13 = v18 + 44;
  }
  *a3 = v12 + v13;
  return 0;
}
