__int64 __fastcall min_pwrlevel_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  unsigned int v7; // w22
  unsigned int v8; // w1
  __int64 v9; // x8
  unsigned int (__fastcall *v10)(_QWORD); // x8
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12 = 0;
  v6 = kstrtouint(a3, 0, &v12);
  if ( v6 )
  {
    a4 = v6;
  }
  else
  {
    if ( *(_DWORD *)(v5 + 10064) >= v12 )
      v7 = v12;
    else
      v7 = *(_DWORD *)(v5 + 10064);
    rt_mutex_lock(v5 + 11088);
    if ( v7 <= *(_DWORD *)(v5 + 10056) )
      v8 = *(_DWORD *)(v5 + 10056);
    else
      v8 = v7;
    v9 = *(_QWORD *)(v5 + 8752);
    *(_DWORD *)(v5 + 10060) = v8;
    v10 = *(unsigned int (__fastcall **)(_QWORD))(v9 + 304);
    if ( *((_DWORD *)v10 - 1) != -227291694 )
      __break(0x8228u);
    if ( v10(v5) )
      kgsl_pwrctrl_pwrlevel_change(v5);
    rt_mutex_unlock(v5 + 11088);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
