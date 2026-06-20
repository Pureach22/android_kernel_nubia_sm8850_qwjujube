__int64 __fastcall cam_qup_i3c_write_table(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned __int64 v3; // x20
  __int64 result; // x0
  unsigned int *v6; // x23
  __int64 v7; // x21
  _QWORD *v8; // x24
  __int64 v9; // x0
  __int64 v10; // x9
  int v11; // w2
  int v12; // w22
  __int64 v13; // x14
  unsigned int v14; // w8
  _QWORD *v15; // x17
  _DWORD *v16; // x16
  unsigned int *v17; // x26
  unsigned __int64 v18; // x15
  unsigned int v19; // w27
  int v20; // w25
  const char *v21; // x3
  const char *v22; // x5
  const char *v23; // x30
  const char *v24; // x4
  _QWORD *v25; // x10
  unsigned int v26; // w6
  __int64 v27; // x10
  __int64 v28; // x6
  int v29; // w10
  __int64 v30; // x1
  unsigned int v31; // w26
  __int64 v32; // x28
  const char *v33; // x19
  __int64 v34; // x10
  const char *v35; // x28
  const char *v36; // x26
  _QWORD *v37; // x24
  const char *v38; // x19
  const char *v39; // x26
  const char *v40; // x28
  _QWORD *v41; // x24
  _BYTE *v42; // x11
  _BYTE *v43; // x11
  unsigned int v44; // w10
  __int64 v45; // x11
  unsigned int v46; // w6
  int v47; // w10
  __int64 v48; // x1
  int v49; // w24
  unsigned int v50; // w27
  __int64 v51; // x28
  __int64 v52; // x10
  const char *v53; // x28
  _DWORD *v54; // x24
  _QWORD *v55; // x26
  const char *v56; // x27
  const char *v57; // x28
  _DWORD *v58; // x24
  _QWORD *v59; // x26
  const char *v60; // x27
  _BYTE *v61; // x28
  int v62; // w10
  __int64 v63; // x1
  _DWORD *v64; // x27
  const char *v65; // x26
  _BYTE *v66; // x26
  int v67; // w10
  __int64 v68; // x1
  unsigned int v69; // w10
  unsigned int v70; // w11
  bool v71; // zf
  const char *v72; // x28
  __int64 v73; // x27
  _QWORD *v74; // x24
  __int64 v75; // x1
  const char *v76; // x24
  __int64 v77; // x28
  _QWORD *v78; // x24
  int *v79; // x28
  _DWORD *v80; // x28
  const char *v81; // x26
  const char *v82; // x24
  _QWORD *v83; // x24
  int *v84; // x24
  const char *v85; // x27
  __int64 v86; // x10
  const char *v87; // x28
  _DWORD *v88; // x23
  _QWORD *v89; // x24
  const char *v90; // x19
  __int64 v91; // x26
  _QWORD *v92; // x28
  __int64 v93; // x10
  int v94; // w0
  int v95; // w22
  __int64 v96; // x0
  __int64 v97; // x19
  __int64 v98; // [xsp+8h] [xbp-38h]
  __int64 v99; // [xsp+8h] [xbp-38h]
  __int64 v100; // [xsp+8h] [xbp-38h]
  __int64 v101; // [xsp+8h] [xbp-38h]
  unsigned int v102; // [xsp+14h] [xbp-2Ch]
  unsigned int v103; // [xsp+14h] [xbp-2Ch]
  unsigned int v104; // [xsp+14h] [xbp-2Ch]
  unsigned int v105; // [xsp+14h] [xbp-2Ch]
  unsigned int v106; // [xsp+14h] [xbp-2Ch]
  unsigned int v107; // [xsp+14h] [xbp-2Ch]
  unsigned int v108; // [xsp+14h] [xbp-2Ch]
  unsigned int v109; // [xsp+14h] [xbp-2Ch]
  unsigned int v110; // [xsp+14h] [xbp-2Ch]
  unsigned int v111; // [xsp+14h] [xbp-2Ch]
  unsigned int v112; // [xsp+18h] [xbp-28h]
  unsigned int v113; // [xsp+18h] [xbp-28h]
  unsigned int v114; // [xsp+18h] [xbp-28h]
  unsigned int v115; // [xsp+18h] [xbp-28h]
  unsigned int v116; // [xsp+18h] [xbp-28h]
  unsigned int v117; // [xsp+18h] [xbp-28h]
  unsigned int v118; // [xsp+18h] [xbp-28h]
  unsigned int v119; // [xsp+18h] [xbp-28h]
  unsigned int v120; // [xsp+18h] [xbp-28h]
  int v121; // [xsp+1Ch] [xbp-24h]
  int v122; // [xsp+1Ch] [xbp-24h]
  int v123; // [xsp+1Ch] [xbp-24h]
  int v124; // [xsp+1Ch] [xbp-24h]
  int v125; // [xsp+1Ch] [xbp-24h]
  int v126; // [xsp+1Ch] [xbp-24h]
  int v127; // [xsp+1Ch] [xbp-24h]
  int v128; // [xsp+1Ch] [xbp-24h]
  int v129; // [xsp+1Ch] [xbp-24h]
  int v130; // [xsp+1Ch] [xbp-24h]
  int v131; // [xsp+1Ch] [xbp-24h]
  int v132; // [xsp+1Ch] [xbp-24h]
  __int64 v133; // [xsp+20h] [xbp-20h]
  _QWORD *v134; // [xsp+28h] [xbp-18h]
  unsigned __int64 v135; // [xsp+30h] [xbp-10h]
  __int64 v136; // [xsp+38h] [xbp-8h]

  result = 4294967274LL;
  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 8) )
    return result;
  v6 = (unsigned int *)&unk_2FD000;
  v136 = a1;
  if ( mem_trace_en == 1 )
  {
    v7 = a2;
    v8 = (_QWORD *)cam_mem_trace_alloc(24LL * *(unsigned int *)(a2 + 8), 0xCC0u, 0, "cam_qup_i3c_write_table", 0x195u);
    if ( v8 )
      goto LABEL_6;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_write_table",
      407,
      "Message Buffer memory allocation failed");
    return 4294967284LL;
  }
  v7 = a2;
  v8 = (_QWORD *)_kvmalloc_node_noprof(24LL * *(unsigned int *)(a2 + 8), 0, 3520, 0xFFFFFFFFLL);
  if ( !v8 )
    goto LABEL_13;
