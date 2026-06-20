__int64 __fastcall replicator_reg_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v7; // x23
  int v8; // w0
  int v9; // w24
  int v10; // w21
  __int64 v11; // x22
  unsigned int v12; // w8
  unsigned int v19; // w10

  v3 = *(_QWORD *)(a1 + 96);
  v7 = *(_QWORD *)(v3 + 152);
  v8 = _pm_runtime_resume(v3, 4);
  if ( v8 < 0 )
  {
    v12 = *(_DWORD *)(v3 + 480);
    do
    {
      if ( !v12 )
        break;
      _X12 = (unsigned int *)(v3 + 480);
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
    return v8;
  }
  raw_spin_lock(v7 + 32);
  v9 = *(unsigned __int8 *)(v7 + 88);
  if ( v9 == 1 )
  {
    v10 = readl_relaxed(*(_QWORD *)v7 + *(unsigned int *)(a2 + 32));
    v11 = 0;
  }
  else
  {
    v10 = 0;
    v11 = -22;
  }
  raw_spin_unlock(v7 + 32);
  _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
  if ( v9 )
    return (int)sysfs_emit(a3, "0x%x\n", v10);
  return v11;
}
