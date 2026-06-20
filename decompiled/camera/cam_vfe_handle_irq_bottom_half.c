__int64 __fastcall cam_vfe_handle_irq_bottom_half(_DWORD *a1, __int64 a2)
{
  _DWORD *v3; // x27
  __int64 v4; // x25
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x10
  int v8; // w11
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  char v13; // w12
  __int64 v14; // x8
  _DWORD *v15; // x9
  int v16; // w11
  int v17; // w10
  int v18; // w12
  int v19; // w9
  _BOOL4 v20; // w19
  _BOOL4 v21; // w22
  int v22; // w9
  _BOOL4 v23; // w20
  int v24; // w20
  __int64 v25; // x0
  char v26; // w8
  unsigned int v27; // w9
  int v28; // w19
  int v29; // w22
  int v30; // w24
  int v31; // w8
  __int64 v32; // x27
  unsigned int v33; // w28
  __int64 (__fastcall *v34)(); // x8
  const char *v35; // x7
  __int64 v36; // x9
  const char *v37; // x7
  _DWORD *v38; // x8
  __int64 v39; // x0
  int v40; // w8
  int v41; // w10
  __int64 v42; // x9
  const char *v43; // x7
  int v44; // w8
  _DWORD *v45; // x8
  __int64 v46; // x0
  _QWORD *v47; // x22
  __int64 v48; // x8
  __int64 v49; // x23
  unsigned int *v50; // x8
  const char *v51; // x3
  __int64 v52; // x4
  __int64 v53; // x6
  __int64 v54; // x7
  const char *v55; // x5
  __int64 v56; // x9
  int v57; // w10
  __int64 v58; // x19
  _DWORD *v59; // x11
  __int64 v60; // x20
  unsigned int v61; // w25
  __int64 v62; // x8
  const char *v63; // x3
  __int64 v64; // x4
  const char *v65; // x5
  _QWORD *v66; // x20
  __int64 v67; // x24
  int v68; // w25
  __int64 v69; // x8
  __int64 v70; // x26
  unsigned __int64 v71; // x27
  __int64 v72; // x20
  __int64 v73; // x8
  unsigned int *v74; // x8
  __int64 v75; // x20
  __int64 v76; // x8
  const char *v77; // x6
  char v78; // w8
  char v79; // w19
  _QWORD *v80; // x19
  char v81; // w20
  __int64 v82; // x11
  __int64 v83; // x9
  __int64 v84; // x10
  __int64 v85; // x12
  __int64 v86; // x13
  __int64 v87; // x14
  __int64 v88; // x8
  __int64 v89; // x15
  __int64 v90; // x19
  __int64 v91; // x16
  __int64 v92; // x8
  __int64 v93; // x23
  const char *v94; // x11
  unsigned int *v95; // x25
  int v96; // w21
  int v97; // w20
  int v98; // w27
  unsigned int v99; // w28
  unsigned int v100; // w0
  unsigned __int64 v101; // x22
  __int64 v102; // x8
  __int64 v103; // x7
  int v104; // w28
  unsigned int v105; // w19
  __int64 *v106; // x26
  bool v107; // cc
  __int64 v108; // x8
  int v109; // w0
  __int64 v110; // x7
  unsigned int v111; // w19
  __int64 *v112; // x26
  unsigned int v113; // w21
  unsigned int v114; // w8
  const char *v115; // x7
  const char *v116; // x9
  char v117; // [xsp+0h] [xbp-4F0h]
  int v119; // [xsp+1Ch] [xbp-4D4h]
  __int64 v120; // [xsp+20h] [xbp-4D0h]
  char v121; // [xsp+2Ch] [xbp-4C4h]
  __int64 *v122; // [xsp+30h] [xbp-4C0h]
  __int64 *v123; // [xsp+38h] [xbp-4B8h]
  const char *v124; // [xsp+40h] [xbp-4B0h]
  int v125; // [xsp+48h] [xbp-4A8h]
  __int64 v126; // [xsp+48h] [xbp-4A8h]
  int v127; // [xsp+50h] [xbp-4A0h]
  __int64 v128; // [xsp+50h] [xbp-4A0h]
  int v129; // [xsp+5Ch] [xbp-494h]
  int v130; // [xsp+5Ch] [xbp-494h]
  int v131; // [xsp+60h] [xbp-490h]
  unsigned int v132; // [xsp+60h] [xbp-490h]
  __int64 v133; // [xsp+60h] [xbp-490h]
  __int64 v134; // [xsp+68h] [xbp-488h] BYREF
  __int64 v135; // [xsp+70h] [xbp-480h]
  __int64 v136; // [xsp+78h] [xbp-478h]
  __int64 v137; // [xsp+80h] [xbp-470h] BYREF
  int v138; // [xsp+88h] [xbp-468h]
  __int64 v139; // [xsp+90h] [xbp-460h] BYREF
  unsigned __int64 v140; // [xsp+98h] [xbp-458h]
  __int64 v141; // [xsp+A0h] [xbp-450h]
  __int64 v142; // [xsp+A8h] [xbp-448h]
  __int64 *v143; // [xsp+B0h] [xbp-440h]
  __int64 v144; // [xsp+B8h] [xbp-438h] BYREF
  unsigned __int64 v145; // [xsp+C0h] [xbp-430h] BYREF
  _QWORD v146[2]; // [xsp+C8h] [xbp-428h]
  int v147; // [xsp+D8h] [xbp-418h]
  char s[1024]; // [xsp+E0h] [xbp-410h] BYREF
  __int64 v149; // [xsp+4E0h] [xbp-10h]

  v3 = a1;
  v149 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v142 = 0;
  v143 = nullptr;
  v140 = 0;
  v141 = 0;
  v139 = 0;
  v138 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_handle_irq_bottom_half",
      2461,
      "Invalid params handle_priv:%pK, evt_payload_priv:%pK",
      a1,
      (const void *)a2);
    result = 0xFFFFFFFFLL;
    goto LABEL_160;
  }
  v4 = *((_QWORD *)a1 + 3);
  v144 = a2;
  if ( *(_DWORD *)(*(_QWORD *)(v4 + 72) + 10512LL) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_handle_irq_bottom_half",
      2472,
      "VFE:%u Handling overflow, Ignore bottom half",
      *(_DWORD *)(*((_QWORD *)a1 + 2) + 4LL));
    cam_vfe_top_put_evt_payload(v4, &v144);
    result = 1;
