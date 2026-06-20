__int64 __fastcall cam_qup_i2c_write_table(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int64 v4; // x23
  __int64 v5; // x21
  unsigned int *v6; // x25
  __int64 v7; // x0
  __int64 v8; // x8
  unsigned int v9; // w16
  int v10; // w22
  unsigned __int64 v11; // x13
  _QWORD *v12; // x17
  int *v13; // x15
  unsigned int *v14; // x19
  unsigned __int64 v15; // x14
  unsigned int v16; // w24
  __int64 v17; // x2
  int v18; // w28
  const char *v19; // x3
  const char *v20; // x5
  const char *v21; // x30
  const char *v22; // x4
  unsigned int v23; // w21
  unsigned int *v24; // x10
  unsigned int v25; // w9
  unsigned int v26; // w6
  __int64 v27; // x9
  int v28; // w9
  __int64 v29; // x1
  int v30; // w27
  unsigned __int64 v31; // x26
  const char *v32; // x19
  const char *v33; // x20
  __int64 v34; // x9
  const char *v35; // x27
  unsigned __int64 v36; // x20
  _QWORD *v37; // x26
  const char *v38; // x19
  const char *v39; // x27
  const char *v40; // x19
  unsigned __int64 v41; // x20
  _QWORD *v42; // x26
  _BYTE *v43; // x10
  _BYTE *v44; // x10
  unsigned int v45; // w9
  __int64 v46; // x10
  int v47; // w9
  __int64 v48; // x1
  int v49; // w26
  const char *v50; // x19
  __int64 v51; // x9
  const char *v52; // x19
  unsigned __int64 v53; // x20
  _QWORD *v54; // x26
  const char *v55; // x21
  const char *v56; // x26
  const char *v57; // x19
  unsigned __int64 v58; // x20
  _BYTE *v59; // x19
  int v60; // w9
  __int64 v61; // x1
  int v62; // w20
  const char *v63; // x19
  _BYTE *v64; // x19
  int v65; // w9
  __int64 v66; // x1
  unsigned int v67; // w9
  unsigned int v68; // w10
  bool v69; // zf
  const char *v70; // x21
  unsigned __int64 v71; // x26
  const char *v72; // x26
  _QWORD *v73; // x26
  const char *v74; // x20
  int v75; // w20
  unsigned __int64 v76; // x26
  const char *v77; // x19
  const char *v78; // x20
  _QWORD *v79; // x20
  int *v80; // x21
  __int64 v81; // x9
  int v82; // w20
  unsigned int v83; // w25
  const char *v84; // x26
  const char *v85; // x27
  unsigned __int64 v86; // x26
  __int64 v87; // x9
  unsigned __int64 v88; // x19
  int v89; // w20
  unsigned __int64 v90; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v92; // x20
  unsigned __int64 v93; // [xsp+10h] [xbp-30h]
  unsigned __int64 v94; // [xsp+10h] [xbp-30h]
  unsigned __int64 v95; // [xsp+10h] [xbp-30h]
  unsigned __int64 v96; // [xsp+10h] [xbp-30h]
  unsigned __int64 v97; // [xsp+10h] [xbp-30h]
  unsigned __int64 v98; // [xsp+10h] [xbp-30h]
  unsigned int v99; // [xsp+18h] [xbp-28h]
  unsigned int v100; // [xsp+18h] [xbp-28h]
  unsigned int v101; // [xsp+18h] [xbp-28h]
  unsigned int v102; // [xsp+18h] [xbp-28h]
  unsigned int v103; // [xsp+18h] [xbp-28h]
  unsigned int v104; // [xsp+18h] [xbp-28h]
  unsigned int v105; // [xsp+18h] [xbp-28h]
  unsigned int v106; // [xsp+18h] [xbp-28h]
  int v107; // [xsp+1Ch] [xbp-24h]
  int v108; // [xsp+1Ch] [xbp-24h]
  int v109; // [xsp+1Ch] [xbp-24h]
  int v110; // [xsp+1Ch] [xbp-24h]
  int v111; // [xsp+1Ch] [xbp-24h]
  int v112; // [xsp+1Ch] [xbp-24h]
  int v113; // [xsp+1Ch] [xbp-24h]
  int v114; // [xsp+1Ch] [xbp-24h]
  int v115; // [xsp+1Ch] [xbp-24h]
  int v116; // [xsp+1Ch] [xbp-24h]
  int v117; // [xsp+1Ch] [xbp-24h]
  __int64 v118; // [xsp+20h] [xbp-20h]
  unsigned int *v119; // [xsp+28h] [xbp-18h]
  unsigned __int64 v120; // [xsp+30h] [xbp-10h]
  __int64 v121; // [xsp+38h] [xbp-8h]

  result = 4294967274LL;
  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 8) )
    return result;
  v4 = (unsigned __int64)&unk_2FD000;
  v121 = a1;
  if ( mem_trace_en == 1 )
  {
    v5 = a2;
    v6 = (unsigned int *)cam_mem_trace_alloc(
                           16LL * *(unsigned int *)(a2 + 8),
                           0xCC0u,
                           0,
                           "cam_qup_i2c_write_table",
                           0x198u);
    if ( v6 )
      goto LABEL_6;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_write_table",
      410,
      "Message Buffer memory allocation failed");
    return 4294967284LL;
  }
  v5 = a2;
  v6 = (unsigned int *)_kvmalloc_node_noprof(16LL * *(unsigned int *)(a2 + 8), 0, 3520, 0xFFFFFFFFLL);
  if ( !v6 )
    goto LABEL_13;
