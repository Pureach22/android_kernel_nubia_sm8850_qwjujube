__int64 __fastcall SetZsPageMovable(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x9
  __int64 result; // x0
  int v5; // w8
  unsigned __int64 v11; // x9

  v1 = *(_QWORD *)(a1 + 16);
  while ( 1 )
  {
    v2 = *(_QWORD *)(v1 + 8);
    _X8 = (unsigned __int64 *)v1;
    if ( (v2 & 1) != 0 )
    {
      _X8 = (unsigned __int64 *)(v2 - 1);
      if ( (*(_QWORD *)(v2 - 1) & 1) != 0 )
        goto LABEL_10;
    }
    else if ( (*(_QWORD *)v1 & 1) != 0 )
    {
      goto LABEL_10;
    }
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldaxr(_X8);
    while ( __stxr(v11 | 1, _X8) );
    if ( (v11 & 1) != 0 )
LABEL_10:
      __break(0x800u);
    _SetPageMovable(v1, zsmalloc_mops);
    result = unlock_page(v1);
    v5 = **(_DWORD **)(v1 + 40);
    if ( (v5 & 0x3FC000) != 0x160000 )
      break;
    if ( (v5 & 1) == 0 )
    {
      v1 = *(_QWORD *)(v1 + 32);
      if ( v1 )
        continue;
    }
    return result;
  }
  __break(0x800u);
  return zs_free(result);
}
