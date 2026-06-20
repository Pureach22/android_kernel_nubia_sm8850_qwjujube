__int64 __fastcall cvp_read_platform_resources_from_dt(__int64 a1)
{
  char **v1; // x27
  __int64 v2; // x25
  _QWORD *v3; // x26
  __int64 *resource; // x0
  __int64 v6; // x8
  __int64 v7; // x8
  unsigned int v8; // w22
  unsigned __int64 StatusReg; // x8
  unsigned int irq; // w0
  unsigned int v11; // w0
  char v12; // w8
  __int64 v13; // x20
  int string_helper; // w0
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x23
  unsigned int v18; // w21
  __int64 v19; // x0
  __int64 v20; // x3
  char v21; // w8
  __int64 v22; // x24
  __int64 i; // x21
  int v24; // w9
  char v25; // w8
  __int64 v26; // x20
  __int64 v27; // x2
  __int64 v28; // x3
  unsigned __int64 v29; // x8
  __int64 v30; // x0
  int v31; // w8
  int v32; // w10
  __int64 v33; // x20
  __int16 v34; // w9
  __int64 j; // x23
  void *v36; // x0
  unsigned __int64 v37; // x8
  __int64 v38; // x20
  __int64 v39; // x2
  __int64 v40; // x3
  unsigned __int64 v41; // x8
  __int64 v42; // x0
  int v43; // w8
  int v44; // w10
  __int64 v45; // x20
  __int16 v46; // w9
  __int64 k; // x23
  void *v48; // x0
  __int64 v49; // x0
  __int64 v50; // x2
  __int64 v51; // x3
  char v52; // w8
  int v53; // w8
  __int64 v54; // x20
  __int64 v55; // x0
  int v56; // w9
  __int64 v57; // x10
  int v58; // w9
  __int64 v59; // x10
  int v60; // w9
  __int64 v61; // x10
  char v62; // w11
  unsigned __int64 v63; // x8
  __int64 v64; // x1
  __int64 v65; // x2
  void *v66; // x0
  unsigned __int64 v67; // x8
  unsigned __int64 v68; // x8
  unsigned __int64 v69; // x8
  __int64 v70; // x0
  int v71; // w9
  int variable_u32_array; // w0
  __int64 v73; // x3
  int v74; // w8
  __int64 v75; // x26
  __int64 v76; // x22
  _QWORD *v77; // x20
  int v78; // w21
  size_t v79; // x0
  __int64 v80; // x0
  unsigned __int64 v81; // x8
  __int64 v82; // x21
  __int64 v83; // x23
  unsigned int v84; // w0
  __int64 v85; // x0
  unsigned __int64 v86; // x28
  __int64 v87; // x0
  __int64 v88; // x24
  int v89; // w0
  unsigned int v90; // w8
  unsigned int v91; // w25
  char **v92; // x26
  __int64 v93; // x27
  unsigned int v94; // w0
  unsigned __int64 v95; // x0
  __int64 v96; // x1
  unsigned __int64 v97; // x8
  __int64 v98; // x0
  __int64 v99; // x2
  __int64 v100; // x3
  const char **v101; // x21
  size_t v102; // x0
  __int64 v103; // x0
  __int64 v104; // x24
  const char *v105; // x1
  unsigned __int64 v106; // x25
  unsigned int v107; // w8
  char **v108; // x23
  __int64 v109; // x20
  unsigned __int64 v110; // x27
  __int64 v111; // x0
  const char *v112; // x26
  __int64 v113; // x28
  size_t v114; // x24
  size_t v115; // x0
  size_t v116; // x2
  __int64 property; // x0
  void *v118; // x3
  unsigned int v119; // w8
  __int64 v120; // x10
  char v121; // w8
  unsigned __int64 v122; // x8
  unsigned __int64 v123; // x8
  unsigned __int64 v124; // x8
  unsigned __int64 v125; // x8
  unsigned __int64 v126; // x8
  unsigned __int64 v127; // x8
  unsigned __int64 v128; // x8
  unsigned __int64 v129; // x8
  unsigned __int64 v130; // x8
  unsigned __int64 v131; // x8
  __int64 v132; // x1
  __int64 v133; // x2
  void *v134; // x0
  unsigned __int64 v135; // x8
  unsigned __int64 v136; // x8
  unsigned __int64 v137; // x8
  void *v138; // x0
  unsigned __int64 v139; // x8
  unsigned __int64 v140; // x8
  unsigned __int64 v141; // x8
  unsigned __int64 v142; // x8
  unsigned __int64 v143; // x8
  unsigned int v144; // w8
  _QWORD *v145; // x10
  _DWORD *v146; // x21
  unsigned __int64 v147; // x8
  __int64 v148; // x28
  int v149; // w0
  __int64 v150; // x2
  __int64 v151; // x3
  unsigned int v152; // w26
  unsigned __int64 v153; // x22
  __int64 v154; // x0
  __int64 v155; // x23
  int v156; // w0
  __int64 v157; // x2
  __int64 v158; // x3
  int v159; // w8
  int v160; // w9
  __int64 v161; // x0
  __int64 v162; // x24
  int v163; // w0
  __int64 v164; // x25
  __int64 v165; // x0
  __int64 v166; // x3
  char v167; // w8
  unsigned int v168; // w26
  __int64 v169; // x21
  unsigned __int64 v170; // x20
  __int64 v171; // x27
  char v172; // w8
  __int64 v173; // x22
  __int64 v174; // x2
  __int64 v175; // x3
  unsigned int u32_table; // w0
  __int64 v177; // x26
  _QWORD *v178; // x27
  int v179; // w8
  int v180; // w9
  unsigned __int64 v181; // x8
  unsigned __int64 v182; // x8
  __int64 v183; // x1
  __int64 v184; // x2
  void *v185; // x0
  unsigned __int64 v186; // x8
  __int64 v187; // x21
  __int64 v188; // x0
  unsigned int v189; // w0
  __int64 v190; // x0
  __int64 v191; // x3
  char v192; // w9
  __int64 v193; // x23
  unsigned int v194; // w22
  __int64 v195; // x0
  __int64 v196; // x3
  char v197; // w8
  int v198; // w0
  __int64 v199; // x20
  __int64 v200; // x20
  __int64 v201; // x20
  __int64 v202; // x20
  __int64 v203; // x20
  unsigned __int64 v204; // x8
  unsigned __int64 v205; // x8
  __int64 v206; // x8
  __int64 v207; // x8
  __int64 v208; // x9
  unsigned __int64 v209; // x8
  unsigned __int64 v210; // x8
  unsigned int v211; // w8
  __int64 v212; // x10
  unsigned __int64 v214; // x8
  unsigned __int64 v215; // x8
  unsigned __int64 v216; // x8
  __int64 v217; // x0
  __int64 v218; // x30
  unsigned __int64 v219; // [xsp+30h] [xbp-B0h]
  __int64 v220; // [xsp+38h] [xbp-A8h]
  _QWORD *v221; // [xsp+40h] [xbp-A0h]
  __int64 v222; // [xsp+48h] [xbp-98h]
  unsigned int v223; // [xsp+5Ch] [xbp-84h] BYREF
  __int64 v224; // [xsp+60h] [xbp-80h] BYREF
  unsigned int v225; // [xsp+68h] [xbp-78h]
  __int64 v226; // [xsp+70h] [xbp-70h] BYREF
  unsigned int v227; // [xsp+78h] [xbp-68h]
  unsigned __int64 v228; // [xsp+80h] [xbp-60h] BYREF
  __int64 v229; // [xsp+88h] [xbp-58h]
  __int64 v230; // [xsp+90h] [xbp-50h]
  __int64 v231; // [xsp+98h] [xbp-48h]
  __int64 v232; // [xsp+A0h] [xbp-40h]
  __int64 v233; // [xsp+A8h] [xbp-38h]
  __int64 v234; // [xsp+B0h] [xbp-30h]
  __int64 v235; // [xsp+B8h] [xbp-28h]
  __int64 v236; // [xsp+C0h] [xbp-20h]
  __int64 v237; // [xsp+C8h] [xbp-18h]
  __int64 v238; // [xsp+D0h] [xbp-10h]

  v1 = off_6C000;
  v238 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 864);
  v223 = 0;
  if ( !*(_QWORD *)(v2 + 760) )
  {
    v8 = -2;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_853A7, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v8 = -2;
    }
    goto LABEL_332;
  }
  v3 = (_QWORD *)(a1 + 944);
  *(_QWORD *)(a1 + 944) = a1 + 944;
  *(_QWORD *)(a1 + 952) = a1 + 944;
  *(_QWORD *)(a1 + 608) = 0;
  resource = (__int64 *)platform_get_resource(v2, 512, 0);
  if ( resource )
  {
    v6 = *resource;
    *(_QWORD *)(a1 + 616) = *resource;
    v7 = resource[1] - v6 + 1;
  }
  else
  {
    LODWORD(v7) = -1;
    *(_QWORD *)(a1 + 616) = -1;
  }
  *(_DWORD *)(a1 + 640) = v7;
  irq = platform_get_irq(v2, 0);
  *(_DWORD *)(a1 + 752) = irq;
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    printk(&unk_8D660, "core", "cvp_read_platform_resources_from_dt", irq);
  v11 = platform_get_irq(v2, 1);
  v12 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 756) = v11;
  if ( (v12 & 1) != 0 && !msm_cvp_debug_out )
    printk(&unk_95EEE, "core", "cvp_read_platform_resources_from_dt", v11);
  v13 = *(_QWORD *)(a1 + 864);
  string_helper = of_property_read_string_helper(*(_QWORD *)(v13 + 760), "cache-slice-names", 0, 0, 0);
  if ( string_helper <= 0 )
  {
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      printk(&unk_9073F, "core", v15, v16);
    *(_BYTE *)(a1 + 800) = 0;
    *(_DWORD *)(a1 + 816) = 0;
    *(_QWORD *)(a1 + 808) = 0;
  }
  else
  {
    v17 = (unsigned int)string_helper;
    v18 = string_helper;
    v19 = devm_kmalloc(v13 + 16, 24LL * (unsigned int)string_helper, 3520);
    *(_QWORD *)(a1 + 808) = v19;
    if ( v19 )
    {
      v21 = BYTE1(msm_cvp_debug);
      *(_DWORD *)(a1 + 816) = v18;
      if ( (v21 & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_8544E, "core", v18, v20);
      v22 = 0;
      for ( i = 0; i != v17; ++i )
      {
        of_property_read_string_helper(
          *(_QWORD *)(v13 + 760),
          "cache-slice-names",
          *(_QWORD *)(a1 + 808) + v22,
          1,
          (unsigned int)i);
        v22 += 24;
      }
      *(_BYTE *)(a1 + 800) = 1;
    }
    else
    {
      v24 = msm_cvp_debug_out;
      v25 = msm_cvp_debug;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v136 = _ReadStatusReg(SP_EL0);
        printk(&unk_90763, *(unsigned int *)(v136 + 1800), *(unsigned int *)(v136 + 1804), &unk_8E7CE);
        v25 = msm_cvp_debug;
        v24 = msm_cvp_debug_out;
      }
      *(_BYTE *)(a1 + 800) = 0;
      *(_DWORD *)(a1 + 816) = 0;
      *(_QWORD *)(a1 + 808) = 0;
      if ( (v25 & 2) != 0 && !v24 )
      {
        v137 = _ReadStatusReg(SP_EL0);
        printk(&unk_906D1, *(unsigned int *)(v137 + 1800), *(unsigned int *)(v137 + 1804), "warn");
      }
    }
  }
  v26 = *(_QWORD *)(a1 + 864);
  if ( !of_find_property(*(_QWORD *)(v26 + 760), "qcom,qdss-presets", 0) )
  {
    if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
      goto LABEL_59;
    v36 = &unk_8C258;
LABEL_48:
    printk(v36, "core", v27, v28);
    goto LABEL_59;
  }
  v29 = (unsigned __int64)(int)get_u32_array_num_elements(*(_QWORD *)(v26 + 760)) >> 1;
  *(_DWORD *)(a1 + 848) = v29;
  if ( !(_DWORD)v29 )
  {
    if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
      goto LABEL_59;
    v36 = &unk_871E0;
    goto LABEL_48;
  }
  v30 = devm_kmalloc(v26 + 16, 8LL * (int)v29, 3520);
  *(_QWORD *)(a1 + 840) = v30;
  if ( v30 )
  {
    if ( (of_property_read_variable_u32_array(
            *(_QWORD *)(v26 + 760),
            "qcom,qdss-presets",
            v30,
            2 * *(_DWORD *)(a1 + 848),
            0)
        & 0x80000000) == 0 )
    {
      v31 = *(_DWORD *)(a1 + 848);
      if ( v31 >= 1 )
      {
        v32 = msm_cvp_debug_out;
        v33 = 0;
        v34 = msm_cvp_debug;
        for ( j = 0; j < v31; ++j )
        {
          if ( (v34 & 0x100) != 0 && !v32 )
          {
            printk(
              &unk_8FBC1,
              "core",
              *(unsigned int *)(*(_QWORD *)(a1 + 840) + v33),
              *(unsigned int *)(*(_QWORD *)(a1 + 840) + v33 + 4));
            v34 = msm_cvp_debug;
            v32 = msm_cvp_debug_out;
            v31 = *(_DWORD *)(a1 + 848);
          }
          v33 += 8;
        }
      }
      goto LABEL_59;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v140 = _ReadStatusReg(SP_EL0);
      printk(&unk_867A8, *(unsigned int *)(v140 + 1800), *(unsigned int *)(v140 + 1804), &unk_8E7CE);
    }
    *(_QWORD *)(a1 + 840) = 0;
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v37 = _ReadStatusReg(SP_EL0);
    printk(&unk_91CD1, *(unsigned int *)(v37 + 1800), *(unsigned int *)(v37 + 1804), &unk_8E7CE);
  }
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v135 = _ReadStatusReg(SP_EL0);
    printk(&unk_853D2, *(unsigned int *)(v135 + 1800), *(unsigned int *)(v135 + 1804), "warn");
  }
