__int64 __fastcall cam_isp_blob_vfe_out_update(
        unsigned int a1,
        __int64 a2,
        _DWORD *a3,
        __int64 a4,
        unsigned int a5,
        int a6)
{
  int v6; // w6
  unsigned int v7; // w8
  __int64 v8; // x20
  __int64 v9; // x15
  __int64 v11; // x22
  unsigned int v12; // w13
  int v13; // w14
  _DWORD *v14; // x17
  __int64 *v15; // x19
  const char *v16; // x3
  const char *v17; // x5
  __int64 v18; // x0
  __int64 v19; // x4
  int *v20; // x24
  __int64 v22; // x0
  bool v23; // w8
  unsigned int v24; // w10
  _BOOL4 v26; // w9
  int v28; // w9
  unsigned int v29; // w10
  unsigned int v30; // w26
  __int64 v31; // x10
  __int64 v32; // x11
  __int64 v33; // x7
  __int64 v34; // x30
  __int64 *v35; // x23
  int v36; // w6
  unsigned int *v37; // x9
  unsigned int v38; // w7
  __int64 v39; // x6
  __int64 *v40; // x8
  int v41; // w26
  __int64 v42; // x21
  unsigned int v43; // w9
  __int64 v44; // x9
  int v45; // w7
  int v46; // w10
  __int64 v47; // x20
  unsigned int v48; // w23
  int v49; // w28
  int v50; // w19
  unsigned int v51; // w25
  __int64 v52; // x22
  unsigned int v53; // w9
  __int64 *v54; // x8
  unsigned int *v55; // x11
  __int64 v56; // x10
  unsigned int v57; // w7
  __int64 v58; // x6
  __int64 *v59; // x8
  unsigned __int64 v60; // x12
  __int64 **v61; // x8
  __int64 v62; // x8
  __int64 v63; // x11
  __int64 v64; // x0
  int v65; // w19
  _DWORD *v66; // x26
  unsigned int v67; // w28
  __int64 v68; // x20
  const void *v69; // x4
  __int64 v70; // x25
  _DWORD *v71; // x22
  __int64 v72; // x23
  int v73; // w27
  unsigned int v74; // w21
  unsigned __int64 v75; // x10
  __int64 **v76; // x8
  __int64 v77; // x8
  __int64 v78; // x9
  __int64 v79; // x0
  unsigned int v80; // w9
  _DWORD *v81; // x19
  unsigned int v82; // w20
  int v83; // w26
  __int64 v84; // x28
  __int64 v85; // x25
  int v86; // w27
  unsigned int v87; // w23
  int v88; // w9
  const char *v89; // x6
  unsigned int v90; // w28
  int v91; // w19
  __int64 v92; // x27
  int v93; // w23
  unsigned int v94; // w21
  unsigned int v95; // w20
  int v96; // w7
  _DWORD *v97; // x19
  __int64 v98; // x20
  unsigned int v99; // w26
  int v100; // w28
  int v101; // w25
  unsigned int v102; // w21
  __int64 v103; // x22
  unsigned int v105; // w19
  char v106; // w4
  const char *v107; // x6
  __int64 v108; // x4
  __int64 v109; // [xsp+20h] [xbp-70h]
  __int64 v110; // [xsp+28h] [xbp-68h]
  __int64 v111; // [xsp+28h] [xbp-68h]
  __int64 v112; // [xsp+28h] [xbp-68h]
  _DWORD *v113; // [xsp+30h] [xbp-60h]
  _DWORD *v114; // [xsp+30h] [xbp-60h]
  __int64 v115; // [xsp+38h] [xbp-58h]
  __int64 v116; // [xsp+38h] [xbp-58h]
  __int64 v117; // [xsp+38h] [xbp-58h]
  _DWORD *v118; // [xsp+40h] [xbp-50h]
  _DWORD *v119; // [xsp+40h] [xbp-50h]
  _DWORD *v120; // [xsp+40h] [xbp-50h]
  _DWORD *v121; // [xsp+40h] [xbp-50h]
  __int64 v122; // [xsp+48h] [xbp-48h]
  unsigned int v123; // [xsp+48h] [xbp-48h]
  __int64 *v124; // [xsp+50h] [xbp-40h]
  __int64 *v125; // [xsp+58h] [xbp-38h]
  unsigned int v126; // [xsp+64h] [xbp-2Ch]
  unsigned int v127; // [xsp+64h] [xbp-2Ch]
  __int64 *v128; // [xsp+68h] [xbp-28h]
  __int64 v129; // [xsp+70h] [xbp-20h]
  __int64 v130; // [xsp+78h] [xbp-18h]
  int v131; // [xsp+80h] [xbp-10h] BYREF
  int v132; // [xsp+84h] [xbp-Ch] BYREF
  __int64 v133; // [xsp+88h] [xbp-8h]

  v133 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a4 + 40);
  v7 = *(_DWORD *)(a4 + 24);
  v8 = *(_QWORD *)(a4 + 16);
  v131 = 0;
  if ( v6 + 1 >= v7 )
  {
    v16 = "cam_isp_blob_vfe_out_update";
    v17 = "Insufficient HW entries :%d, ctx_idx: %u";
    v18 = 3;
    v19 = 11481;
    goto LABEL_91;
  }
  if ( !*a3 )
  {
    v12 = 0;
LABEL_93:
    _ReadStatusReg(SP_EL0);
    return v12;
  }
  v9 = *(_QWORD *)(a2 + 16);
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = a3 + 2;
  v15 = (__int64 *)(v8 + 256);
  v124 = (__int64 *)(v8 + 280);
  v125 = (__int64 *)(v8 + 272);
  v129 = v8;
  v130 = a2;
  v128 = (__int64 *)(v8 + 256);
  while ( 1 )
  {
    v20 = &v14[12 * v11];
    if ( a6 == 7 )
    {
      v24 = *v20 - 20481;
      v26 = (unsigned int)*v20 >> 13 > 2 && max_sfe_out_res + 24576 > (unsigned int)*v20;
      v23 = v24 < 3;
      if ( v24 >= 3 && !v26 )
        goto LABEL_7;
      v22 = 1;
    }
    else
    {
      if ( a6 == 2 && ((unsigned int)*v20 < 0x3000 || max_ife_out_res + 12288 <= (unsigned int)*v20) )
        goto LABEL_7;
      v22 = 0;
      v23 = 0;
    }
    v29 = *(_DWORD *)(v9 + 20);
    v28 = *(_DWORD *)(v9 + 24);
    v30 = v29 - (v28 + v13);
    if ( v29 <= v28 + v13 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_vfe_out_update",
        11507,
        "No free kmd memory for base idx: %d, ctx_idx: %u",
        **(_DWORD **)(a2 + 8),
        *(_DWORD *)(v8 + 56));
      v12 = -12;
      goto LABEL_93;
    }
    v31 = *(_QWORD *)(v9 + 8);
    v32 = v13 & 0xFFFFFFFC;
    v33 = v28 & 0xFFFFFFFC;
    v34 = v31 + v32;
    if ( !v23 )
      break;
    v35 = v15;
    v132 = 0;
    do
    {
      v35 = (__int64 *)*v35;
      if ( v35 == v15 )
      {
        v16 = "cam_isp_blob_sfe_rd_update";
        v17 = "Failed to find SFE rd resource: %u, check if rsrc is acquired, ctx_idx: %u";
        v18 = 3;
        v19 = 11382;
        goto LABEL_91;
      }
      v36 = *((_DWORD *)v35 + 5);
    }
    while ( v36 != *v20 );
    v122 = v28 & 0xFFFFFFFC;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v96 = *(_DWORD *)(v8 + 56);
      v97 = a3;
      v98 = a4;
      v127 = v30;
      v99 = a5;
      v100 = a6;
      v117 = v9;
      v121 = v14;
      v112 = v11;
      v101 = v13;
      v102 = a1;
      v103 = v31 + v32;
      v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_isp_blob_sfe_rd_update",
              11387,
              "SFE RM config for port: 0x%x, ctx_idx: %u",
              v36,
              v96);
      a3 = v97;
      v9 = v117;
      v14 = v121;
      a4 = v98;
      v15 = v128;
      v8 = v129;
      v34 = v103;
      v11 = v112;
      a5 = v99;
      v30 = v127;
      a2 = v130;
      a1 = v102;
      v13 = v101;
      a6 = v100;
    }
    v37 = *(unsigned int **)(a2 + 8);
    v38 = v37[2];
    v39 = *v37;
    if ( v38 == 7 )
    {
      if ( (unsigned int)v39 > 2 )
        goto LABEL_116;
      v75 = (8 * v39) | 0xE0;
      v76 = (__int64 **)&g_ife_hw_mgr[v39 + 28];
    }
    else
    {
      if ( v38 != 2 )
      {
        if ( v38 )
          goto LABEL_99;
        if ( (unsigned int)v39 >= 8 )
          goto LABEL_116;
        v40 = &g_ife_hw_mgr[v39 + 12];
        goto LABEL_78;
      }
      if ( (unsigned int)v39 > 7 )
        goto LABEL_116;
      v75 = 8 * v39 + 160;
      v76 = (__int64 **)((char *)g_ife_hw_mgr + v75);
    }
    if ( v75 > 0x13FD8 )
      goto LABEL_117;
    v40 = *v76;
