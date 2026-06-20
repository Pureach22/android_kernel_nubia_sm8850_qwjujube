__int64 __fastcall cam_vfe_bus_acquire_vfe_out(__int64 a1, __int64 a2)
{
  _DWORD *v3; // x8
  __int64 v5; // x22
  int v6; // kr00_4
  unsigned int v7; // w19
  int v8; // w9
  int v9; // w8
  int v10; // w11
  int v11; // w10
  __int64 result; // x0
  char v13; // w23
  unsigned int v14; // w28
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x25
  __int64 v19; // x27
  unsigned int v20; // w24
  unsigned int v21; // w22
  __int64 v22; // x8
  _QWORD *v23; // x14
  __int64 v24; // x8
  int v25; // w8
  __int64 v26; // x9
  _DWORD *v27; // x12
  _QWORD *v28; // x13
  int v29; // w9
  __int64 v30; // x16
  int v31; // w26
  int v32; // w15
  unsigned int v33; // w17
  __int64 v34; // x6
  __int64 v35; // x0
  int *i; // x9
  _DWORD *v37; // x24
  int *v38; // x23
  unsigned int v39; // w25
  unsigned int v40; // w10
  int *v41; // x25
  int **v42; // x28
  int v43; // w23
  _QWORD *v44; // x24
  int v45; // w25
  unsigned int v46; // w22
  int *v47; // x24
  _DWORD *v48; // x22
  _QWORD *v49; // x8
  int **v50; // x8
  _QWORD *v51; // x9
  __int64 v52; // x10
  _QWORD *v53; // x2
  _QWORD *v54; // x1
  __int64 v55; // x8
  __int64 v56; // x22
  __int64 v57; // x24
  __int64 v58; // x25
  _DWORD *v59; // x28
  unsigned int v60; // w23
  unsigned int wm_idx; // w0
  __int64 v62; // x26
  int v63; // w6
  unsigned int *v64; // x25
  unsigned int v65; // w9
  int v66; // w8
  char v67; // w9
  unsigned int v68; // w10
  unsigned int v69; // w8
  __int64 v70; // x6
  unsigned int v71; // w8
  int v72; // w9
  int v73; // w8
  unsigned int v74; // w8
  unsigned int v75; // w8
  unsigned int v76; // w8
  __int64 v77; // x8
  unsigned int v78; // w8
  unsigned int v79; // w9
  unsigned int v80; // w8
  unsigned int v81; // w9
  int v82; // w6
  char v83; // w8
  unsigned int v84; // w28
  char v85; // w23
  char v86; // w23
  char v87; // w23
  char v88; // w23
  __int64 v89; // x4
  int **v90; // x8
  __int64 v91; // x9
  __int64 v92; // x8
  unsigned int v93; // w25
  unsigned int v94; // w21
  char v95; // w8
  _QWORD *v96; // x22
  unsigned int cpas_hw_version; // w0
  int v98; // w8
  const char *v99; // x5
  __int64 v100; // x4
  __int64 v101; // x6
  __int64 v102; // x11
  int v103; // w10
  unsigned int v104; // w11
  __int64 v105; // x10
  unsigned int v106; // w9
  const char *v107; // x5
  __int64 v108; // x4
  __int64 v109; // x8
  __int64 v110; // x9
  unsigned int v111; // w22
  int v112; // w24
  __int64 v113; // x25
  unsigned int v114; // w28
  unsigned int v115; // w22
  __int64 v116; // x24
  __int64 v117; // x13
  _QWORD *v118; // [xsp+8h] [xbp-38h]
  unsigned int v119; // [xsp+10h] [xbp-30h]
  unsigned int v120; // [xsp+10h] [xbp-30h]
  int v121; // [xsp+14h] [xbp-2Ch]
  int v122; // [xsp+14h] [xbp-2Ch]
  int v123; // [xsp+14h] [xbp-2Ch]
  __int64 v124; // [xsp+18h] [xbp-28h]
  __int64 v125; // [xsp+20h] [xbp-20h]
  __int64 v126; // [xsp+20h] [xbp-20h]
  __int64 v127; // [xsp+20h] [xbp-20h]
  __int64 v128; // [xsp+20h] [xbp-20h]
  unsigned int v129; // [xsp+28h] [xbp-18h]
  unsigned int v130; // [xsp+28h] [xbp-18h]
  int v131; // [xsp+28h] [xbp-18h]
  unsigned int v132; // [xsp+30h] [xbp-10h]
  unsigned int v133; // [xsp+30h] [xbp-10h]
  int v134; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v135; // [xsp+38h] [xbp-8h]

  v135 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_acquire_vfe_out",
      2080,
      "Invalid Param");
    result = 4294967274LL;
    goto LABEL_265;
  }
  v3 = *(_DWORD **)(a2 + 56);
  v5 = (unsigned int)v3[1];
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_acquire_vfe_out",
      2088,
      "Acquiring resource type 0x%x",
      *v3);
    v3 = *(_DWORD **)(a2 + 56);
  }
  v6 = *v3 - 12288;
  v7 = 0;
  v8 = 16;
  v9 = 10;
  v10 = 5;
  v11 = 4;
  switch ( v6 )
  {
    case 0:
      goto LABEL_49;
    case 1:
      goto LABEL_31;
    case 2:
      v10 = 6;
      goto LABEL_31;
    case 3:
      v7 = 7;
      if ( (unsigned int)v5 > 0x31 )
        goto LABEL_243;
      v15 = 16896000;
      goto LABEL_45;
    case 4:
      v7 = 8;
      if ( (unsigned int)v5 > 0x31 )
        goto LABEL_243;
      if ( ((1LL << v5) & 0x2000380005000LL) != 0 )
      {
        v13 = 0;
        v14 = 2;
        goto LABEL_52;
      }
      if ( v5 != 45 )
        goto LABEL_243;
LABEL_47:
      v13 = 1;
      v14 = 1;
      goto LABEL_52;
    case 5:
      v7 = 9;
      if ( (unsigned int)v5 > 0x31 )
        goto LABEL_243;
      v15 = 118784;
      goto LABEL_45;
    case 6:
      goto LABEL_41;
    case 7:
      v7 = 1;
      goto LABEL_41;
    case 8:
      v7 = 2;
      goto LABEL_41;
    case 9:
      v7 = 3;
LABEL_41:
      if ( (unsigned int)v5 > 0x31 )
        goto LABEL_243;
      v16 = 1LL << v5;
      v15 = 2115490044;
      goto LABEL_46;
    case 10:
      goto LABEL_25;
    case 11:
      v9 = 11;
      if ( (_DWORD)v5 != 19 )
        goto LABEL_10;
      goto LABEL_26;
    case 12:
      v9 = 12;
      if ( (_DWORD)v5 != 19 )
        goto LABEL_10;
      goto LABEL_26;
    case 13:
      v9 = 13;
      if ( (_DWORD)v5 != 19 )
        goto LABEL_10;
      goto LABEL_26;
    case 14:
      v9 = 14;
      if ( (_DWORD)v5 != 19 )
        goto LABEL_10;
      goto LABEL_26;
    case 15:
      v9 = 15;
      if ( (_DWORD)v5 != 19 )
        goto LABEL_10;
      goto LABEL_26;
    case 16:
      goto LABEL_37;
    case 17:
      v9 = 17;
LABEL_25:
      if ( (_DWORD)v5 != 19 )
      {
LABEL_10:
        v7 = v9;
        goto LABEL_243;
      }
LABEL_26:
      v13 = 1;
      v7 = v9;
      v14 = 1;
      goto LABEL_52;
    case 18:
      v8 = 18;
LABEL_37:
      if ( (_DWORD)v5 == 17 )
      {
        v13 = 1;
        v7 = v8;
        v14 = 1;
        goto LABEL_52;
      }
      v7 = v8;
      goto LABEL_243;
    case 19:
      v11 = 19;
LABEL_49:
      if ( (unsigned int)v5 <= 0x31 && ((1LL << v5) & 0x201E380005004LL) != 0 )
      {
        v13 = 0;
        v14 = 2;
        v7 = v11;
        goto LABEL_52;
      }
      v7 = v11;
      goto LABEL_243;
    case 20:
      v10 = 20;
      goto LABEL_31;
    case 21:
      v10 = 21;
LABEL_31:
      if ( (unsigned int)(v5 - 35) >= 2 )
      {
        v7 = v10;
LABEL_243:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_get_num_wm",
          635,
          "Unsupported format %u for resource_type %u",
          v5,
          v7);
        result = 4294967274LL;
        goto LABEL_265;
      }
      v13 = 1;
      v7 = v10;
      v14 = 1;
