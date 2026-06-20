__int64 __fastcall sde_plane_set_revalidate(__int64 result, char a2)
{
  if ( result )
    *(_BYTE *)(result + 2416) = a2 & 1;
  return result;
}
