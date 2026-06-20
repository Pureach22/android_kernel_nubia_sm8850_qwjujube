__int64 __fastcall dp_panel_read_sink_caps(unsigned __int8 *a1, __int64 a2, char a3)
{
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 ipc_log_context; // x0
  void *v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w21
  __int64 v14; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 sink_dsc_caps; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  _BYTE *v26; // x8
  unsigned int v27; // w10
  int v28; // w8
  int v29; // w20
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned __int64 v32; // x22
  __int64 v33; // x0
  int v34; // w22
  __int64 v35; // x0
  unsigned __int64 v36; // x21
  __int64 v37; // x0
  __int64 lttpr_common_caps; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  unsigned __int64 v41; // x28
  __int64 v42; // x0
  int v43; // w10
  int v44; // w8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  unsigned int v48; // w8
  __int64 v49; // x10
  unsigned __int64 v50; // x21
  __int64 v51; // x0
  int v52; // w9
  unsigned int v53; // w8
  int v54; // w10
  __int64 v55; // x0
  unsigned int v56; // w8
  __int64 v57; // x0
  unsigned int v58; // w8
  __int64 v59; // x0
  __int64 v60; // x0
  unsigned __int8 v61; // w27
  unsigned __int8 *v62; // x21
  int v63; // w22
  __int64 v64; // x0
  bool v65; // zf
  __int64 v66; // x8
  int v67; // w8
  __int64 v68; // x0
  unsigned __int64 v69; // x20
  __int64 i; // x22
  __int64 v71; // x0
  unsigned int v72; // w21
  __int64 v73; // x0
  unsigned int v74; // w8
  unsigned int v75; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v76[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v77[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v78; // [xsp+18h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  if ( !a1 || !a2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v10 = &unk_275B6D;
LABEL_21:
    printk(v10, "dp_panel_read_sink_caps");
    v13 = -22;
    goto LABEL_22;
  }
  v6 = *(_QWORD *)(*((_QWORD *)a1 + 149) + 24LL);
  a1[1235] = 0;
  v77[0] = 0;
  v76[0] = 0;
  *(_WORD *)(a1 + 1233) = 0;
  v7 = drm_dp_dpcd_read(v6, 14, v76, 1);
  if ( (_DWORD)v7 != 1 )
  {
    v11 = get_ipc_log_context(v7);
    ipc_log_string(
      v11,
      "[e][%-4d]error reading DP_TRAINING_AUX_RD_INTERVAL\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v12 = printk(&unk_21FAB7, "dp_panel_read_dpcd");
LABEL_8:
    v13 = -22;
LABEL_9:
    v14 = get_ipc_log_context(v12);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v14,
      "[e][%-4d]panel dpcd read failed/incorrect, set default params\n",
      *(_DWORD *)(StatusReg + 1800));
    v16 = printk(&unk_272586, "dp_panel_read_sink_caps");
    *(_QWORD *)(a1 + 76) = 0x1000278D0LL;
    v17 = get_ipc_log_context(v16);
    ipc_log_string(
      v17,
      "[d][%-4d]link_rate=%d num_lanes=%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *((_DWORD *)a1 + 19),
      *((_DWORD *)a1 + 20));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]link_rate=%d num_lanes=%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *((_DWORD *)a1 + 19),
        *((_DWORD *)a1 + 20));
    goto LABEL_11;
  }
  if ( (v76[0] & 0x80000000) != 0 )
  {
    v31 = get_ipc_log_context(v7);
    v32 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v31, "[d][%-4d]using EXTENDED_RECEIVER_CAPABILITY_FIELD\n", *(_DWORD *)(v32 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]using EXTENDED_RECEIVER_CAPABILITY_FIELD\n", *(_DWORD *)(v32 + 1800));
    v8 = 8704;
  }
  else
  {
    v8 = 0;
  }
  v33 = drm_dp_dpcd_read(v6, v8, a1, 16);
  v34 = v33;
  if ( (int)v33 <= 15 )
  {
    v35 = get_ipc_log_context(v33);
    v36 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v35, "[e][%-4d]dpcd read failed, rlen=%d\n", *(_DWORD *)(v36 + 1800), v34);
    v12 = printk(&unk_2597A8, "dp_panel_read_dpcd");
    if ( v34 == -110 )
    {
      v37 = get_ipc_log_context(v12);
      ipc_log_string(v37, "[e][%-4d]DPCD read failed, return early\n", *(_DWORD *)(v36 + 1800));
      printk(&unk_261169, "dp_panel_read_sink_caps");
      v13 = -110;
      goto LABEL_22;
    }
    goto LABEL_8;
  }
  print_hex_dump(&unk_2597DF, "[msm-dp]SINK DPCD: ", 0, 8, 1, a1, v33 & 0x7FFFFFFF, 0);
  lttpr_common_caps = drm_dp_read_lttpr_common_caps(v6, a1, a1 + 20);
  if ( (_DWORD)lttpr_common_caps )
  {
    v39 = get_ipc_log_context(lttpr_common_caps);
    ipc_log_string(v39, "[w][%-4d]dpcd lttpr read fail:%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), 0);
    lttpr_common_caps = printk(&unk_230ACF, "dp_panel_read_dpcd");
  }
  v40 = get_ipc_log_context(lttpr_common_caps);
  v41 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v40,
    "[d][%-4d]lttpr caps - rev:0x%x, max_lr: 0x%x, phy_rp_cnt: 0x%x, phy_rp_mode: 0x%x",
    *(_DWORD *)(v41 + 1800),
    a1[20],
    a1[21],
    a1[22],
    a1[23]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]lttpr caps - rev:0x%x, max_lr: 0x%x, phy_rp_cnt: 0x%x, phy_rp_mode: 0x%x",
      *(_DWORD *)(v41 + 1800),
      a1[20],
      a1[21],
      a1[22],
      a1[23]);
  v42 = drm_dp_dpcd_read(*(_QWORD *)(*((_QWORD *)a1 + 149) + 24LL), 8720, v77, 1);
  if ( (_DWORD)v42 == 1 )
  {
    v43 = (v77[0] >> 4) & 1;
    v44 = (v77[0] >> 5) & 1;
    a1[1233] = (v77[0] & 8) != 0;
    a1[1234] = v43;
    a1[1235] = v44;
    v45 = get_ipc_log_context(v42);
    ipc_log_string(
      v45,
      "[d][%-4d]vsc=%d, vscext=%d, vscext_chaining=%d\n",
      *(_DWORD *)(v41 + 1800),
      a1[1233],
      a1[1234],
      a1[1235]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]vsc=%d, vscext=%d, vscext_chaining=%d\n",
        *(_DWORD *)(v41 + 1800),
        a1[1233],
        a1[1234],
        a1[1235]);
  }
  else
  {
    v46 = get_ipc_log_context(v42);
    ipc_log_string(v46, "[d][%-4d]failed to read DPRX_FEATURE_ENUMERATION_LIST\n", *(_DWORD *)(v41 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]failed to read DPRX_FEATURE_ENUMERATION_LIST\n",
        *(_DWORD *)(v41 + 1800));
    v77[0] = 0;
  }
  v47 = a1[1];
  if ( !a1[1] )
  {
    v47 = 20;
    a1[1] = 20;
  }
  v48 = *a1;
  v49 = *((_QWORD *)a1 + 151);
  a1[72] = v48;
  a1[1265] = v48 & 0xF;
  a1[1264] = v48 >> 4;
  v50 = *(unsigned int *)(v49 + 708);
  v51 = drm_dp_bw_code_to_link_rate(v47);
  v52 = v51;
  v53 = *((_DWORD *)a1 + 226);
  v54 = a1[2] & 0x1F;
  if ( v50 < (int)v51 )
    v52 = v50;
  *((_DWORD *)a1 + 19) = v52;
  *((_DWORD *)a1 + 20) = v54;
  if ( v53 <= 0x1E && ((1 << v53) & 0x40100440) != 0 )
  {
    v55 = get_ipc_log_context(v51);
    ipc_log_string(v55, "[d][%-4d]debug link bandwidth code: 0x%x\n", *(_DWORD *)(v41 + 1800), *((_DWORD *)a1 + 226));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]debug link bandwidth code: 0x%x\n",
        *(_DWORD *)(v41 + 1800),
        *((_DWORD *)a1 + 226));
    v51 = drm_dp_bw_code_to_link_rate(*((unsigned int *)a1 + 226));
    *((_DWORD *)a1 + 19) = v51;
  }
  v56 = *((_DWORD *)a1 + 225);
  if ( v56 <= 4 && ((1 << v56) & 0x16) != 0 )
  {
    v57 = get_ipc_log_context(v51);
    v51 = ipc_log_string(v57, "[d][%-4d]debug lane count: %d\n", *(_DWORD *)(v41 + 1800), *((_DWORD *)a1 + 225));
    if ( (_drm_debug & 4) != 0 )
      v51 = _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]debug lane count: %d\n",
              *(_DWORD *)(v41 + 1800),
              *((_DWORD *)a1 + 225));
    *((_DWORD *)a1 + 20) = *((_DWORD *)a1 + 225);
  }
  if ( (a3 & 1) != 0 )
  {
    v58 = *((_DWORD *)a1 + 20);
    if ( v58 >= 2 )
      v58 = 2;
    *((_DWORD *)a1 + 20) = v58;
  }
  v59 = get_ipc_log_context(v51);
  ipc_log_string(
    v59,
    "[i][%-4d]: version:%d.%d, rate:%d, lanes:%d\n",
    *(_DWORD *)(v41 + 1800),
    a1[1264],
    a1[1265],
    *((_DWORD *)a1 + 19),
    *((_DWORD *)a1 + 20));
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_26B5FE, *(unsigned int *)(v41 + 1800));
  else
    printk(&unk_27C429, "dp_panel_read_dpcd");
  if ( *a1 >= 0x11u && (char)a1[2] < 0 )
    *((_QWORD *)a1 + 11) |= 1uLL;
  v60 = drm_dp_dpcd_read(*(_QWORD *)(*((_QWORD *)a1 + 149) + 24LL), 582, v76, 1);
  if ( (_DWORD)v60 == 1 && (v76[0] & 0x20) != 0 )
    *((_QWORD *)a1 + 11) |= 2uLL;
  v61 = a1[7];
  if ( (a1[5] & 1) != 0 && *a1 >= 0x11u )
  {
    v62 = a1 + 28;
    v60 = drm_dp_dpcd_read(*(_QWORD *)(*((_QWORD *)a1 + 149) + 24LL), 128, a1 + 28, 16);
    v63 = v60;
    if ( (int)v60 < 16 )
    {
      v64 = get_ipc_log_context(v60);
      ipc_log_string(v64, "[e][%-4d]ds port status failed, rlen=%d\n", *(_DWORD *)(v41 + 1800), v63);
      v12 = printk(&unk_2185F0, "dp_panel_read_dpcd");
      goto LABEL_8;
    }
    for ( i = 0; i != 16; ++i )
    {
      if ( v62[i] )
      {
        v71 = get_ipc_log_context(v60);
        ipc_log_string(v71, "[i][%-4d]: ds_ports[%d] = 0x%x\n", *(_DWORD *)(v41 + 1800), i, v62[i]);
        if ( (_drm_debug & 4) != 0 )
          v60 = printk(&unk_248376, *(unsigned int *)(v41 + 1800));
        else
          v60 = printk(&unk_255F6C, "dp_panel_read_dpcd");
      }
    }
  }
  v72 = v61 & 7;
  if ( v72 >= 2 )
  {
    v73 = get_ipc_log_context(v60);
    ipc_log_string(v73, "[d][%-4d]DS port count %d greater that max (%d) supported\n", *(_DWORD *)(v41 + 1800), v72, 1);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]DS port count %d greater that max (%d) supported\n",
        *(_DWORD *)(v41 + 1800),
        v72,
        1);
  }
  v12 = drm_dp_link_rate_to_bw_code(*((unsigned int *)a1 + 19));
  v13 = 0;
  if ( (unsigned __int8)v12 > 0x1Eu )
    goto LABEL_9;
  if ( ((1 << v12) & 0x40100440) == 0 )
    goto LABEL_9;
  v74 = *((_DWORD *)a1 + 20);
  v13 = 0;
  if ( v74 > 4 )
    goto LABEL_9;
  if ( ((1 << v74) & 0x16) == 0 )
    goto LABEL_9;
  v12 = drm_dp_link_rate_to_bw_code(*((unsigned int *)a1 + 19));
  v13 = 0;
  if ( *((_DWORD *)a1 + 224) < (unsigned int)(unsigned __int8)v12 )
    goto LABEL_9;
