__int64 __fastcall cam_vfe_bus_start_vfe_out(__int64 a1)
{
  __int64 v1; // x26
  __int64 v2; // x20
  int v3; // w6
  int v4; // w8
  __int64 v5; // x27
  unsigned int v6; // w21
  __int64 v7; // x24
  _DWORD *v8; // x20
  __int64 v9; // x23
  int v10; // w19
  int v11; // w8
  int v12; // w9
  unsigned int cpas_hw_version; // w0
  __int64 v14; // x21
  unsigned int *v15; // x22
  __int64 v16; // x0
  __int64 v17; // x1
  unsigned int v18; // w19
  __int64 v19; // x4
  __int64 v20; // x21
  int v21; // w8
  __int64 v22; // x1
  __int64 v23; // x4
  __int64 v24; // x20
  _DWORD *v25; // x21
  __int64 v26; // x22
  int v27; // w8
  __int64 v28; // x1
  unsigned int v29; // w19
  char v30; // w23
  unsigned int v31; // w0
  int v32; // w0
  int v33; // w8
  unsigned int v34; // w19
  int v35; // w23
  __int64 v36; // x10
  __int64 v37; // x0
  int v38; // w0
  __int64 v40; // x19
  __int64 v41; // [xsp+10h] [xbp-30h]
  __int64 v42; // [xsp+18h] [xbp-28h]
  int v43; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v44; // [xsp+28h] [xbp-18h] BYREF
  int v45; // [xsp+30h] [xbp-10h]
  __int64 v46; // [xsp+38h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_start_vfe_out",
      2283,
      "Invalid input");
    v6 = -22;
    goto LABEL_82;
  }
  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(_QWORD *)(v1 + 8);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v40 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_start_vfe_out",
      2290,
      "Start resource index %d",
      *(_DWORD *)v1);
    a1 = v40;
  }
  v3 = *(_DWORD *)(a1 + 8);
  if ( v3 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_start_vfe_out",
      2294,
      "Invalid resource state:%d",
      v3);
    v6 = -13;
    goto LABEL_82;
  }
  v4 = *(_DWORD *)(v1 + 16);
  v45 = 0;
  v44 = 0;
  v41 = v2;
  v42 = a1;
  if ( v4 )
  {
    v5 = 0;
    while ( 1 )
    {
      if ( v5 == 2 )
        __break(0x5512u);
      v7 = *(_QWORD *)(v1 + 24 + 8 * v5);
      v43 = 0;
      v8 = *(_DWORD **)(v7 + 24);
      v9 = *((_QWORD *)v8 + 1);
      v10 = *(unsigned __int8 *)(v9 + 33610);
      cam_io_w(15, *(_QWORD *)(v9 + 8) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 64LL));
      cam_io_w_mb((unsigned int)v8[8], *(_QWORD *)(v9 + 8) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 28LL));
      cam_io_w((unsigned int)v8[9], *(_QWORD *)(v9 + 8) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 32LL));
      cam_io_w((unsigned int)v8[12], *(_QWORD *)(v9 + 8) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 36LL));
      v11 = *v8;
      if ( *v8 <= 2u )
      {
        cam_io_w_mb((unsigned int)v8[10], *(_QWORD *)(v9 + 8) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 40LL));
        v11 = *v8;
      }
      v12 = v8[14];
      HIDWORD(v44) = 1 << v11;
      if ( v12 )
        break;
LABEL_31:
      v21 = debug_priority;
      v22 = debug_mdl & 8;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v22,
          4,
          "cam_vfe_bus_start_wm",
          1294,
          "WM res %d width = %d, height = %d",
          *v8,
          v8[8],
          v8[9]);
        v21 = debug_priority;
        v22 = debug_mdl & 8;
        if ( (debug_mdl & 8) == 0 )
          goto LABEL_36;
      }
      else if ( (debug_mdl & 8) == 0 )
      {
        goto LABEL_36;
      }
      if ( !v21 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v22,
          4,
          "cam_vfe_bus_start_wm",
          1296,
          "WM res %d pk_fmt = %d",
          *v8,
          v8[12] & 0xF);
        v21 = debug_priority;
        v22 = debug_mdl & 8;
      }
