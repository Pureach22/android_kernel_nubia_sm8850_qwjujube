__int64 __fastcall sub_2C8764(long double a1, long double a2, float a3)
{
  short float v3; // h19
  short float v4; // h29

  *(short float *)&a3 = v4 - (short float)(v4 * v3);
  return wlan_cm_update_roam_rt_stats(a1, a2, a3);
}
