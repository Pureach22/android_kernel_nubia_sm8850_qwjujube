__int64 __fastcall cam_vfe_camif_lite_resource_start_0(__int64 a1)
{
  int v1; // w6
  __int64 v3; // x23
  __int64 v4; // x8
  unsigned int v5; // w0
  int v6; // w8
  unsigned int v7; // w20
  int v8; // w8
  __int64 result; // x0
  __int64 v10; // x8
  unsigned int v11; // w0
  int v12; // w10
  int v13; // w8
  int v14; // w9
  unsigned int v15; // w20
  int v16; // w8
  __int64 v17; // x8
  int v18; // w10
  int v19; // w9
  unsigned int v20; // w20
  int v21; // w8
  int v22; // w7
  int v23; // w6
  const char *v24; // x9
  unsigned int v25; // w19
  _QWORD v26[2]; // [xsp+10h] [xbp-30h] BYREF
  int v27; // [xsp+20h] [xbp-20h]
  int v28; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_resource_start",
      259,
      "Invalid input arguments");
    result = 4294967274LL;
    goto LABEL_35;
  }
  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_resource_start",
      265,
      "Invalid camif lite res res_state:%d",
      v1);
    result = 4294967274LL;
    goto LABEL_35;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_resource_start",
      270,
      "CAMIF LITE:%d %s Start",
      *(_DWORD *)(a1 + 4),
      (const char *)(a1 + 128));
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(_QWORD *)(*(_QWORD *)(v3 + 40) + 3296LL);
  if ( !v4 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_resource_start",
      277,
      "Invalid soc_private");
    result = 4294967277LL;
    goto LABEL_35;
  }
  if ( (*(_BYTE *)(v4 + 24) & 1) == 0 )
  {
    v5 = cam_io_r_mb(*(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 52LL));
    v6 = *(_DWORD *)(a1 + 4);
    v7 = v5;
    if ( v6 == 8 )
    {
      v8 = (1 << *(_DWORD *)(*(_QWORD *)(v3 + 32) + 4LL)) | (*(_DWORD *)(v3 + 84) << 31);
    }
    else
    {
      if ( v6 != 9 || *(_DWORD *)(v3 + 48) != 2 )
        goto LABEL_17;
      v8 = 1 << **(_DWORD **)(v3 + 32);
    }
    v7 = v8 | v5;
LABEL_17:
    cam_io_w_mb(v7, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 52LL));
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_resource_start",
        302,
        "VFE:%d core_cfg val:%d",
        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
        v7);
    cam_io_w_mb(
      *(unsigned int *)(*(_QWORD *)(v3 + 32) + 16LL),
      *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 20LL));
    *(_QWORD *)(v3 + 22688) = 0;
    *(_QWORD *)(v3 + 22696) = 0;
    *(_QWORD *)(v3 + 22704) = 0;
    *(_QWORD *)(v3 + 22712) = 0;
    *(_QWORD *)(v3 + 22720) = 0;
    *(_QWORD *)(v3 + 22728) = 0;
    *(_QWORD *)(v3 + 22736) = 0;
    *(_QWORD *)(v3 + 22744) = 0;
  }
  *(_DWORD *)(a1 + 8) = 4;
  cam_io_w_mb(
    *(unsigned int *)(*(_QWORD *)(v3 + 32) + 12LL),
    *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 40LL));
  v10 = *(_QWORD *)(v3 + 24);
  v29 = 0;
  v30 = 0;
  v26[0] = 0;
  v26[1] = 0;
  v27 = 0;
  v11 = cam_io_r(*(_QWORD *)v3 + *(unsigned int *)(v10 + 96));
  cam_io_w_mb(
    *(_DWORD *)(*(_QWORD *)(v3 + 32) + 52LL) | v11,
    *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 96LL));
  result = 0;
  if ( *(_BYTE *)(a1 + 144) == 1 )
  {
    v12 = *(_DWORD *)(v3 + 116);
    HIDWORD(v26[0]) = *(_DWORD *)(*(_QWORD *)(v3 + 32) + 32LL) | *(_DWORD *)(*(_QWORD *)(v3 + 32) + 24LL);
    if ( v12 )
    {
      result = 0;
    }
    else
    {
      v13 = cam_irq_controller_subscribe_irq(
              *(_QWORD *)(v3 + 128),
              3u,
              (__int64)v26,
              a1,
              *(_QWORD *)(a1 + 112),
              *(_QWORD *)(a1 + 120),
              *(_QWORD *)(a1 + 56),
              tasklet_bh_api,
              0);
      result = 0;
      *(_DWORD *)(v3 + 116) = v13;
      if ( v13 <= 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_camif_lite_resource_start",
          353,
          "IRQ handle subscribe failure");
        result = 4294967284LL;
        *(_DWORD *)(v3 + 116) = 0;
      }
    }
    v14 = *(_DWORD *)(v3 + 120);
    HIDWORD(v26[0]) = *(_DWORD *)(*(_QWORD *)(v3 + 32) + 20LL);
    if ( !v14 )
    {
      v15 = result;
      v16 = cam_irq_controller_subscribe_irq(
              *(_QWORD *)(v3 + 128),
              1u,
              (__int64)v26,
              a1,
              *(_QWORD *)(a1 + 112),
              *(_QWORD *)(a1 + 120),
              *(_QWORD *)(a1 + 56),
              tasklet_bh_api,
              0);
      result = v15;
      *(_DWORD *)(v3 + 120) = v16;
      if ( v16 <= 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_camif_lite_resource_start",
          374,
          "IRQ handle subscribe failure");
        result = 4294967284LL;
        *(_DWORD *)(v3 + 120) = 0;
      }
    }
  }
  v17 = *(_QWORD *)(v3 + 32);
  v18 = *(_DWORD *)(v3 + 112);
  v19 = *(_DWORD *)(v17 + 36);
  LODWORD(v17) = *(_DWORD *)(v17 + 40);
  v28 = v19;
  HIDWORD(v29) = v17;
  if ( !v18 )
  {
    v20 = result;
    v21 = cam_irq_controller_subscribe_irq(
            *(_QWORD *)(v3 + 128),
            0,
            (__int64)&v28,
            a1,
            (__int64)cam_vfe_camif_lite_err_irq_top_half_0,
            *(_QWORD *)(a1 + 120),
            *(_QWORD *)(a1 + 56),
            tasklet_bh_api,
            0);
    result = v20;
    *(_DWORD *)(v3 + 112) = v21;
    if ( v21 <= 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_camif_lite_resource_start",
        400,
        "Error IRQ handle subscribe failure");
      result = 4294967284LL;
      *(_DWORD *)(v3 + 112) = 0;
    }
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v22 = *(_DWORD *)(a1 + 4);
    v23 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL);
    v24 = (const char *)(a1 + 128);
    v25 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_resource_start",
      408,
      "VFE:%d CAMIF LITE:%d %s Start Done",
      v23,
      v22,
      v24);
    result = v25;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
