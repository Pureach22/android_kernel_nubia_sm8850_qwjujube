__int64 __fastcall hdd_thermal_mitigation_unregister_wpps(__int64 result, __int64 a2)
{
  if ( *(_BYTE *)(result + 6946) == 1 )
    return pld_thermal_unregister(a2, 2u);
  return result;
}
