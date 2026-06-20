__int64 __fastcall cam_vfe_bus_ver3_start_vfe_out(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x23
  __int64 v4; // x22
  __int64 v5; // x26
  int v6; // w6
  __int64 v7; // x8
  __int64 started; // x0
  __int64 v9; // x20
  _DWORD *v10; // x27
  __int64 v11; // x28
  int v12; // w24
  int v13; // w0
  int v14; // w8
  int v15; // w8
  __int64 result; // x0
  __int64 v17; // x20
  __int64 v18; // x0
  int v19; // w0
  __int64 v20; // x6
  int v21; // w0
  int v22; // w0
  char v23; // w11
  unsigned int v24; // w0
  unsigned int v25; // w0
  int v26; // w9
  int v27; // w8
  __int64 v28; // x0
  int v29; // w8
  __int64 v30; // x20
  int v31; // w0
  const char *v32; // x12
  __int64 v33; // [xsp+28h] [xbp-28h] BYREF
  __int64 v34; // [xsp+30h] [xbp-20h] BYREF
  int v35; // [xsp+3Ch] [xbp-14h] BYREF
  __int64 v36; // [xsp+40h] [xbp-10h]
  __int64 v37; // [xsp+48h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v33 = 0;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_start_vfe_out",
      2373,
      "Invalid input");
    result = 4294967274LL;
LABEL_66:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v1 = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD *)(v1 + 16);
  v4 = *(unsigned int *)(v1 + 12);
  v5 = *(_QWORD *)(*(_QWORD *)(v1 + 56) + 24LL);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_start_vfe_out",
      2383,
      "Start VFE:%u out_type:0x%X",
      *(_DWORD *)(v3 + 8),
      *(_DWORD *)(v1 + 8));
  v6 = *(_DWORD *)(a1 + 8);
  v7 = *(_QWORD *)(v1 + 16);
  if ( v6 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_start_vfe_out",
      2389,
      "Invalid resource state:%d VFE:%u out_type:0x%X",
      v6,
      *(_DWORD *)(v7 + 8),
      *(_DWORD *)(v1 + 8));
    result = 4294967283LL;
    goto LABEL_66;
  }
  if ( (*(_BYTE *)(v7 + 34670) & 1) != 0 )
    goto LABEL_7;
  v17 = *(_QWORD *)(v1 + 24);
  v36 = 0;
  v18 = *(_QWORD *)(v17 + 40);
  v35 = 1 << *(_DWORD *)(v17 + 34740);
  v19 = cam_irq_controller_subscribe_irq(
          v18,
          4u,
          (__int64)&v35,
          v17,
          (__int64)cam_vfe_bus_ver3_handle_bus_irq,
          0,
          0,
          nullptr,
          0);
  *(_DWORD *)(v17 + 34944) = v19;
  if ( v19 <= 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_subscribe_init_irq",
      3643,
      "VFE:%u Failed to subscribe BUS (buf_done) IRQ",
      *(_DWORD *)(v17 + 8));
    *(_DWORD *)(v17 + 34944) = 0;
    result = 4294967282LL;
    goto LABEL_66;
  }
  cam_irq_controller_register_dependent(*(_QWORD *)(v17 + 40), *(_QWORD *)(v17 + 32), (__int64)&v35);
  v20 = *(_QWORD *)(v17 + 34960);
  if ( v20 )
  {
    v21 = cam_irq_controller_subscribe_irq(
            *(_QWORD *)(v17 + 32),
            0,
            (__int64)&bus_error_irq_mask_0,
            v17,
            (__int64)&cam_vfe_bus_ver3_handle_err_irq_top_half,
            (__int64)cam_vfe_bus_ver3_handle_err_irq_bottom_half,
            v20,
            tasklet_bh_api,
            0);
    *(_DWORD *)(v17 + 34952) = v21;
    if ( v21 <= 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver3_subscribe_init_irq",
        3667,
        "VFE:%u Failed to subscribe BUS Error IRQ",
        *(_DWORD *)(v17 + 8));
      *(_DWORD *)(v17 + 34952) = 0;
      result = 4294967282LL;
      goto LABEL_66;
    }
  }
  if ( (*(_BYTE *)(v17 + 34628) & 8) != 0 )
  {
    v22 = cam_irq_controller_subscribe_irq(
            *(_QWORD *)(v17 + 40),
            2u,
            (__int64)&v35,
            v17,
            (__int64)cam_vfe_bus_ver3_handle_rup_irq,
            0,
            0,
            nullptr,
            0);
    *(_DWORD *)(v17 + 34948) = v22;
    if ( v22 <= 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver3_subscribe_init_irq",
        3687,
        "VFE:%u Failed to subscribe BUS (rup) IRQ",
        *(_DWORD *)(v17 + 8));
      *(_DWORD *)(v17 + 34948) = 0;
      result = 4294967282LL;
      goto LABEL_66;
    }
  }
  *(_BYTE *)(v17 + 34670) = 1;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_subscribe_init_irq",
      3694,
      "VFE:%u BUS irq subscribed",
      *(_DWORD *)(v17 + 8));
