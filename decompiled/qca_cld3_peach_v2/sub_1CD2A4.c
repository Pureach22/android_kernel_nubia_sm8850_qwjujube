__int64 __fastcall sub_1CD2A4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( !a5 )
    JUMPOUT(0x10289C);
  return wlan_serialization_find_and_start_timer(a1, a2);
}
