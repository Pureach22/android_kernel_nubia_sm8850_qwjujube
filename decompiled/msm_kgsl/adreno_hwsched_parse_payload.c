__int64 __fastcall adreno_hwsched_parse_payload(__int64 a1, int a2)
{
  unsigned __int64 v2; // x9
  __int64 v3; // x10

  if ( !*(_WORD *)(a1 + 2) )
    return 0;
  v2 = 0;
  while ( 1 )
  {
    v3 = a1 + 4 * v2;
    if ( *(_DWORD *)(v3 + 4) == a2 )
      break;
    v2 += 2LL;
    if ( v2 >= *(unsigned __int16 *)(a1 + 2) )
      return 0;
  }
  return *(unsigned int *)(v3 + 8);
}
