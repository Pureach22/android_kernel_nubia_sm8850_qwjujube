__int64 __fastcall sme_set_ba_buff_size(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned __int16 a11)
{
  if ( a11 )
  {
    *(_WORD *)(a1 + 21622) = a11;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: addba buff size is set to %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "sme_set_ba_buff_size",
      a11);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: invalid buff size %d", a2, a3, a4, a5, a6, a7, a8, a9, "sme_set_ba_buff_size", 0);
    return 4294967274LL;
  }
}
