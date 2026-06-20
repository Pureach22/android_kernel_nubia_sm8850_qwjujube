__int64 __fastcall fastrpc_lowest_capacity_corecount(__int64 a1, __int64 a2)
{
  char v2; // w13
  __int64 v3; // x8
  bool v4; // cf
  unsigned __int64 v5; // x13
  unsigned __int64 v6; // x13

  v2 = 0;
  v3 = _cpu_possible_mask;
  do
  {
    v5 = v3 & (-1LL << v2);
    if ( !v5 )
      break;
    v6 = __clz(__rbit64(v5));
    if ( !cpu_topology[12 * (unsigned int)v6 + 2] )
      ++*(_DWORD *)(a2 + 52696);
    v4 = v6 >= 0x1F;
    v2 = v6 + 1;
  }
  while ( !v4 );
  return dev_info(a1, "Lowest capacity core count: %u\n", *(_DWORD *)(a2 + 52696));
}
