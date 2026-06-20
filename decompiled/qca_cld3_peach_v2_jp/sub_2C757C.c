__int64 __fastcall sub_2C757C(long double a1, long double a2, int16x8_t a3)
{
  int16x8_t v3; // q10

  return wlan_cm_roam_reject_reassoc_event(a1, a2, COERCE_LONG_DOUBLE(vmlsq_laneq_s16(a3, v3, *(int16x8_t *)&a2, 6)));
}
