bool __fastcall sde_encoder_is_built_in_display(_BOOL8 result)
{
  if ( result )
    return (unsigned int)(*(_DWORD *)(result + 696) - 1) < 2;
  return result;
}
