__int64 __fastcall cam_soc_util_reg_dump_to_cmd_buf(
        const void *a1,
        unsigned int *a2,
        __int64 a3,
        _DWORD *a4,
        __int64 a5,
        __int64 a6,
        char a7,
        __int64 a8,
        unsigned __int64 a9)
{
  unsigned int v11; // w8
  unsigned int v12; // w9
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x21
  unsigned __int64 v15; // x28
  unsigned int *v16; // x22
  const void *v17; // x23
  unsigned int v18; // w27
  unsigned int v19; // w0
  unsigned int v20; // w26
  const char *v21; // x5
  __int64 v22; // x4
  unsigned int *v23; // x6
  _DWORD *v24; // x7
  const char *v25; // x5
  __int64 v26; // x4
  __int64 v27; // x6
  __int64 v29; // x8
  unsigned int v30; // w27
  char *v31; // x6
  unsigned int v32; // w28
  unsigned int v33; // w0
  unsigned __int64 v34; // x6
  unsigned int v35; // w26
  int v36; // w6
  unsigned int v37; // w7
  __int64 v38; // x4
  __int64 v39; // x8
  _DWORD *v40; // x28
  char *v41; // x0
  int v42; // w27
  char *v43; // x8
  __int64 v44; // x6
  unsigned int v45; // w0
  char *v46; // x0
  _DWORD *v47; // x3
  __int64 v48; // x22
  __int64 v49; // x26
  __int64 v50; // x27
  char v51; // w28
  __int64 v52; // x23
  const char *v53; // x5
  __int64 v54; // x4
  __int64 v55; // x26
  char v56; // w27
  unsigned int v57; // [xsp+1Ch] [xbp-64h]
  char *v58; // [xsp+20h] [xbp-60h]
  char *v59; // [xsp+20h] [xbp-60h]
  __int64 v60; // [xsp+28h] [xbp-58h]
  __int64 v61; // [xsp+28h] [xbp-58h]
  char v62; // [xsp+34h] [xbp-4Ch]
  unsigned __int64 v63; // [xsp+38h] [xbp-48h]
  const void *v64; // [xsp+40h] [xbp-40h]
  const void *v65; // [xsp+40h] [xbp-40h]
  const void *v66; // [xsp+40h] [xbp-40h]
  __int64 v67; // [xsp+48h] [xbp-38h]
  __int64 v68; // [xsp+50h] [xbp-30h]
  unsigned int v69; // [xsp+5Ch] [xbp-24h] BYREF
  _DWORD *v70; // [xsp+60h] [xbp-20h] BYREF
  char *v71; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v72[2]; // [xsp+70h] [xbp-10h] BYREF

  v72[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = nullptr;
  v72[0] = 0;
  v70 = nullptr;
  v69 = 0;
  if ( !a1 || !a2 || !a4 )
  {
    v21 = "Invalid args to reg dump [%pK] [%pK]";
    v22 = 5362;
    v23 = a2;
    v24 = a4;
LABEL_21:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned int *, _DWORD *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_reg_dump_to_cmd_buf",
      v22,
      v21,
      v23,
      v24);
LABEL_25:
    v20 = -22;
    goto LABEL_26;
  }
  v12 = a2[2];
  v11 = a2[3];
  if ( !v11 || !v12 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_reg_dump_to_cmd_buf",
      5368,
      "Invalid cmd buf size %d %d",
      v11,
      v12);
    goto LABEL_25;
  }
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    v48 = a3;
    v65 = a1;
    v49 = a5;
    v50 = a6;
    v51 = a7;
    v52 = a8;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_reg_dump_to_cmd_buf",
      5373,
      " Get cpu buf success req_id: %llu buf_size: %zu",
      a3,
      a9);
    a1 = v65;
    a8 = v52;
    a7 = v51;
    a6 = v50;
    a5 = v49;
    a3 = v48;
  }
  v13 = a2[1];
  if ( a9 < 4 || a9 - 4 < v13 )
  {
    v25 = "Invalid offset for cmd buf: %zu";
    v26 = 5378;
    v27 = a2[1];
LABEL_24:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_reg_dump_to_cmd_buf",
      v26,
      v25,
      v27);
    goto LABEL_25;
  }
  v15 = a2[2];
  v14 = a2[3];
  if ( a9 - v13 < v15 || (unsigned int)v15 < (unsigned int)v14 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_reg_dump_to_cmd_buf",
      5388,
      "Invalid params for cmd buf len: %zu size: %zu remain_len: %zu",
      a2[3],
      a2[3],
      a9 - v13);
    goto LABEL_25;
  }
  v16 = (unsigned int *)(v13 + a8);
  v17 = (const void *)(v13 + a8 + v15);
  if ( (unsigned __int64)v17 <= v13 + a8 || (unsigned int *)((char *)v16 + v14) <= v16 )
  {
    v21 = "Invalid length or size for cmd buf: [%zu] [%zu]";
    v22 = 5399;
    v23 = (unsigned int *)a2[3];
    v24 = (_DWORD *)a2[2];
    goto LABEL_21;
  }
  v68 = a3;
  if ( (debug_mdl & 0x20000) == 0 || debug_priority )
  {
    v18 = *v16;
    if ( *v16 )
      goto LABEL_18;
    goto LABEL_88;
  }
  v66 = a1;
  v61 = a5;
  v55 = a6;
  v56 = a7;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x20000,
    4,
    "cam_soc_util_reg_dump_to_cmd_buf",
    5405,
    "Buffer params start [%pK] input_end [%pK] buf_end [%pK]",
    v16,
    (char *)v16 + v14,
    v17);
  a1 = v66;
  a5 = v61;
  a7 = v56;
  a6 = v55;
  v18 = *v16;
  if ( !*v16 )
  {
LABEL_88:
    v27 = v68;
    v25 = "Invalid number of dump sets 0, req_id: [%llu]";
    v26 = 5410;
    goto LABEL_24;
  }
