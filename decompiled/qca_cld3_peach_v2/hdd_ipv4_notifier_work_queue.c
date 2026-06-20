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
  __int64 v29; // x22
  __int64 vdev_by_user; // x0
  __int64 v31; // x20
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x23
  __int64 v50; // x21
  const char *v51; // x2
  __int64 v52; // [xsp+8h] [xbp-18h] BYREF
  int v53; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+18h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 16);
  v52 = 0;
  result = _osif_vdev_sync_op_start(v2, &v52, "hdd_ipv4_notifier_work_queue");
  if ( !(_DWORD)result )
  {
    v12 = (_QWORD *)(a1 - 48);
    v53 = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "__hdd_ipv4_notifier_work_queue");
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 - 48,
                         (__int64)"__hdd_ipv4_notifier_work_queue",
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20) )
      goto LABEL_19;
    v29 = *(_QWORD *)(a1 - 24);
    if ( (unsigned int)_wlan_hdd_validate_context(
                         v29,
                         (__int64)"__hdd_ipv4_notifier_work_queue",
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28) )
      goto LABEL_19;
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52784), 6u, (__int64)"__hdd_ipv4_notifier_work_queue");
    if ( !vdev_by_user )
      goto LABEL_19;
    v31 = vdev_by_user;
    hdd_enable_arp_offload(a1 - 48, vdev_by_user, 4u, v21, v22, v23, v24, v25, v26, v27, v28);
    ((void (__fastcall *)(__int64, __int64, __int64))hdd_enable_icmp_offload)(a1 - 48, v31, 4);
    if ( (unsigned int)ucfg_mlme_get_sta_keepalive_method(*(_QWORD *)v29, &v53) )
    {
LABEL_18:
      _hdd_objmgr_put_vdev_by_user(
        v31,
        6u,
        (__int64)"__hdd_ipv4_notifier_work_queue",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40);
LABEL_19:
      qdf_trace_msg(0x33u, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "__hdd_ipv4_notifier_work_queue");
      result = _osif_vdev_sync_op_stop(v52, "hdd_ipv4_notifier_work_queue");
      goto LABEL_20;
    }
    if ( v53 == 2 )
      hdd_set_grat_arp_keepalive((_QWORD *)(a1 - 48), v33, v34, v35, v36, v37, v38, v39, v40);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: FILS Roaming support: %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "__hdd_ipv4_notifier_work_queue",
      *(unsigned __int8 *)(v29 + 3264));
    if ( a1 == 48 )
    {
      v51 = "%s: adapter is null";
    }
    else
    {
      v49 = *(_QWORD *)(a1 - 16);
      v50 = *(_QWORD *)(v49 + 968);
      if ( v50 )
      {
        while ( 1 )
        {
          v50 = *(_QWORD *)(v50 + 16);
          if ( !v50 )
            goto LABEL_17;
          if ( !strcmp((const char *)(v49 + 296), (const char *)(v50 + 76)) )
          {
            if ( *(_BYTE *)(v29 + 3264) == 1 )
              sme_send_hlp_ie_info(*(_QWORD *)(v29 + 16), *(unsigned __int8 *)(v31 + 168), *(unsigned int *)(v50 + 48));
            goto LABEL_17;
          }
        }
      }
      v51 = "%s: Failed to get in_device";
    }
    qdf_trace_msg(0x33u, 2u, v51, v41, v42, v43, v44, v45, v46, v47, v48, "hdd_lookup_ifaddr");
LABEL_17:
    hdd_send_ps_config_to_fw(v12, v41, v42, v43, v44, v45, v46, v47, v48);
    goto LABEL_18;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
