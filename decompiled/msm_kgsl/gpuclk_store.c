__int64 __fastcall gpuclk_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  __int64 v7; // x21
  __int64 v8; // x10
  unsigned int v9; // w13
  int v10; // w13
  _DWORD *v11; // x8
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v13 = 0;
  v6 = kstrtouint(a3, 0, &v13);
  if ( v6 )
  {
    a4 = v6;
  }
  else
  {
    v7 = *(unsigned int *)(v5 + 10068);
    v8 = v7 - 1;
    while ( 1 )
    {
      LODWORD(v7) = v7 - 1;
      if ( (int)v7 < 0 )
        break;
      if ( (unsigned int)v7 >= 0x20 )
        __break(0x5512u);
      v9 = v8-- & 0x1F;
      v10 = *(_DWORD *)(v5 + 9144 + 28LL * v9) - v13;
      if ( v10 < 0 )
        v10 = -v10;
      if ( v10 <= 4999999 )
      {
        rt_mutex_lock(v5 + 11088);
        v11 = *(_DWORD **)(*(_QWORD *)(v5 + 8752) + 304LL);
        if ( *(v11 - 1) != -227291694 )
          __break(0x8228u);
        if ( ((unsigned int (__fastcall *)(__int64, _QWORD, __int64))v11)(v5, (unsigned int)v7, 3) )
          kgsl_pwrctrl_pwrlevel_change(v5);
        rt_mutex_unlock(v5 + 11088);
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
