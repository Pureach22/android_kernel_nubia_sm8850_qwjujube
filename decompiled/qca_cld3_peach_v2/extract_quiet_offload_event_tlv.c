__int64 __fastcall extract_quiet_offload_event_tlv(
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
  unsigned int v14; // w9
  int v15; // w9

  v13 = *a10;
  v14 = *(_DWORD *)(*a10 + 24);
  if ( (~v14 & 5) == 0 )
  {
LABEL_2:
    *(_WORD *)a11 = *(_DWORD *)(v13 + 4);
    *(_BYTE *)(a11 + 2) = *(_WORD *)(v13 + 6);
    *(_BYTE *)(a11 + 3) = *(_BYTE *)(v13 + 7);
    *(_WORD *)(a11 + 4) = *(_DWORD *)(v13 + 8);
    v15 = *(_DWORD *)(v13 + 24);
    if ( (v15 & 2) == 0 )
    {
      if ( (v15 & 4) == 0 )
      {
LABEL_5:
        *(_BYTE *)(a11 + 13) = *(_DWORD *)(v13 + 28) == 0;
        return 0;
      }
LABEL_4:
      *(_BYTE *)(a11 + 12) = *(_DWORD *)(v13 + 20);
      goto LABEL_5;
    }
LABEL_9:
    *(_WORD *)(a11 + 6) = *(_DWORD *)(v13 + 12);
    *(_BYTE *)(a11 + 8) = *(_WORD *)(v13 + 14);
    *(_BYTE *)(a11 + 9) = *(_BYTE *)(v13 + 15);
    *(_WORD *)(a11 + 10) = *(_DWORD *)(v13 + 16);
    if ( (*(_DWORD *)(v13 + 24) & 4) == 0 )
      goto LABEL_5;
    goto LABEL_4;
  }
  if ( (v14 & 2) != 0 )
  {
    if ( (v14 & 1) == 0 )
      goto LABEL_9;
    goto LABEL_2;
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Invalid sta quiet offload event. present bit: mld mac %d link mac %d linkid %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "extract_quiet_offload_event_tlv",
    v14 & 1,
    (v14 >> 2) & 1,
    0,
    v11,
    v12);
  return 4;
}
