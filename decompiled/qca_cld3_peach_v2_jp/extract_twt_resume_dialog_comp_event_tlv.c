__int64 __fastcall extract_twt_resume_dialog_comp_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8
  __int64 v14; // x9
  int v15; // w9

  if ( a10 )
  {
    v13 = *a10;
    *(_DWORD *)a11 = *(_DWORD *)(*a10 + 4);
    *(_WORD *)(a11 + 4) = *(_DWORD *)(v13 + 8);
    *(_BYTE *)(a11 + 6) = *(_WORD *)(v13 + 10);
    *(_BYTE *)(a11 + 7) = *(_BYTE *)(v13 + 11);
    *(_WORD *)(a11 + 8) = *(_DWORD *)(v13 + 12);
    v14 = *(unsigned int *)(v13 + 20);
    if ( (unsigned int)v14 > 0xB )
      v15 = 7;
    else
      v15 = dword_A2DF6C[v14];
    *(_DWORD *)(a11 + 16) = v15;
    *(_DWORD *)(a11 + 12) = *(_DWORD *)(v13 + 16);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: evt_buf is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_twt_resume_dialog_comp_event_tlv",
      v11,
      v12);
    return 4;
  }
}
