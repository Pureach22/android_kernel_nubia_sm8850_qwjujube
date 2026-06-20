__int64 __fastcall cam_vfe_camif_ver3_resource_start(__int64 a1)
{
  __int64 v1; // x6
  __int64 v3; // x21
  __int64 v4; // x8
  __int64 v5; // x20
  unsigned int v6; // w0
  int v7; // w0
  unsigned int v8; // w8
  const char *v9; // x5
  __int64 v10; // x4
  __int64 result; // x0
  int v12; // w8
  _DWORD *v13; // x8
  int v14; // w10
  _DWORD *v15; // x9
  __int64 v16; // x0
  int v17; // w8
  unsigned __int16 v18; // w8
  int v19; // w8
  int v20; // w10
  int v21; // w9
  unsigned int v22; // w8
  unsigned int v23; // w9
  unsigned int v24; // w8
  unsigned int v25; // w20
  char v26; // w8
  unsigned int v27; // w0
  _DWORD *v28; // x8
  int v29; // w10
  int v30; // w10
  int v31; // w0
  __int64 v32; // x8
  char v33; // w9
  int v34; // w0
  int v35; // w0
  unsigned int v36; // w20
  __int64 v37; // [xsp+10h] [xbp-40h]
  _QWORD v38[2]; // [xsp+18h] [xbp-38h] BYREF
  int v39; // [xsp+28h] [xbp-28h]
  __int64 v40; // [xsp+30h] [xbp-20h] BYREF
  __int64 v41; // [xsp+38h] [xbp-18h]
  int v42; // [xsp+40h] [xbp-10h]
  __int64 v43; // [xsp+48h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_resource_start",
      382,
      "Error, Invalid input arguments");
    result = 4294967274LL;
    goto LABEL_64;
  }
  v1 = *(unsigned int *)(a1 + 8);
  if ( (_DWORD)v1 != 2 )
  {
    v9 = "Error, Invalid camif res res_state:%d";
    v10 = 388;
    goto LABEL_9;
  }
  v3 = *(_QWORD *)(a1 + 24);
  v42 = 0;
  v40 = 0;
  v41 = 0;
  v4 = *(_QWORD *)(v3 + 40);
  v38[0] = 0;
  v38[1] = 0;
  v39 = 0;
  v5 = *(_QWORD *)(v4 + 3296);
  if ( !v5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_resource_start",
      400,
      "Error, soc_private NULL");
    result = 4294967277LL;
    goto LABEL_64;
  }
  v6 = cam_io_r(*(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 96LL));
  cam_io_w_mb(
    *(_DWORD *)(*(_QWORD *)(v3 + 32) + 104LL) | v6,
    *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 96LL));
  v7 = cam_io_r_mb(*(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 52LL));
  v8 = *(_DWORD *)(v3 + 22688) - 1;
  if ( v8 <= 1 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL) == 2 )
    {
      v9 = "Error, HVX not available for IFE_%d";
      v10 = 426;
      v1 = 2;
LABEL_9:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_camif_ver3_resource_start",
        v10,
        v9,
        v1);
      result = 4294967274LL;
      goto LABEL_64;
    }
    v7 |= ((*(_DWORD *)(*(_QWORD *)(v3 + 32) + 40LL) & v8) << *(_DWORD *)(*(_QWORD *)(v3 + 32) + 36LL))
        | (1 << *(_DWORD *)(*(_QWORD *)(v3 + 32) + 44LL));
  }
  v12 = *(_DWORD *)(v3 + 22684);
  if ( v12 == 2 )
  {
    v13 = *(_DWORD **)(v3 + 32);
    v7 |= 1 << *v13;
  }
  else
  {
    if ( (unsigned int)(v12 - 1) > 1 )
      goto LABEL_17;
    v13 = *(_DWORD **)(v3 + 32);
  }
  v7 |= 1 << v13[3];