LABEL_36:
      if ( v22 && !v21 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v22,
          4,
          "cam_vfe_bus_start_wm",
          1298,
          "WM res %d stride = %d, burst len = %d",
          *v8,
          v8[10],
          15);
        v21 = debug_priority;
        v22 = debug_mdl & 8;
        if ( (debug_mdl & 8) != 0 )
        {
LABEL_39:
          if ( !v21 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v22,
              4,
              "cam_vfe_bus_start_wm",
              1301,
              "enable WM res %d offset 0x%x val 0x%x",
              *v8,
              *(_DWORD *)(*((_QWORD *)v8 + 2) + 8LL),
              v8[28]);
        }
      }
      else if ( v22 )
      {
        goto LABEL_39;
      }
      v6 = 0;
      *(_DWORD *)(v7 + 8) = 4;
LABEL_9:
      if ( ++v5 >= (unsigned __int64)*(unsigned int *)(v1 + 16) )
        goto LABEL_54;
    }
    cpas_hw_version = cam_cpas_get_cpas_hw_version(&v43);
    if ( cpas_hw_version )
    {
      v6 = cpas_hw_version;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_start_wm",
        1228,
        "failed to get HW version rc=%d",
        cpas_hw_version);
      goto LABEL_9;
    }
    if ( v43 == 1462528 || (unsigned int)(v43 - 1) > 0x1750FE )
    {
      if ( ((unsigned int)(v43 - 1528064) > 0x30 || ((1LL << v43) & 0x1000100000003LL) == 0) && v43 != 1462528 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_start_wm",
          1285,
          "Invalid HW version: %d",
          v43);
        v6 = -22;
        goto LABEL_9;
      }
      v20 = *(_QWORD *)(*((_QWORD *)v8 + 2) + 72LL);
      if ( !v20 )
      {
        v23 = 1269;
        goto LABEL_43;
      }
      v15 = (unsigned int *)(v20 + 24);
      v16 = (unsigned int)cam_io_r_mb(*(_QWORD *)(v9 + 8) + *(unsigned int *)(v20 + 24)) | 1;
      if ( !v10 )
        goto LABEL_30;
      v16 = (unsigned int)v16 & ~*(_DWORD *)(v20 + 36);
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_30;
      v17 = debug_mdl & 8;
      v18 = v16;
      v19 = 1279;
    }
    else
    {
      v14 = *(_QWORD *)(*((_QWORD *)v8 + 2) + 72LL);
      if ( !v14 )
      {
        v23 = 1242;
LABEL_43:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_start_wm",
          v23,
          "ubwc_regs is NULL");
        v6 = -22;
        goto LABEL_9;
      }
      v15 = (unsigned int *)(v14 + 24);
      v16 = (unsigned int)cam_io_r_mb(*(_QWORD *)(v9 + 8) + *(unsigned int *)(v14 + 24)) | 1;
      if ( !v10 )
        goto LABEL_30;
      v16 = (unsigned int)v16 & ~*(_DWORD *)(v14 + 32);
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_30;
      v17 = debug_mdl & 8;
      v18 = v16;
      v19 = 1252;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v17,
      4,
      "cam_vfe_bus_start_wm",
      v19,
      "Force disable UBWC compression, ubwc_mode_cfg: 0x%x",
      v18);
    v16 = v18;
LABEL_30:
    cam_io_w_mb(v16, *(_QWORD *)(v9 + 8) + *v15);
    goto LABEL_31;
  }
  v6 = 0;