LABEL_78:
    v77 = *v40;
    if ( !v77 || (v78 = v37[1], (unsigned int)v78 >= 2) )
    {
LABEL_99:
      v16 = "cam_isp_blob_sfe_rd_update";
      v17 = "Invalid base %u type %u";
      v18 = 3;
      v19 = 11393;
      goto LABEL_91;
    }
    v79 = v35[v78 + 4];
    if ( !v79 )
    {
      v12 = 0;
      goto LABEL_7;
    }
    v80 = v30;
    v81 = a3;
    v82 = a5;
    v83 = a6;
    v84 = a4;
    v119 = v14;
    v85 = v9;
    v86 = v13;
    v87 = a1;
    v12 = cam_isp_add_cmd_buf_update(v79, v77, a1, 0x17u, (const void *)(v34 + v122), v80, (__int64)v20, &v132);
    if ( (v12 & 0x80000000) != 0 )
    {
      v105 = v12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_sfe_rd_update",
        11412,
        "Failed to update SFE RM config out_type:0x%X base_idx:%d bytes_used:%u rc:%d ctx_idx: %u",
        *v20,
        **(_DWORD **)(v130 + 8),
        v132,
        v12,
        *(_DWORD *)(v129 + 56));
      goto LABEL_110;
    }
    a2 = v130;
    if ( v12 )
      goto LABEL_93;
    a5 = v82;
    v8 = v129;
    v14 = v119;
    a4 = v84;
    a6 = v83;
    a3 = v81;
    v13 = v132 + v86;
    v9 = v85;
    a1 = v87;
