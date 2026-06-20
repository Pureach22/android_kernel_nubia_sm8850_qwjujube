__int64 __fastcall hdd_ipv6_notifier_work_queue(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
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
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 vdev_by_user; // x0
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _QWORD v47[2]; // [xsp+0h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 48);
  v47[0] = 0;
  result = _osif_vdev_sync_op_start(v2, v47, "hdd_ipv6_notifier_work_queue");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "__hdd_ipv6_notifier_work_queue");
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 - 80,
                          (__int64)"__hdd_ipv6_notifier_work_queue",
                          v12,
                          v13,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19)
      && !(unsigned int)_wlan_hdd_validate_context(
                          *(_QWORD *)(a1 - 56),
                          (__int64)"__hdd_ipv6_notifier_work_queue",
                          v20,
                          v21,
                          v22,
                          v23,
                          v24,
                          v25,
                          v26,
                          v27) )
    {
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                       *(_QWORD *)(a1 + 52744),
                       6u,
                       (__int64)"__hdd_ipv6_notifier_work_queue");
      if ( vdev_by_user )
      {
        v29 = vdev_by_user;
        hdd_enable_ns_offload(a1 - 80, vdev_by_user, 5u, v20, v21, v22, v23, v24, v25, v26, v27);
        v30 = ((double (__fastcall *)(__int64, __int64, __int64))hdd_enable_icmp_offload)(a1 - 80, v29, 5);
        if ( !(unsigned int)_hdd_validate_adapter(
                              a1 - 80,
                              (__int64)"hdd_send_ps_config_to_fw",
                              v30,
                              v31,
                              v32,
                              v33,
                              v34,
                              v35,
                              v36,
                              v37) )
          sme_ps_update(*(_QWORD *)(*(_QWORD *)(a1 - 56) + 16LL), *(unsigned __int8 *)(*(_QWORD *)(a1 + 52744) + 8LL));
        _hdd_objmgr_put_vdev_by_user(
          v29,
          6u,
          (__int64)"__hdd_ipv6_notifier_work_queue",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46);
      }
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "__hdd_ipv6_notifier_work_queue");
    result = _osif_vdev_sync_op_stop(v47[0], "hdd_ipv6_notifier_work_queue");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