LABEL_6:
  v135 = (unsigned int)(8 * *(_DWORD *)(v7 + 8));
  v9 = _kmalloc_noprof(v135, 3521);
  v10 = v136;
  if ( !v9 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_write_table",
      413,
      "Buffer memory allocation failed");
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v8, 0);
    else
      kvfree(v8);
    return 4294967284LL;
  }
  v11 = *(_DWORD *)(v7 + 12);
  if ( (unsigned int)(v11 - 5) >= 0xFFFFFFFC )
  {
    v12 = *(_DWORD *)(v7 + 16);
    v13 = v7;
    if ( (unsigned int)(v12 - 5) >= 0xFFFFFFFC )
    {
      v14 = *(_DWORD *)(v7 + 8);
      v15 = &unk_393000;
      v16 = &unk_393000;
      v133 = v9;
      if ( v14 )
      {
        v17 = *(unsigned int **)v7;
        v18 = v135;
        v19 = 0;
        v14 = 0;
        v20 = 0;
        v21 = "cam_qup_i3c_write_optimized";
        v22 = "reg addr = 0x%x data type: %d";
        v23 = "byte %d: 0x%x";
        v24 = "reg addr: 0x%x Data: 0x%x";
        v134 = v8;
        while ( 1 )
        {
          v27 = v15[458];
          v6 = v17;
          if ( (v27 & 0x4000000000LL) != 0 && !v16[919] )
          {
            v122 = v11;
            v103 = v14;
            v39 = v21;
            v40 = v22;
            v3 = v13;
            v7 = (__int64)v16;
            v41 = v15;
            v2 = (__int64)v23;
            ((void (__fastcall *)(__int64, __int64, __int64))cam_print_log)(3, v27 & 0x4000000000LL, 4);
            v18 = v135;
            v10 = v136;
            v24 = "reg addr: 0x%x Data: 0x%x";
            v11 = v122;
            v14 = v103;
            v9 = v133;
            v23 = (const char *)v2;
            v22 = v40;
            v21 = v39;
            v15 = v41;
            v16 = (_DWORD *)v7;
            v13 = v3;
            if ( v122 > 2 )
            {
LABEL_38:
              v28 = v19;
              if ( v11 == 3 )
              {
                if ( v18 <= (unsigned __int16)v20 )
                  goto LABEL_164;
                v43 = (_BYTE *)(v9 + (unsigned __int16)v20);
                *v43 = *((_WORD *)v6 + 1);
                if ( v18 == (unsigned __int16)v20 + 1LL )
                  goto LABEL_164;
                v43[1] = BYTE1(*v6);
                if ( v18 <= (unsigned __int64)(unsigned __int16)v20 + 2 )
                  goto LABEL_164;
                v2 = 3;
                v43[2] = *v6;
              }
              else
              {
                if ( v11 != 4 )
                {
LABEL_157:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                    3,
                    0x4000000000LL,
                    1,
                    "cam_qup_i3c_write_optimized",
                    318,
                    "Invalid I2C addr type",
                    v28);
                  v9 = v133;
                  v8 = v134;
                  LODWORD(v7) = -22;
                  v6 = (unsigned int *)&unk_2FD000;
                  goto LABEL_10;
                }
                if ( v18 <= (unsigned __int16)v20
                  || (v42 = (_BYTE *)(v9 + (unsigned __int16)v20),
                      *v42 = *((_BYTE *)v6 + 3),
                      v18 == (unsigned __int16)v20 + 1LL)
                  || (v42[1] = *((_WORD *)v6 + 1), v18 <= (unsigned __int64)(unsigned __int16)v20 + 2)
                  || (v42[2] = BYTE1(*v6), v18 <= (unsigned __int64)(unsigned __int16)v20 + 3) )
                {
LABEL_164:
                  __break(1u);
LABEL_165:
                  v95 = 5000;
LABEL_170:
                  v94 = v7;
                  goto LABEL_171;
                }
                v2 = 4;
                v42[3] = *v6;
              }
              goto LABEL_49;
            }
          }
          else if ( v11 > 2 )
          {
            goto LABEL_38;
          }
          v28 = v19;
          if ( v11 == 1 )
          {
            if ( v18 <= (unsigned __int16)v20 )
              goto LABEL_164;
            v34 = v15[458];
            v2 = 1;
            *(_BYTE *)(v9 + (unsigned __int16)v20) = *(_BYTE *)v6;
            if ( (v34 & 0x4000000000LL) != 0 && !v16[919] )
            {
              v35 = v22;
              v102 = v14;
              v36 = v21;
              v3 = v13;
              v7 = (__int64)v16;
              v37 = v15;
              v38 = v23;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                v34 & 0x4000000000LL,
                4,
                v21,
                294,
                v23,
                0);
              v18 = v135;
              v10 = v136;
              LODWORD(v28) = v19;
              v11 = 1;
              v14 = v102;
              v24 = "reg addr: 0x%x Data: 0x%x";
              v9 = v133;
              v23 = v38;
              v22 = v35;
              v21 = v36;
              v15 = v37;
              v16 = (_DWORD *)v7;
              v13 = v3;
              v2 = 1;
            }
          }
          else
          {
            if ( v11 != 2 )
              goto LABEL_157;
            v3 = (unsigned __int16)v20;
            if ( v18 <= (unsigned __int16)v20 )
              goto LABEL_164;
            v7 = v9 + (unsigned __int16)v20;
            *(_BYTE *)v7 = BYTE1(*v6);
            if ( v18 == (unsigned __int16)v20 + 1LL )
              goto LABEL_164;
            v29 = v16[919];
            v30 = v15[458] & 0x4000000000LL;
            *(_BYTE *)(v7 + 1) = *v6;
            if ( v30 && !v29 )
            {
              v111 = v14;
              v90 = v21;
              v91 = v13;
              v92 = v15;
              ((void (__fastcall *)(__int64))cam_print_log)(3);
              v16 = &unk_393000;
              v18 = v135;
              v10 = v136;
              v11 = 2;
              LODWORD(v28) = v19;
              v14 = v111;
              v9 = v133;
              v24 = "reg addr: 0x%x Data: 0x%x";
              v29 = debug_priority;
              v23 = "byte %d: 0x%x";
              v22 = "reg addr = 0x%x data type: %d";
              v21 = v90;
              v15 = v92;
              v13 = v91;
              v2 = 2;
              if ( (v92[458] & 0x4000000000LL) != 0 )
              {
LABEL_29:
                if ( !v29 )
                {
                  v121 = v11;
                  if ( v18 <= (unsigned __int16)v20 )
                    goto LABEL_164;
                  v31 = v14;
                  if ( v135 == (unsigned __int16)v20 + 1LL )
                    goto LABEL_164;
                  v32 = v13;
                  v33 = v21;
                  v3 = (unsigned __int64)v23;
                  ((void (__fastcall *)(__int64))cam_print_log)(3);
                  v18 = v135;
                  v10 = v136;
                  v23 = (const char *)v3;
                  v9 = v133;
                  v11 = v121;
                  v21 = v33;
                  v2 = 2;
                  v14 = v31;
                  v13 = v32;
                  v16 = &unk_393000;
                  v15 = &unk_393000;
                  v22 = "reg addr = 0x%x data type: %d";
                  v24 = "reg addr: 0x%x Data: 0x%x";
                  LODWORD(v28) = v19;
                }
              }
            }
            else
            {
              v2 = 2;
              if ( v30 )
                goto LABEL_29;
            }
          }
LABEL_49:
          v20 += v2;
          v44 = v28 + 1;
          while ( 1 )
          {
            v45 = v15[458];
            v46 = v44;
            if ( (v45 & 0x4000000000LL) != 0 && !v16[919] )
            {
              v105 = v14;
              v114 = v44;
              v3 = (unsigned __int64)v24;
              v125 = v11;
              v57 = v21;
              v7 = v13;
              v58 = v16;
              v59 = v15;
              v60 = v23;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
                3,
                v45 & 0x4000000000LL,
                4,
                v21,
                326,
                v24,
                *v6,
                v6[1]);
              v46 = v114;
              v11 = v125;
              v18 = v135;
              v10 = v136;
              v24 = (const char *)v3;
              v14 = v105;
              v9 = v133;
              v23 = v60;
              v22 = "reg addr = 0x%x data type: %d";
              v21 = v57;
              v15 = v59;
              v16 = v58;
              v13 = v7;
              if ( v12 <= 2 )
              {
LABEL_53:
                if ( v12 == 1 )
                {
                  if ( v18 <= (unsigned __int16)v20 )
                    goto LABEL_164;
                  v52 = v15[458];
                  v49 = 1;
                  *(_BYTE *)(v9 + (unsigned __int16)v20) = *((_BYTE *)v6 + 4);
                  if ( (v52 & 0x4000000000LL) != 0 && !v16[919] )
                  {
                    v104 = v14;
                    v113 = v46;
                    v124 = v11;
                    v3 = (unsigned __int64)v22;
                    v53 = v21;
                    v7 = v13;
                    v54 = v16;
                    v55 = v15;
                    v56 = v23;
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                      3,
                      v52 & 0x4000000000LL,
                      4,
                      v21,
                      330,
                      "Byte %d: 0x%x",
                      (unsigned __int16)v2);
                    v46 = v113;
                    v11 = v124;
                    v18 = v135;
                    v10 = v136;
                    v24 = "reg addr: 0x%x Data: 0x%x";
                    v14 = v104;
                    v9 = v133;
                    v23 = v56;
                    v22 = (const char *)v3;
                    v21 = v53;
                    v15 = v55;
                    v16 = v54;
                    v13 = v7;
                    v49 = 1;
                  }
                }
                else
                {
                  v3 = (unsigned __int16)v20;
                  if ( v18 <= (unsigned __int16)v20 )
                    goto LABEL_164;
                  v7 = v9 + (unsigned __int16)v20;
                  *(_BYTE *)v7 = BYTE1(v6[1]);
                  if ( v18 == (unsigned __int16)v20 + 1LL )
                    goto LABEL_164;
                  v47 = v16[919];
                  v48 = v15[458] & 0x4000000000LL;
                  *(_BYTE *)(v7 + 1) = v6[1];
                  if ( !v48 || v47 )
                  {
                    v49 = 2;
                    if ( !v48 )
                      goto LABEL_92;
LABEL_59:
                    if ( v47 )
                      goto LABEL_92;
                    v112 = v46;
                    v123 = v11;
                    if ( v18 <= (unsigned __int16)v20 || v18 == (unsigned __int16)v20 + 1LL )
                      goto LABEL_164;
                    v50 = v14;
                    v51 = v13;
                    v3 = (unsigned __int64)v21;
                    ((void (__fastcall *)(__int64))cam_print_log)(3);
                    v18 = v135;
                    v10 = v136;
                    v21 = (const char *)v3;
                    v9 = v133;
                    v14 = v50;
                    v13 = v51;
                    v16 = &unk_393000;
                    goto LABEL_105;
                  }
                  v106 = v14;
                  v115 = v46;
                  v126 = v11;
                  v72 = v21;
                  v73 = v13;
                  v74 = v15;
                  ((void (__fastcall *)(__int64))cam_print_log)(3);
                  v46 = v115;
                  v11 = v126;
                  v16 = &unk_393000;
                  v18 = v135;
                  v10 = v136;
                  v14 = v106;
                  v24 = "reg addr: 0x%x Data: 0x%x";
                  v9 = v133;
                  v47 = debug_priority;
                  v23 = "byte %d: 0x%x";
                  v22 = "reg addr = 0x%x data type: %d";
                  v21 = v72;
                  v15 = v74;
                  v13 = v73;
                  v75 = v74[458] & 0x4000000000LL;
                  v49 = 2;
                  if ( v75 )
                    goto LABEL_59;
                }
                goto LABEL_92;
              }
            }
            else if ( v12 <= 2 )
            {
              goto LABEL_53;
            }
            if ( v12 == 3 )
            {
              v3 = (unsigned __int16)v20;
              if ( v18 <= (unsigned __int16)v20 )
                goto LABEL_164;
              v7 = (unsigned __int16)v20 + 1LL;
              v66 = (_BYTE *)(v9 + (unsigned __int16)v20);
              *v66 = BYTE2(v6[1]);
              if ( v18 == v7 )
                goto LABEL_164;
              v66[1] = BYTE1(v6[1]);
              if ( v18 <= (unsigned __int64)(unsigned __int16)v20 + 2 )
                goto LABEL_164;
              v67 = v16[919];
              v68 = v15[458] & 0x4000000000LL;
              v66[2] = v6[1];
              if ( v68 && !v67 )
              {
                v107 = v14;
                v116 = v46;
                v127 = v11;
                v76 = v21;
                v77 = v13;
                ((void (__fastcall *)(__int64))cam_print_log)(3);
                v15 = &unk_393000;
                v16 = &unk_393000;
                v14 = v107;
                v46 = v116;
                v11 = v127;
                v18 = v135;
                v10 = v136;
                v9 = v133;
                v67 = debug_priority;
                v24 = "reg addr: 0x%x Data: 0x%x";
                v23 = "byte %d: 0x%x";
                v22 = "reg addr = 0x%x data type: %d";
                v21 = v76;
                v13 = v77;
                v68 = debug_mdl & 0x4000000000LL;
                if ( (debug_mdl & 0x4000000000LL) != 0 )
                  goto LABEL_89;
              }
              else if ( v68 )
              {
LABEL_89:
                if ( !v67 )
                {
                  v117 = v46;
                  v128 = v11;
                  v98 = v13;
                  v108 = v14;
                  if ( v18 <= (unsigned __int16)v20 || v18 == v7 )
                    goto LABEL_164;
                  v78 = v15;
                  v79 = v16;
                  v3 = (unsigned __int64)v21;
                  ((void (__fastcall *)(__int64))cam_print_log)(3);
                  v18 = v135;
                  v10 = v136;
                  v67 = v79[919];
                  v21 = (const char *)v3;
                  v15 = v78;
                  v68 = v78[458] & 0x4000000000LL;
                  v9 = v133;
                  v13 = v98;
                  v14 = v108;
                  v46 = v117;
                  v11 = v128;
                  v16 = v79;
                  v22 = "reg addr = 0x%x data type: %d";
                  v23 = "byte %d: 0x%x";
                  v24 = "reg addr: 0x%x Data: 0x%x";
                }
              }
              v49 = 3;
              if ( v68 && !v67 )
              {
                v112 = v46;
                v123 = v11;
                if ( v18 <= (unsigned __int64)(unsigned __int16)v20 + 2 )
                  goto LABEL_164;
                v3 = v14;
                v80 = v16;
                v7 = v13;
                v81 = v21;
                ((void (__fastcall *)(__int64))cam_print_log)(3);
                v18 = v135;
                v10 = v136;
                v21 = v81;
                v9 = v133;
                v14 = v3;
                v13 = v7;
                v16 = v80;
                goto LABEL_105;
              }
              goto LABEL_92;
            }
            v3 = (unsigned __int16)v20;
            if ( v18 <= (unsigned __int16)v20 )
              goto LABEL_164;
            v7 = (unsigned __int16)v20 + 1LL;
            v61 = (_BYTE *)(v9 + (unsigned __int16)v20);
            *v61 = HIBYTE(v6[1]);
            if ( v18 == v7 )
              goto LABEL_164;
            v61[1] = *((_WORD *)v6 + 3);
            if ( v18 <= (unsigned __int64)(unsigned __int16)v20 + 2 )
              goto LABEL_164;
            v61[2] = BYTE1(v6[1]);
            if ( v18 <= (unsigned __int64)(unsigned __int16)v20 + 3 )
              goto LABEL_164;
            v62 = v16[919];
            v63 = v15[458] & 0x4000000000LL;
            v61[3] = v6[1];
            if ( v63 && !v62 )
            {
              v109 = v14;
              v118 = v46;
              v129 = v11;
              v82 = v21;
              v99 = v13;
              ((void (__fastcall *)(__int64))cam_print_log)(3);
              v15 = &unk_393000;
              v16 = &unk_393000;
              v13 = v99;
              v46 = v118;
              v11 = v129;
              v18 = v135;
              v10 = v136;
              v14 = v109;
              v9 = v133;
              v24 = "reg addr: 0x%x Data: 0x%x";
              v62 = debug_priority;
              v23 = "byte %d: 0x%x";
              v22 = "reg addr = 0x%x data type: %d";
              v21 = v82;
              v63 = debug_mdl & 0x4000000000LL;
              if ( (debug_mdl & 0x4000000000LL) != 0 )
              {
LABEL_76:
                if ( !v62 )
                {
                  v119 = v46;
                  v130 = v11;
                  v100 = v13;
                  v110 = v14;
                  if ( v18 <= (unsigned __int16)v20 || v18 == v7 )
                    goto LABEL_164;
                  v83 = v15;
                  v3 = (unsigned __int64)v21;
                  ((void (__fastcall *)(__int64))cam_print_log)(3);
                  v18 = v135;
                  v10 = v136;
                  v16 = &unk_393000;
                  v9 = v133;
                  v21 = (const char *)v3;
                  v63 = v83[458] & 0x4000000000LL;
                  v62 = debug_priority;
                  v13 = v100;
                  v14 = v110;
                  v46 = v119;
                  v11 = v130;
                  v15 = v83;
                  v22 = "reg addr = 0x%x data type: %d";
                  v23 = "byte %d: 0x%x";
                  v24 = "reg addr: 0x%x Data: 0x%x";
                }
              }
            }
            else if ( v63 )
            {
              goto LABEL_76;
            }
            if ( !v63 || v62 )
            {
              v49 = 4;
              if ( !v63 )
                goto LABEL_92;
LABEL_80:
              if ( v62 )
                goto LABEL_92;
              v112 = v46;
              v123 = v11;
              if ( v18 <= (unsigned __int64)(unsigned __int16)v20 + 3 )
                goto LABEL_164;
              v3 = v14;
              v64 = v16;
              v7 = v13;
              v65 = v21;
              ((void (__fastcall *)(__int64))cam_print_log)(3);
              v18 = v135;
              v10 = v136;
              v21 = v65;
              v9 = v133;
              v14 = v3;
              v13 = v7;
              v16 = v64;
LABEL_105:
              v46 = v112;
              v11 = v123;
              v15 = &unk_393000;
              v22 = "reg addr = 0x%x data type: %d";
              v23 = "byte %d: 0x%x";
              v24 = "reg addr: 0x%x Data: 0x%x";
              goto LABEL_92;
            }
            v120 = v46;
            v131 = v11;
            v101 = v13;
            if ( v18 <= (unsigned __int64)(unsigned __int16)v20 + 2 )
              goto LABEL_164;
            v3 = v14;
            v7 = (__int64)v15;
            v84 = v16;
            v85 = v21;
            ((void (__fastcall *)(__int64))cam_print_log)(3);
            v18 = v135;
            v10 = v136;
            v46 = v120;
            v11 = v131;
            v62 = v84[919];
            v21 = v85;
            v15 = (_QWORD *)v7;
            v9 = v133;
            v13 = v101;
            v16 = v84;
            v14 = v3;
            v22 = "reg addr = 0x%x data type: %d";
            v23 = "byte %d: 0x%x";
            v24 = "reg addr: 0x%x Data: 0x%x";
            v49 = 4;
            if ( (*(_QWORD *)(v7 + 3664) & 0x4000000000LL) != 0 )
              goto LABEL_80;
LABEL_92:
            v20 += v49;
            v2 = (unsigned int)(v49 + v2);
            if ( v46 >= *(_DWORD *)(v13 + 8) )
              break;
            v17 = v6 + 4;
            v69 = v6[4];
            if ( i3c_lookahead_en )
            {
              v70 = *v6;
              v6 += 4;
              v71 = v70 + v12 == v69;
              v44 = v46 + 1;
              if ( v71 )
                continue;
            }
            goto LABEL_115;
          }
          v17 = v6;
