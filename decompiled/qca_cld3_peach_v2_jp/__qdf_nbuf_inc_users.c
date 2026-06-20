__int64 __fastcall _qdf_nbuf_inc_users(__int64 a1)
{
  __int64 v1; // x8
  __int64 v4; // x19
  unsigned int v10; // w9

  v1 = a1;
  _X0 = (unsigned int *)(a1 + 236);
  __asm { PRFM            #0x11, [X0] }
  do
    v10 = __ldxr(_X0);
  while ( __stxr(v10 + 1, _X0) );
  if ( !v10 )
  {
    v4 = v1;
    goto LABEL_8;
  }
  if ( (((v10 + 1) | v10) & 0x80000000) != 0 )
  {
    v4 = v1;
LABEL_8:
    refcount_warn_saturate();
    return v4;
  }
  return v1;
}
