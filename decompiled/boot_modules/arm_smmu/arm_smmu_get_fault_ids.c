__int64 __fastcall arm_smmu_get_fault_ids(__int64 a1, int *a2)
{
  __int64 result; // x0
  _QWORD *v5; // x20
  int v6; // w22
  __int64 v7; // x21
  _DWORD **v8; // x8
  __int64 v9; // x1
  _DWORD *v10; // x8
  __int64 v11; // x0
  _DWORD **v12; // x8
  __int64 v13; // x1
  _DWORD *v14; // x8
  __int64 v15; // x0
  __int64 v16; // x22
  unsigned int v17; // w21
  __int64 v18; // x19
  unsigned int v19; // w8
  unsigned int v26; // w10

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = *(_QWORD **)(a1 - 184);
    v6 = *(unsigned __int8 *)(a1 - 136);
    v7 = *v5;
    if ( (*(_WORD *)(*v5 + 488LL) & 7) == 0 && (result = _pm_runtime_resume(*v5, 4), (result & 0x80000000) != 0) )
    {
      v19 = *(_DWORD *)(v7 + 480);
      do
      {
        if ( !v19 )
          break;
        _X12 = (unsigned int *)(v7 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v26 = __ldxr(_X12);
          if ( v26 != v19 )
            break;
          if ( !__stlxr(v19 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v26 == v19;
        v19 = v26;
      }
      while ( !_ZF );
    }
    else
    {
      v8 = (_DWORD **)v5[6];
      v9 = (unsigned int)(*((_DWORD *)v5 + 6) + v6);
      if ( v8 && (v10 = *v8) != nullptr )
      {
        if ( *(v10 - 1) != 616069899 )
          __break(0x8228u);
        v11 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v10)(v5, v9, 88);
      }
      else
      {
        v11 = readl_relaxed_0((unsigned int *)(v5[1] + (int)((_DWORD)v9 << *((_DWORD *)v5 + 7)) + 88LL));
      }
      if ( (v11 & 0xC00001FE) != 0 )
      {
        v12 = (_DWORD **)v5[6];
        v13 = (unsigned int)(*((_DWORD *)v5 + 6) + v6);
        if ( v12 && (v14 = *v12) != nullptr )
        {
          if ( *(v14 - 1) != 616069899 )
            __break(0x8228u);
          v15 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v14)(v5, v13, 108);
        }
        else
        {
          v15 = readl_relaxed_0((unsigned int *)(v5[1] + (int)((_DWORD)v13 << *((_DWORD *)v5 + 7)) + 108LL));
        }
        v17 = v15;
        if ( (*(_WORD *)(*v5 + 488LL) & 7) == 0 )
        {
          v16 = *v5;
          *(_QWORD *)(v16 + 520) = ktime_get_mono_fast_ns(v15);
          _pm_runtime_suspend(*v5, 13);
        }
        *a2 = (unsigned __int16)v17 >> 13;
        a2[1] = (v17 >> 8) & 0x1F;
        a2[2] = (unsigned __int8)v17;
        return 0;
      }
      else
      {
        if ( (*(_WORD *)(*v5 + 488LL) & 7) == 0 )
        {
          v18 = *v5;
          *(_QWORD *)(v18 + 520) = ktime_get_mono_fast_ns(v11);
          _pm_runtime_suspend(*v5, 13);
        }
        return 4294967274LL;
      }
    }
  }
  return result;
}
