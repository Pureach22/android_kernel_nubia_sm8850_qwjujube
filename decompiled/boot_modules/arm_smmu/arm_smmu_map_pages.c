__int64 __fastcall arm_smmu_map_pages(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *v8; // x26
  _DWORD **v9; // x24
  __int64 v10; // x23
  __int64 v12; // x22
  __int64 v13; // x27
  __int64 v14; // x22
  __int64 v15; // x20
  unsigned int v16; // w19
  __int64 v17; // x28
  __int64 result; // x0
  _DWORD *v19; // x10
  __int64 v20; // x6
  __int64 v21; // x23
  unsigned int v22; // w24
  unsigned int v23; // w8
  unsigned int v30; // w10

  v8 = *(_QWORD **)(a1 - 184);
  v9 = *(_DWORD ***)(a1 - 168);
  if ( !v9 )
    return 4294967277LL;
  v10 = *v8;
  v12 = a2;
  if ( (*(_WORD *)(*v8 + 488LL) & 7) != 0 )
    goto LABEL_4;
  v13 = a8;
  v14 = a4;
  v15 = a5;
  v16 = a6;
  v17 = a3;
  result = _pm_runtime_resume(*v8, 4);
  a4 = v14;
  v12 = a2;
  a3 = v17;
  a6 = v16;
  a5 = v15;
  a8 = v13;
  if ( (result & 0x80000000) != 0 )
  {
    v23 = *(_DWORD *)(v10 + 480);
    do
    {
      if ( !v23 )
        break;
      _X12 = (unsigned int *)(v10 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v30 = __ldxr(_X12);
        if ( v30 != v23 )
          break;
        if ( !__stlxr(v23 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v30 == v23;
      v23 = v30;
    }
    while ( !_ZF );
  }
  else
  {
LABEL_4:
    v19 = *v9;
    if ( (*(_BYTE *)(a1 - 47) & 2) != 0 )
      v20 = 2080;
    else
      v20 = 3264;
    if ( *(v19 - 1) != 2054949561 )
      __break(0x822Au);
    result = ((__int64 (__fastcall *)(_DWORD **, __int64, __int64, __int64, __int64, __int64, __int64, __int64))v19)(
               v9,
               v12,
               a3,
               a4,
               a5,
               a6,
               v20,
               a8);
    if ( (*(_WORD *)(*v8 + 488LL) & 7) != 0 )
    {
      if ( (_DWORD)result )
        return result;
    }
    else
    {
      v22 = result;
      v21 = *v8;
      *(_QWORD *)(v21 + 520) = ktime_get_mono_fast_ns(result);
      _pm_runtime_suspend(*v8, 13);
      result = v22;
      if ( v22 )
        return result;
    }
    return 0;
  }
  return result;
}
