__int64 __fastcall scheduler_clear_event_mask(__int64 a1)
{
  unsigned int v1; // w19
  __int64 result; // x0
  unsigned __int64 v9; // x10

  v1 = a1;
  result = scheduler_get_context(a1);
  if ( result )
  {
    _X9 = (unsigned __int64 *)(result + 616 + 8LL * (v1 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v9 = __ldxr(_X9);
    while ( __stxr(v9 & ~(1LL << v1), _X9) );
  }
  return result;
}