LABEL_59:
  v38 = *(_QWORD *)(a1 + 864);
  if ( !of_find_property(*(_QWORD *)(v38 + 760), "qcom,reg-presets", 0) )
  {
    if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
      goto LABEL_76;
    v48 = &unk_8E5F1;
LABEL_75:
    printk(v48, "core", v39, v40);
    goto LABEL_76;
  }
  v41 = (unsigned __int64)(int)get_u32_array_num_elements(*(_QWORD *)(v38 + 760)) >> 1;
  *(_DWORD *)(a1 + 832) = v41;
  if ( !(_DWORD)v41 )
  {
    if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
      goto LABEL_76;
    v48 = &unk_899CE;
    goto LABEL_75;
  }
  v42 = devm_kmalloc(v38 + 16, 8LL * (int)v41, 3520);
  *(_QWORD *)(a1 + 824) = v42;
  if ( !v42 )
  {
    v8 = -12;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v68 = _ReadStatusReg(SP_EL0);
      printk(&unk_91CD1, *(unsigned int *)(v68 + 1800), *(unsigned int *)(v68 + 1804), &unk_8E7CE);
      v8 = -12;
    }
    goto LABEL_155;
  }
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(v38 + 760),
          "qcom,reg-presets",
          v42,
          2 * *(_DWORD *)(a1 + 832),
          0)
      & 0x80000000) != 0 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v141 = _ReadStatusReg(SP_EL0);
      printk(&unk_8D7BD, *(unsigned int *)(v141 + 1800), *(unsigned int *)(v141 + 1804), &unk_8E7CE);
    }
    v8 = -22;
    *(_QWORD *)(a1 + 824) = 0;
