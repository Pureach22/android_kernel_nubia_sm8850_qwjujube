__int64 __fastcall cam_ife_csid_ver1_start(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v4; // x25
  unsigned int *v5; // x26
  unsigned int v6; // w22
  int is_vc_full_width; // w0
  int v8; // w8
  __int64 v9; // x22
  __int64 v10; // x28
  unsigned int *v11; // x23
  __int64 v12; // x0
  unsigned int v13; // w8
  int *v14; // x9
  int v15; // w10
  int v16; // w11
  unsigned int *v17; // x9
  int v18; // w13
  __int64 v19; // x0
  int v20; // w8
  __int64 v21; // x1
  __int64 v22; // x25
  __int64 i; // x23
  int v24; // w0
  __int64 j; // x23
  int v26; // w0
  int v27; // w0
  int v28; // w0
  int v29; // w0
  int v30; // w0
  int v31; // w0
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x21
  __int64 v37; // x8
  int v38; // w10
  int v39; // w0
  unsigned __int64 v40; // x22
  int *v41; // x8
  const char *v42; // x3
  int v43; // w6
  __int64 v44; // x4
  int v45; // w23
  unsigned int v46; // w26
  int *v47; // x21
  int v48; // w8
  __int64 v49; // x7
  unsigned int v50; // w9
  unsigned int *v51; // x23
  __int64 v52; // x26
  __int64 v53; // x1
  unsigned int *v54; // x7
  const char *v55; // x3
  __int64 v56; // x6
  __int64 v57; // x4
  const char *v58; // x5
  __int64 v59; // x9
  __int64 v60; // x8
  unsigned int v61; // w8
  unsigned int *v62; // x23
  unsigned int v63; // w26
  const char *v64; // x3
  __int64 v65; // x6
  __int64 v66; // x4
  const char *v67; // x5
  unsigned int v68; // w8
  unsigned int v69; // w9
  __int64 v70; // x25

  v2 = *(_QWORD *)(a1 + 3680);
  *(_DWORD *)(v2 + 44) = 0;
  *(_BYTE *)(v2 + 28314) = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_start",
      3014,
      "CSID:%d num_res %u",
      *(_DWORD *)(*(_QWORD *)v2 + 4LL),
      *(_DWORD *)(a2 + 8));
    if ( (*(_BYTE *)(v2 + 28318) & 1) != 0 )
      goto LABEL_32;
  }
  else if ( (*(_BYTE *)(v2 + 28318) & 1) != 0 )
  {
    goto LABEL_32;
  }
  v4 = *(_QWORD *)(v2 + 8);
  v5 = ***(unsigned int ****)(v2 + 16);
  cam_io_w_mb(
    ((*(_DWORD *)(v2 + 28272) - 1) << v5[63])
  | (*(_DWORD *)(v2 + 28276) << v5[64])
  | (unsigned int)((*(_DWORD *)(v2 + 28268) << v5[65]) | (*(_DWORD *)(v2 + 28264) << v5[66])),
    *(_QWORD *)(v4 + 384) + v5[4]);
  v6 = (1 << v5[46]) | (1 << v5[36]);
  is_vc_full_width = cam_ife_csid_is_vc_full_width(v2 + 27016);
  if ( is_vc_full_width == 1 )
  {
    v6 |= 1 << v5[37];
  }
  else if ( is_vc_full_width < 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_enable_csi2",
      2126,
      "Error VC DT");
    goto LABEL_32;
  }
  cam_io_w_mb(v6, *(_QWORD *)(v4 + 384) + v5[5]);
  if ( (unsigned int)cam_ife_csid_ver1_hw_reset(v2) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_enable_csi2",
      2136,
      "CSID[%d] hw reset fail",
      *(_DWORD *)(*(_QWORD *)v2 + 4LL));
  }
  else
  {
    v8 = *(_DWORD *)(v2 + 28392);
    *(_BYTE *)(v2 + 28318) = 1;
    if ( v8 == 0x4000 )
    {
      v9 = *(_QWORD *)(v2 + 8);
      v10 = **(_QWORD **)(v2 + 16);
      v11 = *(unsigned int **)(v10 + 88);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver1_init_tpg_hw",
          1400,
          "CSID:%d TPG config",
          *(_DWORD *)(*(_QWORD *)v2 + 4LL));
      cam_io_w_mb((v11[29] << v11[33]) | *(_DWORD *)(v2 + 80), *(_QWORD *)(v9 + 384) + v11[1]);
      cam_io_w_mb((v11[20] << v11[37]) | (v11[21] << v11[36]), *(_QWORD *)(v9 + 384) + v11[2]);
      cam_io_w_mb(v11[22], *(_QWORD *)(v9 + 384) + v11[3]);
      cam_io_w_mb(
        (unsigned int)((*(_DWORD *)(v2 + 60) << v11[23]) | *(_DWORD *)(v2 + 64)),
        *(_QWORD *)(v9 + 384) + v11[4]);
      cam_io_w_mb(*(unsigned int *)(v2 + 84), *(_QWORD *)(v9 + 384) + *(unsigned int *)(*(_QWORD *)(v10 + 88) + 20LL));
      cam_io_w_mb(
        (*(_DWORD *)(v2 + 72) << v11[25]) | v11[28],
        *(_QWORD *)(v9 + 384) + *(unsigned int *)(*(_QWORD *)(v10 + 88) + 24LL));
      cam_io_w_mb(v11[26] << v11[38], *(_QWORD *)(v9 + 384) + v11[7]);
      cam_io_w_mb(*(unsigned int *)(v2 + 68), *(_QWORD *)(v9 + 384) + v11[9]);
    }
    if ( *(_DWORD *)(v2 + 28292) )
      v12 = (v5[73] | v5[74] | *(_DWORD *)(v2 + 28352)) & 0xF7FFF7FF | 0x8000000;
    else
      v12 = v5[73] | v5[74] | *(_DWORD *)(v2 + 28352) | 0x8000000;
    cam_io_w_mb(v12, *(_QWORD *)(v4 + 384) + v5[1]);
    if ( *(_DWORD *)(v2 + 27064) )
    {
      v13 = 0;
    }
    else if ( *(_DWORD *)(v2 + 27120) )
    {
      v13 = 1;
    }
    else if ( *(_DWORD *)(v2 + 27176) )
    {
      v13 = 2;
    }
    else
    {
      if ( !*(_DWORD *)(v2 + 27232) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_ife_csid_ver1_rx_capture_config",
          1177,
          "CSID[%d] no valid cid",
          *(_DWORD *)(*(_QWORD *)v2 + 4LL));
        goto LABEL_32;
      }
      v13 = 3;
    }
    v14 = (int *)(v2 + 27016 + 56LL * v13);
    v15 = *v14;
    v16 = v14[1];
    v17 = ***(unsigned int ****)(v2 + 16);
    if ( (*(_BYTE *)(v2 + 28332) & 0x10) != 0 )
      v18 = (v15 << v17[43]) | (1 << v17[39]);
    else
      v18 = 0;
    v19 = (1 << v17[38]) | v18 | (v16 << v17[41]) | (unsigned int)(v15 << v17[42]);
    if ( *(_DWORD *)(v2 + 28268) == 1 )
      v19 = (1 << v17[40]) | (v16 << v17[44]) | (v15 << v17[45]) | (unsigned int)v19;
    cam_io_w_mb(v19, *(_QWORD *)(*(_QWORD *)(v2 + 8) + 384LL) + v17[6]);
  }
