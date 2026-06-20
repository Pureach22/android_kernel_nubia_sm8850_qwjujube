__int64 __fastcall wlan_hdd_cleanup_remain_on_channel_ctx(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int sta_vdev_id; // w20
  __int64 sta_vdev_for_p2p_dev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x19
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  result = _hdd_objmgr_get_vdev_by_user(a1, 0x53u, (__int64)"wlan_hdd_cleanup_remain_on_channel_ctx");
  if ( result )
  {
    v10 = *(_QWORD *)(result + 152);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v10 + 80);
      if ( v11 )
      {
        v12 = result;
        if ( (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*(_QWORD *)(v10 + 80)) & 1) != 0 )
        {
          sta_vdev_id = ucfg_p2p_psoc_priv_get_sta_vdev_id(v11);
          sta_vdev_for_p2p_dev = wlan_hdd_get_sta_vdev_for_p2p_dev(v11, sta_vdev_id, 83);
          if ( sta_vdev_for_p2p_dev )
          {
            v31 = sta_vdev_for_p2p_dev;
            ucfg_p2p_cleanup_roc_by_vdev(sta_vdev_for_p2p_dev, v23, v24, v25, v26, v27, v28, v29, v30);
            _hdd_objmgr_put_vdev_by_user(
              v31,
              0x53u,
              (__int64)"wlan_hdd_cleanup_remain_on_channel_ctx",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40);
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Invalid sta_vdev %d for p2p device operation",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "wlan_hdd_cleanup_remain_on_channel_ctx",
              (unsigned __int8)sta_vdev_id);
          }
        }
        else
        {
          ucfg_p2p_cleanup_roc_by_vdev(v12, v13, v14, v15, v16, v17, v18, v19, v20);
        }
        result = v12;
      }
    }
    return _hdd_objmgr_put_vdev_by_user(
             result,
             0x53u,
             (__int64)"wlan_hdd_cleanup_remain_on_channel_ctx",
             (unsigned int *)v10,
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9);
  }
  return result;
}
