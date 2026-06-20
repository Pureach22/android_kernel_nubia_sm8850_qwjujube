__int64 __fastcall hdd_validate_channel_and_bandwidth(
        __int64 a1,
        unsigned int a2,
        int a3,
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
  __int64 v12; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  const char *v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  const char *v36; // x2
  __int64 v37; // x4
  int v38; // w0
  bool is_5ghz_ch_freq; // w0
  int v40; // w0
  __int64 vdev_by_user; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int16 *v50; // x20
  unsigned int operation_chan_freq; // w21
  bool is_6ghz_op_class; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x4
  unsigned int v62; // w19
  __int64 v63; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v64[4]; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v65[4]; // [xsp+Ch] [xbp-24h] BYREF
  int v66; // [xsp+10h] [xbp-20h] BYREF
  __int64 v67; // [xsp+14h] [xbp-1Ch]
  __int64 v68; // [xsp+1Ch] [xbp-14h]
  int v69; // [xsp+24h] [xbp-Ch]
  __int64 v70; // [xsp+28h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 24);
  v69 = 0;
  v68 = 0;
  v67 = 0;
  if ( !v12 )
  {
    v26 = "%s: hdd context is NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)wlan_reg_get_chan_enum_for_freq(a2, a5, a6, a7, a8, a9, a10, a11, a12) < 0x66 )
  {
    if ( !wlan_reg_is_24ghz_ch_freq(a2) && !wlan_reg_is_5ghz_ch_freq(a2) && !wlan_reg_is_6ghz_chan_freq(a2) )
    {
      v36 = "%s: CH %d is not in 2.4GHz or 5GHz or 6GHz";
      goto LABEL_17;
    }
    LODWORD(v68) = a3;
    v35 = *(_QWORD *)(v12 + 8);
    v66 = 9;
    wlan_reg_set_channel_params_for_pwrmode(v35, a2, 0, (__int64)&v66, 0, v27, v28, v29, v30, v31, v32, v33, v34);
    if ( v66 == 9 )
    {
      v36 = "%s: failed to get max bandwdith for %d";
LABEL_17:
      v37 = a2;
LABEL_18:
      qdf_trace_msg(0x33u, 2u, v36, v27, v28, v29, v30, v31, v32, v33, v34, "hdd_validate_channel_and_bandwidth", v37);
      result = 4294967274LL;
      goto LABEL_43;
    }
    if ( !wlan_reg_is_24ghz_ch_freq(a2) )
      goto LABEL_23;
    if ( a4 != 9 && a4 != 1 )
    {
      if ( a4 )
      {
        v36 = "%s: BW %d not possible in 2.4GHz band";
        v37 = a4;
        goto LABEL_18;
      }
      wlan_reg_is_5ghz_ch_freq(a2);
LABEL_29:
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 6, "hdd_validate_channel_and_bandwidth");
      if ( !vdev_by_user )
      {
        result = 4294967274LL;
        goto LABEL_43;
      }
      if ( *(_DWORD *)(a1 + 40) == 3 )
      {
        v50 = (unsigned __int16 *)vdev_by_user;
        if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v12 + 8), a2, v42, v43, v44, v45, v46, v47, v48, v49) & 1) == 0
          || !ucfg_p2p_is_vdev_wfd_r2_mode((__int64)v50) )
        {
          v62 = 0;
          vdev_by_user = (__int64)v50;
          goto LABEL_42;
        }
        v65[0] = 0;
        v64[0] = 0;
        BYTE4(v63) = 0;
        LOBYTE(v63) = 0;
        operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq(v50);
        ucfg_p2p_get_ap_assist_dfs_params((__int64)v50, v65, v64, nullptr, 0, (_BYTE *)&v63 + 4, &v63);
        is_6ghz_op_class = wlan_reg_is_6ghz_op_class(*(_QWORD *)(v12 + 8), BYTE4(v63));
        v61 = 0;
        if ( !is_6ghz_op_class )
          v61 = (unsigned int)wlan_reg_legacy_chan_to_freq(
                                *(_QWORD *)(v12 + 8),
                                (unsigned __int8)v63,
                                v53,
                                v54,
                                v55,
                                v56,
                                v57,
                                v58,
                                v59,
                                v60);
        vdev_by_user = (__int64)v50;
        if ( (v65[0] & 1) == 0 && v64[0] == 1 && ((_DWORD)v61 != operation_chan_freq || (_DWORD)v61 != a2) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Assist AP freq %d, vdev freq %d, new_freq %d",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "hdd_validate_channel_and_bandwidth",
            v61,
            operation_chan_freq,
            a2,
            v63);
          vdev_by_user = (__int64)v50;
          v62 = -22;
          goto LABEL_42;
        }
      }
      v62 = 0;
LABEL_42:
      _hdd_objmgr_put_vdev_by_user(vdev_by_user, 6, "hdd_validate_channel_and_bandwidth");
      result = v62;
      goto LABEL_43;
    }
    v38 = wlan_reg_ch_to_freq(0xDu);
    if ( a4 == 9 || v38 != a2 || v66 )
    {
LABEL_23:
      is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(a2);
      if ( !a4 )
        goto LABEL_29;
      if ( !is_5ghz_ch_freq )
        goto LABEL_29;
      v40 = wlan_reg_ch_to_freq(0x26u);
      if ( a4 == 9 || v40 != a2 || v66 )
        goto LABEL_29;
      v26 = "%s: Only BW20 possible on channel freq 5825";
    }
    else
    {
      v26 = "%s: Only BW20 possible on channel freq 2484";
    }
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v26, a5, a6, a7, a8, a9, a10, a11, a12, "hdd_validate_channel_and_bandwidth");
    result = 4294967274LL;
    goto LABEL_43;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Channel freq %d not in driver's valid channel list",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "hdd_validate_channel_and_bandwidth",
    a2);
  result = 4294967201LL;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
