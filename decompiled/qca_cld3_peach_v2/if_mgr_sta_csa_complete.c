__int64 __fastcall if_mgr_sta_csa_complete(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19

  v1 = *(_QWORD *)(a1 + 216);
  if ( !v1 )
    return 16;
  v2 = *(_QWORD *)(v1 + 80);
  if ( !v2 )
    return 16;
  wlan_tdls_notify_channel_switch_complete(*(_QWORD *)(v1 + 80), *(unsigned __int8 *)(a1 + 168));
  policy_mgr_trigger_roam_for_sta_sap_mcc_non_dbs(v2);
  return 0;
}
