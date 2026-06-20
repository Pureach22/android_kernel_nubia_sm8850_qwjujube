__int64 __fastcall cb_object_alloc(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v6; // x1
  unsigned int v13; // w9

  v1 = fget(a1);
  if ( v1 )
  {
    if ( *(_UNKNOWN ***)(v1 + 16) != &server_fops )
    {
      v2 = -9;
LABEL_10:
      fput(v1);
      return v2;
    }
    v3 = v1;
    v2 = _kmalloc_cache_noprof(_trace_trigger_soft_disabled, 3520, 112);
    v1 = v3;
    if ( !v2 )
    {
      v2 = -12;
      goto LABEL_10;
    }
    *(_DWORD *)(v2 + 88) = 1;
    v4 = *(_QWORD *)(v3 + 32);
    *(_QWORD *)(v2 + 104) = v4;
    _X8 = (unsigned int *)(v4 + 16);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 + 1, _X8) );
    if ( v13 )
    {
      if ( (((v13 + 1) | v13) & 0x80000000) == 0 )
        goto LABEL_10;
      v6 = 1;
    }
    else
    {
      v6 = 2;
    }
    refcount_warn_saturate(_X8, v6);
    v1 = v3;
    goto LABEL_10;
  }
  return -9;
}
