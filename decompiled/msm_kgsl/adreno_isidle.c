__int64 __fastcall adreno_isidle(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x20
  int v4; // w22
  __int64 v5; // x24
  __int64 v6; // x8
  __int64 (__fastcall *v7)(_QWORD); // x8
  char v8; // w0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 11120);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  if ( v2 == 32 || v2 == 2 )
  {
    __dmb(0xBu);
    if ( *(int *)(a1 + 19632) < 1 )
    {
LABEL_7:
      v7 = *(__int64 (__fastcall **)(_QWORD))(v3 + 120);
      if ( *((_DWORD *)v7 - 1) != -1780529452 )
        __break(0x8228u);
      v8 = v7(a1);
    }
    else
    {
      v4 = 0;
      v5 = a1;
      while ( 1 )
      {
        v6 = *(int *)(v5 + 14380);
        v10 = 0;
        kgsl_sharedmem_readl(*(_QWORD *)(v5 - 1320LL * (int)v6 + 48), &v10, 32 * v6);
        if ( v10 != *(_DWORD *)(v5 + 14372) )
          break;
        ++v4;
        v5 += 1320;
        if ( v4 >= *(_DWORD *)(a1 + 19632) )
          goto LABEL_7;
      }
      v8 = 0;
    }
  }
  else
  {
    v8 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return v8 & 1;
}
