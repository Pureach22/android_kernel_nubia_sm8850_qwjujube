__int64 __fastcall syna_tcm_v1_read_message(__int64 a1, _BYTE *a2, __int64 a3)
{
  _BYTE *v4; // x25
  _BOOL4 v5; // w26
  int v6; // w8
  unsigned int v7; // w22
  int v8; // w8
  int v9; // w9
  __int64 v10; // x8
  unsigned int v11; // w8
  unsigned int *v12; // x21
  const void *v13; // x20
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x0
  __int64 v17; // x2
  void *v18; // x0
  unsigned int v19; // w0
  __int64 v20; // x24
  __int64 v21; // x2
  char v22; // w8
  unsigned int v23; // w8
  unsigned int v24; // w20
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 v27; // x0
  __int64 v28; // x2
  __int64 v29; // x21
  void *v30; // x22
  int v31; // w24
  __int64 v32; // x0
  __int64 (*v33)(void); // x8
  __int64 v34; // x0
  unsigned int v35; // w23
  unsigned int v36; // w9
  unsigned int v37; // w13
  int v38; // w9
  int v39; // w12
  unsigned int v40; // w10
  unsigned int v41; // w8
  unsigned int v42; // w11
  bool v43; // zf
  char v44; // w9
  int v45; // w12
  unsigned int v46; // w8
  unsigned int v47; // w11
  unsigned int v48; // w20
  unsigned int v49; // w27
  size_t v50; // x24
  unsigned int v51; // w22
  const void *v52; // x23
  __int64 v53; // x0
  __int64 v54; // x2
  void *v55; // x0
  __int64 v56; // x2
  __int64 v57; // x0
  __int64 v58; // x2
  __int64 v59; // x8
  unsigned int v60; // w9
  int v61; // w11
  unsigned int v62; // w22
  unsigned int v63; // w10
  unsigned int v64; // w8
  void *v65; // x0
  __int64 v66; // x2
  char v67; // w8
  void *v68; // x0
  unsigned int v69; // w20
  unsigned int v70; // w26
  int v71; // w25
  int v72; // w21
  unsigned int v73; // w9
  unsigned int v74; // w28
  unsigned int v75; // w23
  unsigned int v76; // w24
  __int64 v77; // x8
  unsigned int v78; // w8
  size_t v79; // x2
  unsigned int v80; // w22
  void *v81; // x20
  __int64 v82; // x0
  __int64 v83; // x2
  __int64 v84; // x0
  __int64 v85; // x2
  __int64 v86; // x0
  int v87; // w20
  __int64 v88; // x0
  int v89; // w8
  __int64 v90; // x1
  __int64 v91; // x2
  __int64 v92; // x8
  __int64 v93; // x8
  const void *v94; // x1
  char *v95; // x0
  __int64 v96; // x2
  void *v97; // x0
  int v98; // w20
  __int64 v99; // x2
  char v100; // w8
  __int64 v101; // x2
  char v102; // w8
  _BYTE *v103; // x9
  __int64 v104; // x2
  char v105; // w8
  int v106; // w10
  int v107; // w9
  unsigned int v108; // w11
  __int64 v109; // x12
  int v110; // w14
  unsigned int v111; // w10
  char v112; // w8
  __int64 v113; // x22
  __int64 v114; // x9
  void (*v115)(void); // x11
  __int64 v116; // x2
  char v117; // w8
  size_t v118; // x23
  size_t v119; // x8
  void *v120; // x0
  void *v121; // x20
  __int64 v122; // x0
  __int64 v123; // x2
  __int64 v124; // x0
  __int64 v125; // x2
  int v126; // w8
  size_t v127; // x22
  size_t v128; // x8
  void *v129; // x0
  void *v130; // x20
  __int64 v131; // x0
  __int64 v132; // x2
  __int64 v133; // x0
  __int64 v134; // x2
  __int64 v135; // x2
  __int64 v136; // x2
  void *v137; // x0
  __int64 v138; // x8
  unsigned int v139; // w4
  __int64 v140; // x2
  __int64 v141; // x2
  char v142; // w8
  __int64 v143; // x2
  char v144; // w8
  unsigned int v145; // w3
  __int64 v146; // x2
  const void *v147; // x1
  __int64 v148; // x2
  __int64 v149; // x2
  char v150; // w8
  unsigned int v151; // w8
  __int64 v152; // x2
  __int64 v153; // x2
  __int64 v154; // x2
  void *v155; // x0
  __int64 v156; // x8
  unsigned int v157; // w4
  __int64 v158; // x2
  __int64 v159; // x2
  char v160; // w8
  __int64 v161; // x2
  __int64 v162; // x2
  char v163; // w8
  __int64 v164; // x8
  __int64 *v165; // x20
  __int64 v166; // x3
  _DWORD *v167; // x9
  __int64 v168; // x2
  __int64 v169; // x1
  __int64 v170; // x2
  __int64 v171; // x2
  char v172; // w8
  void *v173; // x0
  void *v174; // x0
  const char *v175; // x1
  __int64 v176; // x2
  char v177; // w8
  void *v178; // x0
  void *v179; // x0
  __int64 v180; // x0
  __int64 v181; // x2
  const void *v182; // x1
  __int64 v183; // x2
  const void *v184; // x20
  __int64 v185; // x2
  __int64 v186; // x2
  char v187; // w8
  void *v188; // x0
  void *v189; // x0
  __int64 v190; // x2
  int v191; // w8
  int v192; // w10
  int v193; // w8
  __int64 v194; // x0
  int v195; // w8
  __int64 v196; // x1
  _BOOL4 v198; // [xsp+4h] [xbp-2Ch]
  _BYTE *v199; // [xsp+8h] [xbp-28h]
  int v200; // [xsp+18h] [xbp-18h]
  unsigned int v201; // [xsp+1Ch] [xbp-14h]
  unsigned int v202; // [xsp+20h] [xbp-10h]
  unsigned int v203; // [xsp+24h] [xbp-Ch]
  const void **v204; // [xsp+28h] [xbp-8h]

  if ( !a1 )
  {
    v65 = unk_3365A;
LABEL_93:
    printk(v65, "syna_tcm_v1_read_message", a3);
    return (unsigned int)-241;
  }
  if ( !*(_QWORD *)(a1 + 72) )
  {
    v65 = unk_3C6C4;
    goto LABEL_93;
  }
  v4 = a2;
  if ( *(_BYTE *)(a1 + 890) != 1 )
  {
    v5 = 0;
    if ( !a2 )
      goto LABEL_8;
    goto LABEL_7;
  }
  v5 = *(_DWORD *)(a1 + 504) == 0;
  if ( a2 )
LABEL_7:
    *a2 = -1;
LABEL_8:
  *(_BYTE *)(a1 + 509) = 0;
  mutex_lock(a1 + 840);
  if ( *(_BYTE *)(a1 + 640) )
    printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 640));
  mutex_lock(a1 + 592);
  ++*(_BYTE *)(a1 + 640);
  if ( v5 )
  {
    v6 = *(_DWORD *)(a1 + 892);
    v7 = 4;
    if ( v6 )
    {
      v8 = v6 + *(unsigned __int8 *)(a1 + 900);
      if ( *(_BYTE *)(a1 + 896) )
        v9 = 6;
      else
        v9 = 4;
      v7 = v8 + v9 + 1;
    }
  }
  else
  {
    v7 = 4;
  }
  v10 = *(_QWORD *)(a1 + 72);
  v204 = (const void **)(a1 + 576);
  if ( *(_BYTE *)(v10 + 21) == 1 && v7 > *(_DWORD *)(v10 + 28) )
  {
    v11 = *(_DWORD *)(v10 + 24);
    if ( !v11 )
    {
      v7 = 0;
      v12 = (unsigned int *)(a1 + 584);
      goto LABEL_29;
    }
    v7 = v7 / v11 * v11;
  }
  v12 = (unsigned int *)(a1 + 584);
  if ( v7 > *(_DWORD *)(a1 + 584) )
  {
    v13 = *v204;
    if ( *v204 )
    {
      v14 = syna_request_managed_device();
      if ( !v14 )
      {
        printk(unk_3BE43, "syna_pal_mem_free", v15);
        v16 = syna_request_managed_device();
        if ( v16 )
          goto LABEL_26;
        goto LABEL_260;
      }
      devm_kfree(v14, v13);
    }
    v16 = syna_request_managed_device();
    if ( v16 )
    {
LABEL_26:
      if ( (int)v7 > 0 )
      {
        v18 = (void *)devm_kmalloc(v16, v7, 3520);
        *v204 = v18;
        if ( v18 )
        {
          *(_DWORD *)(a1 + 584) = v7;
          memset(v18, 0, v7);
          *(_DWORD *)(a1 + 588) = 0;
          goto LABEL_29;
        }
LABEL_262:
        printk(unk_3703C, "syna_tcm_buf_alloc", v7);
        *(_QWORD *)(a1 + 584) = 0;
        printk(unk_343B9, "syna_tcm_v1_read_message", v170);
        v171 = *(unsigned __int8 *)(a1 + 640);
        if ( (_DWORD)v171 == 1 )
        {
          v172 = 0;
        }
        else
        {
          printk(unk_38244, "syna_tcm_buf_unlock", v171);
          v172 = *(_BYTE *)(a1 + 640) - 1;
        }
        *(_BYTE *)(a1 + 640) = v172;
        mutex_unlock(a1 + 592);
        *(_DWORD *)(a1 + 512) = 0;
        v35 = -243;
        *(_BYTE *)(a1 + 509) = -1;
        goto LABEL_349;
      }
      v68 = unk_38286;
LABEL_261:
      printk(v68, "syna_pal_mem_alloc", v17);
      *v204 = nullptr;
      goto LABEL_262;
    }
LABEL_260:
    v68 = unk_3BE43;
    goto LABEL_261;
  }
