__int64 __fastcall epping_close(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 v8; // x0

  v8 = g_epping_ctx;
  if ( !g_epping_ctx )
    return qdf_trace_msg(0x33u, 1u, "%s: error: g_epping_ctx  = NULL", a1, a2, a3, a4, a5, a6, a7, a8, "epping_close");
  g_epping_ctx = 0;
  return _qdf_mem_free(v8);
}
