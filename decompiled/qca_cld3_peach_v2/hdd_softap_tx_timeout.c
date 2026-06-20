__int64 __fastcall hdd_softap_tx_timeout(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 v5; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  unsigned int v23; // w0
  unsigned int v24; // w1
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int64 v33; // x20
  __int64 v34; // x22
  __int64 vdev_by_user; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x20
  unsigned int *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  _QWORD v54[2]; // [xsp+0h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54[0] = 0;
  result = _osif_vdev_sync_op_start(a1, v54, "hdd_softap_tx_timeout");
  if ( !(_DWORD)result )
  {
    qdf_dp_trace(0, 0xBu, 0xFFu, 0, 0, 0, v3, v4);
    v5 = *(_QWORD *)(a1 + 2712);
    if ( (cds_get_driver_state(v6, v7, v8, v9, v10, v11, v12, v13) & 8) != 0
      || (cds_get_driver_state(v14, v15, v16, v17, v18, v19, v20, v21) & 0x10) != 0 )
    {
      v22 = "%s: Recovery in Progress. Ignore!!!";
      v23 = 60;
      v24 = 2;
    }
    else
    {
      if ( *(_BYTE *)(v5 + 185) != 1 )
      {
        qdf_trace_msg(
          0x3Cu,
          2u,
          "%s: Transmission timeout occurred jiffies %lu",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "__hdd_softap_tx_timeout",
          jiffies);
        if ( *(_DWORD *)(a1 + 1096) )
        {
          v33 = 0;
          v34 = 328;
          do
          {
            qdf_trace_msg(
              0x3Bu,
              8u,
              "Queue: %d status: %d txq->trans_start: %lu",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              (unsigned int)v33++,
              *(_QWORD *)(*(_QWORD *)(a1 + 24) + v34 + 8) & 1LL,
              *(_QWORD *)(*(_QWORD *)(a1 + 24) + v34));
            v34 += 384;
          }
          while ( v33 < *(unsigned int *)(a1 + 1096) );
        }
        wlan_hdd_display_adapter_netif_queue_history(a1 + 2688);
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 55520), 0x61u, (__int64)"__hdd_softap_tx_timeout");
        if ( vdev_by_user )
        {
          v44 = vdev_by_user;
          ucfg_dp_softap_tx_timeout(vdev_by_user, v36, v37, v38, v39, v40, v41, v42, v43);
          _hdd_objmgr_put_vdev_by_user(
            v44,
            0x61u,
            (__int64)"__hdd_softap_tx_timeout",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53);
        }
        qdf_trace_msg(
          0x3Bu,
          8u,
          "carrier state: %d",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          (*(_QWORD *)(a1 + 168) & 4LL) == 0);
        goto LABEL_8;
      }
      v22 = "%s: wlan is suspended, ignore timeout";
      v23 = 51;
      v24 = 8;
    }
    qdf_trace_msg(v23, v24, v22, v14, v15, v16, v17, v18, v19, v20, v21, "__hdd_softap_tx_timeout");
LABEL_8:
    result = _osif_vdev_sync_op_stop(v54[0], "hdd_softap_tx_timeout");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
