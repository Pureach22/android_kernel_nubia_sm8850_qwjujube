__int64 __fastcall adreno_perfcounter_query_group(
        __int64 a1,
        unsigned int a2,
        unsigned __int64 a3,
        unsigned int a4,
        unsigned int *a5)
{
  __int64 v5; // x8
  __int64 v7; // x23
  __int64 result; // x0
  unsigned int v9; // w8
  __int64 v11; // x22
  unsigned __int64 v12; // x20
  __int64 v13; // x19
  __int64 v14; // x8
  __int64 v15; // x20
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x9
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  unsigned int v28; // w20
  unsigned __int64 StatusReg; // x25
  __int64 v30; // x26

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 48LL);
  *a5 = 0;
  if ( !v5 || *(_DWORD *)(v5 + 8) <= a2 )
    return 4294967274LL;
  v7 = *(_QWORD *)v5 + 56LL * a2;
  result = 0;
  v9 = *(_DWORD *)(v7 + 8);
  *a5 = v9;
  if ( a3 && a4 )
  {
    if ( v9 >= a4 )
      v11 = a4;
    else
      v11 = v9;
    v12 = 4LL * (unsigned int)v11;
    v13 = _kmalloc_noprof(v12, 3264);
    if ( v13 )
    {
      while ( 1 )
      {
        rt_mutex_lock(a1 + 11088);
        if ( !(_DWORD)v11 )
          break;
        v14 = 0;
        while ( v12 > 4 * v14 )
        {
          *(_DWORD *)(v13 + 4 * v14) = *(_DWORD *)(*(_QWORD *)v7 + 48 * v14);
          if ( ++v14 == v11 )
          {
            v15 = 4 * v11;
            goto LABEL_17;
          }
        }
        __break(1u);
        v12 = 4LL * (unsigned int)v11;
        StatusReg = _ReadStatusReg(SP_EL0);
        v30 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &adreno_perfcounter_query_group__alloc_tag;
        v13 = _kmalloc_noprof(v12, 3264);
        *(_QWORD *)(StatusReg + 80) = v30;
        if ( !v13 )
          return 4294967284LL;
      }
      v15 = 0;
LABEL_17:
      rt_mutex_unlock(a1 + 11088);
      if ( (unsigned int)v11 >> 29 )
      {
        __break(0x800u);
        v28 = -14;
      }
      else
      {
        _check_object_size(v13, v15, 1);
        v16 = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(v16 + 70) & 0x20) != 0 || (v17 = a3, (*(_QWORD *)v16 & 0x4000000) != 0) )
          v17 = a3 & ((__int64)(a3 << 8) >> 8);
        if ( 0x8000000000LL - v15 >= v17 )
        {
          v18 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v24 = *(_QWORD *)(v16 + 8);
          _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v24);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v18);
          v15 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v13, v15);
          v25 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v27 - 4096);
          _WriteStatusReg(TTBR1_EL1, v27);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v25);
        }
        if ( v15 )
          v28 = -14;
        else
          v28 = 0;
      }
      kfree(v13);
      return v28;
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
