__int64 __fastcall min_clock_mhz_store(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w0
  int v6; // w9
  __int64 v7; // x8
  __int64 v8; // x11
  unsigned int v9; // w14
  int v10; // w14
  unsigned int v11; // w22
  unsigned int v12; // w1
  __int64 v13; // x8
  unsigned int (__fastcall *v14)(_QWORD); // x8
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v5 = kstrtouint(a2, 0, &v16);
  if ( v5 )
  {
    a3 = v5;
  }
  else
  {
    v6 = 1000000 * v16;
    v7 = *(unsigned int *)(a1 + 10068);
    v8 = v7 - 1;
    v16 *= 1000000;
    while ( 1 )
    {
      LODWORD(v7) = v7 - 1;
      if ( (int)v7 < 0 )
        break;
      if ( (unsigned int)v7 >= 0x20 )
        __break(0x5512u);
      v9 = v8-- & 0x1F;
      v10 = *(_DWORD *)(a1 + 9144 + 28LL * v9) - v6;
      if ( v10 < 0 )
        v10 = -v10;
      if ( v10 <= 4999999 )
      {
        if ( *(_DWORD *)(a1 + 10064) >= (unsigned int)v7 )
          v11 = v7;
        else
          v11 = *(_DWORD *)(a1 + 10064);
        rt_mutex_lock(a1 + 11088);
        if ( v11 <= *(_DWORD *)(a1 + 10056) )
          v12 = *(_DWORD *)(a1 + 10056);
        else
          v12 = v11;
        v13 = *(_QWORD *)(a1 + 8752);
        *(_DWORD *)(a1 + 10060) = v12;
        v14 = *(unsigned int (__fastcall **)(_QWORD))(v13 + 304);
        if ( *((_DWORD *)v14 - 1) != -227291694 )
          __break(0x8228u);
        if ( v14(a1) )
          kgsl_pwrctrl_pwrlevel_change(a1);
        rt_mutex_unlock(a1 + 11088);
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
