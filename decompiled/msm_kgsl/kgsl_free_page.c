__int64 __fastcall kgsl_free_page(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  unsigned int v4; // w8
  unsigned int v11; // w8
  unsigned int v12; // w8

  if ( *(_QWORD *)(a1 + 112) )
  {
    v2 = *(_QWORD *)(a2 + 8);
    if ( (v2 & 1) != 0 )
      result = v2 - 1;
    else
      result = a2;
    _X9 = (unsigned int *)(result + 52);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v11 = __ldxr(_X9);
      v12 = v11 - 1;
    }
    while ( __stlxr(v12, _X9) );
    __dmb(0xBu);
    if ( !v12 )
      return _folio_put();
  }
  else
  {
    if ( (*(_QWORD *)a2 & 0x40) != 0 )
      v4 = *(unsigned __int8 *)(a2 + 64);
    else
      v4 = 0;
    return _free_pages(a2, v4);
  }
  return result;
}
