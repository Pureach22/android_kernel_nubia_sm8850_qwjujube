__int64 __fastcall adreno_check_idle(_QWORD *a1)
{
  __int64 result; // x0
  int v3; // w8
  __int64 v4; // x20
  int v5; // w22
  _QWORD *v6; // x24
  __int64 v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = adreno_profile_process_results();
  if ( !a1[1389] )
  {
    __break(0x800u);
    goto LABEL_16;
  }
  result = completion_done(a1 + 2532);
  if ( (result & 1) == 0 )
  {
    result = __ratelimit(&adreno_check_idle__rs, "adreno_check_idle");
    if ( (_DWORD)result )
      result = dev_err(*a1, "Dispatcher not idle before SLUMBER\n");
  }
  v3 = *((_DWORD *)a1 + 2780);
  v4 = *(_QWORD *)(a1[1783] + 40LL);
  if ( v3 == 32 || v3 == 2 )
  {
    __dmb(0xBu);
    if ( *((int *)a1 + 4908) >= 1 )
    {
      v5 = 0;
      v6 = a1;
      do
      {
        v7 = *((int *)v6 + 3595);
        v9 = 0;
        kgsl_sharedmem_readl(v6[-165 * (int)v7 + 6], &v9, 32 * v7);
        if ( v9 != *((_DWORD *)v6 + 3593) )
          goto LABEL_14;
        ++v5;
        v6 += 165;
      }
      while ( v5 < *((_DWORD *)a1 + 4908) );
    }
    v8 = *(__int64 (__fastcall **)(_QWORD))(v4 + 120);
    if ( *((_DWORD *)v8 - 1) != -1780529452 )
      __break(0x8228u);
    result = v8(a1);
    if ( (result & 1) == 0 )
    {
LABEL_14:
      result = __ratelimit(&adreno_check_idle__rs_49, "adreno_check_idle");
      if ( (_DWORD)result )
        result = dev_err(*a1, "Device not idle before SLUMBER\n");
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
