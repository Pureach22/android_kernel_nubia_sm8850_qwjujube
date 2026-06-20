__int64 __fastcall hdd_reset_roam_params(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19

  v2 = a2;
  wlan_cm_update_roam_states(a1, a2, 0, 0);
  wlan_cm_update_roam_states(a1, v2, 0, 2);
  return wlan_cm_update_roam_states(a1, v2, 0, 1);
}
