__int64 __fastcall wlan_hdd_cfg80211_get_channel(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x25
  __int64 *v11; // x22
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
  int v33; // w24
  __int64 v34; // x0
  __int64 v35; // x0
  unsigned int v36; // w28
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x24
  unsigned int v56; // w23
  __int64 link_info_by_vdev; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int16 *v66; // x8
  unsigned int v67; // w24
  unsigned int v68; // w25
  unsigned int v69; // w26
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  int ch_width_from_phymode; // w27
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  bool is_24ghz_ch_freq; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w2
  const char *v97; // x2
  const char *v98; // x3
  unsigned int v99; // w1
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x24
  char v110; // w25
  __int64 v111; // x0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  int per_link_chan_info; // w23
  __int64 vdev_by_user; // x0
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 v130; // x21
  __int64 vdev_by_link_id; // x22
  unsigned int *v132; // x23
  unsigned int v133; // w22
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  int v142; // w8
  unsigned int v143; // w9
  int v144; // w8
  int v145; // w26
  unsigned int v146; // w23
  unsigned int v147; // w24
  bool v148; // w0
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  unsigned int v157; // w2
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  unsigned int *v166; // x8
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  double v183; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  __int64 channel_khz; // x0
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  int v200; // w8
  int v201; // w9
  unsigned int v202; // w6
  __int64 v203; // x5
  int v204; // w19
  unsigned int *v205; // x8
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  __int64 v214; // [xsp+10h] [xbp-70h] BYREF
  __int64 v215; // [xsp+18h] [xbp-68h] BYREF
  unsigned __int64 v216; // [xsp+20h] [xbp-60h]
  __int64 v217; // [xsp+28h] [xbp-58h]
  _QWORD v218[2]; // [xsp+30h] [xbp-50h] BYREF
  unsigned __int64 v219; // [xsp+40h] [xbp-40h]
  __int64 v220; // [xsp+48h] [xbp-38h]
  __int64 v221; // [xsp+50h] [xbp-30h]
  __int64 v222; // [xsp+58h] [xbp-28h] BYREF
  int v223; // [xsp+60h] [xbp-20h] BYREF
  __int64 v224; // [xsp+64h] [xbp-1Ch]
  __int64 v225; // [xsp+6Ch] [xbp-14h]
  int v226; // [xsp+74h] [xbp-Ch]
  __int64 v227; // [xsp+78h] [xbp-8h]

  v227 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v214 = 0;
  result = _osif_vdev_sync_op_start(v8, &v214, "wlan_hdd_cfg80211_get_channel");
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
      v31 = *(_QWORD *)(v10 + 55520);
      if ( v31 )
      {
        if ( (*(_QWORD *)(v31 + 5968) & 2) == 0 )
          goto LABEL_4;
        v32 = *(_DWORD *)(v31 + 320);
        v33 = 0;
        if ( v32 > 2047 )
        {
          if ( v32 >= 0x2000 )
          {
            if ( v32 != 0x2000 && v32 != 0x4000 )
              goto LABEL_54;
          }
          else if ( v32 != 2048 && v32 != 4096 )
          {
            goto LABEL_54;
          }
        }
        else if ( v32 > 255 )
        {
          if ( v32 != 256 && v32 != 512 )
            goto LABEL_54;
        }
        else if ( v32 != 16 && v32 != 64 )
        {
LABEL_54:
          v33 = 1;
        }
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(v31, 6, "wlan_key_get_link_vdev");
        if ( vdev_by_user )
        {
          v130 = vdev_by_user;
          if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v122, v123, v124, v125, v126, v127, v128, v129) & 1) == 0
            || (vdev_by_link_id = mlo_get_vdev_by_link_id(v130, a3, 6),
                _hdd_objmgr_put_vdev_by_user(v130, 6, "wlan_key_get_link_vdev"),
                (v130 = vdev_by_link_id) != 0) )
          {
            v132 = *(unsigned int **)(v130 + 40);
            v133 = *(unsigned __int16 *)v132;
            *(_QWORD *)(a4 + 12) = v132[4];
            *(_QWORD *)a4 = ieee80211_get_channel_khz(a1, 1000 * v133);
            v142 = v132[6];
            if ( v142 <= 2 )
            {
              if ( v142 )
              {
                if ( v142 == 1 )
                {
                  v144 = 2;
                  goto LABEL_85;
                }
                if ( v142 == 2 )
                {
                  v144 = 3;
LABEL_85:
                  *(_DWORD *)(a4 + 8) = v144;
                  goto LABEL_86;
                }
              }
              else if ( v33 )
              {
                *(_DWORD *)(a4 + 8) = 0;
LABEL_86:
                if ( v132[6] == 7 )
                {
                  *(_DWORD *)(a4 + 8) = 13;
                  *(_DWORD *)(a4 + 12) = v132[5];
                }
                if ( (wlan_vdev_mlme_is_mlo_vdev(v130, v134, v135, v136, v137, v138, v139, v140, v141) & 1) != 0 )
                  wlan_objmgr_vdev_release_ref(v130, 6u, v166, v167, v168, v169, v170, v171, v172, v173, v174);
                else
                  _hdd_objmgr_put_vdev_by_user(v130, 6, "wlan_key_put_link_vdev");
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: vdev: %d, freq:%d, ch_width:%d, c_freq1:%d, c_freq2:%d",
                  v175,
                  v176,
                  v177,
                  v178,
                  v179,
                  v180,
                  v181,
                  v182,
                  "wlan_hdd_cfg80211_get_channel_sap",
                  *(unsigned __int8 *)(v130 + 168),
                  v133,
                  *(unsigned int *)(a4 + 8),
                  *(unsigned int *)(a4 + 12),
                  *(_DWORD *)(a4 + 16));
                v20 = 0;
                goto LABEL_5;
              }
            }
            else
            {
              if ( v142 <= 4 )
              {
                v143 = v132[5];
                if ( v142 == 3 )
                {
                  *(_DWORD *)(a4 + 8) = 5;
                  *(_DWORD *)(a4 + 12) = v143;
                }
                else
                {
                  *(_DWORD *)(a4 + 8) = 4;
                  *(_DWORD *)(a4 + 16) = v143;
                }
                goto LABEL_86;
              }
              if ( v142 == 5 )
              {
                v144 = 6;
                goto LABEL_85;
              }
              if ( v142 == 6 )
              {
                v144 = 7;
                goto LABEL_85;
              }
            }
            v144 = 1;
            goto LABEL_85;
          }
        }
