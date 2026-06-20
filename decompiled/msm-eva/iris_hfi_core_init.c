__int64 __fastcall iris_hfi_core_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  const char *v4; // x24
  char **v5; // x25
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 context_bank; // x0
  __int64 v10; // x3
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v13; // x2
  unsigned __int64 v14; // x8
  __int64 v15; // x1
  __int64 v16; // x2
  void *v17; // x0
  unsigned int v18; // w21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  __int64 v22; // x2
  unsigned __int64 v23; // x8
  __int64 v24; // x2
  unsigned __int64 v25; // x8
  __int64 v26; // x2
  unsigned __int64 v27; // x8
  __int64 v28; // x27
  unsigned __int64 v29; // x26
  __int64 v30; // x8
  int v31; // w20
  const char *v32; // x2
  unsigned __int64 *v33; // x21
  unsigned __int64 v34; // x0
  __int64 v35; // x8
  unsigned __int64 v36; // x11
  _QWORD *v37; // x21
  __int64 v38; // x3
  __int64 v39; // x8
  int v40; // w20
  unsigned __int64 v41; // x0
  __int64 v42; // x8
  __int64 *v43; // x22
  __int64 v44; // x28
  int v45; // w8
  unsigned __int64 v46; // x8
  void *v47; // x0
  __int64 v48; // x8
  unsigned __int64 v49; // x28
  void *v50; // x0
  _QWORD *v51; // x20
  __int64 v52; // x8
  unsigned __int64 v53; // x0
  const char *v54; // x1
  __int64 v55; // x8
  unsigned __int64 v56; // x11
  unsigned __int64 v57; // x20
  const char **v58; // x28
  const char *v59; // x22
  const char *v60; // x27
  __int64 v61; // x3
  __int64 v62; // x0
  unsigned __int64 v63; // x8
  __int64 pkt_ops_handle; // x0
  __int64 v65; // x1
  __int64 v66; // x2
  __int64 v67; // x3
  unsigned int v68; // w0
  void *v69; // x0
  __int64 v70; // x8
  unsigned __int64 v71; // x11
  _QWORD *v72; // x24
  unsigned int v73; // w0
  __int64 v74; // x1
  __int64 v75; // x2
  void *v76; // x0
  __int64 v77; // x8
  unsigned __int64 v78; // x11
  _QWORD *v79; // x20
  unsigned __int64 v81; // x8
  unsigned int v82; // w0
  char v83; // w9
  __int64 v84; // x8
  const char *v85; // x26
  int v86; // w21
  __int64 v87; // x22
  void *v88; // x0
  int v89; // w20
  int v90; // w24
  __int64 v91; // x23
  int v92; // w11
  __int64 v93; // x12
  int v94; // w11
  __int64 v95; // x12
  _QWORD *v96; // x8
  __int64 v97; // x8
  int v98; // w10
  _DWORD *v99; // x8
  int v100; // w9
  int v101; // w10
  void *v102; // x0
  unsigned __int64 v103; // x20
  __int64 v104; // x1
  __int64 v105; // x2
  void *v106; // x0
  int v107; // w8
  __int64 v108; // x9
  _DWORD *v109; // x8
  void *v110; // x0
  __int64 v111; // x20
  char **v112; // x27
  void *v113; // x0
  __int64 v114; // x3
  unsigned int fw; // w0
  unsigned __int64 v116; // x8
  _DWORD *v117; // x23
  int v118; // w21
  unsigned __int64 v119; // x0
  __int64 v120; // x3
  int v121; // w9
  int v122; // w8
  unsigned __int64 v123; // x21
  __int64 v124; // x0
  __int64 v125; // x22
  const char **v126; // x23
  unsigned __int64 v127; // x20
  char v128; // w0
  void *v129; // x0
  __int64 v130; // x9
  int v131; // w0
  _DWORD **v132; // x8
  _DWORD *v133; // x8
  unsigned int v134; // w0
  int v135; // w8
  __int64 v136; // x0
  __int64 v137; // x8
  __int64 v138; // x25
  __int64 v139; // x21
  unsigned int *v140; // x24
  _DWORD *v141; // x20
  _DWORD *v142; // x28
  __int64 v143; // x22
  __int64 v144; // x23
  __int64 v145; // x8
  int v146; // w8
  int v147; // w9
  __int64 v148; // x22
  char **v149; // x28
  unsigned int *v150; // x21
  __int64 v151; // x8
  unsigned int (*v152)(void); // x8
  __int64 v153; // x1
  __int64 v154; // x2
  __int64 v155; // x3
  __int64 v156; // x1
  __int64 v157; // x2
  __int64 v158; // x3
  __int64 v159; // x8
  __int64 v160; // x20
  unsigned __int64 v161; // x21
  unsigned __int64 v162; // x27
  __int64 cpu_device; // x0
  __int64 v164; // x0
  __int64 v165; // x2
  __int64 v166; // x3
  char v167; // w24
  const char *v168; // x0
  const char *v169; // x2
  __int64 v170; // x0
  int v171; // w23
  __int64 v172; // x8
  bool v173; // zf
  __int64 v174; // x8
  int v175; // w8
  unsigned __int64 v176; // x20
  __int64 v177; // x21
  __int64 (__fastcall *v178)(_QWORD, _QWORD, _QWORD, _QWORD); // x0
  unsigned __int64 v179; // [xsp+8h] [xbp-28h]
  __int64 v180; // [xsp+10h] [xbp-20h] BYREF
  int v181; // [xsp+18h] [xbp-18h]
  unsigned int v182; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v183[2]; // [xsp+20h] [xbp-10h] BYREF

  v4 = (const char *)&unk_1000;
  v5 = off_6C000;
  v183[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v182 = 0;
  v181 = 0;
  v180 = 0;
  if ( !a1 )
  {
    v18 = -19;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8E92C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    goto LABEL_198;
  }
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    printk(&unk_8F3BA, "core", a3, a4);
  pm_stay_awake(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 256LL) + 112LL));
  mutex_lock(a1 + 80);
  v7 = _kmalloc_cache_noprof(printk, 3520, 20);
  while ( 2 )
  {
    *(_QWORD *)(a1 + 56) = v7;
    if ( !v7 )
    {
      v18 = -12;
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
      {
        v20 = _ReadStatusReg(SP_EL0);
        printk(&unk_8E954, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
      }
      goto LABEL_194;
    }
    v8 = *(_QWORD *)(a1 + 2208);
    *(_DWORD *)(v7 + 12) = 2;
    *(_DWORD *)(a1 + 64) = 1;
    context_bank = msm_cvp_smem_get_context_bank(v8, 0);
    if ( !context_bank )
    {
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
      {
        v21 = _ReadStatusReg(SP_EL0);
        printk(&unk_87695, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
      }
      goto LABEL_41;
    }
    v11 = *(_QWORD *)(a1 + 2208);
    v12 = context_bank;
    v13 = *(_QWORD *)(v11 + 56);
    if ( v13 )
    {
      if ( (unsigned int)iommu_map(
                           *(_QWORD *)(context_bank + 48),
                           *(_QWORD *)(v11 + 48),
                           v13,
                           *(unsigned int *)(v11 + 64),
                           3,
                           0) )
      {
        if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
        {
          v14 = _ReadStatusReg(SP_EL0);
          v15 = *(unsigned int *)(v14 + 1800);
          v16 = *(unsigned int *)(v14 + 1804);
          v17 = &unk_82DBC;
LABEL_40:
          printk(v17, v15, v16, &unk_8E7CE);
          goto LABEL_41;
        }
        goto LABEL_41;
      }
      v11 = *(_QWORD *)(a1 + 2208);
    }
    v22 = *(_QWORD *)(v11 + 80);
    if ( !v22 )
    {
LABEL_29:
      v24 = *(_QWORD *)(v11 + 104);
      if ( v24 )
      {
        if ( (unsigned int)iommu_map(
                             *(_QWORD *)(v12 + 48),
                             *(_QWORD *)(v11 + 96),
                             v24,
                             *(unsigned int *)(v11 + 112),
                             19,
                             0) )
        {
          if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
          {
            v25 = _ReadStatusReg(SP_EL0);
            v15 = *(unsigned int *)(v25 + 1800);
            v16 = *(unsigned int *)(v25 + 1804);
            v17 = &unk_94E49;
            goto LABEL_40;
          }
          goto LABEL_41;
        }
        v11 = *(_QWORD *)(a1 + 2208);
      }
      v26 = *(_QWORD *)(v11 + 128);
      if ( v26
        && (unsigned int)iommu_map(
                           *(_QWORD *)(v12 + 48),
                           *(_QWORD *)(v11 + 120),
                           v26,
                           *(unsigned int *)(v11 + 136),
                           19,
                           0)
        && (v4[3992] & 1) != 0
        && !*((_DWORD *)v5 + 366) )
      {
        v27 = _ReadStatusReg(SP_EL0);
        v15 = *(unsigned int *)(v27 + 1800);
        v16 = *(unsigned int *)(v27 + 1804);
        v17 = &unk_94281;
        goto LABEL_40;
      }
      goto LABEL_41;
    }
    if ( !(unsigned int)iommu_map(*(_QWORD *)(v12 + 48), *(_QWORD *)(v11 + 72), v22, *(unsigned int *)(v11 + 88), 19, 0) )
    {
      v11 = *(_QWORD *)(a1 + 2208);
      goto LABEL_29;
    }
    if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
    {
      v23 = _ReadStatusReg(SP_EL0);
      v15 = *(unsigned int *)(v23 + 1800);
      v16 = *(unsigned int *)(v23 + 1804);
      v17 = &unk_83964;
      goto LABEL_40;
    }
LABEL_41:
    v28 = *(_QWORD *)(a1 + 2208);
    v29 = _ReadStatusReg(SP_EL0);
    v30 = *(_QWORD *)(a1 + 2208);
    if ( *(_DWORD *)(v30 + 464) )
    {
      if ( (v4[3992] & 4) != 0 && !*((_DWORD *)v5 + 366) )
      {
        v31 = 0;
        v32 = "__init_regulators";
LABEL_45:
        printk(&unk_92F1F, "info", v32, v10);
        goto LABEL_62;
      }
    }
    else
    {
      v33 = *(unsigned __int64 **)(v30 + 264);
      if ( v33 < &v33[3 * *(unsigned int *)(v30 + 272)] )
      {
        while ( 1 )
        {
          v34 = regulator_get(*(_QWORD *)(v30 + 256) + 16LL, v33[2]);
          *v33 = v34;
          if ( !v34 || v34 >= 0xFFFFFFFFFFFFF001LL )
            break;
          v30 = *(_QWORD *)(a1 + 2208);
          v33 += 3;
          if ( (unsigned __int64)v33 >= *(_QWORD *)(v30 + 264) + 24 * (unsigned __int64)*(unsigned int *)(v30 + 272) )
            goto LABEL_66;
        }
        if ( v34 )
          v31 = v34;
        else
          v31 = -521;
        if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
          printk(&unk_88B3F, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
        *v33 = 0;
        v35 = *(_QWORD *)(a1 + 2208);
        if ( *(_DWORD *)(v35 + 464) )
        {
          if ( (v4[3992] & 4) != 0 && !*((_DWORD *)v5 + 366) )
          {
            v32 = "__deinit_regulators";
            goto LABEL_45;
          }
        }
        else
        {
          v36 = *(_QWORD *)(v35 + 264);
          v37 = (_QWORD *)(v36 + 24LL * (unsigned int)(*(_DWORD *)(v35 + 272) - 1));
          if ( (unsigned __int64)v37 >= v36 )
          {
            do
            {
              if ( *v37 )
              {
                regulator_put();
                *v37 = 0;
                v35 = *(_QWORD *)(a1 + 2208);
              }
              v37 -= 3;
            }
            while ( (unsigned __int64)v37 >= *(_QWORD *)(v35 + 264) );
          }
        }
LABEL_62:
        if ( v31 )
        {
          v18 = -19;
          if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
            printk(&unk_9216B, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
          goto LABEL_188;
        }
      }
    }
LABEL_66:
    if ( (unsigned int)msm_cvp_init_clocks(a1) )
    {
      v18 = -19;
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
        printk(&unk_921A1, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
      goto LABEL_183;
    }
    v39 = *(_QWORD *)(a1 + 2208);
    if ( *(_DWORD *)(v39 + 320) )
    {
      v40 = 0;
      while ( 1 )
      {
        v42 = *(_QWORD *)(v28 + 312);
        if ( !v42 )
          goto LABEL_77;
        v43 = (__int64 *)(v42 + 24LL * v40);
        v44 = *v43;
        if ( (msm_cvp_debug & 0x400) != 0 && !*((_DWORD *)v5 + 366) )
        {
          printk(&unk_860D3, &unk_8DA84, *(_QWORD *)(v42 + 24LL * v40 + 16), *v43);
          if ( v44 )
            goto LABEL_77;
        }
        else if ( v44 )
        {
          goto LABEL_77;
        }
        v45 = *((_DWORD *)v43 + 2);
        if ( v45 )
        {
          if ( v45 != 1 )
          {
            if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v5 + 366) )
              printk(&unk_8E993, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
            goto LABEL_174;
          }
          v41 = _reset_control_get(
                  *(_QWORD *)(v28 + 256) + 16LL,
                  *(_QWORD *)(*(_QWORD *)(v28 + 312) + 24LL * v40 + 16),
                  0,
                  0,
                  0,
                  0);
          if ( v41 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v5 + 366) )
            {
              v46 = v29;
              v47 = &unk_86111;
              goto LABEL_101;
            }
            goto LABEL_174;
          }
          if ( (msm_cvp_debug & 0x400) == 0 || *((_DWORD *)v5 + 366) )
            goto LABEL_76;
          v48 = *(_QWORD *)(v28 + 312);
          v49 = v41;
          v50 = &unk_8F3DD;
        }
        else
        {
          v41 = _devm_reset_control_get(
                  *(_QWORD *)(v28 + 256) + 16LL,
                  *(_QWORD *)(*(_QWORD *)(v28 + 312) + 24LL * v40 + 16),
                  0,
                  0,
                  0,
                  1);
          if ( v41 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (msm_cvp_debug & 1) == 0 || *((_DWORD *)v5 + 366) )
              goto LABEL_174;
            v46 = v29;
            v47 = &unk_86C02;
LABEL_101:
            printk(v47, *(unsigned int *)(v46 + 1800), *(unsigned int *)(v46 + 1804), &unk_8E7CE);
LABEL_174:
            v4 = (const char *)&unk_1000;
            v18 = -19;
            if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v5 + 366) )
              printk(&unk_8DB6D, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
LABEL_182:
            msm_cvp_deinit_clocks(a1);
LABEL_183:
            v77 = *(_QWORD *)(a1 + 2208);
            if ( *(_DWORD *)(v77 + 464) )
            {
              if ( (v4[3992] & 4) != 0 && !*((_DWORD *)v5 + 366) )
                printk(&unk_92F1F, "info", "__deinit_regulators", v38);
            }
            else
            {
              v78 = *(_QWORD *)(v77 + 264);
              v79 = (_QWORD *)(v78 + 24LL * (unsigned int)(*(_DWORD *)(v77 + 272) - 1));
              if ( (unsigned __int64)v79 >= v78 )
              {
                do
                {
                  if ( *v79 )
                  {
                    regulator_put();
                    *v79 = 0;
                    v77 = *(_QWORD *)(a1 + 2208);
                  }
                  v79 -= 3;
                }
                while ( (unsigned __int64)v79 >= *(_QWORD *)(v77 + 264) );
                goto LABEL_142;
              }
            }
LABEL_188:
            if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
            {
              printk(&unk_942B8, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
              if ( (v4[3992] & 1) == 0 )
                goto LABEL_193;
            }
            else if ( (v4[3992] & 1) == 0 )
            {
              goto LABEL_193;
            }
LABEL_191:
            if ( !*((_DWORD *)v5 + 366) )
              printk(&unk_93A74, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
            goto LABEL_193;
          }
          if ( (msm_cvp_debug & 0x400) == 0 || *((_DWORD *)v5 + 366) )
            goto LABEL_76;
          v48 = *(_QWORD *)(v28 + 312);
          v49 = v41;
          v50 = &unk_8399D;
        }
        printk(v50, &unk_8DA84, *(_QWORD *)(v48 + 24LL * v40 + 16), v49);
        v41 = v49;
LABEL_76:
        *(_QWORD *)(*(_QWORD *)(v28 + 312) + 24LL * v40) = v41;
        *((_DWORD *)v43 + 3) = 0;
LABEL_77:
        v39 = *(_QWORD *)(a1 + 2208);
        if ( (unsigned int)++v40 >= *(_DWORD *)(v39 + 320) )
        {
          v4 = (const char *)&unk_1000;
          break;
        }
      }
    }
    v51 = *(_QWORD **)(v39 + 296);
    if ( v51 < &v51[15 * *(unsigned int *)(v39 + 304)] )
    {
      while ( 1 )
      {
        v52 = v51[3];
        if ( *(_QWORD *)(v52 + 152) )
        {
          v54 = *(const char **)(v52 + 112);
          if ( !v54 )
            v54 = *(const char **)v52;
          _warn_printk("%s's drvdata already set\n", v54);
          __break(0x800u);
          v52 = v51[3];
        }
        *(_QWORD *)(v52 + 152) = a1;
        v53 = of_icc_get(v51[3], *v51);
        v51[13] = v53;
        if ( !v53 || v53 >= 0xFFFFFFFFFFFFF001LL )
          break;
        v39 = *(_QWORD *)(a1 + 2208);
        v51 += 15;
        if ( (unsigned __int64)v51 >= *(_QWORD *)(v39 + 296) + 120 * (unsigned __int64)*(unsigned int *)(v39 + 304) )
          goto LABEL_123;
      }
      if ( v53 )
        v18 = v53;
      else
        v18 = -521;
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
        printk(&unk_909A4, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
      v51[13] = 0;
      kfree(*(_QWORD *)(a1 + 56));
      v55 = *(_QWORD *)(a1 + 2208);
      *(_QWORD *)(a1 + 56) = 0;
      *(_QWORD *)(a1 + 64) = 0;
      v56 = *(_QWORD *)(v55 + 296);
      v57 = v56 + 120LL * (unsigned int)(*(_DWORD *)(v55 + 304) - 1);
      if ( v57 >= v56 )
      {
        do
        {
          *(_QWORD *)(*(_QWORD *)(v57 + 24) + 152LL) = 0;
          icc_put(*(_QWORD *)(v57 + 104));
          *(_QWORD *)(v57 + 104) = 0;
          v57 -= 120LL;
        }
        while ( v57 >= *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 296LL) );
      }
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
        printk(&unk_82DF5, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
      goto LABEL_182;
    }
LABEL_123:
    if ( *(_BYTE *)(v39 + 192) != 1
      || (v58 = *(const char ***)(v39 + 200), v58 >= &v58[3 * *(unsigned int *)(v39 + 208)]) )
    {
      v18 = 0;
      goto LABEL_141;
    }
    v59 = v4;
    while ( 1 )
    {
      v60 = *v58;
      if ( !strcmp("cvp", *v58) )
      {
        v62 = 28;
LABEL_134:
        v58[2] = (const char *)llcc_slice_getd(v62);
        goto LABEL_135;
      }
      if ( !strcmp("cvpfw", v60) )
      {
        v62 = 32;
        goto LABEL_134;
      }
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
        printk(&unk_86146, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
LABEL_135:
      v63 = (unsigned __int64)v58[2];
      if ( !v63 || v63 >= 0xFFFFFFFFFFFFF001LL )
        break;
      if ( (msm_cvp_debug & 0x100) != 0 && !*((_DWORD *)v5 + 366) )
        printk(&unk_857EB, "core", *v58, v61);
      v58 += 3;
      if ( (unsigned __int64)v58 >= *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 200LL)
                                  + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 208LL) )
      {
        v18 = 0;
        goto LABEL_141;
      }
    }
    if ( v63 )
      v18 = (unsigned int)v58[2];
    else
      v18 = -521;
    if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
      printk(&unk_84E2E, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
    v58[2] = nullptr;
    v70 = *(_QWORD *)(a1 + 2208);
    if ( *(_BYTE *)(v70 + 192) == 1 )
    {
      v71 = *(_QWORD *)(v70 + 200);
      v72 = (_QWORD *)(v71 + 24LL * (unsigned int)(*(_DWORD *)(v70 + 208) - 1));
      if ( (unsigned __int64)v72 >= v71 )
      {
        do
        {
          if ( v72[2] )
          {
            if ( (msm_cvp_debug & 0x100) != 0 && !*((_DWORD *)v5 + 366) )
              printk(&unk_96346, "core", *v72, v61);
            llcc_slice_putd();
            v72[2] = 0;
            v70 = *(_QWORD *)(a1 + 2208);
          }
          v72 -= 3;
        }
        while ( (unsigned __int64)v72 >= *(_QWORD *)(v70 + 200) );
      }
    }
    v4 = v59;
    if ( (v59[3992] & 2) != 0 && !*((_DWORD *)v5 + 366) )
      printk(&unk_913F1, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), "warn");
LABEL_141:
    *(_QWORD *)(a1 + 2504) = _kmalloc_large_noprof(23424, 3520);
LABEL_142:
    if ( v18 )
      goto LABEL_188;
    if ( !*(_QWORD *)(a1 + 2208) )
    {
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
        printk(&unk_8BC06, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
LABEL_155:
      v18 = -22;
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
      {
        v69 = &unk_86097;
LABEL_222:
        printk(v69, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
      }
LABEL_157:
      _deinit_resources(a1);
      if ( (v4[3992] & 1) == 0 )
        goto LABEL_193;
      goto LABEL_191;
    }
    *(_DWORD *)(a1 + 2424) = 0;
    pkt_ops_handle = cvp_hfi_get_pkt_ops_handle(0);
    *(_QWORD *)(a1 + 2416) = pkt_ops_handle;
    if ( !pkt_ops_handle )
    {
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
        printk(&unk_82512, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
      goto LABEL_155;
    }
    v68 = _iris_power_on(a1, v65, v66, v67);
    if ( v68 )
    {
      v18 = v68;
      if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
      {
        v69 = &unk_95896;
        goto LABEL_222;
      }
      goto LABEL_157;
    }
    v73 = synx_recover(8);
    if ( !v73 )
    {
      if ( msm_cvp_mmrm_enabled == 1 )
      {
        v82 = msm_cvp_mmrm_register(a1);
        if ( v82 )
        {
          v18 = v82;
          if ( (v4[3992] & 1) == 0 || *((_DWORD *)v5 + 366) )
            goto LABEL_338;
          v74 = *(unsigned int *)(v29 + 1800);
          v75 = *(unsigned int *)(v29 + 1804);
          v76 = &unk_8A704;
          goto LABEL_181;
        }
      }
      *(_BYTE *)(a1 + 73) = 0;
      v83 = BYTE1(msm_cvp_debug);
      *(_DWORD *)(a1 + 2408) = 2;
      if ( (v83 & 1) != 0 && !*((_DWORD *)v5 + 366) )
        printk(&unk_96318, "core", *(_QWORD *)(a1 + 2168) + 8LL, *(_QWORD *)(*(_QWORD *)(a1 + 2168) + 16LL));
      v84 = *(_QWORD *)(a1 + 2208);
      v179 = v29;
      v85 = v4;
      v86 = *(_DWORD *)(v84 + 240);
      if ( *(_QWORD *)(v84 + 336) == v84 + 336 )
        v87 = *(_QWORD *)(*(_QWORD *)(a1 + 2168) + 8LL);
      else
        LODWORD(v87) = 0;
      v88 = *(void **)(a1 + 144);
      if ( v88 )
      {
        memset(v88, 0, 0x2FF000u);
        v89 = *(_DWORD *)(a1 + 152);
        v90 = *(_DWORD *)(a1 + 136);
        v91 = *(_QWORD *)(a1 + 144);
      }
      else
      {
        if ( (unsigned int)_smem_alloc(a1, a1 + 840, 3141632, 0) )
        {
          v103 = v179;
          if ( (v4[3992] & 1) == 0 || *((_DWORD *)v5 + 366) )
            goto LABEL_334;
          v104 = *(unsigned int *)(v179 + 1800);
          v105 = *(unsigned int *)(v179 + 1804);
          v106 = &unk_8A750;
LABEL_368:
          printk(v106, v104, v105, &unk_8E7CE);
          if ( (v4[3992] & 1) != 0 )
          {
LABEL_335:
            if ( !*((_DWORD *)v5 + 366) )
              printk(&unk_8B1CC, *(unsigned int *)(v103 + 1800), *(unsigned int *)(v103 + 1804), &unk_8E7CE);
          }
LABEL_337:
          power_off_iris2(a1);
          _deinit_resources(a1);
          v18 = -12;
          goto LABEL_338;
        }
        v91 = *(_QWORD *)(a1 + 848);
        v89 = 456;
        v90 = *(_DWORD *)(a1 + 840) - v87;
        *(_QWORD *)(a1 + 144) = v91;
        *(_DWORD *)(a1 + 136) = v90;
        *(_DWORD *)(a1 + 152) = 456;
        memcpy((void *)(a1 + 160), (const void *)(a1 + 864), 0x98u);
      }
      *(_DWORD *)(a1 + 1032) = v89 + v90;
      *(_QWORD *)(a1 + 1040) = v91 + v89;
      *(_QWORD *)(a1 + 1024) = v91 + 288;
      *(_DWORD *)(a1 + 1048) = 819200;
      *(_DWORD *)(v91 + 288) = 1;
      *(_QWORD *)(v91 + 296) = 0x3200001010000LL;
      *(_DWORD *)(v91 + 304) = 0;
      *(_QWORD *)(v91 + 312) = 0x100000001LL;
      *(_DWORD *)(v91 + 320) = 1;
      *(_QWORD *)(v91 + 324) = 0;
      *(_QWORD *)(v91 + 332) = 0;
      *(_DWORD *)(v91 + 340) = 0;
      v92 = *(_DWORD *)(a1 + 136);
      v93 = *(_QWORD *)(a1 + 144);
      *(_DWORD *)(a1 + 1016) = 0;
      *(_DWORD *)(a1 + 1240) = 819200;
      *(_DWORD *)(a1 + 1224) = v92 + v89 + 819200;
      *(_QWORD *)(a1 + 1216) = v93 + 344;
      *(_QWORD *)(a1 + 1232) = v93 + v89 + 819200;
      *(_DWORD *)(v93 + 344) = 1;
      *(_QWORD *)(v93 + 352) = 0x3200001010000LL;
      *(_DWORD *)(v93 + 360) = 0;
      *(_QWORD *)(v93 + 368) = 0x100000001LL;
      *(_DWORD *)(v93 + 376) = 1;
      *(_QWORD *)(v93 + 380) = 0;
      *(_QWORD *)(v93 + 388) = 0;
      *(_DWORD *)(v93 + 396) = 0;
      v94 = *(_DWORD *)(a1 + 136);
      v95 = *(_QWORD *)(a1 + 144);
      *(_DWORD *)(a1 + 1208) = 0;
      *(_DWORD *)(a1 + 1432) = 819200;
      *(_DWORD *)(a1 + 1416) = v94 + v89 + 1638400;
      *(_QWORD *)(a1 + 1424) = v95 + v89 + 1638400;
      *(_QWORD *)(a1 + 1408) = v95 + 400;
      *(_DWORD *)(v95 + 400) = 1;
      *(_QWORD *)(v95 + 408) = 0x3200001010000LL;
      *(_DWORD *)(v95 + 432) = 1;
      *(_DWORD *)(v95 + 416) = 0;
      *(_QWORD *)(v95 + 424) = 0x100000001LL;
      *(_QWORD *)(v95 + 436) = 0;
      *(_QWORD *)(v95 + 444) = 0;
      *(_DWORD *)(v95 + 452) = 0;
      v96 = *(_QWORD **)(a1 + 144);
      *(_DWORD *)(a1 + 1400) = 0;
      v96[3] = a1;
      v96[4] = 0x7076635F6D736DLL;
      *v96 = 0x1C800000000LL;
      v96[1] = 0x3800000120LL;
      v96[2] = 0x300000003LL;
      *(_DWORD *)(*(_QWORD *)(a1 + 1024) + 4LL) = *(_DWORD *)(a1 + 1032);
      v97 = *(_QWORD *)(a1 + 1216);
      v98 = *(_DWORD *)(v97 + 8) | 1;
      *(_DWORD *)(v97 + 4) = *(_DWORD *)(a1 + 1224);
      *(_DWORD *)(v97 + 8) = v98;
      v99 = *(_DWORD **)(a1 + 1408);
      v100 = *(_DWORD *)(a1 + 1416);
      v101 = v99[2];
      v99[8] = 0;
      v99[1] = v100;
      v99[2] = v101 | 2;
      v102 = *(void **)(a1 + 672);
      if ( v102 )
      {
        memset(v102, 0, 0x100000u);
      }
      else if ( (unsigned int)_smem_alloc(a1, a1 + 840, 0x100000, 0) )
      {
        if ( (v85[3992] & 2) != 0 && !*((_DWORD *)v5 + 366) )
          printk(&unk_909DB, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), "warn");
        *(_DWORD *)(a1 + 664) = 0;
      }
      else
      {
        v107 = *(_DWORD *)(a1 + 840);
        v108 = *(_QWORD *)(a1 + 848);
        *(_DWORD *)(a1 + 680) = 0x100000;
        *(_QWORD *)(a1 + 672) = v108;
        *(_DWORD *)(a1 + 664) = v107 - v87;
        memcpy((void *)(a1 + 688), (const void *)(a1 + 864), 0x98u);
      }
      v109 = *(_DWORD **)(a1 + 672);
      if ( v109 )
        *v109 = 0x100000;
      v110 = *(void **)(a1 + 2528);
      v111 = *(_QWORD *)(cvp_driver + 48);
      if ( v110 )
      {
        v112 = v5;
        memset(v110, 0, 0x500000u);
        if ( v111 )
        {
          *(_QWORD *)(v111 + 1372) = 0;
LABEL_244:
          memset((void *)(v111 + 1384), 0, 0xC300u);
        }
      }
      else
      {
        if ( (unsigned int)_smem_alloc(a1, a1 + 840, 5242880, 2) )
        {
          if ( (v85[3992] & 2) != 0 && !*((_DWORD *)v5 + 366) )
            printk(&unk_92F50, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), "warn");
          v112 = v5;
          *(_DWORD *)(a1 + 2520) = 0;
          goto LABEL_250;
        }
        v130 = *(_QWORD *)(a1 + 848);
        v112 = v5;
        *(_DWORD *)(a1 + 2520) = *(_DWORD *)(a1 + 840);
        *(_QWORD *)(a1 + 2528) = v130;
        *(_DWORD *)(a1 + 2536) = 5242880;
        memcpy((void *)(a1 + 2544), (const void *)(a1 + 864), 0x98u);
        if ( v111 )
        {
          _mutex_init(v111 + 1320, "&core->kmd_dbg.dbg_lock", &_interface_queues_init___key);
          *(_DWORD *)(v111 + 1312) = 0;
          *(_QWORD *)(v111 + 1368) = 0;
          *(_DWORD *)(v111 + 1376) = 0;
          goto LABEL_244;
        }
      }
LABEL_250:
      if ( !*(_QWORD *)(a1 + 496) && (msm_cvp_fw_debug_mode & 2) != 0 && v86 )
      {
        if ( (unsigned int)_smem_alloc(a1, a1 + 840, 4096, 0) )
        {
          if ( (v85[3992] & 2) != 0 && !*((_DWORD *)v112 + 366) )
            printk(&unk_96E4C, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), "warn");
          v117 = *(_DWORD **)(a1 + 496);
          *(_DWORD *)(a1 + 488) = 0;
        }
        else
        {
          v135 = *(_DWORD *)(a1 + 840);
          v117 = *(_DWORD **)(a1 + 848);
          *(_DWORD *)(a1 + 504) = 4096;
          *(_QWORD *)(a1 + 496) = v117;
          *(_DWORD *)(a1 + 488) = v135 - v87;
          memcpy((void *)(a1 + 512), (const void *)(a1 + 864), 0x98u);
        }
        if ( v117 )
        {
          *v117 = v86;
          v117[1] = *(_DWORD *)(a1 + 488) + 8;
          v136 = msm_cvp_smem_get_context_bank(*(_QWORD *)(a1 + 2208), 0);
          if ( !v136 )
          {
            v103 = v179;
            v4 = v85;
            v5 = v112;
            if ( (v85[3992] & 1) == 0 || *((_DWORD *)v112 + 366) )
              goto LABEL_334;
            printk(&unk_8DBA2, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), &unk_8E7CE);
            if ( (v85[3992] & 1) != 0 )
              goto LABEL_335;
            goto LABEL_337;
          }
          v137 = *(_QWORD *)(a1 + 2208);
          v138 = *(unsigned int *)(v137 + 240);
          if ( !(_DWORD)v138 )
            goto LABEL_323;
          if ( (int)v138 >= 1 )
          {
            v139 = *(_QWORD *)(v136 + 48);
            v140 = *(unsigned int **)(v137 + 232);
            v141 = v117 + 2;
            v142 = v117 + 3;
            v143 = 0;
            v144 = 2147487744LL;
            do
            {
              if ( v139 )
              {
                if ( (unsigned int)iommu_map(v139, v144, *v140, v140[1], 3, 0) )
                {
                  v146 = *((_DWORD *)v112 + 366);
                  v147 = *((_DWORD *)v85 + 998) & 1;
                  if ( v147 && !v146 )
                  {
                    printk(&unk_921D0, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), &unk_8E7CE);
                    v146 = *((_DWORD *)v112 + 366);
                    if ( (*((_DWORD *)v85 + 998) & 1) != 0 )
                      goto LABEL_318;
                  }
                  else if ( v147 )
                  {
LABEL_318:
                    if ( !v146 )
                      printk(&unk_8A782, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), &unk_8E7CE);
                  }
                  if ( (_DWORD)v143 )
                  {
                    v148 = v143 + 1;
                    do
                    {
                      iommu_unmap(
                        v139,
                        (unsigned int)v141[4 * (unsigned int)(v148 - 2)],
                        (unsigned int)v141[4 * (unsigned int)(v148 - 2) + 2]);
                      --v148;
                    }
                    while ( v148 > 1 );
                  }
LABEL_323:
                  if ( (v85[3992] & 1) != 0 && !*((_DWORD *)v112 + 366) )
                    printk(&unk_88B74, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), &unk_8E7CE);
                  msm_cvp_smem_free(a1 + 512);
                  *(_QWORD *)(a1 + 496) = 0;
                  *(_DWORD *)(a1 + 488) = 0;
                  break;
                }
              }
              else
              {
                v144 = *v140;
              }
              *(v142 - 1) = v144;
              ++v143;
              *v142 = *v140;
              v145 = v140[1];
              v140 += 2;
              *(_QWORD *)(v142 + 1) = (unsigned int)v145;
              v144 += v145;
              v142 += 4;
            }
            while ( v138 != v143 );
          }
        }
      }
      v113 = *(void **)(a1 + 392);
      v183[0] = 0;
      if ( v113 )
      {
        memset(v113, 0, 0x300000u);
        v5 = v112;
LABEL_253:
        cvp_dsp_init_hfi_queue_hdr(a1);
        _setup_ucregion_memory_map(a1);
        v4 = v85;
        if ( !(unsigned int)msm_cvp_map_ipcc_regs(&v182) )
        {
          if ( (msm_cvp_debug & 0x100) != 0 && !*((_DWORD *)v5 + 366) )
            printk(&unk_93AA9, "core", v182, v114);
          _write_register(a1, 0xA0060u, v182);
        }
        fw = _load_fw(a1);
        if ( fw )
        {
          v18 = fw;
          if ( (v85[3992] & 1) == 0 || *((_DWORD *)v5 + 366) )
            goto LABEL_338;
          v116 = v179;
          v76 = &unk_94E19;
        }
        else
        {
          if ( !(unsigned int)_boot_firmware(a1) )
          {
            v131 = _read_register(a1, 0xA0058u);
            v132 = *(_DWORD ***)(a1 + 2416);
            *(_DWORD *)(a1 + 16) = v131;
            if ( v132 )
            {
              v133 = *v132;
              if ( v133 )
              {
                if ( *(v133 - 1) != 456970915 )
                  __break(0x8228u);
                v134 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v133)(&v180, 0);
                if ( v134 )
                {
                  v18 = v134;
                  if ( (v85[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
                    printk(&unk_9137F, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), &unk_8E7CE);
                  goto LABEL_338;
                }
              }
            }
            if ( (unsigned int)_iface_cmdq_write(a1, (unsigned int *)&v180) )
            {
              v18 = -39;
              goto LABEL_338;
            }
            v149 = v5;
            v150 = (unsigned int *)_kmalloc_cache_noprof(kfree, 3520, 16);
            v151 = *(_QWORD *)(a1 + 2416);
            if ( v151 )
            {
              v152 = *(unsigned int (**)(void))(v151 + 64);
              if ( v152 )
              {
                if ( *((_DWORD *)v152 - 1) != -383367176 )
                  __break(0x8228u);
                if ( v152() )
                  goto LABEL_394;
              }
            }
            if ( (unsigned int)_iface_cmdq_write(a1, v150) )
            {
LABEL_394:
              if ( (v85[3992] & 2) != 0 && !*((_DWORD *)v5 + 366) )
                printk(&unk_95855, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), "warn");
            }
            kfree(v150);
            _sys_set_debug(a1, msm_cvp_fw_debug);
            _enable_subcaches(a1, v153, v154, v155);
            _set_subcaches(a1, v156, v157, v158);
            _set_ubwc_config(a1);
            _sys_set_idle_indicator(a1);
            if ( *(_DWORD *)(a1 + 2696) )
            {
              *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 400LL) = _kmalloc_noprof(
                                                              80LL * *(unsigned int *)(*(_QWORD *)(a1 + 2208) + 384LL),
                                                              3520);
              v159 = *(_QWORD *)(a1 + 2208);
              if ( *(_QWORD *)(v159 + 400) )
              {
                if ( *(_DWORD *)(v159 + 384) )
                {
                  v160 = 0;
                  v161 = 0;
                  v5 = (char **)&_cpu_possible_mask;
                  v4 = "iris_hfi_core_init";
                  while ( v160 != 160 )
                  {
                    v162 = *(unsigned int *)(v159 + 4 * v161 + 392);
                    if ( ((*(_QWORD *)((char *)&_cpu_possible_mask + ((v162 >> 3) & 0x1FFFFFF8)) >> v162) & 1) != 0 )
                    {
                      if ( (msm_cvp_debug & 0x400) != 0 && !*((_DWORD *)v149 + 366) )
                        printk(&unk_94251, &unk_8DA84, "iris_hfi_core_init", (unsigned int)v161);
                      cpu_device = get_cpu_device((unsigned int)v162);
                      if ( (dev_pm_qos_add_request(
                              cpu_device,
                              *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 400LL) + v160,
                              1,
                              *(unsigned int *)(a1 + 2696))
                          & 0x80000000) != 0
                        && (v85[3992] & 2) != 0
                        && !*((_DWORD *)v149 + 366) )
                      {
                        printk(&unk_93AC9, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), "warn");
                      }
                    }
                    v159 = *(_QWORD *)(a1 + 2208);
                    ++v161;
                    v160 += 80;
                    if ( v161 >= *(unsigned int *)(v159 + 384) )
                      goto LABEL_373;
                  }
                  __break(0x5512u);
                  v176 = _ReadStatusReg(SP_EL0);
                  v177 = *(_QWORD *)(v176 + 80);
                  v178 = printk;
                  *(_QWORD *)(v176 + 80) = &iris_hfi_core_init__alloc_tag;
                  v7 = _kmalloc_cache_noprof(v178, 3520, 20);
                  *(_QWORD *)(v176 + 80) = v177;
                  continue;
                }
              }
              else if ( (v85[3992] & 2) != 0 && !*((_DWORD *)v5 + 366) )
              {
                printk(&unk_8CF9A, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), "warn");
              }
            }
