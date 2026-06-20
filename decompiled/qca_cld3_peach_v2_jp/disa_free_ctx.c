__int64 __fastcall disa_free_ctx(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0

  if ( !gp_disa_ctx )
    return qdf_trace_msg(0x5Cu, 2u, "%s: disa ctx is already freed", a1, a2, a3, a4, a5, a6, a7, a8, "disa_free_ctx");
  result = _qdf_mem_free(gp_disa_ctx);
  gp_disa_ctx = 0;
  return result;
}
