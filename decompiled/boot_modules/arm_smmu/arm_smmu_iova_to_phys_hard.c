__int64 __fastcall arm_smmu_iova_to_phys_hard(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  _QWORD *v3; // x21
  __int64 v4; // x19
  __int64 v5; // x22
  __int64 v6; // x23
  int v7; // w0
  int v8; // w8
  __int64 v9; // x8
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  __int64 result; // x0
  __int64 v12; // x19
  __int64 v13; // x20
  unsigned int v14; // w8
  unsigned int v21; // w10

  v2 = a1 - 184;
  v3 = *(_QWORD **)(a1 - 184);
  if ( (*((_BYTE *)v3 + 36) & 0x10) != 0 )
    return 0;
  v4 = *v3;
  if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 )
  {
    v5 = a1;
    v6 = a2;
    v7 = _pm_runtime_resume(*v3, 4);
    a2 = v6;
    v8 = v7;
    a1 = v5;
    if ( v8 < 0 )
    {
      v14 = *(_DWORD *)(v4 + 480);
      while ( v14 )
      {
        _X12 = (unsigned int *)(v4 + 480);
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
  v9 = v3[6];
  if ( v9 && (v10 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 64)) != nullptr )
  {
    if ( *((_DWORD *)v10 - 1) != -438034054 )
      __break(0x8228u);
    result = v10(v2, a2);
  }
  else if ( (*(_BYTE *)(*(_QWORD *)v2 + 32LL) & 0x20) != 0 && !*(_DWORD *)(a1 - 112) )
  {
    result = _arm_smmu_iova_to_phys_hard();
  }
  else
  {
    result = 0;
  }
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
