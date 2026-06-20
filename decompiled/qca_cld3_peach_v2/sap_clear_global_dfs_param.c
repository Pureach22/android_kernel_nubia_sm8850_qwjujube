__int64 __fastcall sap_clear_global_dfs_param(__int64 a1, __int64 a2)
{
  unsigned int *valid_concurrent_session; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  valid_concurrent_session = (unsigned int *)sap_find_valid_concurrent_session();
  if ( valid_concurrent_session && wlan_reg_is_5ghz_ch_freq(*valid_concurrent_session) )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: conc session exists, no need to clear dfs struct",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sap_clear_global_dfs_param");
  }
  else
  {
    wlansap_cleanup_cac_timer(a2);
    sap_cac_reset_notify(a1);
  }
  return 0;
}