LABEL_160:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = *(_QWORD *)(a2 + 48);
  v7 = *(_QWORD *)(a2 + 80);
  v8 = *(_DWORD *)(a2 + 32);
  v120 = v4;
  v134 = *(_QWORD *)(a2 + 40);
  v135 = v6;
  v9 = *((_QWORD *)a1 + 2);
  v136 = v7;
  LODWORD(v7) = *a1;
  LODWORD(v6) = a1[1];
  LODWORD(v9) = *(_DWORD *)(v9 + 4);
  v147 = v8;
  v140 = __PAIR64__(v9, v6);
  v141 = 0x200000000LL;
  v143 = &v134;
  v10 = *(_QWORD *)(a2 + 16);
  v11 = *(_QWORD *)(a2 + 24);
  LODWORD(v139) = v7;
  v12 = *(_QWORD *)(v4 + 24);
  v13 = *(_BYTE *)(v4 + 22814);
  v146[0] = v10;
  v146[1] = v11;
  v14 = *(unsigned int *)(v12 + 776);
  if ( (v13 & 1) == 0 )
  {
    if ( (unsigned int)v14 > 4 )
      goto LABEL_169;
    if ( (*(_DWORD *)(*(_QWORD *)(v4 + 64) + 4LL) & *((_DWORD *)v146 + v14)) != 0 )
      cam_vfe_handle_sof(v4, a2, &v139);
    goto LABEL_69;
  }
  if ( (unsigned int)v14 > 4 )
    goto LABEL_169;
  v15 = *(_DWORD **)(v4 + 64);
  v16 = *((_DWORD *)v146 + v14);
  v18 = v15[1];
  v17 = v15[2];
  v19 = v15[4];
  if ( (v16 & (v17 | v18 | v19)) == 0 )
  {
LABEL_69:
    v44 = -1;
    goto LABEL_71;
  }
  v131 = v16 & v18;
  v20 = (v16 & v18) != 0;
  v129 = v16 & v17;
  v21 = (v16 & v17) != 0;
  v22 = v16 & v19;
  v23 = v22 != 0;
  v127 = v22;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    if ( v131 )
      v115 = "Y";
    else
      v115 = "N";
    if ( v129 )
      v116 = "Y";
    else
      v116 = "N";
    v117 = (char)v116;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_handle_frame_timing_irqs",
      2393,
      "VFE:%u SOF:%s EPOCH:%s EOF:%s",
      *(unsigned int *)(*(_QWORD *)(v4 + 16) + 4LL),
      v115);
  }
  v24 = v21 + v20 + v23;
  if ( *(_DWORD *)(v4 + 22804) == v24 )
  {
    if ( (unsigned int)__ratelimit(&cam_vfe_handle_frame_timing_irqs__rs, "cam_vfe_handle_frame_timing_irqs") )
      v25 = 3;
    else
      v25 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v25,
      8,
      2,
      "cam_vfe_handle_frame_timing_irqs",
      2399,
      "VFE:%u top-half delay",
      *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL));
  }
  if ( !v24 )
  {
LABEL_70:
    v44 = 0;
    goto LABEL_71;
  }
  v26 = debug_mdl;
  v27 = debug_priority;
  v125 = v24;
  if ( v127 )
    v28 = -1;
  else
    v28 = 0;
  if ( v129 )
    v29 = -1;
  else
    v29 = 0;
  if ( v131 )
    v30 = -1;
  else
    v30 = 0;
  while ( 1 )
  {
    if ( (v26 & 8) != 0 && v27 <= 2 )
    {
      v36 = *(unsigned int *)(v4 + 22800);
      v37 = "INVALID";
      if ( (unsigned int)v36 <= 2 )
        v37 = off_44EC18[v36];
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v26 & 8,
        4,
        "cam_vfe_handle_frame_timing_irqs",
        2407,
        "VFE:%u enter state:%s (%d/%d)",
        *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL),
        v37,
        v24,
        v125);
      v31 = *(_DWORD *)(v4 + 22800);
      if ( !v31 )
      {
LABEL_42:
        v32 = *((_QWORD *)v3 + 3);
        v24 += v30;
        if ( !v131 )
        {
          v35 = "SOF";
          goto LABEL_52;
        }
        v33 = 1;
        v34 = (__int64 (__fastcall *)())cam_vfe_handle_sof;
        goto LABEL_44;
      }
    }
    else
    {
      v31 = *(_DWORD *)(v4 + 22800);
      if ( !v31 )
        goto LABEL_42;
    }
    if ( v31 != 2 )
      break;
    v32 = *((_QWORD *)v3 + 3);
    v24 += v28;
    if ( !v127 )
    {
      v35 = "EOF";
LABEL_52:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_vfe_handle_frame_timing_irqs",
        2371,
        "VFE:%u missed %s",
        *(_DWORD *)(*(_QWORD *)(v32 + 16) + 4LL),
        v35);
      goto LABEL_53;
    }
    v33 = 4;
    v34 = (__int64 (__fastcall *)())&cam_vfe_handle_eof;
