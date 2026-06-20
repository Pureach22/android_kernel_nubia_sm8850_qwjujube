__int64 __fastcall max_pwrlevel_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  unsigned int v7; // w1
  __int64 v8; // x8
  unsigned int (__fastcall *v9)(_QWORD); // x8
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v11 = 0;
  v6 = kstrtouint(a3, 0, &v11);
  if ( v6 )
  {
    a4 = v6;
  }
  else
  {
    rt_mutex_lock(v5 + 11088);
    v7 = v11;
    if ( v11 > *(_DWORD *)(v5 + 10060) )
    {
      v7 = *(_DWORD *)(v5 + 10060);
      v11 = v7;
    }
    v8 = *(_QWORD *)(v5 + 8752);
    *(_DWORD *)(v5 + 10056) = v7;
    v9 = *(unsigned int (__fastcall **)(_QWORD))(v8 + 304);
    if ( *((_DWORD *)v9 - 1) != -227291694 )
      __break(0x8228u);
    if ( v9(v5) )
      kgsl_pwrctrl_pwrlevel_change(v5);
    rt_mutex_unlock(v5 + 11088);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
