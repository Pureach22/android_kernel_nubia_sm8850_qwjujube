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
  _QWORD *v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 vdev_by_user; // x0
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _QWORD v48[2]; // [xsp+0h] [xbp-10h] BYREF

  v48[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 48);
  v48[0] = 0;
  result = _osif_vdev_sync_op_start(v2, v48, "hdd_ipv6_notifier_work_queue");
  if ( !(_DWORD)result )
  {
    v12 = (_QWORD *)(a1 - 80);
    qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "__hdd_ipv6_notifier_work_queue");
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 - 80,
                          (__int64)"__hdd_ipv6_notifier_work_queue",
                          v13,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20)
      && !(unsigned int)_wlan_hdd_validate_context(
                          *(_QWORD *)(a1 - 56),
                          (__int64)"__hdd_ipv6_notifier_work_queue",
                          v21,
                          v22,
                          v23,
                          v24,
                          v25,
                          v26,
                          v27,
                          v28) )
    {
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                       *(_QWORD *)(a1 + 52752),
                       6u,
                       (__int64)"__hdd_ipv6_notifier_work_queue");
      if ( vdev_by_user )
      {
        v30 = vdev_by_user;
        hdd_enable_ns_offload((__int64)v12, vdev_by_user, 5u, v21, v22, v23, v24, v25, v26, v27, v28);
        v31 = ((double (__fastcall *)(_QWORD *, __int64, __int64))hdd_enable_icmp_offload)(v12, v30, 5);
        hdd_send_ps_config_to_fw(v12, v31, v32, v33, v34, v35, v36, v37, v38);
        _hdd_objmgr_put_vdev_by_user(
          v30,
          6u,
          (__int64)"__hdd_ipv6_notifier_work_queue",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47);
      }
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "__hdd_ipv6_notifier_work_queue");
    result = _osif_vdev_sync_op_stop(v48[0], "hdd_ipv6_notifier_work_queue");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
