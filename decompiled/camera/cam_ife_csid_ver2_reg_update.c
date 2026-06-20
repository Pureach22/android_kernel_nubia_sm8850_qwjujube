__int64 __fastcall cam_ife_csid_ver2_reg_update(__int64 a1, __int64 *a2, int a3)
{
  const char *v3; // x5
  __int64 v4; // x6
  __int64 v5; // x4
  __int64 *v7; // x26
  __int64 v8; // x24
  __int64 v11; // x27
  unsigned int v12; // w19
  __int64 v13; // x22
  __int64 (__fastcall *v14)(_QWORD); // x8
  int v15; // w20
  unsigned int *v16; // x21
  __int64 *v17; // x9
  __int64 v18; // x10
  char v19; // w8
  __int64 v20; // x15
  __int64 v21; // x11
  __int64 v22; // x13
  unsigned __int64 v23; // x12
  unsigned int v24; // w8
  __int64 v25; // x15
  __int64 v26; // x7
  __int64 v27; // x16
  __int64 v28; // x15
  unsigned __int64 v29; // x14
  int v30; // w13
  unsigned int v31; // w12
  __int64 v32; // x7
  __int64 v33; // x17
  __int64 v34; // x8
  _DWORD *v35; // x0
  unsigned int v36; // w12
  int v37; // w13
  unsigned int v38; // w8
  __int64 v39; // x7
  bool v40; // zf
  const char *v41; // x9
  int v42; // w14
  __int64 v43; // x15
  char v44; // w16
  int v45; // w13
  int v46; // w14
  _DWORD *v47; // x11
  int v48; // w15
  __int64 v49; // x6
  int v50; // w9
  unsigned int v51; // w10
  int v52; // w11
  const char *v53; // x12
  const char *v54; // x15
  _DWORD *v55; // x8
  __int64 v56; // x0
  __int64 *v57; // x22
  unsigned __int64 StatusReg; // [xsp+40h] [xbp-10h]
  __int64 v59; // [xsp+48h] [xbp-8h]

  if ( a3 != 136 )
  {
    v3 = "CSID[%u] Invalid arg size: %d expected:%ld";
    v4 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v5 = 7948;
    goto LABEL_5;
  }
  if ( (unsigned int)(*((_DWORD *)a2 + 28) - 13) <= 0xFFFFFFF3 )
  {
    v3 = "CSID[%u] Invalid num_res %u";
    v4 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v5 = 7960;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_reg_update",
      v5,
      v3,
      v4);
    return 4294967274LL;
  }
  v7 = a2 + 2;
  v8 = *(_QWORD *)(a2[2] + 48);
  if ( !v8 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_reg_update",
      7966,
      "CSID[%u] Invalid CDM ops",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
    return 4294967274LL;
  }
  v11 = **(_QWORD **)(a1 + 31136);
  if ( (*(_BYTE *)(*(_QWORD *)(v11 + 120) + 828LL) & 0x10) != 0 )
  {
    if ( *((_BYTE *)a2 + 130) )
      v12 = 2;
    else
      v12 = 3;
  }
  else
  {
    v12 = 1;
  }
  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL);
  v14 = *(__int64 (__fastcall **)(_QWORD))(v8 + 24);
  if ( *((_DWORD *)v14 - 1) != 2010610996 )
    __break(0x8228u);
  v15 = v14(v12);
  if ( (a2[16] & 1) == 0 && (unsigned int)(4 * v15) > *((_DWORD *)a2 + 2) )
  {
    v3 = "CSID[%u] buf size:%d is not sufficient, expected: %d";
    v4 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v5 = 7981;
    goto LABEL_5;
  }
  if ( mem_trace_en != 1 )
  {
    v16 = (unsigned int *)_kvmalloc_node_noprof(8 * v12, 0, 3520, 0xFFFFFFFFLL);
    if ( v16 )
      goto LABEL_21;
    goto LABEL_34;
  }
  v16 = (unsigned int *)cam_mem_trace_alloc(8 * v12, 0xCC0u, 0, "cam_ife_csid_ver2_reg_update", 0x1F31u);
  if ( !v16 )
  {
LABEL_34:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_reg_update",
      7987,
      "Failed at allocating memory for reg_val_pair");
    return 4294967284LL;
  }
  while ( 1 )
  {
LABEL_21:
    v17 = a2;
    v18 = a1;
    if ( *((_DWORD *)a2 + 31) )
    {
      v19 = debug_mdl;
      *(_DWORD *)(a1 + 2092) = *((_DWORD *)a2 + 30);
      if ( (v19 & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          v19 & 8,
          4,
          "cam_ife_csid_ver2_reg_update",
          7994,
          "CSID[%u] MUP %u",
          *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
        v18 = a1;
        v17 = a2;
      }
    }
    v20 = *((unsigned int *)v17 + 28);
    v21 = **(_QWORD **)(v18 + 31136);
    if ( (*(_BYTE *)(*(_QWORD *)(v11 + 120) + 828LL) & 0x10) != 0 )
      break;
    if ( !(_DWORD)v20 )
    {
      v24 = 0;
LABEL_43:
      v36 = *(_DWORD *)(*(_QWORD *)(v21 + 120) + 24LL);
      *v16 = v36;
      v16[1] = v24;
      if ( *((_BYTE *)v17 + 128) == 1 )
      {
        v37 = *((_DWORD *)v17 + 29);
      }
      else
      {
        v37 = *(_DWORD *)(v18 + 2092);
        if ( *((_BYTE *)v17 + 129) == 1 )
          v37 = (*(_DWORD *)(v18 + 2092) & 1) == 0;
      }
      v39 = (v37 << *(_DWORD *)(*(_QWORD *)(v21 + 120) + 440LL)) | v24;
      v16[1] = v39;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v40 = *((_BYTE *)v17 + 128) == 0;
        v41 = "AHB";
        if ( v40 )
          v41 = "CDM";
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver2_get_sc_reg_val_pair",
          7925,
          "CSID[%d] configure rup_aup_mup: 0x%x offset: 0x%x via %s",
          *(unsigned int *)(*(_QWORD *)(v18 + 31120) + 4LL),
          v39,
          v36,
          v41);
LABEL_76:
        v17 = a2;
        goto LABEL_77;
      }
      goto LABEL_77;
    }
    v22 = 8 * v20;
    v23 = 0;
    v24 = 0;
    while ( v23 != 96 )
    {
      v25 = v7[v23 / 8];
      v26 = *(unsigned int *)(v25 + 4);
      if ( (unsigned int)v26 > 0xB )
        break;
      v27 = *(_QWORD *)(v21 + 136 + 8 * v26);
      if ( !v27 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_get_sc_reg_val_pair",
          7898,
          "CSID:%d Invalid Path Resource [id %d name %s]",
          *(unsigned int *)(*(_QWORD *)(v18 + 31120) + 4LL),
          v26,
          v25 + 128);
        goto LABEL_76;
      }
      v23 += 8LL;
      v24 |= *(_DWORD *)(v27 + 540);
      if ( v22 == v23 )
        goto LABEL_43;
    }