LABEL_52:
      v17 = a1 + 152LL * v7;
      v18 = v17 + 39104;
      if ( *(_DWORD *)(v17 + 39112) != 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_acquire_vfe_out",
          2102,
          "Resource not available: Res_id %d state:%d",
          v7);
        result = 4294967280LL;
        goto LABEL_265;
      }
      v19 = *(_QWORD *)(v17 + 39128);
      *(_QWORD *)(*(_QWORD *)(v19 + 8) + 33600LL) = *(_QWORD *)(a2 + 24);
      *(_BYTE *)(*(_QWORD *)(v19 + 8) + 33610LL) = *(_BYTE *)(a2 + 96);
      v20 = *(_DWORD *)v19;
      *(_QWORD *)(v19 + 104) = *(_QWORD *)(a2 + 16);
      v21 = *(_DWORD *)(*(_QWORD *)(a2 + 56) + 24LL);
      mutex_lock(*(_QWORD *)(v19 + 8) + 33536LL);
      if ( v20 <= 0x15 && ((0x3801F7u >> v20) & 1) != 0 )
      {
        v22 = *(_QWORD *)(v19 + 8);
        if ( *(_DWORD *)(v22 + 33588) )
        {
          if ( v21 != *(_DWORD *)(v22 + 33584) )
          {
            if ( (unsigned int)__ratelimit(&cam_vfe_bus_acquire_vfe_out__rs, "cam_vfe_bus_acquire_vfe_out") )
              v35 = 3;
            else
              v35 = 2;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
              v35,
              8,
              1,
              "cam_vfe_bus_acquire_vfe_out",
              2128,
              "Mismatch: Acquire mode[%d], drvr mode[%d]",
              *(unsigned int *)(*(_QWORD *)(v19 + 8) + 33584LL),
              v21);
            mutex_unlock(*(_QWORD *)(v19 + 8) + 33536LL);
            result = 4294967274LL;
            goto LABEL_265;
          }
          *(_DWORD *)(v19 + 96) = v21;
        }
        else
        {
          *(_DWORD *)(v19 + 96) = v21;
          *(_DWORD *)(v22 + 33584) = v21;
          v22 = *(_QWORD *)(v19 + 8);
        }
        ++*(_DWORD *)(v22 + 33588);
      }
      mutex_unlock(*(_QWORD *)(v19 + 8) + 33536LL);
      v23 = (_QWORD *)(a1 + 42600);
      v124 = v18;
      *(_QWORD *)(a1 + 42656) = *(_QWORD *)(a2 + 8);
      *(_DWORD *)(v19 + 16) = v14;
      *(_DWORD *)(v18 + 4) = **(_DWORD **)(a2 + 56);
      *(_QWORD *)(v18 + 56) = *(_QWORD *)(a2 + 8);
      v24 = *(_QWORD *)(a2 + 88);
      *(_QWORD *)(v18 + 48) = v24;
      *(_QWORD *)(v19 + 88) = v24;
      if ( (v13 & 1) != 0 )
      {
        v25 = *(_DWORD *)(a2 + 68);
        v26 = *(_QWORD *)(a2 + 56);
        v27 = &unk_393000;
        v28 = &unk_393000;
        if ( !v25 )
        {
          if ( (unsigned int)(*(_DWORD *)(v26 + 16) - 1) > 4 )
            goto LABEL_125;
          v25 = 0;
        }
      }
      else
      {
        v26 = *(_QWORD *)(a2 + 56);
        v25 = *(_DWORD *)(a2 + 68);
        v27 = &unk_393000;
        v28 = &unk_393000;
      }
      v29 = *(_DWORD *)(v26 + 16);
      v30 = *(_QWORD *)(a2 + 8);
      v31 = *(_DWORD *)(a2 + 64);
      v32 = *(_DWORD *)(a2 + 76);
      v33 = *(_DWORD *)(a2 + 80);
      if ( v29 <= 2 )
      {
        if ( !v29 )
        {
          v34 = 4294967274LL;
          goto LABEL_95;
        }
        if ( v29 != 1 )
        {
          if ( v29 == 2 )
          {
            v34 = 1;
            goto LABEL_87;
          }
LABEL_83:
          v34 = 4294967274LL;
          goto LABEL_87;
        }
        v34 = 0;
      }
      else
      {
        if ( v29 <= 4 )
        {
          if ( v29 == 3 )
            v34 = 2;
          else
            v34 = 3;
          goto LABEL_87;
        }
        if ( v29 != 5 )
        {
          if ( v29 == 6 )
          {
            v34 = 5;
            goto LABEL_87;
          }
          goto LABEL_83;
        }
        v34 = 4;
      }