LABEL_4:
        v20 = -22;
LABEL_5:
        v21 = v20;
        _osif_vdev_sync_op_stop(v214, "wlan_hdd_cfg80211_get_channel");
        result = v21;
        goto LABEL_6;
      }
      v97 = "%s: invalid link_info";
      v98 = "wlan_hdd_cfg80211_get_channel_sap";
      v99 = 2;
LABEL_34:
      qdf_trace_msg(0x33u, v99, v97, v22, v23, v24, v25, v26, v27, v28, v29, v98);
      goto LABEL_4;
    }
    v220 = 0;
    v221 = 0;
    v34 = *(_QWORD *)(v10 + 55520);
    v218[1] = 0;
    v219 = 0;
    v217 = 0;
    v218[0] = 0;
    v215 = 0;
    v216 = 0;
    if ( (hdd_cm_is_vdev_associated(v34) & 1) == 0 )
    {
      v97 = "%s: vdev not associated";
      v98 = "wlan_hdd_cfg80211_get_channel_sta";
      v99 = 8;
      goto LABEL_34;
    }
    v35 = *(_QWORD *)(v10 + 55520);
    v36 = *(_DWORD *)(v35 + 688);
    v37 = _hdd_objmgr_get_vdev_by_user(v35, 6, "wlan_key_get_link_vdev");
    if ( v37
      && ((v46 = v37, (wlan_vdev_mlme_is_mlo_vdev(v37, v38, v39, v40, v41, v42, v43, v44, v45) & 1) == 0)
       || (v55 = mlo_get_vdev_by_link_id(v46, a3, 6),
           _hdd_objmgr_put_vdev_by_user(v46, 6, "wlan_key_get_link_vdev"),
           (v46 = v55) != 0)) )
    {
      if ( ucfg_cm_is_vdev_active(v46, v47, v48, v49, v50, v51, v52, v53, v54) )
      {
        v56 = *(unsigned __int8 *)(v46 + 168);
        v226 = 0;
        v225 = 0;
        v224 = 0;
        v222 = 0;
        link_info_by_vdev = hdd_get_link_info_by_vdev(v11);
        if ( !link_info_by_vdev )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: link_info is null",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "wlan_hdd_cfg80211_get_vdev_chan_info");
          v20 = -16;
          goto LABEL_117;
        }
        v66 = *(unsigned __int16 **)(v46 + 40);
        v67 = *v66;
        v68 = *((_DWORD *)v66 + 4);
        v69 = *((_DWORD *)v66 + 5);
        LOWORD(v218[0]) = *v66;
        mlme_get_peer_phymode(*v11, (_BYTE *)(link_info_by_vdev + 308), (_DWORD *)&v222 + 1);
        ch_width_from_phymode = wlan_mlme_get_ch_width_from_phymode(
                                  HIDWORD(v222),
                                  v70,
                                  v71,
                                  v72,
                                  v73,
                                  v74,
                                  v75,
                                  v76,
                                  v77);
        LODWORD(v220) = ch_width_from_phymode;
        if ( (wlan_mlme_get_cur_ch_width_update_from_ap(v46, &v222, v79, v80, v81, v82, v83, v84, v85, v86) & 1) != 0 )
        {
          ch_width_from_phymode = v222;
          LODWORD(v220) = v222;
        }
        v223 = ch_width_from_phymode;
        LODWORD(v225) = v69;
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v67);
        v96 = 0;
        if ( ch_width_from_phymode == 1 && is_24ghz_ch_freq )
        {
          if ( v68 <= v67 )
            v96 = v67 - 20;
          else
            v96 = v67 + 20;
        }
        wlan_reg_set_channel_params_for_pwrmode(
          v11[1],
          v67,
          v96,
          (__int64)&v223,
          0,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95);
        if ( __PAIR64__(v69, v68) != __PAIR64__(v225, HIDWORD(v224)) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Old ccfs1 %d ccfs2 %d - New ccfs1 %d ccfs2 %d",
            v158,
            v159,
            v160,
            v161,
            v162,
            v163,
            v164,
            v165,
            "wlan_hdd_cfg80211_get_vdev_chan_info",
            v68,
            v69);
          v68 = HIDWORD(v224);
          v69 = v225;
        }
        v219 = __PAIR64__(v69, v68);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev: %d, freq: %d, freq1: %d, freq2: %d, ch_width: %d, max_ch_width:%d",
          v158,
          v159,
          v160,
          v161,
          v162,
          v163,
          v164,
          v165,
          "wlan_hdd_cfg80211_get_vdev_chan_info",
          v56,
          v67,
          v68,
          v69,
          ch_width_from_phymode,
          v223);
        v110 = 0;
