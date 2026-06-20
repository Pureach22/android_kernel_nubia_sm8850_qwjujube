__int64 __fastcall os_if_dp_register_hdd_callbacks(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  a2[22] = osif_dp_send_tcp_param_update_event;
  a2[38] = os_if_dp_nud_stats_info;
  a2[36] = osif_dp_process_mic_error;
  os_if_dp_register_txrx_callbacks(a2);
  a2[42] = osif_dp_register_lpass_ssr_notifier;
  a2[43] = osif_dp_unregister_lpass_ssr_notifier;
  osif_dp_register_stc_callbacks(a2);
  ucfg_dp_register_hdd_callbacks(a1, a2);
  v5[0] = osif_dp_get_arp_stats_event_handler;
  result = ucfg_dp_register_event_handler(a1, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
