__int64 __fastcall coresight_tmc_reg32_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x22
  __int64 v9; // x24
  int v10; // w0
  __int64 v11; // x8
  unsigned int v12; // w8
  unsigned int v19; // w10
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 96);
  v21[0] = 0;
  v9 = *(_QWORD *)(v8 + 152);
  v10 = _pm_runtime_resume(v8, 4);
  if ( v10 < 0 )
  {
    v12 = *(_DWORD *)(v8 + 480);
    do
    {
      if ( !v12 )
        break;
      _X12 = (unsigned int *)(v8 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v19 = __ldxr(_X12);
        if ( v19 != v12 )
          break;
        if ( !__stlxr(v12 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v19 == v12;
      v12 = v19;
    }
    while ( !_ZF );
    a4 = v10;
  }
  else
  {
    raw_spin_lock(v9 + 104);
    if ( *(_BYTE *)(v9 + 408) == 1 && !(unsigned int)kstrtoull(a3, 0, v21) )
    {
      writel_relaxed(0xC5ACCE55, (unsigned int *)(*(_QWORD *)(v9 + 8) + 4016LL));
      __dsb(0xFu);
      writel_relaxed(v21[0], (unsigned int *)(*(_QWORD *)(v9 + 8) + *(unsigned int *)(a2 + 32)));
      v11 = *(_QWORD *)(v9 + 8);
      __dsb(0xFu);
      writel_relaxed(0, (unsigned int *)(v11 + 4016));
    }
    raw_spin_unlock(v9 + 104);
    _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