LABEL_155:
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v97 = _ReadStatusReg(SP_EL0);
      printk(&unk_8D682, *(unsigned int *)(v97 + 1800), *(unsigned int *)(v97 + 1804), &unk_8E7CE);
    }
    goto LABEL_332;
  }
  v43 = *(_DWORD *)(a1 + 832);
  if ( v43 >= 1 )
  {
    v44 = msm_cvp_debug_out;
    v45 = 0;
    v46 = msm_cvp_debug;
    for ( k = 0; k < v43; ++k )
    {
      if ( (v46 & 0x100) != 0 && !v44 )
      {
        printk(
          &unk_84A28,
          "core",
          *(unsigned int *)(*(_QWORD *)(a1 + 824) + v45),
          *(unsigned int *)(*(_QWORD *)(a1 + 824) + v45 + 4));
        v46 = msm_cvp_debug;
        v44 = msm_cvp_debug_out;
        v43 = *(_DWORD *)(a1 + 832);
      }
      v45 += 8;
    }
  }
LABEL_76:
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "soc_ver", a1 + 1244, 1, 0) & 0x80000000) != 0 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v127 = _ReadStatusReg(SP_EL0);
      printk(&unk_83F68, *(unsigned int *)(v127 + 1800), *(unsigned int *)(v127 + 1804), "warn");
    }
    *(_DWORD *)(a1 + 1244) = 0x10000;
  }
  v49 = *(_QWORD *)(*(_QWORD *)(a1 + 864) + 760LL);
  v228 = 0;
  if ( (of_property_read_variable_u32_array(v49, "qcom,ipcc-reg", &v228, 2, 0) & 0x80000000) != 0 )
  {
    v53 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v128 = _ReadStatusReg(SP_EL0);
      printk(&unk_87E03, *(unsigned int *)(v128 + 1800), *(unsigned int *)(v128 + 1804), &unk_8E7CE);
      v53 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 1) == 0 )
        goto LABEL_90;
    }
    else if ( (msm_cvp_debug & 1) == 0 )
    {
      goto LABEL_90;
    }
    if ( !v53 )
    {
      v129 = _ReadStatusReg(SP_EL0);
      printk(&unk_95F13, *(unsigned int *)(v129 + 1800), *(unsigned int *)(v129 + 1804), &unk_8E7CE);
    }
  }
  else
  {
    v50 = (unsigned int)v228;
    v51 = HIDWORD(v228);
    v52 = BYTE1(msm_cvp_debug);
    *(_QWORD *)(a1 + 624) = (unsigned int)v228;
    *(_DWORD *)(a1 + 644) = v51;
    if ( (v52 & 1) != 0 && !msm_cvp_debug_out )
      printk(&unk_8F091, "core", v50, v51);
  }
