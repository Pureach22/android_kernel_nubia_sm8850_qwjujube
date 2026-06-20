bool __fastcall sde_encoder_is_dsi_display(_BOOL8 result)
{
  if ( result )
    return *(_DWORD *)(result + 640) == 16;
  return result;
}
