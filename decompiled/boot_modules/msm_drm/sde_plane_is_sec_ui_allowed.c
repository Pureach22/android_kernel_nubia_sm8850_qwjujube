bool __fastcall sde_plane_is_sec_ui_allowed(_BOOL8 result)
{
  if ( result )
    return (*(_BYTE *)(result + 1938) & 0x20) == 0;
  return result;
}
