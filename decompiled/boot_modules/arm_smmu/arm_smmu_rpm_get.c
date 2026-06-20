__int64 __fastcall arm_smmu_rpm_get(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  unsigned int v3; // w8
  unsigned int v10; // w10

  v1 = *a1;
  if ( (*(_WORD *)(*a1 + 488LL) & 7) != 0 )
    return 0;
  result = _pm_runtime_resume(*a1, 4);
  if ( (result & 0x80000000) == 0 )
    return 0;
  v3 = *(_DWORD *)(v1 + 480);
  do
  {
    if ( !v3 )
      break;
    _X12 = (unsigned int *)(v1 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v10 = __ldxr(_X12);
      if ( v10 != v3 )
        break;
      if ( !__stlxr(v3 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v10 == v3;
    v3 = v10;
  }
  while ( !_ZF );
  return result;
}