LABEL_87:
      for ( i = *(int **)(a1 + 42632); ; i = *(int **)i )
      {
        if ( i == (int *)(a1 + 42632) )
          goto LABEL_95;
        v37 = *((_DWORD **)i - 1);
        if ( v37[6] == (_DWORD)v34 && v37[7] == v31 )
          break;
      }
      v38 = i - 8;
      if ( i != &dword_20 )
      {
        if ( *(i - 6) != 4 )
          goto LABEL_121;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_acquire_comp_grp",
          1687,
          "Invalid State %d Comp Grp %u",
          4,
          *v37);
        v39 = -16;
LABEL_227:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_acquire_vfe_out",
          2164,
          "VFE%d Comp_Grp acquire fail for Out %d rc=%d",
          **(_DWORD **)(v19 + 8),
          v7,
          v39);
        result = v39;
        goto LABEL_265;
      }
LABEL_95:
      v40 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 3);
      if ( !v25 )
      {
        if ( v40 )
        {
          v115 = v34;
          v123 = *(_DWORD *)(a2 + 76);
          v116 = *(_QWORD *)(a2 + 8);
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_acquire_comp_grp",
            1652,
            "Acquire comp group");
          v32 = v123;
          v30 = v116;
          v23 = (_QWORD *)(a1 + 42600);
          v28 = &unk_393000;
          v27 = &unk_393000;
          v34 = v115;
        }
        v49 = (_QWORD *)*v23;
        if ( (_QWORD *)*v23 != v23 )
        {
          v37 = (_DWORD *)*(v49 - 1);
          v38 = (int *)(v49 - 4);
          goto LABEL_114;
        }
        v89 = 1654;