LABEL_6:
  v120 = (unsigned int)(8 * *(_DWORD *)(v5 + 8));
  v7 = _kmalloc_noprof(v120, 3521);
  v8 = v121;
  if ( !v7 )
  {
LABEL_139:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_write_table",
      416,
      "Buffer memory allocation failed");
    if ( *(_BYTE *)(v4 + 2904) == 1 )
      cam_mem_trace_free(v6, 0);
    else
      kvfree(v6);
    return 4294967284LL;
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(v5 + 12);
    if ( v9 - 5 < 0xFFFFFFFC
      || (v10 = *(_DWORD *)(v5 + 16), v11 = v5, (unsigned int)(v10 - 5) < 0xFFFFFFFC)
      || !*(_QWORD *)(v8 + 8) )
    {
      v23 = -22;
      goto LABEL_15;
    }
    v12 = &unk_393000;
    v13 = (int *)&unk_393000;
    v118 = v7;
    if ( !*(_DWORD *)(v5 + 8) )
      break;
    v14 = *(unsigned int **)v5;
    v15 = v120;
    v16 = 0;
    LODWORD(v17) = 0;
    v18 = 0;
    v19 = "cam_qup_i2c_write_optimized";
    v20 = "reg addr = 0x%x data type: %d";
    v21 = "byte %d: 0x%x";
    v22 = "reg addr: 0x%x Data: 0x%x";
    v119 = v6;
    while ( 1 )
    {
      v27 = v12[458];
      v6 = v14;
      if ( (v27 & 0x4000000000LL) != 0 && !v13[919] )
        break;
      if ( (int)v9 > 2 )
        goto LABEL_37;
LABEL_21:
      if ( v9 == 1 )
      {
        if ( v15 <= (unsigned __int16)v18 )
          goto LABEL_138;
        v34 = v12[458];
        v30 = 1;
        *(_BYTE *)(v7 + (unsigned __int16)v18) = *(_BYTE *)v6;
        if ( (v34 & 0x4000000000LL) != 0 && !v13[919] )
        {
          v107 = v17;
          v35 = v19;
          v36 = v11;
          v5 = (__int64)v13;
          v4 = 1;
          v37 = v12;
          v38 = v21;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            v34 & 0x4000000000LL,
            4,
            v19,
            299,
            v21,
            0);
          v15 = v120;
          v8 = v121;
          LODWORD(v17) = v107;
          v7 = v118;
          v22 = "reg addr: 0x%x Data: 0x%x";
          v21 = v38;
          v20 = "reg addr = 0x%x data type: %d";
          v19 = v35;
          v12 = v37;
          v9 = 1;
          v13 = (int *)v5;
          v11 = v36;
          v30 = 1;
        }
      }
      else
      {
        if ( v9 != 2 )
          goto LABEL_135;
        if ( v15 <= (unsigned __int16)v18 )
          goto LABEL_138;
        v5 = (unsigned __int16)v18 + 1LL;
        *(_BYTE *)(v7 + (unsigned __int16)v18) = BYTE1(*v6);
        if ( v15 == v5 )
          goto LABEL_138;
        v28 = v13[919];
        v29 = v12[458] & 0x4000000000LL;
        *(_BYTE *)(v7 + (unsigned __int16)v18 + 1) = *v6;
        if ( v29 && !v28 )
        {
          v117 = v17;
          v85 = v19;
          v86 = v11;
          v4 = 2;
          ((void (__fastcall *)(__int64))cam_print_log)(3);
          v12 = &unk_393000;
          v13 = (int *)&unk_393000;
          LODWORD(v17) = v117;
          v15 = v120;
          v8 = v121;
          v7 = v118;
          v28 = debug_priority;
          v22 = "reg addr: 0x%x Data: 0x%x";
          v21 = "byte %d: 0x%x";
          v20 = "reg addr = 0x%x data type: %d";
          v19 = v85;
          v9 = 2;
          v11 = v86;
          v30 = 2;
          if ( (debug_mdl & 0x4000000000LL) != 0 )
          {
LABEL_28:
            if ( !v28 )
            {
              v99 = v9;
              if ( v15 <= (unsigned __int16)v18 || v120 == v5 )
                goto LABEL_138;
              v4 = (unsigned int)v17;
              v31 = v11;
              v32 = v19;
              v33 = v21;
              ((void (__fastcall *)(__int64))cam_print_log)(3);
              v15 = v120;
              v8 = v121;
              v21 = v33;
              v7 = v118;
              v9 = v99;
              v19 = v32;
              v30 = 2;
              LODWORD(v17) = v4;
              v11 = v31;
              v13 = (int *)&unk_393000;
              v12 = &unk_393000;
              v20 = "reg addr = 0x%x data type: %d";
              v22 = "reg addr: 0x%x Data: 0x%x";
            }
          }
        }
        else
        {
          v30 = 2;
          if ( v29 )
            goto LABEL_28;
        }
      }
