__int64 __fastcall kgsl_pwrctrl_enable_gx_gdsc(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  unsigned int v4; // w19
  __int64 v5; // x20
  unsigned int v6; // w8
  unsigned int v13; // w10

  if ( a1[1126] )
  {
    result = regulator_enable();
  }
  else
  {
    v5 = a1[1129];
    if ( !v5 )
      return 0;
    result = _pm_runtime_resume(a1[1129], 4);
    if ( (result & 0x80000000) == 0 )
      return 0;
    v6 = *(_DWORD *)(v5 + 480);
    do
    {
      if ( !v6 )
        break;
      _X12 = (unsigned int *)(v5 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v13 = __ldxr(_X12);
        if ( v13 != v6 )
          break;
        if ( !__stlxr(v6 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v13 == v6;
      v6 = v13;
    }
    while ( !_ZF );
  }
  if ( (_DWORD)result )
  {
    v3 = *a1;
    v4 = result;
    dev_err(v3, "Failed to enable GX gdsc, error %d\n", result);
    return v4;
  }
  return result;
}
