__int64 __fastcall a6xx_gmu_pm_resume(__int64 a1)
{
  unsigned int v3; // w9
  unsigned int v9; // w11
  __int64 result; // x0
  __int64 v11; // x20
  unsigned __int64 v13; // x9

  _X19 = (unsigned __int64 *)(a1 - 352);
  if ( (*(_QWORD *)(a1 - 352) & 0x10) != 0 )
  {
    _X8 = (unsigned int *)(a1 + 20412);
    v3 = *(_DWORD *)(a1 + 20412);
    while ( (int)(v3 - 1) >= 0 )
    {
      __asm { PRFM            #0x11, [X8] }
      while ( 1 )
      {
        v9 = __ldxr(_X8);
        if ( v9 != v3 )
          break;
        if ( !__stlxr(v3 - 1, _X8) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v9 == v3;
      v3 = v9;
      if ( _ZF )
        goto LABEL_13;
    }
    v11 = a1;
    _warn_printk("GPU halt refcount unbalanced\n");
    a1 = v11;
    __break(0x800u);
LABEL_13:
    result = adreno_dispatcher_start(a1);
    __asm { PRFM            #0x11, [X19] }
    do
      v13 = __ldxr(_X19);
    while ( __stxr(v13 & 0xFFFFFFFFFFFFFFEFLL, _X19) );
  }
  else
  {
    result = _warn_printk("resume invoked without a suspend\n");
    __break(0x800u);
  }
  return result;
}
