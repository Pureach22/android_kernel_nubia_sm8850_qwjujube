__int64 __fastcall sub_2C7D04(long double a1)
{
  float32x2_t v1; // d9
  float32x2_t v2; // d25

  return wlan_mlme_cfg_get_aux_supported_modes(a1, vadd_f32(v1, v2).n64_f64[0]);
}