LABEL_226:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_acquire_comp_grp",
          v89,
          "No Free Composite Group",
          v34);
        v39 = -19;
        goto LABEL_227;
      }
      v132 = v14;
      if ( v40 )
      {
        v111 = v34;
        v112 = *(_DWORD *)(a2 + 76);
        v113 = *(_QWORD *)(a2 + 8);
        v114 = *(_DWORD *)(a2 + 80);
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_acquire_comp_grp",
          1631,
          "Acquire dual comp group");
        v33 = v114;
        v30 = v113;
        v32 = v112;
        v23 = (_QWORD *)(a1 + 42600);
        v34 = v111;
      }
      v42 = (int **)(v23 + 2);
      v41 = (int *)v23[2];
      if ( v41 == (int *)(v23 + 2) )
      {
        v89 = 1633;
        goto LABEL_226;
      }
      if ( (unsigned int)v34 >= 6 )
        v43 = 12;
      else
        v43 = v34 + 6;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v129 = v34;
        v44 = v23;
        v45 = v32;
        v125 = v30;
        v46 = v33;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_get_free_dual_comp_grp",
          1585,
          "dual_comp_grp_idx :%d",
          v43);
        v30 = v125;
        v32 = v45;
        v34 = v129;
        v41 = *v42;
        v33 = v46;
        v23 = v44;
      }
      do
      {
        if ( v41 == (int *)v42 )
        {
          v39 = -22;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_acquire_comp_grp",
            1641,
            "failed to acquire dual comp grp for :%d rc :%d",
            v34,
            -22);
          goto LABEL_227;
        }
        v47 = v41;
        v41 = *(int **)v41;
        v48 = *((_DWORD **)v47 - 1);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v130 = v34;
          v118 = v23;
          v119 = v33;
          v121 = v32;
          v126 = v30;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_get_free_dual_comp_grp",
            1591,
            "current grp type : %d expected :%d",
            *v48,
            v43);
          v33 = v119;
          v32 = v121;
          v30 = v126;
          v23 = v118;
          v34 = v130;
        }
      }
      while ( v43 != *v48 );
      v90 = *((int ***)v47 + 1);
      v38 = v47 - 8;
      if ( *v90 == v47 && (v91 = *(_QWORD *)v47, *(int **)(*(_QWORD *)v47 + 8LL) == v47) )
      {
        *(_QWORD *)(v91 + 8) = v90;
        *v90 = (int *)v91;
      }
      else
      {
        _list_del_entry_valid_or_report(v47);
        v33 = v104;
        v30 = v105;
        v34 = v106;
      }
      v14 = v132;
      *(_QWORD *)v47 = v47;
      *((_QWORD *)v47 + 1) = v47;
      if ( v47 == &dword_20 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_acquire_comp_grp",
          1641,
          "failed to acquire dual comp grp for :%d rc :%d",
          v34,
          0);
        goto LABEL_125;
      }
      v92 = *((_QWORD *)v47 - 2);
      v37 = *((_DWORD **)v47 - 1);
      v134 = 0;
      v93 = *(_DWORD *)(v92 + 4);
      v37[10] = 0;
      if ( v93 == v33 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver2_get_intra_client_mask",
          332,
          "Invalid params. Same core as Master and Slave",
          v34);
        v39 = -22;
        goto LABEL_227;
      }
      v120 = v33;
      v122 = v32;
      v96 = v23;
      v128 = v30;
      v131 = v34;
      cpas_hw_version = cam_cpas_get_cpas_hw_version(&v134);
      v28 = &unk_393000;
      v27 = &unk_393000;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v133 = cpas_hw_version;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver2_get_intra_client_mask",
          338,
          "CPAS VERSION %d",
          v134);
        cpas_hw_version = v133;
        v28 = &unk_393000;
        v27 = &unk_393000;
      }
      v30 = v128;
      v23 = v96;
      v32 = v122;
      if ( v134 == 1507584 )
        v98 = 3;
      else
        v98 = 1;
      if ( v93 == 2 )
      {
        LODWORD(v34) = v131;
        if ( v120 < 2 )
          goto LABEL_247;
        v99 = "Invalid value for slave core %u";
        v100 = 385;
LABEL_254:
        v101 = v120;
        goto LABEL_255;
      }
      LODWORD(v34) = v131;
      if ( v93 == 1 )
      {
        if ( (v120 | 2) == 2 )
          goto LABEL_247;
        v99 = "Invalid value for slave core %u";
        v100 = 372;
        goto LABEL_254;
      }
      if ( v93 )
      {
        v99 = "Invalid value for master core %u";
        v100 = 392;
        v101 = v93;
LABEL_255:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver2_get_intra_client_mask",
          v100,
          v99,
          v101);
        v39 = -22;
        goto LABEL_227;
      }
      if ( v120 - 1 >= 2 )
      {
        v99 = "Invalid value for slave core %u";
        v100 = 359;
        goto LABEL_254;
      }
