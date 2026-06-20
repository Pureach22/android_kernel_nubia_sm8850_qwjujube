__int64 __fastcall extract_install_key_comp_event_tlv(
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
        unsigned int a11,
        __int64 a12)
{
  __int64 v12; // x8
  const char *v14; // x2

  if ( a11 > 0xF )
  {
    if ( a10 )
    {
      v12 = *a10;
      if ( *a10 )
      {
        *(_DWORD *)a12 = *(_DWORD *)(v12 + 4);
        *(_DWORD *)(a12 + 4) = *(_DWORD *)(v12 + 16);
        *(_DWORD *)(a12 + 8) = *(_DWORD *)(v12 + 20);
        *(_DWORD *)(a12 + 12) = *(_DWORD *)(v12 + 24);
        *(_WORD *)(a12 + 16) = *(_DWORD *)(v12 + 8);
        *(_BYTE *)(a12 + 18) = *(_WORD *)(v12 + 10);
        *(_BYTE *)(a12 + 19) = *(_BYTE *)(v12 + 11);
        *(_WORD *)(a12 + 20) = *(_DWORD *)(v12 + 12);
        return 0;
      }
      v14 = "%s: received null event data from target";
    }
    else
    {
      v14 = "%s: received null buf from target";
    }
    qdf_trace_msg(0x31u, 2u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "extract_install_key_comp_event_tlv");
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid event buf len %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_install_key_comp_event_tlv",
      a11);
  }
  return 4;
}
