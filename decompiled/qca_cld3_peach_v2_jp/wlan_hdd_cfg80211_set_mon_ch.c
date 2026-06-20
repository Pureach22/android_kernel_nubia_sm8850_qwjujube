__int64 __fastcall wlan_hdd_cfg80211_set_mon_ch(_QWORD *a1, unsigned int *a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w0
  unsigned int v15; // w19
  __int64 v16; // x21
  __int64 adapter; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w23
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  bool is_sub_20_mhz_enabled; // w0
  const char *v53; // x2
  unsigned int vht_ch_width; // w5
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x26
  __int64 v64; // x27
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w9
  unsigned int v74; // w10
  int v75; // w24
  __int64 v76; // x8
  __int64 v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x20
  unsigned int v95; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x20
  unsigned int v105; // w21
  __int64 v106; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // x22
  __int64 v116; // x8
  __int16 v117; // w9
  unsigned int v118; // w20
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 v127; // x21
  unsigned int v128; // w0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x23
  __int64 v138; // x21
  __int64 v139; // x19
  __int64 v140; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v141; // [xsp+10h] [xbp-20h] BYREF
  __int64 v142; // [xsp+14h] [xbp-1Ch]
  int v143; // [xsp+1Ch] [xbp-14h]
  int v144; // [xsp+20h] [xbp-10h] BYREF
  __int16 v145; // [xsp+24h] [xbp-Ch]
  __int64 v146; // [xsp+28h] [xbp-8h]

  v146 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[61];
  v140 = 0;
  result = _osif_psoc_sync_op_start(v4, &v140, "wlan_hdd_cfg80211_set_mon_ch");
  if ( (_DWORD)result )
    goto LABEL_5;
  if ( a1 )
  {
    v145 = 0;
    v144 = 0;
    v143 = 0;
    v142 = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v6, v7, v8, v9, v10, v11, v12, v13, "__wlan_hdd_cfg80211_set_mon_ch");
    v14 = _wlan_hdd_validate_context(a1 + 192, "__wlan_hdd_cfg80211_set_mon_ch");
    if ( v14 )
      goto LABEL_4;
    v16 = a1[194];
    adapter = hdd_get_adapter(a1 + 192, 6);
    if ( !adapter )
    {
      v14 = -5;
      goto LABEL_4;
    }
    v26 = adapter;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: %s: set monitor mode freq %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "__wlan_hdd_cfg80211_set_mon_ch",
      *(_QWORD *)(adapter + 32) + 296LL,
      *(unsigned int *)(*(_QWORD *)a2 + 4LL));
    if ( (wlan_reg_get_channel_state_for_pwrmode(
            a1[193],
            *(_DWORD *)(*(_QWORD *)a2 + 4LL),
            0,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34)
        & 0xFFFFFFFB) != 0 )
    {
      v43 = hdd_map_nl_chan_width(a2[2]);
      if ( v43 > 6
        || (is_sub_20_mhz_enabled = cds_is_sub_20_mhz_enabled(v44, v45, v46, v47, v48, v49, v50, v51), v43 >= 4)
        && !is_sub_20_mhz_enabled )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: invalid BW received %d",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "__wlan_hdd_cfg80211_set_mon_ch",
          v43);
        v14 = -22;
        goto LABEL_4;
      }
      vht_ch_width = (unsigned __int8)sme_get_vht_ch_width();
      if ( v43 == 3 && vht_ch_width < 2 || v43 == 4 && vht_ch_width <= 2 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: FW does not support this BW %d max BW supported %d",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "__wlan_hdd_cfg80211_set_mon_ch",
          v43);
        v14 = -22;
        goto LABEL_4;
      }
      v63 = v26 + 49152;
      v64 = *(_QWORD *)(v26 + 52824);
      if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(*(_QWORD *)a2 + 4LL)) && a2[2] == 2 && (v73 = a2[3]) != 0 )
      {
        v74 = *(_DWORD *)(*(_QWORD *)a2 + 4LL);
        if ( v73 <= v74 )
        {
          if ( v73 >= v74 )
            v75 = 0;
          else
            v75 = v74 - 20;
        }
        else
        {
          v75 = v74 + 20;
        }
      }
      else
      {
        v75 = 0;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: set mon ch:width=%d, freq %d sec_ch_2g_freq=%d",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "__wlan_hdd_cfg80211_set_mon_ch");
      qdf_mem_copy(&v144, (const void *)(v26 + 1617), 6u);
      v76 = *(_QWORD *)a2;
      v77 = a1[193];
      v141 = v43;
      wlan_reg_set_channel_params_for_pwrmode(
        v77,
        *(_DWORD *)(v76 + 4),
        v75,
        (__int64)&v141,
        0,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85);
      if ( !(unsigned int)wlan_hdd_change_hw_mode_for_given_chnl(
                            v26,
                            *(_DWORD *)(*(_QWORD *)a2 + 4LL),
                            1u,
                            v86,
                            v87,
                            v88,
                            v89,
                            v90,
                            v91,
                            v92,
                            v93) )
      {
        if ( *(_BYTE *)(v26 + 52194) == 1 )
        {
          v94 = jiffies;
          if ( _wlan_hdd_cfg80211_set_mon_ch___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: monitor mode vdev up in progress",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "__wlan_hdd_cfg80211_set_mon_ch");
            _wlan_hdd_cfg80211_set_mon_ch___last_ticks = v94;
          }
          v14 = -16;
          goto LABEL_4;
        }
        v95 = qdf_event_reset(v26 + 1664);
        if ( v95 )
        {
          v104 = jiffies;
          if ( _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1136 - jiffies + 125 < 0 )
          {
            v105 = v95;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: failed to reinit monitor mode vdev up event",
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              "__wlan_hdd_cfg80211_set_mon_ch");
            v95 = v105;
            _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1136 = v104;
          }
          v14 = qdf_status_to_os_return(v95);
          goto LABEL_4;
        }
        *(_BYTE *)(v26 + 52194) = 1;
        qdf_mem_set(&v141, 0x10u, 0);
        v106 = _qdf_mem_malloc(0x40u, "__wlan_hdd_cfg80211_set_mon_ch", 32592);
        if ( v106 )
        {
          v115 = v106;
          *(_BYTE *)v106 = *(_BYTE *)(*(_QWORD *)(v26 + 52824) + 8LL);
          v116 = *(_QWORD *)a2;
          v141 = v43;
          LODWORD(v116) = *(_DWORD *)(v116 + 4);
          *(_DWORD *)(v106 + 12) = v43;
          *(_DWORD *)(v106 + 4) = v116;
          hdd_select_cbmode(
            v26,
            *(_DWORD *)(*(_QWORD *)a2 + 4LL),
            v75,
            &v141,
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114);
          v117 = *(_WORD *)((char *)&v142 + 1);
          *(_BYTE *)(v115 + 8) = v142;
          *(_WORD *)(v115 + 16) = v117;
          sme_fill_channel_change_request(v16, v115, *(unsigned int *)(v64 + 92));
          v118 = sme_send_channel_change_req(v16, v115);
          _qdf_mem_free(v115);
          if ( v118 )
          {
            v127 = jiffies;
            if ( _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1138 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to set sme_RoamChannel for monitor mode status: %d",
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                v125,
                v126,
                "__wlan_hdd_cfg80211_set_mon_ch",
                v118);
              _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1138 = v127;
            }
          }
          else
          {
            v128 = qdf_wait_for_event_completion(v26 + 1664, 0x2EE0u);
            if ( !v128 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: exit",
                v129,
                v130,
                v131,
                v132,
                v133,
                v134,
                v135,
                v136,
                "__wlan_hdd_cfg80211_set_mon_ch");
              v14 = 0;
              goto LABEL_4;
            }
            v118 = v128;
            v137 = jiffies;
            if ( _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1140 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: monitor vdev up event time out vdev id: %d",
                v129,
                v130,
                v131,
                v132,
                v133,
                v134,
                v135,
                v136,
                "__wlan_hdd_cfg80211_set_mon_ch",
                *(unsigned __int8 *)(*(_QWORD *)(v26 + 52824) + 8LL));
              _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1140 = v137;
            }
            if ( *(_BYTE *)(v26 + 1701) == 1 )
            {
              v138 = jiffies;
              if ( _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1142 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: monitor mode vdev up event forcefully set",
                  v129,
                  v130,
                  v131,
                  v132,
                  v133,
                  v134,
                  v135,
                  v136,
                  "__wlan_hdd_cfg80211_set_mon_ch");
                _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1142 = v138;
              }
            }
            else
            {
              v139 = jiffies;
              if ( v118 == 15 )
              {
                if ( _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1144 - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: monitor mode vdev up timed out",
                    v129,
                    v130,
                    v131,
                    v132,
                    v133,
                    v134,
                    v135,
                    v136,
                    "__wlan_hdd_cfg80211_set_mon_ch");
                  _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1144 = v139;
                }
              }
              else if ( _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1146 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed monitor mode vdev up(status-%d)",
                  v129,
                  v130,
                  v131,
                  v132,
                  v133,
                  v134,
                  v135,
                  v136,
                  "__wlan_hdd_cfg80211_set_mon_ch",
                  v118);
                _wlan_hdd_cfg80211_set_mon_ch___last_ticks_1146 = v139;
              }
            }
          }
          *(_BYTE *)(v63 + 3042) = 0;
          v14 = qdf_status_to_os_return(v118);
          goto LABEL_4;
        }
        v14 = -12;
LABEL_4:
        v15 = v14;
        _osif_psoc_sync_op_stop(v140, "wlan_hdd_cfg80211_set_mon_ch");
        result = v15;
LABEL_5:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v53 = "%s: Failed to change hw mode";
    }
    else
    {
      v53 = "%s: Invalid chan freq received for monitor mode aborting";
    }
    qdf_trace_msg(0x33u, 2u, v53, v35, v36, v37, v38, v39, v40, v41, v42, "__wlan_hdd_cfg80211_set_mon_ch");
    v14 = -22;
    goto LABEL_4;
  }
  __break(0x800u);
  return wlan_hdd_cfg80211_connect();
}
