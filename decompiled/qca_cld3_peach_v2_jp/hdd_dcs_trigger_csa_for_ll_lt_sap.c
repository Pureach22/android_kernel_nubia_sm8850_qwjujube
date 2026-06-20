__int64 __fastcall hdd_dcs_trigger_csa_for_ll_lt_sap(__int64 a1, __int64 a2, char a3, unsigned int a4)
{
  unsigned int ll_lt_sap_freq; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  __int64 v18; // [xsp+0h] [xbp-30h] BYREF
  __int64 v19; // [xsp+8h] [xbp-28h]
  __int64 (__fastcall *v20)(); // [xsp+10h] [xbp-20h]
  __int64 v21; // [xsp+18h] [xbp-18h]
  __int64 v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = nullptr;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(a1);
  if ( ll_lt_sap_freq )
  {
    wlan_ll_lt_store_to_avoid_list_and_flush_old(a1, ll_lt_sap_freq, a4);
    LOBYTE(v18) = a3;
    HIDWORD(v18) = wlan_ll_lt_sap_bearer_switch_get_id(a1);
    v19 = 0x400000000LL;
    v20 = hdd_ll_lt_sap_acs_start_bearer_switch_requester_cb;
    v22 = a2;
    result = wlan_ll_lt_sap_switch_bearer_to_ble(a1, &v18);
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: ll_lt_sap is not resent",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "hdd_switch_bearer_to_ble_on_ll_lt_sap_acs_start",
               v18,
               v19,
               v20,
               v21);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
