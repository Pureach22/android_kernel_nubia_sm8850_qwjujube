__int64 __fastcall policy_mgr_is_p2p_p2p_conc_supported(__int64 a1)
{
  return wlan_mlme_get_p2p_p2p_conc_support(a1) & 1;
}