LABEL_54:
  v24 = *(_QWORD *)(v1 + 40);
  if ( v24 )
  {
    v25 = *(_DWORD **)(v24 + 24);
    v45 = 0;
    v44 = 0;
    v26 = *((_QWORD *)v25 + 1);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_start_comp_grp",
        1782,
        "comp group id:%d streaming state:%d",
        *v25,
        *(_DWORD *)(v24 + 8));
    cam_io_w_mb((unsigned int)v25[11], *(_QWORD *)(v26 + 8) + **((unsigned int **)v25 + 2));
    if ( *(_DWORD *)(v24 + 8) == 4 )
    {
      v6 = 0;
      goto LABEL_79;
    }
    v27 = debug_priority;
    v28 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v28,
        4,
        "cam_vfe_bus_start_comp_grp",
        1789,
        "composite_mask is 0x%x",
        v25[11]);
      v27 = debug_priority;
      v28 = debug_mdl & 8;
      if ( (debug_mdl & 8) != 0 )
      {
LABEL_63:
        if ( !v27 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v28,
            4,
            "cam_vfe_bus_start_comp_grp",
            1791,
            "composite_mask addr 0x%x",
            **((_DWORD **)v25 + 2));
      }
    }
    else if ( (debug_mdl & 8) != 0 )
    {
      goto LABEL_63;
    }
    v29 = *v25 - 6;
    if ( v29 > 5 )
    {
      LODWORD(v44) = 1 << (*v25 + 5);
    }
    else
    {
      v30 = 2 * v29;
      if ( v25[8] )
      {
        v31 = cam_io_r_mb(*(_QWORD *)(v26 + 8) + *(unsigned int *)(*(_QWORD *)(v26 + 40) + 20LL));
        cam_io_w_mb((v25[10] << v30) | v31, *(_QWORD *)(v26 + 8) + *(unsigned int *)(*(_QWORD *)(v26 + 40) + 20LL));
        v45 = 1 << v29;
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_start_comp_grp",
          1819,
          "addr_sync_mask addr 0x%x",
          *(_DWORD *)(*((_QWORD *)v25 + 2) + 4LL));
      cam_io_w_mb((unsigned int)v25[11], *(_QWORD *)(v26 + 8) + *(unsigned int *)(*((_QWORD *)v25 + 2) + 4LL));
      v32 = cam_io_r_mb(*(_QWORD *)(v26 + 8) + *(unsigned int *)(*(_QWORD *)(v26 + 40) + 72LL));
      v33 = v25[12] << v29;
      v34 = v25[10] << (v30 + 8);
      v35 = v33 | v32;
      cam_io_w_mb(v33 | v32 | v34, *(_QWORD *)(v26 + 8) + *(unsigned int *)(*(_QWORD *)(v26 + 40) + 72LL));
      v36 = *(_QWORD *)(v26 + 40);
      v37 = *(_DWORD *)(v26 + 33592) & (unsigned int)~v25[11];
      *(_DWORD *)(v26 + 33592) = v37;
      cam_io_w_mb(v37, *(_QWORD *)(v26 + 8) + *(unsigned int *)(v36 + 80));
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_start_comp_grp",
          1842,
          "addr_sync_cfg: 0x%x addr_no_sync_cfg: 0x%x",
          v35 | v34,
          *(_DWORD *)(v26 + 33592));
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_start_comp_grp",
        1849,
        "VFE start COMP_GRP%d",
        *v25);
    v6 = 0;
    *(_DWORD *)(v24 + 8) = 4;
  }
LABEL_79:
  v38 = cam_irq_controller_subscribe_irq(
          *(_QWORD *)(v41 + 24),
          1u,
          (__int64)&v44,
          v42,
          *(_QWORD *)(v42 + 112),
          *(_QWORD *)(v42 + 120),
          *(_QWORD *)(v42 + 56),
          tasklet_bh_api,
          0);
  *(_DWORD *)(v42 + 64) = v38;
  if ( v38 <= 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_start_vfe_out",
      2317,
      "Subscribe IRQ failed for res_id %d",
      *(_DWORD *)(v42 + 4));
    *(_DWORD *)(v42 + 64) = 0;
    v6 = -14;
  }
  else
  {
    *(_DWORD *)(v42 + 8) = 4;
  }
LABEL_82:
  _ReadStatusReg(SP_EL0);
  return v6;
}