LABEL_373:
            v164 = mutex_unlock(a1 + 80);
            cvp_dsp_send_hfi_queue(v164);
            pm_relax(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 256LL) + 112LL));
            v18 = 0;
            if ( (msm_cvp_debug & 0x100) != 0 && !*((_DWORD *)v149 + 366) )
            {
              printk(&unk_90088, "core", v165, v166);
              v18 = 0;
            }
            goto LABEL_198;
          }
          v18 = -19;
          if ( (v85[3992] & 1) == 0 || *((_DWORD *)v5 + 366) )
            goto LABEL_338;
          v116 = v179;
          v76 = &unk_87667;
        }
        v74 = *(unsigned int *)(v116 + 1800);
        v75 = *(unsigned int *)(v116 + 1804);
LABEL_181:
        printk(v76, v74, v75, &unk_8E7CE);
        goto LABEL_338;
      }
      v118 = 0;
      v5 = v112;
      while ( 1 )
      {
        v119 = dma_alloc_attrs(*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 440LL), 3145728, v183, 3264, 0);
        v121 = *((_DWORD *)v85 + 998);
        v122 = *((_DWORD *)v112 + 366);
        if ( v119 )
        {
          if ( v119 < 0xFFFFFFFFFFFFF001LL )
            break;
        }
        if ( (v121 & 1) != 0 && !v122 )
          printk(&unk_89CDF, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), &unk_8E7CE);
        usleep_range_state(100000, 105000, 2);
        if ( ++v118 == 10 )
        {
          v103 = v179;
          v4 = v85;
          if ( (v85[3992] & 1) != 0 && !*((_DWORD *)v112 + 366) )
            printk(&unk_8CFCF, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), &unk_8E7CE);