LABEL_32:
  if ( *(_DWORD *)(v2 + 28392) != 0x4000 || (*(_BYTE *)(v2 + 28319) & 1) != 0 )
    goto LABEL_77;
  v20 = debug_priority;
  v21 = debug_mdl & 8;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v21,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1292,
      "CSID:%d start CSID TPG",
      *(_DWORD *)(*(_QWORD *)v2 + 4LL));
    v20 = debug_priority;
    v21 = debug_mdl & 8;
    v22 = *(_QWORD *)(v2 + 8);
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_39;
  }
  else
  {
    v22 = *(_QWORD *)(v2 + 8);
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_39;
  }
  if ( !v20 )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v21,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1296,
      "================ TPG ============");
LABEL_39:
  for ( i = 0; i != 64; i += 4 )
  {
    v24 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + i + 1536);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_tpg_start",
        1304,
        "reg 0x%x = 0x%x",
        i | 0x600,
        v24);
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1307,
      "================ IPP =============");
  for ( j = 0; j != 40; j += 4 )
  {
    v26 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + j + 512);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_tpg_start",
        1314,
        "reg 0x%x = 0x%x",
        j | 0x200,
        v26);
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1317,
      "================ RX =============");
  v27 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + 256LL);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1324,
      "reg 0x%x = 0x%x",
      256,
      v27);
  v28 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + 260LL);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1324,
      "reg 0x%x = 0x%x",
      260,
      v28);
  v29 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + 264LL);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1324,
      "reg 0x%x = 0x%x",
      264,
      v29);
  v30 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + 268LL);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1324,
      "reg 0x%x = 0x%x",
      268,
      v30);
  v31 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + 272LL);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1324,
      "reg 0x%x = 0x%x",
      272,
      v31);
  v36 = **(_QWORD **)(v2 + 16);
  if ( *(_DWORD *)(v2 + 76)
    && (unsigned int)cam_ife_csid_enable_ife_force_clock_on(
                       v22 + 96,
                       *(_DWORD *)(*(_QWORD *)(v36 + 88) + 76LL),
                       v32,
                       v33,
                       v34,
                       v35) )
  {
    goto LABEL_77;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_start",
      1338,
      "============ TPG control ============");
  v37 = *(_QWORD *)(v36 + 88);
  v38 = *(_DWORD *)(v37 + 124);
  LODWORD(v37) = *(_DWORD *)(v37 + 156);
  *(_BYTE *)(v2 + 28319) = 1;
  cam_io_w_mb(
    (*(_DWORD *)(v2 + 28272) - 1) & (unsigned int)v37 | v38,
    *(_QWORD *)(v22 + 384) + **(unsigned int **)(v36 + 88));
  v39 = cam_io_r_mb(*(_QWORD *)(v22 + 384) + 1536LL);
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
LABEL_77:
    if ( !*(_DWORD *)(a2 + 8) )
    {
LABEL_143:
      v46 = 0;
      *(_BYTE *)(v2 + 28321) = 0;
      return v46;
    }
    goto LABEL_78;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_csid_ver1_tpg_start",
    1348,
    "reg 0x%x = 0x%x",
    1536,
    v39);
  if ( !*(_DWORD *)(a2 + 8) )
    goto LABEL_143;
