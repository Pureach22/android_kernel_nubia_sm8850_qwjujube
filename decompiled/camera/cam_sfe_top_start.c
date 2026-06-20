__int64 __fastcall cam_sfe_top_start(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x24
  __int64 v4; // x19
  _QWORD *v5; // x23
  unsigned int v7; // w0
  unsigned int v8; // w19
  const char *v9; // x5
  __int64 v10; // x6
  __int64 v11; // x4
  __int64 result; // x0
  const char *v13; // x5
  __int64 v14; // x4
  unsigned int v15; // w0
  unsigned int v16; // w8
  const char *v17; // x8
  unsigned int started; // w0
  int v19; // w0
  __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x10
  const char **v23; // x9
  int v24; // w9
  int v25; // w10
  int v26; // w24
  unsigned int v27; // w0
  int v28; // w24
  int v29; // w10
  int v30; // w0
  __int64 v31; // x0
  __int64 v32; // x6
  int v33; // w0
  int v34; // w22
  unsigned int v35; // w22
  unsigned int v36; // w11
  __int64 v37; // x12
  int v38; // w13
  _QWORD *v39; // x9
  __int64 v40; // x10
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v45[2]; // [xsp+10h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  if ( !a1 || !a2 )
  {
    v13 = "Invalid args";
    v14 = 1953;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_start",
      v14,
      v13);
    result = 4294967274LL;
    goto LABEL_12;
  }
  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 112LL);
  if ( !v2 )
  {
    v13 = "Invalid input";
    v14 = 1962;
    goto LABEL_11;
  }
  if ( *(_DWORD *)(v2 + 92) != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_start",
      1968,
      "SFE HW [%u] not powered up",
      *(_DWORD *)(v2 + 116));
    result = 0xFFFFFFFFLL;
    goto LABEL_12;
  }
  v4 = *(_QWORD *)(a2 + 24);
  v5 = a1 + 3584;
  v45[0] = 0;
  v7 = ((__int64 (*)(void))cam_sfe_top_calc_hw_clk_rate)();
  if ( v7 )
  {
    v8 = v7;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_apply_clock_start_stop",
      1099,
      "SFE:%d Failed in calculating clock rate rc=%d",
      *(unsigned int *)(a1[1] + 4LL));
LABEL_7:
    *((_DWORD *)v5 + 726) = 0;
    *((_BYTE *)v5 + 3648) = 0;
    v9 = "SFE:%d Failed in applying start clock rc:%d";
    v10 = *(unsigned int *)(v2 + 116);
    v11 = 1977;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_start",
      v11,
      v9,
      v10,
      v8);
    result = v8;
    goto LABEL_12;
  }
  if ( *((_DWORD *)v5 + 726) != 1 )
  {
    v15 = cam_sfe_top_set_hw_clk_rate(a1, v45[0], 1, 0);
    if ( v15 )
    {
      v8 = v15;
      v16 = *((_DWORD *)v5 + 726) - 1;
      if ( v16 > 2 )
        v17 = "Invalid State";
      else
        v17 = off_44E3E8[v16];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_top_apply_clock_start_stop",
        1110,
        "SFE:%d Failed in voting final clk:%lu clk_state:%s",
        *(_DWORD *)(a1[1] + 4LL),
        v45[0],
        v17);
      goto LABEL_7;
    }
  }
  *((_DWORD *)v5 + 726) = 0;
  *((_BYTE *)v5 + 3648) = 0;
  started = cam_sfe_top_apply_bw_start_stop((__int64)a1);
  if ( started )
  {
    v10 = *(unsigned int *)(v2 + 116);
    v9 = "SFE:%d Failed in applying start bw rc:%d";
    v8 = started;
    v11 = 1984;
    goto LABEL_8;
  }
  v19 = cam_io_r_mb(*(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 24) + 20LL));
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    v34 = v19;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_top_start",
      1993,
      "SFE HW [%u] core_cfg: 0x%x",
      *(_DWORD *)(v2 + 116),
      v19);
    v19 = v34;
  }
  v20 = *(_QWORD *)(v4 + 24);
  v21 = a2;
  v22 = *(unsigned int *)(v20 + 160);
  if ( !(_DWORD)v22 )
    goto LABEL_32;
  v23 = (const char **)(*(_QWORD *)(v20 + 152) + 8LL);
  while ( *((_DWORD *)v23 - 2) != v19 )
  {
    --v22;
    v23 += 2;
    if ( !v22 )
      goto LABEL_32;
  }
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_top_start",
      2000,
      "SFE HW [%u] : [%s]",
      *(_DWORD *)(v2 + 116),
      *v23);
    v21 = a2;
    if ( *((_WORD *)v5 + 1795) )
      goto LABEL_33;
  }
  else
  {
LABEL_32:
    if ( *((_WORD *)v5 + 1795) )
      goto LABEL_33;
  }
  cam_io_w(
    *(unsigned int *)(*(_QWORD *)(v4 + 32) + 8LL),
    *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 24) + 136LL));
  v39 = a1;
  v21 = a2;
  if ( !*(_DWORD *)(*(_QWORD *)(v4 + 24) + 176LL) )
    goto LABEL_61;
  v37 = a1[4037];
  v36 = *(_DWORD *)(v37 + 144);
  if ( v36 )
  {
    v38 = *((_DWORD *)v5 + 889);
    v40 = v37 + 152;
    if ( (*(_DWORD *)(v37 + 152) & v38) == 0 && *(_BYTE *)(v37 + 156) != 1 )
      goto LABEL_73;
    v36 = 0;
LABEL_58:
    v37 = 24;
    *((_DWORD *)v5 + 895) = *(_DWORD *)(v40 + 24LL * v36 + 8);
  }
  while ( 1 )
  {
LABEL_59:
    v41 = *((unsigned int *)v5 + 895);
    if ( (_DWORD)v41 )
    {
      cam_io_w(v41, *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 24) + 140LL));
      v39 = a1;
      v21 = a2;
    }
