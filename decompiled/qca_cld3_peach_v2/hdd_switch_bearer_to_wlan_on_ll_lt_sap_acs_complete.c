__int64 __fastcall hdd_switch_bearer_to_wlan_on_ll_lt_sap_acs_complete(__int64 a1, unsigned __int8 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // [xsp+0h] [xbp-30h] BYREF
  __int64 v22; // [xsp+8h] [xbp-28h]
  __int64 v23; // [xsp+10h] [xbp-20h]
  __int64 v24; // [xsp+18h] [xbp-18h]
  __int64 v25; // [xsp+20h] [xbp-10h]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  if ( (unsigned int)policy_mgr_get_ll_lt_sap_freq(a1) )
  {
    LOBYTE(v21) = a2;
    HIDWORD(v21) = wlan_ll_lt_sap_bearer_switch_get_id(a1);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Vdev %d ACS completed, switch bearer back to wlan",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_switch_bearer_to_wlan_on_ll_lt_sap_acs_complete",
      a2,
      v21,
      0x400000001LL,
      ll_lt_sap_acs_complete_bearer_switch_req_cb,
      v24,
      v25,
      v26);
    result = wlan_ll_lt_sap_switch_bearer_to_wlan(a1, &v21);
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: ll_lt_sap is not resent",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "hdd_switch_bearer_to_wlan_on_ll_lt_sap_acs_complete",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