LABEL_115:
          v86 = v15[458];
          v19 = v46;
          if ( (v86 & 0x4000000000LL) != 0 && !v16[919] )
          {
            v132 = v11;
            v3 = v14;
            v87 = v21;
            v7 = v13;
            v88 = v16;
            v89 = v15;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v86 & 0x4000000000LL,
              4,
              v21,
              381,
              "offset: %d len: %d curr_mindx: %d",
              (unsigned __int16)v20,
              (unsigned __int16)v2,
              v14);
            v18 = v135;
            v10 = v136;
            v24 = "reg addr: 0x%x Data: 0x%x";
            v11 = v132;
            v9 = v133;
            v23 = "byte %d: 0x%x";
            v22 = "reg addr = 0x%x data type: %d";
            v21 = v87;
            v15 = v89;
            v16 = v88;
            v13 = v7;
            v14 = v3;
          }
          v25 = &v134[3 * (int)v14++];
          *(_BYTE *)v25 = 0;
          *((_WORD *)v25 + 1) = v2;
          v25[1] = v9 - (unsigned __int16)v2 + (unsigned __int16)v20;
          v26 = *(_DWORD *)(v13 + 8);
          if ( v19 >= v26 )
          {
            v8 = v134;
            v6 = (unsigned int *)&unk_2FD000;
            goto LABEL_122;
          }
        }
      }
      v26 = 0;
