bool __fastcall wlan_ll_sap_is_bearer_switch_req_on_csa(__int64 a1, unsigned __int8 a2)
{
  return policy_mgr_is_vdev_ll_lt_sap(a1, a2) && (ll_lt_sap_get_bearer_switch_cap_for_csa(a1) & 1) != 0;
}
