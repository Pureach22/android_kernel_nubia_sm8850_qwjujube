__int64 __fastcall sub_297E50(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7)
{
  int8x16_t v7; // q14
  int8x16_t v8; // q19

  return wlan_mlme_is_aux_emlsr_support_by_hwmode(a1, a2, a3, a4, a5, a6, a7, COERCE_LONG_DOUBLE(vabdq_s8(v8, v7)));
}
