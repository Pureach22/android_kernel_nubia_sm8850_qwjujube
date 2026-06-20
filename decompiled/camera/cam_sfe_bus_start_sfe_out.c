__int64 __fastcall cam_sfe_bus_start_sfe_out(__int64 a1)
{
  __int64 v1; // x21
  int v2; // w6
  __int64 v4; // x22
  __int64 v5; // x20
  unsigned int v6; // w24
  __int64 v7; // x24
  _DWORD *v8; // x8
  int v9; // w9
  int v10; // w0
  __int64 result; // x0
  __int64 v12; // x0
  int v13; // w0
  __int64 v14; // x6
  __int64 v15; // x0
  int v16; // w0
  _DWORD *v17; // x25
  int v18; // [xsp+1Ch] [xbp-14h] BYREF
  int v19; // [xsp+20h] [xbp-10h] BYREF
  int v20; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_start_sfe_out",
      1511,
      "Invalid input");
    result = 4294967274LL;
    goto LABEL_23;
  }
  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_QWORD *)(v1 + 8);
  if ( v2 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_start_sfe_out",
      1523,
      "Invalid resource state:%d SFE:%d out_type:0x%X",
      v2,
      *(_DWORD *)v4,
      *(_DWORD *)v1);
    result = 4294967283LL;
    goto LABEL_23;
  }
  v5 = *(_QWORD *)(v1 + 16);
  if ( (*(_BYTE *)(v5 + 27448) & 1) == 0 )
  {
    v19 = 0;
    v12 = *(_QWORD *)(v5 + 24);
    v20 = 1 << *(_DWORD *)(v5 + 27560);
    v13 = cam_irq_controller_subscribe_irq(
            v12,
            0,
            (__int64)&v20,
            v5,
            (__int64)cam_sfe_bus_wr_handle_bus_irq,
            0,
            0,
            nullptr,
            0);
    *(_DWORD *)(v5 + 27584) = v13;
    if ( v13 <= 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_subscribe_error_irq",
        2392,
        "Failed to subscribe BUS TOP IRQ");
      *(_DWORD *)(v5 + 27584) = 0;
      result = 4294967282LL;
      goto LABEL_23;
    }
    cam_irq_controller_register_dependent(*(_QWORD *)(v5 + 24), *(_QWORD *)(v5 + 40), (__int64)&v20);
    v14 = *(_QWORD *)(v5 + 27592);
    if ( v14 )
    {
      v15 = *(_QWORD *)(v5 + 40);
      v19 = *(_DWORD *)(v5 + 27464);
      v16 = cam_irq_controller_subscribe_irq(
              v15,
              0,
              (__int64)&v19,
              v5,
              (__int64)&cam_sfe_bus_wr_handle_err_irq_top_half,
              (__int64)cam_sfe_bus_wr_handle_err_irq_bottom_half,
              v14,
              tasklet_bh_api,
              0);
      *(_DWORD *)(v5 + 27588) = v16;
      if ( v16 <= 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_subscribe_error_irq",
          2415,
          "Failed to subscribe BUS Error IRQ");
        *(_DWORD *)(v5 + 27588) = 0;
        result = 4294967282LL;
        goto LABEL_23;
      }
    }
    *(_BYTE *)(v5 + 27448) = 1;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_subscribe_error_irq",
        2422,
        "BUS WR error irq subscribed");
  }
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_start_sfe_out",
      1535,
      "Start SFE:%d out_type:0x%X",
      **(_DWORD **)(v1 + 8),
      *(_DWORD *)v1);
    if ( *(_DWORD *)(v1 + 24) )
    {
LABEL_7:
      v6 = 0;
      do
        cam_sfe_bus_start_wm(*(_QWORD *)(v1 + 32) + 152LL * (int)v6++);
      while ( v6 < *(_DWORD *)(v1 + 24) );
    }
  }
  else if ( *(_DWORD *)(v1 + 24) )
  {
    goto LABEL_7;
  }
  v7 = *(_QWORD *)(v1 + 40);
  v18 = 0;
  v8 = *(_DWORD **)(v7 + 24);
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    v17 = *(_DWORD **)(v7 + 24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_start_comp_grp",
      1134,
      "Start SFE:%d comp_grp:%d streaming state:%d comp_mask:0x%X",
      **((_DWORD **)v8 + 1),
      *v8,
      *(_DWORD *)(v7 + 8),
      v8[9]);
    v8 = v17;
  }
  if ( *(_DWORD *)(v7 + 8) != 4 )
  {
    v9 = v8[1];
    v18 = v9;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_start_comp_grp",
        1145,
        "Start Done SFE:%d comp_grp:%d buf_done_mask:0x%x",
        **((_DWORD **)v8 + 1),
        *v8,
        v9);
    *(_DWORD *)(v7 + 8) = 4;
  }
  if ( (!*(_DWORD *)(v1 + 68) || *(_DWORD *)(v1 + 64))
    && (v10 = cam_irq_controller_subscribe_irq(
                *(_QWORD *)(v4 + 32),
                1u,
                (__int64)&v18,
                a1,
                *(_QWORD *)(a1 + 112),
                *(_QWORD *)(a1 + 120),
                *(_QWORD *)(a1 + 56),
                tasklet_bh_api,
                0),
        *(_DWORD *)(a1 + 64) = v10,
        v10 <= 0) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_start_sfe_out",
      1568,
      "Subscribe IRQ failed for sfe out_res: %d",
      *(_DWORD *)(a1 + 4));
    *(_DWORD *)(a1 + 64) = 0;
    result = 4294967282LL;
  }
  else
  {
    result = 0;
    *(_DWORD *)(a1 + 8) = 4;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
