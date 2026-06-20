__int64 __fastcall cam_smmu_get_memory_regions_info(__int64 a1, __int64 a2)
{
  __int64 child_by_name; // x21
  __int64 property; // x0
  __int64 next_available_child; // x0
  _BOOL4 v7; // w24
  __int64 v8; // x25
  int v9; // w26
  __int64 discard_memory_regions; // x0
  __int64 v11; // x1
  __int64 v12; // x7
  __int64 v13; // x28
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  int v17; // w10
  __int64 v18; // x7
  __int64 v19; // x27
  __int64 v20; // x0
  __int64 v21; // x9
  __int64 v22; // x0
  unsigned int variable_u32_array; // w0
  int v24; // w8
  __int64 v25; // x7
  __int64 v26; // x28
  __int64 v27; // x0
  __int64 v28; // x9
  __int64 v29; // x0
  unsigned int v30; // w0
  int v31; // w8
  __int64 v32; // x7
  __int64 v33; // x28
  __int64 v34; // x0
  __int64 v35; // x9
  __int64 v36; // x0
  int v37; // w8
  __int64 v38; // x7
  __int64 v39; // x28
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x9
  int v43; // w10
  __int64 v44; // x8
  __int64 v45; // x9
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x7
  __int64 v49; // x28
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x9
  int v53; // w10
  int v54; // w8
  __int64 v55; // x1
  const char *v56; // x5
  __int64 v57; // x4
  unsigned int v58; // w27
  int v60; // w9
  unsigned __int64 v61; // x6
  __int64 v62; // x8
  __int64 v63; // x7
  __int64 v64; // x10
  unsigned __int64 v65; // x9
  unsigned __int64 v66; // x10
  __int64 v67; // [xsp+10h] [xbp-70h]
  const char *v68; // [xsp+50h] [xbp-30h] BYREF
  int v69; // [xsp+5Ch] [xbp-24h] BYREF
  __int64 v70; // [xsp+60h] [xbp-20h] BYREF
  __int64 v71; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v72[2]; // [xsp+70h] [xbp-10h] BYREF

  v72[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = 0;
  v72[0] = 0;
  v70 = 0;
  v68 = nullptr;
  if ( !a1 || !a2 )
  {
    v56 = "Invalid argument(s)";
    v57 = 4905;
    goto LABEL_74;
  }
  v69 = 0;
  child_by_name = of_get_child_by_name();
  property = of_find_property(a1, "qcom,secure-cb", 0);
  *(_BYTE *)(a2 + 80) = property != 0;
  if ( !child_by_name )
  {
    if ( property )
    {
LABEL_106:
      v58 = 0;
      goto LABEL_76;
    }
    v56 = "iova-mem-map not present";
    v57 = 4919;
LABEL_74:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_memory_regions_info",
      v57,
      v56);
LABEL_75:
    v58 = -22;
    goto LABEL_76;
  }
  next_available_child = of_get_next_available_child(child_by_name, 0);
  v7 = 1;
  v72[0] = next_available_child;
  if ( !next_available_child )
  {
LABEL_82:
    if ( !*(_BYTE *)(a2 + 84) )
      goto LABEL_104;
    discard_memory_regions = cam_smmu_get_discard_memory_regions(a1, a2 + 8656, a2 + 8664);
    if ( (_DWORD)discard_memory_regions )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_get_memory_regions_info",
        5184,
        "Invalid Discard region specified in CB, rc=%d",
        discard_memory_regions);
      goto LABEL_75;
    }
    v60 = *(_DWORD *)(a2 + 2992);
    if ( v60 < 1 )
      goto LABEL_104;
    v61 = *(_QWORD *)(a2 + 8656);
    v62 = *(_QWORD *)(a2 + 3600);
    v63 = *(_QWORD *)(a2 + 8664);
    v64 = *(_QWORD *)(a2 + 3608);
    if ( v61 == v62 && v63 == v64 )
    {
      if ( v61 && v63 )
      {
        v65 = *(_QWORD *)(a2 + 3584);
        v66 = *(_QWORD *)(a2 + 3592) + v65;
        if ( v61 <= v65 || v61 >= v66 || v63 + v61 >= v66 )
          goto LABEL_108;
        discard_memory_regions = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   64,
                                   3,
                                   "cam_smmu_validate_discard_iova_region",
                                   4886,
                                   "[%s] : Discard region specified [0x%x 0x%x] in [0x%x 0x%x]",
                                   *(const char **)(a2 + 32),
                                   *(_QWORD *)(a2 + 8656),
                                   (int)v63 + (int)v61,
                                   *(_QWORD *)(a2 + 3584),
                                   v66);
        v60 = *(_DWORD *)(a2 + 2992);
      }
      if ( v60 < 2 )
      {
LABEL_104:
        if ( v7 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_get_memory_regions_info",
            5198,
            "No memory regions found, at least one needed");
          v58 = -19;
          goto LABEL_76;
        }
        goto LABEL_106;
      }
      v61 = *(_QWORD *)(a2 + 8656);
      v62 = *(_QWORD *)(a2 + 4272);
      v63 = *(_QWORD *)(a2 + 8664);
      v64 = *(_QWORD *)(a2 + 4280);
      if ( v61 == v62 && v63 == v64 )
      {
        if ( !v61 || !v63 )
        {
LABEL_103:
          if ( v60 > 2 )
          {
LABEL_118:
            __break(0x5512u);
            return cam_smmu_setup_cb(discard_memory_regions, v11);
          }
          goto LABEL_104;
        }
        v65 = *(_QWORD *)(a2 + 4256);
        v66 = *(_QWORD *)(a2 + 4264) + v65;
        if ( v61 > v65 && v61 < v66 && v63 + v61 < v66 )
        {
          discard_memory_regions = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                     3,
                                     64,
                                     3,
                                     "cam_smmu_validate_discard_iova_region",
                                     4886,
                                     "[%s] : Discard region specified [0x%x 0x%x] in [0x%x 0x%x]",
                                     *(const char **)(a2 + 32),
                                     *(_QWORD *)(a2 + 8656),
                                     (int)v63 + (int)v61,
                                     *(_QWORD *)(a2 + 4256),
                                     v66);
          v60 = *(_DWORD *)(a2 + 2992);
          goto LABEL_103;
        }
