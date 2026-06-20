__int64 __fastcall sde_encoder_phys_vid_setup_timing_engine(_QWORD *a1)
{
  __int64 v2; // x8
  int v3; // w22
  __int64 result; // x0
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x24
  __int64 v18; // x23
  int v19; // w4
  int v20; // w5
  __int64 v21; // x8
  int v22; // w6
  __int64 v23; // x10
  int v24; // w7
  int v25; // w9
  int v26; // w10
  int v27; // w11
  int v28; // w4
  int v29; // w5
  int panel_vfp; // w0
  char v31; // w15
  int v32; // w8
  int v33; // w10
  __int64 v34; // x9
  int v35; // w10
  __int64 v36; // x10
  char v37; // w12
  unsigned int v38; // w11
  __int64 v39; // x10
  unsigned int v40; // w12
  unsigned int v41; // w13
  int v42; // w11
  unsigned int v43; // w8
  signed __int64 v44; // x9
  unsigned __int64 v45; // x13
  unsigned __int64 v46; // x8
  int v47; // w11
  unsigned __int64 v48; // x13
  __int64 v49; // x15
  bool v50; // cf
  __int64 v51; // x10
  char v52; // w12
  signed __int64 v53; // x8
  __int64 v54; // x8
  char v55; // w9
  __int64 v56; // x8
  unsigned __int64 v57; // x9
  __int64 v58; // x9
  __int64 v59; // x8
  __int64 v60; // x10
  __int64 v61; // x8
  __int64 v62; // x9
  __int64 v63; // x9
  __int64 v64; // x11
  __int64 v65; // x8
  __int64 v66; // x9
  __int64 v67; // x10
  int v68; // w4
  __int64 v69; // x8
  int v70; // w5
  __int64 sde_format_ext; // x21
  int v72; // w4
  __int64 v73; // x8
  int v74; // w5
  __int64 v75; // x0
  __int64 v76; // x3
  __int64 v77; // x20
  __int64 v78; // x0
  void (__fastcall *v79)(__int64, __int64 *, __int64, __int64, bool); // x9
  __int64 v80; // x1
  __int64 v81; // x2
  __int64 v82; // x3
  unsigned __int16 *v83; // x4
  __int64 v84; // x0
  void (*v85)(void); // x8
  unsigned int disp_op; // w0
  __int64 v87; // x22
  __int64 v88; // x20
  int v89; // w6
  int v90; // w12
  int v91; // w9
  int v92; // w8
  unsigned int v93; // w11
  int v94; // w8
  int v95; // w26
  int v96; // w9
  int v97; // w20
  int v98; // w4
  __int64 v99; // x8
  int v100; // w5
  __int64 v101; // x21
  __int64 v102; // x0
  void (__fastcall *v103)(__int64, __int64 *); // x9
  void (*v104)(void); // x8
  void (*v105)(void); // x8
  __int64 v106; // x8
  __int64 v107; // x20
  __int64 v108; // x21
  int num_lines; // w0
  int v110; // w8
  __int64 v111; // x0
  void (*v112)(void); // x8
  __int64 (*v113)(void); // x8
  __int64 v114; // x20
  __int64 (*v115)(void); // x8
  _DWORD *v116; // x8
  __int64 v117; // x0
  __int64 v118; // x2
  __int64 v119; // [xsp+28h] [xbp-E8h] BYREF
  __int64 v120; // [xsp+30h] [xbp-E0h] BYREF
  __int64 v121; // [xsp+38h] [xbp-D8h]
  __int64 v122; // [xsp+40h] [xbp-D0h]
  __int64 v123; // [xsp+48h] [xbp-C8h]
  __int64 v124; // [xsp+50h] [xbp-C0h]
  __int64 v125; // [xsp+58h] [xbp-B8h]
  __int64 v126; // [xsp+60h] [xbp-B0h]
  __int64 v127; // [xsp+68h] [xbp-A8h]
  __int64 v128; // [xsp+70h] [xbp-A0h]
  __int64 v129; // [xsp+78h] [xbp-98h]
  __int64 v130; // [xsp+80h] [xbp-90h]
  __int64 v131; // [xsp+88h] [xbp-88h] BYREF
  __int64 v132; // [xsp+90h] [xbp-80h] BYREF
  __int64 v133; // [xsp+98h] [xbp-78h]
  __int64 v134; // [xsp+A0h] [xbp-70h]
  __int64 v135; // [xsp+A8h] [xbp-68h]
  __int64 v136; // [xsp+B0h] [xbp-60h]
  __int64 v137; // [xsp+B8h] [xbp-58h]
  __int64 v138; // [xsp+C0h] [xbp-50h]
  __int64 v139; // [xsp+C8h] [xbp-48h]
  __int64 v140; // [xsp+D0h] [xbp-40h]
  __int64 v141; // [xsp+D8h] [xbp-38h]
  __int64 v142; // [xsp+E0h] [xbp-30h]
  __int64 v143; // [xsp+E8h] [xbp-28h]
  __int64 v144; // [xsp+F0h] [xbp-20h]
  __int64 v145; // [xsp+F8h] [xbp-18h]
  __int64 v146; // [xsp+100h] [xbp-10h]
  __int64 v147; // [xsp+108h] [xbp-8h]

  v147 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[1];
  v129 = 0;
  v130 = 0;
  v127 = 0;
  v128 = 0;
  v125 = 0;
  v126 = 0;
  v123 = 0;
  v124 = 0;
  v121 = 0;
  v122 = 0;
  HIDWORD(v119) = 0;
  v120 = 0;
  if ( v2 )
    v3 = *(_DWORD *)(v2 + 4676);
  else
    v3 = 0;
  v145 = 0;
  v146 = 0;
  v143 = 0;
  v144 = 0;
  v141 = 0;
  v142 = 0;
  v139 = 0;
  v140 = 0;
  v137 = 0;
  v138 = 0;
  v135 = 0;
  v136 = 0;
  v133 = 0;
  v134 = 0;
  v132 = 0;
  if ( !a1 || !a1[64] || !a1[52] || !v2 || !a1[53] )
  {
    result = printk(&unk_2382D0, "sde_encoder_phys_vid_setup_timing_engine");
    goto LABEL_166;
  }
  result = sde_encoder_get_disp_op(*a1);
  v5 = a1[78];
  v6 = a1[79];
  v144 = a1[77];
  v145 = v5;
  v7 = a1[73];
  v8 = a1[74];
  v146 = v6;
  v9 = a1[76];
  v140 = v7;
  v141 = v8;
  v10 = a1[69];
  v142 = a1[75];
  v143 = v9;
  v11 = a1[70];
  v12 = a1[72];
  v136 = v10;
  v137 = v11;
  v13 = a1[65];
  v138 = a1[71];
  v139 = v12;
  v14 = a1[66];
  v15 = a1[68];
  v132 = v13;
  v133 = v14;
  v134 = a1[67];
  v135 = v15;
  if ( (unsigned int)result >= 3 )
    goto LABEL_168;
  v16 = a1[53];
  v17 = (unsigned int)result;
  if ( *(_QWORD *)(v16 + 8LL * (unsigned int)result + 80) )
  {
    v18 = *a1;
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_21;
    if ( v18 )
    {
      v19 = *(_DWORD *)(v18 + 24);
      if ( v16 )
      {
LABEL_14:
        v20 = *(_DWORD *)(v16 + 32) - 1;
LABEL_20:
        _drm_dev_dbg(0, 0, 0, "enc%d intf%d enabling mode:\n", v19, v20);
LABEL_21:
        drm_mode_debug_printmodeline(&v132);
        v21 = a1[53];
        v22 = *((_DWORD *)a1 + 166);
        if ( v22 )
        {
          v23 = *a1;
          if ( *a1 && *(_DWORD *)(v23 + 196) == 1 && *(_BYTE *)(v23 + 4936) == 1 && (*(_BYTE *)(v21 + 77) & 1) == 0 )
            goto LABEL_35;
        }
        else if ( !*(_BYTE *)(v21 + 77) )
        {
          goto LABEL_35;
        }
        v24 = WORD2(v132) >> 1;
        v25 = WORD1(v133) >> 1;
        v26 = HIWORD(v132) >> 1;
        v27 = (unsigned __int16)v133 >> 1;
        WORD2(v132) >>= 1;
        WORD1(v133) >>= 1;
        HIWORD(v132) >>= 1;
        LOWORD(v133) = (unsigned __int16)v133 >> 1;
        if ( (_drm_debug & 4) != 0 )
        {
          if ( *a1 )
          {
            v28 = *(_DWORD *)(*a1 + 24LL);
            if ( v21 )
            {
LABEL_31:
              v29 = *(_DWORD *)(v21 + 32) - 1;
LABEL_34:
              _drm_dev_dbg(
                0,
                0,
                0,
                "enc%d intf%d split_role %d, halve horizontal %d %d %d %d\n",
                v28,
                v29,
                v22,
                v24,
                v25,
                v26,
                v27);
              goto LABEL_35;
            }
          }
          else
          {
            v28 = -1;
            if ( v21 )
              goto LABEL_31;
          }
          v29 = -1;
          goto LABEL_34;
        }
LABEL_35:
        panel_vfp = *((_DWORD *)a1 + 574);
        if ( !panel_vfp )
        {
          panel_vfp = sde_connector_get_panel_vfp(a1[1], &v132);
          *((_DWORD *)a1 + 574) = panel_vfp;
          if ( panel_vfp <= 0 )
          {
            panel_vfp = (unsigned __int16)v134 - HIWORD(v133);
            *((_DWORD *)a1 + 574) = panel_vfp;
          }
        }
        v129 = 0;
        v130 = 0;
        v127 = 0;
        v128 = 0;
        v125 = 0;
        v126 = 0;
        v123 = 0;
        v124 = 0;
        v121 = 0;
        v122 = 0;
        v120 = 0;
        if ( WORD1(v133) < (unsigned int)(unsigned __int16)v133
          || HIWORD(v132) < (unsigned int)WORD2(v132)
          || WORD2(v134) < (unsigned int)WORD1(v134)
          || WORD1(v134) < (unsigned int)(unsigned __int16)v134
          || (unsigned __int16)v133 < (unsigned int)HIWORD(v132)
          || (unsigned __int16)v134 < (unsigned int)HIWORD(v133) )
        {
          printk(&unk_249412, "drm_mode_to_intf_timing_params");
          result = printk(&unk_235062, "drm_mode_to_intf_timing_params");
          goto LABEL_79;
        }
        LODWORD(v122) = WORD1(v133) - (unsigned __int16)v133;
        HIDWORD(v122) = HIWORD(v132) - WORD2(v132);
        v31 = *((_BYTE *)a1 + 816);
        LODWORD(v120) = WORD2(v132);
        HIDWORD(v120) = HIWORD(v133);
        BYTE5(v129) = v31;
        LODWORD(v121) = WORD2(v132);
        HIDWORD(v121) = HIWORD(v133);
        LODWORD(v125) = ((unsigned int)v135 >> 1) & 1;
        HIDWORD(v125) = ((unsigned int)v135 >> 3) & 1;
        LODWORD(v123) = WORD2(v134) - WORD1(v134);
        HIDWORD(v123) = (unsigned __int16)v134 - HIWORD(v133);
        LODWORD(v127) = WORD2(v133);
        HIDWORD(v127) = panel_vfp;
        LODWORD(v124) = (unsigned __int16)v133 - HIWORD(v132);
        HIDWORD(v124) = WORD1(v134) - (unsigned __int16)v134;
        v126 = 0xFF00000000LL;
        result = drm_mode_vrefresh(a1 + 65);
        v32 = *((_DWORD *)a1 + 200);
        HIDWORD(v130) = result;
        if ( v32 )
        {
          v33 = *((_DWORD *)a1 + 205);
          BYTE5(v128) = 1;
          LODWORD(v130) = v33;
        }
        v34 = a1[53];
        v35 = *(_DWORD *)(*(_QWORD *)(v34 + 40) + 48LL);
        if ( v35 == 1 )
        {
          v125 = 0;
          v35 = *(_DWORD *)(*(_QWORD *)(v34 + 40) + 48LL);
        }
        if ( (unsigned int)(v35 - 9) <= 1 )
        {
          v122 = (unsigned int)(v122 + HIDWORD(v122));
          v123 = (unsigned int)(v123 + HIDWORD(v123));
        }
        v36 = *a1;
        if ( *a1 )
        {
          v37 = *(_BYTE *)(v36 + 4720);
          v38 = *(_DWORD *)(v36 + 4724);
          BYTE4(v128) = v37;
          LODWORD(v128) = v38;
          v39 = *(_QWORD *)(v34 + 40);
          if ( *(_DWORD *)(v39 + 48) != 10 )
            goto LABEL_59;
          if ( (v37 & 1) != 0 )
            goto LABEL_56;
        }
        else
        {
          BYTE4(v128) = 0;
          LODWORD(v128) = 0;
          v39 = *(_QWORD *)(v34 + 40);
          v38 = 0;
          if ( *(_DWORD *)(v39 + 48) != 10 )
            goto LABEL_59;
        }
        if ( *((_DWORD *)a1 + 201) >= 0x65u )
        {
LABEL_56:
          v40 = (unsigned int)v120 / v38;
          LODWORD(v121) = (unsigned int)v121 / v38;
          v41 = (unsigned int)v122 / v38;
          LODWORD(v120) = (unsigned int)v120 / v38;
          LODWORD(v122) = (unsigned int)v122 / v38;
          HIDWORD(v122) /= v38;
          LODWORD(v124) = (unsigned int)v124 / v38;
          if ( v32 == 1 && *((_DWORD *)a1 + 201) >= 0x65u )
          {
            v42 = *((_DWORD *)a1 + 203);
            LODWORD(v129) = *((_DWORD *)a1 + 202);
            v39 = *(_QWORD *)(v34 + 40);
            LODWORD(v120) = v42 + v40;
            LODWORD(v122) = v42 + v41;
          }
        }
LABEL_59:
        if ( (unsigned int)(v32 - 1) <= 1 && *(_DWORD *)(v39 + 48) != 10 )
        {
          v43 = *((_DWORD *)a1 + 201);
          v44 = v43 / 0x64uLL;
          v45 = v43 % 0x64;
          v46 = (unsigned __int64)(unsigned int)v120 << 32;
          v47 = -32;
          do
          {
            v48 = 2 * v45;
            if ( v48 <= 0x63 )
              v49 = 0;
            else
              v49 = -100;
            v50 = __CFADD__(v47++, 1);
            v44 = (v48 > 0x63) | (unsigned __int64)(2 * v44);
            v45 = v49 + v48;
          }
          while ( !v50 );
          v51 = 62;
          if ( 2 * v45 > 0x63 )
            ++v44;
          do
          {
            if ( ((v46 >> v51) & 1) != (unsigned __int64)(unsigned int)v120 >> 31 )
              break;
            --v51;
          }
          while ( v51 );
          v52 = v51 - 30;
          v53 = v46 << (62 - (unsigned __int8)v51);
          if ( (unsigned int)(62 - v51) >= 0x20 )
            v52 = 0;
          v54 = v53 / (v44 >> v52);
          v55 = 30 - v51;
          if ( (unsigned int)(62 - v51) <= 0x20 )
            v55 = 0;
          v56 = v54 >> v55;
          v57 = 0xFFFFFFFF00000001LL;
          if ( v56 >= 0 )
            v57 = 0xFFFFFFFFLL;
          LODWORD(v120) = (v57 + v56) >> 32;
          LODWORD(v121) = v120;
        }
LABEL_79:
        v58 = v128;
        a1[342] = v127;
        v60 = v129;
        v59 = v130;
        a1[343] = v58;
        a1[345] = v59;
        v62 = v123;
        v61 = v124;
        a1[344] = v60;
        a1[338] = v62;
        v63 = v125;
        v64 = v126;
        a1[339] = v61;
        v65 = v120;
        a1[340] = v63;
        v66 = v121;
        v67 = v122;
        a1[341] = v64;
        LODWORD(v64) = *((unsigned __int8 *)a1 + 2289);
        a1[335] = v65;
        a1[336] = v66;
        a1[337] = v67;
        if ( (_DWORD)v64 == 1 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            if ( *a1 )
            {
              v68 = *(_DWORD *)(*a1 + 24LL);
              v69 = a1[53];
              if ( v69 )
              {
LABEL_83:
                v70 = *(_DWORD *)(v69 + 32) - 1;
LABEL_90:
                result = _drm_dev_dbg(
                           0,
                           0,
                           0,
                           "enc%d intf%d skipping intf programming since cont splash is enabled\n",
                           v68,
                           v70);
                goto LABEL_151;
              }
            }
            else
            {
              v68 = -1;
              v69 = a1[53];
              if ( v69 )
                goto LABEL_83;
            }
            v70 = -1;
            goto LABEL_90;
          }
LABEL_151:
          v114 = *a1;
          if ( *a1 )
          {
            result = ((__int64 (__fastcall *)(_QWORD))sde_encoder_in_clone_mode)(*a1);
            if ( (result & 1) == 0 )
            {
              if ( *(_QWORD *)(v114 + 4960) )
              {
                result = sde_encoder_phys_vid_setup_panic_ctrl((__int64)a1);
                if ( *((_BYTE *)a1 + 2289) == 1 )
                {
                  result = a1[52];
                  if ( result )
                  {
                    v115 = *(__int64 (**)(void))(result + 8 * v17 + 1192);
                    if ( v115 )
                    {
                      if ( *((_DWORD *)v115 - 1) != 949740941 )
                        __break(0x8228u);
                      result = v115();
                    }
                  }
                }
              }
            }
          }
          goto LABEL_160;
        }
        sde_format_ext = sde_get_sde_format_ext(875710290, 0);
        if ( (_drm_debug & 4) == 0 )
        {
LABEL_94:
          v75 = raw_spin_lock_irqsave(a1[103]);
          v76 = *(unsigned __int8 *)(v18 + 753);
          v77 = v75;
          v78 = a1[53];
          v79 = *(void (__fastcall **)(__int64, __int64 *, __int64, __int64, bool))(v78 + 8 * v17 + 80);
          if ( *((_DWORD *)v79 - 1) != -272990229 )
            __break(0x8229u);
          v79(v78, &v120, sde_format_ext, v76, v3 != 0);
          v84 = a1[52];
          if ( (*(_QWORD *)(*(_QWORD *)(v84 + 72) + 32LL) & 0x10) != 0 )
          {
            sde_encoder_helper_update_intf_cfg((__int64 **)a1, v80, v81, v82, v83);
          }
          else if ( *(_QWORD *)(v84 + 808 + 8 * v17) )
          {
            v85 = *(void (**)(void))(v84 + 808 + 8 * v17);
            if ( *((_DWORD *)v85 - 1) != -1201655407 )
              __break(0x8228u);
            v85();
          }
          raw_spin_unlock_irqrestore(a1[103], v77);
          result = *a1;
          if ( *(_DWORD *)(*(_QWORD *)(a1[53] + 40LL) + 48LL) != 1 )
            goto LABEL_133;
          v131 = 0;
          disp_op = sde_encoder_get_disp_op(result);
          if ( disp_op >= 3 )
            goto LABEL_168;
          v87 = disp_op;
          if ( !*(_QWORD *)(a1[53] + 8LL * disp_op + 104) )
          {
            __break(0x800u);
LABEL_132:
            result = *a1;
LABEL_133:
            if ( !result )
            {
LABEL_160:
              v116 = (_DWORD *)a1[50];
              if ( v116 )
              {
                v117 = *a1;
                v118 = *(_QWORD *)(a1[1] + 2512LL);
                if ( *(v116 - 1) != 1659771273 )
                  __break(0x8228u);
                result = ((__int64 (__fastcall *)(__int64, char *, __int64, _QWORD))v116)(
                           v117,
                           (char *)&v119 + 4,
                           v118,
                           0);
              }
              if ( HIDWORD(v119) )
              {
                *(_DWORD *)(v18 + 4808) = HIDWORD(v119);
                sde_encoder_phys_vid_setup_avr(a1);
                result = sde_encoder_phys_vid_avr_ctrl(a1);
              }
              goto LABEL_166;
            }
            if ( *(_BYTE *)(result + 4936) != 1 || *((_DWORD *)a1 + 166) != 1 )
              goto LABEL_151;
            result = sde_encoder_get_disp_op(result);
            if ( (unsigned int)result < 3 )
            {
              v106 = a1[53];
              v107 = (unsigned int)result;
              if ( *(_QWORD *)(v106 + 8LL * (unsigned int)result + 1376) )
              {
                if ( *(_DWORD *)(*(_QWORD *)(v106 + 40) + 48LL) == 1
                  && (v108 = *(_QWORD *)(a1[64] + 152LL),
                      (num_lines = programmable_fetch_get_num_lines(a1, (_DWORD *)a1 + 670)) != 0) )
                {
                  v110 = num_lines + ((32 * *(_DWORD *)(v108 + 22008)) >> 31);
                }
                else
                {
                  v110 = 0;
                }
                v111 = a1[53];
                if ( *((_DWORD *)a1 + 676) + *((_DWORD *)a1 + 673) + *((_DWORD *)a1 + 677) + *((_DWORD *)a1 + 679) == *(_DWORD *)(*(_QWORD *)(v111 + 40) + 64LL) + v110 )
                {
                  if ( (_drm_debug & 4) != 0 )
                  {
                    _drm_dev_dbg(0, 0, 0, "flush snapshot should be set before mdp vsync\n");
                    v111 = a1[53];
                  }
                  v112 = *(void (**)(void))(v111 + 8 * v107 + 1376);
                  if ( *((_DWORD *)v112 - 1) != -765822515 )
                    __break(0x8228u);
                  v112();
                  v111 = a1[53];
                }
                v113 = *(__int64 (**)(void))(v111 + 8 * v107 + 1376);
                if ( *((_DWORD *)v113 - 1) != -765822515 )
                  __break(0x8228u);
                result = v113();
              }
              goto LABEL_151;
            }
LABEL_168:
            __break(0x5512u);
            JUMPOUT(0xF4538);
          }
          v88 = *(_QWORD *)(a1[64] + 152LL);
          *((_DWORD *)a1 + 576) = 0;
          v89 = programmable_fetch_get_num_lines(a1, &v120);
          if ( v89 )
          {
            v90 = v121;
            v91 = v124;
            v92 = v123 + HIDWORD(v121) + HIDWORD(v123) + HIDWORD(v124);
            v93 = HIDWORD(v130) * v92;
            v94 = v92 - v89;
            *((_DWORD *)a1 + 576) = (v93 + 1000000 * v89 - 1) / v93;
            v95 = v122 + v90 + HIDWORD(v122) + v91;
            if ( (*(_QWORD *)(v88 + 22008) & 0x4000000LL) != 0 )
              v96 = v122 + v90 + HIDWORD(v122) + v91;
            else
              v96 = 0;
            LOBYTE(v131) = 1;
            v97 = v96 + v95 * v94 + 1;
            HIDWORD(v131) = v97;
            if ( (_drm_debug & 4) == 0 )
              goto LABEL_119;
          }
          else
          {
            v97 = 0;
            if ( (_drm_debug & 4) == 0 )
            {
LABEL_119:
              v101 = raw_spin_lock_irqsave(a1[103]);
              v102 = a1[53];
              v103 = *(void (__fastcall **)(__int64, __int64 *))(v102 + 8 * v87 + 104);
              if ( *((_DWORD *)v103 - 1) != 248700179 )
                __break(0x8229u);
              v103(v102, &v131);
              v104 = *(void (**)(void))(a1[53] + 8 * v87 + 128);
              if ( v104 )
              {
                if ( *((_DWORD *)v104 - 1) != -1913620264 )
                  __break(0x8228u);
                v104();
              }
              raw_spin_unlock_irqrestore(a1[103], v101);
              if ( *a1 )
              {
                if ( *(_BYTE *)(*a1 + 4936LL) == 1 && *((_DWORD *)a1 + 166) == 1 )
                {
                  v105 = *(void (**)(void))(a1[53] + 8 * v87 + 1256);
                  if ( v105 )
                  {
                    if ( *((_DWORD *)v105 - 1) != 248700179 )
                      __break(0x8228u);
                    v105();
                  }
                }
              }
              goto LABEL_132;
            }
          }
          if ( *a1 )
          {
            v98 = *(_DWORD *)(*a1 + 24LL);
            v99 = a1[53];
            if ( v99 )
            {
LABEL_115:
              v100 = *(_DWORD *)(v99 + 32) - 1;
LABEL_118:
              _drm_dev_dbg(
                0,
                0,
                0,
                "enc%d intf%d vfp_fetch_lines %u vfp_fetch_start_vsync_counter %u\n",
                v98,
                v100,
                v89,
                v97);
              goto LABEL_119;
            }
          }
          else
          {
            v98 = -1;
            v99 = a1[53];
            if ( v99 )
              goto LABEL_115;
          }
          v100 = -1;
          goto LABEL_118;
        }
        if ( *a1 )
        {
          v72 = *(_DWORD *)(*a1 + 24LL);
          v73 = a1[53];
          if ( v73 )
          {
LABEL_87:
            v74 = *(_DWORD *)(v73 + 32) - 1;
LABEL_93:
            _drm_dev_dbg(0, 0, 0, "enc%d intf%d fmt_fourcc 0x%X\n", v72, v74, 875710290);
            goto LABEL_94;
          }
        }
        else
        {
          v72 = -1;
          v73 = a1[53];
          if ( v73 )
            goto LABEL_87;
        }
        v74 = -1;
        goto LABEL_93;
      }
    }
    else
    {
      v19 = -1;
      if ( v16 )
        goto LABEL_14;
    }
    v20 = -1;
    goto LABEL_20;
  }
  if ( !(_DWORD)result )
    result = printk(&unk_23BB1F, "sde_encoder_phys_vid_setup_timing_engine");
LABEL_166:
  _ReadStatusReg(SP_EL0);
  return result;
}
