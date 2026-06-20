__int64 __fastcall wlan_ll_sap_fw_bearer_switch_req(__int64 a1, unsigned int a2)
{
  unsigned __int8 ll_lt_sap_vdev_id; // w21
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD v14[4]; // [xsp+0h] [xbp-30h] BYREF
  __int64 (__fastcall *v15)(); // [xsp+10h] [xbp-20h]
  __int64 v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  ll_lt_sap_vdev_id = wlan_policy_mgr_get_ll_lt_sap_vdev_id(a1);
  v14[0] = ll_lt_sap_vdev_id;
  v14[1] = ll_lt_sap_bearer_switch_get_id(a1);
  v14[2] = a2;
  v14[3] = 2;
  v15 = fw_bearer_switch_requester_cb;
  if ( a2 == 1 )
  {
    result = ll_lt_sap_switch_bearer_to_wlan(a1, v14);
    if ( !(_DWORD)result )
      goto LABEL_6;
    goto LABEL_5;
  }
  result = ll_lt_sap_switch_bearer_to_ble(a1, v14);
  if ( (_DWORD)result )
  {
LABEL_5:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d Bearer req failed type %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_ll_sap_fw_bearer_switch_req",
      ll_lt_sap_vdev_id,
      a2);
    ll_lt_sap_deliver_audio_transport_switch_resp_to_fw(a1, a2, 0);
    result = 4;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