LABEL_48:
      v18 += v30;
      v45 = v16 + 1;
      while ( 1 )
      {
        v46 = v12[458];
        v16 = v45;
        if ( (v46 & 0x4000000000LL) != 0 && !v13[919] )
        {
          v56 = v22;
          v110 = v17;
          v57 = v19;
          v58 = v11;
          v4 = v9;
          v5 = (__int64)v21;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
            3,
            v46 & 0x4000000000LL,
            4,
            v19,
            330,
            v22,
            *v6,
            v6[1]);
          v15 = v120;
          v8 = v121;
          LODWORD(v17) = v110;
          v7 = v118;
          v22 = v56;
          v21 = (const char *)v5;
          v20 = "reg addr = 0x%x data type: %d";
          v19 = v57;
          v12 = &unk_393000;
          v9 = v4;
          v13 = (int *)&unk_393000;
          v11 = v58;
          if ( v10 <= 2 )
          {
LABEL_52:
            if ( v10 == 1 )
            {
              if ( v15 <= (unsigned __int16)v18 )
                goto LABEL_138;
              v51 = v12[458];
              v5 = 1;
              *(_BYTE *)(v7 + (unsigned __int16)v18) = *((_BYTE *)v6 + 4);
              if ( (v51 & 0x4000000000LL) != 0 && !v13[919] )
              {
                v109 = v17;
                v52 = v19;
                v53 = v11;
                v4 = v9;
                v54 = v12;
                v55 = v21;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                  3,
                  v51 & 0x4000000000LL,
                  4,
                  v19,
                  333,
                  "Byte %d: 0x%x",
                  (unsigned __int16)v30);
                v15 = v120;
                v8 = v121;
                LODWORD(v17) = v109;
                v7 = v118;
                v22 = "reg addr: 0x%x Data: 0x%x";
                v21 = v55;
                v20 = "reg addr = 0x%x data type: %d";
                v19 = v52;
                v12 = v54;
                v9 = v4;
                v13 = (int *)&unk_393000;
                v11 = v53;
                v5 = 1;
              }
            }
            else
            {
              if ( v15 <= (unsigned __int16)v18 )
                goto LABEL_138;
              v4 = (unsigned __int16)v18 + 1LL;
              *(_BYTE *)(v7 + (unsigned __int16)v18) = BYTE1(v6[1]);
              if ( v15 == v4 )
                goto LABEL_138;
              v47 = v13[919];
              v48 = v12[458] & 0x4000000000LL;
              *(_BYTE *)(v7 + (unsigned __int16)v18 + 1) = v6[1];
              if ( !v48 || v47 )
              {
                v5 = 2;
                if ( !v48 )
                  goto LABEL_91;
LABEL_58:
                if ( v47 )
                  goto LABEL_91;
                v100 = v9;
                v93 = v11;
                if ( v15 <= (unsigned __int16)v18 || v15 == v4 )
                  goto LABEL_138;
                v49 = v17;
                v50 = v19;
                ((void (__fastcall *)(__int64))cam_print_log)(3);
                v15 = v120;
                v8 = v121;
                v19 = v50;
                v7 = v118;
                v11 = v93;
                LODWORD(v17) = v49;
LABEL_105:
                v9 = v100;
                v13 = (int *)&unk_393000;
                v12 = &unk_393000;
                v20 = "reg addr = 0x%x data type: %d";
                v21 = "byte %d: 0x%x";
                v22 = "reg addr: 0x%x Data: 0x%x";
                goto LABEL_91;
              }
              v101 = v9;
              v111 = v17;
              v70 = v19;
              v71 = v11;
              ((void (__fastcall *)(__int64))cam_print_log)(3);
              v12 = &unk_393000;
              v13 = (int *)&unk_393000;
              v7 = v118;
              v9 = v101;
              LODWORD(v17) = v111;
              v15 = v120;
              v8 = v121;
              v47 = debug_priority;
              v22 = "reg addr: 0x%x Data: 0x%x";
              v21 = "byte %d: 0x%x";
              v20 = "reg addr = 0x%x data type: %d";
              v19 = v70;
              v11 = v71;
              v5 = 2;
              if ( (debug_mdl & 0x4000000000LL) != 0 )
                goto LABEL_58;
            }
            goto LABEL_91;
          }
        }
        else if ( v10 <= 2 )
        {
          goto LABEL_52;
        }
        if ( v10 != 3 )
        {
          if ( v15 <= (unsigned __int16)v18 )
            goto LABEL_138;
          v5 = (unsigned __int16)v18 + 1LL;
          v59 = (_BYTE *)(v7 + (unsigned __int16)v18);
          *v59 = HIBYTE(v6[1]);
          if ( v15 == v5 )
            goto LABEL_138;
          v4 = (unsigned __int16)v18 + 2LL;
          v59[1] = *((_WORD *)v6 + 3);
          if ( v15 <= v4 )
            goto LABEL_138;
          v59[2] = BYTE1(v6[1]);
          if ( v15 <= (unsigned __int64)(unsigned __int16)v18 + 3 )
            goto LABEL_138;
          v60 = v13[919];
          v61 = v12[458] & 0x4000000000LL;
          v59[3] = v6[1];
          if ( v61 && !v60 )
          {
            v104 = v9;
            v114 = v17;
            v96 = v11;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              v61,
              4,
              "cam_qup_i2c_write_optimized",
              357,
              "Byte %d: 0x%x",
              (unsigned __int16)v30);
            v12 = &unk_393000;
            v13 = (int *)&unk_393000;
            v11 = v96;
            v9 = v104;
            LODWORD(v17) = v114;
            v15 = v120;
            v8 = v121;
            v7 = v118;
            v60 = debug_priority;
            v22 = "reg addr: 0x%x Data: 0x%x";
            v21 = "byte %d: 0x%x";
            v20 = "reg addr = 0x%x data type: %d";
            v19 = "cam_qup_i2c_write_optimized";
            v61 = debug_mdl & 0x4000000000LL;
            if ( (debug_mdl & 0x4000000000LL) != 0 )
              goto LABEL_75;
          }
          else if ( v61 )
          {
LABEL_75:
            if ( !v60 )
            {
              v105 = v9;
              v115 = v17;
              v97 = v11;
              if ( v15 <= (unsigned __int16)v18 || v15 == v5 )
                goto LABEL_138;
              v78 = v19;
              ((void (__fastcall *)(__int64))cam_print_log)(3);
              v12 = &unk_393000;
              v13 = (int *)&unk_393000;
              v7 = v118;
              v60 = debug_priority;
              v11 = v97;
              v9 = v105;
              LODWORD(v17) = v115;
              v61 = debug_mdl & 0x4000000000LL;
              v15 = v120;
              v8 = v121;
              v19 = v78;
              v20 = "reg addr = 0x%x data type: %d";
              v21 = "byte %d: 0x%x";
              v22 = "reg addr: 0x%x Data: 0x%x";
            }
          }
          if ( !v61 || v60 )
          {
            v5 = 4;
            if ( !v61 )
              goto LABEL_91;
LABEL_79:
            if ( v60 )
              goto LABEL_91;
            v100 = v9;
            if ( v15 <= (unsigned __int64)(unsigned __int16)v18 + 3 )
              goto LABEL_138;
            v62 = v17;
            v4 = v11;
            v63 = v19;
            ((void (__fastcall *)(__int64))cam_print_log)(3);
            v7 = v118;
            v8 = v121;
            v19 = v63;
            LODWORD(v17) = v62;
            v11 = v4;
            goto LABEL_104;
          }
          v106 = v9;
          v116 = v17;
          v98 = v11;
          if ( v15 <= v4 )
            goto LABEL_138;
          v79 = v12;
          v80 = v13;
          v4 = (unsigned __int64)v19;
          ((void (__fastcall *)(__int64))cam_print_log)(3);
          v60 = v80[919];
          v19 = (const char *)v4;
          v9 = v106;
          LODWORD(v17) = v116;
          v15 = v120;
          v8 = v121;
          v7 = v118;
          v11 = v98;
          v12 = v79;
          v13 = v80;
          v20 = "reg addr = 0x%x data type: %d";
          v21 = "byte %d: 0x%x";
          v22 = "reg addr: 0x%x Data: 0x%x";
          v5 = 4;
          if ( (v79[458] & 0x4000000000LL) != 0 )
            goto LABEL_79;
          goto LABEL_91;
        }
        if ( v15 <= (unsigned __int16)v18 )
          goto LABEL_138;
        v5 = (unsigned __int16)v18 + 1LL;
        v64 = (_BYTE *)(v7 + (unsigned __int16)v18);
        *v64 = BYTE2(v6[1]);
        if ( v15 == v5 )
          goto LABEL_138;
        v4 = (unsigned __int16)v18 + 2LL;
        v64[1] = BYTE1(v6[1]);
        if ( v15 <= v4 )
          goto LABEL_138;
        v65 = v13[919];
        v66 = v12[458] & 0x4000000000LL;
        v64[2] = v6[1];
        if ( v66 && !v65 )
        {
          v102 = v9;
          v112 = v17;
          v72 = v19;
          v94 = v11;
          ((void (__fastcall *)(__int64))cam_print_log)(3);
          v12 = &unk_393000;
          v13 = (int *)&unk_393000;
          v11 = v94;
          v9 = v102;
          LODWORD(v17) = v112;
          v15 = v120;
          v8 = v121;
          v7 = v118;
          v65 = debug_priority;
          v22 = "reg addr: 0x%x Data: 0x%x";
          v21 = "byte %d: 0x%x";
          v20 = "reg addr = 0x%x data type: %d";
          v19 = v72;
          v66 = debug_mdl & 0x4000000000LL;
          if ( (debug_mdl & 0x4000000000LL) == 0 )
            goto LABEL_89;
        }
        else if ( !v66 )
        {
          goto LABEL_89;
        }
        if ( !v65 )
        {
          v103 = v9;
          v113 = v17;
          v95 = v11;
          if ( v15 <= (unsigned __int16)v18 || v15 == v5 )
            goto LABEL_138;
          v73 = v12;
          v74 = v19;
          ((void (__fastcall *)(__int64))cam_print_log)(3);
          v13 = (int *)&unk_393000;
          v7 = v118;
          v9 = v103;
          LODWORD(v17) = v113;
          v66 = v73[458] & 0x4000000000LL;
          v15 = v120;
          v8 = v121;
          v65 = debug_priority;
          v11 = v95;
          v19 = v74;
          v12 = v73;
          v20 = "reg addr = 0x%x data type: %d";
          v21 = "byte %d: 0x%x";
          v22 = "reg addr: 0x%x Data: 0x%x";
        }