LABEL_247:
      v39 = cpas_hw_version;
      v37[10] = v98;
      if ( cpas_hw_version )
        goto LABEL_227;
LABEL_114:
      v50 = *((int ***)v38 + 5);
      v51 = v38 + 8;
      if ( *v50 == v38 + 8 && (v52 = *v51, *(_QWORD **)(*v51 + 8LL) == v51) )
      {
        *(_QWORD *)(v52 + 8) = v50;
        *v50 = (int *)v52;
      }
      else
      {
        _list_del_entry_valid_or_report(v38 + 8);
        v30 = v102;
        LODWORD(v34) = v103;
      }
      *((_QWORD *)v38 + 7) = v30;
      v53 = v23 + 4;
      *((_QWORD *)v38 + 4) = 0xDEAD000000000100LL;
      *((_QWORD *)v38 + 5) = 0xDEAD000000000122LL;
      v38[2] = 2;
      v37[7] = v31;
      v37[8] = v32;
      v37[6] = v34;
      v37[11] = 0;
      v37[12] = v32 == 0;
      v54 = (_QWORD *)v23[5];
      if ( v51 == v23 + 4 || v54 == v51 || (_QWORD *)*v54 != v53 )
      {
        _list_add_valid_or_report(v51);
        v55 = *(_QWORD *)(v117 + 3664);
        if ( (v55 & 8) != 0 )
          goto LABEL_122;
      }
      else
      {
        v23[5] = v51;
        *((_QWORD *)v38 + 4) = v53;
        *((_QWORD *)v38 + 5) = v54;
        *v54 = v51;
LABEL_121:
        v55 = v28[458];
        if ( (v55 & 8) != 0 )
        {
LABEL_122:
          if ( !v27[919] )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v55 & 8,
              4,
              "cam_vfe_bus_acquire_comp_grp",
              1692,
              "Comp Grp type %u",
              *v37);
        }
      }
      ++v37[13];
      *(_QWORD *)(v19 + 40) = v38;
