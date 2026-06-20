__int64 __fastcall sde_dbg_update_dump_mode(__int64 result)
{
  int v1; // w8

  if ( (result & 1) != 0 )
    v1 = 8;
  else
    v1 = 2;
  dword_29437C = v1;
  *(_DWORD *)(sde_dbg_base + 786456) = v1;
  return result;
}
