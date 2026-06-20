__int64 __fastcall sde_plane_set_error(__int64 result, char a2)
{
  if ( result )
    *(_BYTE *)(result + 2380) = a2 & 1;
  return result;
}
