__int64 sub_29D5D0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    return ucfg_mlme_get_coex_unsafe_chan_nb_user_prefer();
  else
    return wlan_mlme_get_self_gen_frm_pwr();
}
