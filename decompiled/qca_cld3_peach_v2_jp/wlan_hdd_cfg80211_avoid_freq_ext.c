// positive sp value has been detected, the output may be wrong!
__int64 __fastcall wlan_hdd_cfg80211_avoid_freq_ext(_QWORD *a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x4
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  int v36; // w0
  __int64 v37; // x20
  __int64 *v38; // x20
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x23
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x20
  __int64 v57; // x25
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x21
  unsigned int v67; // w19
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x20
  int v77; // w9
  __int64 v78; // x20
  int v79; // w27
  unsigned __int64 v80; // x26
  unsigned int v81; // w21
  unsigned __int16 *v82; // x23
  __int64 v83; // x8
  unsigned int v84; // w9
  unsigned int v85; // w0
  __int64 v86; // x8
  unsigned int v87; // w1
  __int64 v88; // x22
  __int64 v89; // x24
  __int64 v90; // x23
  unsigned int v91; // w21
  __int64 adapter_by_ifindex; // x0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x22
  unsigned int v102; // w21
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int64 v119; // x20
  __int64 v120; // x20
  __int64 v121; // x20
  __int64 v122; // x22
  __int64 v123; // x20
  __int64 v124; // x20
  __int64 v125; // [xsp-390h] [xbp-6C0h] BYREF
  _QWORD v126[2]; // [xsp-388h] [xbp-6B8h] BYREF
  __int64 v127; // [xsp-378h] [xbp-6A8h]
  __int64 v128; // [xsp-370h] [xbp-6A0h]
  __int64 v129; // [xsp-368h] [xbp-698h]
  __int64 v130; // [xsp-360h] [xbp-690h]
  __int64 v131; // [xsp-358h] [xbp-688h]
  __int64 v132; // [xsp-350h] [xbp-680h] BYREF
  _WORD *v133; // [xsp-348h] [xbp-678h]
  __int64 v134; // [xsp-340h] [xbp-670h]
  __int64 v135; // [xsp-338h] [xbp-668h]
  __int64 v136; // [xsp-330h] [xbp-660h]
  __int64 v137; // [xsp-328h] [xbp-658h]
  __int64 v138; // [xsp-320h] [xbp-650h]
  _DWORD v139[170]; // [xsp-318h] [xbp-648h] BYREF
  __int64 v140; // [xsp-70h] [xbp-3A0h]
  __int64 v141; // [xsp+0h] [xbp-330h]

  v140 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a1[61];
  v125 = 0;
  result = _osif_psoc_sync_op_start(v8, &v125, (__int64)"wlan_hdd_cfg80211_avoid_freq_ext");
  if ( (_DWORD)result )
    goto LABEL_27;
  if ( !a1 )
  {
LABEL_87:
    __break(0x800u);
    JUMPOUT(0x55A830);
  }
  memset(v139, 0, sizeof(v139));
  v10 = *(_QWORD *)(a2 + 32) + 296LL;
  v137 = 0;
  v138 = 0;
  v135 = 0;
  v136 = 0;
  v133 = nullptr;
  v134 = 0;
  v131 = 0;
  v132 = 0;
  v129 = 0;
  v130 = 0;
  v127 = 0;
  v128 = 0;
  v126[0] = 0;
  v126[1] = 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "__wlan_hdd_cfg80211_avoid_freq_ext",
    v10);
  if ( (ucfg_mlme_get_coex_unsafe_chan_nb_user_prefer(a1[192]) & 1) == 0 )
  {
    v37 = jiffies;
    if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Coex unsafe chan nb user prefer is not set",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__wlan_hdd_cfg80211_avoid_freq_ext");
      _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks = v37;
    }
    v36 = -95;
    goto LABEL_26;
  }
  if ( (hdd_get_conparam() & 0xFFFFFFFE) != 4 )
  {
    v38 = a1 + 192;
    v36 = _wlan_hdd_validate_context(
            (__int64)(a1 + 192),
            (__int64)"__wlan_hdd_cfg80211_avoid_freq_ext",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34);
    if ( v36 )
      goto LABEL_26;
    v47 = *(_QWORD *)(a2 + 32);
    if ( v47 == -2688 )
    {
      v57 = jiffies;
      if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_4 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: adapter not found for ifindex: %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "__wlan_hdd_cfg80211_avoid_freq_ext",
          MEMORY[0xFFFFFFFFFFFFF660]);
        _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_4 = v57;
      }
    }
    else if ( (hdd_is_connection_in_progress(nullptr, nullptr, v39, v40, v41, v42, v43, v44, v45, v46) & 1) != 0
           && !policy_mgr_is_vdev_ll_lt_sap(*v38, *(unsigned __int8 *)(*(_QWORD *)(v47 + 55512) + 8LL)) )
    {
      v56 = jiffies;
      if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_6 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Update chan list refused: conn in progress",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "__wlan_hdd_cfg80211_avoid_freq_ext");
        _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_6 = v56;
      }
      v36 = -1;
      goto LABEL_26;
    }
    qdf_mem_set(v139, 0x2A8u, 0);
    if ( a3 || a4 )
    {
      if ( (unsigned int)_nla_parse(&v132, 6, a3, a4, &avoid_freq_ext_policy, 31, 0) )
      {
        v76 = jiffies;
        if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_10 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid avoid freq ext ATTR",
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            "__wlan_hdd_cfg80211_avoid_freq_ext");
          _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_10 = v76;
        }
        goto LABEL_7;
      }
      if ( !v133 )
      {
        v78 = jiffies;
        if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_12 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Attr avoid frequency ext range failed",
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            "__wlan_hdd_cfg80211_avoid_freq_ext");
          _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_12 = v78;
        }
        goto LABEL_7;
      }
      v139[0] = 42;
      if ( v137 )
      {
        v77 = *(_DWORD *)(v137 + 4);
        v139[169] = v77;
      }
      else
      {
        LOBYTE(v77) = v139[169];
      }
      if ( (v77 & 8) != 0 )
        v139[169] = 2;
      v79 = (unsigned __int16)(*v133 - 4);
      if ( (unsigned int)v79 < 4 )
      {
        v81 = 0;
LABEL_64:
        v90 = jiffies;
        if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_24 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            3u,
            "%s: Number of freq range %u less than expected %u",
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            "__wlan_hdd_cfg80211_avoid_freq_ext",
            v81,
            42);
          _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_24 = v90;
        }
        v139[0] = v81;
      }
      else
      {
        v80 = 0;
        v81 = 0;
        v82 = v133 + 2;
        do
        {
          v84 = *v82;
          if ( v84 < 4 || v79 < v84 )
            break;
          if ( v80 == 168 )
          {
            v122 = jiffies;
            if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_14 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                3u,
                "%s: Ignoring excess range number",
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                "__wlan_hdd_cfg80211_avoid_freq_ext");
              _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_14 = v122;
            }
            goto LABEL_67;
          }
          if ( (unsigned int)_nla_parse(v126, 6, v82 + 2, (unsigned __int16)(v84 - 4), &avoid_freq_ext_policy, 31, 0) )
          {
            v123 = jiffies;
            if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_16 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: nla_parse failed",
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                "__wlan_hdd_cfg80211_avoid_freq_ext");
              _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_16 = v123;
            }
            goto LABEL_7;
          }
          if ( !v127 )
            goto LABEL_7;
          v85 = *(_DWORD *)(v127 + 4);
          v86 = v128;
          v139[v80 + 1] = v85;
          if ( !v86 )
            goto LABEL_7;
          v87 = *(_DWORD *)(v86 + 4);
          v139[v80 + 2] = v87;
          if ( v85 || v87 || v80 * 4 )
          {
            if ( (wlan_reg_is_same_band_freqs(v85, v87) & 1) == 0 )
            {
              v124 = jiffies;
              if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_20 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: start freq %d end freq %d not in same band",
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  "__wlan_hdd_cfg80211_avoid_freq_ext",
                  (unsigned int)v139[v80 + 1],
                  (unsigned int)v139[v80 + 2]);
                _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_20 = v124;
              }
              goto LABEL_7;
            }
          }
          else
          {
            v89 = jiffies;
            if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_18 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Clear unsafe channel list",
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                "__wlan_hdd_cfg80211_avoid_freq_ext");
              _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_18 = v89;
            }
          }
          if ( v139[v80 + 2] < v139[v80 + 1] )
            goto LABEL_7;
          if ( v129 )
          {
            if ( v80 * 4 + 12 > 0x2A8 || (v139[v80 + 3] = *(_DWORD *)(v129 + 4), v80 > 166) )
            {
LABEL_86:
              __break(1u);
              goto LABEL_87;
            }
            LOBYTE(v139[v80 + 4]) = 1;
          }
          v88 = jiffies;
          if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_22 - jiffies + 125 < 0 )
          {
            if ( v80 * 4 + 12 > 0x2A8 )
              goto LABEL_86;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: ext avoid freq start: %u end: %u txpower %d mask %d",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "__wlan_hdd_cfg80211_avoid_freq_ext");
            _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_22 = v88;
          }
          ++v81;
          v80 += 4LL;
          v83 = (*v82 + 3) & 0x1FFFC;
          v79 -= v83;
          v82 = (unsigned __int16 *)((char *)v82 + v83);
        }
        while ( v79 > 3 );
        if ( v81 <= 0x29 )
          goto LABEL_64;
      }
