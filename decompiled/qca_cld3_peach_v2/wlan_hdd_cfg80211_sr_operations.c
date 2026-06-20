__int64 __fastcall wlan_hdd_cfg80211_sr_operations(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x25
  __int64 *v24; // x21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  __int64 vdev_by_user; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x19
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const char *v61; // x2
  unsigned int *v62; // x8
  unsigned int v63; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v72; // w24
  unsigned int *v73; // x8
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int v82; // w1
  int v83; // w22
  int v84; // w23
  char v85; // w0
  int v86; // w0
  const char *v87; // x2
  unsigned int v88; // w1
  __int64 v89; // x0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w22
  unsigned int v99; // w21
  char v100; // w22
  __int64 cmpt_obj; // x0
  char v102; // w8
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  __int64 v120; // x20
  unsigned int v121; // w21
  __int64 v122; // x0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  char v131; // w8
  __int64 v132; // x0
  char v133; // w8
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x0
  unsigned int v137; // w22
  __int64 v138; // x0
  __int64 v139; // [xsp+0h] [xbp-110h] BYREF
  _BYTE v140[4]; // [xsp+Ch] [xbp-104h] BYREF
  _BYTE v141[4]; // [xsp+10h] [xbp-100h] BYREF
  _BYTE v142[4]; // [xsp+14h] [xbp-FCh] BYREF
  _BYTE v143[4]; // [xsp+18h] [xbp-F8h] BYREF
  unsigned __int8 v144[4]; // [xsp+1Ch] [xbp-F4h] BYREF
  _QWORD v145[16]; // [xsp+20h] [xbp-F0h] BYREF
  __int64 v146; // [xsp+A0h] [xbp-70h] BYREF
  __int64 v147; // [xsp+A8h] [xbp-68h]
  __int64 v148; // [xsp+B0h] [xbp-60h]
  __int64 v149; // [xsp+B8h] [xbp-58h]
  __int64 v150; // [xsp+C0h] [xbp-50h]
  __int64 v151; // [xsp+C8h] [xbp-48h]
  __int64 v152; // [xsp+D0h] [xbp-40h]
  __int64 v153; // [xsp+D8h] [xbp-38h]
  __int64 v154; // [xsp+E0h] [xbp-30h]
  __int64 v155; // [xsp+E8h] [xbp-28h] BYREF
  __int64 v156; // [xsp+F0h] [xbp-20h]
  __int64 v157; // [xsp+F8h] [xbp-18h]
  __int64 v158; // [xsp+100h] [xbp-10h]
  __int64 v159; // [xsp+108h] [xbp-8h]

  v159 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 488);
  v139 = 0;
  result = _osif_psoc_sync_op_start(v8, &v139, (__int64)"wlan_hdd_cfg80211_sr_operations");
  if ( (_DWORD)result )
    goto LABEL_8;
  v144[0] = 0;
  v143[0] = 0;
  v142[0] = 0;
  v141[0] = 0;
  if ( a1 )
  {
    v23 = *(_QWORD *)(a2 + 32);
    v157 = 0;
    v158 = 0;
    v24 = (__int64 *)(a1 + 1536);
    v155 = 0;
    v156 = 0;
    v153 = 0;
    v154 = 0;
    v151 = 0;
    v152 = 0;
    v149 = 0;
    v150 = 0;
    v147 = 0;
    v148 = 0;
    v146 = 0;
    memset(v145, 0, sizeof(v145));
    v140[0] = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "__wlan_hdd_cfg80211_sr_operations",
      v23 + 296);
    v33 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_sr_operations",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32);
    if ( v33 )
    {
LABEL_7:
      v42 = v33;
      _osif_psoc_sync_op_stop(v139, (__int64)"wlan_hdd_cfg80211_sr_operations");
      result = v42;
LABEL_8:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( (unsigned int)hdd_get_conparam() == 5 || (unsigned int)hdd_get_conparam() == 4 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM or Monitor mode",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "__wlan_hdd_cfg80211_sr_operations");
      v33 = -1;
      goto LABEL_7;
    }
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                     *(_QWORD *)(v23 + 55520),
                     5u,
                     (__int64)"__wlan_hdd_cfg80211_sr_operations");
    if ( !vdev_by_user )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Null VDEV",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "__wlan_hdd_cfg80211_sr_operations");
      v33 = -22;
      goto LABEL_7;
    }
    v52 = vdev_by_user;
    wlan_mlme_get_sr_enable_modes(*v24, v140);
    if ( ((v140[0] >> *(_DWORD *)(v23 + 2728)) & 1) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: SR operation not allowed for mode %d",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "__wlan_hdd_cfg80211_sr_operations");
LABEL_21:
      v83 = -22;
LABEL_22:
      _hdd_objmgr_put_vdev_by_user(
        v52,
        5u,
        (__int64)"__wlan_hdd_cfg80211_sr_operations",
        v62,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60);
      v33 = v83;
      goto LABEL_7;
    }
    if ( *(_DWORD *)(a1 + 3000) == 2 )
    {
      v61 = "%s: Driver Modules are closed";
LABEL_19:
      v82 = 2;
LABEL_20:
      qdf_trace_msg(0x33u, v82, v61, v53, v54, v55, v56, v57, v58, v59, v60, "__wlan_hdd_cfg80211_sr_operations");
      goto LABEL_21;
    }
    if ( (sme_is_feature_supported_by_fw(13) & 1) == 0 )
    {
      v61 = "%s: 11AX is not supported";
      goto LABEL_19;
    }
    v63 = ucfg_spatial_reuse_operation_allowed(*v24, v52);
    if ( v63 )
    {
      v72 = v63;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: SR operations not allowed status: %u",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "__wlan_hdd_cfg80211_sr_operations",
        v63);
      _hdd_objmgr_put_vdev_by_user(
        v52,
        5u,
        (__int64)"__wlan_hdd_cfg80211_sr_operations",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81);
      v33 = qdf_status_to_os_return(v72);
      goto LABEL_7;
    }
    if ( (unsigned int)_nla_parse(&v155, 3, a3, a4, &wlan_hdd_sr_policy, 31, 0) )
    {
      v61 = "%s: invalid attr";
      goto LABEL_19;
    }
    if ( !v156 )
    {
      v61 = "%s: SR operation not specified";
      goto LABEL_19;
    }
    v84 = *(unsigned __int8 *)(v156 + 4);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: SR Operation 0x%x",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "__wlan_hdd_cfg80211_sr_operations",
      *(unsigned __int8 *)(v156 + 4));
    ucfg_spatial_reuse_get_sr_config(v52, v142, v141, v144);
    v85 = hdd_check_mode_support_for_sr(v23 + 2688, v142[0]);
    if ( v84 != 8 && (v85 & 1) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: SR operation not allowed, sr_ctrl = %x, mode = %d",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "__wlan_hdd_cfg80211_sr_operations",
        v142[0],
        *(unsigned int *)(v23 + 2728));
      goto LABEL_21;
    }
    if ( v84 && (v144[0] & 1) == 0 )
    {
      v61 = "%s: SR operation not allowed";
      goto LABEL_19;
    }
    if ( v157 )
    {
      v86 = wlan_cfg80211_nla_parse_nested_1(&v146);
      if ( v86 )
      {
        v83 = v86;
        v87 = "%s: sr_param_attr parse failed";
        v88 = 2;
LABEL_98:
        qdf_trace_msg(0x33u, v88, v87, v53, v54, v55, v56, v57, v58, v59, v60, "__wlan_hdd_cfg80211_sr_operations");
        goto LABEL_22;
      }
    }
    if ( v84 <= 5 )
    {
      if ( (unsigned int)v84 < 2 )
      {
        v100 = v142[0];
        if ( v84 )
        {
          v144[0] = 0;
          cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v52, v53, v54, v55, v56, v57, v58, v59, v60);
          if ( !cmpt_obj || *(_BYTE *)(cmpt_obj + 202) != 1 )
          {
            v61 = "%s: SR not enabled, reject disable command";
            goto LABEL_64;
          }
          v102 = v144[0];
        }
        else
        {
          v102 = 1;
          v144[0] = 1;
        }
        v121 = 0;
        if ( (v102 & 1) != 0 && v152 )
        {
          if ( (v100 & 8) == 0 )
          {
            v61 = "%s: SRG OBSS PD threshold set is disallowed\n";
            goto LABEL_19;
          }
          v121 = *(_DWORD *)(v152 + 4);
          v136 = wlan_vdev_mlme_get_cmpt_obj(v52, v53, v54, v55, v56, v57, v58, v59, v60);
          if ( v136 )
            *(_BYTE *)(v136 + 232) = 1;
        }
        if ( v144[0] == 1 && v153 )
        {
          if ( (v100 & 2) != 0 )
          {
            v61 = "%s: non-SRG OBSS PD threshold set is disallowed\n";
            goto LABEL_19;
          }
          v137 = *(_DWORD *)(v153 + 4);
          v138 = wlan_vdev_mlme_get_cmpt_obj(v52, v53, v54, v55, v56, v57, v58, v59, v60);
          if ( v138 )
            *(_BYTE *)(v138 + 232) = 1;
        }
        else
        {
          if ( (v100 & 0xA) == 2 )
          {
            v61 = "%s: Failed to enable SR\n";
            goto LABEL_19;
          }
          v137 = 0;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: setting sr enable %d with pd threshold srg: %d non srg: %d",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "__wlan_hdd_cfg80211_sr_operations",
          v144[0],
          v121,
          v137);
        ucfg_spatial_reuse_set_sr_enable(v52, v144[0]);
        if ( (unsigned int)ucfg_spatial_reuse_setup_req(v52, *(_QWORD *)(a1 + 1544), v144[0], v121, v137) )
        {
          v61 = "%s: failed to enable Spatial Reuse feature";
          goto LABEL_19;
        }
        goto LABEL_96;
      }
      if ( v84 == 4 )
      {
        if ( v147 && !*(_BYTE *)(v147 + 4) )
        {
          v61 = "%s: invalid sr_he_siga_val15_enable param";
          goto LABEL_19;
        }
        if ( !(unsigned int)ucfg_spatial_reuse_send_sr_prohibit(v52, 1) )
          goto LABEL_96;
LABEL_60:
        v61 = "%s: Prohibit command can not be sent";
LABEL_64:
        v82 = 8;
        goto LABEL_20;
      }
      if ( v84 == 5 )
      {
        if ( !(unsigned int)ucfg_spatial_reuse_send_sr_prohibit(v52, 0) )
        {
LABEL_96:
          v83 = 0;
          goto LABEL_97;
        }
        goto LABEL_60;
      }
      goto LABEL_56;
    }
    switch ( v84 )
    {
      case 6:
        if ( !(unsigned int)policy_mgr_get_mac_id_by_session_id(*v24, *(_BYTE *)(*(_QWORD *)(v23 + 55520) + 8LL), v143) )
        {
          if ( (unsigned int)hdd_get_sr_stats(a1 + 1536, v143[0], v145) )
            goto LABEL_21;
          v111 = _cfg80211_alloc_reply_skb(*(_QWORD *)(a1 + 1560), 103, 197, 64);
          if ( v111 )
          {
            v120 = v111;
            if ( (unsigned int)hdd_add_stats_info(v111, v145) )
            {
LABEL_79:
              sk_skb_reason_drop(0, v120, 2);
              goto LABEL_21;
            }
LABEL_55:
            v83 = cfg80211_vendor_cmd_reply(v120);
LABEL_97:
            v87 = "%s: exit";
            v88 = 8;
            goto LABEL_98;
          }
LABEL_80:
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            v119,
            "__wlan_hdd_cfg80211_sr_operations");
          v83 = -12;
          goto LABEL_22;
        }
        break;
      case 7:
        if ( !(unsigned int)policy_mgr_get_mac_id_by_session_id(*v24, *(_BYTE *)(*(_QWORD *)(v23 + 55520) + 8LL), v143) )
        {
          if ( (unsigned int)hdd_clear_sr_stats(a1 + 1536, v143[0]) )
          {
            v83 = -11;
            goto LABEL_22;
          }
          goto LABEL_96;
        }
        break;
      case 8:
        v89 = wlan_vdev_mlme_get_cmpt_obj(v52, v53, v54, v55, v56, v57, v58, v59, v60);
        if ( v89 )
        {
          v98 = *(unsigned __int8 *)(v89 + 200);
          v99 = *(unsigned __int8 *)(v89 + 201);
        }
        else
        {
          v99 = 0;
          v98 = 0;
        }
        v122 = wlan_vdev_mlme_get_cmpt_obj(v52, v90, v91, v92, v93, v94, v95, v96, v97);
        if ( v122 )
          v131 = *(_BYTE *)(v122 + 199);
        else
          v131 = 0;
        v141[0] = v131;
        v132 = wlan_vdev_mlme_get_cmpt_obj(v52, v123, v124, v125, v126, v127, v128, v129, v130);
        if ( v132 )
          v133 = *(_BYTE *)(v132 + 198);
        else
          v133 = 0;
        v134 = *(_QWORD *)(a1 + 1560);
        v142[0] = v133;
        v135 = _cfg80211_alloc_reply_skb(v134, 103, 197, 56);
        if ( v135 )
        {
          v120 = v135;
          if ( (unsigned int)hdd_add_param_info(v135, v98, v99, v141[0], v142[0]) )
            goto LABEL_79;
          goto LABEL_55;
        }
        goto LABEL_80;
      default:
LABEL_56:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid SR Operation",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "__wlan_hdd_cfg80211_sr_operations");
        v83 = -22;
        goto LABEL_97;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get mac_id for vdev_id: %u",
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      "__wlan_hdd_cfg80211_sr_operations",
      *(unsigned __int8 *)(*(_QWORD *)(v23 + 55520) + 8LL));
    v83 = -11;
    goto LABEL_22;
  }
  __break(0x800u);
  return hdd_sr_pack_suspend_resume_event(result, v10, v11, v12, v13, v14);
}
