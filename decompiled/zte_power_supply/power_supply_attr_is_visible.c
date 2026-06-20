__int64 __fastcall power_supply_attr_is_visible(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 *v3; // x0
  __int64 v4; // x8
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x12
  int v7; // w11
  int (*v9)(void); // x8

  if ( a3 >= 0x13 )
  {
    __break(0x5512u);
    JUMPOUT(0x916C);
  }
  if ( !(&zte_power_supply_attrs)[11 * a3] )
    return 0;
  v3 = *(__int64 **)(a1 + 152);
  v4 = *v3;
  v5 = *(_QWORD *)(*v3 + 40);
  if ( !v5 )
    return 0;
  v6 = 0;
  v7 = 1;
  while ( *(_DWORD *)(*(_QWORD *)(v4 + 32) + 4 * v6) != a3 )
  {
    v6 = v7++;
    if ( v5 <= v6 )
      return 0;
  }
  v9 = *(int (**)(void))(v4 + 64);
  if ( !v9 )
    return 292;
  if ( *((_DWORD *)v9 - 1) != 1057561745 )
    __break(0x8228u);
  if ( v9() <= 0 )
    return 292;
  else
    return 420;
}
