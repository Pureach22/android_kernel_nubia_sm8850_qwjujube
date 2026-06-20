__int64 ipa3_attach_to_smmu()
{
  __int64 v0; // x8
  __int64 v1; // x9
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x8
  char *v6; // x28
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  _QWORD *v10; // x27
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned __int64 domain_for_dev; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 property; // x0
  int v22; // w8
  int v23; // w9
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned int mappings_configuration; // w0
  int v28; // w21
  int v29; // w25
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  unsigned __int64 v37; // t2
  __int64 v38; // x25
  unsigned __int64 v39; // x27
  _DWORD *v40; // x8
  unsigned int v41; // w9
  __int64 v42; // x2
  unsigned __int64 v43; // x21
  unsigned int v44; // w10
  __int64 v45; // x22
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  unsigned __int64 v50; // x0
  bool v51; // zf
  __int64 v52; // x0
  char v53; // w8
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  int v57; // w0
  int v58; // w25
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x8
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x8
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x0
  __int64 v79; // x0
  unsigned __int64 v80; // x0
  __int64 v81; // x8
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  char v85; // w8
  __int64 v86; // x8
  __int64 v87; // x0
  __int64 v88; // x0
  int v89; // w5
  int v90; // w6
  __int64 v91; // x8
  __int64 v92; // x0
  __int64 v93; // x0
  unsigned __int64 v94; // x0
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  char v99; // w8
  __int64 v100; // x8
  __int64 v101; // x0
  __int64 v102; // x0
  unsigned int v103; // w0
  int v104; // w21
  int v105; // w25
  __int64 v106; // x9
  __int64 v107; // x0
  __int64 v108; // x0
  __int64 v109; // x8
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x8
  __int64 v113; // x0
  __int64 v114; // x0
  unsigned int v115; // w0
  int v116; // w21
  int v117; // w25
  __int64 v118; // x8
  __int64 v119; // x0
  __int64 v120; // x0
  __int64 v121; // x28
  unsigned __int64 v122; // t2
  int v123; // w0
  __int64 v124; // x8
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  int v129; // w0
  unsigned __int64 v130; // x0
  unsigned __int64 v131; // x25
  __int64 v132; // x28
  unsigned __int64 v133; // x21
  __int64 v134; // x8
  __int64 v135; // x22
  __int64 v136; // x0
  __int64 v137; // x0
  __int64 v138; // x8
  int v139; // w0
  __int64 v140; // x10
  __int64 v141; // x0
  __int64 v142; // x0
  unsigned __int64 v143; // x25
  _DWORD *v144; // x8
  unsigned int v145; // w9
  __int64 v146; // x2
  unsigned __int64 v147; // x21
  unsigned int v148; // w10
  __int64 v149; // x22
  __int64 v150; // x0
  __int64 v151; // x8
  __int64 v152; // x0
  __int64 v153; // x0
  __int64 v154; // x0
  __int64 v155; // x0
  __int64 v156; // x8
  __int64 v157; // x0
  __int64 v158; // x0
  __int64 v159; // x0
  __int64 v160; // x0
  __int64 v161; // x0
  __int64 v162; // x0
  __int64 v163; // x0
  __int64 v164; // x0
  __int64 v165; // x8
  __int64 v166; // x0
  __int64 v167; // x0
  __int64 v168; // x8
  __int64 v169; // x0
  __int64 v170; // x0
  __int64 v171; // x8
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x0
  __int64 v175; // x0
  __int64 v176; // x8
  __int64 v177; // x0
  __int64 v178; // x0
  __int64 v179; // x8
  __int64 v180; // x0
  __int64 v181; // x0
  __int64 v182; // x0
  __int64 v183; // x0
  __int64 v184; // x0
  __int64 v185; // x0
  __int64 v186; // x8
  __int64 v187; // x0
  __int64 v188; // x0
  __int64 v189; // x8
  __int64 v190; // x0
  __int64 v191; // x0
  __int64 v192; // x8
  __int64 v193; // x0
  __int64 v194; // x0
  __int64 v195; // x8
  __int64 v196; // x0
  __int64 v197; // x0
  int v198; // w21
  __int64 v199; // x8
  __int64 v200; // x0
  int v201; // w4
  __int64 v202; // x0
  __int64 v203; // x10
  __int64 v204; // x0
  __int64 result; // x0
  unsigned int v206; // w20
  __int64 v207; // x8
  __int64 v208; // x0
  __int64 v209; // x0
  __int64 v210; // [xsp+8h] [xbp-38h] BYREF
  __int64 v211; // [xsp+10h] [xbp-30h] BYREF
  unsigned __int64 v212; // [xsp+18h] [xbp-28h] BYREF
  __int64 v213; // [xsp+20h] [xbp-20h] BYREF
  __int64 v214; // [xsp+28h] [xbp-18h] BYREF
  size_t v215[2]; // [xsp+30h] [xbp-10h] BYREF

  v215[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v1 = ipa3_ctx + 0x8000;
  if ( byte_1F79A7 == 1 )
  {
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d smmu is enabled\n", "ipa3_attach_to_smmu", 11620);
        v0 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v0 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d smmu is enabled\n", "ipa3_attach_to_smmu", 11620);
    }
    v4 = 0;
    while ( 1 )
    {
      v6 = &smmu_cb[56 * v4];
      if ( v6[54] == 1 )
      {
        v7 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v8 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v8 )
          {
            ipc_log_string(v8, "ipa %s:%d SMMU CB type %d already initialized\n", "ipa_smmu_cb_probe", 11591, v4);
            v7 = ipa3_ctx;
          }
          v9 = *(_QWORD *)(v7 + 34160);
          if ( v9 )
            ipc_log_string(v9, "ipa %s:%d SMMU CB type %d already initialized\n", "ipa_smmu_cb_probe", 11591, v4);
        }
        goto LABEL_10;
      }
      v10 = *((_QWORD **)v6 + 1);
      if ( (unsigned int)v4 <= 6 )
      {
        if ( ((1 << v4) & 0x66) != 0 )
        {
          v11 = ipa3_ctx;
          LODWORD(v214) = 0;
          v215[0] = 0;
          if ( ipa3_ctx )
          {
            v12 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v12 )
            {
              ipc_log_string(v12, "ipa %s:%d CB %d PROBE dev=%pK\n", "ipa_smmu_perph_cb_probe", 11050, v4, v10);
              v11 = ipa3_ctx;
            }
            v13 = *(_QWORD *)(v11 + 34160);
            if ( v13 )
              ipc_log_string(v13, "ipa %s:%d CB %d PROBE dev=%pK\n", "ipa_smmu_perph_cb_probe", 11050, v4, v10);
          }
          if ( (smmu_info[v4] & 1) == 0 )
          {
            printk(&unk_3FA839, "ipa_smmu_perph_cb_probe");
            v5 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_9;
            v141 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v141 )
            {
              ipc_log_string(v141, "ipa %s:%d cb %d is disabled\n", "ipa_smmu_perph_cb_probe", 11053, v4);
              v5 = ipa3_ctx;
            }
            v142 = *(_QWORD *)(v5 + 34160);
            if ( v142 )
            {
              ipc_log_string(v142, "ipa %s:%d cb %d is disabled\n", "ipa_smmu_perph_cb_probe", 11053, v4);
              LODWORD(v5) = 0;
              goto LABEL_9;
            }
LABEL_274:
            LODWORD(v5) = 0;
            goto LABEL_9;
          }
          v14 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v15 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v15 )
            {
              ipc_log_string(
                v15,
                "ipa %s:%d CB %d PROBE dev=%pK retrieving IOMMU mapping\n",
                "ipa_smmu_perph_cb_probe",
                11057,
                v4,
                v10);
              v14 = ipa3_ctx;
            }
            v16 = *(_QWORD *)(v14 + 34160);
            if ( v16 )
              ipc_log_string(
                v16,
                "ipa %s:%d CB %d PROBE dev=%pK retrieving IOMMU mapping\n",
                "ipa_smmu_perph_cb_probe",
                11057,
                v4,
                v10);
          }
          domain_for_dev = iommu_get_domain_for_dev(v10);
          *((_QWORD *)v6 + 2) = domain_for_dev;
          if ( !domain_for_dev || domain_for_dev >= 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_3C92A2, "ipa_smmu_perph_cb_probe");
            v151 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v152 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v152 )
              {
                ipc_log_string(v152, "ipa %s:%d could not get iommu domain\n", "ipa_smmu_perph_cb_probe", 11061);
                v151 = ipa3_ctx;
              }
              v153 = *(_QWORD *)(v151 + 34160);
              if ( v153 )
              {
                ipc_log_string(v153, "ipa %s:%d could not get iommu domain\n", "ipa_smmu_perph_cb_probe", 11061);
LABEL_244:
                LODWORD(v5) = -22;
                goto LABEL_9;
              }
            }
            goto LABEL_308;
          }
          v18 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v19 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v19 )
            {
              ipc_log_string(v19, "ipa %s:%d CB %d PROBE mapping retrieved\n", "ipa_smmu_perph_cb_probe", 11065, v4);
              v18 = ipa3_ctx;
            }
            v20 = *(_QWORD *)(v18 + 34160);
            if ( v20 )
              ipc_log_string(v20, "ipa %s:%d CB %d PROBE mapping retrieved\n", "ipa_smmu_perph_cb_probe", 11065, v4);
          }
          property = of_find_property(v10[93], "dma-coherent", 0);
          *((_QWORD *)v6 + 1) = v10;
          *v6 = 1;
          *((_DWORD *)v6 + 10) = 0;
          v6[53] = property != 0;
          *((_QWORD *)v6 + 4) = 0;
          if ( (of_property_read_variable_u32_array(v10[93], "qcom,ipa-dma-addr-pool", v215, 2, 0) & 0x80000000) == 0 )
          {
            v22 = v215[0];
            v23 = HIDWORD(v215[0]);
            *((_DWORD *)v6 + 8) = v215[0];
            *((_DWORD *)v6 + 9) = v23;
            *((_DWORD *)v6 + 10) = v23 + v22;
          }
          v24 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v25 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v25 )
            {
              ipc_log_string(
                v25,
                "ipa %s:%d CB %d PROBE dev=%pK va_start=0x%x va_size=0x%x\n",
                "ipa_smmu_perph_cb_probe",
                11090,
                v4,
                v10,
                *((_DWORD *)v6 + 8),
                *((_DWORD *)v6 + 9));
              v24 = ipa3_ctx;
            }
            v26 = *(_QWORD *)(v24 + 34160);
            if ( v26 )
              ipc_log_string(
                v26,
                "ipa %s:%d CB %d PROBE dev=%pK va_start=0x%x va_size=0x%x\n",
                "ipa_smmu_perph_cb_probe",
                11090,
                v4,
                v10,
                *((_DWORD *)v6 + 8),
                *((_DWORD *)v6 + 9));
          }
          mappings_configuration = qcom_iommu_get_mappings_configuration(*((_QWORD *)v6 + 2));
          if ( (mappings_configuration & 0x80000000) != 0 )
          {
            printk(&unk_3EBB5D, "ipa_smmu_perph_cb_probe");
            v30 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v154 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v154 )
              {
                ipc_log_string(
                  v154,
                  "ipa %s:%d No Mapping configuration found for CB %d\n",
                  "ipa_smmu_perph_cb_probe",
                  11109,
                  v4);
                v30 = ipa3_ctx;
              }
              v155 = *(_QWORD *)(v30 + 34160);
              if ( v155 )
              {
                ipc_log_string(
                  v155,
                  "ipa %s:%d No Mapping configuration found for CB %d\n",
                  "ipa_smmu_perph_cb_probe",
                  11109,
                  v4);
                v29 = 0;
                v28 = 0;
                v30 = ipa3_ctx;
                if ( !ipa3_ctx )
                  goto LABEL_50;
              }
              else
              {
                v29 = 0;
                v28 = 0;
                if ( !v30 )
                  goto LABEL_50;
              }
