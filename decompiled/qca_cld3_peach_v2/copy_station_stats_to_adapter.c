__int64 __fastcall copy_station_stats_to_adapter(__int64 a1, __int64 a2)
{
  __int64 v4; // x25
  __int64 result; // x0
  __int64 v6; // x24
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x8
  __int64 v11; // x22
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  char v20; // w0
  unsigned __int8 v21; // w8
  unsigned int v22; // w19
  __int64 link_info_from_vdev; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x19
  __int64 v33; // x24
  __int64 v34; // x19
  unsigned int v35; // w25
  int v36; // w0
  __int64 dynamic_vdev_config; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _DWORD *v46; // x22
  int connected_band; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w23
  unsigned int v57; // w19
  unsigned __int64 v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 cmpt_obj; // x0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x0
  __int64 v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x0
  __int64 v87; // x0
  _BOOL4 v88; // w22
  unsigned __int8 mcs_idx; // w0
  int v90; // w8
  __int64 v91; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // [xsp+0h] [xbp-130h]
  __int64 v103; // [xsp+8h] [xbp-128h]
  _QWORD v104[24]; // [xsp+10h] [xbp-120h] BYREF
  _QWORD v105[12]; // [xsp+D0h] [xbp-60h] BYREF

  v105[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)a1;
  result = _hdd_objmgr_get_vdev_by_user(a1, 0x51u, (__int64)"copy_station_stats_to_adapter");
  if ( result )
  {
    v6 = result;
    qdf_mem_copy((void *)(a1 + 2712), (const void *)(*(_QWORD *)(a2 + 96) + 12LL), 0x10u);
    qdf_mem_copy((void *)(a1 + 2728), (const void *)(*(_QWORD *)(a2 + 96) + 28LL), 0x10u);
    qdf_mem_copy((void *)(a1 + 2744), (const void *)(*(_QWORD *)(a2 + 96) + 44LL), 0x10u);
    qdf_mem_copy((void *)(a1 + 2768), (const void *)(*(_QWORD *)(a2 + 96) + 68LL), 0x10u);
    *(_DWORD *)(a1 + 2704) = *(_DWORD *)(*(_QWORD *)(a2 + 96) + 4LL);
    *(_BYTE *)(a1 + 2708) = *(_BYTE *)(*(_QWORD *)(a2 + 96) + 8LL);
    *(_DWORD *)(a1 + 2760) = *(_DWORD *)(*(_QWORD *)(a2 + 96) + 60LL);
    *(_DWORD *)(a1 + 2764) = *(_DWORD *)(*(_QWORD *)(a2 + 96) + 64LL);
    *(_DWORD *)(a1 + 2784) = *(_DWORD *)(*(_QWORD *)(a2 + 96) + 84LL);
    *(_DWORD *)(a1 + 2788) = *(_DWORD *)(*(_QWORD *)(a2 + 96) + 88LL);
    *(_DWORD *)(a1 + 2792) = *(_DWORD *)(*(_QWORD *)(a2 + 96) + 92LL);
    *(_DWORD *)(a1 + 2796) = *(_DWORD *)(*(_QWORD *)(a2 + 96) + 96LL);
    *(_DWORD *)(a1 + 2800) = *(_DWORD *)(*(_QWORD *)(a2 + 96) + 100LL);
    *(_DWORD *)(a1 + 4512) = *(_DWORD *)(*(_QWORD *)(a2 + 56) + 12LL);
    *(_QWORD *)(a1 + 4520) = *(_QWORD *)(*(_QWORD *)(a2 + 56) + 16LL);
    *(_DWORD *)(a1 + 4528) = *(_DWORD *)(*(_QWORD *)(a2 + 56) + 8LL);
    *(_DWORD *)(v4 + 71104) = **(_DWORD **)(a2 + 8);
    *(_DWORD *)(v4 + 71108) = jiffies_to_msecs(jiffies);
    v7 = *(_QWORD *)(a2 + 192);
    if ( v7 )
      *(_BYTE *)(a1 + 2697) = *(_BYTE *)(v7 + 1);
    qdf_mem_copy((void *)(a1 + 2948), (const void *)(*(_QWORD *)(a2 + 128) + 1LL), 2u);
    v9 = *(_QWORD *)(a2 + 168);
    v8 = *(_QWORD *)(a2 + 176);
    *(_DWORD *)(a1 + 4556) = *(_DWORD *)(a2 + 184);
    *(_QWORD *)(a1 + 4540) = v9;
    *(_QWORD *)(a1 + 4548) = v8;
    v10 = *(_QWORD *)(v6 + 216);
    if ( v10 )
      v11 = *(_QWORD *)(v10 + 80);
    else
      v11 = 0;
    v12 = ucfg_cp_stats_is_bcn_rssi_history_report_cfg_enable(v11);
    if ( (v20 & 1) != 0 && *(_DWORD *)(a2 + 200) && *(_QWORD *)(a2 + 208) )
    {
      v102 = v6;
      v21 = 0;
      do
      {
        v22 = v21;
        link_info_from_vdev = wlan_hdd_get_link_info_from_vdev(
                                v12,
                                v13,
                                v14,
                                v15,
                                v16,
                                v17,
                                v18,
                                v19,
                                v11,
                                *(_BYTE *)(*(_QWORD *)(a2 + 208) + 84LL * v21));
        if ( link_info_from_vdev )
          qdf_mem_copy(
            (void *)(link_info_from_vdev + 4560),
            (const void *)(*(_QWORD *)(a2 + 208) + 84LL * v22 + 4),
            0x50u);
        else
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: no link info found vdev %d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "copy_station_bcn_rssi_stats",
            *(unsigned __int8 *)(*(_QWORD *)(a2 + 208) + 84LL * v22));
        v21 = v22 + 1;
      }
      while ( *(_DWORD *)(a2 + 200) > (unsigned int)(unsigned __int8)(v22 + 1) );
      if ( v4 )
      {
        v32 = v4 + 52840;
        v33 = v4 + 52840;
        memset(v105, 0, 80);
        memset(v104, 0, sizeof(v104));
        v103 = v4 + 52840;
        do
        {
          if ( (unsigned __int64)(0x71B3F945A27B1F49LL * ((v33 - v32) >> 3)) > 2 )
            break;
          if ( !(unsigned int)wlan_hdd_get_station_bcn_rssi_history(
                                (__int64 *)v33,
                                v105,
                                v12,
                                v13,
                                v14,
                                v15,
                                v16,
                                v17,
                                v18,
                                v19) )
          {
            v34 = 0;
            v35 = 0;
            do
            {
              v12 = scnprintf((char *)v104 + v35, 192LL - v35, "%d 0x%x,", LODWORD(v105[v34]), HIDWORD(v105[v34]));
              if ( v36 < 1 )
                break;
              v35 += v36;
              if ( v35 >= 0xAC )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "bcn_rssi_his vdev %d (rssi and tsf): %s",
                  v12,
                  v13,
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  *(unsigned __int8 *)(v33 + 8),
                  v104);
                v35 = 0;
              }
              ++v34;
            }
            while ( v34 != 10 );
            v32 = v103;
            if ( v35 )
              qdf_trace_msg(
                0x33u,
                8u,
                "bcn_rssi_his vdev %d (rssi and tsf): %s",
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                *(unsigned __int8 *)(v33 + 8),
                v104);
          }
          v33 += 6088;
        }
        while ( v33 );
      }
      v6 = v102;
    }
    dynamic_vdev_config = mlme_get_dynamic_vdev_config(v6, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( !dynamic_vdev_config )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: nss chain dynamic config NULL",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "copy_station_stats_to_adapter");
LABEL_60:
      result = _hdd_objmgr_put_vdev_by_user(
                 v6,
                 0x51u,
                 (__int64)"copy_station_stats_to_adapter",
                 (unsigned int *)v58,
                 v59,
                 v60,
                 v61,
                 v62,
                 v63,
                 v64,
                 v65,
                 v66);
      goto LABEL_61;
    }
    v46 = (_DWORD *)dynamic_vdev_config;
    connected_band = hdd_conn_get_connected_band(a1);
    if ( connected_band == 2 )
    {
      v56 = v46[5];
      v57 = v46[7];
    }
    else if ( connected_band == 1 )
    {
      v56 = v46[4];
      v57 = v46[6];
    }
    else
    {
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v6, v48, v49, v50, v51, v52, v53, v54, v55);
      if ( cmpt_obj )
        v56 = *(unsigned __int8 *)(cmpt_obj + 23);
      else
        v56 = 0;
      v76 = wlan_vdev_mlme_get_cmpt_obj(v6, v68, v69, v70, v71, v72, v73, v74, v75);
      if ( v76 )
        v57 = *(unsigned __int8 *)(v76 + 23);
      else
        v57 = 0;
    }
    v77 = wlan_vdev_mlme_get_cmpt_obj(v6, v48, v49, v50, v51, v52, v53, v54, v55);
    if ( v77 )
    {
      if ( v57 <= *(unsigned __int8 *)(v77 + 23) )
      {
LABEL_47:
        *(_BYTE *)(a1 + 2809) = v57;
        *(_DWORD *)(a1 + 2824) = *(_DWORD *)(a2 + 140);
        *(_DWORD *)(a1 + 2856) = *(_DWORD *)(a2 + 144);
        v87 = wlan_vdev_mlme_get_cmpt_obj(v6, v78, v79, v80, v81, v82, v83, v84, v85);
        if ( v87 )
          v88 = *(_WORD *)(v87 + 280) != 0;
        else
          v88 = 0;
        mcs_idx = sme_get_mcs_idx(
                    *(unsigned int *)(a2 + 140),
                    *(unsigned int *)(a2 + 144),
                    v88,
                    a1 + 2809,
                    a1 + 2845,
                    a1 + 2852,
                    a1 + 2840);
        v90 = *(unsigned __int8 *)(a1 + 2860);
        *(_DWORD *)(a1 + 2832) = mcs_idx;
        if ( v90 )
        {
          v58 = *(unsigned __int8 *)(a1 + 2861);
          if ( *(_BYTE *)(a1 + 2861) )
            goto LABEL_60;
        }
        v91 = wlan_vdev_mlme_get_cmpt_obj(v6, v59, v60, v61, v62, v63, v64, v65, v66);
        if ( v91 )
        {
          if ( v56 <= *(unsigned __int8 *)(v91 + 23) )
            goto LABEL_59;
        }
        else if ( !v56 )
        {
LABEL_59:
          *(_BYTE *)(a1 + 2808) = v56;
          v101 = *(unsigned int *)(a2 + 136);
          *(_DWORD *)(a1 + 2820) = v101;
          v58 = (unsigned __int8)sme_get_mcs_idx(
                                   v101,
                                   *(unsigned int *)(a2 + 144),
                                   v88,
                                   a1 + 2808,
                                   a1 + 2844,
                                   a1 + 2848,
                                   a1 + 2836);
          *(_DWORD *)(a1 + 2828) = v58;
          goto LABEL_60;
        }
        v100 = wlan_vdev_mlme_get_cmpt_obj(v6, v92, v93, v94, v95, v96, v97, v98, v99);
        if ( v100 )
          LOBYTE(v56) = *(_BYTE *)(v100 + 23);
        else
          LOBYTE(v56) = 0;
        goto LABEL_59;
      }
    }
    else if ( !v57 )
    {
      goto LABEL_47;
    }
    v86 = wlan_vdev_mlme_get_cmpt_obj(v6, v78, v79, v80, v81, v82, v83, v84, v85);
    if ( v86 )
      LOBYTE(v57) = *(_BYTE *)(v86 + 23);
    else
      LOBYTE(v57) = 0;
    goto LABEL_47;
  }
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
