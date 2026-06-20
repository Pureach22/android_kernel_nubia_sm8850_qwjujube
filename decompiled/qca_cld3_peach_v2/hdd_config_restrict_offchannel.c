__int64 __fastcall hdd_config_restrict_offchannel(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w22
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  const char *v21; // x3
  __int64 v22; // x4
  __int64 v23; // x8
  unsigned int v24; // w19
  __int64 *v25; // x21
  __int64 vdev_by_user; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  unsigned __int8 v36; // w2
  __int64 v37; // x0
  unsigned int v38; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v40; // x8
  unsigned int channel; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w21
  __int64 result; // x0
  unsigned __int64 v52; // x8
  __int64 v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+8h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a2 + 4);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_restrict_offchannel",
    *(unsigned __int8 *)(a2 + 4));
  if ( v11 >= 2 )
  {
    v20 = "%s: Invalid value %u";
    v21 = "hdd_config_restrict_offchannel";
    v22 = v11;
LABEL_16:
    qdf_trace_msg(0x33u, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, v21, v22);
    goto LABEL_17;
  }
  v23 = *a1;
  v24 = *(_DWORD *)(*a1 + 40);
  if ( (v24 & 0xFFFFFFFD) != 1 )
  {
    v20 = "%s: Invalid interface type:%d";
    v21 = "wlan_hdd_handle_restrict_offchan_config";
    v22 = v24;
    goto LABEL_16;
  }
  v25 = *(__int64 **)(v23 + 24);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(v23 + 52832), 6, "wlan_hdd_handle_restrict_offchan_config");
  if ( !vdev_by_user )
  {
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  v35 = vdev_by_user;
  if ( (v11 & 1) != 0 )
  {
    v36 = *(_BYTE *)(vdev_by_user + 168);
    v37 = *v25;
    v62 = *(unsigned __int8 *)(v35 + 168);
    v38 = policy_mgr_qdf_opmode_to_pm_con_mode(v37, v24, v36, v27, v28, v29, v30, v31, v32, v33, v34);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v35 + 1344);
      v40 = *(_QWORD *)(v35 + 1352);
    }
    else
    {
      raw_spin_lock_bh(v35 + 1344);
      v40 = *(_QWORD *)(v35 + 1352) | 1LL;
      *(_QWORD *)(v35 + 1352) = v40;
    }
    *(_DWORD *)(v35 + 48) |= 0x200u;
    if ( (v40 & 1) != 0 )
    {
      *(_QWORD *)(v35 + 1352) = v40 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v35 + 1344);
    }
    else
    {
      raw_spin_unlock(v35 + 1344);
    }
    channel = policy_mgr_get_channel(*v25, v38, &v62);
    if ( channel && !(unsigned int)wlan_hdd_send_avoid_freq_for_dnbs((__int64)v25, channel) )
    {
      v50 = 0;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to send avoid_freq",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "wlan_hdd_handle_restrict_offchan_config");
      v50 = -22;
    }
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: vdev %d mode %d dnbs enabled",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "wlan_hdd_handle_restrict_offchan_config",
      v62,
      v24);
  }
  else
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v52 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v52 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v52 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(vdev_by_user + 1344);
      v53 = *(_QWORD *)(v35 + 1352);
    }
    else
    {
      raw_spin_lock_bh(vdev_by_user + 1344);
      v53 = *(_QWORD *)(v35 + 1352) | 1LL;
      *(_QWORD *)(v35 + 1352) = v53;
    }
    *(_DWORD *)(v35 + 48) &= ~0x200u;
    if ( (v53 & 1) != 0 )
    {
      *(_QWORD *)(v35 + 1352) = v53 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v35 + 1344);
    }
    else
    {
      raw_spin_unlock(v35 + 1344);
    }
    if ( (unsigned int)wlan_hdd_send_avoid_freq_for_dnbs((__int64)v25, 0) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to clear avoid_freq",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "wlan_hdd_handle_restrict_offchan_config");
      v50 = -22;
    }
    else
    {
      v50 = 0;
    }
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: vdev mode %d dnbs disabled",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "wlan_hdd_handle_restrict_offchan_config",
      v24);
  }
  _hdd_objmgr_put_vdev_by_user(v35, 6, "wlan_hdd_handle_restrict_offchan_config");
  result = v50;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