LABEL_125:
      v56 = 0;
      v127 = v14;
      while ( 2 )
      {
        v57 = v19 + 8 * v56;
        v58 = *(_QWORD *)(a2 + 8);
        v59 = *(_DWORD **)(a2 + 56);
        v60 = *(_DWORD *)(a2 + 68);
        *(_QWORD *)(v57 + 24) = 0;
        wm_idx = cam_vfe_bus_get_wm_idx(v7);
        if ( wm_idx >= *(_DWORD *)(a1 + 33616) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_acquire_wm",
            935,
            "Unsupported VFE out %d plane %d",
            v7,
            v56);
          goto LABEL_261;
        }
        v62 = a1 + 33632 + 152LL * wm_idx;
        v63 = *(_DWORD *)(v62 + 8);
        if ( v63 != 1 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_acquire_wm",
            942,
            "WM res not available state:%d",
            v63);
          v94 = -114;
          goto LABEL_262;
        }
        *(_QWORD *)(v62 + 56) = v58;
        v64 = *(unsigned int **)(v62 + 24);
        *(_DWORD *)(v62 + 8) = 2;
        v65 = v59[1];
        v64[11] = v65;
        v66 = 5;
        switch ( v65 )
        {
          case 1u:
          case 2u:
          case 3u:
          case 4u:
          case 5u:
          case 6u:
          case 7u:
          case 0xDu:
          case 0x14u:
          case 0x23u:
          case 0x24u:
            v66 = 0;
            break;
          case 0xCu:
            v66 = 1;
            break;
          case 0xEu:
          case 0x31u:
            v66 = 2;
            break;
          case 0xFu:
            v66 = 3;
            break;
          case 0x10u:
            v66 = 4;
            break;
          case 0x11u:
            break;
          case 0x12u:
            v66 = 9;
            break;
          case 0x13u:
            v66 = 10;
            break;
          case 0x18u:
            v66 = 8;
            break;
          case 0x1Fu:
            if ( wm_idx > 0x15 || ((1 << wm_idx) & 0x200050) == 0 )
              goto LABEL_136;
            goto LABEL_135;
          case 0x20u:
          case 0x25u:
          case 0x26u:
          case 0x2Du:
LABEL_136:
            v66 = 14;
            break;
          case 0x21u:
          case 0x27u:
            v66 = 11;
            break;
          default:
LABEL_135:
            v66 = 15;
            break;
        }
        v64[12] = v66;
        v64[8] = v59[2];
        v64[9] = v59[3];
        v64[33] = v59[2];
        v67 = debug_mdl;
        v68 = v59[3];
        v64[29] = v60;
        v64[7] = 0;
        v64[34] = v68;
        if ( (v67 & 8) != 0 && !debug_priority )
        {
          v86 = wm_idx;
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            v67 & 8,
            4,
            "cam_vfe_bus_acquire_wm",
            961,
            "WM %d width %d height %d",
            *v64);
          LOBYTE(wm_idx) = v86;
        }
        v69 = *v64;
        if ( *v64 <= 2 )
        {
          v70 = v64[11];
          if ( (int)v70 > 13 )
          {
            if ( (int)v70 >= 19 )
            {
              if ( (_DWORD)v70 == 19 )
              {
                v64[28] = 1;
                v64[12] = 10;
                goto LABEL_188;
              }
              if ( (_DWORD)v70 != 49 && (_DWORD)v70 != 20 )
              {
LABEL_257:
                v107 = "Unsupported RDI format %d";
                v108 = 1004;
                goto LABEL_260;
              }
            }
          }
          else if ( (unsigned int)(v70 - 1) >= 7 )
          {
            if ( (_DWORD)v70 != 12 )
              goto LABEL_257;
            v71 = v64[8];
            v72 = 1;
            v64[28] = 1;
            v73 = 2 * v71;
LABEL_204:
            v64[12] = v72;
            v64[8] = v73;
            v64[10] = v73;
            goto LABEL_188;
          }
          v64[12] = 0;
          *((_QWORD *)v64 + 4) = 65281;
          v64[10] = 65281;
LABEL_156:
          v64[28] = 3;
          goto LABEL_188;
        }
        if ( v69 > 0x15 || ((1 << v69) & 0x300198) == 0 )
        {
          if ( v69 - 11 <= 8 )
          {
            *((_QWORD *)v64 + 4) = 0;
            v64[10] = 1;
            goto LABEL_156;
          }
          if ( v69 == 9 )
          {
            v78 = v64[8];
            v79 = v64[12];
            v64[28] = 1;
            v73 = 2 * v78;
            v72 = v79 | 0x10;
            goto LABEL_204;
          }
          if ( v69 == 10 )
          {
            *((_QWORD *)v64 + 4) = 0;
            v64[10] = 1;
            v64[28] = 3;
            if ( v7 == 9 )
              v64[12] |= 0x10u;
          }
          else
          {
            v80 = v64[8];
            v81 = v64[9];
            v64[28] = 1;
            v82 = 4 * v80;
            v83 = debug_mdl;
            v64[8] = v82;
            v64[9] = v81 >> 1;
            if ( (v83 & 8) != 0 && !debug_priority )
            {
              v88 = wm_idx;
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v83 & 8,
                4,
                "cam_vfe_bus_acquire_wm",
                1138,
                "before width %d",
                v82);
              v82 = v64[8];
              LOBYTE(wm_idx) = v88;
            }
            v84 = (v82 + 15) & 0xFFFFFFF0;
            if ( v84 != v82 )
            {
              v85 = wm_idx;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                2,
                "cam_vfe_bus_acquire_wm",
                1143,
                "Override width %u with expected %u",
                v82,
                v84);
              LOBYTE(wm_idx) = v85;
              v64[8] = v84;
            }
          }
