__int64 __fastcall wlan_hdd_nan_is_supported(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char is_feature_supported_by_fw; // w0

  if ( (cfg_nan_get_enable(*a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
    is_feature_supported_by_fw = sme_is_feature_supported_by_fw(11);
  else
    is_feature_supported_by_fw = 0;
  return is_feature_supported_by_fw & 1;
}
