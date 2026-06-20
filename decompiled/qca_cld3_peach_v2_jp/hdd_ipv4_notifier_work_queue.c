__int64 __fastcall hdd_ipv4_notifier_work_queue(__int64 a1)
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
  __int64 v28; // x22
  __int64 vdev_by_user; // x0
  __int64 v30; // x21
  unsigned int *v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x25
  __int64 v49; // x24
  const char *v50; // x2
  __int64 v51; // [xsp+8h] [xbp-18h] BYREF
  int v52; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+18h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 16);
  v51 = 0;
  result = _osif_vdev_sync_op_start(v2, &v51, "hdd_ipv4_notifier_work_queue");
  if ( !(_DWORD)result )
  {
    v52 = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "__hdd_ipv4_notifier_work_queue");
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 - 48,
                         (__int64)"__hdd_ipv4_notifier_work_queue",
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19) )
      goto LABEL_20;
    v28 = *(_QWORD *)(a1 - 24);
    if ( (unsigned int)_wlan_hdd_validate_context(
                         v28,
                         (__int64)"__hdd_ipv4_notifier_work_queue",
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27) )
      goto LABEL_20;
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52776), 6u, (__int64)"__hdd_ipv4_notifier_work_queue");
    if ( !vdev_by_user )
      goto LABEL_20;
    v30 = vdev_by_user;
    hdd_enable_arp_offload(a1 - 48, vdev_by_user, 4u, v20, v21, v22, v23, v24, v25, v26, v27);
    ((void (__fastcall *)(__int64, __int64, __int64))hdd_enable_icmp_offload)(a1 - 48, v30, 4);
    if ( (unsigned int)ucfg_mlme_get_sta_keepalive_method(*(_QWORD *)v28, &v52) )
    {
LABEL_19:
      _hdd_objmgr_put_vdev_by_user(
        v30,
        6u,
        (__int64)"__hdd_ipv4_notifier_work_queue",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39);
LABEL_20:
      qdf_trace_msg(0x33u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "__hdd_ipv4_notifier_work_queue");
      result = _osif_vdev_sync_op_stop(v51, "hdd_ipv4_notifier_work_queue");
      goto LABEL_21;
    }
    if ( v52 == 2 )
      hdd_set_grat_arp_keepalive((_QWORD *)(a1 - 48), v32, v33, v34, v35, v36, v37, v38, v39);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: FILS Roaming support: %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "__hdd_ipv4_notifier_work_queue",
      *(unsigned __int8 *)(v28 + 3264));
    if ( a1 == 48 )
    {
      v50 = "%s: adapter is null";
    }
    else
    {
      v48 = *(_QWORD *)(a1 - 16);
      v49 = *(_QWORD *)(v48 + 968);
      if ( v49 )
      {
        while ( 1 )
        {
          v49 = *(_QWORD *)(v49 + 16);
          if ( !v49 )
            goto LABEL_17;
          if ( !strcmp((const char *)(v48 + 296), (const char *)(v49 + 76)) )
          {
            if ( *(_BYTE *)(v28 + 3264) == 1 )
              sme_send_hlp_ie_info(*(_QWORD *)(v28 + 16), *(unsigned __int8 *)(v30 + 104), *(unsigned int *)(v49 + 48));
            goto LABEL_17;
          }
        }
      }
      v50 = "%s: Failed to get in_device";
    }
    qdf_trace_msg(0x33u, 2u, v50, v40, v41, v42, v43, v44, v45, v46, v47, "hdd_lookup_ifaddr");
LABEL_17:
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 - 48,
                          (__int64)"hdd_send_ps_config_to_fw",
                          v40,
                          v41,
                          v42,
                          v43,
                          v44,
                          v45,
                          v46,
                          v47) )
      sme_ps_update(*(_QWORD *)(*(_QWORD *)(a1 - 24) + 16LL), *(unsigned __int8 *)(*(_QWORD *)(a1 + 52776) + 8LL));
    goto LABEL_19;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
