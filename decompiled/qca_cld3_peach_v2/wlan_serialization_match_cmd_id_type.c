bool __fastcall wlan_serialization_match_cmd_id_type(__int64 a1, _DWORD *a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x8

  if ( !a2 )
    return 0;
  v3 = -16;
  if ( !a3 )
    v3 = 0;
  v4 = a1 + v3;
  return *(_DWORD *)(v4 + 36) == a2[1] && *(_DWORD *)(v4 + 32) == *a2;
}
