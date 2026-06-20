bool __fastcall sde_cesta_is_enabled(int a1)
{
  bool v1; // zf

  if ( a1 )
    v1 = 1;
  else
    v1 = cesta_list_0 == 0;
  return !v1;
}
