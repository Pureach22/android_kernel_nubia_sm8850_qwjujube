__int64 __fastcall sde_connector_init(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        _QWORD *a5,
        char a6,
        unsigned int a7,
        char a8)
{
  __int64 v10; // x22
  __int64 v17; // x19
  int v18; // w27
  __int64 v20; // x23
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 (__fastcall **v24)(); // x8
  int v25; // w3
  __int64 (__fastcall *v26)(__int64, __int64 *, __int64); // x8
  __int64 v27; // x2
  int v28; // w0
  unsigned __int64 v29; // x0
  int v30; // w0
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x27
  __int64 **v34; // x10
  __int64 *v35; // x8
  __int64 v36; // x8
  __int64 v37; // x26
  __int64 v38; // x8
  unsigned int v39; // w8
  unsigned __int64 v40; // x0
  unsigned __int64 v41; // x3
  __int64 v42; // x8
  __int64 v43; // x0
  unsigned __int64 v44; // x0
  __int64 **v45; // x26
  __int64 (__fastcall *v46)(__int64, __int64); // x8
  int v47; // w0
  int v48; // w0
  __int64 **v49; // x25
  __int64 *v50; // x8
  int v51; // w24
  void (__fastcall *v52)(__int64, __int64); // x8
  __int64 v53; // x8
  int v54; // w8
  __int64 v55; // x8
  __int64 *v56; // x9
  __int64 *v57; // x8
  __int64 v58; // x8
  __int64 v59; // x8
  int status; // w0
  void *v61; // x0
  void *v62; // x0
  __int64 v63; // [xsp+10h] [xbp-F0h]
  _QWORD v64[3]; // [xsp+18h] [xbp-E8h] BYREF
  __int64 v65; // [xsp+30h] [xbp-D0h] BYREF
  __int64 v66; // [xsp+38h] [xbp-C8h]
  __int64 v67; // [xsp+40h] [xbp-C0h]
  __int64 v68; // [xsp+48h] [xbp-B8h]
  __int64 v69; // [xsp+50h] [xbp-B0h]
  __int64 v70; // [xsp+58h] [xbp-A8h]
  __int64 v71; // [xsp+60h] [xbp-A0h]
  __int64 v72; // [xsp+68h] [xbp-98h]
  __int64 v73; // [xsp+70h] [xbp-90h]
  __int64 v74; // [xsp+78h] [xbp-88h]
  __int64 v75; // [xsp+80h] [xbp-80h]
  __int64 v76; // [xsp+88h] [xbp-78h]
  __int64 v77; // [xsp+90h] [xbp-70h]
  __int64 v78; // [xsp+98h] [xbp-68h]
  __int64 v79; // [xsp+A0h] [xbp-60h]
  __int64 v80; // [xsp+A8h] [xbp-58h]
  __int64 v81; // [xsp+B0h] [xbp-50h]
  __int64 v82; // [xsp+B8h] [xbp-48h]
  __int64 v83; // [xsp+C0h] [xbp-40h]
  __int64 v84; // [xsp+C8h] [xbp-38h]
  char s[8]; // [xsp+D0h] [xbp-30h] BYREF
  __int64 v86; // [xsp+D8h] [xbp-28h]
  __int64 v87; // [xsp+E0h] [xbp-20h]
  __int64 v88; // [xsp+E8h] [xbp-18h]
  __int64 v89; // [xsp+F0h] [xbp-10h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  if ( !a1 || !a2 || (v10 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    printk(&unk_219F7C, "sde_connector_init");
    v17 = -22;
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(v10 + 8) )
  {
    printk(&unk_2504FE, "sde_connector_init");
    v17 = -22;
    goto LABEL_9;
  }
  v17 = _kmalloc_cache_noprof(kthread_unpark, 3520, 5368);
  if ( !v17 )
  {
    printk(&unk_24CEF0, "sde_connector_init");
    v17 = -12;
    goto LABEL_9;
  }
  v63 = a2;
  *(_DWORD *)(v17 + 2740) = 0;
  v18 = hfi_connector_init(a7, (_QWORD *)v17);
  if ( v18 )
    goto LABEL_8;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v18 = drm_connector_init(a1, v17, &sde_connector_ops, a7);
  if ( v18 )
    goto LABEL_8;
  *(_DWORD *)(v17 + 4352) = 0;
  *(_BYTE *)(v17 + 5128) = a8 & 1;
  *(_QWORD *)(v17 + 2752) = a3;
  *(_DWORD *)(v17 + 2736) = a7;
  *(_QWORD *)(v17 + 2744) = v63;
  *(_QWORD *)(v17 + 2760) = a4;
  *(_QWORD *)(v17 + 3288) = 0;
  *(_DWORD *)(v17 + 3296) = 0;
  *(_BYTE *)(v17 + 4518) = 0;
  v20 = *(_QWORD *)(v10 + 8);
  v21 = 1712;
  if ( !*(_QWORD *)(v20 + 1768) )
    v21 = 1704;
  v22 = 1728;
  v23 = *(_QWORD *)(v20 + v21);
  if ( !*(_QWORD *)(v20 + 1768) )
    v22 = 1720;
  *(_QWORD *)(v17 + 2784) = v23;
  *(_QWORD *)(v17 + 2792) = *(_QWORD *)(v20 + v22);
  if ( a5 && (memcpy((void *)(v17 + 2872), a5, 0x1A0u), a5[28]) && a5[29] )
    v24 = sde_connector_helper_ops_v2;
  else
    v24 = sde_connector_helper_ops;
  v25 = *(_DWORD *)(v17 + 64);
  *(_QWORD *)(v17 + 2088) = v24;
  *(_BYTE *)(v17 + 2080) = a6;
  *(_WORD *)(v17 + 164) = 0;
  snprintf((char *)(v17 + 2800), 0x10u, "conn%u", v25);
  if ( !*(_QWORD *)(v17 + 2760)
    || (v26 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v17 + 2944)) == nullptr )
  {
    printk(&unk_27DE90, "sde_connector_get_info");
    v17 = -22;
    goto LABEL_9;
  }
  v27 = *(_QWORD *)(v17 + 2760);
  if ( *((_DWORD *)v26 - 1) != 81886827 )
    __break(0x8228u);
  v28 = v26(v17, &v65, v27);
  if ( v28 )
  {
    v17 = v28;
    goto LABEL_9;
  }
  if ( (*(_BYTE *)(v63 + 644) & 0x80) != 0 )
  {
    *(_BYTE *)(v17 + 5129) = 1;
  }
  else if ( (*(_BYTE *)(v17 + 5129) & 1) == 0 )
  {
    v29 = sde_fence_init(v17 + 2800, *(unsigned int *)(v17 + 64));
    *(_QWORD *)(v17 + 2864) = v29;
    if ( v29 >= 0xFFFFFFFFFFFFF001LL )
    {
      v18 = v29;
      printk(&unk_256BCE, "sde_connector_init");
LABEL_141:
      drm_connector_cleanup(v17);
LABEL_8:
      kfree(v17);
      v17 = v18;
      goto LABEL_9;
    }
  }
  _mutex_init(v17 + 2816, "&c_conn->lock", &sde_connector_init___key);
  _mutex_init(v17 + 4592, "&c_conn->bl_vrr.bl_lock", &sde_connector_init___key_61);
  v30 = drm_connector_attach_encoder(v17, v63);
  if ( v30 )
  {
    v18 = v30;
    v62 = &unk_25403A;
LABEL_139:
    printk(v62, "sde_connector_init");
LABEL_140:
    sde_fence_deinit(*(_QWORD *)(v17 + 2864));
    goto LABEL_141;
  }
  v31 = *(_QWORD *)v17;
  v87 = 0;
  v88 = 0;
  *(_QWORD *)s = 0;
  v86 = 0;
  if ( !v31 || (v32 = *(_QWORD *)(v31 + 56)) == 0 )
  {
    v61 = &unk_242658;
LABEL_137:
    printk(v61, "sde_connector_get_kms");
    printk(&unk_234896, "sde_backlight_setup");
    v18 = -22;
LABEL_138:
    v62 = &unk_21DFB6;
    goto LABEL_139;
  }
  v33 = *(_QWORD *)(v32 + 8);
  if ( !v33 )
  {
    v61 = &unk_234896;
    goto LABEL_137;
  }
  v34 = (__int64 **)(v17 + 2760);
  if ( *(_QWORD *)(v17 + 2968) && *(_DWORD *)(v17 + 2736) == 16 )
  {
    v35 = (__int64 *)(v17 + 2760);
    if ( *(_BYTE *)(v17 + 5128) == 1 )
      v35 = *v34;
    v36 = *v35;
    if ( v36 )
    {
      v37 = *(_QWORD *)(v36 + 264);
      if ( *(_DWORD *)(v37 + 1472) == 2 || (v38 = *(_QWORD *)(v33 + 152)) == 0 || (*(_BYTE *)(v38 + 20120) & 1) == 0 )
      {
        v39 = *(_DWORD *)(v37 + 1488);
        v64[1] = 0x100000000LL;
        v64[2] = 0;
        LODWORD(v64[0]) = v39 >> 1;
        HIDWORD(v64[0]) = v39;
        snprintf(s, 0x20u, "panel%u-backlight", sde_backlight_setup_display_count);
        v40 = backlight_device_register(s, *(_QWORD *)(a1 + 8), v17, &sde_backlight_device_ops, v64);
        v41 = v40;
        *(_QWORD *)(v17 + 4360) = v40;
        if ( v40 && v40 < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(v17 + 4400) = *(unsigned int *)(v37 + 1488);
          v42 = *(_QWORD *)(v33 + 152);
          if ( !v42 || (*(_BYTE *)(v42 + 20120) & 1) == 0 )
          {
            v43 = *(_QWORD *)(a1 + 8);
            *(_QWORD *)(v17 + 4376) = sde_backlight_cooling_cb;
            v44 = backlight_cdev_register(v43, v41, v17 + 4376);
            *(_QWORD *)(v17 + 4368) = v44;
            if ( !v44 || v44 >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( (_drm_debug & 4) != 0 )
                printk(&unk_23C41F, v44);
              else
                printk(&unk_262AB7, "sde_backlight_setup");
              *(_QWORD *)(v17 + 4368) = 0;
            }
          }
          v34 = (__int64 **)(v17 + 2760);
          ++sde_backlight_setup_display_count;
          goto LABEL_51;
        }
        printk(&unk_235908, "sde_backlight_setup");
        v18 = -19;
        *(_QWORD *)(v17 + 4360) = 0;
        goto LABEL_138;
      }
    }
  }
