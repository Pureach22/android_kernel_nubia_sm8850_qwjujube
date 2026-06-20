__int64 __fastcall kgsl_drawobj_sync_create(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  unsigned int v5; // w8
  unsigned int v6; // w21
  unsigned int v12; // w9
  __int64 v13; // x19
  __int64 v15; // [xsp+8h] [xbp-8h]

  _X19 = a2;
  v4 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 152);
  if ( !v4 )
    return -12;
  if ( _X19 )
  {
    v5 = *_X19;
    if ( *_X19 )
    {
      do
      {
        __asm { PRFM            #0x11, [X19] }
        do
          v12 = __ldxr(_X19);
        while ( v12 == v5 && __stxr(v5 + 1, _X19) );
        v6 = v5;
        if ( v12 == v5 )
          break;
        v6 = 0;
        v5 = v12;
      }
      while ( v12 );
    }
    else
    {
      v6 = 0;
    }
    if ( (((v6 + 1) | v6) & 0x80000000) != 0 )
    {
      v15 = v4;
      refcount_warn_saturate(_X19, 0);
      v4 = v15;
      if ( v6 )
        goto LABEL_14;
    }
    else if ( v6 )
    {
LABEL_14:
      *(_DWORD *)(v4 + 32) = 1;
      *(_DWORD *)(v4 + 16) = 4;
      *(_QWORD *)v4 = a1;
      *(_QWORD *)(v4 + 8) = _X19;
      v13 = v4;
      *(_QWORD *)(v4 + 40) = syncobj_destroy;
      *(_QWORD *)(v4 + 48) = syncobj_destroy_object;
      init_timer_key(v4 + 80, syncobj_timer, 0, 0, 0);
      return v13;
    }
  }
  kfree(v4);
  return -2;
}