LABEL_44:
    if ( *((_DWORD *)v34 - 1) != -1970210571 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64 *))v34)(v32, a2, &v139);
    if ( (*(_BYTE *)(*(_QWORD *)(v32 + 72) + 10920LL) & 1) == 0 )
    {
      v38 = *(_DWORD **)(v32 + 80);
      if ( v38 )
      {
        v39 = *(_QWORD *)(v32 + 88);
        if ( *(v38 - 1) != 414296116 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64 *))v38)(v39, v33, &v139);
      }
    }
LABEL_53:
    v40 = *(_DWORD *)(v32 + 22800);
    if ( v40 != 2 )
    {
      if ( v40 == 1 )
      {
        v41 = 2;
        goto LABEL_61;
      }
      if ( !v40 )
      {
        if ( *((_BYTE *)a1 + 144) )
          v41 = 2;
        else
          v41 = 1;
        goto LABEL_61;
      }
    }
    v41 = 0;
LABEL_61:
    *(_DWORD *)(v32 + 22800) = v41;
    v26 = debug_mdl;
    v27 = debug_priority;
    if ( (debug_mdl & 8) != 0 )
    {
      v3 = a1;
      if ( (unsigned int)debug_priority <= 2 )
      {
        v42 = *(unsigned int *)(v4 + 22800);
        v43 = "INVALID";
        if ( (unsigned int)v42 <= 2 )
          v43 = off_44EC18[v42];
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_handle_frame_timing_irqs",
          2439,
          "VFE:%u exit state:%s (%d/%d)",
          *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL),
          v43,
          v24,
          v125);
        v26 = debug_mdl;
        v27 = debug_priority;
      }
    }
    else
    {
      v3 = a1;
    }
    if ( v24 <= 0 )
      goto LABEL_70;
  }
  if ( v31 == 1 )
  {
    v32 = *((_QWORD *)v3 + 3);
    v24 += v29;
    if ( !v129 )
    {
      v35 = "EPOCH";
      goto LABEL_52;
    }
    v33 = 3;
    v34 = cam_vfe_handle_epoch;
    goto LABEL_44;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_handle_frame_timing_irqs",
    2427,
    "VFE:%u frame state machine in invalid state",
    *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL));
  v44 = -22;