LABEL_188:
          *(_QWORD *)(v57 + 24) = v62;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v87 = wm_idx;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_acquire_wm",
              1152,
              "WM %d: processed width %d, processed  height %d",
              *v64,
              v64[8],
              v64[9]);
            LOBYTE(wm_idx) = v87;
            v77 = *(_QWORD *)(v19 + 40);
            if ( !v77 )
            {
LABEL_126:
              if ( v127 == ++v56 )
              {
                result = 0;
                *(_DWORD *)(v124 + 8) = 2;
                v95 = debug_mdl;
                *(_QWORD *)(a2 + 48) = v124;
                if ( (v95 & 8) != 0 && !debug_priority )
                {
                  ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    v95 & 8,
                    4,
                    "cam_vfe_bus_acquire_vfe_out",
                    2195,
                    "Acquire successful");
                  result = 0;
                }
                goto LABEL_265;
              }
              continue;
            }
          }
          else
          {
            v77 = *(_QWORD *)(v19 + 40);
            if ( !v77 )
              goto LABEL_126;
          }
          *(_DWORD *)(*(_QWORD *)(v77 + 24) + 44LL) |= 1 << wm_idx;
          goto LABEL_126;
        }
        break;
      }
      v70 = v64[11];
      if ( (int)v70 <= 37 )
      {
        if ( (int)v70 > 32 )
        {
          if ( (_DWORD)v70 != 33 )
          {
            if ( (_DWORD)v70 != 37 )
            {
LABEL_256:
              v107 = "Invalid format %d";
              v108 = 1105;
              goto LABEL_260;
            }
            v64[14] = 1;
            goto LABEL_172;
          }
          v64[8] = 12 * ((v64[8] + 2) / 3) / 3;
          if ( !(_DWORD)v56 )
            goto LABEL_187;
          if ( (_DWORD)v56 != 1 )
          {
            v107 = "Invalid plane %d";
            v108 = 1072;
            goto LABEL_259;
          }
        }
        else
        {
          if ( (unsigned int)(v70 - 31) >= 2 )
          {
            if ( (_DWORD)v70 != 14 )
              goto LABEL_256;
            if ( (_DWORD)v56 )
            {
              if ( (_DWORD)v56 != 1 )
              {
                v107 = "Invalid plane %d";
                v108 = 1098;
                goto LABEL_259;
              }
LABEL_167:
              v64[9] >>= 1;
            }
LABEL_168:
            v64[8] *= 2;
LABEL_187:
            v64[28] = 1;
            goto LABEL_188;
          }
LABEL_172:
          if ( !(_DWORD)v56 )
            goto LABEL_187;
          if ( (_DWORD)v56 != 1 )
          {
            v107 = "Invalid plane %d";
            v108 = 1043;
            goto LABEL_259;
          }
        }
LABEL_174:
        v75 = v64[9];
        v64[28] = 1;
        v64[9] = v75 >> 1;
        goto LABEL_188;
      }
      if ( (int)v70 <= 44 )
      {
        if ( (_DWORD)v70 == 38 )
        {
          v76 = v64[8];
          v64[14] = 1;
          v64[8] = (v76 + 63) & 0xFFFFFFC0;
          if ( !(_DWORD)v56 )
            goto LABEL_187;
          if ( (_DWORD)v56 != 1 )
          {
            v107 = "Invalid plane %d";
            v108 = 1025;
            goto LABEL_259;
          }
        }
        else
        {
          if ( (_DWORD)v70 != 39 )
            goto LABEL_256;
          v74 = v64[8];
          v64[14] = 1;
          v64[8] = 192 * ((v74 + 47) / 0x30) / 3;
          if ( !(_DWORD)v56 )
            goto LABEL_187;
          if ( (_DWORD)v56 != 1 )
          {
            v107 = "Invalid plane %d";
            v108 = 1058;
            goto LABEL_259;
          }
        }
        goto LABEL_174;
      }
      if ( (_DWORD)v70 == 45 )
        goto LABEL_172;
      if ( (_DWORD)v70 != 49 )
        goto LABEL_256;
      v64[12] |= 0x10u;
      if ( !(_DWORD)v56 )
        goto LABEL_168;
      if ( (_DWORD)v56 == 1 )
        goto LABEL_167;
      v107 = "Invalid plane %d";
      v108 = 1085;