LABEL_29:
  v19 = syna_tcm_v1_read(a1, v7, *(_QWORD *)(a1 + 576), *(unsigned int *)(a1 + 584));
  if ( (v19 & 0x80000000) != 0 )
  {
    v35 = v19;
    printk(unk_38466, "syna_tcm_v1_read_message", v7);
    v66 = *(unsigned __int8 *)(a1 + 640);
    if ( (_DWORD)v66 == 1 )
    {
      v67 = 0;
    }
    else
    {
      printk(unk_38244, "syna_tcm_buf_unlock", v66);
      v67 = *(_BYTE *)(a1 + 640) - 1;
    }
    *(_BYTE *)(a1 + 640) = v67;
    mutex_unlock(a1 + 592);
    *(_DWORD *)(a1 + 512) = 0;
    *(_BYTE *)(a1 + 509) = -1;
    goto LABEL_349;
  }
  v20 = *(_QWORD *)(a1 + 576);
  *(_DWORD *)(a1 + 512) = *(unsigned __int16 *)(v20 + 2);
  if ( *(_BYTE *)(v20 + 1) )
    *(_BYTE *)(a1 + 509) = *(_BYTE *)(v20 + 1);
  v21 = *(unsigned __int8 *)(a1 + 640);
  if ( (_DWORD)v21 == 1 )
  {
    v22 = 0;
  }
  else
  {
    printk(unk_38244, "syna_tcm_buf_unlock", v21);
    v22 = *(_BYTE *)(a1 + 640) - 1;
  }
  *(_BYTE *)(a1 + 640) = v22;
  mutex_unlock(a1 + 592);
  v23 = *(_DWORD *)(a1 + 512);
  if ( !v23 )
    goto LABEL_157;
  if ( *(_BYTE *)(v20 + 1) == 3 )
  {
    if ( *(_DWORD *)(a1 + 60) )
      v24 = *(_DWORD *)(a1 + 60);
    else
      v24 = 64;
    v25 = syna_request_managed_device();
    if ( v25 )
    {
      if ( v24 <= 0x7FFFFFFE )
      {
        v27 = devm_kmalloc(v25, v24 + 1, 3520);
        if ( v27 )
        {
          v29 = v27;
          v30 = unk_37DFA;
          v31 = 100;
          while ( 1 )
          {
            v32 = *(_QWORD *)(a1 + 72);
            if ( !v32 )
              goto LABEL_279;
            v33 = *(__int64 (**)(void))(v32 + 32);
            if ( !v33 )
              break;
            /* CFI check removed */
            if ( (v33() & 0x80000000) != 0 )
              goto LABEL_280;
            if ( *(_BYTE *)(v29 + 1) )
            {
              usleep_range_state(1000, 2000, 2);
              if ( --v31 )
                continue;
            }
            v34 = syna_request_managed_device();
            if ( v34 )
              goto LABEL_51;
            goto LABEL_281;
          }
          v30 = unk_3617E;
LABEL_279:
          printk(v30, "syna_tcm_read", v28);
LABEL_280:
          printk(unk_31A6B, "syna_tcm_v1_discard_message", v24);
          v34 = syna_request_managed_device();
          if ( v34 )
          {
LABEL_51:
            devm_kfree(v34, v29);
            v35 = -242;
            goto LABEL_349;
          }
LABEL_281:
          v174 = unk_3BE43;
          v175 = "syna_pal_mem_free";
          goto LABEL_282;
        }
LABEL_268:
        v174 = unk_37F60;
        v175 = "syna_tcm_v1_discard_message";
LABEL_282:
        printk(v174, v175, v28);
        v35 = -242;
        goto LABEL_349;
      }
      v173 = unk_38286;
    }
    else
    {
      v173 = unk_3BE43;
    }
    printk(v173, "syna_pal_mem_alloc", v26);
    goto LABEL_268;
  }
  v36 = v23 - (v7 - 4);
  if ( v23 < v7 - 4 )
    v36 = 0;
  v37 = v7 <= 4 ? *(_DWORD *)(a1 + 512) : v36;
  if ( !v37 )
  {
LABEL_157:
    if ( *(_BYTE *)(a1 + 640) )
      printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 640));
    mutex_lock(a1 + 592);
    v103 = *(_BYTE **)(a1 + 576);
    ++*(_BYTE *)(a1 + 640);
    *v103 = -91;
    *(_BYTE *)(*(_QWORD *)(a1 + 576) + 1LL) = *(_BYTE *)(a1 + 509);
    *(_WORD *)(*(_QWORD *)(a1 + 576) + 2LL) = *(_DWORD *)(a1 + 512);
    v104 = *(unsigned __int8 *)(a1 + 640);
    if ( (_DWORD)v104 == 1 )
    {
      v105 = 0;
    }
    else
    {
      printk(unk_38244, "syna_tcm_buf_unlock", v104);
      v105 = *(_BYTE *)(a1 + 640) - 1;
    }
    *(_BYTE *)(a1 + 640) = v105;
    mutex_unlock(a1 + 592);
    if ( *(_BYTE *)(a1 + 896) == 1 && *(_DWORD *)(a1 + 512) )
    {
      if ( *(_BYTE *)(a1 + 640) )
        printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 640));
      mutex_lock(a1 + 592);
      v106 = *(_DWORD *)(a1 + 512);
      v107 = *(unsigned __int8 *)(a1 + 640);
      v108 = *(_DWORD *)(a1 + 584);
      *(_BYTE *)(a1 + 640) = v107 + 1;
      if ( v108 > v106 + 5 )
      {
        v109 = *(_QWORD *)(a1 + 576);
        v110 = *(unsigned __int8 *)(a1 + 900);
        *(_WORD *)(a1 + 898) = *(_WORD *)(v109 + (unsigned int)(v106 + 5));
        if ( v110 == 1 )
        {
          v111 = v106 + 7;
          if ( v108 >= v111 )
            *(_BYTE *)(a1 + 901) = *(_BYTE *)(v109 + v111);
        }
        if ( v107 )
        {
          printk(unk_38244, "syna_tcm_buf_unlock", (unsigned __int8)(v107 + 1));
          v112 = *(_BYTE *)(a1 + 640) - 1;
        }
        else
        {
          v112 = 0;
        }
        *(_BYTE *)(a1 + 640) = v112;
        mutex_unlock(a1 + 592);
      }
    }
    v113 = *(unsigned __int8 *)(a1 + 509);
    if ( *(_QWORD *)(a1 + 5080 + 16 * v113 + 8) )
    {
      if ( *(_BYTE *)(a1 + 640) )
        printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 640));
      mutex_lock(a1 + 592);
      v114 = a1 + 5080 + 16LL * *(unsigned __int8 *)(a1 + 509);
      ++*(_BYTE *)(a1 + 640);
      v115 = *(void (**)(void))(v114 + 8);
      if ( *((_DWORD *)v115 - 1) != -1617705974 )
        __break(0x822Bu);
      v115();
      v116 = *(unsigned __int8 *)(a1 + 640);
      if ( (_DWORD)v116 == 1 )
      {
        v117 = 0;
      }
      else
      {
        printk(unk_38244, "syna_tcm_buf_unlock", v116);
        v117 = *(_BYTE *)(a1 + 640) - 1;
      }
      *(_BYTE *)(a1 + 640) = v117;
      mutex_unlock(a1 + 592);
      LODWORD(v113) = *(unsigned __int8 *)(a1 + 509);
    }
    if ( (unsigned int)v113 >= 0x10 )
    {
      if ( !*(_DWORD *)(a1 + 512) )
      {
        *(_DWORD *)(a1 + 268) = 0;
        if ( !v4 )
          goto LABEL_340;
        goto LABEL_339;
      }
      if ( *(_BYTE *)(a1 + 320) )
        printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 320));
      mutex_lock(a1 + 272);
      v118 = *(unsigned int *)(a1 + 512);
      v119 = *(unsigned int *)(a1 + 264);
      v120 = *(void **)(a1 + 256);
      ++*(_BYTE *)(a1 + 320);
      if ( (unsigned int)v119 >= (unsigned int)v118 )
      {
        v118 = v119;
LABEL_207:
        memset(v120, 0, v118);
        v135 = *(unsigned __int8 *)(a1 + 640);
        *(_DWORD *)(a1 + 268) = 0;
        if ( (_DWORD)v135 )
          printk(unk_38244, "syna_tcm_buf_lock", v135);
        mutex_lock(a1 + 592);
        v137 = *(void **)(a1 + 256);
        ++*(_BYTE *)(a1 + 640);
        if ( v137 )
        {
          v138 = *(_QWORD *)(a1 + 576);
          if ( v138 != -4 )
          {
            v139 = *(_DWORD *)(a1 + 512);
            v140 = (unsigned int)(*(_DWORD *)(a1 + 584) - 4);
            if ( v139 <= *(_DWORD *)(a1 + 264) && v139 <= (unsigned int)v140 )
            {
              memcpy(v137, (const void *)(v138 + 4), *(unsigned int *)(a1 + 512));
              v141 = *(unsigned __int8 *)(a1 + 640);
              *(_DWORD *)(a1 + 268) = *(_DWORD *)(a1 + 512);
              if ( (_DWORD)v141 == 1 )
              {
                v142 = 0;
              }
              else
              {
                printk(unk_38244, "syna_tcm_buf_unlock", v141);
                v142 = *(_BYTE *)(a1 + 640) - 1;
              }
              *(_BYTE *)(a1 + 640) = v142;
              mutex_unlock(a1 + 592);
              v143 = *(unsigned __int8 *)(a1 + 320);
              if ( (_DWORD)v143 == 1 )
              {
                v144 = 0;
              }
              else
              {
                printk(unk_38244, "syna_tcm_buf_unlock", v143);
                v144 = *(_BYTE *)(a1 + 320) - 1;
              }
              *(_BYTE *)(a1 + 320) = v144;
              mutex_unlock(a1 + 272);
              if ( (_DWORD)v113 != 16 )
                goto LABEL_253;
              if ( *(_BYTE *)(a1 + 640) )
                printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 640));
              mutex_lock(a1 + 592);
              v145 = *(_DWORD *)(a1 + 512);
              v146 = (unsigned int)(*(_DWORD *)(a1 + 584) - 4);
              v147 = (const void *)(*(_QWORD *)(a1 + 576) + 4LL);
              ++*(_BYTE *)(a1 + 640);
              if ( (syna_tcm_v1_parse_idinfo(a1, v147, v146, v145) & 0x80000000) != 0 )
              {
                printk(unk_39E78, "syna_tcm_v1_dispatch_report", v148);
                syna_tcm_buf_unlock((__int64)v204);
                if ( !v4 )
                  goto LABEL_340;
                goto LABEL_339;
              }
              v149 = *(unsigned __int8 *)(a1 + 640);
              if ( (_DWORD)v149 == 1 )
              {
                v150 = 0;
              }
              else
              {
                printk(unk_38244, "syna_tcm_buf_unlock", v149);
                v150 = *(_BYTE *)(a1 + 640) - 1;
              }
              *(_BYTE *)(a1 + 640) = v150;
              mutex_unlock(a1 + 592);
              if ( *(_DWORD *)(a1 + 504) != 1 )
              {
LABEL_253:
                v164 = a1 + 16LL * (unsigned int)v113;
                if ( *(_QWORD *)(v164 + 992) )
                {
                  v165 = (__int64 *)(v164 + 984);
                  if ( *(_BYTE *)(a1 + 320) )
                    printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 320));
                  mutex_lock(a1 + 272);
                  v166 = *v165;
                  v167 = (_DWORD *)v165[1];
                  v168 = *(unsigned int *)(a1 + 268);
                  v169 = *(_QWORD *)(a1 + 256);
                  ++*(_BYTE *)(a1 + 320);
                  if ( *(v167 - 1) != -1617705974 )
                    __break(0x8229u);
                  ((void (__fastcall *)(_QWORD, __int64, __int64, __int64))v167)((unsigned int)v113, v169, v168, v166);
LABEL_311:
                  v186 = *(unsigned __int8 *)(a1 + 320);
                  if ( (_DWORD)v186 == 1 )
                  {
                    v187 = 0;
                  }
                  else
                  {
                    printk(unk_38244, "syna_tcm_buf_unlock", v186);
                    v187 = *(_BYTE *)(a1 + 320) - 1;
                  }
                  *(_BYTE *)(a1 + 320) = v187;
                  mutex_unlock(a1 + 272);
                  if ( !v4 )
                  {
LABEL_340:
                    v35 = 0;
                    if ( v5 )
                    {
                      v191 = *(_DWORD *)(a1 + 60);
                      v192 = v191 - 5;
                      if ( *(_DWORD *)(a1 + 512) < (unsigned int)(v191 - 5) )
                        v192 = *(_DWORD *)(a1 + 512);
                      if ( v191 )
                        v193 = v192;
                      else
                        v193 = *(_DWORD *)(a1 + 512);
                      if ( *(unsigned __int8 *)(a1 + 509) < 0x10u )
                        v193 = 0;
                      *(_DWORD *)(a1 + 892) = v193;
                    }
                    goto LABEL_349;
                  }
LABEL_339:
                  *v4 = *(_BYTE *)(a1 + 509);
                  goto LABEL_340;
                }
LABEL_338:
                if ( !v4 )
                  goto LABEL_340;
                goto LABEL_339;
              }
              v151 = *(unsigned __int8 *)(a1 + 508);
              if ( v151 > 0x1E )
              {
                if ( v151 != 31 && v151 != 49 )
                  goto LABEL_249;
              }
              else if ( v151 != 4 && v151 != 20 )
              {
LABEL_249:
                if ( *(_BYTE *)(a1 + 496) == 1 )
                {
                  *(_DWORD *)(a1 + 504) = 0;
                }
                else
                {
                  printk(unk_3B956, "syna_tcm_v1_dispatch_report", 16);
                  *(_DWORD *)(a1 + 504) = -1;
                }
                if ( (completion_done(a1 + 544) & 1) == 0 )
                  complete(a1 + 544);
                goto LABEL_253;
              }
              goto LABEL_335;
            }
            printk(unk_3944E, "syna_pal_mem_cpy", v140);
          }
        }
        printk(unk_32AED, "syna_tcm_v1_dispatch_report", v136);
        v176 = *(unsigned __int8 *)(a1 + 640);
        if ( (_DWORD)v176 == 1 )
        {
          v177 = 0;
        }
        else
        {
          printk(unk_38244, "syna_tcm_buf_unlock", v176);
          v177 = *(_BYTE *)(a1 + 640) - 1;
        }
        *(_BYTE *)(a1 + 640) = v177;
        mutex_unlock(a1 + 592);
        goto LABEL_311;
      }
      if ( v120 )
      {
        v121 = v120;
        v122 = syna_request_managed_device();
        if ( !v122 )
        {
          printk(unk_3BE43, "syna_pal_mem_free", v123);
          v124 = syna_request_managed_device();
          if ( v124 )
            goto LABEL_189;
          goto LABEL_308;
        }
        devm_kfree(v122, v121);
      }
      v124 = syna_request_managed_device();
      if ( v124 )
      {
LABEL_189:
        if ( (int)v118 > 0 )
        {
          v120 = (void *)devm_kmalloc(v124, v118, 3520);
          *(_QWORD *)(a1 + 256) = v120;
          if ( v120 )
          {
            *(_DWORD *)(a1 + 264) = v118;
            goto LABEL_207;
          }
LABEL_310:
          printk(unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v118);
          *(_QWORD *)(a1 + 264) = 0;
          printk(unk_3795A, "syna_tcm_v1_dispatch_report", v185);
          goto LABEL_311;
        }
        v178 = unk_38286;
LABEL_309:
        printk(v178, "syna_pal_mem_alloc", v125);
        *(_QWORD *)(a1 + 256) = 0;
        goto LABEL_310;
      }
