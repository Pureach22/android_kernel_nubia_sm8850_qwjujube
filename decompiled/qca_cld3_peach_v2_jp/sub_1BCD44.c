__int64 __fastcall sub_1BCD44(long double a1)
{
  int8x16_t v1; // q20
  int8x16_t v2; // q25

  return wlan_sm_get_state_name(a1, COERCE_LONG_DOUBLE(vextq_s8(v2, v1, 7u)));
}
