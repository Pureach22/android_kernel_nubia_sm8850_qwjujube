__int64 __fastcall qce_core_irq_handler(__int64 a1, __int64 a2)
{
  unsigned __int64 v9; // x9

  _X8 = (unsigned __int64 *)(a2 + 70272);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stlxr(v9 | 1, _X8) );
  __dmb(0xBu);
  if ( (v9 & 1) == 0 )
    _tasklet_schedule(a2 + 70264);
  return 1;
}
