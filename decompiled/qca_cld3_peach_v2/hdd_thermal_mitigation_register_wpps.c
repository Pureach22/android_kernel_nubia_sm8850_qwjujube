__int64 __fastcall hdd_thermal_mitigation_register_wpps(__int64 result, __int64 a2)
{
  if ( *(_BYTE *)(result + 6946) == 1 )
    return pld_thermal_register(a2, 1, 2u);
  return result;
}