LABEL_18:
  v63 = v15;
  v64 = a1;
  v62 = a7;
  v67 = a6;
  v60 = a5;
  v19 = cam_common_mem_kdup(v72, v16, 4LL * (v18 - 1) + 8);
  if ( !v19 )
  {
    v29 = v72[0];
    if ( v18 == *(_DWORD *)v72[0] )
    {
      if ( v18 >= 0x3FFFFFFF )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_reg_dump_to_cmd_buf",
          5434,
          "Integer Overflow req_id: [%llu] num_dump_sets: [%u]",
          v68,
          v18);
        v20 = -75;
LABEL_34:
        cam_common_mem_free(v72[0]);
        goto LABEL_26;
      }
      if ( 4 * (unsigned __int64)(v18 - 1) + 8 >= v14 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_reg_dump_to_cmd_buf",
          5445,
          "Invalid number of dump sets, req_id: [%llu] num_dump_sets: [%u]",
          v68,
          v18);
        v20 = -22;
        goto LABEL_34;
      }
      if ( (debug_mdl & 0x20000) == 0
        || debug_priority
        || (((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x20000,
              4,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5452,
              "reg_input_info req_id: %llu ctx %pK num_dump_sets: %d",
              v68,
              v64,
              v18),
            v29 = v72[0],
            *(_DWORD *)v72[0]) )
      {
        v30 = 0;
        while ( 1 )
        {
          v31 = (char *)*(unsigned int *)(v29 + 4LL * (int)v30 + 4);
          if ( (unsigned int)v14 <= (unsigned int)v31 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5459,
              "Invalid dump set offset: [%pK], cmd_buf_start: [%pK] cmd_in_data_end: [%pK]",
              v31,
              v16,
              (char *)v16 + v14);
            v20 = -22;
            goto LABEL_34;
          }
          v32 = *(_DWORD *)&v31[(_QWORD)v16 + 12];
          if ( !v32 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5470,
              "Invalid number of read ranges 0, req_id: [%llu]",
              v68);
            v20 = -22;
            goto LABEL_34;
          }
          v58 = &v31[(_QWORD)v16];
          v33 = cam_common_mem_kdup(&v71, &v31[(_QWORD)v16], 16);
          if ( v33 )
          {
            v20 = v33;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5479,
              "Alloc and copy req: [%llu] desc fail",
              v68);
            goto LABEL_34;
          }
          if ( v32 != *((_DWORD *)v71 + 3) )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5484,
              "TOCTOU race with userland, error out");
            v20 = 0;
            goto LABEL_86;
          }
          if ( v32 >= 0x2762763 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5494,
              "Integer Overflow req_id: [%llu] num_read_range: [%u]",
              v68,
              v32);
            v20 = -75;
            goto LABEL_86;
          }
          if ( (char *)v16 + v14 - v71 <= 104 * (unsigned __int64)(v32 - 1) + 120 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5506,
              "Invalid number of read ranges, req_id: [%llu] num_read_range: [%d]",
              v68,
              v32);
            goto LABEL_85;
          }
          v34 = *((unsigned int *)v71 + 1);
          if ( v34 + 16 >= v63 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5517,
              "Invalid out buffer offset: [%pK],  cmd_buf_start: [%pK] cmd_buf_end: [%pK]",
              (const void *)v34,
              v16,
              v17);
            goto LABEL_85;
          }
          v35 = *(_DWORD *)v71;
          if ( (unsigned int)(*(_DWORD *)v71 - 9) <= 0xFFFFFFF7 )
            break;
          if ( *(a4 - 1) != 1563550165 )
            __break(0x8233u);
          v36 = ((__int64 (__fastcall *)(_QWORD, const void *, _DWORD **, unsigned int *))a4)(v35, v64, &v70, &v69);
          if ( v36 || !v70 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5536,
              "Reg space data callback failed rc: %d soc_info: [%pK]",
              v36,
              v70);
            goto LABEL_85;
          }
          v37 = v70[120];
          v38 = v67;
          v39 = v68;
          if ( v69 > v37 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5544,
              "Invalid reg base idx: %d num reg map: %d",
              v69,
              v37);
            goto LABEL_85;
          }
          if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x20000,
              4,
              "cam_soc_util_reg_dump_to_cmd_buf",
              5552,
              "Reg data callback success req_id: %llu base_type: %d base_idx: %d num_read_range: %d",
              v68,
              v35,
              v69,
              *((_DWORD *)v71 + 3));
            v38 = v67;
            v39 = v68;
            if ( (v62 & 1) != 0 )
            {
LABEL_71:
              v47 = v70;
              v46 = v71;
              *(_DWORD *)(v38 + 12) = v35;
              v20 = cam_soc_util_user_reg_dump(v46, v58, v60, v47);
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x20000,
                3,
                "cam_soc_util_reg_dump_to_cmd_buf",
                5566,
                "%s reg_base_idx %d dumped offset %u",
                *((const char **)v70 + 3),
                v69,
                *(_QWORD *)(v60 + 8));
              goto LABEL_86;
            }
          }
          else if ( (v62 & 1) != 0 )
          {
            goto LABEL_71;
          }
          v40 = (unsigned int *)((char *)v16 + *((unsigned int *)v71 + 1));
          *(_QWORD *)v40 = v39;
          v41 = v71;
          v40[2] = 0;
          *(_DWORD *)(v38 + 12) = v35;
          if ( *((_DWORD *)v41 + 3) )
          {
            v57 = v30;
            v42 = 0;
            v59 = v58 + 16;
            while ( 1 )
            {
              if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x20000,
                  4,
                  "cam_soc_util_reg_dump_to_cmd_buf",
                  5583,
                  "Number of bytes written to cmd buffer: %u req_id: %llu",
                  v40[2],
                  v68);
              v43 = &v59[104 * v42];
              v44 = *(unsigned int *)v43;
              if ( (unsigned int)(v44 - 2) >= 2 )
              {
                if ( (_DWORD)v44 != 1 )
                {
                  v53 = "Invalid Reg dump read type: %d";
                  v54 = 5599;
                  goto LABEL_82;
                }
                v45 = cam_soc_util_dump_cont_reg_range(v70, v43 + 8, v69, v40, v17);
              }
              else
              {
                v45 = ((__int64 (__fastcall *)(_DWORD *, char *, _QWORD, _DWORD *))cam_soc_util_dump_dmi_ctxt_reg_range)(
                        v70,
                        v43 + 8,
                        v69,
                        v40);
              }
              v20 = v45;
              if ( v45 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x20000,
                  1,
                  "cam_soc_util_reg_dump_to_cmd_buf",
                  5607,
                  "Reg range read failed rc: %d reg_base_idx: %d dump_out_buf: %pK",
                  v45,
                  v69,
                  v40);
                goto LABEL_86;
              }
              if ( (unsigned int)++v42 >= *((_DWORD *)v71 + 3) )
              {
                v30 = v57;
                break;
              }
            }
          }
          ((void (*)(void))cam_common_mem_free)();
          v29 = v72[0];
          ++v30;
          v20 = 0;
          if ( v30 >= *(_DWORD *)v72[0] )
            goto LABEL_34;
        }
        v53 = "Invalid Reg dump base type: %d";
        v54 = 5527;
        v44 = v35;
LABEL_82:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_reg_dump_to_cmd_buf",
          v54,
          v53,
          v44);
LABEL_85:
        v20 = -22;
LABEL_86:
        cam_common_mem_free(v71);
        goto LABEL_34;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_reg_dump_to_cmd_buf",
        5425,
        "TOCTOU race with userland, error out");
    }
    v20 = 0;
    goto LABEL_34;
  }
  v20 = v19;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_reg_dump_to_cmd_buf",
    5420,
    "Alloc and copy req: %llu input info fail",
    v68);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v20;
}
