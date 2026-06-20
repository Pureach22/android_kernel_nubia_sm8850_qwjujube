__int64 __fastcall _free_zspage(__int64 result, unsigned int *a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v8; // x26
  __int64 v9; // x8
  unsigned __int64 v15; // x8
  unsigned int v18; // w8
  unsigned int v19; // w8
  unsigned __int64 v22; // x10

  v4 = *a2;
  if ( (_DWORD)v4 )
  {
    _X22 = *(_QWORD *)(a3 + 16);
    v3 = result;
    while ( 1 )
    {
      v4 = **(unsigned int **)(_X22 + 40);
      if ( (v4 & 0x3FC000) != 0x160000 )
        break;
      if ( (v4 & 1) != 0 )
        v8 = 0;
      else
        v8 = *(_QWORD *)(_X22 + 32);
      _ClearPageMovable(_X22);
      __asm { PRFM            #0x11, [X22] }
      do
        v15 = __ldxr((unsigned __int64 *)_X22);
      while ( __stxr(v15 & 0xFFFFFFFFFFFF7FFFLL, (unsigned __int64 *)_X22) );
      *(_QWORD *)(_X22 + 32) = 0;
      *(_QWORD *)(_X22 + 40) = 0;
      *(_DWORD *)(_X22 + 48) = -1;
      unlock_page(_X22);
      result = dec_zone_page_state(_X22, 9);
      v9 = *(_QWORD *)(_X22 + 8);
      if ( (v9 & 1) != 0 )
        _X22 = v9 - 1;
      _X9 = (unsigned int *)(_X22 + 52);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v18 = __ldxr(_X9);
        v19 = v18 - 1;
      }
      while ( __stlxr(v19, _X9) );
      __dmb(0xBu);
      if ( !v19 )
        result = _folio_put(_X22);
      _X22 = v8;
      if ( !v8 )
      {
        result = kmem_cache_free(*(_QWORD *)(v3 + 2056), a3);
        v4 = (int)a2[52];
        *((_QWORD *)a2 + 39) -= (int)a2[51];
        goto LABEL_21;
      }
    }
    __break(0x800u);
  }
  __break(0x800u);
LABEL_21:
  _X9 = (unsigned __int64 *)(v3 + 2064);
  __asm { PRFM            #0x11, [X9] }
  do
    v22 = __ldxr(_X9);
  while ( __stxr(v22 - v4, _X9) );
  return result;
}