LABEL_46:
              v31 = *(_QWORD *)(v30 + 34152);
              if ( v31 )
              {
                ipc_log_string(
                  v31,
                  "ipa %s:%d CB %d PROBE dev=%pK DOMAIN ATTRS bypass=%d fast=%d\n",
                  "ipa_smmu_perph_cb_probe",
                  11120,
                  v4,
                  v10,
                  v29,
                  v28);
                v30 = ipa3_ctx;
              }
              v32 = *(_QWORD *)(v30 + 34160);
              if ( v32 )
              {
                ipc_log_string(
                  v32,
                  "ipa %s:%d CB %d PROBE dev=%pK DOMAIN ATTRS bypass=%d fast=%d\n",
                  "ipa_smmu_perph_cb_probe",
                  11120,
                  v4,
                  v10,
                  v29,
                  v28);
                v30 = ipa3_ctx;
              }
              goto LABEL_50;
            }
            LOBYTE(v29) = 0;
          }
          else
          {
            v28 = (mappings_configuration >> 2) & 1;
            v29 = mappings_configuration & 1;
            v30 = ipa3_ctx;
            if ( ipa3_ctx )
              goto LABEL_46;
          }
LABEL_50:
          *(_BYTE *)(v30 + v4 + 43310) = v29;
          if ( of_find_property(v10[93], "qcom,shared-cb", 0) )
          {
            v33 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v34 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v34 )
              {
                ipc_log_string(v34, "ipa %s:%d CB %d using shared CB\n", "ipa_smmu_perph_cb_probe", 11125, v4);
                v33 = ipa3_ctx;
              }
              v35 = *(_QWORD *)(v33 + 34160);
              if ( v35 )
                ipc_log_string(v35, "ipa %s:%d CB %d using shared CB\n", "ipa_smmu_perph_cb_probe", 11125, v4);
            }
            v6[52] = 1;
          }
          v36 = of_get_property(v10[93], "qcom,additional-mapping", &v214);
          if ( !v36 )
            goto LABEL_8;
          HIDWORD(v37) = -1431655765 * v214;
          LODWORD(v37) = -1431655765 * v214;
          if ( (unsigned int)(v37 >> 2) <= 0x15555555 )
          {
            if ( (unsigned int)v214 >= 4 )
            {
              v38 = v36;
              v39 = 0;
              do
              {
                v40 = (_DWORD *)(v38 + 4 * v39);
                v41 = bswap32(v40[1]);
                v42 = v41 & 0xFFFFF000;
                v43 = bswap32(*v40 & 0xF0FFFF);
                v44 = (v41 & 0xFFF) + bswap32(v40[2]);
                v212 = v42;
                v45 = (v44 + 4095) & 0xFFFFF000;
                if ( ipa3_ctx )
                {
                  v46 = *(_QWORD *)(ipa3_ctx + 34160);
                  if ( v46 )
                  {
                    ipc_log_string(
                      v46,
                      "ipa %s:%d mapping 0x%lx to 0x%pa size %d\n",
                      "ipa_smmu_perph_cb_probe",
                      11152,
                      v43,
                      &v212,
                      v45);
                    v42 = v212;
                  }
                }
                ipa3_iommu_map(*((const void **)v6 + 2), v43, v42, v45, 0x13u);
                v39 += 3LL;
              }
              while ( v39 < (unsigned __int64)(unsigned int)v214 >> 2 );
            }
LABEL_8:
            LODWORD(v5) = 0;
            v6[54] = 1;
            goto LABEL_9;
          }
          printk(&unk_3F727A, "ipa_smmu_perph_cb_probe");
          v156 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v157 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v157 )
            {
              ipc_log_string(v157, "ipa %s:%d wrong additional mapping format\n", "ipa_smmu_perph_cb_probe", 11135);
              v156 = ipa3_ctx;
            }
            v158 = *(_QWORD *)(v156 + 34160);
            if ( v158 )
              ipc_log_string(v158, "ipa %s:%d wrong additional mapping format\n", "ipa_smmu_perph_cb_probe", 11135);
          }
          *v6 = 0;
          LODWORD(v5) = -14;
          goto LABEL_9;
        }
        if ( (_DWORD)v4 == 3 )
        {
          v71 = ipa3_ctx;
          *(_QWORD *)(ipa3_ctx + 34224) = *(_QWORD *)(ipa3_ctx + 34208) + 16LL;
          v215[0] = 0;
          if ( v71 )
          {
            v72 = *(_QWORD *)(v71 + 34152);
            if ( v72 )
            {
              ipc_log_string(v72, "ipa %s:%d UC CB PROBE dev=%pK\n", "ipa_smmu_uc_cb_probe", 11173, v10);
              v71 = ipa3_ctx;
            }
            v73 = *(_QWORD *)(v71 + 34160);
            if ( v73 )
              ipc_log_string(v73, "ipa %s:%d UC CB PROBE dev=%pK\n", "ipa_smmu_uc_cb_probe", 11173, v10);
          }
          if ( (byte_1F79A3 & 1) == 0 )
          {
            printk(&unk_3A9155, "ipa_smmu_uc_cb_probe");
            v5 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_9;
            v163 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v163 )
            {
              ipc_log_string(v163, "ipa %s:%d UC SMMU is disabled\n", "ipa_smmu_uc_cb_probe", 11176);
              v5 = ipa3_ctx;
            }
            v164 = *(_QWORD *)(v5 + 34160);
            if ( v164 )
            {
              ipc_log_string(v164, "ipa %s:%d UC SMMU is disabled\n", "ipa_smmu_uc_cb_probe", 11176);
              goto LABEL_273;
            }
            goto LABEL_274;
          }
          if ( byte_1F79A8 == 1 )
          {
            if ( (unsigned int)dma_set_mask(v10, -1) || (unsigned int)dma_set_coherent_mask(v10, -1) )
            {
              printk(&unk_3C0098, "ipa_smmu_uc_cb_probe");
              v74 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v75 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v75 )
                {
                  ipc_log_string(v75, "ipa %s:%d DMA set 64bit mask failed\n", "ipa_smmu_uc_cb_probe", 11183);
                  v74 = ipa3_ctx;
                }
                v76 = *(_QWORD *)(v74 + 34160);
                if ( v76 )
                {
                  ipc_log_string(v76, "ipa %s:%d DMA set 64bit mask failed\n", "ipa_smmu_uc_cb_probe", 11183);
                  goto LABEL_290;
                }
              }
              goto LABEL_291;
            }
          }
          else if ( (unsigned int)dma_set_mask(v10, 0xFFFFFFFFLL)
                 || (unsigned int)dma_set_coherent_mask(v10, 0xFFFFFFFFLL) )
          {
            printk(&unk_3F6FC1, "ipa_smmu_uc_cb_probe");
            v171 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v172 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v172 )
              {
                ipc_log_string(v172, "ipa %s:%d DMA set 32bit mask failed\n", "ipa_smmu_uc_cb_probe", 11189);
                v171 = ipa3_ctx;
              }
              v173 = *(_QWORD *)(v171 + 34160);
              if ( v173 )
              {
                ipc_log_string(v173, "ipa %s:%d DMA set 32bit mask failed\n", "ipa_smmu_uc_cb_probe", 11189);
                goto LABEL_290;
              }
            }