LABEL_7:
  if ( !*(_DWORD *)(v1 + 32)
    || (cam_vfe_bus_ver3_start_wm(*(_QWORD *)(v1 + 40)), *(_DWORD *)(v1 + 32) <= 1u)
    || (started = cam_vfe_bus_ver3_start_wm(*(_QWORD *)(v1 + 48)), *(_DWORD *)(v1 + 32) <= 2u) )
  {
    v9 = *(_QWORD *)(v1 + 56);
    v34 = 0;
    v10 = *(_DWORD **)(v9 + 24);
    v11 = *((_QWORD *)v10 + 1);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_start_comp_grp",
        1794,
        "Start VFE:%u comp_grp:%d streaming state:%d comp_mask:0x%lX",
        *(_DWORD *)(v11 + 8),
        *v10,
        *(_DWORD *)(v9 + 8),
        *((_QWORD *)v10 + 2));
    if ( *(_DWORD *)(v9 + 8) != 4 )
    {
      if ( *(_BYTE *)(v11 + 34664) == 1 && v10[9] )
      {
        v12 = v10[8];
        v13 = cam_io_r_mb(*(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + 8LL));
        v14 = *v10;
        if ( v12 )
        {
          v15 = 1 << (v14 + 14);
        }
        else
        {
          v23 = v14 + 14;
          v15 = (1 << v14) | v13;
          v13 = 1 << v23;
        }
        cam_io_w_mb(
          v15 | (unsigned int)v13,
          *(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + 8LL));
        v24 = cam_io_r_mb(*(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + 12LL));
        cam_io_w_mb(
          (1 << *v10) | v24,
          *(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + 12LL));
      }
      if ( v10[15] )
      {
        v25 = cam_io_r_mb(*(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + 48LL));
        cam_io_w_mb(
          v10[15] | v25,
          *(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + 48LL));
      }
      v26 = v10[7];
      v27 = v26;
      if ( !v26 )
        v27 = v10[6];
      LODWORD(v34) = v27;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v32 = "Y";
        if ( !*(_BYTE *)(v1 + 133) )
          v32 = "N";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_start_comp_grp",
          1867,
          "Start Done VFE:%u comp_grp:%d mc_based:%s bus_irq_mask_0: 0x%x comp_done_mask:0x%x mc_comp_done_mask:0x%x",
          *(_DWORD *)(*((_QWORD *)v10 + 1) + 8LL),
          *v10,
          v32,
          v27,
          v10[6],
          v26);
      }
      *(_DWORD *)(v9 + 8) = 4;
    }
    if ( *(_DWORD *)(v1 + 76) && !*(_DWORD *)(v1 + 72) )
      goto LABEL_65;
    if ( *(_DWORD *)(v5 + 28) )
    {
      v28 = *(_QWORD *)(v3 + 56);
      if ( !v28 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_start_vfe_out",
          2414,
          "MC comp buf done ctrler is NULL");
        result = 0xFFFFFFFFLL;
        goto LABEL_66;
      }
      started = cam_irq_controller_subscribe_irq(
                  v28,
                  1u,
                  (__int64)&v34,
                  a1,
                  (__int64)cam_vfe_bus_ver3_handle_mc_comp_done_top_half,
                  *(_QWORD *)(a1 + 120),
                  *(_QWORD *)(a1 + 56),
                  tasklet_bh_api,
                  0);
      *(_DWORD *)(v1 + 124) = started;
      if ( (int)started <= 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_start_vfe_out",
          2431,
          "Subscribe  MC comp IRQ failed for VFE out_res %d, VFE:%u",
          *(_DWORD *)(a1 + 4),
          *(_DWORD *)(*(_QWORD *)(v1 + 16) + 8LL));
        *(_DWORD *)(v1 + 124) = 0;
        result = 4294967282LL;
        goto LABEL_66;
      }
    }
    else
    {
      started = cam_irq_controller_subscribe_irq(
                  *(_QWORD *)(v3 + 48),
                  1u,
                  (__int64)&v34,
                  a1,
                  *(_QWORD *)(a1 + 112),
                  *(_QWORD *)(a1 + 120),
                  *(_QWORD *)(a1 + 56),
                  tasklet_bh_api,
                  0);
      *(_DWORD *)(a1 + 64) = started;
      if ( (int)started <= 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_start_vfe_out",
          2448,
          "Subscribe IRQ failed for VFE out_res %d, VFE:%u",
          *(_DWORD *)(a1 + 4),
          *(_DWORD *)(*(_QWORD *)(v1 + 16) + 8LL));
        *(_DWORD *)(a1 + 64) = 0;
        result = 4294967282LL;
        goto LABEL_66;
      }
    }
    v29 = *(_DWORD *)(v1 + 116);
    if ( v29 )
    {
      LODWORD(v34) = 0;
      HIDWORD(v34) = v29;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_start_vfe_out",
          2462,
          "VFE:%u out_type:0x%X %s bus_irq_mask_0:0x%X for Early done",
          *(_DWORD *)(*(_QWORD *)(v1 + 16) + 8LL),
          *(_DWORD *)(v1 + 8),
          (const char *)(*(_QWORD *)(v1 + 40) + 128LL),
          v29);
      started = cam_irq_controller_subscribe_irq(
                  *(_QWORD *)(*(_QWORD *)(v1 + 24) + 32LL),
                  1u,
                  (__int64)&v34,
                  a1,
                  *(_QWORD *)(a1 + 112),
                  *(_QWORD *)(a1 + 120),
                  *(_QWORD *)(*(_QWORD *)(v1 + 24) + 34960LL),
                  tasklet_bh_api,
                  0);
      *(_DWORD *)(v1 + 128) = started;
      if ( (int)started <= 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_start_vfe_out",
          2477,
          "VFE:%u Failed to subscribe Early done IRQ",
          *(_DWORD *)(*(_QWORD *)(v1 + 24) + 8LL));
        *(_DWORD *)(v1 + 128) = 0;
        result = 4294967282LL;
        goto LABEL_66;
      }
    }
    if ( (*(_BYTE *)(v3 + 34665) & 1) == 0 && !(_DWORD)v4 )
    {
      if ( (*(_BYTE *)(v3 + 34628) & 8) == 0 )
      {
LABEL_65:
        result = 0;
        *(_DWORD *)(a1 + 8) = 4;
        goto LABEL_66;
      }
      goto LABEL_60;
    }
    if ( *(_BYTE *)(a1 + 144) != 1 || (*(_BYTE *)(v3 + 34628) & 8) == 0 )
      goto LABEL_65;
    if ( (unsigned int)v4 <= 6 )
    {
LABEL_60:
      v30 = v3 + 34688;
      if ( !*(_DWORD *)(v3 + 34688 + 4 * v4) )
      {
        v33 = (unsigned int)(1 << v4);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_start_vfe_out",
            2497,
            "VFE:%u out_type:0x%X bus_irq_mask_0:0x%X for RUP",
            *(_DWORD *)(*(_QWORD *)(v1 + 16) + 8LL),
            *(_DWORD *)(v1 + 8),
            1 << v4);
        v31 = cam_irq_controller_subscribe_irq(
                *(_QWORD *)(v3 + 32),
                0,
                (__int64)&v33,
                a1,
                (__int64)cam_vfe_bus_ver3_handle_rup_top_half,
                (__int64)cam_vfe_bus_ver3_handle_rup_bottom_half,
                *(_QWORD *)(a1 + 56),
                tasklet_bh_api,
                1u);
        *(_DWORD *)(v30 + 4 * v4) = v31;
        if ( v31 <= 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_start_vfe_out",
            2513,
            "VFE:%u Failed to subscribe RUP IRQ",
            *(_DWORD *)(*(_QWORD *)(v1 + 16) + 8LL));
          *(_DWORD *)(v30 + 4 * v4) = 0;
          result = 4294967282LL;
          goto LABEL_66;
        }
      }
      goto LABEL_65;
    }
  }
  __break(0x5512u);
  return cam_vfe_bus_ver3_stop_vfe_out(started);
}