LABEL_17:
  v14 = 1;
  if ( *(_BYTE *)(v3 + 22748) == 1 )
  {
    if ( *(_BYTE *)(v3 + 22749) )
      v14 = 1;
    else
      v14 = 2;
  }
  v15 = *(_DWORD **)(v3 + 32);
  v16 = ~(*(_DWORD *)(v3 + 48) << 30) & 0x40000000
      | ~(*(_DWORD *)(v3 + 52) << 29) & 0x20000000
      | ~(*(_DWORD *)(v3 + 56) << 28) & 0x10000000
      | v7
      | ~(*(_DWORD *)(v3 + 60) << 27) & 0x8000000
      | ((*(_DWORD *)(v3 + 64) & 3) << 25)
      | ((*(_DWORD *)(v3 + 68) & 1) << 10)
      | ((*(_DWORD *)(v3 + 72) & 1) << 9)
      | ((*(_DWORD *)(v3 + 76) & 1) << 8)
      | (32 * (*(_DWORD *)(v3 + 84) & 3))
      | ((*(_DWORD *)(v3 + 88) & 3) << 14)
      | (unsigned int)(v14 << v15[5]);
  if ( *(_DWORD *)(v3 + 22744) )
  {
    v17 = v15[27];
    if ( v17 )
      v16 = (((*(_DWORD *)(v3 + 22740) & v17) + 1) << v15[4]) | (unsigned int)v16;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v37 = v5;
    v36 = v16;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_ver3_resource_start",
      471,
      "VFE:%d TOP core_cfg: 0x%X",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
      v16);
    v16 = v36;
    v5 = v37;
  }
  cam_io_w_mb(v16, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 52LL));
  v1 = *(unsigned int *)(v5 + 4);
  if ( (int)v1 > 5702143 )
  {
    if ( (_DWORD)v1 != 5767424 )
    {
      v18 = 512;
LABEL_32:
      if ( (_DWORD)v1 != (v18 | 0x570000) )
      {
        v9 = "Hardware version not proper: 0x%X";
        v10 = 508;
        goto LABEL_9;
      }
    }
  }
  else if ( (_DWORD)v1 != 4718848 )
  {
    v18 = 256;
    goto LABEL_32;
  }
  v19 = *(_DWORD *)(v3 + 22708);
  v20 = *(_DWORD *)(v3 + 22700);
  v21 = *(_DWORD *)(v3 + 22716) + v19;
  v22 = v19 - v20;
  v23 = (unsigned int)(v21 - v20) >> 2;
  if ( v22 >= 2 * v23 )
    v24 = v23;
  else
    v24 = v22 >> 1;
  if ( *(_DWORD *)(v3 + 22732) || *(_DWORD *)(v3 + 22736) )
    v24 >>= 1;
  v25 = v24 | (*(_DWORD *)(*(_QWORD *)(v3 + 32) + 56LL) << 16);
  cam_io_w_mb(v25, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 36LL));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_ver3_resource_start",
      504,
      "epoch_line_cfg: 0x%X",
      v25);
  *(_DWORD *)(a1 + 8) = 4;
  if ( (*(_BYTE *)(v3 + 22749) & 1) == 0 )
  {
    cam_io_w_mb(
      *(unsigned int *)(*(_QWORD *)(v3 + 32) + 52LL),
      *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 56LL));
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_ver3_resource_start",
        522,
        "VFE:%d CAMIF RUP val:0x%X",
        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
        *(_DWORD *)(*(_QWORD *)(v3 + 32) + 52LL));
  }
  v26 = *(_BYTE *)(v3 + 22728);
  *(_BYTE *)(v3 + 22720) = 0;
  *(_DWORD *)(v3 + 22724) = 0;
  if ( (v26 & 1) != 0 )
  {
    v27 = cam_io_r_mb(*(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 80LL));
    cam_io_w_mb(
      *(_DWORD *)(*(_QWORD *)(v3 + 32) + 92LL) | v27,
      *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 80LL));
  }
  v28 = *(_DWORD **)(v3 + 32);
  v29 = v28[20];
  LODWORD(v40) = v28[19];
  LODWORD(v41) = v29;
  if ( *(_DWORD *)(v3 + 22684) != 2 || !*(_DWORD *)(v3 + 22744) )
  {
    v30 = *(_DWORD *)(v3 + 116);
    HIDWORD(v38[0]) = v28[18] | v28[16];
    if ( !v30 )
    {
      v31 = cam_irq_controller_subscribe_irq(
              *(_QWORD *)(v3 + 128),
              3u,
              (__int64)v38,
              a1,
              *(_QWORD *)(a1 + 112),
              *(_QWORD *)(a1 + 120),
              *(_QWORD *)(a1 + 56),
              tasklet_bh_api,
              0);
      *(_DWORD *)(v3 + 116) = v31;
      if ( v31 <= 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_camif_ver3_resource_start",
          564,
          "IRQ handle subscribe failure");
        *(_DWORD *)(v3 + 116) = 0;
      }
    }
    v32 = *(_QWORD *)(v3 + 32);
    v33 = *(_BYTE *)(v3 + 84);
    HIDWORD(v38[0]) = *(_DWORD *)(v32 + 60);
    if ( (v33 & 3) != 0 )
      LODWORD(v38[0]) = *(_DWORD *)(v32 + 88);
    if ( !*(_DWORD *)(v3 + 120) )
    {
      v34 = cam_irq_controller_subscribe_irq(
              *(_QWORD *)(v3 + 128),
              1u,
              (__int64)v38,
              a1,
              *(_QWORD *)(a1 + 112),
              *(_QWORD *)(a1 + 120),
              *(_QWORD *)(a1 + 56),
              tasklet_bh_api,
              0);
      *(_DWORD *)(v3 + 120) = v34;
      if ( v34 <= 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_camif_ver3_resource_start",
          588,
          "SOF IRQ handle subscribe failure");
        *(_DWORD *)(v3 + 120) = 0;
      }
    }
  }
  if ( !*(_DWORD *)(v3 + 112) )
  {
    v35 = cam_irq_controller_subscribe_irq(
            *(_QWORD *)(v3 + 128),
            0,
            (__int64)&v40,
            a1,
            (__int64)cam_vfe_camif_ver3_err_irq_top_half,
            *(_QWORD *)(a1 + 120),
            *(_QWORD *)(a1 + 56),
            tasklet_bh_api,
            0);
    *(_DWORD *)(v3 + 112) = v35;
    if ( v35 <= 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_camif_ver3_resource_start",
        607,
        "Error IRQ handle subscribe failure");
      *(_DWORD *)(v3 + 112) = 0;
    }
  }
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_ver3_resource_start",
      612,
      "VFE:%d CAMIF Start Done",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
    result = 0;
  }
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