LABEL_291:
            LODWORD(v5) = -95;
            goto LABEL_9;
          }
          v91 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v92 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v92 )
            {
              ipc_log_string(
                v92,
                "ipa %s:%d UC CB PROBE dev=%pK retrieving IOMMU mapping\n",
                "ipa_smmu_uc_cb_probe",
                11194,
                v10);
              v91 = ipa3_ctx;
            }
            v93 = *(_QWORD *)(v91 + 34160);
            if ( v93 )
              ipc_log_string(
                v93,
                "ipa %s:%d UC CB PROBE dev=%pK retrieving IOMMU mapping\n",
                "ipa_smmu_uc_cb_probe",
                11194,
                v10);
          }
          v94 = iommu_get_domain_for_dev(v10);
          qword_1F78C8 = v94;
          if ( v94 && v94 < 0xFFFFFFFFFFFFF001LL )
          {
            v95 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v96 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v96 )
              {
                ipc_log_string(v96, "ipa %s:%d UC CB PROBE mapping retrieved\n", "ipa_smmu_uc_cb_probe", 11202);
                v95 = ipa3_ctx;
              }
              v97 = *(_QWORD *)(v95 + 34160);
              if ( v97 )
                ipc_log_string(v97, "ipa %s:%d UC CB PROBE mapping retrieved\n", "ipa_smmu_uc_cb_probe", 11202);
            }
            v51 = of_find_property(v10[93], "dma-coherent", 0) == 0;
            v98 = v10[93];
            v99 = !v51;
            qword_1F78C0 = (__int64)v10;
            byte_1F78B8 = 1;
            dword_1F78E0 = 0;
            byte_1F78ED = v99;
            qword_1F78D8 = 0;
            if ( (of_property_read_variable_u32_array(v98, "qcom,ipa-dma-addr-pool", v215, 2, 0) & 0x80000000) == 0 )
            {
              qword_1F78D8 = v215[0];
              dword_1F78E0 = HIDWORD(v215[0]) + LODWORD(v215[0]);
            }
            v100 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v101 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v101 )
              {
                ipc_log_string(
                  v101,
                  "ipa %s:%d UC CB PROBE dev=%pK va_start=0x%x va_size=0x%x\n",
                  "ipa_smmu_uc_cb_probe",
                  11228,
                  v10,
                  qword_1F78D8,
                  HIDWORD(qword_1F78D8));
                v100 = ipa3_ctx;
              }
              v102 = *(_QWORD *)(v100 + 34160);
              if ( v102 )
                ipc_log_string(
                  v102,
                  "ipa %s:%d UC CB PROBE dev=%pK va_start=0x%x va_size=0x%x\n",
                  "ipa_smmu_uc_cb_probe",
                  11228,
                  v10,
                  qword_1F78D8,
                  HIDWORD(qword_1F78D8));
            }
            v103 = qcom_iommu_get_mappings_configuration(qword_1F78C8);
            if ( (v103 & 0x80000000) != 0 )
            {
              printk(&unk_3E5B5E, "ipa_smmu_uc_cb_probe");
              v106 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v184 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v184 )
                {
                  ipc_log_string(
                    v184,
                    "ipa %s:%d No Mapping configuration found for UC CB\n",
                    "ipa_smmu_uc_cb_probe",
                    11247);
                  v106 = ipa3_ctx;
                }
                v185 = *(_QWORD *)(v106 + 34160);
                if ( v185 )
                {
                  ipc_log_string(
                    v185,
                    "ipa %s:%d No Mapping configuration found for UC CB\n",
                    "ipa_smmu_uc_cb_probe",
                    11247);
                  v104 = 0;
                  v105 = 0;
                  v106 = ipa3_ctx;
                  if ( !ipa3_ctx )
                    goto LABEL_184;
                }
                else
                {
                  v104 = 0;
                  v105 = 0;
                  if ( !v106 )
                    goto LABEL_184;
                }
