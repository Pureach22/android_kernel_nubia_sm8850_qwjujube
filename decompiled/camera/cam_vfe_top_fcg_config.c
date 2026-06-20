__int64 __fastcall cam_vfe_top_fcg_config(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x22
  __int64 v4; // x8
  int v5; // w9
  __int64 v6; // x10
  __int64 v7; // x0
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 result; // x0
  const char *v10; // x3
  const char *v11; // x5
  __int64 v12; // x4
  __int64 v13; // x20
  __int64 v14; // x25
  _DWORD *v15; // x24
  __int64 v17; // x0
  _QWORD *v18; // x19
  int v19; // w10
  int v20; // w6
  int v21; // w9
  const char *v22; // x15
  const char *v23; // x16
  const char *v24; // x13
  __int64 v25; // x1
  unsigned int v26; // w7
  unsigned int *v27; // x17
  unsigned int v28; // w8
  _DWORD *v29; // x2
  int v30; // w14
  char v31; // w3
  int v32; // w8
  int v33; // w3
  unsigned int v34; // w6
  int v35; // w8
  signed int v36; // w8
  char v37; // w3
  const char *v38; // x20
  int v39; // w14
  unsigned int v40; // w6
  char v41; // w3
  int v42; // w8
  signed int v43; // w3
  unsigned int v44; // w6
  int v45; // w8
  signed int v46; // w8
  char v47; // w3
  const char *v48; // x20
  const char *v49; // x20
  unsigned int v50; // w20
  unsigned int v51; // w20
  unsigned int v52; // w20
  unsigned int v53; // w20
  unsigned int v54; // w20
  const char *v55; // x20
  int v56; // w20
  const char *v57; // x5
  __int64 v58; // x4
  int v59; // w8
  int v60; // w8
  unsigned int v61; // w20
  unsigned int v62; // w20
  _DWORD *v63; // x8
  _DWORD *v64; // x8
  __int64 v65; // x0
  const char *v66; // x5
  __int64 v67; // x4
  int v68; // [xsp+14h] [xbp-1Ch]
  unsigned int v69; // [xsp+14h] [xbp-1Ch]
  int v70; // [xsp+14h] [xbp-1Ch]
  unsigned int *v71; // [xsp+18h] [xbp-18h]
  __int64 v72; // [xsp+18h] [xbp-18h]
  unsigned int *v73; // [xsp+18h] [xbp-18h]
  unsigned int *v74; // [xsp+18h] [xbp-18h]
  unsigned int *v75; // [xsp+18h] [xbp-18h]
  unsigned int *v76; // [xsp+18h] [xbp-18h]
  unsigned int *v77; // [xsp+18h] [xbp-18h]
  __int64 v78; // [xsp+18h] [xbp-18h]
  _DWORD *v79; // [xsp+20h] [xbp-10h]
  __int64 v80; // [xsp+20h] [xbp-10h]
  _DWORD *v81; // [xsp+20h] [xbp-10h]
  _DWORD *v82; // [xsp+20h] [xbp-10h]
  _DWORD *v83; // [xsp+20h] [xbp-10h]
  _DWORD *v84; // [xsp+20h] [xbp-10h]
  _DWORD *v85; // [xsp+20h] [xbp-10h]
  __int64 v86; // [xsp+20h] [xbp-10h]
  int v87; // [xsp+28h] [xbp-8h]
  int v88; // [xsp+28h] [xbp-8h]
  int v89; // [xsp+28h] [xbp-8h]
  int v90; // [xsp+28h] [xbp-8h]
  int v91; // [xsp+28h] [xbp-8h]
  int v92; // [xsp+28h] [xbp-8h]
  int v93; // [xsp+28h] [xbp-8h]
  int v94; // [xsp+28h] [xbp-8h]
  int v95; // [xsp+28h] [xbp-8h]
  int v96; // [xsp+28h] [xbp-8h]
  int v97; // [xsp+2Ch] [xbp-4h]
  int v98; // [xsp+2Ch] [xbp-4h]
  int v99; // [xsp+2Ch] [xbp-4h]
  int v100; // [xsp+2Ch] [xbp-4h]
  int v101; // [xsp+2Ch] [xbp-4h]
  int v102; // [xsp+2Ch] [xbp-4h]
  int v103; // [xsp+2Ch] [xbp-4h]
  int v104; // [xsp+2Ch] [xbp-4h]
  int v105; // [xsp+2Ch] [xbp-4h]
  int v106; // [xsp+2Ch] [xbp-4h]
  __int64 v107; // [xsp+48h] [xbp+18h]
  __int64 v108; // [xsp+48h] [xbp+18h]
  __int64 v109; // [xsp+48h] [xbp+18h]
  __int64 v110; // [xsp+48h] [xbp+18h]
  __int64 v111; // [xsp+48h] [xbp+18h]
  __int64 v112; // [xsp+48h] [xbp+18h]
  __int64 v113; // [xsp+48h] [xbp+18h]
  __int64 v114; // [xsp+48h] [xbp+18h]
  __int64 v115; // [xsp+48h] [xbp+18h]
  __int64 v116; // [xsp+48h] [xbp+18h]

  if ( a3 != 40 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_fcg_config",
      1875,
      "Invalid cmd size, arg_size: %u, expected size: %u",
      a3,
      40);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)a2 )
  {
    v10 = "cam_vfe_top_fcg_config";
    v11 = "Invalid cmd args";
    v12 = 1881;
LABEL_31:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      v10,
      v12,
      v11);
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a2 + 48LL);
  if ( !v3 )
  {
    v10 = "cam_vfe_top_fcg_config";
    v11 = "Invalid CDM ops";
    v12 = 1888;
    goto LABEL_31;
  }
  if ( *(_BYTE *)(a2 + 12) == 1 )
  {
    v4 = *(_QWORD *)(a1 + 16);
    if ( v4 )
    {
      if ( (*(_BYTE *)(v4 + 296) & 1) == 0 && (*(_BYTE *)(v4 + 297) & 1) == 0 )
      {
        result = 0;
        *(_BYTE *)(a2 + 28) = 0;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_top_get_fcg_buf_size",
            1841,
            "FCG is not supported by hardware");
          return 0;
        }
        return result;
      }
      v5 = *(_DWORD *)(a2 + 16);
      v6 = *(_QWORD *)(v4 + 216);
      *(_BYTE *)(a2 + 28) = 1;
      if ( v5 )
      {
        v7 = (unsigned int)(*(_DWORD *)(v6 + 16) * v5);
        if ( *(_BYTE *)(v4 + 297) == 1 )
          v7 = (unsigned int)(*(_DWORD *)(a2 + 20) + v7);
        v8 = *(__int64 (__fastcall **)(_QWORD))(v3 + 24);
        if ( *((_DWORD *)v8 - 1) != 2010610996 )
          __break(0x8228u);
        *(_DWORD *)(a2 + 24) = v8(v7);
        return 0;
      }
      v10 = "cam_vfe_top_get_fcg_buf_size";
      v11 = "Number of types(STATS/PHASE) requested is empty";
      v12 = 1849;
    }
    else
    {
      v10 = "cam_vfe_top_get_fcg_buf_size";
      v11 = "Invalid config params";
      v12 = 1834;
    }
    goto LABEL_31;
  }
  if ( !*(_DWORD *)(a2 + 28) )
  {
    v10 = "cam_vfe_top_apply_fcg_update";
    v11 = "Invalid args";
    v12 = 1652;
    goto LABEL_31;
  }
  v13 = *(_QWORD *)(a1 + 16);
  if ( !v13 || (v14 = *(_QWORD *)(a2 + 32)) == 0 )
  {
    v10 = "cam_vfe_top_apply_fcg_update";
    v11 = "Invalid config params";
    v12 = 1659;
    goto LABEL_31;
  }
  v15 = *(_DWORD **)(v13 + 216);
  if ( !v15 )
  {
    v10 = "cam_vfe_top_apply_fcg_update";
    v11 = "Invalid FCG common data";
    v12 = 1665;
    goto LABEL_31;
  }
  if ( *(_DWORD *)v14 >= 4u )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_vfe_top_apply_fcg_update",
      1671,
      "out of bounds %d",
      *(_DWORD *)v14);
    return 4294967274LL;
  }
  if ( mem_trace_en == 1 )
    v17 = cam_mem_trace_alloc(4LL * (unsigned int)v15[3], 0xCC0u, 0, "cam_vfe_top_apply_fcg_update", 0x68Du);
  else
    v17 = _kvmalloc_node_noprof(4LL * (unsigned int)v15[3], 0, 3520, 0xFFFFFFFFLL);
  v18 = (_QWORD *)v17;
  if ( !v17 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_apply_fcg_update",
      1679,
      "Failed allocating memory for reg val pair");
    return 4294967284LL;
  }
  if ( !*(_DWORD *)v14 )
    goto LABEL_87;
  v19 = v15[2];
  v20 = 0;
  v21 = 0;
  v22 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, sel_wr: 0x%x";
  v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
  v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
  v25 = a2;
  while ( 1 )
  {
    v26 = v15[3];
    if ( v20 >= v26 )
    {
      v57 = "reg_val_pair %d exceeds the array limit %u";
      v58 = 1688;
      goto LABEL_81;
    }
    v27 = (unsigned int *)(*(_QWORD *)(v14 + 16) + 16LL * v21);
    if ( !v27 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_fcg_update",
        1695,
        "Failed in FCG channel/context dereference");
      v59 = -22;
      goto LABEL_89;
    }
    if ( (v27[1] & 1) != 0 )
      break;
