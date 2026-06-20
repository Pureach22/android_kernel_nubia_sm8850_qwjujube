_BYTE *__fastcall convert_bcon_bss_color_change_ie(
        _BYTE *result,
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
  _BYTE *v10; // x19

  if ( result[2363] )
  {
    v10 = result;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: 11AX: HE BSS color change present",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "convert_bcon_bss_color_change_ie");
    return qdf_mem_copy((void *)(a2 + 2844), v10 + 2363, 3u);
  }
  return result;
}
