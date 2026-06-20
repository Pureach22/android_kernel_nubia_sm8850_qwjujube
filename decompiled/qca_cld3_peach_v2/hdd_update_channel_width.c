__int64 __fastcall hdd_update_channel_width(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int8 a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x8
  __int64 *v14; // x28
  unsigned int v15; // w23
  __int64 result; // x0
  __int64 v21; // x20
  __int64 vdev_by_user; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x24
  __int64 v32; // x19
  unsigned int v33; // w25
  __int64 v34; // x0
  char is_mlo_vdev; // w0
  __int64 link_info_by_ieee_link_id; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x6
  __int64 ap_link_by_link_id; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w25
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned __int16 *active_channel; // x0
  unsigned __int16 max_chwidth; // w24
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w26
  unsigned int bw_value; // w26
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  unsigned int v92; // w21
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  int updated; // w20
  unsigned int v110; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v111; // [xsp+8h] [xbp-8h]

  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)a1;
  v110 = 0;
  v14 = *(__int64 **)(v13 + 24);
  if ( !v14 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx failure", a6, a7, a8, a9, a10, a11, a12, a13, "hdd_update_channel_width");
    goto LABEL_5;
  }
  v15 = *(unsigned __int8 *)(a1 + 8);
  if ( *(_DWORD *)(v13 + 40) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d: op mode %d, CW update not supported",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "hdd_update_channel_width",
      *(unsigned __int8 *)(a1 + 8));
LABEL_5:
    result = 4294967274LL;
    goto LABEL_6;
  }
  v21 = a1;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_update_channel_width");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d: vdev not found",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_update_channel_width",
      *(unsigned __int8 *)(v21 + 8));
    goto LABEL_5;
  }
  v31 = *(_QWORD *)(vdev_by_user + 216);
  v32 = vdev_by_user;
  if ( !v31 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: pdev is NULL", v23, v24, v25, v26, v27, v28, v29, v30, "hdd_update_channel_width");
    v34 = v32;
LABEL_29:
    _hdd_objmgr_put_vdev_by_user(v34, 6, "hdd_update_channel_width");
    goto LABEL_5;
  }
  if ( a2 >= 6 )
  {
    v33 = 8;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid channel width %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_convert_chwidth_to_phy_chwidth",
      a2);
  }
  else
  {
    v33 = dword_AF75F4[a2];
  }
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v32, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( a4 == 0xFF || (is_mlo_vdev & 1) == 0 )
  {
    active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(v32);
    if ( !active_channel )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: vdev %d: comp_vdev_chan is NULL",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "hdd_update_channel_width",
        *(unsigned __int8 *)(v21 + 8));
      goto LABEL_35;
    }
    v55 = *active_channel;
  }
  else
  {
    link_info_by_ieee_link_id = hdd_get_link_info_by_ieee_link_id(*(_QWORD *)v21, a4, 0);
    if ( !link_info_by_ieee_link_id )
    {
LABEL_28:
      v34 = v32;
      goto LABEL_29;
    }
    v45 = *(unsigned __int8 *)(link_info_by_ieee_link_id + 8);
    v21 = link_info_by_ieee_link_id;
    *(_BYTE *)(link_info_by_ieee_link_id + 1697) = v33;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: save ch_width:%u to link_id:%u vdev_id:%u",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_update_mlo_link_chn_width",
      v33,
      a4,
      v45);
    ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(v32 + 1360), a4);
    if ( !ap_link_by_link_id )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to get MLO link freq",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "hdd_update_channel_width");
      goto LABEL_35;
    }
    v55 = **(unsigned __int16 **)(ap_link_by_link_id + 32);
    _hdd_objmgr_put_vdev_by_user(v32, 6, "hdd_update_channel_width");
    result = _hdd_objmgr_get_vdev_by_user(v21, 6, "hdd_update_channel_width");
    if ( !result )
      goto LABEL_6;
    v32 = result;
    v15 = *(unsigned __int8 *)(v21 + 8);
    wlan_mlme_get_bw_no_punct(*v14, v32, *(unsigned __int16 **)(v32 + 40), &v110);
  }
  if ( v55 )
  {
    max_chwidth = wlan_reg_get_max_chwidth(v31, v55, v56, v57, v58, v59, v60, v61, v62, v63);
    if ( a2 >= 6 )
    {
      v74 = 8;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Invalid channel width %d",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "hdd_convert_chwidth_to_phy_chwidth",
        a2);
    }
    else
    {
      v74 = dword_AF75F4[a2];
    }
    bw_value = (unsigned __int16)wlan_reg_get_bw_value(v74);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: op_freq: %d, max_allowed_bw: %d, bw_to_update: %d",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "hdd_update_channel_width",
      v55,
      max_chwidth,
      bw_value);
    if ( bw_value > max_chwidth )
      goto LABEL_28;
  }
  if ( (ucfg_mlme_is_chwidth_with_notify_supported(*v14) & 1) != 0 && (hdd_cm_is_vdev_connected(v21) & 1) != 0 )
  {
    v92 = hdd_convert_chwidth_to_phy_chwidth(a2, v84, v85, v86, v87, v88, v89, v90, v91);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d : process update ch width request to %d",
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      "hdd_update_channel_width",
      v15,
      v92);
    if ( (unsigned int)ucfg_mlme_send_ch_width_update_with_notify(
                         *v14,
                         (_QWORD *)v32,
                         v92,
                         v15,
                         v101,
                         v102,
                         v103,
                         v104,
                         v105,
                         v106,
                         v107,
                         v108) )
    {
      _hdd_objmgr_put_vdev_by_user(v32, 6, "hdd_update_channel_width");
      result = 4294967291LL;
    }
    else
    {
      updated = hdd_update_bss_rate_flags(v21, *v14, v92);
      _hdd_objmgr_put_vdev_by_user(v32, 6, "hdd_update_channel_width");
      if ( updated )
        result = 4294967291LL;
      else
        result = 0;
    }
    goto LABEL_6;
  }
LABEL_35:
  _hdd_objmgr_put_vdev_by_user(v32, 6, "hdd_update_channel_width");
  result = wma_cli_set_command(v15, 21, a2, 1);
  if ( !(_DWORD)result )
  {
    hdd_restore_sme_config(v21, a2, a5 & 1, a3);
    result = 0;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
