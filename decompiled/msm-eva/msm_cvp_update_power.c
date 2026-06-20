__int64 __fastcall msm_cvp_update_power(__int64 a1)
{
  __int64 inst_validate; // x0
  __int64 v3; // x19
  int v4; // w20
  __int64 v5; // x23
  unsigned int v6; // w26
  int v7; // w22
  __int64 v8; // x27
  unsigned int v9; // w21
  unsigned __int64 v10; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x19
  unsigned __int64 v14; // x25
  unsigned __int64 v15; // x23
  __int64 v16; // x9
  __int64 *v17; // x8
  __int64 v18; // x11
  unsigned int *v19; // x10
  __int64 *v20; // x28
  unsigned __int64 v21; // x11
  unsigned __int64 v22; // x21
  __int64 *v23; // x9
  __int64 v24; // x3
  int v25; // w9
  __int16 v26; // w8
  _BOOL4 v27; // w27
  __int64 v28; // x3
  __int64 v29; // x3
  __int64 v30; // x3
  __int64 v31; // x3
  __int64 v32; // x3
  __int64 v33; // x3
  __int64 v34; // x3
  __int64 v35; // x3
  __int64 v36; // x3
  __int64 v37; // x3
  __int64 v38; // x3
  __int64 v39; // x3
  __int64 v40; // x3
  __int64 v41; // x3
  __int64 v42; // x3
  __int64 v43; // x3
  __int64 v44; // x3
  __int64 v45; // x12
  __int64 v46; // x13
  __int64 v47; // x15
  __int64 v48; // x16
  __int64 v49; // x0
  __int64 v50; // x3
  _QWORD *v51; // x9
  __int64 v52; // x1
  __int64 v53; // x14
  __int64 v54; // x11
  __int64 v55; // x10
  __int64 v56; // x11
  __int64 v57; // x12
  __int64 v58; // x13
  __int64 v59; // x14
  unsigned __int64 v60; // x1
  __int64 *v61; // x8
  __int64 v62; // x10
  unsigned __int64 v63; // x15
  __int64 v64; // x11
  __int64 v65; // x13
  __int64 v66; // x14
  __int64 v67; // x0
  unsigned __int64 v68; // x16
  unsigned __int64 v69; // x17
  unsigned __int64 v70; // x12
  unsigned __int64 v71; // x11
  unsigned __int64 v72; // x14
  unsigned __int64 v73; // x13
  unsigned __int64 v74; // x17
  unsigned __int64 v75; // x9
  unsigned __int64 v76; // x10
  unsigned __int64 v77; // x14
  unsigned __int64 v78; // x15
  unsigned __int64 v79; // x13
  unsigned __int64 v80; // x0
  unsigned __int64 v81; // x16
  __int64 *v82; // x11
  __int64 v83; // x14
  unsigned __int64 v84; // x9
  unsigned __int64 v85; // x12
  unsigned __int64 v86; // x15
  __int64 *v87; // x9
  unsigned __int64 v88; // x10
  unsigned __int64 v89; // x15
  unsigned __int64 v90; // x14
  __int64 *v91; // x10
  __int64 v92; // x12
  __int64 v93; // x13
  unsigned __int64 v94; // x8
  unsigned __int64 v95; // x14
  unsigned __int64 v96; // x15
  unsigned __int64 v97; // x8
  __int64 v98; // x3
  __int64 v99; // x3
  __int64 v100; // x3
  __int64 v101; // x3
  __int64 v102; // x3
  __int64 v103; // x3
  __int64 v104; // x3
  __int64 v105; // x3
  unsigned __int64 v106; // x8
  _QWORD *v107; // x15
  unsigned __int64 *v108; // x8
  unsigned __int64 *v109; // x9
  _QWORD *v110; // x13
  unsigned __int64 *v111; // x12
  __int64 *v112; // x10
  __int64 *v113; // x11
  char v114; // w14
  unsigned __int64 v115; // x16
  unsigned __int64 v116; // x0
  unsigned __int64 v117; // x15
  unsigned __int64 v118; // x17
  unsigned __int64 v119; // x17
  unsigned __int64 v120; // x16
  unsigned __int64 v121; // x0
  unsigned __int64 v122; // x13
  unsigned __int64 v123; // x17
  unsigned __int64 v124; // x0
  char v125; // w17
  unsigned __int64 v126; // x14
  unsigned __int64 v127; // x16
  unsigned __int64 v128; // x15
  __int64 v129; // x23
  __int64 v130; // x25
  unsigned __int64 v131; // x22
  unsigned __int64 v132; // x24
  __int64 v133; // x27
  __int64 v134; // x28
  unsigned __int64 v135; // x9
  unsigned __int64 v136; // x8
  __int64 v137; // x12
  unsigned int *v138; // x11
  int v139; // w9
  unsigned __int64 v140; // x8
  unsigned __int64 v141; // x22
  __int64 v142; // x8
  unsigned int v143; // w0
  unsigned __int64 v144; // x8
  unsigned __int64 v145; // x8
  __int64 v146; // [xsp+0h] [xbp-1D0h]
  unsigned int *v147; // [xsp+8h] [xbp-1C8h]
  unsigned __int64 v148; // [xsp+10h] [xbp-1C0h]
  __int64 v149; // [xsp+18h] [xbp-1B8h]
  _QWORD *v150; // [xsp+20h] [xbp-1B0h]
  __int64 v151; // [xsp+30h] [xbp-1A0h]
  __int64 *v152; // [xsp+38h] [xbp-198h]
  unsigned int v153; // [xsp+40h] [xbp-190h]
  __int64 v154; // [xsp+48h] [xbp-188h]
  __int64 v155; // [xsp+50h] [xbp-180h] BYREF
  __int64 v156; // [xsp+58h] [xbp-178h] BYREF
  __int64 v157; // [xsp+60h] [xbp-170h] BYREF
  __int64 v158; // [xsp+68h] [xbp-168h] BYREF
  __int64 v159; // [xsp+70h] [xbp-160h] BYREF
  __int64 v160; // [xsp+78h] [xbp-158h] BYREF
  unsigned __int64 v161; // [xsp+80h] [xbp-150h] BYREF
  unsigned __int64 v162; // [xsp+88h] [xbp-148h] BYREF
  __int64 v163; // [xsp+90h] [xbp-140h] BYREF
  __int64 v164; // [xsp+98h] [xbp-138h] BYREF
  _QWORD v165[9]; // [xsp+A0h] [xbp-130h] BYREF
  _QWORD v166[9]; // [xsp+E8h] [xbp-E8h] BYREF
  _QWORD v167[9]; // [xsp+130h] [xbp-A0h] BYREF
  _QWORD v168[11]; // [xsp+178h] [xbp-58h] BYREF

  v168[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    inst_validate = cvp_get_inst_validate(*(_QWORD *)(a1 + 128), a1);
    if ( !inst_validate )
    {
      v9 = -104;
      goto LABEL_17;
    }
    v3 = *(_QWORD *)(a1 + 128);
    if ( v3 && *(_DWORD *)(v3 + 304) )
    {
      if ( *(_BYTE *)(*(_QWORD *)(v3 + 888) + 32LL * (unsigned int)(*(_DWORD *)(v3 + 896) - 1) + 28) != 1 )
      {
        v9 = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          v13 = inst_validate;
          printk(&unk_9440A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          inst_validate = v13;
        }
        goto LABEL_15;
      }
      v4 = *(_DWORD *)(v3 + 912);
      v151 = inst_validate;
      if ( v4 )
      {
        v5 = *(_QWORD *)(v3 + 904);
        v6 = 0;
        v7 = 0;
        v153 = 0;
        v154 = 0;
        do
        {
          v8 = v5 + 120LL * v7;
          if ( !strcmp(*(const char **)v8, "eva-ddr") )
          {
            v6 = *(_DWORD *)(v8 + 12);
            v153 = v6 / 0x64;
            v154 = v5 + 120LL * v7;
          }
          ++v7;
        }
        while ( v4 != v7 );
        if ( v154 )
        {
          mutex_lock(v3 + 48);
          v14 = 0;
          v15 = 0;
          v16 = *(_QWORD *)(cvp_driver + 48);
          v17 = *(__int64 **)(v16 + 256);
          v18 = *(int *)(v16 + 776);
          v19 = *(unsigned int **)(v16 + 768);
          v20 = *(__int64 **)(v16 + 280);
          memset(v168, 0, 72);
          v146 = v18;
          v147 = v19;
          v149 = *v17;
          v150 = (_QWORD *)v16;
          LODWORD(v17) = v18 - 1;
          v21 = *v19;
          v22 = v19[(unsigned int)v17];
          v23 = (__int64 *)(v16 + 280);
          memset(v167, 0, sizeof(v167));
          v163 = 0;
          v164 = 0;
          v161 = 0;
          v162 = 0;
          memset(v166, 0, sizeof(v166));
          memset(v165, 0, sizeof(v165));
          v159 = 0;
          v160 = 0;
          v148 = v21;
          v157 = 0;
          v158 = 0;
          v155 = 0;
          v156 = 0;
          if ( v20 != v23 )
          {
            v152 = v23;
            while ( 1 )
            {
              if ( (v20[41] & 0xFFFFFFFE) == 8 )
                goto LABEL_25;
              if ( *((_DWORD *)v20 + 3716) )
              {
                v24 = *((unsigned int *)v20 + 3714);
LABEL_30:
                v25 = msm_cvp_debug_out;
                v26 = msm_cvp_debug;
                v27 = *((_DWORD *)v20 + 3709) > 1u;
                if ( (_DWORD)v24 && (msm_cvp_debug & 0x400) != 0 )
                  goto LABEL_32;
                goto LABEL_34;
              }
              v24 = *((unsigned int *)v20 + 3714);
              if ( *((_DWORD *)v20 + 3715) )
                goto LABEL_30;
              if ( (_DWORD)v24 )
                break;
              if ( *((_DWORD *)v20 + 3717)
                || *((_DWORD *)v20 + 3718)
                || *((_DWORD *)v20 + 3719)
                || *((_DWORD *)v20 + 3720)
                || *((_DWORD *)v20 + 3721)
                || *((_DWORD *)v20 + 3722) )
              {
                v25 = msm_cvp_debug_out;
                v26 = msm_cvp_debug;
                v27 = *((_DWORD *)v20 + 3709) > 1u;
                goto LABEL_34;
              }
LABEL_24:
              v23 = v152;
LABEL_25:
              v20 = (__int64 *)*v20;
              if ( v20 == v23 )
                goto LABEL_207;
            }
            v25 = msm_cvp_debug_out;
            v26 = msm_cvp_debug;
            v27 = *((_DWORD *)v20 + 3709) > 1u;
            if ( (msm_cvp_debug & 0x400) == 0 )
              goto LABEL_34;
LABEL_32:
            if ( !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, &hw_names, v24);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_34:
            v28 = *((unsigned int *)v20 + 3715);
            if ( (_DWORD)v28 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, &unk_1650, v28);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
              v29 = *((unsigned int *)v20 + 3716);
              if ( !(_DWORD)v29 )
                goto LABEL_41;
            }
            else
            {
              v29 = *((unsigned int *)v20 + 3716);
              if ( !(_DWORD)v29 )
                goto LABEL_41;
            }
            if ( (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, &off_1658, v29);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_41:
            v30 = *((unsigned int *)v20 + 3717);
            if ( (_DWORD)v30 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, &unk_1660, v30);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
              v31 = *((unsigned int *)v20 + 3718);
              if ( !(_DWORD)v31 )
                goto LABEL_48;
            }
            else
            {
              v31 = *((unsigned int *)v20 + 3718);
              if ( !(_DWORD)v31 )
                goto LABEL_48;
            }
            if ( (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, aVadl, v31);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_48:
            v32 = *((unsigned int *)v20 + 3719);
            if ( (_DWORD)v32 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, aTof, v32);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
              v33 = *((unsigned int *)v20 + 3720);
              if ( !(_DWORD)v33 )
                goto LABEL_55;
            }
            else
            {
              v33 = *((unsigned int *)v20 + 3720);
              if ( !(_DWORD)v33 )
                goto LABEL_55;
            }
            if ( (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, aRge, v33);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_55:
            v34 = *((unsigned int *)v20 + 3721);
            if ( (_DWORD)v34 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, aXra, v34);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
              v35 = *((unsigned int *)v20 + 3722);
              if ( !(_DWORD)v35 )
                goto LABEL_62;
            }
            else
            {
              v35 = *((unsigned int *)v20 + 3722);
              if ( !(_DWORD)v35 )
                goto LABEL_62;
            }
            if ( (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_964A6, &unk_8DA84, aLsr, v35);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_62:
            v36 = *((unsigned int *)v20 + 3724);
            if ( (_DWORD)v36 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, &hw_names, v36);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
              v37 = *((unsigned int *)v20 + 3725);
              if ( !(_DWORD)v37 )
                goto LABEL_69;
            }
            else
            {
              v37 = *((unsigned int *)v20 + 3725);
              if ( !(_DWORD)v37 )
                goto LABEL_69;
            }
            if ( (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, &unk_1650, v37);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_69:
            v38 = *((unsigned int *)v20 + 3726);
            if ( (_DWORD)v38 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, &off_1658, v38);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
              v39 = *((unsigned int *)v20 + 3727);
              if ( !(_DWORD)v39 )
                goto LABEL_76;
            }
            else
            {
              v39 = *((unsigned int *)v20 + 3727);
              if ( !(_DWORD)v39 )
                goto LABEL_76;
            }
            if ( (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, &unk_1660, v39);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_76:
            v40 = *((unsigned int *)v20 + 3728);
            if ( (_DWORD)v40 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, aVadl, v40);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
              v41 = *((unsigned int *)v20 + 3729);
              if ( !(_DWORD)v41 )
                goto LABEL_83;
            }
            else
            {
              v41 = *((unsigned int *)v20 + 3729);
              if ( !(_DWORD)v41 )
                goto LABEL_83;
            }
            if ( (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, aTof, v41);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_83:
            v42 = *((unsigned int *)v20 + 3730);
            if ( (_DWORD)v42 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, aRge, v42);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
              v43 = *((unsigned int *)v20 + 3731);
              if ( !(_DWORD)v43 )
                goto LABEL_90;
            }
            else
            {
              v43 = *((unsigned int *)v20 + 3731);
              if ( !(_DWORD)v43 )
                goto LABEL_90;
            }
            if ( (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, aXra, v43);
              v25 = msm_cvp_debug_out;
              v26 = msm_cvp_debug;
            }
LABEL_90:
            v44 = *((unsigned int *)v20 + 3732);
            if ( (_DWORD)v44 && (v26 & 0x400) != 0 && !v25 )
            {
              printk(&unk_9147D, &unk_8DA84, aLsr, v44);
              v25 = msm_cvp_debug_out;
              if ( (msm_cvp_debug & 0x400) == 0 )
                goto LABEL_96;
            }
            else if ( (v26 & 0x400) == 0 )
            {
              goto LABEL_96;
            }
            if ( !v25 )
              printk(&unk_861F7, &unk_8DA84, *((unsigned int *)v20 + 3723), *((unsigned int *)v20 + 3733));
LABEL_96:
            v45 = *((unsigned int *)v20 + 3716);
            v46 = *((unsigned int *)v20 + 3717);
            v47 = *((unsigned int *)v20 + 3718);
            v48 = *((unsigned int *)v20 + 3719);
            v49 = *((unsigned int *)v20 + 3720);
            v50 = *((unsigned int *)v20 + 3738);
            v51 = (_QWORD *)((char *)v167 + ((8LL * v27) | ((unsigned __int64)v27 << 6)));
            v53 = v51[2];
            v52 = v51[3];
            v54 = v51[1] + *((unsigned int *)v20 + 3715);
            *v51 += *((unsigned int *)v20 + 3714);
            v51[1] = v54;
            v55 = v53 + v45;
            v56 = v51[4];
            v57 = v51[5];
            v58 = v52 + v46;
            v59 = *((unsigned int *)v20 + 3721);
            v60 = *((unsigned int *)v20 + 3727);
            v51[2] = v55;
            v51[3] = v58;
            v61 = (_QWORD *)((char *)v165 + ((8LL * v27) | ((unsigned __int64)v27 << 6)));
            v51[4] = v56 + v47;
            v51[5] = v57 + v48;
            v62 = *v61;
            v63 = v61[1];
            v64 = v51[6] + v49;
            v65 = v51[7] + v59;
            v66 = *((unsigned int *)v20 + 3722);
            if ( *v61 <= (unsigned __int64)*((unsigned int *)v20 + 3724) )
              v62 = *((unsigned int *)v20 + 3724);
            v67 = v51[8];
            if ( v63 <= *((unsigned int *)v20 + 3725) )
              v63 = *((unsigned int *)v20 + 3725);
            v69 = v61[2];
            v68 = v61[3];
            v70 = *((unsigned int *)v20 + 3726);
            v51[6] = v64;
            v51[7] = v65;
            v51[8] = v67 + v66;
            v72 = v61[4];
            v71 = v61[5];
            v73 = *((unsigned int *)v20 + 3728);
            *v61 = v62;
            v61[1] = v63;
            if ( v69 > v70 )
              v70 = v69;
            v74 = v61[8];
            if ( v68 <= v60 )
              v75 = v60;
            else
              v75 = v68;
            if ( v72 <= v73 )
              v76 = v73;
            else
              v76 = v72;
            v77 = v61[6];
            v78 = v61[7];
            v79 = *((unsigned int *)v20 + 3730);
            v80 = *((unsigned int *)v20 + 3732);
            if ( v71 <= *((unsigned int *)v20 + 3729) )
              v71 = *((unsigned int *)v20 + 3729);
            v81 = *((unsigned int *)v20 + 3731);
            v61[2] = v70;
            v61[3] = v75;
            v61[4] = v76;
            v61[5] = v71;
            v82 = &v160;
            if ( v77 > v79 )
              v79 = v77;
            v83 = *((unsigned int *)v20 + 3723);
            if ( v78 <= v81 )
              v84 = v81;
            else
              v84 = v78;
            if ( v74 <= v80 )
              v85 = v80;
            else
              v85 = v74;
            v61[6] = v79;
            v61[7] = v84;
            if ( v27 )
              v86 = v15;
            else
              v86 = v14;
            v87 = &v158;
            v88 = v86 + v83;
            v89 = *((unsigned int *)v20 + 3733);
            if ( v27 )
              v82 = &v159;
            else
              v14 = v88;
            if ( v27 )
              v15 = v88;
            v90 = *v82;
            v61[8] = v85;
            if ( v27 )
              v87 = &v157;
            v91 = &v156;
            v92 = *((unsigned int *)v20 + 3734);
            if ( v27 )
              v91 = &v155;
            v93 = *v87;
            if ( v90 <= v89 )
              v94 = v89;
            else
              v94 = v90;
            v95 = *v91;
            v96 = *((unsigned int *)v20 + 3735);
            *v82 = v94;
            *v87 = v93 + v92;
            if ( v95 <= v96 )
              v97 = v96;
            else
              v97 = v95;
            *v91 = v97;
            if ( (_DWORD)v50 && (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8A851, &unk_8DA84, &hw_names, v50);
              v98 = *((unsigned int *)v20 + 3739);
              if ( !(_DWORD)v98 )
                goto LABEL_143;
            }
            else
            {
              v98 = *((unsigned int *)v20 + 3739);
              if ( !(_DWORD)v98 )
                goto LABEL_143;
            }
            if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
              printk(&unk_8A851, &unk_8DA84, &unk_1650, v98);
LABEL_143:
            v99 = *((unsigned int *)v20 + 3740);
            if ( (_DWORD)v99 && (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8A851, &unk_8DA84, &off_1658, v99);
              v100 = *((unsigned int *)v20 + 3741);
              if ( !(_DWORD)v100 )
                goto LABEL_150;
            }
            else
            {
              v100 = *((unsigned int *)v20 + 3741);
              if ( !(_DWORD)v100 )
                goto LABEL_150;
            }
            if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
              printk(&unk_8A851, &unk_8DA84, &unk_1660, v100);
LABEL_150:
            v101 = *((unsigned int *)v20 + 3742);
            if ( (_DWORD)v101 && (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8A851, &unk_8DA84, aVadl, v101);
              v102 = *((unsigned int *)v20 + 3743);
              if ( !(_DWORD)v102 )
                goto LABEL_157;
            }
            else
            {
              v102 = *((unsigned int *)v20 + 3743);
              if ( !(_DWORD)v102 )
                goto LABEL_157;
            }
            if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
              printk(&unk_8A851, &unk_8DA84, aTof, v102);
LABEL_157:
            v103 = *((unsigned int *)v20 + 3744);
            if ( (_DWORD)v103 && (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8A851, &unk_8DA84, aRge, v103);
              v104 = *((unsigned int *)v20 + 3745);
              if ( (_DWORD)v104 )
                goto LABEL_161;
            }
            else
            {
              v104 = *((unsigned int *)v20 + 3745);
              if ( (_DWORD)v104 )
              {
LABEL_161:
                if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
                  printk(&unk_8A851, &unk_8DA84, aXra, v104);
              }
            }
            v105 = *((unsigned int *)v20 + 3746);
            if ( (_DWORD)v105 && (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
              printk(&unk_8A851, &unk_8DA84, aLsr, v105);
            goto LABEL_24;
          }
LABEL_207:
          v107 = v167;
          v108 = (unsigned __int64 *)&v164;
          v109 = &v162;
          v110 = v165;
          v111 = (unsigned __int64 *)&v160;
          v112 = &v158;
          v113 = &v156;
          v114 = 1;
          do
          {
            v115 = *(int *)v107;
            if ( v107[1] > v115 )
              v115 = v107[1];
            if ( v107[2] > (unsigned __int64)(int)v115 )
              v115 = v107[2];
            if ( v107[3] > (unsigned __int64)(int)v115 )
              v115 = v107[3];
            if ( v107[4] > (unsigned __int64)(int)v115 )
              v115 = v107[4];
            v116 = v107[6];
            if ( v107[5] > (unsigned __int64)(int)v115 )
              v115 = v107[5];
            v118 = v107[7];
            v117 = v107[8];
            if ( v116 > (int)v115 )
              LODWORD(v115) = v116;
            if ( v118 > (int)v115 )
              LODWORD(v115) = v118;
            v119 = *(int *)v110;
            if ( v117 <= (int)v115 )
              LODWORD(v117) = v115;
            v120 = v110[2];
            v117 = (int)v117;
            if ( v110[1] > v119 )
              v119 = v110[1];
            if ( v120 <= (int)v119 )
              LODWORD(v120) = v119;
            if ( v110[3] > (unsigned __int64)(int)v120 )
              v120 = v110[3];
            if ( v110[4] > (unsigned __int64)(int)v120 )
              v120 = v110[4];
            v121 = v110[6];
            if ( v110[5] > (unsigned __int64)(int)v120 )
              v120 = v110[5];
            v123 = v110[7];
            v122 = v110[8];
            if ( v121 > (int)v120 )
              LODWORD(v120) = v121;
            v124 = *v113;
            v113 = &v155;
            if ( v123 > (int)v120 )
              LODWORD(v120) = v123;
            v125 = v114;
            v126 = *v112;
            if ( v122 <= (int)v120 )
              LODWORD(v122) = v120;
            v127 = *v111;
            if ( (int)v117 <= v14 )
              v117 = v14;
            v111 = (unsigned __int64 *)&v159;
            *v108 = v117;
            v108 = (unsigned __int64 *)&v163;
            v14 = v15;
            if ( (int)v122 > v127 )
              v127 = (int)v122;
            v110 = v166;
            if ( v127 >= v22 )
              v128 = v22;
            else
              v128 = v127;
            if ( v126 <= v124 )
              v126 = v124;
            *v109 = v128;
            v109 = &v161;
            *v112 = v126;
            v112 = &v157;
            v107 = v168;
            v114 = 0;
          }
          while ( (v125 & 1) != 0 );
          v130 = v163;
          v129 = v164;
          v132 = v161;
          v131 = v162;
          v134 = v157;
          v133 = v158;
          if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
            printk(&unk_86CCF, &unk_8DA84, v164, v162);
          if ( v130 + v129 <= v22 )
          {
            if ( v132 <= v131 )
              v135 = v131;
            else
              v135 = v132;
            if ( v130 + v129 <= v135 )
              v136 = v135;
            else
              v136 = v130 + v129;
            if ( v135 <= v22 )
            {
              v22 = v148;
              if ( v136 > v148 )
              {
                v137 = v146;
                if ( (unsigned int)v146 < 2 )
                {
                  v138 = v147;
                  v137 = 1;
                }
                else
                {
                  v138 = v147;
                  v139 = 1;
                  while ( v136 > v147[v139] )
                  {
                    if ( (_DWORD)v146 == ++v139 )
                      goto LABEL_273;
                  }
                  v137 = v139;
                }
LABEL_273:
                v22 = v138[v137];
              }
            }
            v140 = v134 + v133;
            if ( v134 + v133 >= (unsigned __int64)v6 )
              v140 = v6;
            if ( v140 <= v153 )
              v141 = v153;
            else
              v141 = v140;
            if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
              printk(&unk_893B1, &unk_8DA84, "adjust_bw_freqs", v22);
            v142 = v150[159];
            v150[159] = v22;
            v150[160] = v142;
            *(_DWORD *)(v149 + 24) = v22;
            v150[161] = v141;
            mutex_unlock(v3 + 48);
            v143 = msm_cvp_set_clocks(v3);
            if ( v143 )
            {
              v9 = v143;
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                v145 = _ReadStatusReg(SP_EL0);
                printk(&unk_9143E, *(unsigned int *)(v145 + 1800), *(unsigned int *)(v145 + 1804), &unk_8E7CE);
              }
              *(_QWORD *)(v3 + 1272) = *(_QWORD *)(v3 + 1280);
            }
            else
            {
              v9 = msm_cvp_set_bw(v3, v154, *(_QWORD *)(v3 + 1288));
            }
          }
          else
          {
            if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
            {
              v144 = _ReadStatusReg(SP_EL0);
              printk(&unk_8DC73, *(unsigned int *)(v144 + 1800), *(unsigned int *)(v144 + 1804), "warn");
            }
            mutex_unlock(v3 + 48);
            v9 = -524;
          }
          goto LABEL_288;
        }
      }
      v9 = -22;
      if ( (msm_cvp_debug & 1) == 0 )
      {
LABEL_288:
        inst_validate = v151;
        goto LABEL_15;
      }
      inst_validate = v151;
      if ( !msm_cvp_debug_out )
      {
        v106 = _ReadStatusReg(SP_EL0);
        printk(&unk_83A69, *(unsigned int *)(v106 + 1800), *(unsigned int *)(v106 + 1804), &unk_8E7CE);
        goto LABEL_288;
      }
    }
    else
    {
      v9 = -104;
    }
LABEL_15:
    cvp_put_inst(inst_validate);
    goto LABEL_17;
  }
  v9 = -22;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v10 = _ReadStatusReg(SP_EL0);
    printk(&unk_912BD, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v9;
}