LABEL_78:
  v40 = 0;
  do
  {
    v47 = *(int **)(*(_QWORD *)a2 + 8 * v40);
    if ( !v47 )
    {
      v48 = -1;
LABEL_134:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_start",
        3026,
        "CSID:%d: res: %p, res type: %d",
        *(_DWORD *)(*(_QWORD *)v2 + 4LL),
        *(const void **)(*(_QWORD *)a2 + 8 * v40),
        v48);
      return (unsigned int)-22;
    }
    v48 = *v47;
    if ( *v47 != 3 )
      goto LABEL_134;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_start",
        3032,
        "CSID:%d res_type :%d res: %s",
        *(_DWORD *)(*(_QWORD *)v2 + 4LL),
        3,
        (const char *)v47 + 128);
    v49 = (unsigned int)v47[1];
    if ( (unsigned int)v49 > 9 )
    {
      v49 = (unsigned int)*v47;
      v64 = "cam_ife_csid_ver1_start";
      v65 = *(unsigned int *)(*(_QWORD *)v2 + 4LL);
      v66 = 3053;
      v67 = "CSID:%d Invalid res type%d";
      goto LABEL_117;
    }
    if ( ((1 << v49) & 0x1F) != 0 )
    {
      v50 = v47[2];
      if ( v50 != 3 )
      {
        v41 = v47;
        v42 = "cam_ife_csid_ver1_start_rdi_path";
        v43 = *(_DWORD *)(*(_QWORD *)v2 + 4LL);
        v44 = 1893;
LABEL_80:
        v45 = 1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          v42,
          v44,
          "CSID:%d %s path res type:%d res_id:%d Invalid state%d",
          v43,
          (const char *)v41 + 128,
          *v41,
          v49,
          v50);
        goto LABEL_81;
      }
      v51 = *(unsigned int **)(**(_QWORD **)(v2 + 16) + 8 * v49 + 24);
      if ( !v51 )
      {
        v64 = "cam_ife_csid_ver1_start_rdi_path";
        v65 = *(unsigned int *)(*(_QWORD *)v2 + 4LL);
        v66 = 1905;
        v67 = "CSID:%d RDI:%d is not supported on HW";
        goto LABEL_117;
      }
      v52 = *(_QWORD *)(*(_QWORD *)(v2 + 8) + 384LL);
      cam_io_w_mb(1, v52 + v51[6]);
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_100;
      v53 = debug_mdl & 8;
      v54 = (unsigned int *)(v47 + 32);
      v55 = "cam_ife_csid_ver1_start_rdi_path";
      v56 = *(unsigned int *)(*(_QWORD *)v2 + 4LL);
      v57 = 1915;
      v58 = "CSID:%d start: %s";
LABEL_132:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned int *))cam_print_log)(
        3,
        v53,
        4,
        v55,
        v57,
        v58,
        v56,
        v54);
