__int64 __fastcall wlan_ll_sap_switch_bearer_on_sta_connect_complete(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w19

  v4 = 6;
  if ( (unsigned __int8)wlan_policy_mgr_get_ll_lt_sap_vdev_id(a1) != 0xFF )
  {
    if ( (unsigned int)ll_lt_sap_switch_bearer(a1, a2, 1, 0, connect_complete_bearer_switch_requester_cb, 0, 0) )
      return 6;
    else
      return 0;
  }
  return v4;
}
