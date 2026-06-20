__int64 __fastcall chinstatus_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x8
  int v9; // w20
  unsigned int v10; // w8
  unsigned int v17; // w10

  v3 = *(_QWORD *)(a1 + 96);
  v6 = *(_QWORD *)(v3 + 152);
  LODWORD(result) = _pm_runtime_resume(v3, 4);
  if ( (result & 0x80000000) != 0 )
  {
    v10 = *(_DWORD *)(v3 + 480);
    do
    {
      if ( !v10 )
        break;
      _X12 = (unsigned int *)(v3 + 480);
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
  }
  else
  {
    raw_spin_lock(v6 + 56);
    if ( *(_BYTE *)(v6 + 77) == 1 )
    {
      v8 = 312;
      if ( *(_BYTE *)(v6 + 1200) )
        v8 = 128;
      v9 = readl_relaxed_0((unsigned int *)(*(_QWORD *)v6 + v8));
    }
    else
    {
      v9 = 0;
    }
    raw_spin_unlock(v6 + 56);
    _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
    LODWORD(result) = scnprintf(a3, 4096, "0x%x\n", v9);
  }
  return (int)result;
}
