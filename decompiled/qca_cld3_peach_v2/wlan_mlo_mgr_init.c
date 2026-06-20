__int64 wlan_mlo_mgr_init()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x0
  __int64 v17; // x19
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w19
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 mlo_ctx; // x0
  __int64 i; // x8
  __int64 v48; // x9
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7

  if ( wlan_objmgr_get_mlo_ctx() )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Global object is already created",
      v0,
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      "mlo_global_ctx_init");
  }
  else
  {
    v16 = _qdf_mem_malloc(0x4F0u, "mlo_global_ctx_init", 216);
    if ( v16 )
    {
      v17 = v16;
      wlan_objmgr_set_mlo_ctx(v16);
      *(_QWORD *)(v17 + 192) = v17 + 192;
      *(_QWORD *)(v17 + 200) = v17 + 192;
      *(_QWORD *)(v17 + 208) = 0x300000000LL;
      *(_DWORD *)(v17 + 344) = 1024;
      qdf_mutex_create(v17 + 128);
      qdf_mutex_create(v17);
      v18 = qdf_mutex_create(v17 + 64);
      *(_BYTE *)(v17 + 376) = 0;
      *(_BYTE *)(v17 + 378) = 0;
      v8 = mlo_msgq_init(v18);
    }
  }
  if ( (unsigned int)wlan_objmgr_register_vdev_create_handler(
                       0x28u,
                       (__int64)wlan_mlo_mgr_vdev_created_notification,
                       0,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Failed to register vdev create handler",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_mlo_mgr_init");
    return 16;
  }
  else
  {
    v28 = wlan_objmgr_register_vdev_destroy_handler(
            0x28u,
            (__int64)wlan_mlo_mgr_vdev_destroyed_notification,
            0,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    if ( v28 )
    {
      v37 = v28;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Failed to register VDEV destroy handler",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "wlan_mlo_mgr_init");
      wlan_objmgr_unregister_vdev_create_handler(
        0x28u,
        (__int64)wlan_mlo_mgr_vdev_created_notification,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45);
      return v37;
    }
    else
    {
      mlo_ctx = wlan_objmgr_get_mlo_ctx();
      if ( mlo_ctx )
      {
        for ( i = 0; i != 864; i += 16 )
        {
          v48 = mlo_ctx + i;
          *(_BYTE *)(v48 + 384) = 0;
          *(_QWORD *)(v48 + 392) = 0;
        }
        v49 = wlan_objmgr_get_mlo_ctx();
        if ( v49 )
        {
          if ( (*(_BYTE *)(v49 + 1024) & 1) != 0 )
          {
            return 6;
          }
          else
          {
            *(_BYTE *)(v49 + 1024) = 1;
            *(_QWORD *)(v49 + 1032) = &mlo_mgr_link_switch_notification;
            return 0;
          }
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: global mlo mgr not initialized",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "mlo_mgr_register_link_switch_notifier");
          return 4;
        }
      }
      else
      {
        return 4;
      }
    }
  }
}
