__int64 __fastcall extract_rcpi_response_event_tlv(
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
  int v12; // w9

  if ( a10 )
  {
    v11 = *a10;
    *(_DWORD *)a11 = *(_DWORD *)(*a10 + 4);
    *(_WORD *)(a11 + 8) = *(_DWORD *)(v11 + 8);
    *(_BYTE *)(a11 + 10) = *(_WORD *)(v11 + 10);
    *(_BYTE *)(a11 + 11) = *(_BYTE *)(v11 + 11);
    *(_WORD *)(a11 + 12) = *(_DWORD *)(v11 + 12);
    v12 = *(_DWORD *)(v11 + 16);
    if ( (unsigned int)(v12 - 1) >= 4 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid rcpi measurement type from firmware",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_rcpi_response_event_tlv");
      *(_DWORD *)(a11 + 4) = 5;
      return 16;
    }
    else
    {
      *(_DWORD *)(a11 + 4) = v12;
      return 16 * (unsigned int)(*(_DWORD *)(v11 + 24) != 0);
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid rcpi event",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_rcpi_response_event_tlv");
    return 4;
  }
}