LABEL_100:
      cam_io_w_mb(v51[75] | v51[76] | *(_DWORD *)(v2 + 28356) | 2, v52 + v51[1]);
      v45 = 0;
      v46 = 0;
      v47[2] = 4;
      goto LABEL_82;
    }
    if ( ((1 << v49) & 0x380) != 0 )
    {
      v50 = v47[2];
      if ( v50 != 3 )
      {
        v41 = v47;
        v42 = "cam_ife_csid_ver1_start_udi_path";
        v43 = *(_DWORD *)(*(_QWORD *)v2 + 4LL);
        v44 = 1945;
        goto LABEL_80;
      }
      v51 = *(unsigned int **)(**(_QWORD **)(v2 + 16) + 8LL * (unsigned int)(v49 - 7) + 64);
      if ( !v51 )
      {
        v64 = "cam_ife_csid_ver1_start_udi_path";
        v65 = *(unsigned int *)(*(_QWORD *)v2 + 4LL);
        v66 = 1959;
        v67 = "CSID:%d UDI:%d is not supported on HW";
        goto LABEL_117;
      }
      v52 = *(_QWORD *)(*(_QWORD *)(v2 + 8) + 384LL);
      cam_io_w_mb(1, v52 + v51[6]);
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_100;
      v53 = debug_mdl & 8;
      v54 = (unsigned int *)(v47 + 32);
      v55 = "cam_ife_csid_ver1_start_udi_path";
      v56 = *(unsigned int *)(*(_QWORD *)v2 + 4LL);
      v57 = 1969;
      v58 = "CSID:%d Start:%s";
      goto LABEL_132;
    }
    v50 = v47[2];
    if ( v50 != 3 )
    {
      v41 = v47;
      v42 = "cam_ife_csid_ver1_start_pix_path";
      v43 = *(_DWORD *)(*(_QWORD *)v2 + 4LL);
      v44 = 1998;
      goto LABEL_80;
    }
    v59 = **(_QWORD **)(v2 + 16);
    if ( (_DWORD)v49 == 5 )
    {
      if ( !*(_QWORD *)(v59 + 8) )
        goto LABEL_116;
    }
    else if ( (_DWORD)v49 != 6 || !*(_QWORD *)(v59 + 16) )
    {
LABEL_116:
      v64 = "cam_ife_csid_ver1_start_pix_path";
      v65 = *(unsigned int *)(*(_QWORD *)v2 + 4LL);
      v66 = 2013;
      v67 = "CSID:%d PIX:%d is not supported on HW";
LABEL_117:
      v45 = 1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        v64,
        v66,
        v67,
        v65,
        v49);
LABEL_81:
      v46 = -22;
      goto LABEL_82;
    }
    v60 = *((_QWORD *)v47 + 3);
    if ( (_DWORD)v49 == 5 )
    {
      v62 = *(unsigned int **)(v59 + 8);
      v68 = *(_DWORD *)(v60 + 60);
      v69 = v62[58] << v62[59];
      if ( v68 == 2 )
      {
        v63 = (v62[56] << v62[57]) | v69;
        goto LABEL_127;
      }
      if ( v68 == 1 )
      {
        v63 = (v62[53] << v62[57]) | v69;
      }
      else
      {
        v63 = 0;
        if ( v68 > 1 )
          goto LABEL_127;
      }
      goto LABEL_126;
    }
    v61 = *(_DWORD *)(v60 + 60);
    v62 = *(unsigned int **)(v59 + 16);
    if ( !v61 )
    {
      v63 = 0;
LABEL_126:
      v63 |= v62[61];
      goto LABEL_127;
    }
    v63 = v62[56] << v62[57];
    if ( *(_DWORD *)(*(_QWORD *)(v2 + 872) + 60LL) == 1 )
    {
      v63 |= v62[58] << v62[59];
      if ( v61 <= 1 )
        goto LABEL_126;
    }
    else if ( v61 <= 1 )
    {
      goto LABEL_126;
    }
LABEL_127:
    v70 = *(_QWORD *)(v2 + 8);
    cam_io_w_mb(v63, *(_QWORD *)(v70 + 384) + v62[6]);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_start_pix_path",
        2077,
        "CSID:%d Resource[id:%d name:%s]ctrl val: 0x%x",
        *(_DWORD *)(*(_QWORD *)v2 + 4LL),
        v47[1],
        (const char *)v47 + 128,
        v63);
    cam_io_w_mb(v62[75] | v62[76] | *(_DWORD *)(v2 + 28356) | 2, *(_QWORD *)(v70 + 384) + v62[1]);
    v45 = 0;
    v46 = 0;
    v47[2] = 4;
LABEL_82:
    ++v40;
  }
  while ( v40 < *(unsigned int *)(a2 + 8) );
  if ( !v45 )
    goto LABEL_143;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver1_start",
    3062,
    "CSID:%d start fail res type:%d res id:%d",
    *(_DWORD *)(*(_QWORD *)v2 + 4LL),
    *v47,
    v47[1]);
  return v46;
}