LABEL_41:
    if ( (unsigned int)++v21 >= *(_DWORD *)v14 )
    {
      if ( v20 >= 0 )
        v60 = v20;
      else
        v60 = v20 + 1;
      if ( (unsigned int)(v20 + 1) < 3 )
      {
LABEL_87:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_top_apply_fcg_update",
          1810,
          "No reg val pairs");
LABEL_88:
        v59 = 0;
        goto LABEL_89;
      }
      v62 = v60 >> 1;
      v63 = *(_DWORD **)(v3 + 24);
      if ( *(v63 - 1) != 2010610996 )
        __break(0x8228u);
      if ( 4 * ((unsigned int (__fastcall *)(_QWORD, __int64))v63)(v62, v25) == *(_DWORD *)(a2 + 24) )
      {
        v64 = *(_DWORD **)(v3 + 120);
        v65 = *(_QWORD *)(a2 + 16);
        if ( *(v64 - 1) != -1401492769 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD *))v64)(v65, v62, v18);
        goto LABEL_88;
      }
      v57 = "Failed! Buf size:%d is wrong, expected size: %d";
      v58 = 1801;
LABEL_81:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_fcg_update",
        v58,
        v57);
      v59 = -12;
      goto LABEL_89;
    }
  }
  v28 = *v27;
  v29 = (_DWORD *)(*((_QWORD *)v27 + 1) + 24LL * (unsigned int)(*(_DWORD *)(v25 + 28) - 1));
  if ( *v27 == 4 || v28 == 2 )
  {
    if ( (*(_BYTE *)(v13 + 297) & 1) == 0 )
    {
      v66 = "No support for multi context for FCG on ch_ctx_id: 0x%x";
      v67 = 1746;
      goto LABEL_102;
    }
    if ( v20 >= v26 - 1 )
    {
      v110 = v13;
      v50 = v20;
      v80 = *((_QWORD *)v27 + 1) + 24LL * (unsigned int)(*(_DWORD *)(v25 + 28) - 1);
      v90 = v21;
      v100 = v19;
      v72 = *(_QWORD *)(v14 + 16) + 16LL * v21;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_fcg_update",
        1757,
        "Exceed buf size %u when adding reg/val at index %u and %u",
        v26,
        v20,
        v20 + 1);
      v21 = v90;
      v19 = v100;
      v29 = (_DWORD *)v80;
      v27 = (unsigned int *)v72;
      v40 = v50;
      v13 = v110;
      v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v22 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, sel_wr: 0x%x";
      v25 = a2;
      v41 = debug_mdl;
      if ( (debug_mdl & 8) != 0 )
      {
LABEL_62:
        if ( !debug_priority )
        {
          v79 = v29;
          v69 = v40;
          v109 = v13;
          v49 = v22;
          v89 = v21;
          v99 = v19;
          v71 = v27;
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
            3,
            v41 & 8,
            4,
            "cam_vfe_top_apply_fcg_update",
            1763,
            v22,
            *v27,
            (*v27 << v15[7]) & v15[8]);
          v21 = v89;
          v19 = v99;
          v29 = v79;
          v27 = v71;
          v22 = v49;
          v13 = v109;
          v40 = v69;
          v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
          v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
          v25 = a2;
        }
      }
    }
    else
    {
      *((_DWORD *)v18 + v20) = v15[9] + *(_DWORD *)(v13 + 272);
      v39 = v20 + 1;
      v40 = v20 + 2;
      *((_DWORD *)v18 + v39) = (*v27 << v15[7]) & v15[8];
      v41 = debug_mdl;
      if ( (debug_mdl & 8) != 0 )
        goto LABEL_62;
    }
    v42 = v15[3];
    if ( v40 >= v42 - 1 )
    {
      v111 = v13;
      v51 = v40;
      v81 = v29;
      v91 = v21;
      v101 = v19;
      v73 = v27;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_fcg_update",
        1770,
        "Exceed buf size %u when adding reg/val at index %u and %u",
        v42,
        v40,
        v40 + 1);
      v21 = v91;
      v19 = v101;
      v29 = v81;
      v27 = v73;
      v44 = v51;
      v13 = v111;
      v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v22 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, sel_wr: 0x%x";
      v25 = a2;
    }
    else
    {
      v43 = v40 + 1;
      *((_DWORD *)v18 + (int)v40) = v15[5] + *(_DWORD *)(v13 + 272);
      v44 = v40 + 2;
      *((_DWORD *)v18 + v43) = (*v29 << v19) | v29[1];
    }
    v45 = v15[3];
    if ( v44 >= v45 - 1 )
    {
      v112 = v13;
      v52 = v44;
      v82 = v29;
      v92 = v21;
      v102 = v19;
      v74 = v27;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_fcg_update",
        1775,
        "Exceed buf size %u when adding reg/val at index %u and %u",
        v45,
        v44,
        v44 + 1);
      v21 = v92;
      v19 = v102;
      v29 = v82;
      v27 = v74;
      v20 = v52;
      v13 = v112;
      v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v22 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, sel_wr: 0x%x";
      v25 = a2;
      v47 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_41;
    }
    else
    {
      *((_DWORD *)v18 + (int)v44) = v15[6] + *(_DWORD *)(v13 + 272);
      v46 = v44 + 1;
      v20 = v44 + 2;
      *((_DWORD *)v18 + v46) = v29[2];
      v47 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_41;
    }
    if ( debug_priority )
      goto LABEL_41;
    v68 = v20;
    v108 = v13;
    v48 = v23;
    v88 = v21;
    v98 = v19;
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
      3,
      v47 & 8,
      4,
      "cam_vfe_top_apply_fcg_update",
      1781,
      v23,
      *v27,
      (unsigned int)((*v29 << v19) | v29[1]),
      v29[2]);
    v21 = v88;
    v19 = v98;
    v23 = v48;
    v13 = v108;
    v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
