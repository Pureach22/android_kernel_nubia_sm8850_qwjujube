bool __fastcall wlan_serialization_match_cmd_pdev(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8

  v3 = -16;
  if ( !a3 )
    v3 = 0;
  return *(_QWORD *)(*(_QWORD *)(a1 + v3 + 64) + 216LL) == a2;
}
