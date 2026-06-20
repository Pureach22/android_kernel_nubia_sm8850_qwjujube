bool __fastcall _ll_lt_sap_is_bs_ctx_valid(
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
  if ( !a1 )
    qdf_trace_msg(0xA1u, 2u, "BS_SM context is null (via %s)", a3, a4, a5, a6, a7, a8, a9, a10, a2);
  return a1 != 0;
}