LABEL_308:
      v178 = unk_3BE43;
      goto LABEL_309;
    }
    if ( *(_DWORD *)(a1 + 504) != 1 )
      goto LABEL_338;
    v126 = *(_DWORD *)(a1 + 512);
    *(_BYTE *)(a1 + 510) = v113;
    if ( !v126 )
    {
      *(_DWORD *)(a1 + 340) = 0;
      v152 = *(unsigned __int8 *)(a1 + 510);
      if ( !*(_BYTE *)(a1 + 510) )
        goto LABEL_338;
      goto LABEL_334;
    }
    if ( *(_BYTE *)(a1 + 392) )
      printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 392));
    mutex_lock(a1 + 344);
    v127 = *(unsigned int *)(a1 + 512);
    v128 = *(unsigned int *)(a1 + 336);
    v129 = *(void **)(a1 + 328);
    ++*(_BYTE *)(a1 + 392);
    if ( (unsigned int)v128 >= (unsigned int)v127 )
    {
      v127 = v128;
LABEL_231:
      memset(v129, 0, v127);
      v153 = *(unsigned __int8 *)(a1 + 640);
      *(_DWORD *)(a1 + 340) = 0;
      if ( (_DWORD)v153 )
        printk(unk_38244, "syna_tcm_buf_lock", v153);
      mutex_lock(a1 + 592);
      v155 = *(void **)(a1 + 328);
      ++*(_BYTE *)(a1 + 640);
      if ( v155 )
      {
        v156 = *(_QWORD *)(a1 + 576);
        if ( v156 != -4 )
        {
          v157 = *(_DWORD *)(a1 + 512);
          v158 = (unsigned int)(*(_DWORD *)(a1 + 584) - 4);
          if ( v157 <= *(_DWORD *)(a1 + 336) && v157 <= (unsigned int)v158 )
          {
            memcpy(v155, (const void *)(v156 + 4), *(unsigned int *)(a1 + 512));
            v159 = *(unsigned __int8 *)(a1 + 640);
            *(_DWORD *)(a1 + 340) = *(_DWORD *)(a1 + 512);
            if ( (_DWORD)v159 == 1 )
            {
              v160 = 0;
            }
            else
            {
              printk(unk_38244, "syna_tcm_buf_unlock", v159);
              v160 = *(_BYTE *)(a1 + 640) - 1;
            }
            *(_BYTE *)(a1 + 640) = v160;
            mutex_unlock(a1 + 592);
            if ( *(_BYTE *)(a1 + 508) != 2
              || (syna_tcm_v1_parse_idinfo(
                    a1,
                    *(const void **)(a1 + 328),
                    *(unsigned int *)(a1 + 336),
                    *(_DWORD *)(a1 + 340))
                & 0x80000000) == 0 )
            {
              v162 = *(unsigned __int8 *)(a1 + 392);
              if ( (_DWORD)v162 == 1 )
              {
                v163 = 0;
              }
              else
              {
                printk(unk_38244, "syna_tcm_buf_unlock", v162);
                v163 = *(_BYTE *)(a1 + 392) - 1;
              }
              *(_BYTE *)(a1 + 392) = v163;
              mutex_unlock(a1 + 344);
              v152 = *(unsigned __int8 *)(a1 + 510);
              if ( !*(_BYTE *)(a1 + 510) )
                goto LABEL_338;
LABEL_334:
              if ( (_DWORD)v152 != 1 )
              {
                if ( (_DWORD)v152 == 3 )
                {
                  printk(unk_39EA9, "syna_tcm_v1_dispatch_response", v152);
                  if ( !v4 )
                    goto LABEL_340;
                  goto LABEL_339;
                }
                printk(unk_320FD, "syna_tcm_v1_dispatch_response", v152);
                *(_DWORD *)(a1 + 504) = -1;
                goto LABEL_336;
              }
LABEL_335:
              *(_DWORD *)(a1 + 504) = 0;
LABEL_336:
              if ( (completion_done(a1 + 544) & 1) == 0 )
                complete(a1 + 544);
              goto LABEL_338;
            }
            v189 = unk_37999;
            goto LABEL_332;
          }
          printk(unk_3944E, "syna_pal_mem_cpy", v158);
        }
      }
      printk(unk_3AC2B, "syna_tcm_v1_dispatch_response", v154);
      syna_tcm_buf_unlock((__int64)v204);
      goto LABEL_333;
    }
    if ( v129 )
    {
      v130 = v129;
      v131 = syna_request_managed_device();
      if ( !v131 )
      {
        printk(unk_3BE43, "syna_pal_mem_free", v132);
        v133 = syna_request_managed_device();
        if ( v133 )
          goto LABEL_201;
        goto LABEL_329;
      }
      devm_kfree(v131, v130);
    }
    v133 = syna_request_managed_device();
    if ( v133 )
    {
LABEL_201:
      if ( (int)v127 > 0 )
      {
        v129 = (void *)devm_kmalloc(v133, v127, 3520);
        *(_QWORD *)(a1 + 328) = v129;
        if ( v129 )
        {
          *(_DWORD *)(a1 + 336) = v127;
          goto LABEL_231;
        }
LABEL_331:
        printk(unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v127);
        *(_QWORD *)(a1 + 336) = 0;
        v189 = unk_34FAB;
LABEL_332:
        printk(v189, "syna_tcm_v1_dispatch_response", v161);
LABEL_333:
        syna_tcm_buf_unlock(a1 + 328);
        v152 = *(unsigned __int8 *)(a1 + 510);
        if ( !*(_BYTE *)(a1 + 510) )
          goto LABEL_338;
        goto LABEL_334;
      }
      v188 = unk_38286;
LABEL_330:
      printk(v188, "syna_pal_mem_alloc", v134);
      *(_QWORD *)(a1 + 328) = 0;
      goto LABEL_331;
    }
