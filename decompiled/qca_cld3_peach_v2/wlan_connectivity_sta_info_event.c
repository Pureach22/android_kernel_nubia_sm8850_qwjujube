__int64 __fastcall wlan_connectivity_sta_info_event(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w20
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int *v14; // x8
  __int64 v15; // x19
  __int64 v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x20
  unsigned __int16 *v26; // x24
  char *v27; // x21
  bool is_24ghz_ch_freq; // w8
  char *v29; // x0
  bool is_5ghz_ch_freq; // w8
  bool is_6ghz_chan_freq; // w8
  unsigned __int16 *v32; // x24
  bool v33; // w8
  char *v34; // x0
  bool v35; // w8
  bool v36; // w8
  unsigned __int16 *v37; // x24
  const void *v38; // x1
  __int64 *v39; // x0
  __int64 v40; // x21
  __int64 v41; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v43; // [xsp+10h] [xbp-30h]
  __int64 v44; // [xsp+18h] [xbp-28h]
  __int64 v45; // [xsp+20h] [xbp-20h] BYREF
  __int64 v46; // [xsp+28h] [xbp-18h] BYREF
  int v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  v4 = a2;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  time_of_the_day_us = 0;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( result )
  {
    v14 = (unsigned int *)*(unsigned int *)(result + 16);
    v15 = result;
    if ( (_DWORD)v14 )
      goto LABEL_3;
    if ( (wlan_vdev_mlme_is_mlo_vdev(result, v6, v7, v8, v9, v10, v11, v12, v13) & 1) != 0 )
    {
      v14 = (unsigned int *)*(unsigned __int8 *)(v15 + 67);
      if ( ((unsigned __int8)v14 & 2) != 0 )
        goto LABEL_3;
      v14 = (unsigned int *)*(unsigned __int8 *)(v15 + 60);
      if ( ((unsigned __int8)v14 & 2) != 0 )
        goto LABEL_3;
    }
    if ( (a3 & 1) == 0 && !wlan_cm_is_first_candidate_connect_attempt(v15, v6, v7, v8, v9, v10, v11, v12, v13) )
      goto LABEL_3;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    HIWORD(v41) = v4;
    v44 = ktime_get(time_of_the_day_us) / 1000;
    BYTE1(v45) = wlan_vdev_mlme_is_mlo_vdev(v15, v17, v18, v19, v20, v21, v22, v23, v24) & 1;
    if ( BYTE1(v45) )
    {
      qdf_mem_copy(&v41, (const void *)(v15 + 80), 6u);
      v25 = *(_QWORD **)(*(_QWORD *)(v15 + 1360) + 3880LL);
      if ( !v25 )
      {
        v40 = jiffies;
        v14 = (unsigned int *)(wlan_connectivity_sta_info_event___last_ticks_21 - jiffies);
        if ( wlan_connectivity_sta_info_event___last_ticks_21 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x1Fu,
            2u,
            "%s: wlan_populate_link_addr failed",
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            "wlan_connectivity_sta_info_event");
          wlan_connectivity_sta_info_event___last_ticks_21 = v40;
        }
        goto LABEL_3;
      }
      v26 = (unsigned __int16 *)v25[4];
      v27 = (char *)&v45 + 2;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*v26);
      v29 = (char *)&v45 + 2;
      if ( is_24ghz_ch_freq
        || (is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(*v26), v29 = (char *)&v46, is_5ghz_ch_freq)
        || (is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*v26), v29 = (char *)&v46 + 6, is_6ghz_chan_freq) )
      {
        qdf_mem_copy(v29, v25, 6u);
      }
      v32 = (unsigned __int16 *)v25[10];
      v33 = wlan_reg_is_24ghz_ch_freq(*v32);
      v34 = (char *)&v45 + 2;
      if ( v33
        || (v35 = wlan_reg_is_5ghz_ch_freq(*v32), v34 = (char *)&v46, v35)
        || (v36 = wlan_reg_is_6ghz_chan_freq(*v32), v34 = (char *)&v46 + 6, v36) )
      {
        qdf_mem_copy(v34, v25 + 6, 6u);
      }
      v37 = (unsigned __int16 *)v25[16];
      if ( !wlan_reg_is_24ghz_ch_freq(*v37) )
      {
        v27 = (char *)&v46;
        if ( !wlan_reg_is_5ghz_ch_freq(*v37) )
        {
          v27 = (char *)&v46 + 6;
          if ( !wlan_reg_is_6ghz_chan_freq(*v37) )
            goto LABEL_28;
        }
      }
      v38 = v25 + 12;
      v39 = (__int64 *)v27;
    }
    else
    {
      v39 = &v41;
      v38 = (const void *)(v15 + 74);
    }
    qdf_mem_copy(v39, v38, 6u);
LABEL_28:
    host_diag_event_report_payload(3414, 52, &v41);
LABEL_3:
    result = wlan_objmgr_vdev_release_ref(v15, 0x43u, v14, v6, v7, v8, v9, v10, v11, v12, v13);
    goto LABEL_6;
  }
  v16 = jiffies;
  if ( wlan_connectivity_sta_info_event___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x1Fu,
               2u,
               "%s: Invalid vdev:%d",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "wlan_connectivity_sta_info_event",
               v4);
    wlan_connectivity_sta_info_event___last_ticks = v16;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
