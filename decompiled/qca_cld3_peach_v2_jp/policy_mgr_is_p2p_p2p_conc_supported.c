__int64 policy_mgr_is_p2p_p2p_conc_supported()
{
  return wlan_mlme_get_p2p_p2p_conc_support() & 1;
}
