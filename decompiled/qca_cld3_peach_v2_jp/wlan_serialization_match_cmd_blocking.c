__int64 __fastcall wlan_serialization_match_cmd_blocking(__int64 a1, int a2)
{
  __int64 v2; // x8

  v2 = -16;
  if ( !a2 )
    v2 = 0;
  return (*(unsigned __int8 *)(a1 + v2 + 52) >> 1) & 1;
}
