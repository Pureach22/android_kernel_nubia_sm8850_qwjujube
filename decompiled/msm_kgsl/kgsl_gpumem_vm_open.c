__int64 __fastcall kgsl_gpumem_vm_open(__int64 result)
{
  unsigned int v2; // w8
  unsigned int v3; // w20
  unsigned int v9; // w9
  unsigned int v12; // w9
  __int64 v13; // [xsp+8h] [xbp-8h]

  _X19 = *(unsigned int **)(result + 96);
  if ( !_X19 || (unsigned __int64)_X19 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_14;
  v2 = *_X19;
  if ( *_X19 )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v9 = __ldxr(_X19);
      while ( v9 == v2 && __stxr(v2 + 1, _X19) );
      v3 = v2;
      if ( v9 == v2 )
        break;
      v3 = 0;
      v2 = v9;
    }
    while ( v9 );
  }
  else
  {
    v3 = 0;
  }
  if ( (((v3 + 1) | v3) & 0x80000000) != 0 )
  {
    v13 = result;
    refcount_warn_saturate(_X19, 0);
    result = v13;
    if ( v3 )
      goto LABEL_15;
    goto LABEL_14;
  }
  if ( !v3 )
LABEL_14:
    *(_QWORD *)(result + 96) = 0;
LABEL_15:
  _X8 = _X19 + 92;
  __asm { PRFM            #0x11, [X8] }
  do
    v12 = __ldxr(_X8);
  while ( __stxr(v12 + 1, _X8) );
  return result;
}
