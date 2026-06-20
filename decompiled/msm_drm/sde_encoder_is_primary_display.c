bool __fastcall sde_encoder_is_primary_display(_BOOL8 result)
{
  if ( result )
    return *(_DWORD *)(result + 696) == 1;
  return result;
}