LABEL_88:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v59 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_ife_csid_ver2_reg_update__alloc_tag_390;
    v16 = (unsigned int *)_kvmalloc_node_noprof(8 * v12, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v59;
    if ( !v16 )
      goto LABEL_34;
  }
  if ( (_DWORD)v20 )
  {
    v28 = 8 * v20;
    v29 = 0;
    v30 = 0;
    v31 = 0;
    LODWORD(v32) = 0;
    while ( v29 != 96 )
    {
      v33 = v7[v29 / 8];
      v34 = *(unsigned int *)(v33 + 4);
      if ( (unsigned int)v34 > 0xB )
        break;
      v35 = *(_DWORD **)(v21 + 136 + 8 * v34);
      if ( !v35 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_get_mc_reg_val_pair",
          7833,
          "CSID:%d Invalid Path Resource [id %d name %s]",
          *(unsigned int *)(*(_QWORD *)(v18 + 31120) + 4LL),
          (unsigned int)v34,
          v33 + 128);
        goto LABEL_76;
      }
      v29 += 8LL;
      v32 = v35[136] | (unsigned int)v32;
      v31 |= v35[137];
      v30 |= v35[138];
      if ( v28 == v29 )
        goto LABEL_46;
    }
    goto LABEL_88;
  }
  v32 = 0;
  v31 = 0;
  v30 = 0;
LABEL_46:
  *v16 = *(_DWORD *)(*(_QWORD *)(v21 + 120) + 28LL);
  v16[1] = v32;
  if ( (*((_BYTE *)v17 + 130) & 1) != 0 )
  {
    v38 = 2;
  }
  else
  {
    v16[2] = *(_DWORD *)(*(_QWORD *)(v21 + 120) + 32LL);
    v16[3] = v31;
    v38 = 4;
  }
  if ( *((_BYTE *)v17 + 128) == 1 )
  {
    v42 = *((_DWORD *)v17 + 29);
  }
  else
  {
    v42 = *(_DWORD *)(v18 + 2092);
    if ( *((_BYTE *)v17 + 129) == 1 )
      v42 = (*(_DWORD *)(v18 + 2092) & 1) == 0;
  }
  v43 = *(_QWORD *)(v21 + 120);
  v44 = *(_DWORD *)(v43 + 440);
  v16[v38] = *(_DWORD *)(v43 + 24);
  v45 = (v42 << v44) | v30;
  v16[v38 | 1] = v45;
  if ( (debug_mdl & 8) != 0 )
  {
    v46 = debug_priority;
    if ( !debug_priority )
    {
      v47 = *(_DWORD **)(v21 + 120);
      v48 = *((unsigned __int8 *)v17 + 130);
      v49 = *(unsigned int *)(*(_QWORD *)(v18 + 31120) + 4LL);
      v50 = v47[7];
      if ( v48 )
        v51 = 0;
      else
        v51 = v31;
      if ( (v48 & 1) == 0 )
        v46 = v47[8];
      v52 = v47[6];
      if ( *((_BYTE *)a2 + 129) )
        v53 = "Y";
      else
        v53 = "N";
      v54 = "CDM";
      if ( *((_BYTE *)a2 + 128) )
        v54 = "AHB";
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, unsigned int, int, const char *, int, int, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_get_mc_reg_val_pair",
        7873,
        "CSID[%d] configure rup: 0x%x, offset: 0x%x, configure aup: 0x%x, offset: 0x%x, toggle MUP: %s, configure rup_aup"
        "_set: 0x%x, offset: 0x%x via %s",
        v49,
        v32,
        v50,
        v51,
        v46,
        v53,
        v45,
        v52,
        v54);
      goto LABEL_76;
    }
  }
LABEL_77:
  if ( *((_BYTE *)v17 + 128) == 1 )
  {
    cam_io_w_mb(v16[1], v13 + *v16);
    if ( v12 >= 2 )
    {
      cam_io_w_mb(v16[3], v13 + v16[2]);
      if ( v12 != 2 )
        cam_io_w_mb(v16[5], v13 + v16[4]);
    }
  }
  else
  {
    v55 = *(_DWORD **)(v8 + 120);
    v56 = *v17;
    v57 = v17;
    if ( *(v55 - 1) != -1401492769 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, unsigned int *))v55)(v56, v12, v16);
    *((_DWORD *)v57 + 3) = 4 * v15;
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v16, 0);
  else
    kvfree(v16);
  return 0;
}
