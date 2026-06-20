bool __fastcall wlan_serialization_match_cmd_type(__int64 a1, int a2, int a3)
{
  __int64 v3; // x8

  v3 = -16;
  if ( !a3 )
    v3 = 0;
  return *(_DWORD *)(a1 + v3 + 32) == a2;
}
