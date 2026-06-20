__int64 __fastcall reset_tgu_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x21
  __int64 v7; // x20
  int v8; // w0
  unsigned int v10; // w8
  unsigned int v17; // w10
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v18[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 16, v18) )
  {
    a4 = -22;
  }
  else if ( (*(_BYTE *)(v6 + 116) & 1) == 0 && (v7 = *(_QWORD *)(v6 + 8), v8 = _pm_runtime_resume(v7, 4), v8 < 0) )
  {
    v10 = *(_DWORD *)(v7 + 480);
    do
    {
      if ( !v10 )
        break;
      _X12 = (unsigned int *)(v7 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v17 = __ldxr(_X12);
        if ( v17 != v10 )
          break;
        if ( !__stlxr(v10 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v17 == v10;
      v10 = v17;
    }
    while ( !_ZF );
    a4 = v8;
  }
  else
  {
    raw_spin_lock(v6 + 32);
    *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = -978530731;
    __dsb(0xFu);
    if ( v18[0] )
    {
      **(_DWORD **)v6 = 0;
      *(_DWORD *)(v6 + 112) = 0;
      *(_QWORD *)(v6 + 96) = 0;
      *(_QWORD *)(v6 + 104) = 0;
    }
    __dsb(0xFu);
    *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = 0;
    raw_spin_unlock(v6 + 32);
    _pm_runtime_idle(*(_QWORD *)(v6 + 8), 4);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
