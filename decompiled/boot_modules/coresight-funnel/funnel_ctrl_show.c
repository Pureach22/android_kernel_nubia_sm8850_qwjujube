__int64 __fastcall funnel_ctrl_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 *v6; // x24
  int v7; // w0
  int v8; // w25
  int v9; // w0
  __int64 v10; // x8
  int v11; // w22
  __int64 v12; // x23
  unsigned int v13; // w8
  unsigned int v20; // w10

  v3 = *(_QWORD *)(a1 + 96);
  v6 = *(__int64 **)(v3 + 152);
  v7 = _pm_runtime_resume(v3, 4);
  if ( v7 < 0 )
  {
    v13 = *(_DWORD *)(v3 + 480);
    do
    {
      if ( !v13 )
        break;
      _X12 = (unsigned int *)(v3 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v20 = __ldxr(_X12);
        if ( v20 != v13 )
          break;
        if ( !__stlxr(v13 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v20 == v13;
      v13 = v20;
    }
    while ( !_ZF );
    return v7;
  }
  raw_spin_lock_irqsave(v6 + 5);
  v8 = *((unsigned __int8 *)v6 + 88);
  if ( v8 == 1 )
  {
    writel_relaxed(3316436565LL, *v6 + 4016);
    __dsb(0xFu);
    v9 = readl_relaxed(*v6);
    v10 = *v6;
    __dsb(0xFu);
    v11 = v9;
    writel_relaxed(0, v10 + 4016);
    v12 = 0;
  }
  else
  {
    v11 = 0;
    v12 = -22;
  }
  raw_spin_unlock_irqrestore(v6 + 5);
  _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
  if ( v8 )
    return (int)scnprintf(a3, 4096, "%#x\n", v11);
  return v12;
}
