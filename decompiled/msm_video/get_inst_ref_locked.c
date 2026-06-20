__int64 __fastcall get_inst_ref_locked(__int64 result)
{
  unsigned int v1; // w9
  unsigned int v3; // w19
  unsigned int v9; // w10
  __int64 v10; // x20

  v1 = *(_DWORD *)(result + 328);
  _X8 = (unsigned int *)(result + 328);
  if ( v1 )
  {
    do
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v9 = __ldxr(_X8);
      while ( v9 == v1 && __stxr(v1 + 1, _X8) );
      v3 = v1;
      if ( v9 == v1 )
        break;
      v3 = 0;
      v1 = v9;
    }
    while ( v9 );
  }
  else
  {
    v3 = 0;
  }
  if ( (((v3 + 1) | v3) & 0x80000000) != 0 )
  {
    v10 = result;
    refcount_warn_saturate(result + 328, 0);
    result = v10;
  }
  if ( !v3 )
    return 0;
  return result;
}
