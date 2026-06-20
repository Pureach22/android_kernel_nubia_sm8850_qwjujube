__int64 __fastcall rmnet_ipa3_poll_tethering_stats(__int64 *a1)
{
  __int64 v1; // x9
  __int64 v2; // x0
  __int64 network_stats_and_update; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v5 = 257;
  qword_201788 = v1;
  cancel_delayed_work_sync(&ipa_tether_stats_poll_wakequeue_work);
  if ( qword_201788 )
  {
    queue_delayed_work_on(32, system_wq, &ipa_tether_stats_poll_wakequeue_work, 0);
  }
  else
  {
    v2 = ipa3_qmi_stop_data_quota((__int64)&v5);
    network_stats_and_update = rmnet_ipa_get_network_stats_and_update(v2);
    rmnet_ipa_get_stats_and_update(network_stats_and_update);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
