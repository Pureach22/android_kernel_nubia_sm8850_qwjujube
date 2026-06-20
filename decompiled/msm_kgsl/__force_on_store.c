__int64 __fastcall _force_on_store(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v7; // x20
  int v8; // w0
  unsigned __int64 v12; // x10
  unsigned __int64 v19; // x10
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 152);
  v20 = 0;
  if ( gmu_core_gpmu_isenabled(v7) )
  {
    a3 = -95;
  }
  else
  {
    v8 = kstrtouint(a2, 0, &v20);
    if ( v8 )
    {
      a3 = v8;
    }
    else
    {
      rt_mutex_lock(v7 + 11088);
      if ( v20 )
      {
        if ( a4 )
        {
          if ( a4 == 2 )
          {
            kgsl_pwrctrl_axi(v7, 1);
          }
          else
          {
            kgsl_pwrctrl_pwrrail(v7, 1);
            kgsl_pwrctrl_clk(v7, 1, 2);
          }
        }
        else
        {
          kgsl_pwrctrl_pwrrail(v7, 1);
        }
        _X9 = (unsigned __int64 *)(v7 + 9136);
        __asm { PRFM            #0x11, [X9] }
        do
          v12 = __ldxr(_X9);
        while ( __stxr(v12 | (1LL << a4), _X9) );
      }
      else
      {
        _X9 = (unsigned __int64 *)(v7 + 9136);
        __asm { PRFM            #0x11, [X9] }
        do
          v19 = __ldxr(_X9);
        while ( __stxr(v19 & ~(1LL << a4), _X9) );
      }
      rt_mutex_unlock(v7 + 11088);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