LABEL_11:
  if ( (a1[5] & 1) != 0 )
  {
    v18 = drm_dp_dpcd_read(*(_QWORD *)(*((_QWORD *)a1 + 149) + 24LL), 512, &v75, 1);
    if ( (_DWORD)v18 == 1 )
    {
      v75 = v75 & 0x3F | (((v75 >> 7) & 1) << 6);
      if ( !v75 )
      {
        v19 = get_ipc_log_context(v18);
        ipc_log_string(v19, "[e][%-4d]no downstream ports connected\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_267B4E, "dp_panel_read_sink_caps");
        v13 = -107;
        *(_DWORD *)(*((_QWORD *)a1 + 150) + 8LL) = 0;
        goto LABEL_22;
      }
    }
  }
  if ( *(_BYTE *)(*((_QWORD *)a1 + 151) + 724LL) != 1 )
    goto LABEL_19;
  v20 = *((__int64 (__fastcall **)(_QWORD))a1 + 141);
  if ( *((_DWORD *)v20 - 1) != -1505889699 )
    __break(0x8228u);
  sink_dsc_caps = v20(a1);
  if ( (sink_dsc_caps & 1) == 0 )
  {
LABEL_19:
    sde_get_edid(a2, *(_QWORD *)(*((_QWORD *)a1 + 149) + 24LL) + 8LL, a1 + 96);
    if ( !**((_QWORD **)a1 + 12) )
    {
      v22 = get_ipc_log_context(0);
      ipc_log_string(v22, "[e][%-4d]EDID read failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_23AA9E, "dp_panel_read_edid");
      v23 = drm_detect_monitor_audio(**((_QWORD **)a1 + 12));
      a1[960] = v23 & 1;
      v24 = get_ipc_log_context(v23);
      ipc_log_string(
        v24,
        "[e][%-4d]panel edid read failed, set failsafe mode\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      v10 = &unk_230A88;
      goto LABEL_21;
    }
    sink_dsc_caps = ((__int64 (*)(void))drm_detect_monitor_audio)();
    v13 = 0;
    a1[960] = sink_dsc_caps & 1;
  }
  v26 = *((_BYTE **)a1 + 151);
  v27 = *a1;
  a1[969] = v26[730];
  a1[965] = v26[726];
  v28 = (unsigned __int8)v26[727];
  *(_WORD *)(a1 + 967) = 0;
  *((_QWORD *)a1 + 125) = 0;
  a1[966] = v28;
  if ( v27 >= 0x14 && v28 )
  {
    sink_dsc_caps = drm_dp_dpcd_read(*(_QWORD *)(*((_QWORD *)a1 + 149) + 24LL), 144, a1 + 60, 1);
    v29 = sink_dsc_caps;
    if ( (int)sink_dsc_caps > 0 )
    {
      v65 = (a1[60] & 1) == 0;
      a1[968] = a1[60] & 1;
      if ( v65 )
        v66 = 0x100000000LL;
      else
        v66 = 0x10657ED52LL;
      *((_QWORD *)a1 + 125) = v66;
    }
    else
    {
      v30 = get_ipc_log_context(sink_dsc_caps);
      ipc_log_string(
        v30,
        "[e][%-4d]fec capability read failed, rlen=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v29);
      sink_dsc_caps = printk(&unk_22642F, "dp_panel_read_sink_fec_caps");
    }
    if ( a1[965] == 1 && a1[968] == 1 )
      sink_dsc_caps = dp_panel_read_sink_dsc_caps(a1);
  }
  if ( a1[967] == 1 )
  {
    if ( (a1[969] & 1) != 0 )
    {
      if ( (*(_BYTE *)(*((_QWORD *)a1 + 151) + 731LL) & 1) != 0 )
      {
        v67 = 4;
        goto LABEL_89;
      }
      goto LABEL_87;
    }
  }
  else if ( (a1[969] & 1) != 0 )
  {
LABEL_87:
    v67 = 2;
    goto LABEL_89;
  }
  v67 = 1;
LABEL_89:
  *((_DWORD *)a1 + 244) = v67;
  v68 = get_ipc_log_context(sink_dsc_caps);
  v69 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v68,
    "[i][%-4d]fec_en=%d, dsc_en=%d, widebus_en=%d\n",
    *(_DWORD *)(v69 + 1800),
    a1[968],
    a1[967],
    a1[969]);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_275E11, *(unsigned int *)(v69 + 1800));
  else
    printk(&unk_2110DE, "dp_panel_read_sink_caps");
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v13;
}
