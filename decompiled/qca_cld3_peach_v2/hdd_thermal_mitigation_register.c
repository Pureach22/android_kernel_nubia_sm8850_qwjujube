__int64 __fastcall hdd_thermal_mitigation_register(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = pld_thermal_register(a2, 5, 1u);
  if ( *(_BYTE *)(a1 + 6946) == 1 )
    return pld_thermal_register(a2, 1, 2u);
  return result;
}