LABEL_329:
    v188 = unk_3BE43;
    goto LABEL_330;
  }
  if ( (_WORD)v37 == 0xFFFF )
  {
    v35 = -241;
    goto LABEL_327;
  }
  v38 = *(unsigned __int8 *)(a1 + 896);
  v39 = *(unsigned __int8 *)(a1 + 900);
  v40 = v23 + 5;
  v41 = v23 + 7;
  v42 = v37 + 3;
  v43 = v38 == 0;
  v44 = v38 | v39;
  v45 = v39 + 1;
  if ( v43 )
    v41 = v40;
  if ( v43 )
    v42 = v37 + 1;
  v46 = v41 + v45;
  v47 = v42 + v45;
  if ( (v44 & 1) != 0 )
    v48 = v46;
  else
    v48 = v40;
  if ( (v44 & 1) != 0 )
    v49 = v47;
  else
    v49 = v37 + 1;
  v200 = v37;
  if ( *(_BYTE *)(a1 + 640) )
    printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 640));
  mutex_lock(a1 + 592);
  v50 = *(unsigned int *)(a1 + 584);
  v51 = v48 + 1;
  ++*(_BYTE *)(a1 + 640);
  if ( (unsigned int)v50 < v48 + 1 )
  {
    v52 = *v204;
    v53 = syna_request_managed_device();
    if ( v53 )
    {
      if ( v48 < 0x7FFFFFFF )
      {
        v55 = (void *)devm_kmalloc(v53, v48 + 1, 3520);
        *v204 = v55;
        if ( v55 )
        {
          if ( v52 )
          {
            memcpy(v55, v52, v50);
            v57 = syna_request_managed_device();
            if ( v57 )
              devm_kfree(v57, v52);
            else
              printk(unk_3BE43, "syna_pal_mem_free", v58);
            *v12 = v51;
            goto LABEL_81;
          }
          printk(unk_31A9A, "syna_tcm_buf_realloc", v56);
          if ( !syna_request_managed_device() )
            printk(unk_3BE43, "syna_pal_mem_free", v183);
          v184 = *v204;
          v180 = syna_request_managed_device();
          if ( !v180 )
            goto LABEL_292;
          if ( !v184 )
            goto LABEL_326;
          v182 = v184;
          goto LABEL_325;
        }
LABEL_291:
        printk(unk_3703C, "syna_tcm_buf_realloc", v51);
        v180 = syna_request_managed_device();
        if ( !v180 )
        {
LABEL_292:
          printk(unk_3BE43, "syna_pal_mem_free", v181);
LABEL_326:
          *v12 = 0;
          printk(unk_3ABF0, "syna_tcm_v1_continued_read", v181);
          syna_tcm_buf_unlock((__int64)v204);
          v37 = v200;
          v35 = -243;
          goto LABEL_327;
        }
        if ( !v52 )
          goto LABEL_326;
        v182 = v52;
LABEL_325:
        devm_kfree(v180, v182);
        goto LABEL_326;
      }
      v179 = unk_38286;
    }
    else
    {
      v179 = unk_3BE43;
    }
    printk(v179, "syna_pal_mem_alloc", v54);
    *v204 = nullptr;
    goto LABEL_291;
  }
