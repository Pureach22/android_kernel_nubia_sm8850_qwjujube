size_t __fastcall aiqe_deregister_client(
        size_t result,
        unsigned int *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  char v9; // w20
  unsigned int v15; // w9
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (unsigned int)result <= 5 )
  {
    _X19 = a2;
    if ( a2 )
    {
      v9 = result;
      result = sde_evtlog_log(sde_dbg_base_evtlog, "aiqe_deregister_client", 48, -1, result, -1059143953, a7, a8, vars0);
      __asm { PRFM            #0x11, [X19] }
      do
        v15 = __ldxr(_X19);
      while ( __stxr(v15 & ~(1 << v9), _X19) );
    }
  }
  return result;
}