LABEL_108:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_validate_discard_iova_region",
          4876,
          "[%s] : Incorrect Discard region specified [0x%x 0x%x] in [0x%x 0x%x]",
          *(_QWORD *)(a2 + 32),
          v61,
          v63 + v61,
          v65,
          v66);
        goto LABEL_75;
      }
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, __int64, __int64, __int64, __int64))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_validate_discard_iova_region",
      4861,
      "Mismatch Discard region specified, [0x%x 0x%x] [0x%x 0x%x]",
      v61,
      v63,
      v62,
      v64,
      v67);
    goto LABEL_75;
  }
  v8 = next_available_child;
  v9 = 0;
  while ( 1 )
  {
    if ( (of_property_read_string(v8, "iova-region-name", &v68) & 0x80000000) != 0 )
    {
      v56 = "IOVA region not found";
      v57 = 4930;
      goto LABEL_74;
    }
    discard_memory_regions = cam_smmu_get_iova_info_util(v72, &v71, &v70, &v69);
    if ( (_DWORD)discard_memory_regions )
      goto LABEL_79;
    if ( v69 <= 3 )
    {
      if ( v69 > 1 )
      {
        if ( v69 == 2 )
        {
          v47 = v70;
          v46 = v71;
          *(_BYTE *)(a2 + 81) = 1;
          *(_QWORD *)(a2 + 160) = v46;
          *(_QWORD *)(a2 + 168) = v47;
        }
        else
        {
          v25 = *(unsigned int *)(a2 + 2992);
          if ( (int)v25 >= 2 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _QWORD, int))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_get_memory_regions_info",
              5017,
              "Exceeding max supported number of regions max: %u current: %u in cb: %s for region: %d",
              2,
              v25,
              *(_QWORD *)(a2 + 32),
              3);
            goto LABEL_75;
          }
          if ( (unsigned int)v25 > 2 )
            goto LABEL_118;
          v26 = a2 + 3000 + 672LL * (unsigned int)v25;
          v27 = of_find_property(v8, "subregion_support", 0);
          *(_BYTE *)(v26 + 665) = v27 != 0;
          if ( v27 )
          {
            LODWORD(discard_memory_regions) = cam_smmu_get_subregions_memory_info(v72, v26, a2);
            if ( (_DWORD)discard_memory_regions )
              goto LABEL_79;
          }
          v28 = v70;
          v29 = v72[0];
          *(_QWORD *)(v26 + 584) = v71;
          *(_QWORD *)(v26 + 592) = v28;
          v30 = cam_smmu_get_discard_memory_regions(v29, v26 + 600, v26 + 608);
          if ( v30 )
          {
            v58 = v30;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_get_memory_regions_info",
              5041,
              "Invalid Discard region specified in IO region, rc: %d cb: %s",
              v30,
              *(const char **)(a2 + 32));
            goto LABEL_76;
          }
          v31 = *(_DWORD *)(a2 + 2992);
          *(_BYTE *)(a2 + 84) = 1;
          *(_DWORD *)(a2 + 2992) = v31 + 1;
        }
      }
      else if ( v69 )
      {
        if ( v69 != 1 )
          goto LABEL_55;
        v12 = *(unsigned int *)(a2 + 1640);
        if ( (int)v12 >= 2 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _QWORD, int))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_get_memory_regions_info",
            4981,
            "Exceeding max supported number of regions max: %u current: %u in cb: %s for region: %d",
            2,
            v12,
            *(_QWORD *)(a2 + 32),
            1);
          goto LABEL_75;
        }
        if ( (unsigned int)v12 > 2 )
          goto LABEL_118;
        v13 = a2 + 1648 + 672LL * (unsigned int)v12;
        v14 = of_find_property(v8, "subregion_support", 0);
        *(_BYTE *)(v13 + 665) = v14 != 0;
        if ( v14 )
        {
          LODWORD(discard_memory_regions) = cam_smmu_get_subregions_memory_info(v72, v13, a2);
          if ( (_DWORD)discard_memory_regions )
            goto LABEL_79;
        }
        v16 = v70;
        v15 = v71;
        v17 = *(_DWORD *)(a2 + 1640);
        *(_BYTE *)(a2 + 83) = 1;
        *(_QWORD *)(v13 + 584) = v15;
        *(_QWORD *)(v13 + 592) = v16;
        *(_DWORD *)(a2 + 1640) = v17 + 1;
      }
      else
      {
        v38 = *(unsigned int *)(a2 + 288);
        if ( (int)v38 >= 2 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _QWORD, _DWORD))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_get_memory_regions_info",
            4950,
            "Exceeding max supported number of regions max: %u current: %u in cb: %s for region: %d",
            2,
            v38,
            *(_QWORD *)(a2 + 32),
            0);
          goto LABEL_75;
        }
        if ( (unsigned int)v38 > 2 )
          goto LABEL_118;
        v39 = a2 + 296 + 672LL * (unsigned int)v38;
        v40 = of_find_property(v8, "subregion_support", 0);
        *(_BYTE *)(v39 + 665) = v40 != 0;
        if ( v40 )
        {
          LODWORD(discard_memory_regions) = cam_smmu_get_subregions_memory_info(v72, v39, a2);
          if ( (_DWORD)discard_memory_regions )
            goto LABEL_79;
        }
        v42 = v70;
        v41 = v71;
        v43 = *(_DWORD *)(a2 + 288);
        *(_BYTE *)(a2 + 82) = 1;
        *(_QWORD *)(v39 + 584) = v41;
        *(_QWORD *)(v39 + 592) = v42;
        *(_DWORD *)(a2 + 288) = v43 + 1;
      }
      goto LABEL_56;
    }
    if ( v69 <= 5 )
      break;
    if ( v69 == 6 )
    {
      v48 = *(unsigned int *)(a2 + 4344);
      if ( (int)v48 >= 2 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _QWORD, int))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_get_memory_regions_info",
          5061,
          "Exceeding max supported number of regions max: %u current: %u in cb: %s for region: %d",
          2,
          v48,
          *(_QWORD *)(a2 + 32),
          6);
        goto LABEL_75;
      }
      if ( (unsigned int)v48 > 2 )
        goto LABEL_118;
      v49 = a2 + 4352 + 672LL * (unsigned int)v48;
      v50 = of_find_property(v8, "subregion_support", 0);
      *(_BYTE *)(v49 + 665) = v50 != 0;
      if ( v50 )
      {
        LODWORD(discard_memory_regions) = cam_smmu_get_subregions_memory_info(v72, v49, a2);
        if ( (_DWORD)discard_memory_regions )
        {
LABEL_79:
          v58 = discard_memory_regions;
          goto LABEL_76;
        }
      }
      v52 = v70;
      v51 = v71;
      v53 = *(_DWORD *)(a2 + 4344);
      *(_BYTE *)(a2 + 86) = 1;
      *(_QWORD *)(v49 + 584) = v51;
      *(_QWORD *)(v49 + 592) = v52;
      *(_DWORD *)(a2 + 4344) = v53 + 1;
    }
    else
    {
      if ( v69 != 7 )
      {
LABEL_55:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_get_memory_regions_info",
          5167,
          "Incorrect region id present in DT file: %d",
          v69);
        goto LABEL_56;
      }
      v32 = *(unsigned int *)(a2 + 5696);
      if ( (int)v32 >= 2 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _QWORD, int))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_get_memory_regions_info",
          5133,
          "Exceeding max supported number of regions max: %u current: %u in cb: %s for region: %d",
          2,
          v32,
          *(_QWORD *)(a2 + 32),
          7);
        goto LABEL_75;
      }
      if ( (unsigned int)v32 > 2 )
        goto LABEL_118;
      v33 = a2 + 5704 + 672LL * (unsigned int)v32;
      v34 = of_find_property(v8, "subregion_support", 0);
      *(_BYTE *)(v33 + 665) = v34 != 0;
      if ( v34 )
      {
        LODWORD(discard_memory_regions) = cam_smmu_get_subregions_memory_info(v72, v33, a2);
        if ( (_DWORD)discard_memory_regions )
          goto LABEL_79;
      }
      v35 = v70;
      v36 = v72[0];
      *(_QWORD *)(v33 + 584) = v71;
      *(_QWORD *)(v33 + 592) = v35;
      if ( (of_property_read_variable_u32_array(v36, "phy-addr", v33 + 616, 1, 0) & 0x80000000) != 0
        && (debug_mdl & 0x40) != 0
        && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_get_memory_regions_info",
          5156,
          "No phy-addr field in device in cb: %s",
          *(const char **)(a2 + 32));
      }
      v37 = *(_DWORD *)(a2 + 5696);
      *(_BYTE *)(a2 + 88) = 1;
      *(_DWORD *)(a2 + 5696) = v37 + 1;
    }
