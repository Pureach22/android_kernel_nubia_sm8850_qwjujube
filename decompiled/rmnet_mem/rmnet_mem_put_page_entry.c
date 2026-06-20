__int64 __fastcall rmnet_mem_put_page_entry(__int64 result)
{
  __int64 v1; // x8
  unsigned int v8; // w8
  unsigned int v9; // w8

  v1 = *(_QWORD *)(result + 8);
  if ( (v1 & 1) != 0 )
    result = v1 - 1;
  _X9 = (unsigned int *)(result + 52);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v8 = __ldxr(_X9);
    v9 = v8 - 1;
  }
  while ( __stlxr(v9, _X9) );
  __dmb(0xBu);
  if ( !v9 )
    return _folio_put();
  return result;
}
