__int64 __fastcall wlan_objmgr_psoc_get_ref(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v16; // w9
  unsigned int v18; // w9

  if ( !result )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: psoc obj is NULL for id:%d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_objmgr_psoc_get_ref",
             a2);
  _X8 = (unsigned int *)(result + 1680);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 + 1, _X8) );
  if ( a2 < 0x6E )
    _X8 = (unsigned int *)(result + 4LL * a2 + 1684);
  else
    __break(0x5512u);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 + 1, _X8) );
  return result;
}