LABEL_81:
  v59 = *(_QWORD *)(a1 + 72);
  v60 = *(_DWORD *)(a1 + 60);
  if ( !v60 )
    v60 = v48;
  if ( *(_BYTE *)(v59 + 21) != 1 )
  {
    v61 = v200;
    v62 = v60;
    if ( !v60 )
      goto LABEL_87;
    goto LABEL_90;
  }
  v61 = v200;
  v62 = 0;
  if ( !v60 )
  {
    v64 = 0;
    goto LABEL_100;
  }
  v63 = *(_DWORD *)(v59 + 24);
  v64 = 0;
  if ( v63 )
  {
    v62 = v60 / v63 * v63;
    if ( !v62 )
    {
LABEL_87:
      v64 = 0;
      goto LABEL_100;
    }
LABEL_90:
    v64 = (v48 + v62 - 1) / v62;
  }
LABEL_100:
  v198 = v5;
  if ( v64 <= 1 )
    v69 = 1;
  else
    v69 = v64;
  v199 = v4;
  v70 = *(_DWORD *)(a1 + 512) - v61 + 4;
  if ( *(_BYTE *)(a1 + 784) )
    printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 784));
  mutex_lock(a1 + 736);
  v71 = 0;
  v72 = 0;
  v73 = v62 - 2;
  v74 = 255;
  v201 = v62 - 2;
  v202 = v62;
  ++*(_BYTE *)(a1 + 784);
  while ( 1 )
  {
    v75 = v71 + 1;
    v76 = v49 <= v62 ? v49 : v73;
    if ( v76 != 1 )
      break;
    --v49;
    *((_BYTE *)*v204 + v70++) = 90;
LABEL_107:
    ++v71;
    if ( v75 >= v69 )
    {
      v98 = 0;
      v35 = 0;
      *(_DWORD *)(a1 + 588) = v70;
      goto LABEL_152;
    }
  }
  if ( v75 == v69 )
  {
    v77 = *(_QWORD *)(a1 + 72);
    if ( (*(_BYTE *)(v77 + 21) & 1) != 0 && v76 > *(_DWORD *)(v77 + 28) )
    {
      v78 = *(_DWORD *)(v77 + 24);
      if ( v78 )
        v78 *= v76 / v78;
      v76 = v78 - 2;
      if ( v78 - 2 != v49 )
        ++v69;
    }
  }
  v79 = *(unsigned int *)(a1 + 728);
  v203 = v69;
  v80 = v76 + 2;
  v81 = *(void **)(a1 + 720);
  if ( (unsigned int)v79 >= v76 + 2 )
    goto LABEL_127;
  if ( !v81 )
  {
LABEL_123:
    v84 = syna_request_managed_device();
    if ( v84 )
      goto LABEL_124;
LABEL_150:
    v97 = unk_3BE43;
LABEL_321:
    printk(v97, "syna_pal_mem_alloc", v85);
    *(_QWORD *)(a1 + 720) = 0;
    goto LABEL_322;
  }
  v82 = syna_request_managed_device();
  if ( v82 )
  {
    devm_kfree(v82, v81);
    goto LABEL_123;
  }
  printk(unk_3BE43, "syna_pal_mem_free", v83);
  v84 = syna_request_managed_device();
  if ( !v84 )
    goto LABEL_150;
