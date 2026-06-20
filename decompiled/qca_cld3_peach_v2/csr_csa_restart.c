__int64 __fastcall csr_csa_restart(__int64 a1, __int64 a2)
{
  unsigned int v3; // w19
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  int v14; // w22
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _QWORD v34[7]; // [xsp+8h] [xbp-38h] BYREF

  v3 = a2;
  v34[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21624),
         a2,
         7);
  if ( v4 )
  {
    v13 = v4;
    v14 = if_mgr_deliver_event(v4, 0x11u, 0, v5, v6, v7, v8, v9, v10, v11, v12);
    wlan_objmgr_vdev_release_ref(v13, 7u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    if ( v14 || (wlan_ll_sap_is_bearer_switch_req_on_csa(*(_QWORD *)(a1 + 21624), v3) & 1) == 0 )
    {
      memset(&v34[1], 0, 40);
      v34[0] = 5268;
      v24 = scheduler_post_message_debug(
              0x34u,
              0x35u,
              53,
              (unsigned __int16 *)v34,
              0x1CC9u,
              (__int64)"csr_send_csa_restart_req");
      if ( v24 )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: scheduler_post_msg failed!(err=%d)",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "csr_send_csa_restart_req",
          v24);
    }
    else
    {
      v24 = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: VDEV not found for vdev id: %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "csr_csa_restart",
      (unsigned __int8)v3);
    v24 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v24;
}
