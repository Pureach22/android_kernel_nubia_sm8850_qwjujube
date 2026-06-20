__int64 __fastcall ll_lt_sap_switch_bearer_for_p2p_go_start(
        __int64 result,
        unsigned __int8 a2,
        unsigned int a3,
        int a4)
{
  __int64 v4; // x29
  __int64 v5; // x30
  __int64 v8; // x21
  unsigned int v9; // w23
  __int64 v10; // x20
  __int64 *comp_private_obj; // x0
  unsigned int *v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x23
  unsigned int ll_lt_sap_freq; // w0
  unsigned int v23; // w24
  const char *v24; // x2
  __int64 v25; // x4
  __int64 v26; // [xsp+0h] [xbp-40h]
  __int64 v27; // [xsp+8h] [xbp-38h]

  if ( a4 == 3 )
  {
    v26 = v4;
    v27 = v5;
    v8 = result;
    result = wlan_policy_mgr_get_ll_lt_sap_vdev_id(result);
    v9 = (unsigned __int8)result;
    if ( (unsigned __int8)result <= 5u )
    {
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                 v8,
                 (unsigned __int8)result,
                 105);
      if ( result )
      {
        v10 = result;
        comp_private_obj = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(result, 0x34u);
        if ( comp_private_obj )
        {
          v21 = *comp_private_obj;
          if ( !*comp_private_obj )
            return wlan_objmgr_vdev_release_ref(v10, 0x69u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
          ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(v8);
          if ( !ll_lt_sap_freq )
            return wlan_objmgr_vdev_release_ref(v10, 0x69u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
          v23 = ll_lt_sap_freq;
          if ( (policy_mgr_2_freq_always_on_same_mac(v8, a3, ll_lt_sap_freq) & 1) == 0 )
            return wlan_objmgr_vdev_release_ref(v10, 0x69u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
          qdf_trace_msg(
            0xA1u,
            8u,
            "%s: P2P GO freq %d on same mac with ll_lt sap %d",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "ll_lt_sap_switch_bearer_for_p2p_go_start",
            a3,
            v23,
            v4,
            v27);
          if ( (unsigned int)ll_lt_sap_switch_bearer(
                               v8,
                               a2,
                               0,
                               3u,
                               (__int64)p2p_go_start_bearer_switch_requester_cb,
                               0,
                               v21) )
            return wlan_objmgr_vdev_release_ref(v10, 0x69u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
          qdf_event_reset(v21 + 792);
          if ( !(unsigned int)qdf_wait_for_event_completion(v21 + 792, 0x1388u) )
            return wlan_objmgr_vdev_release_ref(v10, 0x69u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
          v24 = "%s: bearer switch to non-wlan failed for vdev %d";
          v25 = a2;
        }
        else
        {
          v24 = "%s: BS_SM vdev %d ll_sap obj null";
          v25 = v9;
        }
        qdf_trace_msg(
          0xA1u,
          2u,
          v24,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "ll_lt_sap_switch_bearer_for_p2p_go_start",
          v25,
          v26,
          v27);
        return wlan_objmgr_vdev_release_ref(v10, 0x69u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
      }
    }
  }
  return result;
}
