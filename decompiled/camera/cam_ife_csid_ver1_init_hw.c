__int64 __fastcall cam_ife_csid_ver1_init_hw(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x19
  __int64 v5; // x21
  _QWORD *v6; // x24
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x1
  unsigned int v12; // w8
  const char *v13; // x5
  __int64 v14; // x6
  __int64 v15; // x4
  unsigned int inited; // w22
  int clk_level; // w0
  unsigned int v18; // w0
  unsigned int v19; // w0
  int v20; // w6
  __int64 v21; // x7
  __int64 *v22; // x8
  __int64 v23; // x27
  unsigned int *v24; // x21
  unsigned int *v25; // x24
  unsigned int v26; // w25
  _DWORD *v27; // x28
  __int64 v28; // x26
  int v29; // w8
  int v30; // w8
  int v31; // w25
  int v32; // w22
  int v33; // w9
  int v34; // w24
  int v35; // w22
  unsigned int v36; // w8
  unsigned int v37; // w0
  unsigned int v38; // w0
  int v39; // w22
  __int64 v40; // x8
  unsigned int v41; // w21
  __int64 *v42; // x8
  __int64 v43; // x26
  unsigned int *v44; // x27
  unsigned int *v45; // x24
  unsigned int v46; // w25
  _DWORD *v47; // x21
  __int64 v48; // x28
  int v49; // w8
  int v50; // w8
  int v51; // w22
  int v52; // w25
  int v53; // w22
  int v54; // w24
  unsigned int v55; // w0
  char v56; // w8
  unsigned int v57; // w21
  int v58; // w22
  unsigned int v59; // w8
  unsigned int v60; // w0
  unsigned int *v61; // x8
  __int64 v62; // x9
  int v63; // w0
  __int64 v64; // x0
  const char *v65; // x3
  const char *v66; // x5
  __int64 v67; // x6
  __int64 v68; // x4
  int v70; // [xsp+8h] [xbp-28h]
  __int64 v71; // [xsp+18h] [xbp-18h] BYREF
  __int64 v72; // [xsp+20h] [xbp-10h]
  __int64 v73; // [xsp+28h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_init_hw",
      2764,
      "CSID: Invalid args");
    inited = -22;
LABEL_112:
    _ReadStatusReg(SP_EL0);
    return inited;
  }
  v4 = *(_QWORD *)(a1 + 3680);
  LODWORD(v71) = 0;
  v5 = *(_QWORD *)(v4 + 8);
  v6 = **(_QWORD ***)(v4 + 16);
  mutex_lock(v5);
  v7 = *(_QWORD *)(v4 + 8);
  v8 = *(_DWORD *)(v7 + 88);
  if ( v8 == -1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_enable_hw",
      2659,
      "CSID:%d Open count reached max",
      *(_DWORD *)(*(_QWORD *)v4 + 4LL));
    inited = -22;
LABEL_23:
    mutex_unlock(*(_QWORD *)(v4 + 8));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_init_hw",
      2775,
      "CSID:%d Enable hw fail",
      *(_DWORD *)(*(_QWORD *)v4 + 4LL));
    goto LABEL_112;
  }
  *(_DWORD *)(v7 + 88) = v8 + 1;
  v9 = *(_QWORD *)(v4 + 8);
  if ( *(_DWORD *)(v9 + 88) >= 2u )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_enable_hw",
        2668,
        "CSID hw has already been enabled");
      v9 = *(_QWORD *)(v4 + 8);
    }
    mutex_unlock(v9);
    goto LABEL_10;
  }
  mutex_unlock(v9);
  clk_level = cam_soc_util_get_clk_level(
                (_BYTE *)(v5 + 96),
                *(_QWORD *)(v4 + 28384),
                *(_DWORD *)(v5 + 2892),
                (int *)&v71);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_enable_hw",
      2680,
      "CSID[%d] clk lvl %u received clk_rate %u applied clk_rate %lu rc %d",
      *(_DWORD *)(*(_QWORD *)v4 + 4LL),
      v71,
      *(_QWORD *)(v4 + 28384),
      *(_QWORD *)(v5 + 2896),
      clk_level);
  v18 = cam_ife_csid_enable_soc_resources(v5 + 96, v71);
  if ( v18 )
  {
    inited = v18;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_enable_hw",
      2686,
      "CSID:%d Enable SOC failed",
      *(_DWORD *)(*(_QWORD *)v4 + 4LL));
