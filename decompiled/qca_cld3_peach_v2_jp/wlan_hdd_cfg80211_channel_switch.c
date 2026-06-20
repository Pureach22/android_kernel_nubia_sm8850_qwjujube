__int64 __fastcall wlan_hdd_cfg80211_channel_switch(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 result; // x0
  _QWORD *v6; // x21
  int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w19
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w0
  unsigned int v27; // w21
  unsigned int v28; // w22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  int v47; // w19
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  const char *v56; // x2
  unsigned int v57; // w1
  _QWORD v58[2]; // [xsp+10h] [xbp-10h] BYREF

  v58[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v58, "wlan_hdd_cfg80211_channel_switch");
  if ( !(_DWORD)result )
  {
    v6 = *(_QWORD **)(a2 + 2712);
    v7 = _wlan_hdd_validate_context(v6, "__wlan_hdd_cfg80211_channel_switch");
    if ( !v7 )
    {
      if ( (*(_DWORD *)(a2 + 2728) | 2) == 3 )
      {
        v17 = *(_QWORD *)(a2 + 55512);
        if ( v17 )
        {
          if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                               *(unsigned __int8 *)(v17 + 8),
                               "__wlan_hdd_cfg80211_channel_switch")
            || (policy_mgr_is_sap_allowed_on_dfs_freq(
                  v6[1],
                  *(unsigned __int8 *)(v17 + 8),
                  *(_DWORD *)(*a3 + 4),
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  v25)
              & 1) == 0 )
          {
            v7 = -22;
          }
          else
          {
            wlan_hdd_set_sap_csa_reason(*v6, *(unsigned __int8 *)(v17 + 8), 2);
            v26 = hdd_map_nl_chan_width(*((unsigned int *)a3 + 2));
            v27 = *((unsigned __int16 *)a3 + 15);
            v28 = v26;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Freq %d width %d CCFS1 %d, CCFS2 %d, ch_width %d punct_bitmap 0x%x",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "__wlan_hdd_cfg80211_channel_switch",
              *(unsigned int *)(*a3 + 4),
              *((unsigned int *)a3 + 2),
              *((unsigned int *)a3 + 3),
              *((unsigned int *)a3 + 4),
              v26,
              v27);
            qdf_event_reset(v17 + 88);
            v37 = hdd_softap_set_channel_change(
                    v17,
                    *(unsigned int *)(*a3 + 4),
                    *((unsigned int *)a3 + 3),
                    v28,
                    v27,
                    0,
                    1);
            if ( v37 )
            {
              v46 = *a3;
              v47 = v37;
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: CSA failed to %d, ret %d",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "__wlan_hdd_cfg80211_channel_switch",
                *(unsigned int *)(v46 + 4),
                v37);
              v7 = v47;
            }
            else
            {
              if ( (unsigned int)qdf_wait_for_event_completion(v17 + 88, 0x32C8u) )
              {
                v56 = "%s: wait for qdf_event failed!!";
                v57 = 2;
              }
              else
              {
                v56 = "%s: csa done";
                v57 = 8;
              }
              qdf_trace_msg(
                0x33u,
                v57,
                v56,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                "__wlan_hdd_cfg80211_channel_switch");
              v7 = 0;
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid link_info",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "__wlan_hdd_cfg80211_channel_switch");
          v7 = -22;
        }
      }
      else
      {
        v7 = -524;
      }
    }
    v16 = v7;
    _osif_vdev_sync_op_stop(v58[0], "wlan_hdd_cfg80211_channel_switch");
    result = v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
