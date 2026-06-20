__int64 __fastcall dp_debug_get(_QWORD *a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x0
  __int64 v4; // x9
  _QWORD *v5; // x21
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 v8; // x11
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x8
  const char *property; // x0
  unsigned __int64 dir; // x0
  unsigned __int64 v16; // x22
  unsigned __int64 file; // x0
  int inited; // w23
  unsigned __int64 v19; // x0
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x0
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x0
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x0
  unsigned __int64 v28; // x0
  unsigned __int64 v29; // x0
  unsigned __int64 v30; // x0
  unsigned __int64 v31; // x0
  unsigned __int64 v32; // x0
  unsigned __int64 v33; // x0
  __int64 ipc_log_context; // x0
  __int64 v36; // x1
  const char *v37; // x0
  unsigned __int64 v38; // x0
  unsigned __int64 v39; // x0
  unsigned __int64 v40; // x0
  unsigned __int64 v41; // x0
  unsigned __int64 v42; // x0
  unsigned __int64 v43; // x0
  unsigned __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  void *v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  void *v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  void *v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  void *v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  void *v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0

  v2 = *a1;
  if ( !v2 || !a1[1] || !a1[2] || !a1[3] || !a1[6] || !a1[8] || !a1[9] )
  {
    ipc_log_context = get_ipc_log_context(v2);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_debug_get");
    return -22;
  }
  v3 = (_QWORD *)devm_kmalloc(v2, 432, 3520);
  if ( !v3 )
    return -12;
  v4 = a1[3];
  v5 = v3 + 47;
  v6 = (__int64)v3;
  v3[13] = a1[2];
  v3[14] = v4;
  v7 = a1[4];
  v8 = a1[5];
  v9 = *a1;
  v3[15] = a1[1];
  v3[16] = v7;
  v3[18] = v8;
  v3[19] = v9;
  v10 = a1[7];
  v3[17] = a1[6];
  v11 = a1[8];
  v12 = a1[9];
  v3[43] = v10;
  v3[44] = v11;
  v13 = a1[10];
  v3[45] = v12;
  v3[46] = v13;
  _mutex_init(v3 + 47, "&debug->lock", &dp_debug_get___key);
  property = (const char *)of_get_property(*(_QWORD *)(*(_QWORD *)(v6 + 152) + 744LL), "label", 0);
  if ( !property )
    property = "drm_dp";
  *(_QWORD *)(v6 + 96) = property;
  dir = debugfs_create_dir();
  v16 = dir;
  if ( !dir || dir > 0xFFFFFFFFFFFFF000LL )
  {
    if ( dir )
      inited = dir;
    else
      inited = -22;
    v46 = get_ipc_log_context(dir);
    ipc_log_string(
      v46,
      "[e][%-4d][%s] debugfs create dir failed, rc = %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    printk(&unk_26B967, "dp_debug_init");
    goto LABEL_102;
  }
  *(_QWORD *)v6 = dir;
  file = debugfs_create_file("dp_debug", 292, dir, v6, &dp_debug_fops);
  inited = file;
  if ( file && file < 0xFFFFFFFFFFFFF001LL )
  {
    v19 = debugfs_create_file("connected", 292, v16, v6, &connected_fops);
    inited = v19;
    if ( v19 && v19 < 0xFFFFFFFFFFFFF001LL )
    {
      v20 = debugfs_create_file("hdr", 256, v16, v6, &hdr_fops);
      inited = v20;
      if ( v20 && v20 < 0xFFFFFFFFFFFFF001LL )
      {
        v21 = debugfs_create_file("hdr_mst", 256, v16, v6, &hdr_mst_fops);
        inited = v21;
        if ( v21 && v21 < 0xFFFFFFFFFFFFF001LL )
        {
          v22 = debugfs_create_file("hdcp", 420, v16, v6, &hdcp_fops);
          inited = v22;
          if ( v22 && v22 < 0xFFFFFFFFFFFFF001LL )
            goto LABEL_23;
          v55 = get_ipc_log_context(v22);
          ipc_log_string(
            v55,
            "[e][%-4d][%s] debugfs hdcp failed, rc=%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(const char **)(v6 + 96),
            inited);
          v48 = &unk_2376FA;
        }
        else
        {
          v53 = get_ipc_log_context(v21);
          ipc_log_string(
            v53,
            "[e][%-4d][%s] debugfs hdr_mst failed, rc=%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(const char **)(v6 + 96),
            inited);
          v48 = &unk_259A7E;
        }
      }
      else
      {
        v50 = get_ipc_log_context(v20);
        ipc_log_string(
          v50,
          "[e][%-4d][%s] debugfs hdr failed, rc=%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(const char **)(v6 + 96),
          inited);
        v48 = &unk_23411C;
      }
    }
    else
    {
      v49 = get_ipc_log_context(v19);
      ipc_log_string(
        v49,
        "[e][%-4d][%s] debugfs connected failed, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(const char **)(v6 + 96),
        inited);
      v48 = &unk_2340DA;
    }
  }
  else
  {
    v47 = get_ipc_log_context(file);
    ipc_log_string(
      v47,
      "[e][%-4d][%s] debugfs create file failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    v48 = &unk_245230;
  }
  printk(v48, "dp_debug_init_status");
  if ( inited )
    goto LABEL_101;
LABEL_23:
  v23 = debugfs_create_file("edid_modes", 420, v16, v6, &edid_modes_fops);
  inited = v23;
  if ( v23 && v23 < 0xFFFFFFFFFFFFF001LL )
  {
    v24 = debugfs_create_file("edid_modes_mst", 420, v16, v6, &edid_modes_mst_fops);
    inited = v24;
    if ( v24 && v24 < 0xFFFFFFFFFFFFF001LL )
    {
      v25 = debugfs_create_file("edid", 420, v16, v6, &edid_fops);
      inited = v25;
      if ( v25 && v25 < 0xFFFFFFFFFFFFF001LL )
      {
        v26 = debugfs_create_file("dpcd", 420, v16, v6, &dpcd_fops);
        inited = v26;
        if ( v26 && v26 < 0xFFFFFFFFFFFFF001LL )
        {
          v27 = debugfs_create_file("crc", 420, v16, v6, &crc_fops);
          inited = v27;
          if ( v27 && v27 < 0xFFFFFFFFFFFFF001LL )
            goto LABEL_33;
          v61 = get_ipc_log_context(v27);
          ipc_log_string(
            v61,
            "[e][%-4d][%s] debugfs crc failed, rc=%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            "drm_dp",
            inited);
          v52 = &unk_25632D;
        }
        else
        {
          v59 = get_ipc_log_context(v26);
          ipc_log_string(
            v59,
            "[e][%-4d][%s] debugfs dpcd failed, rc=%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(const char **)(v6 + 96),
            inited);
          v52 = &unk_26BA69;
        }
      }
      else
      {
        v56 = get_ipc_log_context(v25);
        ipc_log_string(
          v56,
          "[e][%-4d][%s] debugfs edid failed, rc=%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(const char **)(v6 + 96),
          inited);
        v52 = &unk_24B91D;
      }
    }
    else
    {
      v54 = get_ipc_log_context(v24);
      ipc_log_string(
        v54,
        "[e][%-4d][%s] debugfs create edid_modes_mst failed, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(const char **)(v6 + 96),
        inited);
      v52 = &unk_24EDF4;
    }
  }
  else
  {
    v51 = get_ipc_log_context(v23);
    ipc_log_string(
      v51,
      "[e][%-4d][%s] debugfs create edid_modes failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    v52 = &unk_2614B7;
  }
  printk(v52, "dp_debug_init_sink_caps");
  if ( inited )
    goto LABEL_101;
LABEL_33:
  v28 = debugfs_create_file("mst_con_id", 420, v16, v6, &mst_con_id_fops);
  inited = v28;
  if ( !v28 || v28 >= 0xFFFFFFFFFFFFF001LL )
  {
    v57 = get_ipc_log_context(v28);
    ipc_log_string(
      v57,
      "[e][%-4d][%s] debugfs create mst_con_id failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    v58 = &unk_267E81;
    goto LABEL_87;
  }
  v29 = debugfs_create_file("mst_con_info", 420, v16, v6, &mst_conn_info_fops);
  inited = v29;
  if ( !v29 || v29 >= 0xFFFFFFFFFFFFF001LL )
  {
    v60 = get_ipc_log_context(v29);
    ipc_log_string(
      v60,
      "[e][%-4d][%s] debugfs create mst_conn_info failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    v58 = &unk_26BAA6;
LABEL_87:
    printk(v58, "dp_debug_init_mst");
    if ( inited )
      goto LABEL_101;
    goto LABEL_51;
  }
  v30 = debugfs_create_file("mst_con_add", 420, v16, v6, &mst_con_add_fops);
  inited = v30;
  if ( v30 && v30 < 0xFFFFFFFFFFFFF001LL )
  {
    v31 = debugfs_create_file("mst_con_remove", 420, v16, v6, &mst_con_remove_fops);
    inited = v31;
    if ( v31 && v31 < 0xFFFFFFFFFFFFF001LL )
    {
      v32 = debugfs_create_file("mst_mode", 420, v16, v6, &mst_mode_fops);
      inited = v32;
      if ( v32 && v32 < 0xFFFFFFFFFFFFF001LL )
      {
        v33 = debugfs_create_file("mst_sideband_mode", 420, v16, v6, &mst_sideband_mode_fops);
        inited = v33;
        if ( v33 && v33 < 0xFFFFFFFFFFFFF001LL )
        {
          debugfs_create_u32("mst_edid_idx", 420, v16, v6 + 20);
          goto LABEL_51;
        }
        v72 = get_ipc_log_context(v33);
        ipc_log_string(
          v72,
          "[e][%-4d][%s] debugfs mst_sideband_mode failed, rc=%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(const char **)(v6 + 96),
          inited);
        v58 = &unk_21C529;
      }
      else
      {
        v71 = get_ipc_log_context(v32);
        ipc_log_string(
          v71,
          "[e][%-4d][%s] debugfs mst_mode failed, rc=%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(const char **)(v6 + 96),
          inited);
        v58 = &unk_27C6FC;
      }
      goto LABEL_87;
    }
    v36 = *(_QWORD *)(v6 + 96);
    v37 = "[%s] debugfs create mst_con_remove failed, rc=%d\n";
  }
  else
  {
    v36 = *(_QWORD *)(v6 + 96);
    v37 = "[%s] debugfs create mst_con_add failed, rc=%d\n";
  }
  _drm_err(v37, v36, (unsigned int)inited);
  if ( inited )
    goto LABEL_101;
LABEL_51:
  v38 = debugfs_create_file("max_bw_code", 420, v16, v6, &bw_code_fops);
  inited = v38;
  if ( !v38 || v38 >= 0xFFFFFFFFFFFFF001LL )
  {
    v62 = get_ipc_log_context(v38);
    ipc_log_string(
      v62,
      "[e][%-4d][%s] debugfs max_bw_code failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    v63 = &unk_211509;
    goto LABEL_94;
  }
  v39 = debugfs_create_file("max_pclk_khz", 420, v16, v6, &max_pclk_khz_fops);
  inited = v39;
  if ( !v39 || v39 >= 0xFFFFFFFFFFFFF001LL )
  {
    v64 = get_ipc_log_context(v39);
    ipc_log_string(
      v64,
      "[e][%-4d][%s] debugfs max_pclk_khz failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    v63 = &unk_252A01;
    goto LABEL_94;
  }
  debugfs_create_u32("max_lclk_khz", 420, v16, *(_QWORD *)(v6 + 344) + 708LL);
  debugfs_create_u32("lane_count", 420, v16, *(_QWORD *)(v6 + 120) + 900LL);
  debugfs_create_u32("link_bw_code", 420, v16, *(_QWORD *)(v6 + 120) + 904LL);
  debugfs_create_u32("max_bpp", 420, v16, *(_QWORD *)(v6 + 120) + 908LL);
  v40 = debugfs_create_file("mmrm_clk_cb", 420, v16, v6, &mmrm_clk_cb_fops);
  inited = v40;
  if ( !v40 || v40 >= 0xFFFFFFFFFFFFF001LL )
  {
    v67 = get_ipc_log_context(v40);
    ipc_log_string(
      v67,
      "[e][%-4d][%s] debugfs mmrm_clk_cb failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    v63 = &unk_22D4BE;
LABEL_94:
    printk(v63, "dp_debug_init_link");
    if ( inited )
      goto LABEL_101;
  }
  debugfs_create_bool("hdcp_wait_sink_sync", 420, v16, v6 + 163);
  debugfs_create_bool("force_encryption", 420, v16, v6 + 172);
  v41 = debugfs_create_file("hpd", 420, v16, v6, &hpd_fops);
  inited = v41;
  if ( v41 && v41 < 0xFFFFFFFFFFFFF001LL )
  {
    v42 = debugfs_create_file("sim", 420, v16, v6, &sim_fops);
    inited = v42;
    if ( v42 && v42 < 0xFFFFFFFFFFFFF001LL )
    {
      v43 = debugfs_create_file("attention", 420, v16, v6, &attention_fops);
      inited = v43;
      if ( v43 && v43 < 0xFFFFFFFFFFFFF001LL )
      {
        debugfs_create_bool("skip_uevent", 420, v16, v6 + 173);
        debugfs_create_bool("force_multi_func", 420, v16, *(_QWORD *)(v6 + 104) + 13LL);
LABEL_64:
        debugfs_create_bool("dsc_feature_enable", 420, v16, *(_QWORD *)(v6 + 344) + 726LL);
        debugfs_create_bool("fec_feature_enable", 420, v16, *(_QWORD *)(v6 + 344) + 727LL);
        v44 = debugfs_create_file("tpg_ctrl", 420, v16, v6, &tpg_fops);
        inited = v44;
        if ( v44 && v44 < 0xFFFFFFFFFFFFF001LL
          || (v69 = get_ipc_log_context(v44),
              ipc_log_string(
                v69,
                "[e][%-4d][%s] debugfs tpg failed, rc=%d\n",
                *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                *(const char **)(v6 + 96),
                inited),
              printk(&unk_226770, "dp_debug_init_tpg"),
              !inited) )
        {
          inited = dp_debug_init_reg_dump(v6, v16);
          if ( !inited )
          {
            dp_debug_init_feature_toggle(v6, v16);
            dp_debug_init_configs(v6, v16);
            debugfs_create_bool("fifo_error_enable", 420, v16, *(_QWORD *)(v6 + 344) + 729LL);
            *(_QWORD *)(*(_QWORD *)(v6 + 128) + 8LL) = v5;
            v45 = *(_QWORD *)(v6 + 344);
            *(_QWORD *)(v6 + 328) = dp_debug_abort;
            *(_QWORD *)(v6 + 336) = dp_debug_set_mst_con;
            dp_debug_p = v6;
            *(_DWORD *)(v6 + 168) = *(_DWORD *)(v45 + 704);
            return v6 + 160;
          }
        }
        goto LABEL_101;
      }
      v70 = get_ipc_log_context(v43);
      ipc_log_string(
        v70,
        "[e][%-4d][%s] debugfs attention failed, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(const char **)(v6 + 96),
        inited);
      v66 = &unk_24EEBB;
    }
    else
    {
      v68 = get_ipc_log_context(v42);
      ipc_log_string(
        v68,
        "[e][%-4d][%s] debugfs sim failed, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(const char **)(v6 + 96),
        inited);
      v66 = &unk_267EDE;
    }
  }
  else
  {
    v65 = get_ipc_log_context(v41);
    ipc_log_string(
      v65,
      "[e][%-4d][%s] debugfs hpd failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(const char **)(v6 + 96),
      inited);
    v66 = &unk_259BD0;
  }
  printk(v66, "dp_debug_init_sim");
  if ( !inited )
    goto LABEL_64;
LABEL_101:
  debugfs_remove(v16);
LABEL_102:
  devm_kfree(*a1);
  return inited;
}
