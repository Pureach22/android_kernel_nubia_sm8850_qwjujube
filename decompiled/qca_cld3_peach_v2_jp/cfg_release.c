__int64 *cfg_release()
{
  __int64 *result; // x0
  unsigned int v7; // w8
  unsigned int v8; // w8

  qdf_trace_msg(80, 8, "%s: enter", "cfg_release");
  result = (__int64 *)_cfg_global_store;
  if ( _cfg_global_store )
  {
    _X9 = (unsigned int *)(_cfg_global_store + 24);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v7 = __ldxr(_X9);
      v8 = v7 - 1;
    }
    while ( __stlxr(v8, _X9) );
    __dmb(0xBu);
    if ( !v8 )
      result = (__int64 *)cfg_store_free(result);
    _cfg_global_store = 0;
  }
  return result;
}