LABEL_51:
  v45 = v34;
  msm_property_init(v17 + 3312, v17 + 64, a1, v10 + 4832, v17 + 3440, 49, 11, 3960);
  v46 = *(__int64 (__fastcall **)(__int64, __int64))(v17 + 2872);
  if ( v46 )
  {
    if ( *((_DWORD *)v46 - 1) != 282792832 )
      __break(0x8228u);
    v47 = v46(v17, a4);
    if ( v47 )
    {
      v18 = v47;
      v62 = &unk_25407E;
      goto LABEL_139;
    }
  }
  if ( a7 == 16 && (v65 & 0x100000000LL) != 0 )
    sde_connector_register_event(v17, 2u, (__int64)sde_connector_handle_disp_recovery, v17);
  v64[0] = -1;
  msm_property_install_blob(v17 + 3312, "capabilities", 4, 0);
  v48 = sde_connector_set_blob_data(v17, 0, 0);
  if ( v48 )
  {
    v18 = v48;
    printk(&unk_26D0C8, "_sde_connector_install_properties");
    goto LABEL_140;
  }
  msm_property_install_blob(v17 + 3312, "mode_properties", 4, 1);
  if ( a7 == 16 )
  {
    if ( *(_DWORD *)(v17 + 2736) == 16 )
    {
      if ( *(_BYTE *)(v17 + 5128) == 1 )
        v45 = (__int64 **)*v45;
      v49 = (__int64 **)*v45;
      if ( *v45 )
      {
        if ( v49[33] )
        {
          msm_property_install_blob(v17 + 3312, "dimming_bl_lut", 16, 8);
          msm_property_install_range(v17 + 3312, "dimming_dyn_ctrl", 0, 0, -1, 0, 23);
          msm_property_install_range(v17 + 3312, "dimming_min_bl", 0, 0, *((unsigned int *)v49[33] + 372), 0, 24);
          v50 = v49[33];
          if ( v50 )
          {
            if ( *((_DWORD *)v50 + 418) != 1
              || (msm_property_install_blob(v17 + 3312, "hdr_properties", 4, 2),
                  msm_property_set_blob(v17 + 3312, v17 + 4232, v49[33] + 209, 44, 2),
                  (v50 = v49[33]) != nullptr) )
            {
              if ( *((_BYTE *)v50 + 1392) == 1 )
                msm_property_install_range(v17 + 3312, "dyn_bit_clk", 0, 0, -1, 0, 22);
            }
          }
        }
      }
    }
    else
    {
      v49 = nullptr;
    }
    msm_property_install_range(v17 + 3312, "dyn_transfer_time", 0, 0, 1000000, 0, 26);
    mutex_lock(*(_QWORD *)v17 + 432LL);
    sde_connector_fill_modes(v17, *(unsigned int *)(a1 + 920), *(unsigned int *)(a1 + 924));
    mutex_unlock(*(_QWORD *)v17 + 432LL);
  }
  else
  {
    v49 = nullptr;
  }
  msm_property_install_volatile_range(v17 + 3312, "sde_drm_roi_v1", 0, 0, -1, 0, 18);
  v87 = 0;
  v88 = 0;
  *(_QWORD *)s = 0;
  v86 = 0;
  if ( v20 )
  {
    v51 = HIWORD(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v20 + 152) + 9672LL) + 140LL));
    snprintf(s, 0x20u, "%s%d", "SDE_PP_DITHER_V", v51);
    if ( (unsigned int)(v51 - 1) > 2 )
      printk(&unk_238BEC, "_sde_connector_install_dither_property");
    else
      msm_property_install_blob(v17 + 3312, s, 16, 4);
  }
  else
  {
    printk(&unk_25F05F, "_sde_connector_install_dither_property");
  }
  if ( a7 == 10 )
  {
    LODWORD(v88) = 0;
    v86 = 0;
    v87 = 0;
    *(_QWORD *)s = 0;
    *(_BYTE *)(v17 + 4746) = 1;
    msm_property_install_blob(v17 + 3312, "ext_hdr_properties", 4, 3);
    msm_property_set_blob(v17 + 3312, v17 + 4240, s, 28, 3);
    v52 = *(void (__fastcall **)(__int64, __int64))(v17 + 3160);
    if ( v52 )
    {
      if ( *((_DWORD *)v52 - 1) != 1811366754 )
        __break(0x8228u);
      v52(a4, v17);
    }
  }
  msm_property_install_volatile_range(v17 + 3312, "hdr_metadata", 0, 0, -1, 0, 6);
  v53 = *(_QWORD *)(v17 + 2744);
  if ( !v53 || (*(_BYTE *)(v53 + 644) & 0x80) == 0 )
  {
    msm_property_install_volatile_range(v17 + 3312, "RETIRE_FENCE", 0, 0, -1, 0, 12);
    msm_property_install_volatile_range(v17 + 3312, "RETIRE_FENCE_OFFSET", 0, 0, -1, 0, 13);
  }
  msm_property_install_range(v17 + 3312, "autorefresh", 0, 0, 6, 0, 30);
  v54 = HIDWORD(v78);
  *(_DWORD *)(v17 + 4712) = HIDWORD(v78);
  if ( (v54 & 0x10000) == 0 && (v54 & 1) != 0 )
  {
    msm_property_install_range(v17 + 3312, "frame_interval", 0, 0, -1, 0, 39);
    msm_property_install_range(v17 + 3312, "usecase_idx", 0, 0, -1, 0, 40);
  }
  if ( a7 == 16 )
  {
    v55 = *(_QWORD *)(v20 + 152);
    if ( v49 )
    {
      if ( (*(_QWORD *)(v55 + 22008) & 0x200000) != 0 )
      {
        v56 = v49[33];
        if ( v56 )
        {
          if ( *((_BYTE *)v56 + 1976) == 1 )
          {
            msm_property_install_enum(v17 + 3312, "qsync_mode", 0, 0, &e_qsync_mode, 3, 0, 33);
            v55 = *(_QWORD *)(v20 + 152);
            if ( (*(_QWORD *)(v55 + 22008) & 0x2000000000LL) != 0 && (v65 & 0x200000000LL) != 0 )
            {
              msm_property_install_range(v17 + 3312, "EPT_FPS", 0, 0, 0xFFFFFFFFLL, 0, 38);
              v55 = *(_QWORD *)(v20 + 152);
            }
          }
        }
      }
    }
    if ( (*(_QWORD *)(v55 + 22008) & 0x400000) != 0 )
    {
      msm_property_install_enum(
        v17 + 3312,
        "avr_step_state",
        0,
        0,
        &sde_connector_install_qsync_properties_e_avr_step_state,
        3,
        0,
        36);
      v55 = *(_QWORD *)(v20 + 152);
    }
    if ( (*(_QWORD *)(v55 + 22008) & 0x1000000000LL) != 0 )
      msm_property_install_range(v17 + 3312, &unk_265FBD, 0, 0, -1, 0, 37);
    msm_property_install_range(v17 + 3312, "zte_aod_bl", 0, 0, 4, 0, 47);
    msm_property_install_range(v17 + 3312, "zte_layer_type", 0, 0, 0xFFFFFFFFLL, 0, 48);
    msm_property_install_enum(v17 + 3312, "dsc_mode", 0, 0, &e_dsc_mode, 3, 0, 42);
    if ( v49 )
    {
      v57 = v49[33];
      if ( v57 )
      {
        if ( (~HIDWORD(v65) & 3) == 0 )
          msm_property_install_enum(v17 + 3312, "panel_mode", 0, 0, &e_panel_mode, 3, *((_DWORD *)v57 + 338) != 1, 35);
      }
    }
    msm_property_install_enum(v17 + 3312, "bpp_mode", 0, 0, &e_bpp_mode, 3, 0, 46);
    if ( (*(_QWORD *)(*(_QWORD *)(v20 + 152) + 22008LL) & 0x800000) != 0 )
    {
      msm_property_install_blob(v17 + 3312, "DEMURA_PANEL_ID", 4, 7);
      msm_property_set_blob(v17 + 3312, v17 + 4264, v64, 8, 7);
    }
  }
  if ( a7 == 15 || (v65 & 0x200000000LL) != 0 )
    msm_property_install_enum(v17 + 3312, "frame_trigger_mode", 0, 0, &e_frame_trigger_mode, 3, 0, 34);
  msm_property_install_range(v17 + 3312, "bl_scale", 0, 0, 1024, 1024, 19);
  msm_property_install_range(v17 + 3312, "sv_bl_scale", 0, 0, 0xFFFFFFFFLL, 0xFFFF, 20);
  *(_BYTE *)(v17 + 4524) = 0;
  *(_QWORD *)(v17 + 4528) = 0xFFFF00000400LL;
  if ( a7 == 10 )
    msm_property_install_range(v17 + 3312, "supported_colorspaces", 4, 0, 0xFFFF, 0, 21);
  msm_property_install_enum(v17 + 3312, "topology_name", 4, 0, &e_topology_name, 17, 0, 28);
  msm_property_install_enum(v17 + 3312, "topology_control", 0, 1, &e_topology_control, 6, 0, 29);
  v58 = *(_QWORD *)(v17 + 2744);
  if ( !v58 || (*(_BYTE *)(v58 + 644) & 0x80) == 0 )
    msm_property_install_enum(v17 + 3312, "LP", 0, 0, &e_power_mode, 4, 0, 31);
  if ( a4 && a7 == 16 )
  {
    v59 = *(_QWORD *)(a4 + 264);
    if ( v59 )
      msm_property_install_range(v17 + 3312, "brightness", 0, 0, *(unsigned int *)(v59 + 1488), 0, 27);
  }
  else if ( a7 != 16 )
  {
    goto LABEL_122;
  }
  if ( (*(_QWORD *)(*(_QWORD *)(v20 + 152) + 22008LL) & 0x800000) != 0
    && (unsigned int)sde_connector_register_event(v17, 4u, (__int64)sde_connector_handle_panel_id, v17) )
  {
    printk(&unk_224A74, "sde_connector_init");
  }
