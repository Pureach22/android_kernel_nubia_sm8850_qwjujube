__int64 __fastcall adreno_waittimestamp(const char ***a1, __int64 a2)
{
  __int64 result; // x0
  const char **v4; // x8
  const char *v6; // x0
  const char *v7; // x2
  unsigned __int64 v14; // x8

  if ( a2 )
  {
    if ( (*(_QWORD *)(a2 + 32) & 2) != 0 )
    {
      return 4294967294LL;
    }
    else
    {
      LODWORD(result) = adreno_drawctxt_wait();
      if ( (*(_QWORD *)(a2 + 32) & 4LL) != 0 )
        result = 4294967261LL;
      else
        result = (unsigned int)result;
      if ( !(_DWORD)result )
      {
        _X9 = (unsigned __int64 *)(a2 + 32);
        __asm { PRFM            #0x11, [X9] }
        do
          v14 = __ldxr(_X9);
        while ( __stlxr(v14 & 0xFFFFFFFFFFFEFFFFLL, _X9) );
        __dmb(0xBu);
        if ( (v14 & 0x10000) != 0 )
          return 4294967225LL;
        else
          return 0;
      }
    }
  }
  else if ( (adreno_waittimestamp___already_done & 1) != 0 )
  {
    return 4294967271LL;
  }
  else
  {
    v4 = *a1;
    adreno_waittimestamp___already_done = 1;
    v6 = (const char *)dev_driver_string(v4);
    v7 = (*a1)[14];
    if ( !v7 )
      v7 = **a1;
    _warn_printk("%s %s: IOCTL_KGSL_DEVICE_WAITTIMESTAMP is deprecated\n", v6, v7);
    __break(0x800u);
    return 4294967271LL;
  }
  return result;
}