LABEL_124:
  if ( (int)v80 <= 0 )
  {
    v97 = unk_38286;
    goto LABEL_321;
  }
  v86 = devm_kmalloc(v84, v76 + 2, 3520);
  *(_QWORD *)(a1 + 720) = v86;
  if ( !v86 )
  {
LABEL_322:
    printk(unk_3703C, "syna_tcm_buf_alloc", v80);
    *(_QWORD *)(a1 + 728) = 0;
    printk(unk_3D392, "syna_tcm_v1_continued_read", v190);
    v35 = -243;
    v98 = 1;
    goto LABEL_152;
  }
  v81 = (void *)v86;
  v79 = v76 + 2;
  *(_DWORD *)(a1 + 728) = v80;
LABEL_127:
  memset(v81, 0, v79);
  *(_DWORD *)(a1 + 732) = 0;
  if ( v72 + 1 > 5 )
    v87 = v72 + 1;
  else
    v87 = 5;
  do
  {
    v88 = *(unsigned int *)(a1 + 528);
    if ( (int)v88 >= 1 )
    {
      v89 = *(_DWORD *)(a1 + 532);
      if ( v89 >= 1 )
      {
        if ( v89 <= (unsigned int)v88 )
          v90 = (unsigned int)v88;
        else
          v90 = (unsigned int)v89;
        usleep_range_state(v88, v90, 2);
      }
    }
    if ( (syna_tcm_v1_read(a1, v80, *(_QWORD *)(a1 + 720), *(unsigned int *)(a1 + 728)) & 0x80000000) != 0 )
    {
      printk(unk_37206, "syna_tcm_v1_continued_read", v80);
    }
    else
    {
      v92 = *(_QWORD *)(a1 + 720);
      *(_DWORD *)(a1 + 732) = v80;
      v74 = *(unsigned __int8 *)(v92 + 1);
      if ( v74 == 3 )
      {
        v62 = v202;
        v94 = (const void *)(v92 + 2);
        if ( v92 == -2 )
        {
LABEL_300:
          printk(unk_3C094, "syna_tcm_v1_continued_read", v91);
          v35 = -22;
          v98 = 1;
          goto LABEL_152;
        }
LABEL_145:
        v95 = (char *)*v204 + v70;
        if ( v95 )
        {
          v96 = (unsigned int)(*(_DWORD *)(a1 + 728) - 2);
          if ( v76 <= (unsigned int)v96 && v76 <= *(_DWORD *)(a1 + 584) - v70 )
          {
            memcpy(v95, v94, v76);
            v69 = v203;
            v73 = v201;
            v70 += v76;
            v49 -= v76;
            v74 = 3;
            goto LABEL_107;
          }
          printk(unk_3944E, "syna_pal_mem_cpy", v96);
        }
        goto LABEL_300;
      }
    }
    ++v72;
  }
  while ( v72 < 5 );
  v62 = v202;
  if ( v74 == 3 )
  {
    v93 = *(_QWORD *)(a1 + 720);
    v72 = v87;
    v94 = (const void *)(v93 + 2);
    if ( v93 == -2 )
      goto LABEL_300;
    goto LABEL_145;
  }
  printk(unk_3563C, "syna_tcm_v1_continued_read", v74);
  v35 = -242;
  v98 = 1;
