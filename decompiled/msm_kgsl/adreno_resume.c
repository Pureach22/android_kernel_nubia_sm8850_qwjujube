__int64 __fastcall adreno_resume(__int64 result)
{
  int v1; // w8
  unsigned int v3; // w9
  unsigned int v9; // w11
  __int64 v10; // x19
  _QWORD *v11; // x19
  __int64 v12; // x19

  v1 = *(_DWORD *)(result + 11120);
  if ( v1 != 1 )
  {
    if ( v1 == 16 )
    {
      _X8 = (unsigned int *)(result + 20412);
      v3 = *(_DWORD *)(result + 20412);
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
          return kgsl_pwrctrl_change_state(result, 128);
      }
      v12 = result;
      _warn_printk("GPU halt refcount unbalanced\n");
      result = v12;
      __break(0x800u);
      return kgsl_pwrctrl_change_state(result, 128);
    }
    else
    {
      if ( v1 == 2 )
      {
        v10 = result;
        adreno_wait_idle(result);
        result = v10;
      }
      v11 = (_QWORD *)result;
      kgsl_pwrctrl_change_state(result, 128);
      return dev_err(*v11, "resume invoked without a suspend\n");
    }
  }
  return result;
}