LABEL_90:
  v54 = *(_QWORD *)(a1 + 864);
  v55 = *(_QWORD *)(v54 + 760);
  LODWORD(v229) = 0;
  v228 = 0;
  v227 = 0;
  v226 = 0;
  v225 = 0;
  v224 = 0;
  if ( (of_property_read_variable_u32_array(v55, "hwmutex_mappings", &v228, 3, 0) & 0x80000000) != 0 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_109;
    v63 = _ReadStatusReg(SP_EL0);
    v64 = *(unsigned int *)(v63 + 1800);
    v65 = *(unsigned int *)(v63 + 1804);
    v66 = &unk_899F6;
LABEL_108:
    printk(v66, v64, v65, &unk_8E7CE);
    goto LABEL_109;
  }
  v56 = HIDWORD(v228);
  v57 = (unsigned int)v229;
  *(_QWORD *)(a1 + 680) = (unsigned int)v228;
  *(_DWORD *)(a1 + 696) = v56;
  *(_QWORD *)(a1 + 688) = v57;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v54 + 760), "aon_mappings", &v226, 3, 0) & 0x80000000) != 0 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_109;
    v67 = _ReadStatusReg(SP_EL0);
    v64 = *(unsigned int *)(v67 + 1800);
    v65 = *(unsigned int *)(v67 + 1804);
    v66 = &unk_8338F;
    goto LABEL_108;
  }
  v58 = HIDWORD(v226);
  v59 = v227;
  *(_QWORD *)(a1 + 704) = (unsigned int)v226;
  *(_DWORD *)(a1 + 720) = v58;
  *(_QWORD *)(a1 + 712) = v59;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v54 + 760), "aon_timer_mappings", &v224, 3, 0) & 0x80000000) == 0 )
  {
    v60 = HIDWORD(v224);
    v61 = v225;
    v62 = BYTE1(msm_cvp_debug);
    *(_QWORD *)(a1 + 728) = (unsigned int)v224;
    *(_DWORD *)(a1 + 744) = v60;
    *(_QWORD *)(a1 + 736) = v61;
    if ( (v62 & 1) != 0 && !msm_cvp_debug_out )
      printk(&unk_8FBED, "core", *(_QWORD *)(a1 + 656), *(unsigned int *)(a1 + 672));
    goto LABEL_112;
  }
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v69 = _ReadStatusReg(SP_EL0);
    v64 = *(unsigned int *)(v69 + 1800);
    v65 = *(unsigned int *)(v69 + 1804);
    v66 = &unk_91040;
    goto LABEL_108;
  }
LABEL_109:
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v125 = _ReadStatusReg(SP_EL0);
    printk(&unk_89111, *(unsigned int *)(v125 + 1800), *(unsigned int *)(v125 + 1804), &unk_8E7CE);
  }
