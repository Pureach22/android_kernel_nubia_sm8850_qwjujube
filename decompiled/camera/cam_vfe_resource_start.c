__int64 __fastcall cam_vfe_resource_start(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x8
  __int64 v4; // x10
  __int64 v5; // x9
  __int64 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x8
  char v10; // w25
  unsigned int v11; // w9
  int v12; // w12
  unsigned int v13; // w10
  int v14; // w25
  unsigned int v15; // w20
  __int64 v16; // x8
  char v17; // w23
  __int64 v18; // x8
  __int64 v19; // x8
  int v20; // w0
  int v21; // w8
  __int64 result; // x0
  int v23; // w8
  unsigned int v24; // w20
  int v25; // w6
  int v26; // w8
  int v27; // w9
  unsigned int v28; // w20
  int v29; // w8
  int v30; // w6
  const char *v31; // x7
  unsigned int v32; // w19
  int v33; // w20
  int v34; // w0
  int v35; // w26
  int v36; // w22
  int v37; // w0
  int v38; // w7
  _QWORD v39[2]; // [xsp+20h] [xbp-50h] BYREF
  int v40; // [xsp+30h] [xbp-40h]
  _QWORD v41[2]; // [xsp+38h] [xbp-38h] BYREF
  int v42; // [xsp+48h] [xbp-28h]
  _QWORD v43[2]; // [xsp+50h] [xbp-20h] BYREF
  int v44; // [xsp+60h] [xbp-10h]
  __int64 v45; // [xsp+68h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_resource_start",
      2614,
      "Error, Invalid input arguments");
    result = 4294967274LL;
    goto LABEL_53;
  }
  if ( *(_DWORD *)(a1 + 8) != 2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_resource_start",
      2620,
      "VFE:%u Error, Invalid camif res res_state:%d",
      *(unsigned int *)(*(_QWORD *)(a1 + 16) + 4LL));
    result = 4294967274LL;
    goto LABEL_53;
  }
  v2 = *(_QWORD *)(a1 + 24);
  v44 = 0;
  v42 = 0;
  v4 = *(_QWORD *)(v2 + 64);
  v3 = *(_QWORD *)(v2 + 72);
  v40 = 0;
  v5 = *(_QWORD *)(v2 + 24);
  v43[0] = 0;
  v43[1] = 0;
  v6 = v2 + 20480;
  v41[0] = 0;
  v41[1] = 0;
  v39[0] = 0;
  v39[1] = 0;
  v7 = cam_io_w_mb(
         *(unsigned int *)(v4 + 28),
         *(_QWORD *)v2 + *(unsigned int *)(v5 + 704) + *(_QWORD *)(*(_QWORD *)(v3 + 16) + 256LL));
  v8 = *(_QWORD *)(*(_QWORD *)(v2 + 72) + 16LL);
  if ( *(_BYTE *)(v8 + 298) == 1 )
    v7 = cam_io_w_mb(
           *(unsigned int *)(*(_QWORD *)(v2 + 24) + 784LL),
           *(_QWORD *)v2 + *(unsigned int *)(*(_QWORD *)(v2 + 24) + 708LL) + *(_QWORD *)(v8 + 264));
  if ( (*(_BYTE *)(v2 + 22810) & 1) == 0 && *(_BYTE *)(v2 + 22811) == 1 )
  {
    v9 = *(_QWORD *)(v2 + 24);
    if ( (*(_BYTE *)(v9 + 780) & 1) == 0 )
    {
      v10 = debug_mdl;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v35 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL);
        v36 = cam_io_r_mb(
                *(_QWORD *)v2
              + *(unsigned int *)(v9 + 64)
              + *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 72) + 16LL) + 256LL));
        v37 = cam_io_r_mb(
                *(_QWORD *)v2
              + *(unsigned int *)(*(_QWORD *)(v2 + 24) + 68LL)
              + *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 72) + 16LL) + 256LL));
        v38 = v36;
        v6 = v2 + 20480;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v10 & 8,
          4,
          "cam_vfe_resource_start",
          2652,
          "VFE:%u TOP core_cfg0: 0x%x core_cfg1: 0x%x",
          v35,
          v38,
          v37);
      }
      v11 = *(_DWORD *)(v6 + 2212);
      if ( (unsigned int)(*(_DWORD *)(v6 + 2248) - 1) >= 0x64 )
        v14 = 50;
      else
        v14 = *(_DWORD *)(v6 + 2248);
      v13 = *(_DWORD *)(v6 + 2220) + v11;
      v12 = *(_DWORD *)(v6 + 2204);
      if ( (v13 - v12) * v14 / 0x64 >= v11 )
        v15 = *(_DWORD *)(v6 + 2212);
      else
        v15 = (v13 - v12) * v14 / 0x64;
      if ( *(_DWORD *)(v6 + 2232) || *(_DWORD *)(v6 + 2236) || *(_BYTE *)(v6 + 2332) == 1 )
        v15 >>= 1;
      v7 = cam_io_w_mb(
             v15,
             *(_QWORD *)v2
           + *(unsigned int *)(*(_QWORD *)(v2 + 24) + 244LL)
           + *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 72) + 16LL) + 256LL));
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        v7 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_vfe_resource_start",
               2674,
               "VFE:%u height [0x%x : 0x%x] vbi_val: 0x%x epoch_factor: %u%% epoch_line_cfg: 0x%x",
               *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
               *(_DWORD *)(v6 + 2204),
               *(_DWORD *)(v6 + 2212),
               *(_DWORD *)(v6 + 2220),
               v14,
               v15);
    }
  }
  v16 = *(_QWORD *)(v2 + 24);
  if ( (*(_BYTE *)(v16 + 780) & 2) != 0 )
  {
    v17 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v33 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL);
      v34 = cam_io_r_mb(
              *(_QWORD *)v2
            + *(unsigned int *)(v16 + 92)
            + *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 72) + 16LL) + 256LL));
      v7 = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v17 & 8,
             4,
             "cam_vfe_resource_start",
             2683,
             "VFE:%u TOP core_mux_cfg: 0x%x",
             v33,
             v34);
    }
  }
  *(_DWORD *)(a1 + 8) = 4;
  *(_DWORD *)(*(_QWORD *)(v2 + 72) + 10772LL) = 0;
  v18 = *(_QWORD *)(v2 + 72);
  *(_BYTE *)(v6 + 2333) = 0;
  *(_DWORD *)(v6 + 2224) = 0;
  if ( (*(_BYTE *)(v18 + 10920) & 1) == 0 )
  {
    if ( *(_DWORD *)(v6 + 2188) == 2 && *(_DWORD *)(v6 + 2244)
      || (*(_BYTE *)(v6 + 2331) & 1) == 0 && *(_BYTE *)(a1 + 144) != 1 )
    {
LABEL_36:
      result = 0;
      if ( *(_DWORD *)(v2 + 100) )
        goto LABEL_46;
LABEL_45:
      v24 = result;
      v26 = cam_irq_controller_subscribe_irq(
              *(_QWORD *)(v2 + 112),
              1u,
              (__int64)v39,
              a1,
              *(_QWORD *)(a1 + 112),
              *(_QWORD *)(a1 + 120),
              *(_QWORD *)(a1 + 56),
              tasklet_bh_api,
              0);
      result = v24;
      *(_DWORD *)(v2 + 104) = v26;
      if ( v26 > 0 )
      {
LABEL_46:
        v27 = *(_DWORD *)(v2 + 96);
        LODWORD(v43[0]) = *(_DWORD *)(*(_QWORD *)(v2 + 64) + 20LL);
        if ( !v27 )
        {
          v28 = result;
          v29 = cam_irq_controller_subscribe_irq(
                  *(_QWORD *)(v2 + 112),
                  0,
                  (__int64)v43,
                  a1,
                  (__int64)cam_vfe_ver4_err_irq_top_half,
                  *(_QWORD *)(a1 + 120),
                  *(_QWORD *)(a1 + 56),
                  tasklet_bh_api,
                  0);
          result = v28;
          *(_DWORD *)(v2 + 96) = v29;
          if ( v29 <= 0 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_resource_start",
              2771,
              "VFE:%u Error IRQ handle subscribe failure",
              *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
            result = 4294967284LL;
            *(_DWORD *)(v2 + 96) = 0;
          }
        }
        *(_DWORD *)(v6 + 2320) = 0;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v30 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL);
          v31 = (const char *)(a1 + 128);
          v32 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_resource_start",
            2781,
            "VFE:%u Res: %s Start Done",
            v30,
            v31);
          result = v32;
        }
        goto LABEL_53;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_resource_start",
        2749,
        "VFE:%u SOF IRQ handle subscribe failed",
        v25);
      *(_DWORD *)(v2 + 104) = 0;
      result = 4294967284LL;
