__int64 __fastcall ipv6_addr_cmp(unsigned __int64 *a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x9

  v2 = bswap64(*a1);
  v3 = bswap64(*a2);
  if ( v2 == v3 )
  {
    v2 = bswap64(a1[1]);
    v3 = bswap64(a2[1]);
    if ( v2 == v3 )
      return 0;
  }
  if ( v2 < v3 )
    return 0xFFFFFFFFLL;
  return 1;
}
