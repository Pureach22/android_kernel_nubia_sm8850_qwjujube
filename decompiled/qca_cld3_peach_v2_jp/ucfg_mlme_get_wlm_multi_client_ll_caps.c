__int64 __fastcall ucfg_mlme_get_wlm_multi_client_ll_caps(__int64 a1)
{
  return wlan_mlme_get_wlm_multi_client_ll_caps(a1) & 1;
}
