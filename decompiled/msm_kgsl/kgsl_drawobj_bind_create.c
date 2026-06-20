__int64 __fastcall kgsl_drawobj_bind_create(__int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  unsigned int v5; // w8
  unsigned int v6; // w21
  unsigned int v12; // w9
  __int64 v13; // [xsp+8h] [xbp-8h]

  _X19 = a2;
  result = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  if ( !result )
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
      v13 = result;
      refcount_warn_saturate(_X19, 0);
      result = v13;
      if ( v6 )
        goto LABEL_14;
    }
    else if ( v6 )
    {
LABEL_14:
      *(_DWORD *)(result + 32) = 1;
      *(_DWORD *)(result + 16) = 8;
      *(_QWORD *)result = a1;
      *(_QWORD *)(result + 8) = _X19;
      *(_QWORD *)(result + 40) = bindobj_destroy;
      *(_QWORD *)(result + 48) = bindobj_destroy_object;
      return result;
    }
  }
  kfree(result);
  return -2;
}