LABEL_22:
    mutex_lock(*(_QWORD *)(v4 + 8));
    --*(_DWORD *)(*(_QWORD *)(v4 + 8) + 88LL);
    goto LABEL_23;
  }
  *(_DWORD *)(*(_QWORD *)(v4 + 8) + 92LL) = 1;
  v19 = cam_ife_csid_ver1_global_reset(v4);
  if ( v19 )
  {
    inited = v19;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_enable_hw",
      2694,
      "CSID[%d] global reset failed",
      v20);
    cam_ife_csid_disable_soc_resources(v5 + 96);
    *(_DWORD *)(*(_QWORD *)(v4 + 8) + 92LL) = 0;
    goto LABEL_22;
  }
  cam_io_w_mb(1, *(_QWORD *)(v5 + 384) + *(unsigned int *)(v6[12] + 32LL));
  cam_io_w_mb(*(unsigned int *)(*v6 + 140LL), *(_QWORD *)(v5 + 384) + *(unsigned int *)(*v6 + 8LL));
  v61 = (unsigned int *)v6[12];
  if ( v61[39] )
  {
    cam_io_w_mb(v61[51], *(_QWORD *)(v5 + 384) + *(unsigned int *)(v6[1] + 8LL));
    v61 = (unsigned int *)v6[12];
  }
  if ( v61[40] )
  {
    cam_io_w_mb(v61[53], *(_QWORD *)(v5 + 384) + *(unsigned int *)(v6[1] + 8LL));
    v61 = (unsigned int *)v6[12];
  }
  v62 = *(_QWORD *)(v5 + 384);
  if ( v61[38] )
  {
    cam_io_w_mb(v61[52], v62 + *(unsigned int *)(v6[3] + 8LL));
    v61 = (unsigned int *)v6[12];
    v62 = *(_QWORD *)(v5 + 384);
    if ( v61[38] > 1 )
    {
      cam_io_w_mb(v61[52], v62 + *(unsigned int *)(v6[4] + 8LL));
      v61 = (unsigned int *)v6[12];
      v62 = *(_QWORD *)(v5 + 384);
      if ( v61[38] >= 3 )
      {
        cam_io_w_mb(v61[52], v62 + *(unsigned int *)(v6[5] + 8LL));
        v61 = (unsigned int *)v6[12];
        v62 = *(_QWORD *)(v5 + 384);
        if ( v61[38] >= 4 )
        {
          cam_io_w_mb(v61[52], v62 + *(unsigned int *)(v6[6] + 8LL));
          v61 = (unsigned int *)v6[12];
          v62 = *(_QWORD *)(v5 + 384);
          if ( v61[38] >= 5 )
          {
            v10 = cam_io_w_mb(v61[52], v62 + *(unsigned int *)(v6[7] + 8LL));
            v61 = (unsigned int *)v6[12];
            if ( v61[38] > 5 )
              goto LABEL_115;
            v62 = *(_QWORD *)(v5 + 384);
          }
        }
      }
    }
  }
  if ( v61[37] )
  {
    cam_io_w_mb(v61[54], v62 + *(unsigned int *)(v6[8] + 8LL));
    v61 = (unsigned int *)v6[12];
    v62 = *(_QWORD *)(v5 + 384);
    if ( v61[37] > 1 )
    {
      cam_io_w_mb(v61[54], v62 + *(unsigned int *)(v6[9] + 8LL));
      v61 = (unsigned int *)v6[12];
      v62 = *(_QWORD *)(v5 + 384);
      if ( v61[37] >= 3 )
      {
        v10 = cam_io_w_mb(v61[54], v62 + *(unsigned int *)(v6[10] + 8LL));
        v61 = (unsigned int *)v6[12];
        if ( v61[37] > 3 )
          goto LABEL_115;
        v62 = *(_QWORD *)(v5 + 384);
      }
    }
  }
  cam_io_w_mb(1, v62 + v61[10]);
  v63 = cam_io_r_mb(*(_QWORD *)(v5 + 384) + *(unsigned int *)v6[12]);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_enable_hw",
      2735,
      "CSID:%d Enabled CSID HW version: 0x%x",
      *(_DWORD *)(*(_QWORD *)v4 + 4LL),
      v63);
  *(_QWORD *)(v4 + 28376) = 0;
  *(_QWORD *)(v4 + 28368) = 0;
  v64 = raw_spin_lock_irqsave(v4 + 28396);
  *(_BYTE *)(v4 + 28317) = 0;
  *(_BYTE *)(v4 + 28312) = 1;
  raw_spin_unlock_irqrestore(v4 + 28396, v64);
