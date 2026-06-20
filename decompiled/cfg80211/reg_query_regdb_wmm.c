__int64 __fastcall reg_query_regdb_wmm(unsigned __int8 *a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v3; // w10
  unsigned __int8 *i; // x9
  __int64 v5; // x11
  __int64 v6; // x10
  __int64 j; // x11
  unsigned __int8 *v8; // x2

  if ( !regdb )
    return 4294967235LL;
  if ( (unsigned __int64)regdb >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)regdb;
  v3 = *(unsigned __int16 *)(regdb + 10);
  if ( !*(_WORD *)(regdb + 10) )
    return 4294967235LL;
  for ( i = (unsigned __int8 *)(regdb + 8); !a1 || !i || *a1 != *i || a1[1] != i[1]; i += 4 )
  {
    v3 = *((unsigned __int16 *)i + 3);
    if ( !v3 )
      return 4294967235LL;
  }
  v5 = 4LL * (bswap32(v3) >> 16);
  v6 = *(unsigned __int8 *)(regdb + v5 + 1);
  if ( !*(_BYTE *)(regdb + v5 + 1) )
    return 4294967235LL;
  result = 4294967235LL;
  for ( j = v5 + ((*(unsigned __int8 *)(regdb + v5) + 1) & 0x1FE); ; j += 2 )
  {
    v8 = (unsigned __int8 *)(regdb + 4LL * (bswap32(*(unsigned __int16 *)(regdb + j)) >> 16));
    if ( *v8 >= 0x14u && bswap32(*((_DWORD *)v8 + 1)) / 0x3E8 <= a2 && bswap32(*((_DWORD *)v8 + 2)) / 0x3E8 >= a2 )
      break;
    if ( !--v6 )
      return result;
  }
  set_wmm_rule(regdb, i);
  return 0;
}