LABEL_89:
        v5 = 3;
        if ( v66 && !v65 )
        {
          v100 = v9;
          if ( v15 <= v4 )
            goto LABEL_138;
          v75 = v17;
          v76 = v11;
          v77 = v19;
          ((void (__fastcall *)(__int64))cam_print_log)(3);
          v7 = v118;
          v8 = v121;
          v19 = v77;
          LODWORD(v17) = v75;
          v11 = v76;
LABEL_104:
          v15 = v120;
          goto LABEL_105;
        }
LABEL_91:
        v18 += v5;
        LOWORD(v30) = v5 + v30;
        if ( v16 >= *(_DWORD *)(v11 + 8) )
          break;
        v14 = v6 + 4;
        v67 = v6[4];
        if ( i2c_lookahead_en )
        {
          v68 = *v6;
          v6 += 4;
          v69 = v68 + v10 == v67;
          v45 = v16 + 1;
          if ( v69 )
            continue;
        }
        goto LABEL_115;
      }
      v14 = v6;
LABEL_115:
      v81 = v12[458];
      if ( (v81 & 0x4000000000LL) != 0 && !v13[919] )
      {
        v82 = v17;
        v4 = (unsigned __int64)v19;
        v5 = v11;
        v83 = v9;
        v84 = v21;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v81 & 0x4000000000LL,
          4,
          v19,
          385,
          "offset: %d len: %d curr_mindx: %d",
          (unsigned __int16)v18,
          (unsigned __int16)v30,
          v17);
        v15 = v120;
        v8 = v121;
        v22 = "reg addr: 0x%x Data: 0x%x";
        v7 = v118;
        v21 = v84;
        v20 = "reg addr = 0x%x data type: %d";
        v19 = (const char *)v4;
        v12 = &unk_393000;
        v9 = v83;
        v13 = (int *)&unk_393000;
        v11 = v5;
        LODWORD(v17) = v82;
      }
      v6 = v119;
      v24 = &v119[4 * (int)v17];
      v17 = (unsigned int)(v17 + 1);
      v25 = *(unsigned __int16 *)(**(_QWORD **)(v8 + 8) + 2LL);
      *((_WORD *)v24 + 1) = 0;
      *((_WORD *)v24 + 2) = v30;
      *((_QWORD *)v24 + 1) = v7 - (unsigned __int16)v30 + (unsigned __int16)v18;
      *(_WORD *)v24 = v25 >> 1;
      v26 = *(_DWORD *)(v11 + 8);
      if ( v16 >= v26 )
      {
        v4 = (unsigned __int64)&unk_2FD000;
        goto LABEL_124;
      }
    }
    v108 = v17;
    v39 = v19;
    v40 = v20;
    v41 = v11;
    v4 = v9;
    v42 = v12;
    v5 = (__int64)v21;
    ((void (__fastcall *)(__int64, __int64, __int64))cam_print_log)(3, v27 & 0x4000000000LL, 4);
    v15 = v120;
    v8 = v121;
    v22 = "reg addr: 0x%x Data: 0x%x";
    LODWORD(v17) = v108;
    v7 = v118;
    v21 = (const char *)v5;
    v20 = v40;
    v19 = v39;
    v12 = v42;
    v9 = v4;
    v13 = (int *)&unk_393000;
    v11 = v41;
    if ( (int)v4 <= 2 )
      goto LABEL_21;