LABEL_112:
  v70 = *(_QWORD *)(*(_QWORD *)(a1 + 864) + 760LL);
  v228 = 0;
  if ( (of_property_read_variable_u32_array(v70, "qcom,gcc-reg", &v228, 2, 0) & 0x80000000) != 0 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v130 = _ReadStatusReg(SP_EL0);
      printk(&unk_91076, *(unsigned int *)(v130 + 1800), *(unsigned int *)(v130 + 1804), "warn");
    }
  }
  else
  {
    v71 = HIDWORD(v228);
    *(_QWORD *)(a1 + 632) = (unsigned int)v228;
    *(_DWORD *)(a1 + 648) = v71;
  }
  variable_u32_array = of_property_read_variable_u32_array(
                         *(_QWORD *)(*(_QWORD *)(a1 + 864) + 760LL),
                         "framework-type",
                         a1 + 1072,
                         1,
                         0);
  if ( variable_u32_array < 0 )
  {
    v8 = variable_u32_array & (variable_u32_array >> 31);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v81 = _ReadStatusReg(SP_EL0);
      printk(&unk_8C214, *(unsigned int *)(v81 + 1800), *(unsigned int *)(v81 + 1804), &unk_8E7CE);
    }
    goto LABEL_331;
  }
  v74 = *(_DWORD *)(a1 + 1072);
  if ( v74 != 1 )
  {
    v221 = v3;
    v222 = v2;
    if ( !v74 )
    {
      if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
        printk(&unk_8335C, "core", 0, v73);
      v75 = *(_QWORD *)(a1 + 864);
      *(_DWORD *)(a1 + 880) = 0;
      *(_QWORD *)(a1 + 872) = 0;
      v76 = *(_QWORD *)(v75 + 760);
      v77 = *(_QWORD **)(v76 + 96);
      if ( v77 )
      {
        v78 = 0;
        do
        {
          v79 = strlen((const char *)*v77);
          v80 = strnstr(*v77, "-supply", v79 + 1);
          if ( v80 && !*(_BYTE *)(v80 + 7) )
            ++v78;
          v77 = (_QWORD *)v77[3];
        }
        while ( v77 );
        v96 = 24LL * v78;
      }
      else
      {
        v96 = 0;
      }
      v98 = devm_kmalloc(v75 + 16, v96, 3520);
      *(_QWORD *)(a1 + 872) = v98;
      if ( !v98 )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v138 = &unk_833C3;
          v139 = _ReadStatusReg(SP_EL0);
LABEL_334:
          printk(v138, *(unsigned int *)(v139 + 1800), *(unsigned int *)(v139 + 1804), &unk_8E7CE);
        }
LABEL_191:
        if ( *(_DWORD *)(a1 + 880) )
        {
          v119 = 0;
          do
          {
            v120 = *(_QWORD *)(a1 + 872) + 24LL * (int)v119++;
            *(_QWORD *)(v120 + 16) = 0;
          }
          while ( v119 < *(_DWORD *)(a1 + 880) );
        }
        v8 = -12;
        *(_QWORD *)(a1 + 872) = 0;
        v121 = msm_cvp_debug;
        *(_DWORD *)(a1 + 880) = 0;
        if ( (v121 & 1) != 0 && !*((_DWORD *)v1 + 366) )
        {
          v122 = _ReadStatusReg(SP_EL0);
          v8 = -12;
          printk(&unk_954BB, *(unsigned int *)(v122 + 1800), *(unsigned int *)(v122 + 1804), &unk_8E7CE);
        }
        goto LABEL_331;
      }
      v101 = *(const char ***)(v76 + 96);
      if ( v101 )
      {
        v219 = _ReadStatusReg(SP_EL0);
        v220 = v75;
        do
        {
          v102 = strlen(*v101);
          v103 = strnstr(*v101, "-supply", v102 + 1);
          if ( v103 )
          {
            v104 = v103;
            if ( !*(_BYTE *)(v103 + 7) )
            {
              v105 = *v101;
              v236 = 0;
              v237 = 0;
              v234 = 0;
              v235 = 0;
              v232 = 0;
              v233 = 0;
              v230 = 0;
              v231 = 0;
              v228 = 0;
              v229 = 0;
              if ( (unsigned int)_of_parse_phandle_with_args(v76, v105, 0, 0, 0, &v228) )
                v106 = 0;
              else
                v106 = v228;
              if ( v106 < 0xFFFFFFFFFFFFF001LL )
              {
                v107 = *(_DWORD *)(a1 + 880);
                v108 = v1;
                v109 = *(_QWORD *)(a1 + 872) + 24LL * v107;
                *(_DWORD *)(a1 + 880) = v107 + 1;
                v110 = v104 - (_QWORD)*v101 + 1;
                v111 = devm_kmalloc(v75 + 16, v110, 3520);
                *(_QWORD *)(v109 + 16) = v111;
                if ( !v111 )
                {
                  v1 = v108;
                  if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v108 + 366) )
                  {
                    v138 = &unk_9401C;
                    v139 = _ReadStatusReg(SP_EL0);
                    goto LABEL_334;
                  }
                  goto LABEL_191;
                }
                v112 = *v101;
                v113 = v111;
                v114 = v104 - (_QWORD)*v101 + 1;
                v115 = strnlen(*v101, v114);
                if ( v115 == -1 && v114 != -1 )
                {
                  _fortify_panic(2);
LABEL_337:
                  v217 = _fortify_panic(7);
                  if ( (v218 & 0x200000000000LL) == 0 )
                    JUMPOUT(0x65280);
                  return msm_cvp_smmu_fault_handler(v217);
                }
                if ( v115 == v114 )
                  v116 = v114;
                else
                  v116 = v115 + 1;
                if ( v116 > v110 )
                  goto LABEL_337;
                sized_strscpy(v113, v112);
                property = of_find_property(v106, "qcom,support-hw-trigger", 0);
                v75 = v220;
                v1 = v108;
                *(_BYTE *)(v109 + 8) = property != 0;
                if ( (msm_cvp_debug & 0x100) != 0 && !*((_DWORD *)v108 + 366) )
                {
                  if ( property )
                    v118 = &unk_89A2E;
                  else
                    v118 = &unk_910A9;
                  printk(&unk_8E61D, "core", *(_QWORD *)(v109 + 16), v118);
                }
              }
              else if ( (msm_cvp_debug & 2) != 0 && !*((_DWORD *)v1 + 366) )
              {
                printk(&unk_8D7F4, *(unsigned int *)(v219 + 1800), *(unsigned int *)(v219 + 1804), "warn");
              }
            }
          }
          v101 = (const char **)v101[3];
        }
        while ( v101 );
      }
      if ( !*(_DWORD *)(a1 + 880) && (msm_cvp_debug & 0x100) != 0 && !*((_DWORD *)v1 + 366) )
        printk(&unk_8FC3B, "core", v99, v100);
    }
    goto LABEL_229;
  }
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    printk(&unk_8335C, "core", 1, v73);
  v82 = *(_QWORD *)(a1 + 864);
  *(_DWORD *)(a1 + 1088) = 0;
  *(_QWORD *)(a1 + 1080) = 0;
  v83 = *(_QWORD *)(v82 + 760);
  v84 = of_property_read_string_helper(v83, "power-domain-names", 0, 0, 0);
  *(_DWORD *)(a1 + 1088) = v84;
  if ( !v84 )
  {
    v8 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v123 = _ReadStatusReg(SP_EL0);
      printk(&unk_8F0C4, *(unsigned int *)(v123 + 1800), *(unsigned int *)(v123 + 1804), &unk_8E7CE);
      v8 = -22;
    }
    goto LABEL_226;
  }
  v85 = devm_kmalloc(v82 + 16, 24LL * v84, 3520);
  *(_QWORD *)(a1 + 1080) = v85;
  if ( !v85 )
  {
    v8 = -12;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v124 = _ReadStatusReg(SP_EL0);
      printk(&unk_8FC5F, *(unsigned int *)(v124 + 1800), *(unsigned int *)(v124 + 1804), &unk_8E7CE);
      v8 = -12;
    }
    goto LABEL_226;
  }
  v86 = *(unsigned int *)(a1 + 1088);
  v221 = v3;
  v222 = v2;
  v87 = devm_kmalloc(v82 + 16, 4 * v86, 3520);
  if ( v87 )
  {
    v88 = v87;
    v89 = of_property_read_variable_u32_array(v83, "gdsc_has_hw_pc", v87, *(unsigned int *)(a1 + 1088), 0);
    if ( v89 < 0 )
    {
      v8 = v89 & (v89 >> 31);
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_222;
      v131 = _ReadStatusReg(SP_EL0);
      v132 = *(unsigned int *)(v131 + 1800);
      v133 = *(unsigned int *)(v131 + 1804);
      v134 = &unk_929CB;
    }
    else
    {
      if ( !*(_DWORD *)(a1 + 1088) )
        goto LABEL_229;
      v90 = 0;
      while ( 1 )
      {
        v91 = v90;
        if ( v86 <= (int)v90 )
          goto LABEL_335;
        v92 = v1;
        v93 = *(_QWORD *)(a1 + 1080) + 24LL * (int)v90;
        *(_BYTE *)(v93 + 8) = *(_DWORD *)(v88 + 4LL * (int)v90) != 0;
        v94 = of_property_read_string_helper(v83, "power-domain-names", v93 + 16, 1, v90);
        if ( (v94 & 0x80000000) != 0 )
          break;
        v95 = dev_pm_domain_attach_by_name(v82 + 16, *(_QWORD *)(v93 + 16));
        v8 = v95;
        *(_QWORD *)v93 = v95;
        if ( !v95 || v95 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (msm_cvp_debug & 1) != 0 )
          {
            v1 = v92;
            if ( !*((_DWORD *)v92 + 366) )
            {
              v143 = _ReadStatusReg(SP_EL0);
              printk(&unk_8E654, *(unsigned int *)(v143 + 1800), *(unsigned int *)(v143 + 1804), &unk_8E7CE);
            }
            goto LABEL_222;
          }
LABEL_221:
          v1 = v92;
          goto LABEL_222;
        }
        if ( (msm_cvp_debug & 0x100) != 0 && !*((_DWORD *)v92 + 366) )
          printk(&unk_887C7, "core", "msm_cvp_load_PD_table", *(_QWORD *)(v93 + 16));
        v90 = v91 + 1;
        v1 = v92;
        if ( v91 + 1 >= *(_DWORD *)(a1 + 1088) )
          goto LABEL_229;
      }
      v8 = v94;
      if ( (msm_cvp_debug & 1) == 0 )
        goto LABEL_221;
      v1 = v92;
      if ( *((_DWORD *)v92 + 366) )
        goto LABEL_222;
      v142 = _ReadStatusReg(SP_EL0);
      v132 = *(unsigned int *)(v142 + 1800);
      v133 = *(unsigned int *)(v142 + 1804);
      v134 = &unk_8CCA9;
    }
    printk(v134, v132, v133, &unk_8E7CE);
    goto LABEL_222;
  }
  v8 = -12;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v126 = _ReadStatusReg(SP_EL0);
    printk(&unk_9551D, *(unsigned int *)(v126 + 1800), *(unsigned int *)(v126 + 1804), &unk_8E7CE);
    v8 = -12;
  }
