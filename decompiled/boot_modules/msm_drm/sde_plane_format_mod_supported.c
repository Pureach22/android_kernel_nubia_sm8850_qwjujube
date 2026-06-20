bool __fastcall sde_plane_format_mod_supported(__int64 a1, unsigned int a2, __int64 a3)
{
  return sde_get_sde_format_ext(a2, a3) != 0;
}
