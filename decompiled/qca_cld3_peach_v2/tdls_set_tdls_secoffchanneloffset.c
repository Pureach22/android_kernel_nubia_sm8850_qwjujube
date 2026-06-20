__int64 __fastcall tdls_set_tdls_secoffchanneloffset(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x4
  __int16 v12; // w8

  if ( (*(_BYTE *)(a1 + 156) & 1) == 0 || *(_DWORD *)(a1 + 8) <= 1u )
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
      "tdls_set_tdls_secoffchanneloffset");
    return 4294966772LL;
  }
  v11 = (unsigned int)a2;
  *(_WORD *)(a1 + 206) = 255;
  if ( a2 <= 39 )
  {
    if ( a2 == -40 )
    {
      v12 = 1;
      v11 = 1;
      goto LABEL_15;
    }
    if ( !a2 )
    {
      v12 = 0;
      goto LABEL_15;
    }
LABEL_17:
    qdf_trace_msg(
      0,
      2u,
      "%s: Invalid tdls secondary off channel offset %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_set_tdls_secoffchanneloffset");
    return 4294967274LL;
  }
  if ( a2 == 160 )
  {
    v12 = 5;
    v11 = 5;
    goto LABEL_15;
  }
  if ( a2 == 80 )
  {
    v12 = 4;
    v11 = 4;
    goto LABEL_15;
  }
  if ( a2 != 40 )
    goto LABEL_17;
  v12 = 3;
  v11 = 3;
LABEL_15:
  *(_WORD *)(a1 + 206) = v12;
  qdf_trace_msg(
    0,
    4u,
    "%s: change tdls secondary off channel offset to 0x%x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "tdls_set_tdls_secoffchanneloffset",
    v11);
  return 0;
}
