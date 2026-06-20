__int64 __fastcall wlan_hdd_cfg80211_get_channel(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x22
  __int64 *v11; // x25
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w8
  unsigned int v21; // w19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w9
  __int64 v31; // x0
  int v32; // w8
  int v33; // w23
  __int64 v34; // x0
  unsigned int v35; // w28
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x21
  unsigned int v46; // w26
  __int64 link_info_by_vdev; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned __int16 *v56; // x8
  unsigned int v57; // w22
  unsigned int v58; // w23
  unsigned int v59; // w24
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  int ch_width_from_phymode; // w27
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  bool v77; // zf
  bool is_24ghz_ch_freq; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned __int16 v87; // w2
  const char *v88; // x2
  const char *v89; // x3
  unsigned int v90; // w1
  int v91; // w19
  __int64 vdev_by_user; // x0
  unsigned int *v93; // x24
  __int64 v94; // x22
  unsigned int v95; // w21
  int v96; // w8
  unsigned int v97; // w9
  int v98; // w8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // x5
  __int64 v116; // x7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // [xsp+18h] [xbp-28h] BYREF
  int v126; // [xsp+20h] [xbp-20h] BYREF
  unsigned int v127; // [xsp+24h] [xbp-1Ch] BYREF
  int v128; // [xsp+28h] [xbp-18h] BYREF
  _DWORD v129[5]; // [xsp+2Ch] [xbp-14h]

  *(_QWORD *)&v129[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v125 = 0;
  result = _osif_vdev_sync_op_start(v8, &v125, "wlan_hdd_cfg80211_get_channel");
  if ( !(_DWORD)result )
  {
    v10 = *(_QWORD *)(a2 + 32);
    if ( (unsigned int)_hdd_validate_adapter(v10 + 2688, "__wlan_hdd_cfg80211_get_channel") )
      goto LABEL_4;
    v11 = *(__int64 **)(v10 + 2712);
    if ( (unsigned int)_wlan_hdd_validate_context(v11, "__wlan_hdd_cfg80211_get_channel") )
      goto LABEL_4;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: get channel for link id: %d, device mode: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "__wlan_hdd_cfg80211_get_channel",
      a3,
      *(unsigned int *)(v10 + 2728));
    hdd_reg_wait_for_country_change(v11);
    v30 = *(_DWORD *)(v10 + 2728);
    v20 = -22;
    if ( v30 > 1 )
    {
      if ( v30 != 2 )
      {
        if ( v30 != 3 )
          goto LABEL_5;
        goto LABEL_13;
      }
    }
    else if ( v30 )
    {
      if ( v30 != 1 )
        goto LABEL_5;
LABEL_13:
      v31 = *(_QWORD *)(v10 + 55512);
      if ( v31 )
      {
        if ( (*(_QWORD *)(v31 + 4416) & 2) == 0 )
          goto LABEL_4;
        v32 = *(_DWORD *)(v31 + 320);
        v33 = 0;
        if ( v32 > 2047 )
        {
          if ( v32 >= 0x2000 )
          {
            if ( v32 != 0x2000 && v32 != 0x4000 )
              goto LABEL_43;
          }
          else if ( v32 != 2048 && v32 != 4096 )
          {
            goto LABEL_43;
          }
        }
        else if ( v32 > 255 )
        {
          if ( v32 != 256 && v32 != 512 )
            goto LABEL_43;
        }
        else if ( v32 != 16 && v32 != 64 )
        {
LABEL_43:
          v33 = 1;
        }
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(v31, 6, "wlan_key_get_link_vdev");
        if ( vdev_by_user )
        {
          v93 = *(unsigned int **)(vdev_by_user + 40);
          v94 = vdev_by_user;
          v95 = *(unsigned __int16 *)v93;
          *(_QWORD *)(a4 + 12) = v93[4];
          *(_QWORD *)a4 = ieee80211_get_channel_khz(a1, 1000 * v95);
          v96 = v93[6];
          if ( v96 <= 2 )
          {
            if ( v96 )
            {
              if ( v96 == 1 )
              {
                v98 = 2;
                goto LABEL_77;
              }
              if ( v96 == 2 )
              {
                v98 = 3;
LABEL_77:
                *(_DWORD *)(a4 + 8) = v98;
                goto LABEL_78;
              }
            }
            else if ( v33 )
            {
              *(_DWORD *)(a4 + 8) = 0;
LABEL_78:
              _hdd_objmgr_put_vdev_by_user(v94, 6, "wlan_key_put_link_vdev");
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: vdev: %d, freq:%d, ch_width:%d, c_freq1:%d, c_freq2:%d",
                v117,
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                "wlan_hdd_cfg80211_get_channel_sap",
                *(unsigned __int8 *)(v94 + 104),
                v95,
                *(unsigned int *)(a4 + 8),
                *(unsigned int *)(a4 + 12),
                *(_DWORD *)(a4 + 16));
              v20 = 0;
              goto LABEL_5;
            }
          }
          else
          {
            if ( v96 <= 4 )
            {
              v97 = v93[5];
              if ( v96 == 3 )
              {
                *(_DWORD *)(a4 + 8) = 5;
                *(_DWORD *)(a4 + 12) = v97;
              }
              else
              {
                *(_DWORD *)(a4 + 8) = 4;
                *(_DWORD *)(a4 + 16) = v97;
              }
              goto LABEL_78;
            }
            if ( v96 == 5 )
            {
              v98 = 6;
              goto LABEL_77;
            }
            if ( v96 == 6 )
            {
              v98 = 7;
              goto LABEL_77;
            }
          }
          v98 = 1;
          goto LABEL_77;
        }
LABEL_4:
        v20 = -22;
LABEL_5:
        v21 = v20;
        _osif_vdev_sync_op_stop(v125, "wlan_hdd_cfg80211_get_channel");
        result = v21;
        goto LABEL_6;
      }
      v88 = "%s: invalid link_info";
      v89 = "wlan_hdd_cfg80211_get_channel_sap";
      v90 = 2;
LABEL_32:
      qdf_trace_msg(0x33u, v90, v88, v22, v23, v24, v25, v26, v27, v28, v29, v89);
      goto LABEL_4;
    }
    if ( (hdd_cm_is_vdev_associated(*(_QWORD *)(v10 + 55512)) & 1) == 0 )
    {
      v88 = "%s: vdev not associated";
      v89 = "wlan_hdd_cfg80211_get_channel_sta";
      v90 = 8;
      goto LABEL_32;
    }
    v34 = *(_QWORD *)(v10 + 55512);
    v35 = *(_DWORD *)(v34 + 680);
    v36 = _hdd_objmgr_get_vdev_by_user(v34, 6, "wlan_key_get_link_vdev");
    if ( !v36 )
      goto LABEL_4;
    v45 = v36;
    if ( ucfg_cm_is_vdev_active(v36, v37, v38, v39, v40, v41, v42, v43, v44) )
    {
      v46 = *(unsigned __int8 *)(v45 + 104);
      *(_QWORD *)v129 = 0;
      v127 = 0;
      v126 = 0;
      link_info_by_vdev = hdd_get_link_info_by_vdev(v11);
      if ( link_info_by_vdev )
      {
        v56 = *(unsigned __int16 **)(v45 + 40);
        v57 = *v56;
        v58 = *((_DWORD *)v56 + 4);
        v59 = *((_DWORD *)v56 + 5);
        mlme_get_peer_phymode(*v11, (_BYTE *)(link_info_by_vdev + 300), &v127);
        ch_width_from_phymode = wlan_mlme_get_ch_width_from_phymode(v127, v60, v61, v62, v63, v64, v65, v66, v67);
        v77 = (wlan_mlme_get_cur_ch_width_update_from_ap(v45, &v126, v69, v70, v71, v72, v73, v74, v75, v76) & 1) == 0;
        v129[2] = v59;
        if ( !v77 )
          ch_width_from_phymode = v126;
        v128 = ch_width_from_phymode;
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v57);
        v87 = 0;
        if ( ch_width_from_phymode == 1 && is_24ghz_ch_freq )
        {
          if ( v58 <= v57 )
            v87 = v57 - 20;
          else
            v87 = v57 + 20;
        }
        wlan_reg_set_channel_params_for_pwrmode(
          v11[1],
          v57,
          v87,
          (__int64)&v128,
          0,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86);
        if ( __PAIR64__(v59, v58) != *(_QWORD *)&v129[1] )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Old ccfs1 %d ccfs2 %d - New ccfs1 %d ccfs2 %d",
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            "wlan_hdd_cfg80211_get_vdev_chan_info",
            v58,
            v59);
          v58 = v129[1];
          v59 = v129[2];
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev: %d, freq: %d, freq1: %d, freq2: %d, ch_width: %d, max_ch_width:%d",
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          "wlan_hdd_cfg80211_get_vdev_chan_info",
          v46,
          v57,
          v58,
          v59,
          ch_width_from_phymode,
          v128);
        *(_QWORD *)a4 = ieee80211_get_channel_khz(a1, 1000 * v57);
        *(_DWORD *)(a4 + 12) = v58;
        *(_DWORD *)(a4 + 16) = 0;
        if ( ch_width_from_phymode <= 2 )
        {
          if ( ch_width_from_phymode )
          {
            if ( ch_width_from_phymode == 1 )
            {
              v116 = 0;
              v115 = 2;
              goto LABEL_85;
            }
            if ( ch_width_from_phymode == 2 )
            {
              v116 = 0;
              v115 = 3;
              goto LABEL_85;
            }
          }
          else if ( v35 <= 3 )
          {
            v116 = 0;
            v115 = 0;
            *(_DWORD *)(a4 + 8) = 0;
            goto LABEL_86;
          }
        }
        else
        {
          if ( ch_width_from_phymode <= 4 )
          {
            if ( ch_width_from_phymode != 3 )
            {
              v115 = 4;
              *(_DWORD *)(a4 + 16) = v59;
              v116 = v59;
LABEL_85:
              *(_DWORD *)(a4 + 8) = v115;
              goto LABEL_86;
            }
            v115 = 5;
            v116 = 0;
            v58 = v59;
            *(_DWORD *)(a4 + 8) = 5;
            *(_DWORD *)(a4 + 12) = v59;
LABEL_86:
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: freq:%d, ch_width:%d, c_freq1:%d, c_freq2:%d",
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              "wlan_hdd_cfg80211_get_channel_sta",
              v57,
              v115,
              v58,
              v116);
            v91 = 0;
            goto LABEL_87;
          }
          if ( ch_width_from_phymode == 5 )
          {
            v116 = 0;
            v115 = 6;
            goto LABEL_85;
          }
          if ( ch_width_from_phymode == 6 )
          {
            v116 = 0;
            v115 = 7;
            goto LABEL_85;
          }
        }
        v116 = 0;
        v115 = 1;
        goto LABEL_85;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: link_info is null",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wlan_hdd_cfg80211_get_vdev_chan_info");
      v91 = -16;
    }
    else
    {
      v91 = -22;
    }
LABEL_87:
    _hdd_objmgr_put_vdev_by_user(v45, 6, "wlan_key_put_link_vdev");
    v20 = v91;
    goto LABEL_5;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
