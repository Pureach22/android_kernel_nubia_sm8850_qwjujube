__int64 __fastcall wlan_cfg80211_set_interop_issues_ap_config(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19
  __int64 vdev_by_user; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 v29; // x19
  const char *v30; // x2
  int v31; // w24
  unsigned int v32; // w20
  unsigned __int16 *v33; // x26
  unsigned __int64 v34; // x28
  unsigned int v35; // w9
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  int v45; // w30
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  const char *v55; // x2
  __int64 v56; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v57; // [xsp+10h] [xbp-D0h] BYREF
  _QWORD v58[15]; // [xsp+18h] [xbp-C8h] BYREF
  _QWORD v59[2]; // [xsp+90h] [xbp-50h] BYREF
  _WORD *v60; // [xsp+A0h] [xbp-40h]
  __int64 v61; // [xsp+A8h] [xbp-38h]
  _QWORD v62[3]; // [xsp+B0h] [xbp-30h] BYREF
  __int64 v63; // [xsp+C8h] [xbp-18h]
  __int64 v64; // [xsp+D0h] [xbp-10h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 488);
  v56 = 0;
  result = _osif_psoc_sync_op_start(v7, &v56, (__int64)"wlan_cfg80211_set_interop_issues_ap_config");
  if ( (_DWORD)result )
    goto LABEL_14;
  v9 = *(_QWORD *)(a2 + 32);
  v60 = nullptr;
  v61 = 0;
  v59[0] = 0;
  v59[1] = 0;
  v57 = 0;
  memset(v58, 0, sizeof(v58));
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Command not allowed in FTM mode",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_cfg80211_set_interop_issues_ap_config");
    v18 = -1;
LABEL_13:
    _osif_psoc_sync_op_stop(v56, (__int64)"wlan_cfg80211_set_interop_issues_ap_config");
    result = v18;
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                   *(_QWORD *)(v9 + 55512),
                   0x33u,
                   (__int64)"__wlan_cfg80211_set_interop_issues_ap_config");
  if ( !vdev_by_user )
  {
    v30 = "%s: Invalid vdev";
    goto LABEL_12;
  }
  v28 = *(_QWORD *)(vdev_by_user + 152);
  if ( !v28 )
  {
    _hdd_objmgr_put_vdev_by_user(
      vdev_by_user,
      0x33u,
      (__int64)"__wlan_cfg80211_set_interop_issues_ap_config",
      nullptr,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27);
    goto LABEL_11;
  }
  v29 = *(_QWORD *)(v28 + 80);
  _hdd_objmgr_put_vdev_by_user(
    vdev_by_user,
    0x33u,
    (__int64)"__wlan_cfg80211_set_interop_issues_ap_config",
    (unsigned int *)v28,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27);
  if ( !v29 )
  {
LABEL_11:
    v30 = "%s: Invalid psoc";
    goto LABEL_12;
  }
  if ( (unsigned int)_nla_parse(v59, 3, a3, a4, &interop_issues_ap_policy, 31, 0) )
  {
    v30 = "%s: Invalid ATTR";
LABEL_12:
    qdf_trace_msg(
      0x48u,
      2u,
      v30,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "__wlan_cfg80211_set_interop_issues_ap_config");
    v18 = -22;
    goto LABEL_13;
  }
  if ( !v60 || (v31 = (unsigned __int16)(*v60 - 4), (unsigned int)v31 < 4) )
  {
    v32 = 0;
LABEL_29:
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Num of interop issues ap: %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "__wlan_cfg80211_set_interop_issues_ap_config",
      v32);
    HIDWORD(v57) = v32;
    LOBYTE(v57) = 1;
    ucfg_set_interop_issues_ap_config(v29, (__int64)&v57);
    v18 = 0;
    goto LABEL_13;
  }
  v32 = 0;
  v33 = v60 + 2;
  v34 = -120;
  v63 = 0;
  memset(v62, 0, sizeof(v62));
  while ( 1 )
  {
    v35 = *v33;
    if ( v35 < 4 || v31 < v35 )
      goto LABEL_29;
    if ( !v34 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Ignoring excess",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "wlan_parse_interop_issues_ap");
      v32 = 20;
      goto LABEL_29;
    }
    if ( (unsigned int)_nla_parse(v62, 3, v33 + 2, (unsigned __int16)(v35 - 4), &interop_issues_ap_policy, 31, 0) )
    {
      v55 = "%s: nla_parse failed";
LABEL_33:
      qdf_trace_msg(0x48u, 2u, v55, v36, v37, v38, v39, v40, v41, v42, v43, "wlan_parse_interop_issues_ap");
      v32 = -22;
      goto LABEL_29;
    }
    if ( !v63 )
    {
      v55 = "%s: attr addr failed";
      goto LABEL_33;
    }
    v44 = nla_memcpy((char *)v59 + v34, v63, 6);
    if ( v34 + 4 < 0xFFFFFFFFFFFFFF7FLL || v34 + 2 < 0xFFFFFFFFFFFFFF80LL || v34 <= 0xFFFFFFFFFFFFFF7ELL )
      break;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wlan_parse_interop_issues_ap",
      *((unsigned __int8 *)&v58[15] + v34),
      *((unsigned __int8 *)v59 + v34 + 1),
      *((unsigned __int8 *)v59 + v34 + 2),
      *((unsigned __int8 *)v59 + v34 + 5));
    ++v32;
    v34 += 6LL;
    v54 = (*v33 + 3) & 0x1FFFC;
    v31 -= v54;
    v33 = (unsigned __int16 *)((char *)v33 + v54);
    if ( v31 <= 3 )
      goto LABEL_29;
  }
  __break(1u);
  if ( !v45 )
    JUMPOUT(0x4A27A4);
  return wlan_cfg80211_init_interop_issues_ap(v44);
}
