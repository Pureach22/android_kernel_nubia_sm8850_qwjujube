__int64 __fastcall wlan_hdd_cfg80211_config_tspec(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x20
  int v37; // w4
  unsigned int v38; // w19
  int v39; // w4
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x20
  __int64 v50; // x20
  unsigned int v51; // w19
  unsigned int v52; // w0
  __int64 v53; // x20
  unsigned int v54; // w0
  __int64 v55; // x20
  __int64 v56; // x20
  __int64 v57; // x21
  __int64 v58; // x20
  __int64 v59; // x20
  __int64 v60; // x20
  __int64 v61; // x20
  __int64 v62; // x20
  __int64 v63; // x20
  __int64 v64; // x20
  __int64 v65; // x20
  __int64 v66; // x20
  __int64 v67; // x20
  __int64 v68; // x20
  int v69; // w8
  __int64 v70; // [xsp+0h] [xbp-100h] BYREF
  unsigned int v71; // [xsp+Ch] [xbp-F4h] BYREF
  __int64 v72; // [xsp+10h] [xbp-F0h] BYREF
  __int64 v73; // [xsp+18h] [xbp-E8h]
  __int64 v74; // [xsp+20h] [xbp-E0h]
  __int64 v75; // [xsp+28h] [xbp-D8h]
  __int64 v76; // [xsp+30h] [xbp-D0h]
  __int64 v77; // [xsp+38h] [xbp-C8h]
  __int64 v78; // [xsp+40h] [xbp-C0h]
  __int64 v79; // [xsp+48h] [xbp-B8h]
  __int64 v80; // [xsp+50h] [xbp-B0h]
  int v81; // [xsp+58h] [xbp-A8h]
  __int64 v82; // [xsp+60h] [xbp-A0h] BYREF
  __int64 v83; // [xsp+68h] [xbp-98h]
  __int64 v84; // [xsp+70h] [xbp-90h]
  __int64 v85; // [xsp+78h] [xbp-88h]
  __int64 v86; // [xsp+80h] [xbp-80h]
  __int64 v87; // [xsp+88h] [xbp-78h]
  __int64 v88; // [xsp+90h] [xbp-70h]
  __int64 v89; // [xsp+98h] [xbp-68h]
  __int64 v90; // [xsp+A0h] [xbp-60h]
  __int64 v91; // [xsp+A8h] [xbp-58h]
  __int64 v92; // [xsp+B0h] [xbp-50h]
  __int64 v93; // [xsp+B8h] [xbp-48h]
  __int64 v94; // [xsp+C0h] [xbp-40h]
  __int64 v95; // [xsp+C8h] [xbp-38h]
  __int64 v96; // [xsp+D0h] [xbp-30h]
  __int64 v97; // [xsp+D8h] [xbp-28h]
  __int64 v98; // [xsp+E0h] [xbp-20h]
  __int64 v99; // [xsp+E8h] [xbp-18h]
  __int64 v100; // [xsp+F0h] [xbp-10h]
  __int64 v101; // [xsp+F8h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v70 = 0;
  result = _osif_vdev_sync_op_start(v8, &v70, "wlan_hdd_cfg80211_config_tspec");
  if ( (_DWORD)result )
    goto LABEL_52;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    v81 = 0;
    v79 = 0;
    v80 = 0;
    v77 = 0;
    v78 = 0;
    v75 = 0;
    v76 = 0;
    v73 = 0;
    v74 = 0;
    v72 = 0;
    v99 = 0;
    v100 = 0;
    v97 = 0;
    v98 = 0;
    v95 = 0;
    v96 = 0;
    v93 = 0;
    v94 = 0;
    v91 = 0;
    v92 = 0;
    v89 = 0;
    v90 = 0;
    v87 = 0;
    v88 = 0;
    v85 = 0;
    v86 = 0;
    v83 = 0;
    v84 = 0;
    v82 = 0;
    v71 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_config_tspec",
      v18 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__wlan_hdd_cfg80211_config_tspec");
      v27 = -1;
LABEL_51:
      v51 = v27;
      _osif_vdev_sync_op_stop(v70, "wlan_hdd_cfg80211_config_tspec");
      result = v51;
LABEL_52:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v27 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_config_tspec",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    if ( v27 )
      goto LABEL_51;
    if ( (unsigned int)_nla_parse(&v82, 18, a3, a4, &config_tspec_policy, 31, 0) )
    {
      v36 = jiffies;
      if ( _wlan_hdd_cfg80211_config_tspec___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid ATTR",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__wlan_hdd_cfg80211_config_tspec");
        _wlan_hdd_cfg80211_config_tspec___last_ticks = v36;
        v27 = -22;
        goto LABEL_51;
      }
LABEL_50:
      v27 = -22;
      goto LABEL_51;
    }
    if ( !v83 || !v84 )
    {
      v50 = jiffies;
      if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_117 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Mandatory attributes are not present",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__wlan_hdd_cfg80211_config_tspec");
        _wlan_hdd_cfg80211_config_tspec___last_ticks_117 = v50;
        v27 = -22;
        goto LABEL_51;
      }
      goto LABEL_50;
    }
    v81 = 0;
    v79 = 0;
    v80 = 0;
    v77 = 0;
    v78 = 0;
    v75 = 0;
    v76 = 0;
    v73 = 0;
    v74 = 0;
    v72 = 0;
    v37 = *(unsigned __int8 *)(v83 + 4);
    v38 = *(unsigned __int8 *)(v84 + 4);
    if ( v37 == 2 )
    {
      v54 = hdd_wmm_checkts(v18 + 2688, v38, v28, v29, v30, v31, v32, v33, v34, v35);
      if ( (v54 & 0xFFFFFFFE) == 0x12 )
      {
        v55 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_147 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: hdd_wmm_checkts failed %d",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "__wlan_hdd_cfg80211_config_tspec",
            v54);
          _wlan_hdd_cfg80211_config_tspec___last_ticks_147 = v55;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
    }
    else if ( v37 == 1 )
    {
      hdd_get_handle_from_ts_id(v18 + 2688, *(unsigned __int8 *)(v84 + 4), &v71);
      if ( v71 )
      {
        v52 = hdd_wmm_delts(v18 + 2688, v71, v41, v42, v43, v44, v45, v46, v47, v48);
        if ( v52 - 15 <= 1 )
        {
          v53 = jiffies;
          if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_145 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: hdd_wmm_delts failed %d",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "__wlan_hdd_cfg80211_config_tspec",
              v52);
            _wlan_hdd_cfg80211_config_tspec___last_ticks_145 = v53;
            v27 = -22;
            goto LABEL_51;
          }
          goto LABEL_50;
        }
      }
      else
      {
        v57 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_143 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: ts_id is already freed %d",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "__wlan_hdd_cfg80211_config_tspec",
            v38);
          _wlan_hdd_cfg80211_config_tspec___last_ticks_143 = v57;
        }
      }
    }
    else
    {
      if ( *(_BYTE *)(v83 + 4) )
      {
        v56 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_149 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid operation %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_149 = v56;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      BYTE4(v74) = *(_BYTE *)(v84 + 4);
      if ( !v85 )
      {
        v58 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_121 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Direction is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_121 = v58;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      v39 = *(unsigned __int8 *)(v85 + 4);
      if ( *(_BYTE *)(v85 + 4) )
      {
        if ( v39 != 1 && v39 != 3 )
        {
          v60 = jiffies;
          if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_119 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Invalid direction %d",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "__wlan_hdd_cfg80211_config_tspec");
            _wlan_hdd_cfg80211_config_tspec___last_ticks_119 = v60;
            v27 = -22;
            goto LABEL_51;
          }
          goto LABEL_50;
        }
        LODWORD(v74) = *(unsigned __int8 *)(v85 + 4);
      }
      if ( v86 )
        BYTE4(v73) = 1;
      if ( !v88 )
      {
        v59 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_125 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: ACK policy is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_125 = v59;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      if ( *(_BYTE *)(v88 + 4) && *(_BYTE *)(v88 + 4) != 3 )
      {
        v61 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_123 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid ack policy %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_123 = v61;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      HIDWORD(v72) = *(unsigned __int8 *)(v88 + 4);
      if ( !v89 )
      {
        v62 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_127 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Nominal msdu size is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_127 = v62;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      LOWORD(v75) = *(_WORD *)(v89 + 4);
      if ( !v90 )
      {
        v63 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_129 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Maximum msdu size is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_129 = v63;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      WORD1(v75) = *(_WORD *)(v90 + 4);
      if ( !v91 )
      {
        v64 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_131 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Min service interval is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_131 = v64;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      HIDWORD(v75) = *(_DWORD *)(v91 + 4);
      if ( !v92 )
      {
        v65 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_133 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Max service interval is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_133 = v65;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      LODWORD(v76) = *(_DWORD *)(v92 + 4);
      if ( !v93 )
      {
        v66 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_135 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Inactivity interval is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_135 = v66;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      HIDWORD(v76) = *(_DWORD *)(v93 + 4);
      if ( !v94 )
      {
        v67 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_137 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Suspension interval is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_137 = v67;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      LODWORD(v77) = *(_DWORD *)(v94 + 4);
      if ( !v100 )
      {
        v68 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_139 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Surplus bw allowance is not present",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_config_tspec");
          _wlan_hdd_cfg80211_config_tspec___last_ticks_139 = v68;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      LOWORD(v81) = *(_WORD *)(v100 + 4);
      if ( v87 )
        LODWORD(v73) = *(unsigned __int8 *)(v87 + 4);
      if ( v95 )
        LODWORD(v78) = *(_DWORD *)(v95 + 4);
      if ( v96 )
        HIDWORD(v78) = *(_DWORD *)(v96 + 4);
      if ( v97 )
        LODWORD(v79) = *(_DWORD *)(v97 + 4);
      if ( v98 )
      {
        HIDWORD(v79) = *(_DWORD *)(v98 + 4);
        if ( HIDWORD(v79) )
          LOBYTE(v72) = 1;
      }
      if ( v99 )
        HIDWORD(v80) = *(_DWORD *)(v99 + 4);
      v40 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))hdd_wmm_addts)(
              v18 + 2688,
              (unsigned int)_wlan_hdd_cfg80211_config_tspec_add_tspec_handle,
              &v72);
      if ( (v40 & 0x1E) == 4 || v40 <= 0x13 && ((1 << v40) & 0x81840) != 0 )
      {
        v49 = jiffies;
        if ( _wlan_hdd_cfg80211_config_tspec___last_ticks_141 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: hdd_wmm_addts failed %d",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "__wlan_hdd_cfg80211_config_tspec",
            v40);
          _wlan_hdd_cfg80211_config_tspec___last_ticks_141 = v49;
          v27 = -22;
          goto LABEL_51;
        }
        goto LABEL_50;
      }
      if ( (unsigned int)(_wlan_hdd_cfg80211_config_tspec_add_tspec_handle + 1) >> 4 <= 0x176 )
        v69 = _wlan_hdd_cfg80211_config_tspec_add_tspec_handle + 1;
      else
        v69 = 5000;
      _wlan_hdd_cfg80211_config_tspec_add_tspec_handle = v69;
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v41, v42, v43, v44, v45, v46, v47, v48, "__wlan_hdd_cfg80211_config_tspec");
    v27 = 0;
    goto LABEL_51;
  }
  __break(0x800u);
  return hdd_wmm_notify_app();
}
