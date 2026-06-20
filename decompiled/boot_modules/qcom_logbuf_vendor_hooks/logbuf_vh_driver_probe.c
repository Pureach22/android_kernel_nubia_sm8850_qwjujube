__int64 logbuf_vh_driver_probe()
{
  __int64 *v0; // x0

  if ( (debug_symbol_available() & 1) == 0 )
    return 4294966779LL;
  v0 = (__int64 *)debug_symbol_lookup_name("prb");
  register_log_minidump(*v0);
  return 0;
}
