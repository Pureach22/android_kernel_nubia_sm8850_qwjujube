__int64 __fastcall extract_thermal_level_stats_tlv(__int64 a1, __int64 a2, unsigned __int8 a3, _DWORD *a4, _DWORD *a5)
{
  __int64 v5; // x8

  if ( !a2 )
    return 4;
  if ( a3 > 4u )
    return 16;
  v5 = *(_QWORD *)(a2 + 16) + 12LL * a3;
  *a4 = *(_DWORD *)(v5 + 4);
  *a5 = *(_DWORD *)(v5 + 8);
  return 0;
}
