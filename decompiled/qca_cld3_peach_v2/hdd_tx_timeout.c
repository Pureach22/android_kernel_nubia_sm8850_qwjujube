__int64 __fastcall hdd_tx_timeout(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x6
  __int64 v12; // x7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // x20
  __int64 v22; // x23
  __int64 vdev_by_user; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x19
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD v42[2]; // [xsp+0h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42[0] = 0;
  result = _osif_vdev_sync_op_start(a1, v42, "hdd_tx_timeout");
  if ( !(_DWORD)result )
  {
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 2712) + 185LL) == 1 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Device is suspended, ignore WD timeout",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "__hdd_tx_timeout");
    }
    else
    {
      qdf_trace_msg(
        0x3Bu,
        2u,
        "%s: Transmission timeout occurred jiffies %lu",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "__hdd_tx_timeout",
        jiffies);
      qdf_dp_trace(0, 0xAu, 0xFFu, 0, 0, 0, v11, v12);
      if ( *(_DWORD *)(a1 + 1096) )
      {
        v21 = 0;
        v22 = 328;
        do
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Queue: %d status: %d txq->trans_start: %lu",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "__hdd_tx_timeout",
            (unsigned int)v21++,
            *(_QWORD *)(*(_QWORD *)(a1 + 24) + v22 + 8) & 1LL,
            *(_QWORD *)(*(_QWORD *)(a1 + 24) + v22));
          v22 += 384;
        }
        while ( v21 < *(unsigned int *)(a1 + 1096) );
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: carrier state: %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "__hdd_tx_timeout",
        (*(_QWORD *)(a1 + 168) & 4LL) == 0);
      wlan_hdd_display_adapter_netif_queue_history(a1 + 2688);
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 55520), 0x61u, (__int64)"__hdd_tx_timeout");
      if ( vdev_by_user )
      {
        v32 = vdev_by_user;
        ucfg_dp_tx_timeout(vdev_by_user, v24, v25, v26, v27, v28, v29, v30, v31);
        _hdd_objmgr_put_vdev_by_user(
          v32,
          0x61u,
          (__int64)"__hdd_tx_timeout",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41);
      }
    }
    result = _osif_vdev_sync_op_stop(v42[0], "hdd_tx_timeout");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
