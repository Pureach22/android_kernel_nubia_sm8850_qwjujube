__int64 __fastcall ipclite_global_spin_lock_timeout(unsigned int a1, unsigned int a2, unsigned __int64 *a3)
{
  __int64 v5; // x0
  __int64 v7; // x23
  unsigned __int64 StatusReg; // x24
  __int64 v16; // x8
  unsigned int v18; // w9
  unsigned int v20; // w9
  unsigned int v22; // w9

  v5 = _msecs_to_jiffies(a2);
  if ( ipclite )
  {
    if ( a1 > 0xFF )
      return 4294967274LL;
    v7 = jiffies + v5;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      __asm { MSR             DAIFSet, #3 }
      *a3 = _ReadStatusReg(DAIF);
      ++*(_DWORD *)(StatusReg + 16);
      _X8 = (unsigned int *)(*(_QWORD *)(ipclite + 6448) + 4LL * a1);
      if ( (feature_mask & 8) != 0 )
      {
        __asm { PRFM            #0x11, [X8] }
        while ( 1 )
        {
          v20 = __ldxr(_X8);
          if ( v20 )
            break;
          if ( !__stlxr(1u, _X8) )
          {
            __dmb(0xBu);
            break;
          }
        }
        if ( !v20 )
          return 0;
      }
      else
      {
        __asm { PRFM            #0x11, [X8] }
        do
          v18 = __ldxr(_X8);
        while ( __stlxr(v18 | 1, _X8) );
        __dmb(0xBu);
        if ( !v18 )
          return 0;
        if ( (v18 & 1) == 0 )
        {
          _X8 = (unsigned int *)(*(_QWORD *)(ipclite + 6448) + 4LL * a1);
          __asm { PRFM            #0x11, [X8] }
          do
            v22 = __ldxr(_X8);
          while ( __stlxr(v22 & 0xFFFFFFFE, _X8) );
          __dmb(0xBu);
        }
      }
      _WriteStatusReg(DAIF, *a3);
      v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v16;
      if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule();
      if ( jiffies - v7 >= 0 )
        return 4294967186LL;
    }
  }
  printk(&unk_F98D, "ipclite", "ipclite_global_spin_lock_timeout");
  return 4294967284LL;
}
