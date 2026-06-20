__int64 __fastcall hdd_update_channel_width(
        unsigned __int8 *a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        char a13)
{
  __int64 *v13; // x28
  unsigned int v14; // w22
  __int64 result; // x0
  __int64 vdev_by_user; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x24
  _QWORD *v30; // x21
  _WORD *active_channel; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w23
  unsigned __int16 max_chwidth; // w24
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w25
  _QWORD *v51; // x0
  unsigned int bw_value; // w25
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w20
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x0
  __int64 v87; // x21
  __int64 v88; // x0
  __int64 v89; // x19
  unsigned int v90; // w0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  int updated; // w19
  __int64 v108; // [xsp+8h] [xbp-38h] BYREF
  __int64 v109; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v110)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v111)(); // [xsp+20h] [xbp-20h]
  __int64 v112; // [xsp+28h] [xbp-18h]
  __int64 v113; // [xsp+30h] [xbp-10h]
  __int64 v114; // [xsp+38h] [xbp-8h]

  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  if ( !v13 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx failure", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_update_channel_width");
    goto LABEL_5;
  }
  v14 = a1[8];
  if ( *(_DWORD *)(*(_QWORD *)a1 + 40LL) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d: op mode %d, CW update not supported",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_update_channel_width",
      a1[8]);
LABEL_5:
    result = 4294967274LL;
    goto LABEL_6;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_update_channel_width");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d: vdev not found",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "hdd_update_channel_width",
      a1[8]);
    goto LABEL_5;
  }
  v29 = *(_QWORD *)(vdev_by_user + 152);
  v30 = (_QWORD *)vdev_by_user;
  if ( !v29 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: pdev is NULL", v21, v22, v23, v24, v25, v26, v27, v28, "hdd_update_channel_width");
    v51 = v30;
LABEL_21:
    _hdd_objmgr_put_vdev_by_user(v51, 6, "hdd_update_channel_width");
    goto LABEL_5;
  }
  if ( a2 >= 6 )
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid channel width %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "hdd_convert_chwidth_to_phy_chwidth",
      a2);
  active_channel = (_WORD *)wlan_vdev_get_active_channel((__int64)v30);
  if ( active_channel )
  {
    v40 = (unsigned __int16)*active_channel;
    if ( *active_channel )
    {
      max_chwidth = wlan_reg_get_max_chwidth(v29, v40, v32, v33, v34, v35, v36, v37, v38, v39);
      if ( a2 >= 6 )
      {
        v50 = 8;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Invalid channel width %d",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "hdd_convert_chwidth_to_phy_chwidth",
          a2);
      }
      else
      {
        v50 = dword_A0564C[a2];
      }
      bw_value = (unsigned __int16)wlan_reg_get_bw_value(v50);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: op_freq: %d, max_allowed_bw: %d, bw_to_update: %d",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "hdd_update_channel_width",
        v40,
        max_chwidth,
        bw_value);
      if ( bw_value > max_chwidth )
      {
        v51 = v30;
        goto LABEL_21;
      }
    }
    if ( (ucfg_mlme_is_chwidth_with_notify_supported(*v13) & 1) != 0 && (hdd_cm_is_vdev_connected(a1) & 1) != 0 )
    {
      v69 = hdd_convert_chwidth_to_phy_chwidth(a2, v61, v62, v63, v64, v65, v66, v67, v68);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d : process update ch width request to %d",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "hdd_update_channel_width",
        v14,
        v69);
      if ( (unsigned int)ucfg_mlme_send_ch_width_update_with_notify(
                           *v13,
                           v30,
                           v69,
                           v14,
                           v78,
                           v79,
                           v80,
                           v81,
                           v82,
                           v83,
                           v84,
                           v85) )
      {
        _hdd_objmgr_put_vdev_by_user(v30, 6, "hdd_update_channel_width");
        result = 4294967291LL;
      }
      else
      {
        updated = hdd_update_bss_rate_flags(a1, *v13, v69);
        _hdd_objmgr_put_vdev_by_user(v30, 6, "hdd_update_channel_width");
        if ( updated )
          result = 4294967291LL;
        else
          result = 0;
      }
      goto LABEL_6;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d: comp_vdev_chan is NULL",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "hdd_update_channel_width",
      a1[8]);
  }
  _hdd_objmgr_put_vdev_by_user(v30, 6, "hdd_update_channel_width");
  result = wma_cli_set_command(v14, 21, a2, 1);
  if ( !(_DWORD)result )
  {
    v112 = 0;
    v113 = 0;
    v110 = nullptr;
    v111 = nullptr;
    v108 = 0;
    v109 = 0;
    v86 = _qdf_mem_malloc(0x18u, "hdd_restore_sme_config", 2663);
    if ( v86 )
    {
      v87 = v86;
      v88 = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_restore_sme_config");
      if ( v88 )
      {
        v89 = v88;
        *(_QWORD *)v87 = v88;
        *(_BYTE *)(v87 + 12) = a13 & 1;
        *(_DWORD *)(v87 + 8) = a2;
        *(_DWORD *)(v87 + 16) = a3;
        v109 = v87;
        v110 = hdd_restore_sme_config_cb;
        v111 = hdd_restore_sme_config_flush_cb;
        v90 = scheduler_post_message_debug(
                0x33u,
                0x48u,
                72,
                (unsigned __int16 *)&v108,
                0xA7Cu,
                (__int64)"hdd_restore_sme_config");
        if ( v90 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: status %d",
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            "hdd_restore_sme_config",
            v90);
          _hdd_objmgr_put_vdev_by_user(v89, 5, "hdd_restore_sme_config");
          _qdf_mem_free(v87);
        }
      }
      else
      {
        _qdf_mem_free(v87);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: no vdev from link info",
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          "hdd_restore_sme_config");
      }
    }
    result = 0;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