LABEL_6:
    v15 = v128;
LABEL_7:
    if ( ++v11 >= (unsigned __int64)(unsigned int)*a3 )
    {
      if ( !v13 )
        goto LABEL_93;
      v105 = v12;
      v106 = *(_BYTE *)(a2 + 24) == 1
          && *(_DWORD *)(*(_QWORD *)(a4 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a4 + 40) - 1) + 12) == 2;
      cam_isp_update_hw_entry(2, a4, v9, v13, v106);
      *(_BYTE *)(v130 + 24) = 1;
      goto LABEL_110;
    }
  }
  v126 = v30;
  v41 = *v20;
  v123 = v22;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v88 = *(_DWORD *)(v8 + 56);
    v109 = v31 + v32;
    v111 = a4;
    if ( (_DWORD)v22 )
      v89 = "SFE";
    else
      v89 = "VFE";
    v114 = a3;
    v116 = v9;
    v90 = a5;
    v91 = a6;
    v92 = v33;
    v93 = v13;
    v120 = v14;
    v94 = a1;
    v95 = v12;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_vfe_out_update",
      11531,
      "%s out config idx: %d port: 0x%x, ctx_idx: %u",
      v89,
      v11,
      v41,
      v88);
    v34 = v109;
    a4 = v111;
    v12 = v95;
    a3 = v114;
    v9 = v116;
    a6 = v91;
    v15 = v128;
    v8 = v129;
    v22 = v123;
    v14 = v120;
    v33 = v92;
    a2 = v130;
    a1 = v94;
    v13 = v93;
    a5 = v90;
  }
  if ( (unsigned __int8)v41 >= a5 )
  {
    v16 = "cam_isp_blob_vfe_out_update";
    v17 = "Invalid out port:0x%x, ctx_idx: %u";
    v18 = 3;
    v19 = 11535;
    goto LABEL_91;
  }
  v42 = v33;
  if ( (_DWORD)v22 )
  {
    if ( *(_BYTE *)(v8 + 9387) != 1 )
      goto LABEL_53;
    v43 = *v20 - 24576;
    if ( v43 > 2 )
      goto LABEL_53;
    if ( v43 >= *(_DWORD *)(v8 + 9352) )
      goto LABEL_52;
    if ( (*v20 & 3) == 3 )
    {
      if ( (unsigned int)__ratelimit(&cam_ife_hw_mgr_update_scratch_offset__rs, "cam_ife_hw_mgr_update_scratch_offset") )
        v18 = 3;
      else
        v18 = 2;
      v17 = "res_id: %d exceeds max size: %d ctx_idx: %u";
      v16 = "cam_ife_hw_mgr_update_scratch_offset";
      v19 = 11435;
    }
    else
    {
      v44 = *(_QWORD *)(v8 + 9360) + 40LL * (*v20 & 3);
      if ( (*(_BYTE *)(v44 + 48) & 1) != 0 )
      {
        v45 = v20[7];
        v12 = 0;
        *(_DWORD *)(v44 + 44) = v45;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v46 = *(_DWORD *)(v8 + 56);
          v110 = v11;
          v113 = a3;
          v47 = a4;
          v48 = a5;
          v49 = a6;
          v50 = v13;
          v51 = a1;
          v115 = v9;
          v118 = v14;
          v52 = v34;
          v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_ife_hw_mgr_update_scratch_offset",
                  11450,
                  "Scratch addr: 0x%x offset: %u updated for: 0x%x ctx_idx: %u",
                  *(_QWORD *)(v44 + 32),
                  v45,
                  *v20,
                  v46);
          v34 = v52;
          v13 = v50;
          a4 = v47;
          v11 = v110;
          a3 = v113;
          v9 = v115;
          v14 = v118;
          a2 = v130;
          v15 = v128;
          v8 = v129;
          a1 = v51;
          a5 = v48;
          a6 = v49;
LABEL_52:
          v12 = 0;
        }
LABEL_53:
        v53 = *(unsigned __int8 *)(*(_QWORD *)(v8 + 8504) + (unsigned __int8)v41);
        v54 = v124;
        if ( v53 == 255 )
        {
          v108 = 11549;
LABEL_108:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_vfe_out_update",
            v108,
            "Invalid index:%d for out_map",
            (unsigned __int8)v41);
          goto LABEL_92;
        }
        goto LABEL_56;
      }
      v16 = "cam_ife_hw_mgr_update_scratch_offset";
      v17 = "Scratch buffer not configured on ctx: %u for res: %u ctx_idx: %u";
      v18 = 3;
      v19 = 11442;
    }
