unsigned __int64 __fastcall gen8_preemption_pre_ibsubmit(__int64 a1, unsigned __int64 *_X1, __int64 a3, __int64 a4)
{
  __int64 v5; // x19
  __int64 v7; // x21
  __int64 v8; // x19
  unsigned __int64 v14; // x8

  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
    return 0;
  __asm { PRFM            #0x11, [X1] }
  do
    v14 = __ldxr(_X1);
  while ( __stlxr(v14 | 1, _X1) );
  __dmb(0xBu);
  v5 = a4;
  if ( (v14 & 1) == 0 )
  {
    *(_QWORD *)(a4 + 16) = 0;
    *(_QWORD *)a4 = 0x170970001LL;
    *(_QWORD *)(a4 + 8) = 1893105676;
    v5 = a4 + 60;
    *(_DWORD *)(a4 + 24) = 1;
    *(_QWORD *)(a4 + 28) = *(_QWORD *)(_X1[23] + 24);
    *(_DWORD *)(a4 + 36) = 2;
    *(_QWORD *)(a4 + 40) = *(_QWORD *)(_X1[24] + 24);
    *(_DWORD *)(a4 + 48) = 4;
    *(_QWORD *)(a4 + 52) = *(_QWORD *)(_X1[25] + 24);
  }
  if ( a3 )
  {
    v7 = a4;
    v8 = v5 + 4LL * (unsigned int)adreno_prepare_preib_preempt_scratch(a1, a3, v5);
    v5 = v8 + 4LL * (unsigned int)adreno_prepare_preib_postamble_scratch(a1, v8);
    a4 = v7;
  }
  return (unsigned __int64)(v5 - a4) >> 2;
}
