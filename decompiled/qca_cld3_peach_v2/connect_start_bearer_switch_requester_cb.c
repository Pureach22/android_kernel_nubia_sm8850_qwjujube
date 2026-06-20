__int64 __fastcall connect_start_bearer_switch_requester_cb(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        unsigned int a12,
        unsigned int a13)
{
  return wlan_cm_bearer_switch_resp(a1, a2, a13, a12, a3, a4, a5, a6, a7, a8, a9, a10);
}