LABEL_67:
      if ( v138 )
      {
        v91 = *(_DWORD *)(v138 + 4);
        adapter_by_ifindex = hdd_get_adapter_by_ifindex((__int64)(a1 + 192), v91);
        if ( !adapter_by_ifindex )
        {
          v120 = jiffies;
          if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_26 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: HDD adapter for ifindex: %d not found",
              v93,
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              "__wlan_hdd_cfg80211_avoid_freq_ext",
              v91);
            _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_26 = v120;
          }
          goto LABEL_7;
        }
        v101 = adapter_by_ifindex;
        v102 = *(unsigned __int8 *)(*(_QWORD *)(adapter_by_ifindex + 52824) + 8LL);
        if ( !policy_mgr_is_vdev_ll_lt_sap(*v38, v102) )
        {
          v121 = jiffies;
          if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_28 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: vdev: %d Current SAP is not LL SAP",
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              v110,
              "__wlan_hdd_cfg80211_avoid_freq_ext",
              v102);
            _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_28 = v121;
          }
          goto LABEL_7;
        }
        if ( (ucfg_mlme_is_chan_switch_in_progress(
                *(_QWORD *)(*(_QWORD *)(v101 + 52824) + 32LL),
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                v109,
                v110)
            & 1) != 0 )
        {
          v119 = jiffies;
          if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_30 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: vdev: %d CSA is currently in progress",
              v111,
              v112,
              v113,
              v114,
              v115,
              v116,
              v117,
              v118,
              "__wlan_hdd_cfg80211_avoid_freq_ext",
              v102);
            _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_30 = v119;
          }
          goto LABEL_7;
        }
        ucfg_dcs_trigger_dcs(a1[192], *(_BYTE *)(a1[193] + 40LL), v102, 2);
LABEL_25:
        v36 = 0;
        goto LABEL_26;
      }
    }
    else
    {
      v66 = jiffies;
      if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_8 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Clear extended avoid frequency list",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "__wlan_hdd_cfg80211_avoid_freq_ext");
        _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_8 = v66;
      }
    }
    ucfg_reg_ch_avoid_ext();
    goto LABEL_25;
  }
  v35 = jiffies;
  if ( _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_2 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Command not allowed in FTM/MONITOR mode",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "__wlan_hdd_cfg80211_avoid_freq_ext");
    _wlan_hdd_cfg80211_avoid_freq_ext___last_ticks_2 = v35;
  }
LABEL_7:
  v36 = -22;
LABEL_26:
  v67 = v36;
  _osif_psoc_sync_op_stop(v141, (__int64)"wlan_hdd_cfg80211_avoid_freq_ext");
  result = v67;
LABEL_27:
  if ( *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808) != v140 )
    JUMPOUT(0x55A824);
  return result;
}
