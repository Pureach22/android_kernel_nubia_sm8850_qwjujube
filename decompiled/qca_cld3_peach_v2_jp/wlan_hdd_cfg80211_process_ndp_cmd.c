__int64 __fastcall wlan_hdd_cfg80211_process_ndp_cmd(
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
  unsigned __int16 *v12; // x30
  __int64 *v13; // x24
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  __int64 v28; // x22
  unsigned __int64 StatusReg; // x8
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x1
  __int64 v40; // x20
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  __int64 v60; // x25
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int *v69; // x8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x8
  int v79; // w8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x3
  unsigned __int64 v89; // [xsp+0h] [xbp-20h]
  __int64 v90; // [xsp+8h] [xbp-18h] BYREF
  __int64 v91[2]; // [xsp+10h] [xbp-10h] BYREF

  v91[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    __break(0x800u);
    __ldxr(v12);
    return hdd_init_nan_data_mode();
  }
  v13 = (__int64 *)(a1 + 1536);
  result = _wlan_hdd_validate_context(
             a1 + 1536,
             (__int64)"__wlan_hdd_cfg80211_process_ndp_cmd",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12);
  if ( (_DWORD)result )
    goto LABEL_59;
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    v27 = jiffies;
    if ( _wlan_hdd_cfg80211_process_ndp_cmd___last_ticks - jiffies + 125 < 0 )
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
        "__wlan_hdd_cfg80211_process_ndp_cmd");
      _wlan_hdd_cfg80211_process_ndp_cmd___last_ticks = v27;
      result = 0xFFFFFFFFLL;
      goto LABEL_59;
    }
    goto LABEL_14;
  }
  if ( (*(_BYTE *)(a1 + 2998) & 1) == 0 )
  {
    v40 = jiffies;
    if ( _wlan_hdd_cfg80211_process_ndp_cmd___last_ticks_44 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: NAN datapath is not enabled",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__wlan_hdd_cfg80211_process_ndp_cmd");
      _wlan_hdd_cfg80211_process_ndp_cmd___last_ticks_44 = v40;
      result = 0xFFFFFFFFLL;
      goto LABEL_59;
    }
LABEL_14:
    result = 0xFFFFFFFFLL;
    goto LABEL_59;
  }
  v28 = *(_QWORD *)(a1 + 1536);
  v90 = 0;
  v91[0] = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1568);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1568);
    *(_QWORD *)(a1 + 1576) |= 1uLL;
  }
  hdd_get_front_adapter_no_lock((__int64)v13, v91);
  if ( v91[0] )
  {
    hdd_adapter_dev_hold_debug(v91[0], 0x2Eu, v30, v31, v32, v33, v34, v35, v36, v37, v38);
    v39 = v91[0];
  }
  else
  {
    v39 = 0;
  }
  hdd_get_next_adapter_no_lock((__int64)v13, v39, &v90);
  if ( v90 )
    hdd_adapter_dev_hold_debug(v90, 0x2Eu, v41, v42, v43, v44, v45, v46, v47, v48, v49);
  v50 = *(_QWORD *)(a1 + 1576);
  if ( (v50 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 1568);
    v59 = v91[0];
    if ( v91[0] )
      goto LABEL_20;
LABEL_57:
    v88 = 1;
    goto LABEL_58;
  }
  *(_QWORD *)(a1 + 1576) = v50 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 1568);
  v59 = v91[0];
  if ( !v91[0] )
    goto LABEL_57;
LABEL_20:
  v89 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (*(_QWORD *)(v59 + 1640) & 1) != 0 )
    {
      v60 = v59 + 52832;
      if ( v59 != -52832 )
        break;
    }
LABEL_23:
    hdd_adapter_dev_put_debug(v59, 0x2Eu, v51, v52, v53, v54, v55, v56, v57, v58);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v89 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v89 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1568);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1568);
      *(_QWORD *)(a1 + 1576) |= 1uLL;
    }
    v91[0] = v90;
    hdd_get_next_adapter_no_lock((__int64)v13, v90, &v90);
    hdd_validate_next_adapter(v91, &v90, 0x2Eu, v61, v62, v63, v64, v65, v66, v67, v68);
    if ( v90 )
      hdd_adapter_dev_hold_debug(v90, 0x2Eu, v69, v70, v71, v72, v73, v74, v75, v76, v77);
    v78 = *(_QWORD *)(a1 + 1576);
    if ( (v78 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1576) = v78 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1568);
      v59 = v91[0];
      if ( !v91[0] )
        goto LABEL_57;
    }
    else
    {
      raw_spin_unlock(a1 + 1568);
      v59 = v91[0];
      if ( !v91[0] )
        goto LABEL_57;
    }
  }
  while ( 1 )
  {
    v79 = *(_DWORD *)(v59 + 40);
    if ( v79 == 3 )
    {
      if ( (ucfg_nan_is_sta_p2p_ndp_supported(v28) & 1) == 0 )
        goto LABEL_43;
      goto LABEL_44;
    }
    if ( v79 == 2 )
      break;
    if ( v79 != 1 )
      goto LABEL_45;
    if ( (wlan_nan_is_sta_sap_nan_allowed(*v13, v51, v52, v53, v54, v55, v56, v57, v58) & 1) == 0 )
    {
LABEL_43:
      if ( (*(_QWORD *)(v60 + 4416) & 2) != 0 )
        goto LABEL_52;
    }
LABEL_44:
    v59 = v91[0];
LABEL_45:
    if ( v59 )
    {
      if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v60 - *(_DWORD *)v60 - 52832) >> 4))
        || (*(_QWORD *)(v59 + 1640) & 1) == 0 )
      {
        goto LABEL_23;
      }
      v60 = v59 + 52832;
    }
    if ( !v60 )
      goto LABEL_23;
  }
  if ( (ucfg_nan_is_sta_p2p_ndp_supported(v28) & 1) != 0
    || !hdd_cm_is_vdev_associated((_DWORD *)v60) && !hdd_cm_is_connecting(v60) )
  {
    goto LABEL_44;
  }
LABEL_52:
  hdd_adapter_dev_put_debug(v91[0], 0x2Eu, v51, v52, v53, v54, v55, v56, v57, v58);
  if ( v90 )
    hdd_adapter_dev_put_debug(v90, 0x2Eu, v80, v81, v82, v83, v84, v85, v86, v87);
  v88 = 0;
LABEL_58:
  result = os_if_nan_process_ndp_cmd(v28, a3, a4, v88, a2);
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
