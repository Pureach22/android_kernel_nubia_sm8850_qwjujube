__int64 __fastcall a6xx_rgmu_pm_resume(__int64 a1)
{
  unsigned int v2; // w9
  unsigned int v8; // w11
  __int64 result; // x0
  __int64 v10; // x19
  unsigned __int64 v13; // x10

  if ( (*(_QWORD *)(a1 - 16) & 4) != 0 )
  {
    _X8 = (unsigned int *)(a1 + 20412);
    v2 = *(_DWORD *)(a1 + 20412);
    while ( (int)(v2 - 1) >= 0 )
    {
      __asm { PRFM            #0x11, [X8] }
      while ( 1 )
      {
        v8 = __ldxr(_X8);
        if ( v8 != v2 )
          break;
        if ( !__stlxr(v2 - 1, _X8) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v8 == v2;
      v2 = v8;
      if ( _ZF )
        goto LABEL_13;
    }
    v10 = a1;
    _warn_printk("GPU halt refcount unbalanced\n");
    a1 = v10;
    __break(0x800u);
LABEL_13:
    _X8 = (unsigned __int64 *)(a1 - 16);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    return adreno_dispatcher_start(a1);
  }
  else
  {
    result = _warn_printk("resume invoked without a suspend\n");
    __break(0x800u);
  }
  return result;
}