LABEL_180:
                v107 = *(_QWORD *)(v106 + 34152);
                if ( v107 )
                {
                  ipc_log_string(
                    v107,
                    "ipa %s:%d UC CB PROBE dev=%pK DOMAIN ATTRS bypass=%d fast=%d\n",
                    "ipa_smmu_uc_cb_probe",
                    11257,
                    v10,
                    v105,
                    v104);
                  v106 = ipa3_ctx;
                }
                v108 = *(_QWORD *)(v106 + 34160);
                if ( v108 )
                {
                  ipc_log_string(
                    v108,
                    "ipa %s:%d UC CB PROBE dev=%pK DOMAIN ATTRS bypass=%d fast=%d\n",
                    "ipa_smmu_uc_cb_probe",
                    11257,
                    v10,
                    v105,
                    v104);
                  v106 = ipa3_ctx;
                }
                goto LABEL_184;
              }
              LOBYTE(v105) = 0;
            }
            else
            {
              v104 = (v103 >> 2) & 1;
              v105 = v103 & 1;
              v106 = ipa3_ctx;
              if ( ipa3_ctx )
                goto LABEL_180;
            }
LABEL_184:
            LODWORD(v5) = 0;
            *(_BYTE *)(v106 + 43313) = v105;
            *(_QWORD *)(ipa3_ctx + 34224) = v10;
            byte_1F78EE = 1;
            goto LABEL_9;
          }
          printk(&unk_3C92A2, "ipa_smmu_uc_cb_probe");
          v179 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v180 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v180 )
            {
              ipc_log_string(v180, "ipa %s:%d could not get iommu domain\n", "ipa_smmu_uc_cb_probe", 11198);
              v179 = ipa3_ctx;
            }
            v181 = *(_QWORD *)(v179 + 34160);
            if ( v181 )
            {
              ipc_log_string(v181, "ipa %s:%d could not get iommu domain\n", "ipa_smmu_uc_cb_probe", 11198);
              goto LABEL_244;
            }
          }
          goto LABEL_308;
        }
        if ( (_DWORD)v4 == 4 )
        {
          v47 = ipa3_ctx;
          v215[0] = 0;
          if ( ipa3_ctx )
          {
            v48 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v48 )
            {
              ipc_log_string(v48, "ipa %s:%d 11AD CB probe: dev=%pK\n", "ipa_smmu_11ad_cb_probe", 11524, v10);
              v47 = ipa3_ctx;
            }
            v49 = *(_QWORD *)(v47 + 34160);
            if ( v49 )
              ipc_log_string(v49, "ipa %s:%d 11AD CB probe: dev=%pK\n", "ipa_smmu_11ad_cb_probe", 11524, v10);
          }
          if ( (byte_1F79A4 & 1) == 0 )
          {
            printk(&unk_3EBB93, "ipa_smmu_11ad_cb_probe");
            v5 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_9;
            v161 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v161 )
            {
              ipc_log_string(v161, "ipa %s:%d 11AD SMMU is disabled", "ipa_smmu_11ad_cb_probe", 11527);
              v5 = ipa3_ctx;
            }
            v162 = *(_QWORD *)(v5 + 34160);
            if ( v162 )
            {
              ipc_log_string(v162, "ipa %s:%d 11AD SMMU is disabled", "ipa_smmu_11ad_cb_probe", 11527);
              goto LABEL_273;
            }
            goto LABEL_274;
          }
          v50 = iommu_get_domain_for_dev(v10);
          qword_1F7900 = v50;
          if ( !v50 || v50 >= 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_3C92A2, "ipa_smmu_11ad_cb_probe");
            v165 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v166 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v166 )
              {
                ipc_log_string(v166, "ipa %s:%d could not get iommu domain\n", "ipa_smmu_11ad_cb_probe", 11533);
                v165 = ipa3_ctx;
              }
              v167 = *(_QWORD *)(v165 + 34160);
              if ( v167 )
              {
                ipc_log_string(v167, "ipa %s:%d could not get iommu domain\n", "ipa_smmu_11ad_cb_probe", 11533);
                goto LABEL_244;
              }
            }
            goto LABEL_308;
          }
          v51 = of_find_property(v10[93], "dma-coherent", 0) == 0;
          v52 = v10[93];
          v53 = !v51;
          qword_1F78F8 = (__int64)v10;
          byte_1F78F0 = 1;
          dword_1F7918 = 0;
          byte_1F7925 = v53;
          qword_1F7910 = 0;
          if ( (of_property_read_variable_u32_array(v52, "qcom,ipa-dma-addr-pool", v215, 2, 0) & 0x80000000) == 0 )
          {
            qword_1F7910 = v215[0];
            dword_1F7918 = HIDWORD(v215[0]) + LODWORD(v215[0]);
          }
          v54 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v55 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v55 )
            {
              ipc_log_string(
                v55,
                "ipa %s:%d 11AD CB PROBE dev=%pK va_start=0x%x va_size=0x%x\n",
                "ipa_smmu_11ad_cb_probe",
                11560,
                v10,
                qword_1F7910,
                HIDWORD(qword_1F7910));
              v54 = ipa3_ctx;
            }
            v56 = *(_QWORD *)(v54 + 34160);
            if ( v56 )
              ipc_log_string(
                v56,
                "ipa %s:%d 11AD CB PROBE dev=%pK va_start=0x%x va_size=0x%x\n",
                "ipa_smmu_11ad_cb_probe",
                11560,
                v10,
                qword_1F7910,
                HIDWORD(qword_1F7910));
          }
          v57 = qcom_iommu_get_mappings_configuration(qword_1F7900);
          if ( v57 < 0 )
          {
            printk(&unk_3CF2AA, "ipa_smmu_11ad_cb_probe");
            v59 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v174 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v174 )
              {
                ipc_log_string(
                  v174,
                  "ipa %s:%d No Mapping configuration found for 11AD CB\n",
                  "ipa_smmu_11ad_cb_probe",
                  11566);
                v59 = ipa3_ctx;
              }
              v175 = *(_QWORD *)(v59 + 34160);
              if ( v175 )
              {
                ipc_log_string(
                  v175,
                  "ipa %s:%d No Mapping configuration found for 11AD CB\n",
                  "ipa_smmu_11ad_cb_probe",
                  11566);
                v58 = 0;
                v59 = ipa3_ctx;
                if ( !ipa3_ctx )
                  goto LABEL_91;
              }
              else
              {
                v58 = 0;
                if ( !v59 )
                  goto LABEL_91;
              }
