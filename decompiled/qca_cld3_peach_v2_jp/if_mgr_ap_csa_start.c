__int64 __fastcall if_mgr_ap_csa_start(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned int v3; // w20

  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 1 )
    return 0;
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 16;
  v2 = *(_QWORD *)(v1 + 80);
  if ( !v2 )
    return 16;
  v3 = *(unsigned __int8 *)(a1 + 104);
  wlan_tdls_notify_channel_switch_start(*(_QWORD *)(v1 + 80));
  if ( (wlan_ll_sap_is_bearer_switch_req_on_csa(v2, v3) & 1) != 0 )
    return wlan_ll_sap_switch_bearer_on_ll_sap_csa(v2, v3);
  else
    return 0;
}
