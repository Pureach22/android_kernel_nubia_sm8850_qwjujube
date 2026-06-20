__int64 __fastcall sde_cesta_get_phandle(int a1)
{
  __int64 v1; // x8

  if ( cesta_list_0 )
    v1 = cesta_list_0 + 16;
  else
    v1 = 0;
  if ( a1 )
    return 0;
  else
    return v1;
}
