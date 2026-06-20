__int64 __fastcall lim_check_if_vendor_oui_match(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        const void *a10,
        unsigned __int8 a11,
        unsigned __int8 *a12,
        unsigned __int8 a13)
{
  if ( a12 && a13 )
  {
    if ( *a12 == 221 && !(unsigned int)qdf_mem_cmp(a12 + 2, a10, a11) )
      return 1;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: IE Null or ie len zero %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "lim_check_if_vendor_oui_match",
      a13);
  }
  return 0;
}
