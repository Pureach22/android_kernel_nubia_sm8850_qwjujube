__int64 __fastcall adreno_spin_idle(__int64 a1, unsigned int a2)
{
  __int64 v3; // x24
  __int64 v4; // x24
  __int64 (__fastcall *v5)(_QWORD); // x8
  int v6; // w8
  __int64 v7; // x25
  int v8; // w26
  __int64 v9; // x27
  __int64 v10; // x8
  __int64 result; // x0
  int v12; // w8
  __int64 v13; // x21
  int v14; // w22
  __int64 v15; // x24
  __int64 v16; // x8
  __int64 (__fastcall *v17)(_QWORD); // x8
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = jiffies;
  v4 = _msecs_to_jiffies(a2) + v3;
  do
  {
    __dmb(9u);
    if ( *(_DWORD *)(a1 + 24448) )
      goto LABEL_15;
    v6 = *(_DWORD *)(a1 + 11120);
    v7 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
    if ( v6 != 32 && v6 != 2 )
      goto LABEL_25;
    __dmb(0xBu);
    if ( *(int *)(a1 + 19632) < 1 )
    {
LABEL_2:
      v5 = *(__int64 (__fastcall **)(_QWORD))(v7 + 120);
      if ( *((_DWORD *)v5 - 1) != -1780529452 )
        __break(0x8228u);
      if ( (v5(a1) & 1) != 0 )
        goto LABEL_25;
    }
    else
    {
      v8 = 0;
      v9 = a1;
      while ( 1 )
      {
        v10 = *(int *)(v9 + 14380);
        v18 = 0;
        kgsl_sharedmem_readl(*(_QWORD *)(v9 - 1320LL * (int)v10 + 48), &v18, 32 * v10);
        if ( v18 != *(_DWORD *)(v9 + 14372) )
          break;
        ++v8;
        v9 += 1320;
        if ( v8 >= *(_DWORD *)(a1 + 19632) )
          goto LABEL_2;
      }
    }
  }
  while ( jiffies - v4 < 0 );
  __dmb(9u);
  if ( *(_DWORD *)(a1 + 24448) )
  {
LABEL_15:
    result = 4294967261LL;
    goto LABEL_26;
  }
  v12 = *(_DWORD *)(a1 + 11120);
  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  if ( v12 == 32 || v12 == 2 )
  {
    __dmb(0xBu);
    if ( *(int *)(a1 + 19632) >= 1 )
    {
      v14 = 0;
      v15 = a1;
      do
      {
        v16 = *(int *)(v15 + 14380);
        v18 = 0;
        kgsl_sharedmem_readl(*(_QWORD *)(v15 - 1320LL * (int)v16 + 48), &v18, 32 * v16);
        if ( v18 != *(_DWORD *)(v15 + 14372) )
          goto LABEL_27;
        ++v14;
        v15 += 1320;
      }
      while ( v14 < *(_DWORD *)(a1 + 19632) );
    }
    v17 = *(__int64 (__fastcall **)(_QWORD))(v13 + 120);
    if ( *((_DWORD *)v17 - 1) != -1780529452 )
      __break(0x8228u);
    if ( (v17(a1) & 1) == 0 )
    {
LABEL_27:
      result = 4294967186LL;
      goto LABEL_26;
    }
  }
LABEL_25:
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
