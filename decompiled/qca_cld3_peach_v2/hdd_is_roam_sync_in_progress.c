bool __fastcall hdd_is_roam_sync_in_progress(__int64 *a1, __int64 a2)
{
  return wlan_cm_is_roam_sync_in_progress(*a1, a2);
}
