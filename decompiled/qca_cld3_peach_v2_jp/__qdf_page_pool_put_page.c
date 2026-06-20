__int64 __fastcall _qdf_page_pool_put_page(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  __int64 result; // x0
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x9

  v2 = a2 & 0xFFFFFFFFFFFFFFFELL;
  if ( *(_QWORD *)((a2 & 0xFFFFFFFFFFFFFFFELL) + 40) == 1 )
    return page_pool_put_unrefed_netmem();
  _X10 = (unsigned __int64 *)(v2 + 40);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v10 = __ldxr(_X10);
    v11 = v10 - 1;
  }
  while ( __stlxr(v11, _X10) );
  __dmb(0xBu);
  if ( (v11 & 0x8000000000000000LL) != 0 )
  {
    __break(0x800u);
  }
  else if ( !v11 )
  {
    *(_QWORD *)(v2 + 40) = 1;
    return page_pool_put_unrefed_netmem();
  }
  return result;
}
