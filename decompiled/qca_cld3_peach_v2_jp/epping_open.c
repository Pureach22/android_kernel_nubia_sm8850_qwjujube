__int64 __fastcall epping_open(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  qdf_trace_msg(0x33u, 5u, "%s: Enter", a1, a2, a3, a4, a5, a6, a7, a8, "epping_open");
  g_epping_ctx = _qdf_mem_malloc(0x1D8u, "epping_open", 83);
  if ( !g_epping_ctx )
    return 4294967284LL;
  *(_DWORD *)g_epping_ctx = cds_get_conparam();
  return 0;
}
