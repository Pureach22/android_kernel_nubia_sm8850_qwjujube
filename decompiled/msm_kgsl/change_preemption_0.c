__int64 __fastcall change_preemption_0(__int64 result)
{
  unsigned __int64 v7; // x9

  _X8 = (unsigned __int64 *)(result + 14240);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 ^ 0x200, _X8) );
  return result;
}
