__int64 __fastcall ucfg_clear_user_disabled_roaming(__int64 a1, unsigned int a2)
{
  wlan_mlme_set_usr_disabled_roaming(a1, 0);
  return mlme_set_supplicant_disabled_roaming(a1, a2, 0);
}
