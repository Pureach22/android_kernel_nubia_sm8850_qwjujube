__int64 __fastcall sub_2197DC(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x22

  *(_DWORD *)(v3 - 8) = 0;
  *(_DWORD *)(v3 - 4) = a3;
  return wmi_unified_extract_roam_trigger_stats();
}
