__int64 __fastcall sub_1B7CC8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( !a5 )
    JUMPOUT(0xED2C0);
  return wlan_serialization_find_and_stop_timer(a1, a2);
}
