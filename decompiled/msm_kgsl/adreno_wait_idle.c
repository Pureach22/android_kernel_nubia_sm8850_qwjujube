__int64 __fastcall adreno_wait_idle(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x20
  int v4; // w22
  __int64 v5; // x24
  __int64 v6; // x8
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 result; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 11112) )
  {
    __break(0x800u);
    result = 4294967261LL;
    goto LABEL_14;
  }
  v1 = *(_DWORD *)(a1 + 11120);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  if ( v1 != 32 && v1 != 2 )
    goto LABEL_11;
  __dmb(0xBu);
  if ( *(int *)(a1 + 19632) >= 1 )
  {
    v4 = 0;
    v5 = a1;
    do
    {
      v6 = *(int *)(v5 + 14380);
      v9 = 0;
      kgsl_sharedmem_readl(*(_QWORD *)(v5 - 1320LL * (int)v6 + 48), &v9, 32 * v6);
      if ( v9 != *(_DWORD *)(v5 + 14372) )
        goto LABEL_12;
      ++v4;
      v5 += 1320;
    }
    while ( v4 < *(_DWORD *)(a1 + 19632) );
  }
  v7 = *(__int64 (__fastcall **)(_QWORD))(v3 + 120);
  if ( *((_DWORD *)v7 - 1) != -1780529452 )
    __break(0x8228u);
  if ( (v7(a1) & 1) != 0 )
  {
LABEL_11:
    result = 0;
    goto LABEL_14;
  }
LABEL_12:
  result = adreno_dispatcher_idle(a1);
  if ( !(_DWORD)result )
    result = adreno_spin_idle(a1, 0x4E20u);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