LABEL_122:
  status = msm_property_install_get_status(v17 + 3312);
  if ( status )
  {
    v18 = status;
    printk(&unk_25052E, "sde_connector_init");
    if ( *(_QWORD *)(v17 + 4224) )
      drm_property_blob_put();
    if ( *(_QWORD *)(v17 + 4232) )
      drm_property_blob_put();
    if ( *(_QWORD *)(v17 + 4248) )
      drm_property_blob_put();
    if ( *(_QWORD *)(v17 + 4256) )
      drm_property_blob_put();
    if ( *(_QWORD *)(v17 + 4240) )
      drm_property_blob_put();
    msm_property_destroy(v17 + 3312);
    goto LABEL_140;
  }
  sde_connector_lm_preference(v17, v20, (unsigned int)v72);
  if ( (*(_BYTE *)(v17 + 5129) & 1) == 0 )
  {
    if ( (v78 & 0x10000000000LL) != 0 || (v78 & 0x100000000000000LL) != 0 || *(_DWORD *)(*(_QWORD *)(v20 + 152) + 52LL) )
      *(_BYTE *)(*(_QWORD *)(v20 + 152) + 22140LL) = 1;
    if ( *(_DWORD *)(v17 + 2736) == 15 && *(_DWORD *)(*(_QWORD *)(v20 + 152) + 52LL) )
      *(_BYTE *)(v17 + 5120) = 1;
    *(_QWORD *)(v17 + 4408) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v17 + 4416) = v17 + 4416;
    *(_QWORD *)(v17 + 4424) = v17 + 4416;
    *(_QWORD *)(v17 + 4432) = sde_connector_check_status_work;
    init_timer_key(v17 + 4440, &delayed_work_timer_fn, 0x200000, 0, 0);
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "connector %d attach encoder %d, wb hwfences:%d\n",
      *(_DWORD *)(v17 + 64),
      *(_DWORD *)(v63 + 24),
      *(unsigned __int8 *)(v17 + 5120));
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v17;
}
