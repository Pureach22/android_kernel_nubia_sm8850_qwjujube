__int64 __fastcall extract_dbr_buf_cv_metadata_tlv(
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

  if ( !a10 )
    return 4;
  v14 = *(_QWORD *)(a10 + 48) + 32LL * a11;
  if ( v14 )
  {
    *(_DWORD *)a12 = *(_DWORD *)(v14 + 4);
    *(_DWORD *)(a12 + 4) = *(_DWORD *)(v14 + 8);
    *(_WORD *)(a12 + 8) = *(_DWORD *)(v14 + 12);
    *(_WORD *)(a12 + 10) = *(_WORD *)(v14 + 14);
    *(_WORD *)(a12 + 12) = *(_DWORD *)(v14 + 16);
    *(_WORD *)(a12 + 14) = *(_WORD *)(v14 + 18);
    *(_WORD *)(a12 + 16) = *(_DWORD *)(v14 + 20);
    *(_BYTE *)(a12 + 18) = *(_WORD *)(v14 + 22);
    *(_BYTE *)(a12 + 19) = *(_BYTE *)(v14 + 23);
    *(_WORD *)(a12 + 20) = *(_DWORD *)(v14 + 24);
    *(_DWORD *)(a12 + 24) = *(_DWORD *)(v14 + 28);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: CV metadata is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_dbr_buf_cv_metadata_tlv",
      v12,
      v13);
    return 16;
  }
}
