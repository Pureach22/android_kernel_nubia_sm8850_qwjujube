__int64 __fastcall zte_power_supply_ocv2cap_simple(_DWORD *a1, int a2, int a3)
{
  int v3; // w9
  _DWORD *i; // x8

  if ( a2 < 1 )
    return (unsigned int)a1[1];
  v3 = 0;
  for ( i = a1; *i >= a3; i += 2 )
  {
    if ( a2 == ++v3 )
      return (unsigned int)a1[2 * a2 - 1];
  }
  if ( v3 )
    return (unsigned int)((a3 - *i) * (*(i - 1) - i[1]) / (*(i - 2) - *i) + i[1]);
  else
    return (unsigned int)a1[1];
}
