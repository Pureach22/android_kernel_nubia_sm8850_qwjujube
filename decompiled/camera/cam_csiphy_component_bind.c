__int64 __fastcall cam_csiphy_component_bind(__int64 a1)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x0
  __int64 v4; // x19
  __int64 v5; // x8
  unsigned int v6; // w23
  int v7; // w8
  int v8; // w4
  unsigned int v9; // w0
  int v10; // w8
  unsigned int v11; // w0
  const char *v12; // x5
  __int64 v13; // x4
  __int64 v14; // x6
  int v15; // w4
  unsigned int v16; // w0
  unsigned __int64 dir; // x6
  _QWORD v19[2]; // [xsp+8h] [xbp-108h] BYREF
  _QWORD v20[2]; // [xsp+18h] [xbp-F8h] BYREF
  __int64 v21; // [xsp+28h] [xbp-E8h] BYREF
  char s[8]; // [xsp+30h] [xbp-E0h] BYREF
  __int64 v23; // [xsp+38h] [xbp-D8h]
  __int64 v24; // [xsp+40h] [xbp-D0h]
  __int64 v25; // [xsp+48h] [xbp-C8h]
  _QWORD v26[16]; // [xsp+50h] [xbp-C0h] BYREF
  __int64 v27; // [xsp+D0h] [xbp-40h]
  __int64 v28; // [xsp+D8h] [xbp-38h]
  __int64 v29; // [xsp+E0h] [xbp-30h]
  __int64 v30; // [xsp+E8h] [xbp-28h]
  __int64 v31; // [xsp+F0h] [xbp-20h]
  char v32[8]; // [xsp+F8h] [xbp-18h] BYREF
  __int16 v33; // [xsp+100h] [xbp-10h]
  __int64 v34; // [xsp+108h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  memset(v26, 0, sizeof(v26));
  v20[0] = 0;
  v20[1] = 0;
  v19[0] = 0;
  v19[1] = 0;
  ktime_get_real_ts64(v20);
  v3 = devm_kmalloc(v2, a1, 4736, 3520);
  if ( v3 )
  {
    v4 = (__int64)v3;
    _mutex_init(v3 + 3, "&new_csiphy_dev->mutex", &cam_csiphy_component_bind___key);
    v5 = *(_QWORD *)(a1 - 16);
    *(_QWORD *)(v4 + 912) = a1 - 16;
    *(_QWORD *)(v4 + 128) = a1 - 16;
    *(_QWORD *)(v4 + 920) = a1;
    *(_QWORD *)(v4 + 936) = v5;
    *(_DWORD *)(v4 + 120) = 0;
    *(_QWORD *)(v4 + 4488) = 0;
    *(_DWORD *)(v4 + 4496) = 0;
    v6 = cam_csiphy_parse_dt_info(a1 - 16, v4);
    if ( (v6 & 0x80000000) != 0 )
    {
      v12 = "DT parsing failed: %d";
      v13 = 541;
      v14 = v6;
    }
    else
    {
      v7 = *(_DWORD *)(v4 + 932);
      v24 = 0;
      v25 = 0;
      *(_QWORD *)s = 0;
      v23 = 0;
      if ( v7 == 4
        && (((__int64 (__fastcall *)(__int64, __int64, _QWORD))cam_cpas_is_feature_supported)(7, 16, 0) & 1) == 0 )
      {
        v14 = *(unsigned int *)(v4 + 932);
        v12 = "PHY%d is not supported";
        v13 = 552;
      }
      else
      {
        if ( (cam_cpas_query_domain_id_security_support() & 1) != 0 )
          *(_BYTE *)(v4 + 4733) = 1;
        v8 = *(_DWORD *)(v4 + 932);
        *(_QWORD *)(v4 + 528) = &csiphy_subdev_intern_ops;
        *(_QWORD *)(v4 + 520) = &csiphy_subdev_ops;
        snprintf((char *)v4, 0x14u, "%s%d", "cam-csiphy-driver", v8);
        *(_DWORD *)(v4 + 544) = 12;
        *(_QWORD *)(v4 + 568) = cam_csiphy_subdev_handle_message;
        *(_QWORD *)(v4 + 536) = v4;
        *(_DWORD *)(v4 + 560) = 65544;
        *(_QWORD *)(v4 + 552) = v4;
        *(_DWORD *)(v4 + 592) = 1;
        v9 = cam_register_subdev(v4 + 128);
        if ( (v9 & 0x80000000) == 0 )
        {
          *(_QWORD *)(a1 + 152) = v4 + 136;
          *(_QWORD *)(v4 + 604) = 0;
          *(_QWORD *)(v4 + 612) = 0;
          *(_QWORD *)(v4 + 620) = 0xFFFFFFFF00000000LL;
          *(_QWORD *)(v4 + 648) = -1;
          *(_DWORD *)(v4 + 684) = -1;
          *(_QWORD *)(v4 + 752) = -1;
          *(_DWORD *)(v4 + 788) = -1;
          *(_QWORD *)(v4 + 856) = -1;
          *(_DWORD *)(v4 + 892) = -1;
          v10 = *(_DWORD *)(v4 + 932);
          *(_QWORD *)(v4 + 812) = 0;
          *(_QWORD *)(v4 + 820) = 0;
          *(_QWORD *)(v4 + 828) = 0xFFFFFFFF00000000LL;
          LODWORD(v27) = v10;
          *(_BYTE *)(v4 + 602) = 0;
          *(_WORD *)(v4 + 600) = 0;
          *(_WORD *)(v4 + 628) = 0;
          *(_WORD *)(v4 + 688) = 0;
          *(_BYTE *)(v4 + 706) = 0;
          *(_WORD *)(v4 + 704) = 0;
          *(_WORD *)(v4 + 732) = 0;
          *(_QWORD *)(v4 + 724) = 0xFFFFFFFF00000000LL;
          *(_QWORD *)(v4 + 708) = 0;
          *(_QWORD *)(v4 + 716) = 0;
          *(_WORD *)(v4 + 792) = 0;
          *(_BYTE *)(v4 + 810) = 0;
          *(_WORD *)(v4 + 808) = 0;
          *(_WORD *)(v4 + 836) = 0;
          *(_WORD *)(v4 + 896) = 0;
          *(_QWORD *)(v4 + 80) = 0;
          *(_WORD *)(v4 + 4734) = 0;
          *(_QWORD *)(v4 + 4528) = 0;
          *(_QWORD *)(v4 + 4536) = 0;
          *(_QWORD *)(v4 + 4544) = 0;
          v29 = v4;
          v30 = 0;
          v28 = a1;
          strcpy((char *)v26, "csiphy");
          v11 = cam_cpas_register_client((__int64)v26);
          if ( v11 )
          {
            v6 = v11;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x8000,
              1,
              "cam_csiphy_component_bind",
              621,
              "CPAS registration failed rc: %d",
              v11);
LABEL_20:
            cam_unregister_subdev(v4 + 128);
            goto LABEL_21;
          }
          if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              (unsigned __int16)debug_mdl & 0x8000,
              4,
              "cam_csiphy_component_bind",
              626,
              "CPAS registration successful handle=%d",
              v31);
          v15 = *(_DWORD *)(v4 + 932);
          *(_DWORD *)(v4 + 88) = v31;
          snprintf(s, 0x20u, "%s%d%s", "csiphy", v15, "_wq");
          v16 = cam_csiphy_register_baseaddress(v4);
          if ( v16 )
          {
            v6 = v16;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x8000,
              1,
              "cam_csiphy_component_bind",
              634,
              "Failed to register baseaddress, rc: %d",
              v16);
            cam_cpas_unregister_client(*(_DWORD *)(v4 + 88));
            goto LABEL_20;
          }
          if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              (unsigned __int16)debug_mdl & 0x8000,
              4,
              "cam_csiphy_component_bind",
              639,
              "%s component bound successfully",
              *(const char **)(a1 - 16));
          v21 = 0;
          v33 = 0;
          *(_QWORD *)v32 = 0;
          if ( !root_dentry )
          {
            if ( (unsigned int)cam_debugfs_create_subdir("csiphy", (unsigned __int64 *)&v21) )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x8000,
                1,
                "cam_csiphy_debug_register",
                350,
                "Debugfs could not create directory!");
LABEL_32:
              ktime_get_real_ts64(v19);
              cam_record_bind_latency();
              v6 = 0;
              goto LABEL_22;
            }
            root_dentry = v21;
          }
          snprintf(v32, 0xAu, "CSIPHY%d", *(_DWORD *)(v4 + 932));
          dir = debugfs_create_dir(v32, root_dentry);
          v21 = dir;
          if ( dir < 0xFFFFFFFFFFFFF001LL )
          {
            debugfs_create_bool("en_common_status_reg_dump", 420);
            debugfs_create_bool("en_lane_status_reg_dump", 420);
            debugfs_create_bool("en_full_phy_reg_dump", 420);
            debugfs_create_bool("skip_aux_settings", 420);
          }
          else
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x8000,
              1,
              "cam_csiphy_debug_register",
              362,
              "Could not create a debugfs PHY indx subdirectory. rc: %ld",
              dir);
          }
          goto LABEL_32;
        }
        v6 = v9;
        v12 = "cam_register_subdev Failed rc: %d";
        v13 = 583;
        v14 = v9;
      }
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_component_bind",
      v13,
      v12,
      v14);
LABEL_21:
    devm_kfree(a1);
    goto LABEL_22;
  }
  v6 = -12;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v6;
}