LABEL_71:
  v119 = v146[0];
  if ( (*(_DWORD *)(*(_QWORD *)(v4 + 64) + 20LL) & v146[0]) != 0 )
  {
    v45 = *(_DWORD **)(v4 + 80);
    LODWORD(v137) = 3;
    v143 = &v137;
    if ( v45 )
    {
      v46 = *(_QWORD *)(v4 + 88);
      if ( *(v45 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))v45)(v46, 0, &v139);
    }
    v47 = *(_QWORD **)(v4 + 72);
    v48 = v47[2];
    if ( *(_DWORD *)(v48 + 168) )
    {
      v49 = 0;
      v132 = v3[1];
      while ( 1 )
      {
        v56 = *(_QWORD *)(v48 + 176) + 32 * v49;
        v57 = *(_DWORD *)v56;
        if ( (*(_DWORD *)v56 & v119) != 0 )
        {
          v58 = 32 * v49;
          v59 = *(_DWORD **)(v120 + 64);
          if ( (v59[8] & v57) != 0 )
          {
            v60 = v47[1304];
            v61 = cam_io_r(*(_QWORD *)(v60 + 288) + *(_QWORD *)(v48 + 256) + *(unsigned int *)(v47[1] + 108LL));
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_top_ver4_print_ipp_violation_info",
              741,
              "VFE[%u] %s occurred at [%llu: %09llu]",
              *(_DWORD *)(v60 + 20),
              *(const char **)(*(_QWORD *)(v47[2] + 176LL) + v58 + 8),
              *(_QWORD *)(a2 + 40),
              *(_QWORD *)(a2 + 48));
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_top_ver4_print_ipp_violation_info",
              742,
              "%s",
              *(const char **)(*(_QWORD *)(v47[2] + 176LL) + v58 + 16));
            v62 = *(_QWORD *)(v47[2] + 64LL);
            if ( !v62 )
            {
              v63 = "cam_vfe_top_ver4_print_ipp_violation_info";
              v64 = 749;
              v65 = "IPP Violation status 0x%x";
LABEL_85:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                8,
                1,
                v63,
                v64,
                v65,
                v61);
              goto LABEL_80;
            }
            v50 = (unsigned int *)(v62 + 16LL * v61);
            v51 = "cam_vfe_top_ver4_print_ipp_violation_info";
            v52 = 747;
            v53 = *v50;
            v54 = *((_QWORD *)v50 + 1);
            v55 = "IPP Violation Module id: [%u %s]";
          }
          else
          {
            if ( (v59[10] & v57) != 0 )
            {
              v66 = *(_QWORD **)(v120 + 72);
              v67 = v66[1304];
              v68 = cam_io_r(*(_QWORD *)(v67 + 288) + *(_QWORD *)(v66[2] + 280LL) + *(unsigned int *)(v66[1] + 116LL));
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_top_ver4_print_pdaf_violation_info",
                  706,
                  "VFE[%u] PDAF HW Violation status 0x%x",
                  *(_DWORD *)(v67 + 20),
                  v68);
              v69 = v66[2];
              if ( *(_DWORD *)(v69 + 184) )
              {
                v70 = 0;
                v71 = 0;
                do
                {
                  if ( (*(_DWORD *)(*(_QWORD *)(v69 + 192) + v70) & v68) != 0 )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_vfe_top_ver4_print_pdaf_violation_info",
                      714,
                      "VFE[%u] %s occurred at [%llu: %09llu]",
                      *(_DWORD *)(v67 + 20),
                      *(const char **)(*(_QWORD *)(v69 + 176) + v58 + 8),
                      *(_QWORD *)(a2 + 40),
                      *(_QWORD *)(a2 + 48));
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_vfe_top_ver4_print_pdaf_violation_info",
                      715,
                      "%s",
                      *(const char **)(*(_QWORD *)(v66[2] + 176LL) + v58 + 16));
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_vfe_top_ver4_print_pdaf_violation_info",
                      717,
                      "PDAF violation description: %s",
                      *(const char **)(*(_QWORD *)(v66[2] + 192LL) + v70 + 8));
                    v69 = v66[2];
                  }
                  ++v71;
                  v70 += 16;
                }
                while ( v71 < *(unsigned int *)(v69 + 184) );
              }
              goto LABEL_80;
            }
            if ( (v59[9] & v57) == 0 )
            {
              if ( (v59[11] & v57) != 0 )
              {
                cam_vfe_top_ver4_print_diag_sensor_frame_count_info(v120, a2, (unsigned int)v49, v132, 1);
                goto LABEL_80;
              }
              if ( (v59[12] & v57) == 0 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_vfe_top_ver4_print_top_irq_error",
                  959,
                  "%s occurred at [%llu: %09llu]",
                  *(const char **)(v56 + 8),
                  *(_QWORD *)(a2 + 40),
                  *(_QWORD *)(a2 + 48));
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_vfe_top_ver4_print_top_irq_error",
                  960,
                  "%s",
                  *(const char **)(*(_QWORD *)(v47[2] + 176LL) + v58 + 16));
                v77 = *(const char **)(*(_QWORD *)(v47[2] + 176LL) + v58 + 24);
                if ( v77 )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    8,
                    1,
                    "cam_vfe_top_ver4_print_top_irq_error",
                    963,
                    "Debug: %s",
                    v77);
                goto LABEL_80;
              }
              v75 = v47[1304];
              v61 = cam_io_r(*(_QWORD *)(v75 + 288) + *(_QWORD *)(v48 + 256) + *(unsigned int *)(v47[1] + 120LL));
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_top_ver4_print_core_violation_info",
                899,
                "VFE[%u] %s occurred at [%llu: %09llu]",
                *(_DWORD *)(v75 + 20),
                *(const char **)(*(_QWORD *)(v47[2] + 176LL) + v58 + 8),
                *(_QWORD *)(a2 + 40),
                *(_QWORD *)(a2 + 48));
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_top_ver4_print_core_violation_info",
                900,
                "%s",
                *(const char **)(*(_QWORD *)(v47[2] + 176LL) + v58 + 16));
              v76 = *(_QWORD *)(v47[2] + 240LL);
              if ( v76 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_vfe_top_ver4_print_core_violation_info",
                  905,
                  "Core Violation status %u, id: [%u %s]",
                  v61,
                  *(_DWORD *)(v76 + 16LL * v61),
                  *(const char **)(v76 + 16LL * v61 + 8));
                goto LABEL_80;
              }
              v63 = "cam_vfe_top_ver4_print_core_violation_info";
              v64 = 907;
              v65 = "Core Violation status %u";
              goto LABEL_85;
            }
            v72 = v47[1304];
            v61 = cam_io_r(*(_QWORD *)(v72 + 288) + *(_QWORD *)(v48 + 264) + *(unsigned int *)(v47[1] + 112LL));
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_top_ver4_print_bayer_violation_info",
              771,
              "VFE[%u] %s occurred at [%llu: %09llu]",
              *(_DWORD *)(v72 + 20),
              *(const char **)(*(_QWORD *)(v47[2] + 176LL) + v58 + 8),
              *(_QWORD *)(a2 + 40),
              *(_QWORD *)(a2 + 48));
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_top_ver4_print_bayer_violation_info",
              772,
              "%s",
              *(const char **)(*(_QWORD *)(v47[2] + 176LL) + v58 + 16));
            v73 = *(_QWORD *)(v47[2] + 72LL);
            if ( !v73 )
            {
              v63 = "cam_vfe_top_ver4_print_bayer_violation_info";
              v64 = 779;
              v65 = "Bayer Violation status 0x%x";
              goto LABEL_85;
            }
            v74 = (unsigned int *)(v73 + 16LL * v61);
            v51 = "cam_vfe_top_ver4_print_bayer_violation_info";
            v52 = 777;
            v53 = *v74;
            v54 = *((_QWORD *)v74 + 1);
            v55 = "Bayer Violation Module id: [%u %s]";
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
            3,
            8,
            1,
            v51,
            v52,
            v55,
            v53,
            v54);
        }
