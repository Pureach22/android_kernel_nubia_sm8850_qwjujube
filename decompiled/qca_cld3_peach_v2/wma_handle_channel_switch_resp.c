__int64 __fastcall wma_handle_channel_switch_resp(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v12; // x24
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  int v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 cmpt_obj; // x0
  __int64 v32; // x22
  __int64 v33; // x25
  unsigned int v34; // w21
  unsigned int ht_rate_flags; // w0
  unsigned int v36; // w23
  __int64 v37; // x8
  int v38; // w8
  unsigned int v39; // w1

  v12 = (__int64 *)(*(_QWORD *)(a1 + 520) + 488LL * *(unsigned __int8 *)a2);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Send channel switch resp vdev %d, status %d, resp type %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_handle_channel_switch_resp");
  if ( !a2[2] )
    goto LABEL_12;
  if ( *((_DWORD *)v12 + 41) != 4 )
  {
    if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)*(unsigned __int8 *)a2 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Invalid vdev_id %hu",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wma_is_vdev_in_ap_mode");
    }
    else
    {
      v21 = *(_QWORD *)(a1 + 520) + 488LL * *(unsigned __int8 *)a2;
      if ( *(_DWORD *)(v21 + 164) == 1 )
      {
        v22 = *(_DWORD *)(v21 + 168);
        if ( !v22 || v22 == 3 )
          goto LABEL_10;
      }
    }
    if ( (mlme_is_chan_switch_in_progress(*v12, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
    {
      if ( a2[2] )
        goto LABEL_25;
LABEL_12:
      if ( a2[3] != 1
        || (wlan_objmgr_iterate_peerobj_list(
              *v12,
              (double (__fastcall *)(__int64, __int64, __int64))wma_peer_send_phymode,
              0,
              8u,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20),
            *((_DWORD *)v12 + 41) != 2)
        || (cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*v12, v13, v14, v15, v16, v17, v18, v19, v20)) == 0 )
      {
LABEL_25:
        if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)*(unsigned __int8 *)a2 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Invalid vdev_id %hu",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "wma_is_vdev_in_ap_mode");
        }
        else
        {
          v37 = *(_QWORD *)(a1 + 520) + 488LL * *(unsigned __int8 *)a2;
          if ( *(_DWORD *)(v37 + 164) == 1 )
          {
            v38 = *(_DWORD *)(v37 + 168);
            v39 = 4;
            if ( !v38 || v38 == 3 )
              goto LABEL_34;
          }
        }
        if ( (mlme_is_chan_switch_in_progress(*v12, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0 )
          v39 = 4;
        else
          v39 = 3;
LABEL_34:
        wlan_vdev_mlme_sm_deliver_evt(*v12, v39, 8u, (__int64)a2, v13, v14, v15, v16, v17, v18, v19, v20);
        return 0;
      }
      v32 = cmpt_obj;
      v33 = *(_QWORD *)(*v12 + 40);
      v34 = *(_DWORD *)(v33 + 28);
      if ( v34 - 31 > 9 )
      {
        if ( v34 - 21 > 9 )
        {
          if ( v34 - 11 > 9 )
          {
            if ( v34 - 5 > 5 )
            {
              v36 = 1;
              goto LABEL_24;
            }
            ht_rate_flags = wma_get_ht_rate_flags(*(_DWORD *)(v33 + 24));
          }
          else
          {
            ht_rate_flags = wma_get_vht_rate_flags(*(_DWORD *)(v33 + 24));
          }
        }
        else
        {
          ht_rate_flags = wma_get_he_rate_flags(*(_DWORD *)(v33 + 24));
        }
      }
      else
      {
        ht_rate_flags = wma_get_eht_rate_flags(*(unsigned int *)(v33 + 24));
      }
      v36 = ht_rate_flags;
LABEL_24:
      *(_DWORD *)(v32 + 304) = v36;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: bss phymode %d rate_flags %x, ch_width %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wma_update_rate_flags_after_vdev_restart",
        v34,
        v36,
        *(unsigned int *)(v33 + 24));
      ucfg_mc_cp_stats_set_rate_flags(*v12, v36);
      goto LABEL_25;
    }
  }
LABEL_10:
  mlme_set_chan_switch_in_progress(*v12, 0, v13, v14, v15, v16, v17, v18, v19, v20);
  lim_process_switch_channel_rsp(*(_QWORD *)(a1 + 16), a2, v23, v24, v25, v26, v27, v28, v29, v30);
  return 0;
}
