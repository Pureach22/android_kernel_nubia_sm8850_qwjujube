__int64 __fastcall cam_debug_sysfs_node_store(__int64 a1, const char **a2, const char *a3, __int64 a4)
{
  __int64 v5; // x19
  const char *v6; // x6
  char *v7; // x20
  char *v8; // x0
  const char *v9; // x24
  char *v10; // x0
  const char *v11; // x21
  char *v12; // x0
  char *v13; // x23
  const char *v14; // x3
  const char *v15; // x5
  __int64 v16; // x4
  const char *v17; // x5
  __int64 v18; // x4
  const char *v19; // x6
  __int64 v20; // x7
  __int64 v22; // x22
  __int64 *v23; // x8
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  char *stringp[2]; // [xsp+10h] [xbp-10h] BYREF

  v5 = a4;
  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a2;
  v24 = 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    3,
    "cam_debug_sysfs_node_store",
    195,
    "Sysfs debug attr name:[%s] buf:[%s] bytes:[%d]",
    v6,
    a3,
    a4);
  v7 = (char *)kmemdup_noprof(a3, v5 + 1, 3264);
  stringp[0] = v7;
  v8 = strsep(stringp, "#");
  if ( !v8 )
  {
    v17 = "Invalid input driver name buf:[%s], count:%d";
    v18 = 202;
LABEL_11:
    v19 = a3;
    v20 = v5;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_debug_sysfs_node_store",
      v18,
      v17,
      v19,
      v20);
    goto LABEL_13;
  }
  v9 = v8;
  v10 = strsep(stringp, "=");
  if ( !v10 )
  {
    v17 = "Invalid input setting buf:[%s], count:%d";
    v18 = 209;
    goto LABEL_11;
  }
  v11 = v10;
  v12 = strsep(stringp, "=");
  if ( !v12 )
  {
    v17 = "Invalid input value buf:[%s], count:%d";
    v18 = 216;
    goto LABEL_11;
  }
  v13 = v12;
  if ( (kstrtoull(v12, 0, &v24) & 0x80000000) != 0 )
  {
    v17 = "Error converting value:[%s], buf:[%s]";
    v18 = 223;
    v19 = v13;
    v20 = (__int64)a3;
    goto LABEL_12;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    3,
    "cam_debug_sysfs_node_store",
    229,
    "Processing sysfs store for driver:[%s], setting:[%s], value:[%llu]",
    v9,
    v11,
    v24);
  if ( !strcmp(v9, "cpas") )
  {
    v22 = v24;
    if ( !strcmp(v11, "camnoc_bw") )
    {
      v23 = &qword_393EC8;
    }
    else if ( !strcmp(v11, "mnoc_hf_0_ab_bw") )
    {
      v23 = &cam_debug;
    }
    else if ( !strcmp(v11, "mnoc_hf_0_ib_bw") )
    {
      v23 = &qword_393E80;
    }
    else if ( !strcmp(v11, "mnoc_hf_1_ab_bw") )
    {
      v23 = &qword_393E88;
    }
    else if ( !strcmp(v11, "mnoc_hf_1_ib_bw") )
    {
      v23 = &qword_393E90;
    }
    else if ( !strcmp(v11, "mnoc_sf_0_ab_bw") )
    {
      v23 = &qword_393E98;
    }
    else if ( !strcmp(v11, "mnoc_sf_0_ib_bw") )
    {
      v23 = &qword_393EA0;
    }
    else if ( !strcmp(v11, "mnoc_sf_1_ab_bw") )
    {
      v23 = &qword_393EA8;
    }
    else if ( !strcmp(v11, "mnoc_sf_1_ib_bw") )
    {
      v23 = &qword_393EB0;
    }
    else if ( !strcmp(v11, "mnoc_sf_icp_ab_bw") )
    {
      v23 = &qword_393EB8;
    }
    else if ( !strcmp(v11, "mnoc_sf_icp_ib_bw") )
    {
      v23 = &qword_393EC0;
    }
    else if ( !strcmp(v11, "cam_ife_0_drv_ab_high_bw") )
    {
      v23 = &qword_393ED0;
    }
    else if ( !strcmp(v11, "cam_ife_0_drv_ib_high_bw") )
    {
      v23 = &qword_393ED8;
    }
    else if ( !strcmp(v11, "cam_ife_1_drv_ab_high_bw") )
    {
      v23 = &qword_393EE0;
    }
    else if ( !strcmp(v11, "cam_ife_1_drv_ib_high_bw") )
    {
      v23 = &qword_393EE8;
    }
    else if ( !strcmp(v11, "cam_ife_2_drv_ab_high_bw") )
    {
      v23 = &qword_393EF0;
    }
    else if ( !strcmp(v11, "cam_ife_2_drv_ib_high_bw") )
    {
      v23 = &qword_393EF8;
    }
    else if ( !strcmp(v11, "cam_ife_0_drv_ab_low_bw") )
    {
      v23 = &qword_393F00;
    }
    else if ( !strcmp(v11, "cam_ife_0_drv_ib_low_bw") )
    {
      v23 = &qword_393F08;
    }
    else if ( !strcmp(v11, "cam_ife_1_drv_ab_low_bw") )
    {
      v23 = &qword_393F10;
    }
    else if ( !strcmp(v11, "cam_ife_1_drv_ib_low_bw") )
    {
      v23 = &qword_393F18;
    }
    else if ( !strcmp(v11, "cam_ife_2_drv_ab_low_bw") )
    {
      v23 = &qword_393F20;
    }
    else if ( !strcmp(v11, "cam_ife_2_drv_ib_low_bw") )
    {
      v23 = &qword_393F28;
    }
    else if ( !strcmp(v11, "cam_ife_0_drv_low_set_zero") )
    {
      v23 = &qword_393F30;
    }
    else if ( !strcmp(v11, "cam_ife_1_drv_low_set_zero") )
    {
      v23 = &qword_393F38;
    }
    else
    {
      if ( strcmp(v11, "cam_ife_2_drv_low_set_zero") )
      {
        v14 = "cam_debug_parse_cpas_settings";
        v15 = "Unsupported cpas sysfs entry";
        v16 = 176;
        goto LABEL_7;
      }
      v23 = &qword_393F40;
    }
    *v23 = v22;
    byte_393F48 = 1;
    goto LABEL_14;
  }
  v14 = "cam_debug_sysfs_node_store";
  v15 = "Unsupported driver in camera debug node";
  v16 = 236;
LABEL_7:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x20000,
    1,
    v14,
    v16,
    v15);
LABEL_13:
  v5 = -1;
LABEL_14:
  kfree(v7);
  _ReadStatusReg(SP_EL0);
  return v5;
}