LABEL_95:
        channel_khz = ieee80211_get_channel_khz(a1, 1000 * (unsigned int)LOWORD(v218[0]));
        v200 = HIDWORD(v219);
        v201 = v220;
        v202 = v219;
        *(_QWORD *)a4 = channel_khz;
        *(_QWORD *)(a4 + 12) = v202;
        if ( v201 <= 2 )
        {
          switch ( v201 )
          {
            case 0:
              if ( v36 <= 3 )
              {
                v203 = 0;
                *(_DWORD *)(a4 + 8) = 0;
                goto LABEL_116;
              }
              v203 = 1;
              goto LABEL_115;
            case 1:
              v203 = 2;
              goto LABEL_115;
            case 2:
              v203 = 3;
              goto LABEL_115;
          }
        }
        else
        {
          if ( v201 <= 4 )
          {
            if ( v201 != 3 )
            {
              v203 = 4;
              *(_DWORD *)(a4 + 16) = v200;
LABEL_115:
              *(_DWORD *)(a4 + 8) = v203;
LABEL_116:
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: freq:%d, ch_width:%d, c_freq1:%d, c_freq2:%d",
                v192,
                v193,
                v194,
                v195,
                v196,
                v197,
                v198,
                v199,
                "wlan_hdd_cfg80211_get_channel_sta",
                LOWORD(v218[0]),
                v203);
              v20 = 0;
              if ( (v110 & 1) != 0 )
                goto LABEL_5;
              goto LABEL_117;
            }
            v203 = 5;
LABEL_111:
            *(_DWORD *)(a4 + 8) = v203;
            *(_DWORD *)(a4 + 12) = v200;
            goto LABEL_116;
          }
          if ( v201 == 5 )
          {
            v203 = 6;
            goto LABEL_115;
          }
          if ( v201 == 6 )
          {
            v203 = 7;
            goto LABEL_115;
          }
        }
        v203 = 1;
        *(_DWORD *)(a4 + 8) = 1;
        if ( v201 != 7 )
          goto LABEL_116;
        v203 = 13;
        goto LABEL_111;
      }
      v111 = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(v10 + 55520), 6, "wlan_hdd_get_standby_link_chan_info");
      if ( !v111 )
      {
        v20 = -22;
        goto LABEL_117;
      }
      v109 = v111;
      v110 = 0;
    }
    else
    {
      v100 = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(v10 + 55520), 6, "wlan_hdd_get_standby_link_chan_info");
      if ( !v100 )
        goto LABEL_4;
      v109 = v100;
      v46 = 0;
      v110 = 1;
    }
    if ( (wlan_vdev_mlme_is_mlo_vdev(v109, v101, v102, v103, v104, v105, v106, v107, v108) & 1) != 0 )
    {
      per_link_chan_info = mlo_mgr_get_per_link_chan_info(v109, a3, v218);
      _hdd_objmgr_put_vdev_by_user(v109, 6, "wlan_hdd_get_standby_link_chan_info");
      if ( !per_link_chan_info )
      {
        v145 = v220;
        v146 = LOWORD(v218[0]);
        v147 = v219;
        LODWORD(v215) = v220;
        BYTE6(v215) = BYTE4(v219);
        v148 = wlan_reg_is_24ghz_ch_freq(LOWORD(v218[0]));
        v157 = 0;
        if ( v145 == 1 && v148 )
        {
          if ( v147 <= v146 )
            v157 = v146 - 20;
          else
            v157 = v146 + 20;
        }
        wlan_reg_set_channel_params_for_pwrmode(
          v11[1],
          LOWORD(v218[0]),
          v157,
          (__int64)&v215,
          0,
          v149,
          v150,
          v151,
          v152,
          v153,
          v154,
          v155,
          v156);
        v219 = v216;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: max allowed ch_width:%d, ap ch_width: %d",
          v183,
          v184,
          v185,
          v186,
          v187,
          v188,
          v189,
          v190,
          "wlan_hdd_cfg80211_get_channel_sta",
          (unsigned int)v215,
          (unsigned int)v220);
        if ( (unsigned int)v215 < (unsigned int)v220 )
          LODWORD(v220) = v215;
        goto LABEL_95;
      }
      v20 = per_link_chan_info;
      if ( (v110 & 1) != 0 )
        goto LABEL_5;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: not a mlo vdev",
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        "wlan_hdd_get_standby_link_chan_info");
      _hdd_objmgr_put_vdev_by_user(v109, 6, "wlan_hdd_get_standby_link_chan_info");
      v20 = -22;
      if ( (v110 & 1) != 0 )
        goto LABEL_5;
    }
LABEL_117:
    v204 = v20;
    if ( (wlan_vdev_mlme_is_mlo_vdev(v46, v101, v102, v103, v104, v105, v106, v107, v108) & 1) != 0 )
      wlan_objmgr_vdev_release_ref(v46, 6u, v205, v206, v207, v208, v209, v210, v211, v212, v213);
    else
      _hdd_objmgr_put_vdev_by_user(v46, 6, "wlan_key_put_link_vdev");
    v20 = v204;
    goto LABEL_5;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