LABEL_122:
      v93 = v15[458];
      LODWORD(v7) = v14;
      if ( (v93 & 0x4000000000LL) != 0 && !v16[919] )
      {
        v97 = v13;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v93 & 0x4000000000LL,
          4,
          "cam_qup_i3c_write_optimized",
          389,
          "Original reg writes: %d optimized Writes: %d",
          v26,
          v14);
        v10 = v136;
        v13 = v97;
        if ( (v7 & 0x80000000) == 0 )
          goto LABEL_125;
      }
      else if ( (v14 & 0x80000000) == 0 )
      {
LABEL_125:
        v3 = v13;
        v94 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 8LL), v8, (unsigned int)v7);
        if ( !v94 )
          goto LABEL_148;
        if ( v94 != -107 )
        {
          LODWORD(v7) = v94;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x4000000000LL,
            1,
            "cam_qup_i3c_write_table",
            446,
            "Failed with i3c_write: rc = %d",
            v94);
          goto LABEL_152;
        }
        usleep_range_state(1000, 1005, 2);
        v94 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL), v8, *(unsigned int *)(v3 + 8));
        if ( !v94 )
          goto LABEL_148;
        if ( v94 == -107 )
        {
          v95 = 1000;
          usleep_range_state(1000, 1005, 2);
          v94 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL), v8, *(unsigned int *)(v3 + 8));
          if ( !v94 )
            goto LABEL_148;
          if ( v94 == -107 )
          {
            usleep_range_state(1000, 1005, 2);
            v94 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL), v8, *(unsigned int *)(v3 + 8));
            if ( !v94 )
              goto LABEL_148;
            if ( v94 == -107 )
            {
              usleep_range_state(1000, 1005, 2);
              v94 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL), v8, *(unsigned int *)(v3 + 8));
              if ( v94 )
              {
                if ( v94 == -107 )
                {
                  usleep_range_state(1000, 1005, 2);
                  v2 = (__int64)v8;
                  LODWORD(v7) = i3c_device_do_priv_xfers(
                                  *(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL),
                                  v8,
                                  *(unsigned int *)(v3 + 8));
                  if ( !(_DWORD)v7 )
                    goto LABEL_152;
                  if ( (_DWORD)v7 != -107 )
                  {
                    v95 = 4000;
                    goto LABEL_170;
                  }
                  usleep_range_state(1000, 1005, 2);
                  LODWORD(v7) = i3c_device_do_priv_xfers(
                                  *(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL),
                                  v8,
                                  *(unsigned int *)(v3 + 8));
                  if ( !(_DWORD)v7 )
                    goto LABEL_152;
                  if ( (_DWORD)v7 != -107 )
                    goto LABEL_165;
                  usleep_range_state(1000, 1005, 2);
                  LODWORD(v7) = i3c_device_do_priv_xfers(
                                  *(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL),
                                  v8,
                                  *(unsigned int *)(v3 + 8));
                  if ( !(_DWORD)v7 )
                    goto LABEL_152;
                  if ( (_DWORD)v7 != -107 )
                  {
                    v95 = 6000;
                    goto LABEL_170;
                  }
                  usleep_range_state(1000, 1005, 2);
                  LODWORD(v7) = i3c_device_do_priv_xfers(
                                  *(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL),
                                  v8,
                                  *(unsigned int *)(v3 + 8));
                  if ( !(_DWORD)v7 )
                    goto LABEL_152;
                  if ( (_DWORD)v7 != -107 )
                  {
                    v95 = 7000;
                    goto LABEL_170;
                  }
                  usleep_range_state(1000, 1005, 2);
                  LODWORD(v7) = i3c_device_do_priv_xfers(
                                  *(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL),
                                  v8,
                                  *(unsigned int *)(v3 + 8));
                  if ( !(_DWORD)v7 )
                    goto LABEL_152;
                  if ( (_DWORD)v7 != -107 )
                  {
                    v95 = 8000;
                    goto LABEL_170;
                  }
                  usleep_range_state(1000, 1005, 2);
                  LODWORD(v7) = i3c_device_do_priv_xfers(
                                  *(_QWORD *)(*(_QWORD *)(v136 + 8) + 8LL),
                                  v8,
                                  *(unsigned int *)(v3 + 8));
                  if ( !(_DWORD)v7 )
                    goto LABEL_152;
                  if ( (_DWORD)v7 != -107 )
                  {
                    v95 = 9000;
                    goto LABEL_170;
                  }
                  v94 = -107;
                  v95 = 10000;
LABEL_171:
                  v8 = (_QWORD *)v2;
                }
                else
                {
                  v95 = 3000;
                }
                goto LABEL_151;
              }
LABEL_148:
              LODWORD(v7) = v94;
              goto LABEL_152;
            }
            v95 = 2000;
          }
        }
        else
        {
          v95 = 0;
        }
LABEL_151:
        LODWORD(v7) = v94;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x4000000000LL,
          1,
          "cam_qup_i3c_write_table",
          444,
          "Retry Failed i3c_write: rc = %d, us = %d",
          v94,
          v95);
LABEL_152:
        v96 = *(unsigned __int16 *)(v3 + 20);
        if ( (unsigned int)v96 < 0x15 )
        {
          if ( *(_WORD *)(v3 + 20) )
            usleep_range_state(
              1000LL * *(unsigned __int16 *)(v3 + 20),
              1000 * (unsigned int)*(unsigned __int16 *)(v3 + 20) + 1000,
              2);
        }
        else
        {
          msleep(v96);
        }
      }
      v9 = v133;
      goto LABEL_10;
    }
  }
  LODWORD(v7) = -22;
LABEL_10:
  kfree(v9);
  if ( *((_BYTE *)v6 + 2904) == 1 )
    cam_mem_trace_free(v8, 0);
  else
    kvfree(v8);
  return (unsigned int)v7;
}