LABEL_259:
      v70 = (unsigned int)v56;
LABEL_260:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_acquire_wm",
        v108,
        v107,
        v70);
LABEL_261:
      v94 = -22;
LABEL_262:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_acquire_vfe_out",
        2183,
        "VFE%d WM acquire failed for Out %d rc=%d",
        **(_DWORD **)(v19 + 8),
        v7,
        v94);
      if ( (_DWORD)v56 )
      {
        v109 = *(_QWORD *)(v57 + 16);
        v110 = *(_QWORD *)(v109 + 24);
        *(_WORD *)(v110 + 24) = 0;
        *(_QWORD *)(v110 + 28) = 0;
        *(_QWORD *)(v110 + 36) = 0;
        *(_QWORD *)(v110 + 44) = 0;
        *(_QWORD *)(v110 + 52) = 0;
        *(_QWORD *)(v110 + 64) = 0;
        *(_QWORD *)(v110 + 72) = 0;
        *(_QWORD *)(v110 + 80) = 0;
        *(_QWORD *)(v110 + 88) = 0;
        *(_QWORD *)(v110 + 96) = 0;
        *(_QWORD *)(v110 + 104) = 0;
        *(_QWORD *)(v110 + 112) = 0;
        *(_QWORD *)(v110 + 120) = 0;
        *(_DWORD *)(v110 + 128) = 0;
        *(_QWORD *)(v109 + 56) = 0;
        *(_DWORD *)(v109 + 8) = 1;
      }
      cam_vfe_bus_release_comp_grp(a1, *(_QWORD *)(v19 + 40));
      result = v94;
LABEL_265:
      _ReadStatusReg(SP_EL0);
      return result;
    case 22:
      v7 = 22;
      if ( (unsigned int)v5 <= 0x31 )
      {
        v15 = 778240;
LABEL_45:
        v16 = 1LL << v5;
LABEL_46:
        if ( (v16 & (v15 & 0xFFFFFFFFFFFFLL | 0x2000000000000LL)) != 0 )
          goto LABEL_47;
      }
      goto LABEL_243;
    default:
      result = 4294967277LL;
      goto LABEL_265;
  }
}
