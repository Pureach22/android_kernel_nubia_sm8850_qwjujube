__int64 __fastcall extract_dbr_buf_cqi_metadata_tlv(
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
        unsigned __int8 a11,
        __int64 a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x8
  unsigned int v15; // w9
  int v16; // w10
  char v17; // w12
  int v19; // w12
  int v20; // w13
  int v21; // w13

  if ( !a10 )
    return 4;
  v14 = *(_QWORD *)(a10 + 64) + 36LL * a11;
  if ( !v14 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: CQI metadata is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_dbr_buf_cqi_metadata_tlv",
      v12,
      v13);
    return 16;
  }
  v15 = *(_DWORD *)(v14 + 32);
  *(_DWORD *)(a12 + 12) = v15 & 0x1FF;
  v16 = *(_DWORD *)(v14 + 4);
  if ( (v15 & 1) == 0 )
  {
    v17 = 0;
    if ( (v15 & 2) == 0 )
      goto LABEL_10;
    goto LABEL_9;
  }
  v19 = *(_DWORD *)(a12 + 4);
  *(_DWORD *)(a12 + 16) = v16;
  *(_DWORD *)(a12 + 4) = v19 | 1;
  *(_DWORD *)(a12 + 20) = (v15 >> 3) & 3;
  *(_WORD *)(a12 + 24) = *(_DWORD *)(v14 + 8);
  *(_BYTE *)(a12 + 26) = *(_WORD *)(v14 + 10);
  *(_BYTE *)(a12 + 27) = *(_BYTE *)(v14 + 11);
  *(_WORD *)(a12 + 28) = *(_DWORD *)(v14 + 12);
  v17 = 1;
  if ( (v15 & 2) != 0 )
  {
LABEL_9:
    v20 = *(_DWORD *)(a12 + 4);
    *(_WORD *)(a12 + 32) = v16;
    *(_WORD *)(a12 + 34) = HIWORD(v16) + 512;
    ++v17;
    *(_DWORD *)(a12 + 4) = v20 | 2;
    *(_DWORD *)(a12 + 36) = (v15 >> 5) & 3;
    *(_WORD *)(a12 + 40) = *(_DWORD *)(v14 + 16);
    *(_BYTE *)(a12 + 42) = *(_WORD *)(v14 + 18);
    *(_BYTE *)(a12 + 43) = *(_BYTE *)(v14 + 19);
    *(_WORD *)(a12 + 44) = *(_DWORD *)(v14 + 20);
  }
LABEL_10:
  if ( (v15 & 4) != 0 )
  {
    v21 = *(_DWORD *)(a12 + 4);
    *(_WORD *)(a12 + 48) = v16;
    *(_WORD *)(a12 + 50) = HIWORD(v16) + 1024;
    ++v17;
    *(_DWORD *)(a12 + 4) = v21 | 4;
    *(_DWORD *)(a12 + 52) = (v15 >> 7) & 3;
    *(_WORD *)(a12 + 56) = *(_DWORD *)(v14 + 24);
    *(_BYTE *)(a12 + 58) = *(_WORD *)(v14 + 26);
    *(_BYTE *)(a12 + 59) = *(_BYTE *)(v14 + 27);
    *(_WORD *)(a12 + 60) = *(_DWORD *)(v14 + 28);
  }
  *(_BYTE *)a12 = v17;
  return 0;
}
