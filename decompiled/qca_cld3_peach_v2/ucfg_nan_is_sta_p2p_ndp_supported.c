__int64 __fastcall ucfg_nan_is_sta_p2p_ndp_supported(__int64 a1)
{
  return wlan_nan_is_sta_p2p_ndp_supported(a1) & 1;
}
