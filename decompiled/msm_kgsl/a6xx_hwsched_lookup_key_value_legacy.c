__int64 __fastcall a6xx_hwsched_lookup_key_value_legacy(__int64 a1, int a2)
{
  _DWORD *v2; // x9
  unsigned int v3; // w8
  unsigned int v4; // w10
  _DWORD *v5; // x9
  unsigned __int16 *v6; // x0

  v2 = *(_DWORD **)(a1 + 22792);
  if ( !*v2 )
    return 0;
  v3 = ((*v2 >> 6) & 0x3FC) - 20;
  if ( ((*v2 >> 6) & 0x3FC) == 0x14 )
    return 0;
  v4 = 0;
  v5 = v2 + 5;
  while ( 1 )
  {
    v6 = (unsigned __int16 *)((char *)v5 + v4);
    if ( *v6 == a2 )
      break;
    v4 += 4 * v6[1] + 4;
    if ( v4 >= v3 )
      return 0;
  }
  return adreno_hwsched_parse_payload();
}
