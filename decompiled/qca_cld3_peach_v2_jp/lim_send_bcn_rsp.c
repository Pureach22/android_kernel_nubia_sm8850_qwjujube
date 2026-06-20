__int64 __fastcall lim_send_bcn_rsp(
        __int64 result,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19

  if ( !a2 )
    return qdf_trace_msg(0x35u, 2u, "%s: rsp is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "lim_send_bcn_rsp");
  if ( *(_QWORD *)(a2 + 540) != 8 )
  {
    v10 = result;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Send beacon resp status %d for reason %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_send_bcn_rsp",
      *((unsigned int *)a2 + 136));
    return lim_nss_or_ch_width_update_rsp(v10, *a2, *((unsigned int *)a2 + 136), *((unsigned int *)a2 + 135));
  }
  return result;
}