LABEL_91:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v18,
      8,
      1,
      v16,
      v19,
      v17);
LABEL_92:
    v12 = -22;
    goto LABEL_93;
  }
  v53 = *(unsigned __int8 *)(*(_QWORD *)(v8 + 8496) + (unsigned __int8)v41);
  v54 = v125;
  if ( v53 == 255 )
  {
    v108 = 11556;
    goto LABEL_108;
  }
LABEL_56:
  v55 = *(unsigned int **)(a2 + 8);
  v56 = *v54;
  v57 = v55[2];
  v58 = *v55;
  if ( v57 == 7 )
  {
    if ( (unsigned int)v58 > 2 )
      goto LABEL_116;
    v60 = (8 * v58) | 0xE0;
    v61 = (__int64 **)&g_ife_hw_mgr[v58 + 28];
    goto LABEL_65;
  }
  if ( v57 == 2 )
  {
    if ( (unsigned int)v58 > 7 )
      goto LABEL_116;
    v60 = 8 * v58 + 160;
    v61 = (__int64 **)((char *)g_ife_hw_mgr + v60);
LABEL_65:
    v22 = 81880;
    if ( v60 > 0x13FD8 )
      goto LABEL_117;
    v59 = *v61;
    goto LABEL_67;
  }
  if ( v57 )
    goto LABEL_97;
  if ( (unsigned int)v58 < 8 )
  {
    v59 = &g_ife_hw_mgr[v58 + 12];
LABEL_67:
    v62 = *v59;
    if ( !v62 || (v63 = v55[1], (unsigned int)v63 >= 2) )
    {
LABEL_97:
      v16 = "cam_isp_blob_vfe_out_update";
      v17 = "Invalid base %u type %u";
      v18 = 3;
      v19 = 11567;
      goto LABEL_91;
    }
    v64 = *(_QWORD *)(v56 + ((unsigned __int64)v53 << 7) + 8 * v63 + 32);
    if ( !v64 )
      goto LABEL_7;
    v65 = a6;
    v66 = a3;
    v67 = a5;
    v68 = a4;
    v69 = (const void *)(v34 + v42);
    v70 = v11;
    v71 = v14;
    v72 = v9;
    v73 = v13;
    v74 = a1;
    v12 = cam_isp_add_cmd_buf_update(v64, v62, a1, 0x1Au, v69, v126, (__int64)v20, &v131);
    if ( (v12 & 0x80000000) != 0 )
    {
      if ( v123 )
        v107 = "SFE";
      else
        v107 = "VFE";
      v105 = v12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_vfe_out_update",
        11589,
        "Failed to update %s Out out_type:0x%X base_idx:%d bytes_used:%u rc:%d ctx_idx: %u",
        v107,
        *v20,
        **(_DWORD **)(v130 + 8),
        v131,
        v12,
        *(_DWORD *)(v129 + 56));
LABEL_110:
      v12 = v105;
      goto LABEL_93;
    }
    a4 = v68;
    v8 = v129;
    a2 = v130;
    a6 = v65;
    v13 = v131 + v73;
    a5 = v67;
    a3 = v66;
    v9 = v72;
    a1 = v74;
    v14 = v71;
    v11 = v70;
    goto LABEL_6;
  }
LABEL_116:
  __break(0x5512u);
LABEL_117:
  __break(1u);
  return cam_isp_blob_hfr_update(v22, a2, a3, a4);
}