LABEL_40:
    v20 = v68;
    v22 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, sel_wr: 0x%x";
    v25 = a2;
    goto LABEL_41;
  }
  if ( v28 == 1 )
  {
    if ( *(_BYTE *)(v13 + 297) == 1 )
    {
      if ( v20 >= v26 - 1 )
      {
        v116 = v13;
        v56 = v20;
        v86 = *((_QWORD *)v27 + 1) + 24LL * (unsigned int)(*(_DWORD *)(v25 + 28) - 1);
        v96 = v21;
        v106 = v19;
        v78 = *(_QWORD *)(v14 + 16) + 16LL * v21;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_top_apply_fcg_update",
          1715,
          "Exceed buf size %u when adding reg/val at index %u and %u",
          v26,
          v20,
          v20 + 1);
        v21 = v96;
        v19 = v106;
        v29 = (_DWORD *)v86;
        v27 = (unsigned int *)v78;
        v20 = v56;
        v13 = v116;
        v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
        v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
        v22 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, sel_wr: 0x%x";
        v25 = a2;
        v31 = debug_mdl;
        if ( (debug_mdl & 8) != 0 )
        {
LABEL_51:
          if ( !debug_priority )
          {
            v85 = v29;
            v70 = v20;
            v115 = v13;
            v55 = v22;
            v95 = v21;
            v105 = v19;
            v77 = v27;
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
              3,
              v31 & 8,
              4,
              "cam_vfe_top_apply_fcg_update",
              1721,
              v22,
              *v27,
              (*v27 << v15[7]) & v15[8]);
            v21 = v95;
            v19 = v105;
            v29 = v85;
            v27 = v77;
            v22 = v55;
            v13 = v115;
            v20 = v70;
            v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
            v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
            v25 = a2;
          }
        }
      }
      else
      {
        *((_DWORD *)v18 + v20) = v15[9] + *(_DWORD *)(v13 + 272);
        v30 = v20 + 1;
        v20 += 2;
        *((_DWORD *)v18 + v30) = (*v27 << v15[7]) & v15[8];
        v31 = debug_mdl;
        if ( (debug_mdl & 8) != 0 )
          goto LABEL_51;
      }
    }
    v32 = v15[3];
    if ( v20 >= (unsigned int)(v32 - 1) )
    {
      v113 = v13;
      v53 = v20;
      v83 = v29;
      v93 = v21;
      v103 = v19;
      v75 = v27;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_fcg_update",
        1728,
        "Exceed buf size %u when adding reg/val at index %u and %u",
        v32,
        v20,
        v20 + 1);
      v21 = v93;
      v19 = v103;
      v29 = v83;
      v27 = v75;
      v34 = v53;
      v13 = v113;
      v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v22 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, sel_wr: 0x%x";
      v25 = a2;
    }
    else
    {
      v33 = v20 + 1;
      *((_DWORD *)v18 + v20) = v15[5] + *(_DWORD *)(v13 + 272);
      v34 = v20 + 2;
      *((_DWORD *)v18 + v33) = (*v29 << v19) | v29[1];
    }
    v35 = v15[3];
    if ( v34 >= v35 - 1 )
    {
      v114 = v13;
      v54 = v34;
      v84 = v29;
      v94 = v21;
      v104 = v19;
      v76 = v27;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_fcg_update",
        1733,
        "Exceed buf size %u when adding reg/val at index %u and %u",
        v35,
        v34,
        v34 + 1);
      v21 = v94;
      v19 = v104;
      v29 = v84;
      v27 = v76;
      v20 = v54;
      v13 = v114;
      v24 = "Program FCG registers for IFE/MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
      v22 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, sel_wr: 0x%x";
      v25 = a2;
      v37 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_41;
    }
    else
    {
      *((_DWORD *)v18 + (int)v34) = v15[6] + *(_DWORD *)(v13 + 272);
      v36 = v34 + 1;
      v20 = v34 + 2;
      *((_DWORD *)v18 + v36) = v29[2];
      v37 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_41;
    }
    if ( debug_priority )
      goto LABEL_41;
    v68 = v20;
    v107 = v13;
    v38 = v24;
    v87 = v21;
    v97 = v19;
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
      3,
      v37 & 8,
      4,
      "cam_vfe_top_apply_fcg_update",
      1739,
      v24,
      *v27,
      (unsigned int)((*v29 << v19) | v29[1]),
      v29[2]);
    v21 = v87;
    v19 = v97;
    v24 = v38;
    v13 = v107;
    v23 = "Program FCG registers for MC_TFE, ch_ctx_id: 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
    goto LABEL_40;
  }
  v66 = "Unsupported ch_ctx_id: 0x%x";
  v67 = 1785;
LABEL_102:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_top_apply_fcg_update",
    v67,
    v66,
    v28);
  v59 = -22;
LABEL_89:
  v61 = v59;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v18, 0);
  else
    kvfree(v18);
  return v61;
}
