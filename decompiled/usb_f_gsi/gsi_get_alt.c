__int64 __fastcall gsi_get_alt(__int64 a1, int a2)
{
  unsigned int v3; // w8

  if ( *(_DWORD *)(a1 + 228) == a2 )
    return 0;
  v3 = *(_DWORD *)(a1 + 224);
  if ( v3 <= 4 && ((1 << v3) & 0x15) != 0 )
    return 0;
  if ( *(_DWORD *)(a1 + 232) == a2 )
    return *(unsigned __int8 *)(a1 + 276);
  return 4294967274LL;
}