LABEL_87:
              v60 = *(_QWORD *)(v59 + 34152);
              if ( v60 )
              {
                ipc_log_string(
                  v60,
                  "ipa %s:%d 11AD CB PROBE dev=%pK DOMAIN ATTRS bypass=%d\n",
                  "ipa_smmu_11ad_cb_probe",
                  11574,
                  v10,
                  v58);
                v59 = ipa3_ctx;
              }
              v61 = *(_QWORD *)(v59 + 34160);
              if ( v61 )
              {
                ipc_log_string(
                  v61,
                  "ipa %s:%d 11AD CB PROBE dev=%pK DOMAIN ATTRS bypass=%d\n",
                  "ipa_smmu_11ad_cb_probe",
                  11574,
                  v10,
                  v58);
                v59 = ipa3_ctx;
              }
              goto LABEL_91;
            }
            LOBYTE(v58) = 0;
          }
          else
          {
            v58 = v57 & 1;
            v59 = ipa3_ctx;
            if ( ipa3_ctx )
              goto LABEL_87;
          }
LABEL_91:
          *(_BYTE *)(v59 + 43314) = v58;
          if ( of_find_property(v10[93], "qcom,shared-cb", 0) )
          {
            v62 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v63 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v63 )
              {
                ipc_log_string(v63, "ipa %s:%d 11AD using shared CB\n", "ipa_smmu_11ad_cb_probe", 11579);
                v62 = ipa3_ctx;
              }
              v64 = *(_QWORD *)(v62 + 34160);
              if ( v64 )
                ipc_log_string(v64, "ipa %s:%d 11AD using shared CB\n", "ipa_smmu_11ad_cb_probe", 11579);
            }
            byte_1F7924 = 1;
          }
          LODWORD(v5) = 0;
          byte_1F7926 = 1;
          goto LABEL_9;
        }
      }
      if ( (_DWORD)v4 )
        goto LABEL_10;
      v65 = ipa3_ctx;
      *(_QWORD *)(ipa3_ctx + 34216) = *(_QWORD *)(ipa3_ctx + 34208) + 16LL;
      v214 = 0;
      v215[0] = 0;
      v211 = 0;
      v212 = 0;
      v213 = 0;
      if ( v65 )
      {
        v66 = *(_QWORD *)(v65 + 34152);
        if ( v66 )
        {
          ipc_log_string(v66, "ipa %s:%d AP CB PROBE dev=%pK\n", "ipa_smmu_ap_cb_probe", 11314, v10);
          v65 = ipa3_ctx;
        }
        v67 = *(_QWORD *)(v65 + 34160);
        if ( v67 )
          ipc_log_string(v67, "ipa %s:%d AP CB PROBE dev=%pK\n", "ipa_smmu_ap_cb_probe", 11314, v10);
      }
      if ( (smmu_info[0] & 1) == 0 )
      {
        printk(&unk_3A2A4A, "ipa_smmu_ap_cb_probe");
        v5 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_9;
        v159 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v159 )
        {
          ipc_log_string(v159, "ipa %s:%d AP SMMU is disabled", "ipa_smmu_ap_cb_probe", 11317);
          v5 = ipa3_ctx;
        }
        v160 = *(_QWORD *)(v5 + 34160);
        if ( v160 )
        {
          ipc_log_string(v160, "ipa %s:%d AP SMMU is disabled", "ipa_smmu_ap_cb_probe", 11317);
LABEL_273:
          LODWORD(v5) = 0;
          goto LABEL_9;
        }
        goto LABEL_274;
      }
      if ( byte_1F79A8 == 1 )
      {
        if ( (unsigned int)dma_set_mask(v10, -1) || (unsigned int)dma_set_coherent_mask(v10, -1) )
        {
          printk(&unk_3C0098, "ipa_smmu_ap_cb_probe");
          v68 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v69 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v69 )
            {
              ipc_log_string(v69, "ipa %s:%d DMA set 64bit mask failed\n", "ipa_smmu_ap_cb_probe", 11324);
              v68 = ipa3_ctx;
            }
            v70 = *(_QWORD *)(v68 + 34160);
            if ( v70 )
            {
              ipc_log_string(v70, "ipa %s:%d DMA set 64bit mask failed\n", "ipa_smmu_ap_cb_probe", 11324);
LABEL_290:
              LODWORD(v5) = -95;
              goto LABEL_9;
            }
          }
          goto LABEL_291;
        }
      }
      else if ( (unsigned int)dma_set_mask(v10, 0xFFFFFFFFLL) || (unsigned int)dma_set_coherent_mask(v10, 0xFFFFFFFFLL) )
      {
        printk(&unk_3F6FC1, "ipa_smmu_ap_cb_probe");
        v168 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v169 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v169 )
          {
            ipc_log_string(v169, "ipa %s:%d DMA set 32bit mask failed\n", "ipa_smmu_ap_cb_probe", 11330);
            v168 = ipa3_ctx;
          }
          v170 = *(_QWORD *)(v168 + 34160);
          if ( v170 )
          {
            ipc_log_string(v170, "ipa %s:%d DMA set 32bit mask failed\n", "ipa_smmu_ap_cb_probe", 11330);
            goto LABEL_290;
          }
        }
        goto LABEL_291;
      }
      v77 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v78 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v78 )
        {
          ipc_log_string(
            v78,
            "ipa %s:%d AP CB PROBE dev=%pK retrieving IOMMU mapping\n",
            "ipa_smmu_ap_cb_probe",
            11335,
            v10);
          v77 = ipa3_ctx;
        }
        v79 = *(_QWORD *)(v77 + 34160);
        if ( v79 )
          ipc_log_string(
            v79,
            "ipa %s:%d AP CB PROBE dev=%pK retrieving IOMMU mapping\n",
            "ipa_smmu_ap_cb_probe",
            11335,
            v10);
      }
      v80 = iommu_get_domain_for_dev(v10);
      qword_1F7820 = v80;
      if ( !v80 || v80 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_3C92A2, "ipa_smmu_ap_cb_probe");
        v176 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v177 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v177 )
          {
            ipc_log_string(v177, "ipa %s:%d could not get iommu domain\n", "ipa_smmu_ap_cb_probe", 11339);
            v176 = ipa3_ctx;
          }
          v178 = *(_QWORD *)(v176 + 34160);
          if ( v178 )
          {
            ipc_log_string(v178, "ipa %s:%d could not get iommu domain\n", "ipa_smmu_ap_cb_probe", 11339);
            goto LABEL_244;
          }
        }
