__int64 __fastcall extract_roam_btm_response_stats_tlv(
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
        __int64 a11,
        unsigned __int8 a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x8
  __int64 v15; // x8
  int v16; // w8

  if ( a10 && (v14 = *(_QWORD *)(a10 + 160)) != 0 && *(_DWORD *)(a10 + 168) > (unsigned int)a12 )
  {
    v15 = v14 + 36LL * a12;
    if ( *(_DWORD *)(v15 + 20) )
    {
      *(_BYTE *)a11 = 1;
      *(_DWORD *)(a11 + 4) = *(_DWORD *)(v15 + 4);
      *(_WORD *)(a11 + 8) = *(_DWORD *)(v15 + 8);
      *(_BYTE *)(a11 + 10) = *(_WORD *)(v15 + 10);
      *(_BYTE *)(a11 + 11) = *(_BYTE *)(v15 + 11);
      *(_WORD *)(a11 + 12) = *(_DWORD *)(v15 + 12);
      *(_DWORD *)(a11 + 16) = *(_DWORD *)(v15 + 16);
      *(_DWORD *)(a11 + 20) = *(_DWORD *)(v15 + 20);
      *(_WORD *)(a11 + 24) = *(_DWORD *)(v15 + 24);
      *(_BYTE *)(a11 + 26) = *(_DWORD *)(v15 + 28);
      v16 = *(_DWORD *)(v15 + 32) & 7;
      *(_BYTE *)(a11 + 28) = v16;
      if ( v16 )
        *(_BYTE *)(a11 + 27) = 1;
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Empty btm response param buf",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_btm_response_stats_tlv",
      v12,
      v13);
    return 0;
  }
}