LABEL_80:
        v48 = v47[2];
        if ( ++v49 >= (unsigned __int64)*(unsigned int *)(v48 + 168) )
        {
          v4 = v120;
          v47 = *(_QWORD **)(v120 + 72);
          break;
        }
      }
    }
    if ( (*(_BYTE *)(v47[1] + 780LL) & 4) != 0 )
    {
      v78 = 1;
      do
      {
        v80 = *(_QWORD **)(v4 + 72);
        v81 = v78;
        v145 = 0;
        memset(s, 0, sizeof(s));
        v82 = 72;
        v84 = v80[1];
        v83 = v80[2];
        if ( (v81 & 1) != 0 )
          v82 = 64;
        v85 = 736;
        if ( (v81 & 1) != 0 )
          v85 = 720;
        v86 = 740;
        if ( (v81 & 1) != 0 )
          v86 = 724;
        v87 = 728;
        v88 = v80[1304];
        if ( (v81 & 1) != 0 )
          v87 = 712;
        v89 = 264;
        v90 = *(_QWORD *)(v83 + v82);
        if ( (v81 & 1) != 0 )
          v89 = 256;
        v91 = 708;
        v92 = *(_QWORD *)(v88 + 288);
        if ( (v81 & 1) != 0 )
          v91 = 704;
        v128 = *(unsigned int *)(v84 + v86);
        v93 = v92 + *(_QWORD *)(v83 + v89);
        v121 = v81;
        v126 = *(unsigned int *)(v84 + v85);
        v94 = "BAYER";
        if ( (v81 & 1) != 0 )
          v94 = "MAIN_PP";
        v95 = (unsigned int *)(v84 + v87);
        v124 = v94;
        v133 = *(unsigned int *)(v84 + v91);
        v96 = 0;
        v97 = 0;
        v98 = 0;
        v130 = cam_io_r_mb(v93 + v133);
        v122 = (__int64 *)(v90 + 520);
        v123 = (__int64 *)(v90 + 8);
        while ( 1 )
        {
          cam_io_w_mb(v130 | (unsigned int)(16 * v98), v93 + v133);
          v99 = cam_io_r_mb(v93 + v128);
          v100 = cam_io_r_mb(v93 + v126);
          v101 = (((((10000 * (unsigned __int64)v100) >> 32) + 10000LL * v99) / 0x2710) << 32)
               | (unsigned int)(((10000LL * v100) & 0xFFFFFFF0LL
                               | (((((10000 * (unsigned __int64)v100) >> 32) + 10000LL * v99) % 0x2710) << 32))
                              / 0x2710);
          if ( !v101 )
            break;
          v102 = *v95;
          if ( (_DWORD)v102 )
          {
            v104 = cam_io_r_mb(v93 + v102);
            v105 = v104 ^ v97;
            if ( v104 != v97 )
            {
              v106 = v123;
              do
              {
                if ( (v105 & 1) != 0 )
                  cam_print_to_buffer((__int64)s, 0x400u, &v145, 3u, 8u, "%s ", *v106, v103, v117);
                v107 = v105 > 1;
                v106 += 2;
                v105 >>= 1;
              }
              while ( v107 );
            }
            v108 = v95[1];
            v97 |= v104;
            if ( (_DWORD)v108 )
            {
              v109 = cam_io_r_mb(v93 + v108);
              v111 = v109 ^ v96;
              v96 |= v109;
              if ( v111 )
              {
                v112 = v122;
                do
                {
                  if ( (v111 & 1) != 0 )
                    cam_print_to_buffer((__int64)s, 0x400u, &v145, 3u, 8u, "%s ", *v112, v110, v117);
                  v107 = v111 > 1;
                  v112 += 2;
                  v111 >>= 1;
                }
                while ( v107 );
              }
            }
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            3,
            "cam_vfe_top_ver4_read_debug_err_vectors",
            440,
            "%s HM CLC(s) error that occurred in time order %d at timestamp %lld: %s",
            v124,
            v98,
            v101,
            s);
          memset(s, 0, sizeof(s));
          if ( ++v98 == 4 )
          {
            cam_io_w_mb(v130 | 0x40u, v93 + v133);
            v79 = v121;
            goto LABEL_111;
          }
        }
        v79 = v121;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_top_ver4_read_debug_err_vectors",
            416,
            "Debug IRQ vectors already read, skip");
LABEL_111:
        v4 = v120;
        v78 = 0;
      }
      while ( (v79 & 1) != 0 );
      v47 = *(_QWORD **)(v120 + 72);
    }
    cam_vfe_top_ver4_print_debug_regs(v47);
    v3 = a1;
    v44 = -1;
  }
  v113 = v44;
  if ( (*(_BYTE *)(*(_QWORD *)(v4 + 72) + 10928LL) & 1) != 0 && (*(_DWORD *)(*(_QWORD *)(v4 + 64) + 4LL) & v119) != 0 )
    cam_vfe_top_ver4_print_diag_sensor_frame_count_info(v4, v144, 0, (unsigned int)v3[1], 0);
  v114 = *(_DWORD *)(*(_QWORD *)(v4 + 24) + 776LL);
  if ( v114 <= 4 )
  {
    if ( (*(_DWORD *)(*(_QWORD *)(v4 + 64) + 16LL) & *((_DWORD *)v146 + v114)) == 0
      || (cam_vfe_top_dump_perf_counters("EOF", v3 + 32, *(_QWORD *)(v4 + 72)),
          v114 = *(_DWORD *)(*(_QWORD *)(v4 + 24) + 776LL),
          v114 <= 4) )
    {
      if ( (*(_DWORD *)(*(_QWORD *)(v4 + 64) + 4LL) & *((_DWORD *)v146 + v114)) != 0 )
        cam_vfe_top_dump_perf_counters("SOF", v3 + 32, *(_QWORD *)(v4 + 72));
      cam_vfe_top_put_evt_payload(v4, &v144);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_handle_irq_bottom_half",
          2549,
          "VFE:%u returning status = %d",
          HIDWORD(v140),
          v113);
      result = v113;
      goto LABEL_160;
    }
  }
LABEL_169:
  __break(0x5512u);
  __break(1u);
  return cam_vfe_res_mux_deinit();
}
