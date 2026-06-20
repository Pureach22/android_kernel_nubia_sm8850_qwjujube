__int64 __fastcall sde_dump_blk_phys_addr_cmp(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  result = 0;
  if ( a2 )
  {
    if ( a3 )
      return (unsigned int)(*(_DWORD *)(a2 + 120) - *(_DWORD *)(a3 + 120));
  }
  return result;
}
