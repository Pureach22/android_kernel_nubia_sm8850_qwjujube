__int64 __fastcall arm_smmu_iova_to_phys(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x20
  __int64 (__fastcall *v4)(_QWORD); // x9
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // x19
  __int64 v8; // x21
  __int64 v9; // x22
  int v10; // w0
  int v11; // w8
  __int64 v12; // x19
  __int64 v13; // x21
  unsigned int v14; // w8
  unsigned int v21; // w10

  v2 = *(_QWORD *)(a1 - 168);
  if ( !v2 )
    return 0;
  v3 = *(_QWORD **)(a1 - 184);
  if ( (v3[4] & 0x20) == 0 || *(_DWORD *)(a1 - 112) )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(v2 + 16);
    v5 = *(_QWORD *)(a1 - 168);
    if ( *((_DWORD *)v4 - 1) != 1371081757 )
      __break(0x8229u);
    return v4(v5);
  }
  v7 = *v3;
  if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 )
  {
    v8 = a1;
    v9 = a2;
    v10 = _pm_runtime_resume(*v3, 4);
    a2 = v9;
    v11 = v10;
    a1 = v8;
    if ( v11 < 0 )
    {
      v14 = *(_DWORD *)(v7 + 480);
      while ( v14 )
      {
        _X12 = (unsigned int *)(v7 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v21 = __ldxr(_X12);
          if ( v21 != v14 )
            break;
          if ( !__stlxr(v14 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        result = 0;
        _ZF = v21 == v14;
        v14 = v21;
        if ( _ZF )
          return result;
      }
      return 0;
    }
  }
  result = _arm_smmu_iova_to_phys_hard(a1, a2);
  if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 )
  {
    v13 = result;
    v12 = *v3;
    *(_QWORD *)(v12 + 520) = ktime_get_mono_fast_ns(result);
    _pm_runtime_suspend(*v3, 13);
    return v13;
  }
  return result;
}
