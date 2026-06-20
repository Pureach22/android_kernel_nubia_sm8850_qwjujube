__int64 __fastcall wlan_ll_sap_switch_bearer_on_sta_connect_start(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned int ll_lt_sap_vdev_id; // w0
  __int64 v9; // x0
  unsigned int *v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x25
  unsigned int ll_lt_sap_freq; // w23
  _QWORD *v21; // x1
  unsigned int v22; // w24
  unsigned int v23; // w19
  __int64 result; // x0
  _QWORD *v25; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = nullptr;
  v26[0] = 0;
  ll_lt_sap_vdev_id = wlan_policy_mgr_get_ll_lt_sap_vdev_id(a1);
  if ( (unsigned __int8)ll_lt_sap_vdev_id <= 5u
    && (v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               a1,
               ll_lt_sap_vdev_id,
               105)) != 0 )
  {
    if ( a2 && (v10 = (unsigned int *)*(unsigned int *)(a2 + 16), (_DWORD)v10) )
    {
      v19 = v9;
      ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(a1);
      qdf_list_peek_front((_QWORD *)a2, v26);
      v21 = (_QWORD *)v26[0];
      if ( v26[0] )
      {
        while ( 1 )
        {
          qdf_list_peek_next((_QWORD *)a2, v21, &v25);
          v22 = *(_DWORD *)(*(_QWORD *)(v26[0] + 24LL) + 1064LL);
          if ( (policy_mgr_2_freq_always_on_same_mac(a1, v22, ll_lt_sap_freq) & 1) != 0 )
            break;
          v21 = v25;
          v25 = nullptr;
          v26[0] = v21;
          if ( !v21 )
            goto LABEL_8;
        }
        qdf_trace_msg(
          0xA1u,
          8u,
          "%s: Scan list has BSS of freq %d on same mac with ll_lt sap %d",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "wlan_ll_sap_switch_bearer_on_sta_connect_start",
          v22,
          ll_lt_sap_freq);
        v23 = ll_lt_sap_switch_bearer(a1, a3, 0, 0, connect_start_bearer_switch_requester_cb, a4, 0);
      }
      else
      {
LABEL_8:
        v23 = 6;
      }
      v9 = v19;
    }
    else
    {
      v23 = 6;
    }
    wlan_objmgr_vdev_release_ref(v9, 0x69u, v10, v11, v12, v13, v14, v15, v16, v17, v18);
    result = v23;
  }
  else
  {
    result = 6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
