__int64 __fastcall sde_crtc_init(__int64 a1, __int64 a2)
{
  __int64 v4; // x23
  __int64 v5; // x24
  _QWORD *v6; // x0
  __int64 v7; // x19
  int v8; // w0
  int v9; // w22
  _QWORD *v10; // x0
  __int64 v11; // x12
  __int64 v12; // x11
  _QWORD *v13; // x9
  __int64 v14; // x13
  __int64 v15; // x14
  __int64 (__fastcall *v16)(); // x15
  __int64 v17; // x22
  __int64 v18; // x10
  __int64 v19; // x2
  _QWORD *v20; // x8
  __int64 v21; // x12
  __int64 v22; // x11
  _QWORD *v23; // x9
  __int64 v24; // x13
  __int64 v25; // x14
  __int64 (__fastcall *v26)(); // x15
  __int64 v27; // x22
  __int64 v28; // x10
  __int64 v29; // x2
  _QWORD *v30; // x8
  __int64 (__fastcall **v31)(); // x4
  __int64 v32; // x10
  __int64 v33; // x9
  __int64 v34; // x11
  __int64 **v35; // x1
  __int64 *v36; // x0
  unsigned __int64 v37; // x0
  unsigned int *v38; // x24
  __int64 v39; // x8
  _QWORD *v40; // x25
  __int64 v41; // x0
  __int64 v42; // x21
  unsigned int v43; // w8
  unsigned int v44; // w8
  __int64 v45; // x2
  __int64 node_opts_by_path; // x0
  const char *v47; // x2
  __int64 v48; // x0
  unsigned int v49; // w8
  const char *v50; // x2
  __int64 v51; // x2
  __int64 v52; // x2
  unsigned int v53; // w8
  unsigned int v54; // w8
  unsigned int v55; // w8
  unsigned int v56; // w8
  unsigned int v57; // w8
  __int64 v58; // x2
  void *v59; // x4
  __int64 v60; // x0
  __int64 v61; // x5
  __int64 v62; // x8
  __int64 v63; // x6
  __int64 v64; // x2
  __int64 v65; // x8
  __int64 v66; // x8
  __int64 v67; // x2
  __int64 v68; // x2
  __int64 v69; // x2
  __int64 v70; // x2
  __int64 v71; // x2
  __int64 v72; // x2
  __int64 v73; // x8
  unsigned int v74; // w22
  void *v75; // x0
  int v76; // w20
  unsigned __int64 v84; // x9
  unsigned __int64 v87; // x9
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v89; // [xsp+10h] [xbp-100h]
  __int64 v90; // [xsp+18h] [xbp-F8h]
  __int64 v91; // [xsp+20h] [xbp-F0h]
  __int64 v92; // [xsp+28h] [xbp-E8h]
  __int64 v93; // [xsp+30h] [xbp-E0h]
  __int64 v94; // [xsp+38h] [xbp-D8h]
  __int64 v95; // [xsp+40h] [xbp-D0h]
  __int64 v96; // [xsp+48h] [xbp-C8h]
  __int64 v97; // [xsp+50h] [xbp-C0h]
  __int64 v98; // [xsp+58h] [xbp-B8h]
  __int64 v99; // [xsp+60h] [xbp-B0h]
  __int64 v100; // [xsp+68h] [xbp-A8h]
  __int64 v101; // [xsp+70h] [xbp-A0h]
  __int64 v102; // [xsp+78h] [xbp-98h]
  __int64 v103; // [xsp+80h] [xbp-90h]
  __int64 v104; // [xsp+88h] [xbp-88h]
  __int64 v105; // [xsp+90h] [xbp-80h]
  __int64 v106; // [xsp+98h] [xbp-78h]
  __int64 v107; // [xsp+A0h] [xbp-70h]
  __int64 v108; // [xsp+A8h] [xbp-68h]
  __int64 v109; // [xsp+B0h] [xbp-60h]
  __int64 v110; // [xsp+B8h] [xbp-58h]
  __int64 v111; // [xsp+C0h] [xbp-50h]
  __int64 v112; // [xsp+C8h] [xbp-48h]
  __int64 v113; // [xsp+D0h] [xbp-40h]
  __int64 v114; // [xsp+D8h] [xbp-38h]
  __int64 v115; // [xsp+E0h] [xbp-30h]
  __int64 v116; // [xsp+E8h] [xbp-28h]
  __int64 v117; // [xsp+F0h] [xbp-20h]
  __int64 v118; // [xsp+F8h] [xbp-18h]
  __int64 v119; // [xsp+100h] [xbp-10h]
  __int64 v120; // [xsp+108h] [xbp-8h]

  v120 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 56);
  v5 = *(_QWORD *)(v4 + 8);
  v6 = (_QWORD *)_kmalloc_large_noprof(8456, 3520);
  v7 = (__int64)v6;
  if ( !v6 )
  {
    v7 = -12;
    goto LABEL_142;
  }
  v8 = hfi_crtc_init(v6);
  if ( v8 )
  {
    v9 = v8;
    kfree(v7);
    v7 = v9;
    goto LABEL_142;
  }
  *(_QWORD *)v7 = a1;
  _mutex_init(v7 + 4616, "&sde_crtc->crtc_lock", &sde_crtc_init___key);
  *(_QWORD *)(v7 + 6032) = 0;
  *(_DWORD *)(v7 + 4712) = 0;
  *(_BYTE *)(v7 + 4512) = 0;
  *(_BYTE *)(v7 + 6040) = 0;
  *(_DWORD *)(v7 + 4468) = 1000000;
  v10 = (_QWORD *)_kmalloc_cache_noprof(kthread_unpark, 3264, 8000);
  *(_QWORD *)(v7 + 4472) = v10;
  if ( v10 )
    *v10 = 0;
  else
    printk(&unk_2195B8, "sde_crtc_init");
  v11 = 4776;
  v12 = 0;
  v13 = (_QWORD *)(v7 + 5424);
  v14 = v7 + 4776;
  v15 = 4720;
  v16 = sde_crtc_frame_event_work;
  *(_QWORD *)(v7 + 5424) = v7 + 5424;
  *(_QWORD *)(v7 + 5432) = v7 + 5424;
  *(_QWORD *)(v7 + 4600) = v7 + 4600;
  *(_QWORD *)(v7 + 4608) = v7 + 4600;
  do
  {
    v17 = v7 + v12;
    v18 = v14 + v12;
    *(_QWORD *)(v17 + 4776) = v7 + v12 + v11;
    *(_QWORD *)(v17 + 4784) = v14 + v12;
    v19 = *(_QWORD *)(v7 + 5424);
    if ( *(_QWORD **)(v19 + 8) != v13 || v18 == v19 )
    {
      _list_add_valid_or_report(v14 + v12, v13);
    }
    else
    {
      *(_QWORD *)(v19 + 8) = v18;
      *(_QWORD *)(v17 + 4776) = v19;
      *(_QWORD *)(v17 + 4784) = v13;
      *v13 = v18;
    }
    v20 = (_QWORD *)(v7 + v12);
    v12 += 88;
    v20[594] = 0;
    v20[593] = 0;
    *(_QWORD *)(v17 + v15) = v17 + v15;
    v20[591] = v18 - 56;
    v20[592] = v16;
  }
  while ( v12 != 704 );
  v21 = 5488;
  v22 = 0;
  v23 = (_QWORD *)(v7 + 6016);
  v24 = v7 + 5488;
  v25 = 5440;
  v26 = sde_crtc_vblank_notify_work;
  *(_QWORD *)(v7 + 6016) = v7 + 6016;
  *(_QWORD *)(v7 + 6024) = v7 + 6016;
  do
  {
    v27 = v7 + v22;
    v28 = v24 + v22;
    *(_QWORD *)(v27 + 5488) = v7 + v22 + v21;
    *(_QWORD *)(v27 + 5496) = v24 + v22;
    v29 = *(_QWORD *)(v7 + 6016);
    if ( *(_QWORD **)(v29 + 8) != v23 || v28 == v29 )
    {
      _list_add_valid_or_report(v24 + v22, v23);
    }
    else
    {
      *(_QWORD *)(v29 + 8) = v28;
      *(_QWORD *)(v27 + 5488) = v29;
      *(_QWORD *)(v27 + 5496) = v23;
      *v23 = v28;
    }
    v30 = (_QWORD *)(v7 + v22);
    v22 += 72;
    v30[684] = 0;
    v30[683] = 0;
    *(_QWORD *)(v27 + v25) = v27 + v25;
    v30[681] = v28 - 48;
    v30[682] = v26;
  }
  while ( v22 != 576 );
  if ( (*(_QWORD *)(*(_QWORD *)(v5 + 152) + 22008LL) & 0x1000000LL) != 0 )
    v31 = &sde_crtc_funcs_v1;
  else
    v31 = &sde_crtc_funcs;
  drm_crtc_init_with_planes(a1, v7, a2, 0, v31, 0);
  *(_QWORD *)(v7 + 448) = &sde_crtc_helper_funcs;
  if ( *(_DWORD *)(*(_QWORD *)(v5 + 152) + 52LL) )
  {
    _X8 = (unsigned __int64 *)(v7 + 7928);
    __asm { PRFM            #0x11, [X8] }
    do
      v84 = __ldxr(_X8);
    while ( __stxr(v84 | 1, _X8) );
    _X8 = (unsigned __int64 *)(v7 + 7928);
    __asm { PRFM            #0x11, [X8] }
    do
      v87 = __ldxr(_X8);
    while ( __stxr(v87 | 2, _X8) );
  }
  snprintf((char *)(v7 + 2176), 0xCu, "crtc%u", *(_DWORD *)(v7 + 112));
  v32 = 0;
  *(_DWORD *)(v7 + 7352) = 0;
  v33 = v7 + 7336;
  v34 = v7 + 6056;
  *(_QWORD *)(v7 + 7336) = v7 + 7336;
  *(_QWORD *)(v7 + 7344) = v7 + 7336;
  do
  {
    v35 = *(__int64 ***)(v7 + 7344);
    v36 = (__int64 *)(v34 + v32);
    if ( (__int64 **)(v34 + v32) == v35 || *v35 != (__int64 *)v33 )
    {
      _list_add_valid_or_report(v36, v35);
    }
    else
    {
      *(_QWORD *)(v7 + 7344) = v36;
      *v36 = v33;
      *(_QWORD *)(v7 + v32 + 6064) = v35;
      *v35 = v36;
    }
    v32 += 80;
  }
  while ( v32 != 1280 );
  v37 = sde_fence_init(v7 + 2176, *(unsigned int *)(v7 + 112));
  *(_QWORD *)(v7 + 3232) = v37;
  if ( v37 >= 0xFFFFFFFFFFFFF001LL )
  {
    v76 = v37;
    printk(&unk_256BCE, "sde_crtc_init");
    drm_crtc_cleanup(v7);
    kfree(v7);
    v7 = v76;
    goto LABEL_142;
  }
  msm_property_init(v7 + 2600, v7 + 112, a1, v4 + 4584, v7 + 2728, 31, 5, 7088);
  v38 = *(unsigned int **)(v5 + 152);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  if ( !v38 )
  {
    printk(&unk_25E60F, "sde_crtc_install_properties");
    goto LABEL_132;
  }
  if ( !*(_QWORD *)v7 || (v39 = *(_QWORD *)(*(_QWORD *)v7 + 56LL)) == 0 )
  {
    v75 = &unk_25E167;
LABEL_138:
    printk(v75, "_sde_crtc_get_kms");
    printk(&unk_215A31, "sde_crtc_install_properties");
    goto LABEL_132;
  }
  v40 = *(_QWORD **)(v39 + 8);
  if ( !v40 )
  {
    v75 = &unk_234896;
    goto LABEL_138;
  }
  v41 = vzalloc_noprof(16396);
  v42 = v41;
  if ( v41 )
  {
    sde_kms_info_reset(v41);
    sde_kms_info_add_keyint(v42, "hw_version", *v38);
    sde_kms_info_add_keyint(v42, "max_linewidth", v38[5394]);
    sde_kms_info_add_keyint(v42, "max_blendstages", v38[5395]);
    v43 = v38[4];
    if ( v43 == 2 )
    {
      ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(v42, "qseed_type", "qseed2");
      v43 = v38[4];
      if ( v43 != 3 )
      {
LABEL_41:
        if ( v43 != 22 )
          goto LABEL_43;
        goto LABEL_42;
      }
    }
    else if ( v43 != 3 )
    {
      goto LABEL_41;
    }
    ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(v42, "qseed_type", "qseed3");
    if ( v38[4] != 22 )
    {
LABEL_43:
      v44 = v38[14];
      if ( v44 == 40 )
      {
        ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(
          v42,
          "cac_version",
          "cac_v2");
        if ( v38[14] != 41 )
        {
LABEL_45:
          v45 = v38[1];
          if ( !(_DWORD)v45 )
          {
LABEL_47:
            *(_DWORD *)s = 0;
            node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
            if ( node_opts_by_path
              && (of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", s, 1, 0) & 0x80000000) == 0
              && *(_DWORD *)s == 7 )
            {
              v47 = "DDR4";
            }
            else
            {
              v47 = "DDR5";
            }
            v48 = ((__int64 (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(
                    v42,
                    "DDR version",
                    v47);
            if ( (sde_is_custom_client(v48) & 1) != 0 )
            {
              v49 = v38[6];
              if ( v49 == 11 )
              {
                v50 = "smart_dma_v2";
              }
              else
              {
                if ( v49 != 12 )
                  goto LABEL_64;
                v50 = "smart_dma_v2p5";
              }
              ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(
                v42,
                "smart_dma_rev",
                v50);
            }
LABEL_64:
            sde_kms_info_add_keyint(v42, "has_src_split", (*((_QWORD *)v38 + 2751) >> 15) & 1LL);
            sde_kms_info_add_keyint(v42, "has_hdr", (*((_QWORD *)v38 + 2751) >> 19) & 1LL);
            sde_kms_info_add_keyint(v42, "has_hdr_plus", (*((_QWORD *)v38 + 2751) >> 20) & 1LL);
            sde_kms_info_add_keyint(v42, "skip_inline_rot_threshold", (*((_QWORD *)v38 + 2751) >> 29) & 1LL);
            v51 = v38[5403];
            if ( (_DWORD)v51 )
              sde_kms_info_add_keyint(v42, "allowed_dsc_reservation_switch", v51);
            if ( v38[5494] )
              sde_kms_info_add_keyint(v42, "has_uidle", 1);
            ((void (__fastcall *)(__int64, const char *, _QWORD))sde_kms_info_add_keystr)(
              v42,
              "core_ib_ff",
              *((_QWORD *)v38 + 2716));
            ((void (__fastcall *)(__int64, const char *, _QWORD))sde_kms_info_add_keystr)(
              v42,
              "core_clk_ff",
              *((_QWORD *)v38 + 2717));
            ((void (__fastcall *)(__int64, const char *, _QWORD))sde_kms_info_add_keystr)(
              v42,
              "comp_ratio_rt",
              *((_QWORD *)v38 + 2718));
            ((void (__fastcall *)(__int64, const char *, _QWORD))sde_kms_info_add_keystr)(
              v42,
              "comp_ratio_nrt",
              *((_QWORD *)v38 + 2719));
            sde_kms_info_add_keyint(v42, "dest_scale_prefill_lines", v38[5442]);
            sde_kms_info_add_keyint(v42, "undersized_prefill_lines", v38[5440]);
            sde_kms_info_add_keyint(v42, "macrotile_prefill_lines", v38[5443]);
            sde_kms_info_add_keyint(v42, "yuv_nv12_prefill_lines", v38[5444]);
            sde_kms_info_add_keyint(v42, "linear_prefill_lines", v38[5445]);
            sde_kms_info_add_keyint(v42, "downscaling_prefill_lines", v38[5446]);
            sde_kms_info_add_keyint(v42, "xtra_prefill_lines", v38[5441]);
            sde_kms_info_add_keyint(v42, "amortizable_threshold", v38[5447]);
            sde_kms_info_add_keyint(v42, "min_prefill_lines", v38[5448]);
            sde_kms_info_add_keyint(v42, "num_mnoc_ports", v38[5471]);
            sde_kms_info_add_keyint(v42, "axi_bus_width", v38[5470]);
            sde_kms_info_add_keyint(v42, "sec_ui_blendstage", v38[5383]);
            v52 = v38[2];
            if ( (_DWORD)v52 )
              sde_kms_info_add_keyint(v42, "ubwc_bw_calc_ver", v52);
            msm_property_install_range(v7 + 2600, "input_fence_timeout", 0, 0, 10000, 10000, 5);
            msm_property_install_volatile_range(v7 + 2600, "output_fence", 0, 0, -1, 0, 6);
            msm_property_install_range(v7 + 2600, "output_fence_offset", 0, 0, 1, 0, 7);
            msm_property_install_range(v7 + 2600, "core_clk", 0, 0, -1, v40[252], 9);
            msm_property_install_range(v7 + 2600, "core_ab", 0, 0, -1, 1000LL * v38[5427], 10);
            msm_property_install_range(v7 + 2600, "core_ib", 0, 0, -1, 1000LL * v38[5427], 11);
            msm_property_install_range(v7 + 2600, "llcc_ab", 0, 0, -1, 1000LL * v38[5427], 12);
            msm_property_install_range(v7 + 2600, "llcc_ib", 0, 0, -1, 1000LL * v38[5427], 13);
            msm_property_install_range(v7 + 2600, "dram_ab", 0, 0, -1, 1000LL * v38[5427], 14);
            msm_property_install_range(v7 + 2600, "dram_ib", 0, 0, -1, 1000LL * v38[5427], 15);
            msm_property_install_range(v7 + 2600, "rot_prefill_bw", 0, 0, -1, 1000LL * v38[5427], 16);
            msm_property_install_range(v7 + 2600, "rot_clk", 0, 0, -1, v40[252], 17);
            if ( (sde_cesta_is_enabled(**(unsigned int **)(v40[17] + 64LL)) & 1) != 0 )
              msm_property_install_range(v7 + 2600, "ubwc_clk", 0, 0, -1, v40[252], 28);
            v53 = v38[5426];
            if ( v53 )
              sde_kms_info_add_keyint(v42, "max_bandwidth_low", 1000LL * v53);
            v54 = v38[5427];
            if ( v54 )
              sde_kms_info_add_keyint(v42, "max_bandwidth_high", 1000LL * v54);
            v55 = v38[5428];
            if ( v55 )
              sde_kms_info_add_keyint(v42, "min_core_ib", 1000LL * v55);
            v56 = v38[5429];
            if ( v56 )
              sde_kms_info_add_keyint(v42, "min_llcc_ib", 1000LL * v56);
            v57 = v38[5430];
            if ( v57 )
              sde_kms_info_add_keyint(v42, "min_dram_ib", 1000LL * v57);
            v58 = v40[252];
            if ( v58 )
              sde_kms_info_add_keyint(v42, "max_mdp_clk", v58);
            if ( (*((_QWORD *)v38 + 2751) & 0x800000000LL) != 0 )
            {
              v62 = v40[19];
              if ( v62 )
                v63 = *(unsigned __int8 *)(v62 + 20120);
              else
                v63 = 0;
              msm_property_install_enum(
                v7 + 2600,
                "vm_request_state",
                0,
                0,
                &sde_crtc_install_properties_e_vm_req_state,
                3,
                v63,
                24);
              if ( (*((_QWORD *)v38 + 2751) & 0x200) == 0 )
              {
LABEL_86:
                if ( (*((_QWORD *)v38 + 2751) & 0x40) == 0 )
                {
LABEL_87:
                  if ( (*((_QWORD *)v38 + 2751) & 8) == 0 )
                    goto LABEL_96;
                  v59 = &sde_crtc_install_properties_e_cwb_data_points;
                  v60 = v7 + 2600;
                  v61 = 2;
LABEL_95:
                  msm_property_install_enum(v60, "capture_mode", 0, 0, v59, v61, 0, 21);
LABEL_96:
                  msm_property_install_enum(
                    v7 + 2600,
                    "fence_error_handle_flag",
                    0,
                    0,
                    &sde_crtc_install_properties_e_fence_error_handle_flag,
                    2,
                    0,
                    27);
                  msm_property_install_volatile_range(v7 + 2600, "sde_drm_roi_v1", 0, 0, -1, 0, 18);
                  msm_property_install_enum(
                    v7 + 2600,
                    "security_level",
                    0,
                    0,
                    &sde_crtc_install_properties_e_secure_level,
                    2,
                    0,
                    19);
                  if ( (*((_QWORD *)v38 + 2712) & 1) != 0 )
                  {
                    msm_property_install_enum(
                      v7 + 2600,
                      "cache_state",
                      0,
                      0,
                      &sde_crtc_install_properties_e_cache_state,
                      2,
                      0,
                      23);
                    if ( (*((_QWORD *)v38 + 2751) & 2) == 0 )
                    {
LABEL_98:
                      if ( (*((_QWORD *)v38 + 85) & 0x8000) == 0 )
                        goto LABEL_100;
                      goto LABEL_99;
                    }
                  }
                  else if ( (*((_QWORD *)v38 + 2751) & 2) == 0 )
                  {
                    goto LABEL_98;
                  }
                  msm_property_install_volatile_range(v7 + 2600, "dim_layer_v1", 0, 0, -1, 0, 8);
                  sde_kms_info_add_keyint(v42, "dim_layer_v1_max_layers", 7);
                  if ( (*((_QWORD *)v38 + 85) & 0x8000) == 0 )
                  {
LABEL_100:
                    v64 = *((unsigned __int8 *)v38 + 708);
                    if ( (_DWORD)v64 == 1 )
                    {
                      sde_kms_info_add_keyint(v42, "has_dest_scaler", v64);
                      sde_kms_info_add_keyint(v42, "dest_scaler_count", v38[2210]);
                      v65 = *((_QWORD *)v38 + 1113);
                      if ( v65 )
                      {
                        sde_kms_info_add_keyint(v42, "max_dest_scaler_input_width", *(unsigned int *)(v65 + 52));
                        sde_kms_info_add_keyint(
                          v42,
                          "max_dest_scaler_output_width",
                          *(unsigned int *)(*((_QWORD *)v38 + 1113) + 56LL));
                        sde_kms_info_add_keyint(
                          v42,
                          "max_dest_scale_up",
                          *(unsigned int *)(*((_QWORD *)v38 + 1113) + 60LL));
                      }
                      v66 = *((_QWORD *)v38 + 1110);
                      if ( (v66 & 8) != 0 )
                      {
                        msm_property_install_volatile_range(v7 + 2600, "dest_scaler", 0, 0, -1, 0, 20);
                        msm_property_install_blob(v7 + 2600, "ds_lut_ed", 0, 1);
                        msm_property_install_blob(v7 + 2600, "ds_lut_cir", 0, 2);
                        msm_property_install_blob(v7 + 2600, "ds_lut_sep", 0, 3);
                      }
                      else if ( (v66 & 0x400000) != 0 )
                      {
                        msm_property_install_volatile_range(v7 + 2600, "dest_scaler", 0, 0, -1, 0, 20);
                      }
                    }
                    v67 = v38[2040];
                    if ( (_DWORD)v67 )
                    {
                      sde_kms_info_add_keyint(v42, "dspp_count", v67);
                      v68 = v38[4994];
                      if ( (_DWORD)v68 )
                      {
                        sde_kms_info_add_keyint(v42, "spr", v68);
                        sde_kms_info_add_keyint(v42, "has_spr_dither", (*((_QWORD *)v38 + 1025) >> 14) & 1LL);
                      }
                      v69 = v38[4993];
                      if ( (_DWORD)v69 )
                      {
                        sde_kms_info_add_keyint(v42, "rc_count", v69);
                        sde_kms_info_add_keyint(v42, "rc_mem_size", *(unsigned int *)(*((_QWORD *)v38 + 1027) + 540LL));
                      }
                      v70 = v38[4995];
                      if ( (_DWORD)v70 )
                        sde_kms_info_add_keyint(v42, "demura_count", v70);
                      v71 = v38[5027];
                      if ( (_DWORD)v71 && *((_BYTE *)v38 + 20112) == 1 )
                        sde_kms_info_add_keyint(v42, "ai_scaler_count", v71);
                      v72 = v38[5029];
                      if ( (_DWORD)v72 && *((_BYTE *)v38 + 20112) == 1 )
                        sde_kms_info_add_keyint(v42, "abc_count", v72);
                    }
                    sde_kms_info_add_keyint(v42, "dsc_block_count", v38[2598]);
                    msm_property_install_blob(v7 + 2600, "capabilities", 4, 0);
                    sde_kms_info_add_keyint(v42, "use_baselayer_for_stage", (*((_QWORD *)v38 + 2751) >> 13) & 1LL);
                    msm_property_set_blob(v7 + 2600, v7 + 3224, v42, (unsigned int)(*(_DWORD *)(v42 + 0x4000) + 1), 0);
                    if ( v38[1738] && (*((_BYTE *)v38 + 6993) & 4) != 0 )
                    {
                      v73 = *((_QWORD *)v38 + 876);
                      v118 = 0;
                      v119 = 0;
                      v116 = 0;
                      v117 = 0;
                      v114 = 0;
                      v115 = 0;
                      v112 = 0;
                      v113 = 0;
                      v110 = 0;
                      v111 = 0;
                      v108 = 0;
                      v109 = 0;
                      v106 = 0;
                      v107 = 0;
                      v104 = 0;
                      v105 = 0;
                      v102 = 0;
                      v103 = 0;
                      LODWORD(v73) = *(_DWORD *)(v73 + 124);
                      v100 = 0;
                      v101 = 0;
                      v98 = 0;
                      v99 = 0;
                      v74 = WORD1(v73);
                      v96 = 0;
                      v97 = 0;
                      v94 = 0;
                      v95 = 0;
                      v92 = 0;
                      v93 = 0;
                      v90 = 0;
                      v91 = 0;
                      *(_QWORD *)s = 0;
                      v89 = 0;
                      snprintf(s, 0x100u, "%s%d", "noise_layer_v", WORD1(v73));
                      if ( v74 != 1 )
                      {
                        printk(&unk_256DD7, "sde_crtc_install_noise_layer_properties");
                        if ( (*((_QWORD *)v38 + 2751) & 0x4000000000LL) == 0 )
                          goto LABEL_129;
                        goto LABEL_128;
                      }
                      sde_kms_info_add_keyint(v42, "has_noise_layer", 1);
                      msm_property_install_volatile_range(v7 + 2600, s, 0, 0, -1, 0, 25);
                    }
                    if ( (*((_QWORD *)v38 + 2751) & 0x4000000000LL) == 0 )
                    {
LABEL_129:
                      if ( (*(_QWORD *)(v40[19] + 22008LL) & 0x8000000000000LL) != 0 )
                        msm_property_install_enum(
                          v7 + 2600,
                          "display_op_idx",
                          0,
                          0,
                          &sde_crtc_install_properties_e_display_op_idx,
                          3,
                          *(_DWORD *)(*(_QWORD *)(v40[17] + 56LL) + 5912LL) == 1,
                          30);
                      vfree(v42);
                      goto LABEL_132;
                    }
LABEL_128:
                    msm_property_install_range(v7 + 2600, "frame_data", 0, 0, -1, 0, 26);
                    goto LABEL_129;
                  }
LABEL_99:
                  msm_property_install_range(v7 + 2600, "flush_sync_en", 0, 0, 1, 0, 29);
                  goto LABEL_100;
                }
LABEL_94:
                v59 = &sde_crtc_install_properties_e_dcwb_data_points;
                v60 = v7 + 2600;
                v61 = 3;
                goto LABEL_95;
              }
            }
            else if ( (*((_QWORD *)v38 + 2751) & 0x200) == 0 )
            {
              goto LABEL_86;
            }
            msm_property_install_enum(
              v7 + 2600,
              "idle_pc_state",
              0,
              0,
              &sde_crtc_install_properties_e_idle_pc_state,
              3,
              0,
              22);
            if ( (*((_QWORD *)v38 + 2751) & 0x40) == 0 )
              goto LABEL_87;
            goto LABEL_94;
          }
LABEL_46:
          sde_kms_info_add_keyint(v42, "UBWC version", v45);
          sde_kms_info_add_keyint(v42, "UBWC macrotile_mode", v38[5400]);
          sde_kms_info_add_keyint(v42, "UBWC highest banking bit", v38[174]);
          sde_kms_info_add_keyint(v42, "UBWC swizzle", v38[176]);
          goto LABEL_47;
        }
      }
      else if ( v44 != 41 )
      {
        goto LABEL_45;
      }
      ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(
        v42,
        "cac_version",
        "cac_loopback");
      v45 = v38[1];
      if ( !(_DWORD)v45 )
        goto LABEL_47;
      goto LABEL_46;
    }
LABEL_42:
    ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(v42, "qseed_type", "qseed3lite");
    goto LABEL_43;
  }
  printk(&unk_2657A2, "sde_crtc_install_properties");
LABEL_132:
  sde_cp_crtc_init(v7);
  sde_cp_crtc_install_properties(v7);
  *(_WORD *)(v7 + 7472) = 0;
  *(_WORD *)(v7 + 7560) = 0;
  *(_BYTE *)(v7 + 7474) = 0;
  *(_BYTE *)(v7 + 7562) = 0;
  *(_QWORD *)(v7 + 7776) = 0;
  *(_QWORD *)(v7 + 7784) = 0;
  *(_QWORD *)(v7 + 7800) = 0;
  *(_QWORD *)(v7 + 7808) = 0;
  *(_QWORD *)(v7 + 7776) = v7 + 7776;
  *(_QWORD *)(v7 + 7784) = v7 + 7776;
  *(_QWORD *)(v7 + 7792) = _sde_crtc_static_cache_read_work;
  init_timer_key(v7 + 7816, &kthread_delayed_work_timer_fn, 0x200000, 0, 0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "%s: successfully initialized crtc, hwfence_out:%d, hwfence_in:%d\n",
      (const char *)(v7 + 2176),
      *(_DWORD *)(v7 + 7928) & 1,
      ((unsigned int)*(_QWORD *)(v7 + 7928) >> 1) & 1);
LABEL_142:
  _ReadStatusReg(SP_EL0);
  return v7;
}
