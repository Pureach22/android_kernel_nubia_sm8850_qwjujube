__int64 __fastcall hdd_thermal_mitigation_unregister(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(a1 + 6946) == 1 )
    pld_thermal_unregister(a2, 2u);
  return pld_thermal_unregister(a2, 1u);
}
