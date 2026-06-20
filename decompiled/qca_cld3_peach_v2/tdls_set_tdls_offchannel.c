__int64 __fastcall tdls_set_tdls_offchannel(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v10; // w19

  if ( (*(_BYTE *)(a1 + 156) & 1) != 0 && (unsigned int)(*(_DWORD *)(a1 + 8) - 2) <= 2 )
  {
    v10 = a2;
    if ( a2 - 166 > 0xFFFFFF5A )
    {
      qdf_trace_msg(
        0,
        4u,
        "%s: change tdls off channel from %d to %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "tdls_set_tdls_offchannel",
        *(unsigned __int8 *)(a1 + 204),
        a2);
      *(_BYTE *)(a1 + 204) = v10;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: Invalid tdls off channel %u",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "tdls_set_tdls_offchannel",
        a2);
      return 4294967274LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: Either TDLS or TDLS Off-channel is not enabled",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_set_tdls_offchannel");
    return 4294966772LL;
  }
}
