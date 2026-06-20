__int64 __fastcall extract_twt_nudge_dialog_comp_event_tlv(
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
  __int64 v11; // x8
  __int64 v12; // x9
  int v13; // w9

  if ( a10 )
  {
    v11 = *a10;
    *(_DWORD *)a11 = *(_DWORD *)(*a10 + 4);
    *(_WORD *)(a11 + 4) = *(_DWORD *)(v11 + 8);
    *(_BYTE *)(a11 + 6) = *(_WORD *)(v11 + 10);
    *(_BYTE *)(a11 + 7) = *(_BYTE *)(v11 + 11);
    *(_WORD *)(a11 + 8) = *(_DWORD *)(v11 + 12);
    v12 = *(unsigned int *)(v11 + 20);
    if ( (unsigned int)v12 > 0xB )
      v13 = 6;
    else
      v13 = dword_B33824[v12];
    *(_DWORD *)(a11 + 16) = v13;
    *(_DWORD *)(a11 + 12) = *(_DWORD *)(v11 + 16);
    *(_DWORD *)(a11 + 20) = *(_DWORD *)(v11 + 24);
    *(_DWORD *)(a11 + 24) = *(_DWORD *)(v11 + 28);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id: %d dialog_id: %d tsf hi : %x tsf lo: %x",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_twt_nudge_dialog_comp_event_tlv");
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
      "extract_twt_nudge_dialog_comp_event_tlv");
    return 4;
  }
}
