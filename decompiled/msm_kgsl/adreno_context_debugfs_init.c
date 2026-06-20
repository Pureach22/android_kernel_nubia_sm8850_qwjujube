__int64 __fastcall adreno_context_debugfs_init(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w8
  unsigned int v5; // w10
  unsigned int v11; // w9
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  _X19 = a2;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)s = 0;
  v14 = 0;
  if ( a2 )
  {
    v4 = *a2;
    if ( *a2 )
    {
      do
      {
        __asm { PRFM            #0x11, [X19] }
        do
          v11 = __ldxr(a2);
        while ( v11 == v4 && __stxr(v4 + 1, a2) );
        v5 = v4;
        if ( v11 == v4 )
          break;
        v5 = 0;
        v4 = v11;
      }
      while ( v11 );
    }
    else
    {
      v5 = 0;
    }
    if ( (((v5 + 1) | v5) & 0x80000000) != 0 )
      refcount_warn_saturate(a2, 0);
  }
  snprintf(s, 0x10u, "%d", _X19[1]);
  result = debugfs_create_file(s, 292, *(_QWORD *)(a1 + 20424), _X19, &ctx_fops);
  _ReadStatusReg(SP_EL0);
  *((_QWORD *)_X19 + 190) = result;
  return result;
}
