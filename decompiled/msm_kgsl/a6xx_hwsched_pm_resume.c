__int64 __fastcall a6xx_hwsched_pm_resume(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v5; // w9
  unsigned int v11; // w11
  __int64 result; // x0
  unsigned __int64 v15; // x10

  v2 = to_a6xx_gmu(a1);
  if ( (*(_QWORD *)(v2 + 1296) & 0x10) != 0 )
  {
    v3 = v2;
    _X8 = (unsigned int *)(a1 + 20412);
    v5 = *(_DWORD *)(a1 + 20412);
    while ( (int)(v5 - 1) >= 0 )
    {
      __asm { PRFM            #0x11, [X8] }
      while ( 1 )
      {
        v11 = __ldxr(_X8);
        if ( v11 != v5 )
          break;
        if ( !__stlxr(v5 - 1, _X8) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v11 == v5;
      v5 = v11;
      if ( _ZF )
        goto LABEL_13;
    }
    _warn_printk("GPU halt refcount unbalanced\n");
    __break(0x800u);
LABEL_13:
    result = adreno_hwsched_start(a1);
    _X8 = (unsigned __int64 *)(v3 + 1296);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
  }
  else
  {
    result = _warn_printk("resume invoked without a suspend\n");
    __break(0x800u);
  }
  return result;
}
