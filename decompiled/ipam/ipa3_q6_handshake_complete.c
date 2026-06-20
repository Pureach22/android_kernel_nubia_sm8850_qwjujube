__int64 __fastcall ipa3_q6_handshake_complete(char a1)
{
  __int64 result; // x0
  __int64 v2; // x8

  if ( (a1 & 1) != 0 )
  {
    ipa3_proxy_clk_unvote();
    rmnet_ipa_send_ssr_notification(1);
    rmnet_ipa_get_network_stats_and_update();
  }
  result = ipa3_set_modem_up(1);
  v2 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + 32260) == 1 )
  {
    result = ipa_send_mhi_endp_ind_to_modem();
    v2 = ipa3_ctx;
  }
  if ( *(_BYTE *)(v2 + 32267) == 1 )
  {
    result = ((__int64 (__fastcall *)(_QWORD))ipa_wdi_opt_dpath_ctrl_enabled)(0);
    if ( (result & 1) != 0 )
      return ipa3_setup_wlan_ctrl_ready_req();
  }
  return result;
}