LABEL_10:
  v10 = mutex_lock(*(_QWORD *)(v4 + 8));
  if ( *(_DWORD *)a2 == 3 )
  {
    v12 = *(_DWORD *)(a2 + 4);
    if ( v12 >= 0xC )
    {
      v13 = "CSID:%d Invalid res tpe:%d res id%d";
      v14 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
      v15 = 2785;
LABEL_80:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int, int))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_init_hw",
        v15,
        v13,
        v14,
        3,
        v12,
        v70);
      inited = -22;
LABEL_111:
      mutex_unlock(*(_QWORD *)(v4 + 8));
      goto LABEL_112;
    }
    if ( *(_DWORD *)(a2 + 8) != 2 )
    {
      v13 = "CSID:%d res type:%d res_id:%dInvalid state %d";
      v14 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
      v70 = *(_DWORD *)(a2 + 8);
      v15 = 2795;
      goto LABEL_80;
    }
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    v10 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_ver1_init_hw",
            2801,
            "CSID:%d res type :%d res_id:%d",
            *(unsigned int *)(*(_QWORD *)v4 + 4LL));
  v21 = *(unsigned int *)(a2 + 4);
  if ( (unsigned int)v21 > 9 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_init_hw",
      2826,
      "CSID:%d Invalid Res id %d",
      *(unsigned int *)(*(_QWORD *)v4 + 4LL));
    inited = -22;