LABEL_222:
  if ( *(_DWORD *)(a1 + 1088) )
  {
    v144 = 0;
    do
    {
      v145 = (_QWORD *)(*(_QWORD *)(a1 + 1080) + 24LL * (int)v144++);
      v145[2] = 0;
      *v145 = 0;
    }
    while ( v144 < *(_DWORD *)(a1 + 1088) );
  }
  *(_QWORD *)(a1 + 1080) = 0;
  *(_DWORD *)(a1 + 1088) = 0;
  if ( v8 )
  {
LABEL_226:
    if ( (msm_cvp_debug & 1) != 0 )
    {
      v146 = (_DWORD *)(a1 + 1072);
      if ( !*((_DWORD *)v1 + 366) )
      {
        v147 = _ReadStatusReg(SP_EL0);
        printk(&unk_8540D, *(unsigned int *)(v147 + 1800), *(unsigned int *)(v147 + 1804), &unk_8E7CE);
      }
    }
    else
    {
      v146 = (_DWORD *)(a1 + 1072);
    }
    goto LABEL_329;
  }
LABEL_229:
  v148 = *(_QWORD *)(a1 + 864);
  v149 = of_property_read_string_helper(*(_QWORD *)(v148 + 760), "clock-names", 0, 0, 0);
  if ( v149 > 0 )
  {
    v152 = v149;
    v153 = 4LL * (unsigned int)v149;
    v154 = devm_kmalloc(v148 + 16, v153, 3520);
    if ( v154 )
    {
      v155 = v154;
      v156 = of_property_read_variable_u32_array(*(_QWORD *)(v148 + 760), "clock-ids", v154, v152, 0);
      v146 = (_DWORD *)(a1 + 1072);
      if ( v156 < 0 )
      {
        v159 = *((_DWORD *)v1 + 366);
        v160 = msm_cvp_debug & 0x100;
        if ( (msm_cvp_debug & 0x100) != 0 && !v159 )
        {
          printk(&unk_867F6, "core", v156 & (unsigned int)(v156 >> 31), v158);
          v159 = *((_DWORD *)v1 + 366);
          v160 = msm_cvp_debug & 0x100;
        }
        msm_cvp_mmrm_enabled = 0;
        if ( v160 && !v159 )
          printk(&unk_949FE, "core", v157, v158);
      }
      v161 = devm_kmalloc(v148 + 16, 4LL * v152, 3520);
      if ( v161 )
      {
        v162 = v161;
        v163 = of_property_read_variable_u32_array(*(_QWORD *)(v148 + 760), "qcom,clock-configs", v161, v152, 0);
        if ( v163 < 0 )
        {
          v8 = v163 & (v163 >> 31);
          if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v1 + 366) )
          {
            v204 = _ReadStatusReg(SP_EL0);
            printk(&unk_83407, *(unsigned int *)(v204 + 1800), *(unsigned int *)(v204 + 1804), &unk_8E7CE);
          }
          goto LABEL_311;
        }
        v164 = 32LL * v152;
        v165 = devm_kmalloc(v148 + 16, v164, 3520);
        *(_QWORD *)(a1 + 888) = v165;
        if ( v165 )
        {
          v167 = BYTE1(msm_cvp_debug);
          *(_DWORD *)(a1 + 896) = v152;
          if ( (v167 & 1) != 0 && !*((_DWORD *)v1 + 366) )
            printk(&unk_8D821, "core", v152, v166);
          v168 = 0;
          v169 = 0;
          v170 = 0;
          while ( 1 )
          {
            v171 = *(_QWORD *)(a1 + 888);
            of_property_read_string_helper(*(_QWORD *)(v148 + 760), "clock-names", v171 + v169, 1, v168);
            if ( msm_cvp_mmrm_enabled == 1 )
            {
              if ( v153 <= v170 )
                break;
              *(_DWORD *)(v171 + v169 + 8) = *(_DWORD *)(v155 + v170);
            }
            if ( v164 == v169 || v153 <= v170 )
              break;
            if ( (*(_BYTE *)(v162 + v170) & 1) != 0 )
            {
              v172 = 1;
            }
            else
            {
              v172 = 0;
              *(_DWORD *)(v171 + v169 + 24) = 0;
            }
            *(_BYTE *)(v171 + v169 + 28) = v172;
            if ( v153 <= v170 )
              break;
            *(_BYTE *)(v171 + v169 + 29) = (*(_BYTE *)(v162 + v170) & 2) != 0;
            if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
              printk(&unk_92A1B, "core", *(_QWORD *)(v171 + v169), *(unsigned int *)(v171 + v169 + 8));
            v169 += 32;
            v170 += 4LL;
            ++v168;
            if ( v164 == v169 )
              goto LABEL_262;
          }
LABEL_335:
          __break(1u);
        }
        v8 = -12;
        if ( (msm_cvp_debug & 1) == 0 || *((_DWORD *)v1 + 366) )
          goto LABEL_311;
        v209 = _ReadStatusReg(SP_EL0);
        v183 = *(unsigned int *)(v209 + 1800);
        v184 = *(unsigned int *)(v209 + 1804);
        v185 = &unk_94A32;
        goto LABEL_310;
      }
      v8 = -12;
      if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v1 + 366) )
      {
        v186 = _ReadStatusReg(SP_EL0);
        v183 = *(unsigned int *)(v186 + 1800);
        v184 = *(unsigned int *)(v186 + 1804);
        v185 = &unk_8A3CD;
        goto LABEL_310;
      }
    }
    else
    {
      v8 = -12;
      if ( (msm_cvp_debug & 1) != 0 )
      {
        v146 = (_DWORD *)(a1 + 1072);
        if ( !*((_DWORD *)v1 + 366) )
        {
          v182 = _ReadStatusReg(SP_EL0);
          v183 = *(unsigned int *)(v182 + 1800);
          v184 = *(unsigned int *)(v182 + 1804);
          v185 = &unk_85D25;
LABEL_310:
          printk(v185, v183, v184, &unk_8E7CE);
          v8 = -12;
        }
      }
      else
      {
        v146 = (_DWORD *)(a1 + 1072);
      }
    }
