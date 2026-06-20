__int64 __fastcall wlan_cm_roam_stop_req(__int64 a1, __int64 a2, unsigned int a3)
{
  return cm_roam_stop_req(a1, a2, a3, nullptr, 0);
}