LABEL_332:
          if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v112 + 366) )
          {
            v104 = *(unsigned int *)(v103 + 1800);
            v105 = *(unsigned int *)(v103 + 1804);
            v106 = &unk_8C5E0;
            goto LABEL_368;
          }
LABEL_334:
          if ( (v4[3992] & 1) != 0 )
            goto LABEL_335;
          goto LABEL_337;
        }
      }
      v123 = v119;
      if ( (v121 & 4) != 0 && !v122 )
        printk(&unk_900B2, "info", "__interface_dsp_queues_init", v120);
      v124 = msm_cvp_smem_get_context_bank(*(_QWORD *)(a1 + 2208), 8);
      if ( !v124 )
      {
        v4 = v85;
        if ( (v85[3992] & 1) == 0 || *((_DWORD *)v112 + 366) )
          goto LABEL_331;
        v129 = &unk_9636C;
        goto LABEL_377;
      }
      v125 = v124;
      v126 = *(const char ***)(v124 + 40);
      v127 = v183[0] - memstart_addr;
      v128 = is_vmalloc_addr((v183[0] - memstart_addr) | 0xFFFFFF8000000000LL);
      if ( (v128 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v167 = v128;
        dma_map_single_attrs___already_done = 1;
        v168 = (const char *)dev_driver_string(v126);
        v169 = v126[14];
        if ( !v169 )
          v169 = *v126;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v168, v169);
        __break(0x800u);
        if ( (v167 & 1) != 0 )
          goto LABEL_288;
      }
      else if ( (v128 & 1) != 0 )
      {
LABEL_288:
        v4 = v85;
        if ( (v85[3992] & 1) == 0 || *((_DWORD *)v112 + 366) )
          goto LABEL_331;
        v129 = &unk_8822D;
LABEL_377:
        printk(v129, *(unsigned int *)(v179 + 1800), *(unsigned int *)(v179 + 1804), &unk_8E7CE);
LABEL_331:
        dma_free_attrs(*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 440LL), 3145728, v123, v183[0], 0);
        v103 = v179;
        goto LABEL_332;
      }
      v170 = dma_map_page_attrs(v126, ((v127 >> 6) & 0x1FFFFFFC0LL) - 0x140000000LL, v127 & 0xFFF, 3145728, 0, 0);
      if ( v170 != -1 )
      {
        v171 = v170;
        if ( (msm_cvp_debug & 0x800) != 0 && !*((_DWORD *)v112 + 366) )
          printk(&unk_88BB8, "dsp", "__interface_dsp_queues_init", v123);
        v172 = v183[0];
        *(_QWORD *)(a1 + 408) = 0;
        *(_QWORD *)(a1 + 416) = 0;
        *(_QWORD *)(a1 + 456) = 0;
        *(_QWORD *)(a1 + 464) = 0;
        *(_QWORD *)(a1 + 408) = v172;
        *(_DWORD *)(a1 + 416) = 3145728;
        v174 = *(_QWORD *)(a1 + 2208);
        *(_QWORD *)(a1 + 440) = 0;
        *(_QWORD *)(a1 + 448) = 0;
        *(_QWORD *)(a1 + 424) = 0;
        *(_QWORD *)(a1 + 432) = 0;
        *(_QWORD *)(a1 + 384) = 0;
        *(_QWORD *)(a1 + 392) = 0;
        *(_QWORD *)(a1 + 368) = 0;
        *(_QWORD *)(a1 + 376) = 0;
        *(_QWORD *)(a1 + 352) = 0;
        *(_QWORD *)(a1 + 360) = 0;
        *(_QWORD *)(a1 + 336) = 0;
        *(_QWORD *)(a1 + 344) = 0;
        *(_QWORD *)(a1 + 392) = v123;
        *(_QWORD *)(a1 + 400) = 0;
        *(_DWORD *)(a1 + 400) = v171;
        *(_QWORD *)(a1 + 472) = 0;
        *(_QWORD *)(a1 + 480) = v125;
        v173 = *(_QWORD *)(v174 + 336) == v174 + 336;
        LODWORD(v174) = 0;
        if ( v173 )
          v174 = *(_QWORD *)(*(_QWORD *)(a1 + 2168) + 8LL);
        v175 = v171 - v174;
        *(_DWORD *)(a1 + 328) = 456;
        *(_DWORD *)(a1 + 1608) = v175 + 456;
        *(_QWORD *)(a1 + 1616) = v123 + 456;
        *(_DWORD *)(a1 + 312) = v175;
        *(_DWORD *)(a1 + 1800) = v175 + 819656;
        *(_QWORD *)(a1 + 320) = v123;
        *(_QWORD *)(a1 + 1808) = v123 + 819656;
        *(_DWORD *)(a1 + 1624) = 819200;
        *(_DWORD *)(a1 + 1592) = 0;
        *(_DWORD *)(a1 + 1992) = v175 + 1638856;
        *(_DWORD *)(a1 + 1816) = 819200;
        *(_DWORD *)(a1 + 1784) = 0;
        *(_QWORD *)(a1 + 2000) = v123 + 1638856;
        *(_DWORD *)(a1 + 2008) = 819200;
        *(_DWORD *)(a1 + 1976) = 0;
        goto LABEL_253;
      }
      goto LABEL_288;
    }
    break;
  }
  v18 = v73;
  if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
  {
    v74 = *(unsigned int *)(v29 + 1800);
    v75 = *(unsigned int *)(v29 + 1804);
    v76 = &unk_82D8C;
    goto LABEL_181;
  }
LABEL_338:
  *(_DWORD *)(a1 + 2408) = 1;
  _unload_fw(a1);
  if ( *(_QWORD *)(a1 + 2400) )
    msm_cvp_mmrm_deregister(a1);
LABEL_193:
  _hwfence_regs_unmap(a1);
LABEL_194:
  if ( (v4[3992] & 1) != 0 && !*((_DWORD *)v5 + 366) )
  {
    v81 = _ReadStatusReg(SP_EL0);
    printk(&unk_913B6, *(unsigned int *)(v81 + 1800), *(unsigned int *)(v81 + 1804), &unk_8E7CE);
  }
  mutex_unlock(a1 + 80);
  pm_relax(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 256LL) + 112LL));
LABEL_198:
  _ReadStatusReg(SP_EL0);
  return v18;
}