LABEL_311:
    if ( (msm_cvp_debug & 1) != 0 && !*((_DWORD *)v1 + 366) )
    {
      v210 = _ReadStatusReg(SP_EL0);
      printk(&unk_87DCB, *(unsigned int *)(v210 + 1800), *(unsigned int *)(v210 + 1804), &unk_8E7CE);
    }
    goto LABEL_324;
  }
  if ( (msm_cvp_debug & 0x100) != 0 && !*((_DWORD *)v1 + 366) )
    printk(&unk_83FCC, "core", v150, v151);
  *(_DWORD *)(a1 + 896) = 0;
LABEL_262:
  v173 = *(_QWORD *)(a1 + 864);
  if ( !of_find_property(*(_QWORD *)(v173 + 760), "qcom,allowed-clock-rates", 0) )
  {
    v178 = v221;
    v177 = v222;
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      printk(&unk_83444, "core", v174, v175);
LABEL_279:
    v187 = *(_QWORD *)(a1 + 864);
    v188 = *(_QWORD *)(v187 + 760);
    LODWORD(v230) = 0;
    v228 = 0;
    v229 = 0;
    v189 = of_property_read_string_helper(v188, "reset-names", 0, 0, 0);
    if ( v189 - 6 <= 0xFFFFFFFA )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v214 = _ReadStatusReg(SP_EL0);
        printk(&unk_85472, *(unsigned int *)(v214 + 1800), *(unsigned int *)(v214 + 1804), &unk_8E7CE);
      }
      *(_DWORD *)(a1 + 928) = 0;