LABEL_308:
        LODWORD(v5) = -22;
        goto LABEL_9;
      }
      v81 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v82 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v82 )
        {
          ipc_log_string(v82, "ipa %s:%d AP CB PROBE mapping retrieved\n", "ipa_smmu_ap_cb_probe", 11343);
          v81 = ipa3_ctx;
        }
        v83 = *(_QWORD *)(v81 + 34160);
        if ( v83 )
          ipc_log_string(v83, "ipa %s:%d AP CB PROBE mapping retrieved\n", "ipa_smmu_ap_cb_probe", 11343);
      }
      v51 = of_find_property(v10[93], "dma-coherent", 0) == 0;
      v84 = v10[93];
      v85 = !v51;
      qword_1F7818 = (__int64)v10;
      smmu_cb[0] = 1;
      dword_1F7838 = 0;
      byte_1F7845 = v85;
      qword_1F7830 = 0;
      if ( (of_property_read_variable_u32_array(v84, "qcom,ipa-dma-addr-pool", &v214, 2, 0) & 0x80000000) == 0 )
      {
        qword_1F7830 = v214;
        dword_1F7838 = HIDWORD(v214) + v214;
      }
      v86 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v87 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v87 )
        {
          ipc_log_string(
            v87,
            "ipa %s:%d AP CB PROBE dev=%pK va_start=0x%x va_size=0x%x\n",
            "ipa_smmu_ap_cb_probe",
            11369,
            v10,
            qword_1F7830,
            HIDWORD(qword_1F7830));
          v86 = ipa3_ctx;
        }
        v88 = *(_QWORD *)(v86 + 34160);
        if ( v88 )
          ipc_log_string(
            v88,
            "ipa %s:%d AP CB PROBE dev=%pK va_start=0x%x va_size=0x%x\n",
            "ipa_smmu_ap_cb_probe",
            11369,
            v10,
            qword_1F7830,
            HIDWORD(qword_1F7830));
      }
      if ( (of_property_read_variable_u32_array(v10[93], "qcom,iommu-geometry", &v213, 2, 0) & 0x80000000) != 0 )
      {
        v109 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v110 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v110 )
          {
            ipc_log_string(
              v110,
              "ipa %s:%d AP CB PROBE Geometry not defined using max!\n",
              "ipa_smmu_ap_cb_probe",
              11376);
            v109 = ipa3_ctx;
          }
          v111 = *(_QWORD *)(v109 + 34160);
          if ( v111 )
            ipc_log_string(
              v111,
              "ipa %s:%d AP CB PROBE Geometry not defined using max!\n",
              "ipa_smmu_ap_cb_probe",
              11376);
        }
        v89 = 0;
        v90 = -268435456;
        dword_1F783C = 0;
      }
      else
      {
        v89 = v213;
        v90 = HIDWORD(v213);
        dword_1F783C = v213;
      }
      v112 = ipa3_ctx;
      dword_1F7840 = v90;
      if ( ipa3_ctx )
      {
        v113 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v113 )
        {
          ipc_log_string(
            v113,
            "ipa %s:%d AP CB PROBE dev=%pK geometry_start=0x%x geometry_end=0x%x\n",
            "ipa_smmu_ap_cb_probe",
            11382,
            v10,
            v89,
            v90);
          v112 = ipa3_ctx;
        }
        v114 = *(_QWORD *)(v112 + 34160);
        if ( v114 )
          ipc_log_string(
            v114,
            "ipa %s:%d AP CB PROBE dev=%pK geometry_start=0x%x geometry_end=0x%x\n",
            "ipa_smmu_ap_cb_probe",
            11382,
            v10,
            dword_1F783C,
            dword_1F7840);
      }
      v115 = qcom_iommu_get_mappings_configuration(qword_1F7820);
      if ( (v115 & 0x80000000) != 0 )
      {
        printk(&unk_3E3099, "ipa_smmu_ap_cb_probe");
        v118 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v182 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v182 )
          {
            ipc_log_string(v182, "ipa %s:%d No Mapping configuration found for AP CB\n", "ipa_smmu_ap_cb_probe", 11401);
            v118 = ipa3_ctx;
          }
          v183 = *(_QWORD *)(v118 + 34160);
          if ( v183 )
          {
            ipc_log_string(v183, "ipa %s:%d No Mapping configuration found for AP CB\n", "ipa_smmu_ap_cb_probe", 11401);
            v117 = 0;
            v116 = 0;
            v118 = ipa3_ctx;
            if ( ipa3_ctx )
              goto LABEL_198;
          }
          else
          {
            v117 = 0;
            v116 = 0;
            if ( v118 )
            {
LABEL_198:
              v119 = *(_QWORD *)(v118 + 34152);
              if ( v119 )
              {
                ipc_log_string(
                  v119,
                  "ipa %s:%d AP CB PROBE dev=%pK DOMAIN ATTRS bypass=%d fast=%d\n",
                  "ipa_smmu_ap_cb_probe",
                  11411,
                  v10,
                  v117,
                  v116);
                v118 = ipa3_ctx;
              }
              v120 = *(_QWORD *)(v118 + 34160);
              if ( v120 )
              {
                ipc_log_string(
                  v120,
                  "ipa %s:%d AP CB PROBE dev=%pK DOMAIN ATTRS bypass=%d fast=%d\n",
                  "ipa_smmu_ap_cb_probe",
                  11411,
                  v10,
                  v117,
                  v116);
                v118 = ipa3_ctx;
              }
            }
          }
        }
        else
        {
          LOBYTE(v117) = 0;
        }
      }
      else
      {
        v116 = (v115 >> 2) & 1;
        v117 = v115 & 1;
        v118 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_198;
      }
      *(_BYTE *)(v118 + 43310) = v117;
      v121 = of_get_property(v10[93], "qcom,additional-mapping", (char *)&v211 + 4);
      if ( v121 )
      {
        HIDWORD(v122) = -1431655765 * HIDWORD(v211);
        LODWORD(v122) = -1431655765 * HIDWORD(v211);
        if ( (unsigned int)(v122 >> 2) > 0x15555555 )
        {
          printk(&unk_3F727A, "ipa_smmu_ap_cb_probe");
          v186 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v187 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v187 )
            {
              ipc_log_string(v187, "ipa %s:%d wrong additional mapping format\n", "ipa_smmu_ap_cb_probe", 11420);
              v186 = ipa3_ctx;
            }
            v188 = *(_QWORD *)(v186 + 34160);
            if ( v188 )
              ipc_log_string(v188, "ipa %s:%d wrong additional mapping format\n", "ipa_smmu_ap_cb_probe", 11420);
          }
          smmu_cb[0] = 0;
          LODWORD(v5) = -14;
          goto LABEL_9;
        }
        if ( HIDWORD(v211) >= 4 )
        {
          v143 = 0;
          do
          {
            v144 = (_DWORD *)(v121 + 4 * v143);
            v145 = bswap32(v144[1]);
            v146 = v145 & 0xFFFFF000;
            v147 = bswap32(*v144 & 0xF0FFFF);
            v148 = (v145 & 0xFFF) + bswap32(v144[2]);
            v210 = v146;
            v149 = (v148 + 4095) & 0xFFFFF000;
            if ( ipa3_ctx )
            {
              v150 = *(_QWORD *)(ipa3_ctx + 34160);
              if ( v150 )
              {
                ipc_log_string(
                  v150,
                  "ipa %s:%d mapping 0x%lx to 0x%pa size %d\n",
                  "ipa_smmu_ap_cb_probe",
                  11437,
                  v147,
                  &v210,
                  v149);
                v146 = v210;
              }
            }
            ipa3_iommu_map((const void *)qword_1F7820, v147, v146, v149, 0x13u);
            v143 += 3LL;
          }
          while ( v143 < (unsigned __int64)HIDWORD(v211) >> 2 );
        }
      }
      v123 = of_property_read_variable_u32_array(v10[93], "qcom,ipa-q6-smem-size", &v211, 1, 0);
      v124 = ipa3_ctx;
      if ( v123 < 0 )
      {
        if ( ipa3_ctx )
        {
          v127 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v127 )
          {
            ipc_log_string(v127, "ipa %s:%d ipa q6 smem size (default) = %u\n", "ipa_smmu_ap_cb_probe", 11447, 0x2000);
            v124 = ipa3_ctx;
          }
          v128 = *(_QWORD *)(v124 + 34160);
          if ( v128 )
            ipc_log_string(v128, "ipa %s:%d ipa q6 smem size (default) = %u\n", "ipa_smmu_ap_cb_probe", 11447, 0x2000);
        }
        LODWORD(v211) = 0x2000;
      }
      else if ( ipa3_ctx )
      {
        v125 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v125 )
        {
          ipc_log_string(v125, "ipa %s:%d ipa q6 smem size = %u\n", "ipa_smmu_ap_cb_probe", 11450, v211);
          v124 = ipa3_ctx;
        }
        v126 = *(_QWORD *)(v124 + 34160);
        if ( v126 )
          ipc_log_string(v126, "ipa %s:%d ipa q6 smem size = %u\n", "ipa_smmu_ap_cb_probe", 11450, v211);
      }
      v51 = *(_DWORD *)(ipa3_ctx + 32256) == 2;
      *(_DWORD *)(ipa3_ctx + 51440) = v211;
      if ( v51 )
        goto LABEL_228;
      v129 = qcom_smem_alloc(1, 497);
      if ( v129 < 0 && v129 != -17 )
      {
        printk(&unk_3D7C96, "ipa_smmu_ap_cb_probe");
        v189 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v190 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v190 )
          {
            ipc_log_string(v190, "ipa %s:%d unable to allocate smem MODEM entry\n", "ipa_smmu_ap_cb_probe", 11461);
            v189 = ipa3_ctx;
          }
          v191 = *(_QWORD *)(v189 + 34160);
          if ( v191 )
            ipc_log_string(v191, "ipa %s:%d unable to allocate smem MODEM entry\n", "ipa_smmu_ap_cb_probe", 11461);
        }
      }
      else
      {
        v130 = qcom_smem_get(1, 497, v215);
        if ( v130 < 0xFFFFFFFFFFFFF001LL )
        {
          v131 = v130;
          if ( v215[0] != (unsigned int)v211 )
          {
            printk(&unk_3AC18D, "ipa_smmu_ap_cb_probe");
            v195 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v196 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v196 )
              {
                ipc_log_string(
                  v196,
                  "ipa %s:%d unexpected read q6 smem size %zu %u\n",
                  "ipa_smmu_ap_cb_probe",
                  11479,
                  v215[0],
                  v211);
                v195 = ipa3_ctx;
              }
              v197 = *(_QWORD *)(v195 + 34160);
              if ( v197 )
                ipc_log_string(
                  v197,
                  "ipa %s:%d unexpected read q6 smem size %zu %u\n",
                  "ipa_smmu_ap_cb_probe",
                  11479,
                  v215[0],
                  v211);
            }
          }
          v132 = qcom_smem_virt_to_phys(v131);
          v133 = v132 & 0xFFFFFFFFFFFFF000LL;
          v212 = v132 & 0xFFFFFFFFFFFFF000LL;
          v134 = ipa3_ctx;
          v135 = ((_DWORD)v211 + (v132 & 0xFFF) + 4095) & 0xFFFFF000;
          if ( ipa3_ctx )
          {
            v136 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v136 )
            {
              ipc_log_string(
                v136,
                "ipa %s:%d mapping 0x%lx to 0x%pa size %d\n",
                "ipa_smmu_ap_cb_probe",
                11487,
                v133,
                &v212,
                v135);
              v134 = ipa3_ctx;
            }
            v137 = *(_QWORD *)(v134 + 34160);
            if ( v137 )
              ipc_log_string(
                v137,
                "ipa %s:%d mapping 0x%lx to 0x%pa size %d\n",
                "ipa_smmu_ap_cb_probe",
                11487,
                v133,
                &v212,
                v135);
          }
          ipa3_iommu_map((const void *)qword_1F7820, v133, v212, v135, 3u);
          v138 = ipa3_ctx + 49152;
          *(_QWORD *)(ipa3_ctx + 51424) = v132;
          *(_QWORD *)(v138 + 2280) = v131;
          v139 = ipa3_peripheral_stats_init(v131);
          if ( v139 )
          {
            v198 = v139;
            printk(&unk_3E3129, "ipa_smmu_ap_cb_probe");
            v199 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v200 = *(_QWORD *)(ipa3_ctx + 34152);
              v201 = v198;
              if ( v200 )
              {
                ipc_log_string(
                  v200,
                  "ipa %s:%d IPA Peripheral stats init failure = %d ",
                  "ipa_smmu_ap_cb_probe",
                  11503,
                  v198);
                v199 = ipa3_ctx;
                v201 = v198;
              }
              v202 = *(_QWORD *)(v199 + 34160);
              if ( v202 )
                ipc_log_string(
                  v202,
                  "ipa %s:%d IPA Peripheral stats init failure = %d ",
                  "ipa_smmu_ap_cb_probe",
                  11503,
                  v201);
            }
          }
