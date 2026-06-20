__int64 __fastcall coresight_tmc_reg64_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v7; // x23
  int v8; // w0
  int v9; // w24
  __int64 v10; // x21
  __int64 v11; // x21
  __int64 v12; // x22
  unsigned int v13; // w8
  unsigned int v20; // w10

  v3 = *(_QWORD *)(a1 + 96);
  v7 = *(_QWORD *)(v3 + 152);
  v8 = _pm_runtime_resume(v3, 4);
  if ( v8 < 0 )
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
    return v8;
  }
  raw_spin_lock(v7 + 104);
  v9 = *(unsigned __int8 *)(v7 + 408);
  if ( v9 == 1 )
  {
    v10 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(v7 + 8) + *(unsigned int *)(a2 + 32)));
    v11 = v10 | (readl_relaxed((unsigned int *)(*(_QWORD *)(v7 + 8) + *(unsigned int *)(a2 + 36))) << 32);
    v12 = 0;
  }
  else
  {
    v11 = 0;
    v12 = -22;
  }
  raw_spin_unlock(v7 + 104);
  _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
  if ( v9 )
    return (int)sysfs_emit(a3, "0x%llx\n", v11);
  return v12;
}
