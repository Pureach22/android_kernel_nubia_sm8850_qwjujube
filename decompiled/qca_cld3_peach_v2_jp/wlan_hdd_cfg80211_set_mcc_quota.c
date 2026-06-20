__int64 __fastcall wlan_hdd_cfg80211_set_mcc_quota(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  const char *v33; // x3
  unsigned int v34; // w1
  __int64 result; // x0
  unsigned int v36; // w21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x20
  int v46; // w28
  unsigned int v47; // w21
  __int64 v48; // x22
  unsigned __int16 *v49; // x23
  const char *v50; // x2
  const char *v51; // x3
  __int64 v52; // x4
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  unsigned int v62; // w9
  unsigned int v63; // w0
  unsigned int v64; // w27
  __int64 adapter_by_ifindex; // x0
  int v66; // w10
  char v67; // w9
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int user_mcc_duty_cycle_percentage; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w20
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // [xsp+8h] [xbp-88h] BYREF
  _BYTE v95[4]; // [xsp+14h] [xbp-7Ch] BYREF
  __int64 v96; // [xsp+18h] [xbp-78h] BYREF
  __int64 v97; // [xsp+20h] [xbp-70h]
  _WORD *v98; // [xsp+28h] [xbp-68h]
  __int64 v99; // [xsp+30h] [xbp-60h]
  __int64 v100; // [xsp+38h] [xbp-58h]
  __int64 v101; // [xsp+40h] [xbp-50h]
  __int64 v102; // [xsp+48h] [xbp-48h]
  _QWORD v103[4]; // [xsp+50h] [xbp-40h] BYREF
  __int64 v104; // [xsp+70h] [xbp-20h]
  __int64 v105; // [xsp+78h] [xbp-18h]
  __int64 v106; // [xsp+80h] [xbp-10h]
  __int64 v107; // [xsp+88h] [xbp-8h]

  v107 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    __break(0x800u);
    return ((__int64 (*)(void))wlan_hdd_set_mcc_low_latency_quota)();
  }
  v15 = (__int64 *)(a1 + 1536);
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = nullptr;
  v96 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_cfg80211_set_mcc_quota");
  if ( (unsigned int)_wlan_hdd_validate_context(
                       (__int64)v15,
                       (__int64)"wlan_hdd_cfg80211_set_mcc_quota",
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23)
    || !*v15 )
  {
    goto LABEL_9;
  }
  if ( (unsigned int)_nla_parse(&v96, 6, a3, a4, &set_mcc_quota_policy, 31, 0) )
  {
    v32 = "%s: Error parsing attributes";
LABEL_6:
    v33 = "wlan_hdd_cfg80211_set_mcc_quota";
LABEL_7:
    v34 = 2;
    goto LABEL_8;
  }
  if ( !v97 )
  {
    v32 = "%s: Quota type not specified";
    goto LABEL_6;
  }
  v36 = *(_DWORD *)(v97 + 4);
  if ( v36 > 1 )
  {
    if ( v36 == 3 )
    {
      result = wlan_hdd_set_mcc_low_latency_quota(v15, a2, &v96);
      goto LABEL_10;
    }
    v50 = "%s: Quota type is not valid %u";
    v51 = "wlan_hdd_cfg80211_set_mcc_quota";
    v52 = v36;
LABEL_23:
    qdf_trace_msg(0x33u, 2u, v50, v24, v25, v26, v27, v28, v29, v30, v31, v51, v52);
    goto LABEL_9;
  }
  v105 = 0;
  v106 = 0;
  v104 = 0;
  memset(v103, 0, sizeof(v103));
  v94 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v24, v25, v26, v27, v28, v29, v30, v31, "wlan_hdd_set_mcc_fixed_quota");
  if ( (unsigned int)_wlan_hdd_validate_context(
                       (__int64)v15,
                       (__int64)"wlan_hdd_set_mcc_fixed_quota",
                       v37,
                       v38,
                       v39,
                       v40,
                       v41,
                       v42,
                       v43,
                       v44) )
    goto LABEL_9;
  v45 = *v15;
  if ( !*v15 )
    goto LABEL_9;
  if ( !v36 )
  {
    v95[0] = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enable : %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_hdd_set_mcc_adaptive_sched",
      1);
    ucfg_policy_mgr_get_mcc_adaptive_sch(v45, v95);
    if ( v95[0] == 1 && (ucfg_policy_mgr_set_dynamic_mcc_adaptive_sch(v45, 1), (unsigned int)sme_set_mas(1)) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Fail to config mcc adaptive sched.",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "wlan_hdd_set_mcc_adaptive_sched");
      result = 4294967285LL;
    }
    else
    {
      LODWORD(v94) = 17;
      BYTE5(v94) = -1;
      wlan_mlme_set_user_mcc_quota(v45, (unsigned int *)&v94);
      result = 0;
    }
    goto LABEL_10;
  }
  if ( !v98 )
  {
    v32 = "%s: No entries present";
    goto LABEL_46;
  }
  v46 = (unsigned __int16)(*v98 - 4);
  if ( (unsigned int)v46 < 4 )
  {
LABEL_45:
    v32 = "%s: No entries found";
    goto LABEL_46;
  }
  v47 = 0;
  v48 = 0;
  v49 = v98 + 2;
  while ( 1 )
  {
    v62 = *v49;
    if ( v62 < 4 || v46 < v62 )
    {
LABEL_42:
      if ( !v47 )
        goto LABEL_45;
      if ( (unsigned int)(v94 - 4) > 0xFFFFFFFD )
      {
        wlan_mlme_set_user_mcc_quota(v45, (unsigned int *)&v94);
        user_mcc_duty_cycle_percentage = wlan_mlme_get_user_mcc_duty_cycle_percentage(v45);
        if ( user_mcc_duty_cycle_percentage )
        {
          v85 = user_mcc_duty_cycle_percentage;
          if ( (unsigned int)wlan_hdd_set_mcc_adaptive_sched(*v15, 0, v77, v78, v79, v80, v81, v82, v83, v84) )
          {
            result = 4294967285LL;
          }
          else if ( (unsigned int)wlan_hdd_send_mcc_vdev_quota(v48, v85, v86, v87, v88, v89, v90, v91, v92, v93) )
          {
            result = 4294967274LL;
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Quota will be configured when MCC scenario exists",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "wlan_hdd_set_mcc_fixed_quota");
          result = 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Support only P2P GO/GC mode now",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_hdd_set_mcc_fixed_quota");
        result = 4294967201LL;
      }
      goto LABEL_10;
    }
    if ( v47 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Only one entry permitted",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wlan_hdd_set_mcc_fixed_quota");
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Entry (%d) for (%u) is ignored",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "wlan_hdd_set_mcc_fixed_quota",
        v47,
        v49[1] & 0x3FFF);
      goto LABEL_25;
    }
    if ( ((__int16)v49[1] & 0x80000000) == 0 )
    {
      do_trace_netlink_extack("NLA_F_NESTED is missing");
      v52 = 4294967274LL;
LABEL_52:
      v50 = "%s: Entry parse error %d";
      v51 = "wlan_hdd_set_mcc_fixed_quota";
      goto LABEL_23;
    }
    v63 = _nla_parse(v103, 6, v49 + 2, (unsigned __int16)(v62 - 4), &set_mcc_quota_policy, 31, 0);
    if ( v63 )
    {
      v52 = v63;
      goto LABEL_52;
    }
    if ( !v105 )
    {
      v32 = "%s: if_index not specified";
      goto LABEL_46;
    }
    v64 = *(_DWORD *)(v105 + 4);
    if ( !v64 )
      break;
    adapter_by_ifindex = hdd_get_adapter_by_ifindex((__int64)v15, v64);
    if ( !adapter_by_ifindex )
    {
      v50 = "%s: interface (%u) not found";
      v51 = "wlan_hdd_set_mcc_fixed_quota";
      v52 = v64;
      goto LABEL_23;
    }
    v48 = adapter_by_ifindex;
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(_BYTE *)(*(_QWORD *)(adapter_by_ifindex + 52824) + 8LL),
                         (__int64)"wlan_hdd_set_mcc_fixed_quota",
                         v24,
                         v25,
                         v26,
                         v27,
                         v28,
                         v29,
                         v30,
                         v31) )
      goto LABEL_9;
    if ( !v104 )
    {
      v32 = "%s: Quota not specified";
LABEL_46:
      v33 = "wlan_hdd_set_mcc_fixed_quota";
      goto LABEL_7;
    }
    v66 = *(_DWORD *)(v48 + 40);
    v67 = *(_BYTE *)(*(_QWORD *)(v48 + 52824) + 8LL);
    BYTE4(v94) = *(_DWORD *)(v104 + 4);
    LODWORD(v94) = v66;
    BYTE5(v94) = v67;
LABEL_25:
    ++v47;
    v61 = (*v49 + 3) & 0x1FFFC;
    v46 -= v61;
    v49 = (unsigned __int16 *)((char *)v49 + v61);
    if ( v46 <= 3 )
      goto LABEL_42;
  }
  v32 = "%s: Invalid if_index";
  v33 = "wlan_hdd_set_mcc_fixed_quota";
  v34 = 8;
LABEL_8:
  qdf_trace_msg(0x33u, v34, v32, v24, v25, v26, v27, v28, v29, v30, v31, v33);
LABEL_9:
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