LABEL_37:
    if ( v9 == 3 )
    {
      if ( v15 <= (unsigned __int16)v18 )
        goto LABEL_138;
      v44 = (_BYTE *)(v7 + (unsigned __int16)v18);
      *v44 = *((_WORD *)v6 + 1);
      if ( v15 == (unsigned __int16)v18 + 1LL )
        goto LABEL_138;
      v44[1] = BYTE1(*v6);
      if ( v15 <= (unsigned __int64)(unsigned __int16)v18 + 2 )
        goto LABEL_138;
      v30 = 3;
      v44[2] = *v6;
      goto LABEL_48;
    }
    if ( v9 != 4 )
    {
LABEL_135:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char **))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_qup_i2c_write_optimized",
        323,
        "Invalid I2C addr type",
        &off_BC000);
      v7 = v118;
      v6 = v119;
      v23 = -22;
      v4 = (unsigned __int64)&unk_2FD000;
      goto LABEL_15;
    }
    if ( v15 > (unsigned __int16)v18 )
    {
      v43 = (_BYTE *)(v7 + (unsigned __int16)v18);
      *v43 = *((_BYTE *)v6 + 3);
      if ( v15 != (unsigned __int16)v18 + 1LL )
      {
        v43[1] = *((_WORD *)v6 + 1);
        if ( v15 > (unsigned __int64)(unsigned __int16)v18 + 2 )
        {
          v43[2] = BYTE1(*v6);
          if ( v15 > (unsigned __int64)(unsigned __int16)v18 + 3 )
          {
            v30 = 4;
            v43[3] = *v6;
            goto LABEL_48;
          }
        }
      }
    }