LABEL_110:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_init_hw",
      2833,
      "CSID:%d res_id:%d path init configuration failed with rc: %d",
      *(_DWORD *)(*(_QWORD *)v4 + 4LL),
      *(_DWORD *)(a2 + 4),
      inited);
    goto LABEL_111;
  }
  if ( ((1 << v21) & 0x1F) == 0 )
  {
    if ( ((1 << v21) & 0x380) == 0 )
    {
      inited = cam_ife_csid_ver1_init_config_pxl_path(v4, a2);
      goto LABEL_105;
    }
    v42 = *(__int64 **)(v4 + 16);
    v71 = 0;
    v72 = 0;
    v43 = *v42;
    v44 = *(unsigned int **)(*v42 + 8LL * (unsigned int)(v21 - 7) + 64);
    if ( !v44 )
    {
      v65 = "cam_ife_csid_ver1_init_config_udi_path";
      v66 = "CSID:%d UDI:%d is not supported on HW";
      v67 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
      v68 = 2349;
      goto LABEL_104;
    }
    v45 = *(unsigned int **)(a2 + 24);
    v46 = *v45;
    if ( *v45 > 4 )
      goto LABEL_115;
    v47 = *(_DWORD **)(v43 + 96);
    v48 = *(_QWORD *)(*(_QWORD *)(v4 + 8) + 384LL);
    inited = cam_ife_csid_get_format_rdi(v45[1], v45[2], (__int64)&v71, v44[64] != 0, 0);
    if ( inited )
      goto LABEL_105;
    v49 = (*(_DWORD *)(v4 + 56LL * v46 + 27020) << v47[17])
        | (*(_DWORD *)(v4 + 56LL * v46 + 27016) << v47[16])
        | (*v45 << v47[15])
        | ((_DWORD)v71 << v47[13]);
    if ( (*(_BYTE *)(v4 + 28332) & 0x80) != 0 )
      v49 |= 1 << v44[66];
    v50 = (*((unsigned __int8 *)v45 + 64) << v44[46]) | v49 | (*((unsigned __int8 *)v45 + 64) << v44[45]);
    if ( v47[45] )
      v50 |= (*((unsigned __int8 *)v45 + 65) << v44[47]) | (*((unsigned __int8 *)v45 + 65) << v44[48]);
    if ( v44[64] )
      v50 |= HIDWORD(v71) << v44[65];
    cam_io_w_mb(((_DWORD)v72 << v44[67]) | (unsigned int)v50, v48 + v44[4]);
    cam_io_w_mb((v47[47] << v47[12]) | (unsigned int)(1 << v44[44]), v48 + v44[5]);
    if ( *((_BYTE *)v45 + 64) == 1 )
    {
      v51 = v47[62] & v45[3];
      v52 = (v47[61] & v45[4]) << v47[20];
      cam_io_w_mb(v51 | (unsigned int)v52, v48 + v44[11]);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver1_init_config_udi_path",
          2418,
          "CSID:%d Horizontal crop config val: 0x%x",
          *(_DWORD *)(*(_QWORD *)v4 + 4LL),
          v51 | v52);
      v53 = v47[64] & v45[6];
      v54 = (v47[63] & v45[7]) << *(_DWORD *)(*(_QWORD *)(v43 + 96) + 80LL);
      cam_io_w_mb(v53 | (unsigned int)v54, v48 + v44[12]);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver1_init_config_udi_path",
          2425,
          "CSID:%d Vertical Crop config val: 0x%x",
          *(_DWORD *)(*(_QWORD *)v4 + 4LL),
          v53 | v54);
    }
    cam_io_w_mb(1, v48 + v44[8]);
    cam_io_w_mb(0, v48 + v44[7]);
    cam_io_w_mb(1, v48 + v44[10]);
    cam_io_w_mb(0, v48 + v44[9]);
    cam_io_w_mb(0, v48 + v44[13]);
    cam_io_w_mb(1, v48 + v44[14]);
    cam_io_w_mb(0, v48 + v44[15]);
    cam_io_w_mb(1, v48 + v44[16]);
    v55 = cam_io_r_mb(v48 + v44[4]);
    v56 = v47[14];
    v57 = v55;
    v58 = 1 << v56;
    cam_io_w_mb((1 << v56) | v55, v48 + v44[4]);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_init_config_udi_path",
        2448,
        "%s cfg0 0x%x",
        (const char *)(a2 + 128),
        v58 | v57);
      v59 = v44[74];
      if ( !v59 )
      {
LABEL_76:
        if ( (*(_BYTE *)(v4 + 28332) & 0x80) != 0 )
        {
          v60 = cam_io_r_mb(v48 + v44[24]);
          cam_io_w_mb(*(_DWORD *)(*(_QWORD *)(v43 + 96) + 220LL) | v60, v48 + v44[24]);
        }
LABEL_78:
        inited = 0;
        *(_DWORD *)(a2 + 8) = 3;
        goto LABEL_105;
      }
    }
    else
    {
      v59 = v44[74];
      if ( !v59 )
        goto LABEL_76;
    }
    cam_io_w_mb(v44[73] | v59, v48 + v44[38]);
    goto LABEL_76;
  }
  v22 = *(__int64 **)(v4 + 16);
  v71 = 0;
  v72 = 0;
  v23 = *v22;
  v24 = *(unsigned int **)(*v22 + 8 * v21 + 24);
  if ( !v24 )
  {
    v65 = "cam_ife_csid_ver1_init_config_rdi_path";
    v66 = "CSID:%d RDI:%d is not supported on HW";
    v67 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
    v68 = 2187;
LABEL_104:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      v65,
      v68,
      v66,
      v67);
    inited = -22;