LABEL_228:
          smmu_info[0] = 1;
          v140 = (unsigned int)dword_1F7838;
          byte_1F7846 = 1;
          LODWORD(v5) = 0;
          *(_QWORD *)(ipa3_ctx + 34216) = v10;
          qword_1F7828 = v140;
          goto LABEL_9;
        }
        printk(&unk_3D7CF6, "ipa_smmu_ap_cb_probe");
        v192 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v193 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v193 )
          {
            ipc_log_string(v193, "ipa %s:%d unable to acquire smem MODEM entry\n", "ipa_smmu_ap_cb_probe", 11471);
            v192 = ipa3_ctx;
          }
          v194 = *(_QWORD *)(v192 + 34160);
          if ( v194 )
            ipc_log_string(v194, "ipa %s:%d unable to acquire smem MODEM entry\n", "ipa_smmu_ap_cb_probe", 11471);
        }
      }
      smmu_cb[0] = 0;
      if ( v121 )
        ipa3_ap_iommu_unmap(smmu_cb, v121, HIDWORD(v211));
      LODWORD(v5) = -14;
LABEL_9:
      if ( (_DWORD)v5 )
      {
        v206 = v5;
        printk(&unk_3AEF9A, "ipa3_attach_to_smmu");
        v207 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v208 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v208 )
          {
            ipc_log_string(v208, "ipa %s:%d probe failed for cb %d\n", "ipa3_attach_to_smmu", 11625, v4);
            v207 = ipa3_ctx;
          }
          v209 = *(_QWORD *)(v207 + 34160);
          if ( v209 )
            ipc_log_string(v209, "ipa %s:%d probe failed for cb %d\n", "ipa3_attach_to_smmu", 11625, v4);
        }
        result = v206;
        goto LABEL_368;
      }
LABEL_10:
      if ( ++v4 == 7 )
        goto LABEL_367;
    }
  }
  v203 = *(_QWORD *)(ipa3_ctx + 34208) + 16LL;
  *(_QWORD *)(ipa3_ctx + 34216) = v203;
  *(_QWORD *)(v1 + 1456) = v203;
  if ( !v0 )
  {
LABEL_367:
    result = 0;
    goto LABEL_368;
  }
  v204 = *(_QWORD *)(v1 + 1384);
  if ( v204 )
  {
    ipc_log_string(v204, "ipa %s:%d smmu is disabled\n", "ipa3_attach_to_smmu", 11632);
    v0 = ipa3_ctx;
  }
  result = *(_QWORD *)(v0 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d smmu is disabled\n", "ipa3_attach_to_smmu", 11632);
    goto LABEL_367;
  }
LABEL_368:
  _ReadStatusReg(SP_EL0);
  return result;
}