LABEL_53:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( *(_BYTE *)(v6 + 2334) != 1 )
    {
      result = 0;
      goto LABEL_44;
    }
  }
  v19 = *(unsigned int *)(*(_QWORD *)(v2 + 24) + 776LL);
  if ( (unsigned int)v19 < 5 )
  {
    *((_DWORD *)v41 + v19) = *(_DWORD *)(*(_QWORD *)(v2 + 64) + 8LL)
                           | *(_DWORD *)(*(_QWORD *)(v2 + 64) + 4LL)
                           | *(_DWORD *)(*(_QWORD *)(v2 + 64) + 16LL);
    v20 = _sw_hweight32();
    v21 = *(_DWORD *)(v2 + 100);
    *(_DWORD *)(v6 + 2324) = v20;
    if ( v21 )
      goto LABEL_36;
    v23 = cam_irq_controller_subscribe_irq(
            *(_QWORD *)(v2 + 112),
            1u,
            (__int64)v41,
            a1,
            *(_QWORD *)(a1 + 112),
            *(_QWORD *)(a1 + 120),
            *(_QWORD *)(a1 + 56),
            tasklet_bh_api,
            0);
    result = 0;
    *(_DWORD *)(v2 + 100) = v23;
    if ( v23 <= 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_resource_start",
        2728,
        "VFE:%u Frame IRQs handle subscribe failure",
        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
      result = 4294967284LL;
      *(_DWORD *)(v2 + 100) = 0;
      if ( *(_DWORD *)(v2 + 100) )
        goto LABEL_46;
      goto LABEL_45;
    }
LABEL_44:
    if ( *(_DWORD *)(v2 + 100) )
      goto LABEL_46;
    goto LABEL_45;
  }
  __break(0x5512u);
  return cam_vfe_resource_stop(v7);
}
