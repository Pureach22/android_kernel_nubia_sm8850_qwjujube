bool __fastcall sde_cesta_is_aoss_supported(int a1)
{
  _BOOL8 result; // x0

  result = 0;
  if ( !a1 )
  {
    if ( cesta_list_0 )
      return *(_DWORD *)cesta_list_0 >> 8 < 0x403u;
  }
  return result;
}