LABEL_105:
    if ( (inited & 0x80000000) == 0 )
    {
      if ( (cam_ife_csid_ver1_hw_reset(v4) & 0x80000000) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_init_hw",
          2841,
          "CSID:%d Failed in HW reset",
          *(_DWORD *)(*(_QWORD *)v4 + 4LL));
      mutex_unlock(*(_QWORD *)(v4 + 8));
      inited = 0;
      goto LABEL_112;
    }
    goto LABEL_110;
  }
  v25 = *(unsigned int **)(a2 + 24);
  v26 = *v25;
  if ( *v25 <= 4 )
  {
    v27 = *(_DWORD **)(v23 + 96);
    v28 = *(_QWORD *)(*(_QWORD *)(v4 + 8) + 384LL);
    inited = cam_ife_csid_get_format_rdi(v25[1], v25[2], (__int64)&v71, v24[64] != 0, 0);
    if ( inited )
      goto LABEL_105;
    v29 = (*(_DWORD *)(v4 + 56LL * v26 + 27020) << v27[17])
        | (*(_DWORD *)(v4 + 56LL * v26 + 27016) << v27[16])
        | (*v25 << v27[15])
        | ((_DWORD)v71 << v27[13]);
    if ( (*(_BYTE *)(v4 + 28332) & 0x80) != 0 )
      v29 |= 1 << v24[66];
    v30 = (*((unsigned __int8 *)v25 + 64) << v24[46]) | v29 | (*((unsigned __int8 *)v25 + 64) << v24[45]);
    if ( v27[45] )
      v30 |= (*((unsigned __int8 *)v25 + 65) << v24[47]) | (*((unsigned __int8 *)v25 + 65) << v24[48]);
    if ( v24[64] )
      v30 |= HIDWORD(v71) << v24[65];
    cam_io_w_mb(((_DWORD)v72 << v24[67]) | (1 << v24[44]) | (unsigned int)v30, v28 + v24[4]);
    if ( *(_BYTE *)(v4 + 56LL * v26 + 27036) == 1 )
      cam_io_w_mb(
        (*(_DWORD *)(v4 + 56LL * v26 + 27032) << v27[31])
      | (*(_DWORD *)(v4 + 56LL * v26 + 27028) << v27[30])
      | (unsigned int)(1 << v27[33]),
        v28 + v24[41]);
    cam_io_w_mb((unsigned int)(v27[47] << v27[12]), v28 + v24[5]);
    if ( *((_BYTE *)v25 + 64) == 1 )
    {
      v31 = v27[62] & v25[3];
      v32 = (v27[61] & v25[4]) << v27[20];
      cam_io_w_mb(v31 | (unsigned int)v32, v28 + v24[11]);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver1_init_config_rdi_path",
          2268,
          "CSID:%d Horizontal crop config val: 0x%x",
          *(_DWORD *)(*(_QWORD *)v4 + 4LL),
          v31 | v32);
      v33 = v27[63] & v25[7];
      v34 = v27[64] & v25[6];
      v35 = v33 << *(_DWORD *)(*(_QWORD *)(v23 + 96) + 80LL);
      cam_io_w_mb(v34 | (unsigned int)v35, v28 + v24[12]);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver1_init_config_rdi_path",
          2275,
          "CSID:%d Vertical Crop config val: 0x%x",
          *(_DWORD *)(*(_QWORD *)v4 + 4LL),
          v34 | v35);
    }
    cam_io_w_mb(1, v28 + v24[8]);
    cam_io_w_mb(0, v28 + v24[7]);
    cam_io_w_mb(1, v28 + v24[10]);
    cam_io_w_mb(0, v28 + v24[9]);
    cam_io_w_mb(0, v28 + v24[13]);
    cam_io_w_mb(1, v28 + v24[14]);
    cam_io_w_mb(0, v28 + v24[15]);
    cam_io_w_mb(1, v28 + v24[16]);
    v36 = v24[74];
    if ( v36 )
      cam_io_w_mb(v24[73] | v36, v28 + v24[38]);
    if ( (*(_BYTE *)(v4 + 28332) & 0x80) != 0 )
    {
      v37 = cam_io_r_mb(v28 + v24[24]);
      cam_io_w_mb(*(_DWORD *)(*(_QWORD *)(v23 + 96) + 220LL) | v37, v28 + v24[24]);
    }
    v38 = cam_io_r_mb(v28 + v24[4]);
    v39 = 1 << v27[14];
    v40 = v24[4];
    v41 = v38;
    cam_io_w_mb(v39 | v38, v28 + v40);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_init_config_rdi_path",
        2313,
        "%s cfg0 0x%x",
        (const char *)(a2 + 128),
        v39 | v41);
    goto LABEL_78;
  }
LABEL_115:
  __break(0x5512u);
  return cam_ife_csid_ver1_init_config_pxl_path(v10, v11);
}
