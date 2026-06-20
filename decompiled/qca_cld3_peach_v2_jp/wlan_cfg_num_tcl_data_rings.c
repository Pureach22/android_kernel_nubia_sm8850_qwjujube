__int64 __fastcall wlan_cfg_num_tcl_data_rings(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 540) == 1 && (wlan_ipa_config_is_opt_wifi_dp_enabled() & 1) == 0 )
    return 1;
  else
    return *(unsigned int *)(a1 + 20);
}
