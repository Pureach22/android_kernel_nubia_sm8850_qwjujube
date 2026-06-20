__int64 __fastcall kgsl_proc_state_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v8; // w8
  unsigned int v9; // w21
  unsigned int v11; // w9
  unsigned __int64 v19; // x9
  unsigned __int64 v22; // x10

  if ( (sysfs_streq(a3, "foreground") & 1) != 0 )
  {
    _X10 = (unsigned __int64 *)(a1 + 288);
    __asm { PRFM            #0x11, [X10] }
    do
      v19 = __ldxr(_X10);
    while ( __stlxr(v19 | 2, _X10) );
    __dmb(0xBu);
    if ( a1 != 104 && (v19 & 2) == 0 )
    {
      _X0 = (unsigned int *)(a1 - 68);
      v8 = *(_DWORD *)(a1 - 68);
      if ( v8 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v11 = __ldxr(_X0);
          while ( v11 == v8 && __stxr(v8 + 1, _X0) );
          v9 = v8;
          if ( v11 == v8 )
            break;
          v9 = 0;
          v8 = v11;
        }
        while ( v11 );
      }
      else
      {
        v9 = 0;
      }
      if ( (((v9 + 1) | v9) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X0, 0);
        if ( !v9 )
          return a4;
        goto LABEL_17;
      }
      if ( v9 )
LABEL_17:
        queue_work_on(32, qword_3A900, a1 + 304);
    }
  }
  else if ( (sysfs_streq(a3, "background") & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)(a1 + 288);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  }
  else
  {
    return -22;
  }
  return a4;
}
