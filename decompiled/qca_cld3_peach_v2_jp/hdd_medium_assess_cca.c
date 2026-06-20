__int64 __fastcall hdd_medium_assess_cca(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 vdev_by_user; // x0
  __int64 v8; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  unsigned int *v18; // x8
  unsigned int v19; // w20
  __int64 v20; // x21
  __int64 v22; // x21
  __int64 v23; // x8
  int v24; // w22
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int8 v42[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 52824);
  v42[0] = 0;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(v6, 0x4Bu, (__int64)"hdd_medium_assess_cca");
  if ( vdev_by_user )
  {
    v8 = vdev_by_user;
    if ( (unsigned int)policy_mgr_get_mac_id_by_session_id(*a1, *(_BYTE *)(*(_QWORD *)(a2 + 52824) + 8LL), v42) )
    {
      v17 = jiffies;
      v18 = (unsigned int *)(hdd_medium_assess_cca___last_ticks - jiffies);
      if ( hdd_medium_assess_cca___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to get mac_id",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "hdd_medium_assess_cca");
        hdd_medium_assess_cca___last_ticks = v17;
        v19 = -22;
LABEL_9:
        _hdd_objmgr_put_vdev_by_user(
          v8,
          0x4Bu,
          (__int64)"hdd_medium_assess_cca",
          v18,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16);
        goto LABEL_10;
      }
    }
    else
    {
      if ( (ucfg_get_dcs_enable(*a1, v42[0], v9, v10, v11, v12, v13, v14, v15, v16) & 2) != 0 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(a2 + 52824) + 2344LL) )
        {
          v22 = jiffies;
          v18 = (unsigned int *)(hdd_medium_assess_cca___last_ticks_16 - jiffies);
          if ( hdd_medium_assess_cca___last_ticks_16 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: ACS is in progress",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "hdd_medium_assess_cca");
            hdd_medium_assess_cca___last_ticks_16 = v22;
          }
          v19 = -16;
        }
        else
        {
          v23 = *(_QWORD *)(a3 + 16);
          v24 = 10;
          if ( v23 )
          {
            v25 = *(_DWORD *)(v23 + 4);
            if ( v25 )
              v24 = v25;
            else
              v24 = 10;
          }
          ucfg_dcs_reset_user_stats(*a1, v42[0], v9, v10, v11, v12, v13, v14, v15, v16);
          ucfg_dcs_register_user_cb(
            *a1,
            v42[0],
            *(_BYTE *)(*(_QWORD *)(a2 + 52824) + 8LL),
            (__int64)hdd_cca_notification_cb,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33);
          ucfg_dcs_set_user_request(*a1, v42[0], v24, v34, v35, v36, v37, v38, v39, v40, v41);
          v19 = 0;
        }
        goto LABEL_9;
      }
      v20 = jiffies;
      v18 = (unsigned int *)(hdd_medium_assess_cca___last_ticks_14 - jiffies);
      if ( hdd_medium_assess_cca___last_ticks_14 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: DCS_WLANIM is not enabled",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "hdd_medium_assess_cca");
        hdd_medium_assess_cca___last_ticks_14 = v20;
        v19 = -22;
        goto LABEL_9;
      }
    }
    v19 = -22;
    goto LABEL_9;
  }
  v19 = -22;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v19;
}
