__int64 __fastcall pwrscale_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  __int64 v7; // x1
  unsigned int (__fastcall *v8)(__int64, __int64, __int64); // x8
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  v6 = kstrtouint(a3, 0, &v10);
  if ( v6 )
  {
    a4 = v6;
  }
  else
  {
    rt_mutex_lock(v5 + 11088);
    v7 = v10;
    v8 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v5 + 8752) + 304LL);
    if ( *((_DWORD *)v8 - 1) != -227291694 )
      __break(0x8228u);
    if ( v8(v5, v7, 5) )
    {
      if ( v10 )
        kgsl_pwrscale_tz_enable(v5);
      else
        kgsl_pwrscale_tz_disable(v5, 0);
    }
    rt_mutex_unlock(v5 + 11088);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
