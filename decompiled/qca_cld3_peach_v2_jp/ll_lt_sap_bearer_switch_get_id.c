__int64 __fastcall ll_lt_sap_bearer_switch_get_id(__int64 a1)
{
  unsigned int ll_lt_sap_vdev_id; // w19
  unsigned int v3; // w21
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  _QWORD *comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v39; // w21

  ll_lt_sap_vdev_id = (unsigned __int8)wlan_policy_mgr_get_ll_lt_sap_vdev_id(a1);
  if ( ll_lt_sap_vdev_id <= 5 )
  {
    v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           a1,
           ll_lt_sap_vdev_id,
           105);
    if ( v4 )
    {
      v13 = v4;
      comp_private_obj = (_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(v4, 0x34u);
      if ( comp_private_obj )
      {
        _X8 = (unsigned int *)(*comp_private_obj + 8LL);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v39 = __ldxr(_X8);
          v3 = v39 + 1;
        }
        while ( __stlxr(v3, _X8) );
        __dmb(0xBu);
        qdf_trace_msg(
          0xA1u,
          8u,
          "BS_SM_%d req_id 0x%x: ",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          ll_lt_sap_vdev_id,
          v3);
      }
      else
      {
        v3 = -1;
        qdf_trace_msg(
          0xA1u,
          2u,
          "%s: BS_SM_%d req_id 0x%x: ll sap obj is NULL",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "ll_lt_sap_bearer_switch_get_id",
          ll_lt_sap_vdev_id,
          0xFFFFFFFFLL);
      }
      wlan_objmgr_vdev_release_ref(v13, 0x69u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
    }
    else
    {
      v3 = -1;
      qdf_trace_msg(
        0xA1u,
        2u,
        "%s: BS_SM_%d req_id 0x%x: Vdev is NULL",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "ll_lt_sap_bearer_switch_get_id",
        ll_lt_sap_vdev_id,
        0xFFFFFFFFLL);
    }
  }
  else
  {
    return (unsigned int)-1;
  }
  return v3;
}
