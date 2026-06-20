__int64 __fastcall dynamic_page_pool_free(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w9

  if ( (*(_QWORD *)a2 & 0x40) != 0 )
    v5 = *(unsigned __int8 *)(a2 + 64);
  else
    v5 = 0;
  if ( *(_DWORD *)(a1 + 72) == v5 )
    return dynamic_page_pool_add(a1, a2);
  __break(0x800u);
  if ( (a5 & 0x40000000000000LL) == 0 )
    JUMPOUT(0xDA9C);
  return dynamic_page_pool_total(a1, a2);
}
