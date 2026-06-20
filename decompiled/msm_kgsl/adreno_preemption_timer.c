__int64 __fastcall adreno_preemption_timer(__int64 result)
{
  unsigned int v7; // w8

  _X9 = (unsigned int *)(result - 16);
  __asm { PRFM            #0x11, [X9] }
  while ( 1 )
  {
    v7 = __ldxr(_X9);
    if ( v7 != 2 )
      break;
    if ( !__stlxr(3u, _X9) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v7 == 2 )
    return queue_work_on(32, system_unbound_wq, result + 40);
  return result;
}