LABEL_284:
      v190 = of_find_property(*(_QWORD *)(v177 + 760), "qcom,use-non-secure-pil", 0);
      *(_BYTE *)(a1 + 936) = v190 != 0;
      if ( v190 || (_QWORD *)*v178 == v178 )
      {
        of_property_read_variable_u32_array(*(_QWORD *)(v177 + 760), "qcom,fw-bias", &v223, 1, 0);
        v192 = BYTE1(msm_cvp_debug);
        *(_QWORD *)(a1 + 608) = v223;
        if ( (v192 & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_954F9, "core", a1 + 608, v191);
      }
      v206 = *(_QWORD *)(a1 + 264);
      v8 = 0;
      v208 = *(_QWORD *)(v206 + 40);
      v207 = *(_QWORD *)(v206 + 48);
      cvp_hfi_defs = v208;
      cvp_hfi_msg_defs = v207;
      goto LABEL_332;
    }
    v193 = v189;
    v194 = v189;
    v195 = devm_kmalloc(v187 + 16, 24LL * v189, 3520);
    *(_QWORD *)(a1 + 920) = v195;
    if ( v195 )
    {
      v197 = BYTE1(msm_cvp_debug);
      *(_DWORD *)(a1 + 928) = v194;
      if ( (v197 & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_8C29D, "core", v194, v196);
      v198 = of_property_read_variable_u32_array(*(_QWORD *)(v187 + 760), "reset-power-status", &v228, v193, 0);
      if ( (v198 & 0x80000000) == 0 )
      {
        v199 = *(_QWORD *)(a1 + 920);
        of_property_read_string_helper(*(_QWORD *)(v187 + 760), "reset-names", v199 + 16, 1, 0);
        *(_DWORD *)(v199 + 8) = v228;
        if ( v194 != 1 )
        {
          v200 = *(_QWORD *)(a1 + 920);
          of_property_read_string_helper(*(_QWORD *)(v187 + 760), "reset-names", v200 + 40, 1, 1);
          *(_DWORD *)(v200 + 32) = HIDWORD(v228);
          if ( v194 != 2 )
          {
            v201 = *(_QWORD *)(a1 + 920);
            of_property_read_string_helper(*(_QWORD *)(v187 + 760), "reset-names", v201 + 64, 1, 2);
            *(_DWORD *)(v201 + 56) = v229;
            if ( v194 != 3 )
            {
              v202 = *(_QWORD *)(a1 + 920);
              of_property_read_string_helper(*(_QWORD *)(v187 + 760), "reset-names", v202 + 88, 1, 3);
              *(_DWORD *)(v202 + 80) = HIDWORD(v229);
              if ( v194 != 4 )
              {
                v203 = *(_QWORD *)(a1 + 920);
                of_property_read_string_helper(*(_QWORD *)(v187 + 760), "reset-names", v203 + 112, 1, 4);
                *(_DWORD *)(v203 + 104) = v230;
              }
            }
          }
        }
        goto LABEL_284;
      }
      v8 = v198 & (v198 >> 31);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v216 = _ReadStatusReg(SP_EL0);
        printk(&unk_8F100, *(unsigned int *)(v216 + 1800), *(unsigned int *)(v216 + 1804), &unk_8E7CE);
      }
      devm_kfree(v187 + 16, *(_QWORD *)(a1 + 920));
    }
    else
    {
      v8 = -12;
    }
    v146 = (_DWORD *)(a1 + 1072);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v215 = _ReadStatusReg(SP_EL0);
      printk(&unk_8FB89, *(unsigned int *)(v215 + 1800), *(unsigned int *)(v215 + 1804), &unk_8E7CE);
    }
    *(_QWORD *)(a1 + 768) = 0;
    goto LABEL_323;
  }
  u32_table = msm_cvp_load_u32_table(
                v173,
                *(_QWORD *)(v173 + 760),
                (__int64)"qcom,allowed-clock-rates",
                4,
                (__int64 *)(a1 + 768),
                (_DWORD *)(a1 + 776));
  v178 = v221;
  v177 = v222;
  if ( !u32_table )
  {
    sort(*(_QWORD *)(a1 + 768), *(unsigned int *)(a1 + 776), 4, cmp, 0);
    goto LABEL_279;
  }
  v179 = msm_cvp_debug_out;
  v8 = u32_table;
  v180 = msm_cvp_debug & 1;
  if ( (msm_cvp_debug & 1) != 0 )
  {
    v146 = (_DWORD *)(a1 + 1072);
    if ( !msm_cvp_debug_out )
    {
      v181 = _ReadStatusReg(SP_EL0);
      printk(&unk_85D5A, *(unsigned int *)(v181 + 1800), *(unsigned int *)(v181 + 1804), &unk_8E7CE);
      v179 = msm_cvp_debug_out;
      v180 = msm_cvp_debug & 1;
    }
  }
  else
  {
    v146 = (_DWORD *)(a1 + 1072);
  }
  if ( v180 && !v179 )
  {
    v205 = _ReadStatusReg(SP_EL0);
    printk(&unk_8D6B8, *(unsigned int *)(v205 + 1800), *(unsigned int *)(v205 + 1804), &unk_8E7CE);
  }
LABEL_323:
  *(_QWORD *)(a1 + 888) = 0;
  *(_DWORD *)(a1 + 896) = 0;
LABEL_324:
  if ( *v146 )
  {
LABEL_330:
    *(_QWORD *)(a1 + 1080) = 0;
    goto LABEL_331;
  }
  if ( *(_DWORD *)(a1 + 880) )
  {
    v211 = 0;
    do
    {
      v212 = *(_QWORD *)(a1 + 872) + 24LL * (int)v211++;
      *(_QWORD *)(v212 + 16) = 0;
    }
    while ( v211 < *(_DWORD *)(a1 + 880) );
  }
  *(_QWORD *)(a1 + 872) = 0;
  *(_DWORD *)(a1 + 880) = 0;
LABEL_329:
  if ( *v146 )
    goto LABEL_330;
LABEL_331:
  *(_QWORD *)(a1 + 824) = 0;
LABEL_332:
  _ReadStatusReg(SP_EL0);
  return v8;
}