LABEL_138:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v92 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_qup_i2c_write_table__alloc_tag_14;
    v120 = (unsigned int)(8 * *(_DWORD *)(v5 + 8));
    v7 = _kmalloc_noprof(v120, 3521);
    *(_QWORD *)(StatusReg + 80) = v92;
    v8 = v121;
    if ( !v7 )
      goto LABEL_139;
  }
  v17 = 0;
  v26 = 0;
LABEL_124:
  v87 = v12[458];
  v23 = v17;
  if ( (v87 & 0x4000000000LL) != 0 && !v13[919] )
  {
    v90 = v11;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v87 & 0x4000000000LL,
      4,
      "cam_qup_i2c_write_optimized",
      393,
      "Original reg writes: %d optimized Writes: %d",
      v26,
      v17);
    v8 = v121;
    v11 = v90;
    v17 = v23;
    if ( (v23 & 0x80000000) == 0 )
    {
LABEL_127:
      v88 = v11;
      v89 = i2c_transfer(*(_QWORD *)(**(_QWORD **)(v8 + 8) + 24LL), v6, v17);
      if ( *(unsigned __int16 *)(v88 + 20) < 0x15u )
      {
        if ( *(_WORD *)(v88 + 20) )
          usleep_range_state(
            1000LL * *(unsigned __int16 *)(v88 + 20),
            1000 * (unsigned int)*(unsigned __int16 *)(v88 + 20) + 1000,
            2);
      }
      else
      {
        msleep(*(unsigned __int16 *)(v88 + 20));
      }
      if ( v89 == v23 )
      {
        v23 = 0;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x4000000000LL,
          1,
          "cam_qup_i2c_write_table",
          446,
          "i2c transfer failed, i2c_msg_size:%d rc:%d",
          v23,
          v89);
        v23 = -5;
      }
    }
  }
  else if ( (v17 & 0x80000000) == 0 )
  {
    goto LABEL_127;
  }
  v7 = v118;
LABEL_15:
  kfree(v7);
  if ( *(_BYTE *)(v4 + 2904) == 1 )
    cam_mem_trace_free(v6, 0);
  else
    kvfree(v6);
  return v23;
}
