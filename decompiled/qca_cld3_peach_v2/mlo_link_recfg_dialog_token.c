__int64 __fastcall mlo_link_recfg_dialog_token(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  __int16 v11; // w8
  unsigned __int8 v13; // w8

  v10 = 0;
  if ( a1 && a2 )
  {
    v11 = *(unsigned __int8 *)(a1 + 3460);
    if ( ((v11 + 1) & 0x100) != 0 )
      v13 = 1;
    else
      v13 = v11 + 1;
    *(_BYTE *)(a1 + 3460) = v13;
    *(_BYTE *)(a2 + 256) = v13;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: gen dialog token %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_link_recfg_dialog_token",
      v13);
    return *(unsigned __int8 *)(a2 + 256);
  }
  return v10;
}
