__int64 __fastcall hif_exec_tasklet_schedule(__int64 result)
{
  unsigned __int64 v7; // x8

  _X9 = (unsigned __int64 *)(result + 3472);
  __asm { PRFM            #0x11, [X9] }
  do
    v7 = __ldxr(_X9);
  while ( __stlxr(v7 | 1, _X9) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    return _tasklet_schedule(result + 3464);
  return result;
}