LABEL_61:
    if ( !*(_DWORD *)(v39[2] + 84LL) )
      break;
    v42 = *((unsigned int *)v5 + 891);
    if ( (_DWORD)v42 )
    {
      *((_BYTE *)v5 + 3568) = 1;
      cam_io_w_mb(v42, *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 24) + 88LL));
      v39 = a1;
      v21 = a2;
      if ( (debug_mdl & 0x40000000) != 0 )
      {
        v36 = debug_priority;
        if ( !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_top_start",
            2041,
            "SFE [%u] perf_count_%d: 0x%x",
            *(_DWORD *)(v2 + 116),
            1,
            *((_DWORD *)v5 + 891));
          v39 = a1;
          v21 = a2;
        }
      }
    }
    v40 = *(unsigned int *)(v39[2] + 84LL);
    if ( (unsigned int)v40 < 2 )
      break;
    v43 = *((unsigned int *)v5 + 893);
    if ( (_DWORD)v43 )
    {
      *((_BYTE *)v5 + 3576) = 1;
      cam_io_w_mb(v43, *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 24) + 112LL));
      v40 = debug_mdl;
      v39 = a1;
      v21 = a2;
      if ( (debug_mdl & 0x40000000) != 0 )
      {
        v36 = debug_priority;
        if ( !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_top_start",
            2041,
            "SFE [%u] perf_count_%d: 0x%x",
            *(_DWORD *)(v2 + 116),
            2,
            *((_DWORD *)v5 + 893));
          v39 = a1;
          v21 = a2;
        }
      }
    }
    v39 = (_QWORD *)*(unsigned int *)(v39[2] + 84LL);
    if ( (unsigned int)v39 <= 2 )
      break;
    while ( 1 )
    {
      __break(0x5512u);
LABEL_73:
      if ( v36 == 1 )
        break;
      if ( (*(_DWORD *)(v37 + 176) & v38) != 0 || (v37 = *(unsigned __int8 *)(v37 + 180), (v37 & 1) != 0) )
      {
        v36 = 1;
        goto LABEL_58;
      }
      if ( v36 == 2 )
        goto LABEL_59;
    }
  }
LABEL_33:
  v24 = *((_DWORD *)v5 + 889);
  if ( (v24 & 2) != 0 )
  {
    v25 = *((_DWORD *)v5 + 890);
    if ( (unsigned int)(v25 - 1) > 4 )
    {
      v26 = 0;
      if ( (v24 & 4) == 0 )
        goto LABEL_41;
    }
    else
    {
      v26 = v25 << *(_DWORD *)(*(_QWORD *)(v4 + 32) + 12LL);
      LODWORD(v44) = v26;
      if ( (v24 & 4) == 0 )
      {
LABEL_41:
        v27 = cam_io_r(*(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 24) + 28LL));
        v28 = v26 | *(_DWORD *)(*(_QWORD *)(v4 + 32) + 4LL);
        if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
        {
          v35 = v27;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_top_start",
            2067,
            "Diag config 0x%x",
            v28 | v27);
          v27 = v35;
        }
        cam_io_w(v28 | v27, *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 24) + 28LL));
        v21 = a2;
        goto LABEL_45;
      }
    }
LABEL_40:
    cam_sfe_top_sel_frame_counter(*(_DWORD *)(v21 + 4), &v44, 0, (_QWORD *)v4);
    v26 = v44;
    goto LABEL_41;
  }
  if ( (v24 & 4) != 0 )
    goto LABEL_40;
LABEL_45:
  v29 = *((_DWORD *)v5 + 896);
  LODWORD(v45[0]) = **(_DWORD **)(v4 + 32);
  if ( v29
    || (v30 = cam_irq_controller_subscribe_irq(
                a1[4],
                0,
                (__int64)v45,
                (__int64)a1,
                (__int64)&cam_sfe_top_handle_err_irq_top_half,
                (__int64)cam_sfe_top_handle_err_irq_bottom_half,
                *(_QWORD *)(v21 + 56),
                tasklet_bh_api,
                0),
        v21 = a2,
        *((_DWORD *)v5 + 896) = v30,
        v30 > 0) )
  {
    *((_DWORD *)v5 + 889) |= 1u;
    if ( *(_DWORD *)(v4 + 68)
      || (v31 = a1[4],
          v32 = *(_QWORD *)(v21 + 56),
          HIDWORD(v44) = *(_DWORD *)(*(_QWORD *)(v4 + 48) + 8LL),
          v33 = cam_irq_controller_subscribe_irq(
                  v31,
                  1u,
                  (__int64)&v44 + 4,
                  a2,
                  (__int64)&cam_sfe_top_handle_irq_top_half,
                  (__int64)cam_sfe_top_handle_irq_bottom_half,
                  v32,
                  tasklet_bh_api,
                  0),
          v21 = a2,
          *(_DWORD *)(v4 + 68) = v33,
          v33 > 0) )
    {
      result = 0;
      *(_DWORD *)(v21 + 8) = 4;
      ++*((_WORD *)v5 + 1795);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_top_start",
        2116,
        "Failed to subscribe SOF/EOF IRQ");
      *(_DWORD *)(v4 + 68) = 0;
      result = 4294967282LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_start",
      2088,
      "Failed to subscribe Top IRQ");
    *((_DWORD *)v5 + 896) = 0;
    result = 4294967282LL;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