LABEL_152:
  v99 = *(unsigned __int8 *)(a1 + 784);
  v4 = v199;
  v5 = v198;
  if ( (_DWORD)v99 == 1 )
  {
    v100 = 0;
  }
  else
  {
    printk(unk_38244, "syna_tcm_buf_unlock", v99);
    v100 = *(_BYTE *)(a1 + 784) - 1;
  }
  *(_BYTE *)(a1 + 784) = v100;
  mutex_unlock(a1 + 736);
  v101 = *(unsigned __int8 *)(a1 + 640);
  if ( (_DWORD)v101 == 1 )
  {
    v102 = 0;
  }
  else
  {
    printk(unk_38244, "syna_tcm_buf_unlock", v101);
    v102 = *(_BYTE *)(a1 + 640) - 1;
  }
  *(_BYTE *)(a1 + 640) = v102;
  mutex_unlock(a1 + 592);
  v37 = v200;
  if ( !v98 )
    goto LABEL_157;
LABEL_327:
  printk(unk_3ABA5, "syna_tcm_v1_read_message", v37);
LABEL_349:
  v194 = *(unsigned int *)(a1 + 528);
  if ( (int)v194 >= 1 )
  {
    v195 = *(_DWORD *)(a1 + 532);
    if ( v195 >= 1 )
    {
      if ( v195 <= (unsigned int)v194 )
        v196 = (unsigned int)v194;
      else
        v196 = (unsigned int)v195;
      usleep_range_state(v194, v196, 2);
    }
  }
  mutex_unlock(a1 + 840);
  return v35;
}
