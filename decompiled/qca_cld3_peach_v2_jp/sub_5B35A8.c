__int64 __fastcall sub_5B35A8(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29

  __arm_mte_get_tag((void *)(v3 - 240));
  return cm_update_scan_mlme_on_roam(a1, a2, a3);
}