LABEL_56:
    v54 = debug_priority;
    v55 = debug_mdl & 0x40;
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v55,
        4,
        "cam_smmu_get_memory_regions_info",
        5170,
        "Found label -> %s",
        *(const char **)(a2 + 32));
      v54 = debug_priority;
      v55 = debug_mdl & 0x40;
      if ( (debug_mdl & 0x40) == 0 )
        goto LABEL_61;
    }
    else if ( (debug_mdl & 0x40) == 0 )
    {
      goto LABEL_61;
    }
    if ( !v54 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v55,
        4,
        "cam_smmu_get_memory_regions_info",
        5171,
        "Found region -> %s",
        v68);
      v54 = debug_priority;
      v55 = debug_mdl & 0x40;
    }
LABEL_61:
    if ( v55 && !v54 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v55,
        4,
        "cam_smmu_get_memory_regions_info",
        5172,
        "region_start -> 0x%lx",
        v71);
      v54 = debug_priority;
      v55 = debug_mdl & 0x40;
      if ( (debug_mdl & 0x40) != 0 )
      {
LABEL_64:
        if ( !v54 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v55,
            4,
            "cam_smmu_get_memory_regions_info",
            5173,
            "region_len -> 0x%lx",
            v70);
          v54 = debug_priority;
          v55 = debug_mdl & 0x40;
        }
      }
    }
    else if ( v55 )
    {
      goto LABEL_64;
    }
    if ( v55 && !v54 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v55,
        4,
        "cam_smmu_get_memory_regions_info",
        5174,
        "region_id -> 0x%x",
        v69);
    v8 = of_get_next_available_child(child_by_name, v72[0]);
    --v9;
    v72[0] = v8;
    if ( !v8 )
    {
      v7 = v9 == 0;
      goto LABEL_82;
    }
  }
  if ( v69 == 4 )
  {
    v45 = v70;
    v44 = v71;
    *(_BYTE *)(a2 + 85) = 1;
    *(_QWORD *)(a2 + 224) = v44;
    *(_QWORD *)(a2 + 232) = v45;
    goto LABEL_56;
  }
  v18 = *(unsigned int *)(a2 + 7048);
  if ( (int)v18 >= 2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _QWORD, int))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_memory_regions_info",
      5093,
      "Exceeding max supported number of regions max: %u current: %u in cb: %s for region: %d",
      2,
      v18,
      *(_QWORD *)(a2 + 32),
      5);
    goto LABEL_75;
  }
  if ( (unsigned int)v18 > 2 )
    goto LABEL_118;
  v19 = a2 + 7056 + 672LL * (unsigned int)v18;
  v20 = of_find_property(v8, "subregion_support", 0);
  *(_BYTE *)(v19 + 665) = v20 != 0;
  if ( v20 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_memory_regions_info",
      5106,
      "Subregion for QDSS not supported, failing cb: %s initialization",
      *(const char **)(a2 + 32));
    v58 = 0;
    goto LABEL_76;
  }
  v21 = v70;
  v22 = v72[0];
  *(_QWORD *)(v19 + 584) = v71;
  *(_QWORD *)(v19 + 592) = v21;
  variable_u32_array = of_property_read_variable_u32_array(v22, "qdss-phy-addr", v19 + 616, 1, 0);
  if ( (variable_u32_array & 0x80000000) == 0 )
  {
    v24 = *(_DWORD *)(a2 + 7048);
    *(_BYTE *)(a2 + 87) = 1;
    *(_DWORD *)(a2 + 7048) = v24 + 1;
    goto LABEL_56;
  }
  v58 = variable_u32_array;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_get_memory_regions_info",
    5117,
    "No phy-addr field for qdss in cb: %s",
    *(const char **)(a2 + 32));
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return v58;
}
