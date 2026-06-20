__int64 __fastcall ucfg_mlme_get_coex_unsafe_chan_nb_user_prefer_for_sap(__int64 a1)
{
  return wlan_mlme_get_coex_unsafe_chan_nb_user_prefer_for_sap(a1) & 1;
}
