__int64 __fastcall wlan_ll_sap_switch_bearer_on_ll_sap_csa_complete(__int64 a1, __int64 a2)
{
  return ll_lt_sap_switch_bearer(a1, a2, 1, 1, wlan_ll_sap_csa_complete_bearer_switch_requester_cb, 0, 0);
}
