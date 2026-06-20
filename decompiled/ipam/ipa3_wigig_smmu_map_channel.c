__int64 __fastcall ipa3_wigig_smmu_map_channel(
        char a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8,
        float a9)
{
  char *smmu_ctx; // x23
  long double v14; // q0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  const char *v20; // x4
  __int64 v21; // x0
  const char *v22; // x4
  unsigned int v23; // w0
  long double v24; // q0
  const char *v25; // x19
  unsigned int v26; // w20
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  const char *v31; // x4
  __int64 v32; // x0
  const char *v33; // x4
  unsigned int v34; // w0
  long double v35; // q0
  __int64 v36; // x8
  __int64 v37; // x0
  const char *v38; // x4
  __int64 v39; // x0
  const char *v40; // x4
  unsigned int v41; // w0
  __int64 v42; // x8
  __int64 v43; // x0
  const char *v44; // x4
  __int64 v45; // x0
  const char *v46; // x4
  unsigned int v47; // w0
  long double v48; // q0
  __int64 v49; // x8
  __int64 v50; // x0
  const char *v51; // x4
  __int64 v52; // x0
  const char *v53; // x4
  unsigned int v54; // w0
  long double v55; // q0
  __int64 v56; // x8
  __int64 v57; // x0
  const char *v58; // x4
  __int64 v59; // x0
  const char *v60; // x4
  unsigned int v61; // w0
  long double v62; // q0
  __int64 v63; // x8
  __int64 v64; // x0
  const char *v65; // x4
  __int64 v66; // x0
  const char *v67; // x4
  unsigned int v68; // w0
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v71; // x0
  int v72; // w25
  unsigned int v73; // w0
  const char *v74; // x24
  unsigned int v75; // w23
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  long double v79; // q0
  __int64 v80; // x8
  __int64 v81; // x0
  __int64 v82; // x0
  long double v83; // q0
  unsigned int v84; // w27
  signed int v85; // w25
  unsigned int v86; // w0
  unsigned int v87; // w9
  __int64 v88; // x8
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x8
  __int64 v92; // x0
  __int64 result; // x0
  __int64 v94; // x8
  __int64 v95; // x0
  __int64 v96; // x0
  const char *v97; // x22
  long double v98; // q0
  __int64 v99; // x8
  __int64 v100; // x0
  __int64 v101; // x0
  const char *v102; // x22
  long double v103; // q0
  __int64 v104; // x8
  __int64 v105; // x0
  __int64 v106; // x0
  const char *v107; // x22
  long double v108; // q0
  __int64 v109; // x8
  __int64 v110; // x0
  __int64 v111; // x0
  const char *v112; // x22
  __int64 v113; // x8
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x1
  __int64 v117; // x2
  unsigned __int64 v118; // x0
  const char *v119; // x19
  __int64 v120; // x8
  __int64 v121; // x0
  __int64 v122; // x0
  const char *v123; // x21
  __int64 v124; // x8
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x8
  __int64 v128; // x0
  __int64 v129; // x0
  __int64 v130; // x23
  __int64 v131; // x25
  unsigned int v132; // w0

  smmu_ctx = ipa3_get_smmu_ctx(4u, a5, a6, a7, a8, a9);
  v15 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      v14 = ipc_log_string(v16, "ipa %s:%d \n", "ipa3_wigig_smmu_map_channel", 377);
      v15 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v15 + 34160);
    if ( v17 )
      v14 = ipc_log_string(v17, "ipa %s:%d \n", "ipa3_wigig_smmu_map_channel", 377);
  }
  if ( !smmu_ctx )
  {
    printk(&unk_3B5F26, "ipa3_wigig_smmu_map_channel");
    v94 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967274LL;
    v95 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v95 )
    {
      ipc_log_string(v95, "ipa %s:%d 11AD SMMU ctx is null\n", "ipa3_wigig_smmu_map_channel", 397);
      v94 = ipa3_ctx;
    }
    v96 = *(_QWORD *)(v94 + 34160);
    if ( !v96 )
      return 4294967274LL;
    ipc_log_string(v96, "ipa %s:%d 11AD SMMU ctx is null\n", "ipa3_wigig_smmu_map_channel", 397);
    return 4294967274LL;
  }
  v18 = ipa3_ctx;
  if ( (a1 & 1) != 0 )
  {
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        if ( (a4 & 1) != 0 )
          v20 = "map";
        else
          v20 = "unmap";
        v14 = ipc_log_string(
                v19,
                "ipa %s:%d RX %s status_ring_HWHEAD_pa %pa uC CB\n",
                "ipa3_wigig_smmu_map_channel",
                404,
                v20,
                a2 + 80,
                *(double *)&v14);
        v18 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v18 + 34160);
      if ( v21 )
      {
        if ( (a4 & 1) != 0 )
          v22 = "map";
        else
          v22 = "unmap";
        v14 = ipc_log_string(
                v21,
                "ipa %s:%d RX %s status_ring_HWHEAD_pa %pa uC CB\n",
                "ipa3_wigig_smmu_map_channel",
                404,
                v22,
                a2 + 80,
                *(double *)&v14);
      }
    }
    v23 = ipa3_wigig_smmu_map_reg(*(_QWORD *)(a2 + 80) & 0xFFFFFFFFFFFFF000LL, a4 & 1, 3, v14);
    if ( v23 )
    {
      if ( (a4 & 1) != 0 )
        v25 = "map";
      else
        v25 = "unmap";
      v26 = v23;
      printk(&unk_3D6A91, "ipa3_wigig_smmu_map_channel");
      v27 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v28 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v28 )
        {
          ipc_log_string(
            v28,
            "ipa %s:%d failed to %s status_ring_HWAHEAD %d\n",
            "ipa3_wigig_smmu_map_channel",
            413,
            v25,
            v26);
          v27 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v27 + 34160);
        if ( v29 )
        {
          ipc_log_string(
            v29,
            "ipa %s:%d failed to %s status_ring_HWAHEAD %d\n",
            "ipa3_wigig_smmu_map_channel",
            413,
            v25,
            v26);
          return v26;
        }
      }
      return v26;
    }
  }
  else
  {
    if ( ipa3_ctx )
    {
      v30 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v30 )
      {
        if ( (a4 & 1) != 0 )
          v31 = "map";
        else
          v31 = "unmap";
        v14 = ipc_log_string(
                v30,
                "ipa %s:%d TX %s status_ring_HWHEAD_pa %pa AP CB\n",
                "ipa3_wigig_smmu_map_channel",
                419,
                v31,
                a2 + 80,
                *(double *)&v14);
        v18 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v18 + 34160);
      if ( v32 )
      {
        if ( (a4 & 1) != 0 )
          v33 = "map";
        else
          v33 = "unmap";
        v14 = ipc_log_string(
                v32,
                "ipa %s:%d TX %s status_ring_HWHEAD_pa %pa AP CB\n",
                "ipa3_wigig_smmu_map_channel",
                419,
                v33,
                a2 + 80,
                *(double *)&v14);
      }
    }
    v34 = ipa3_wigig_smmu_map_reg(*(_QWORD *)(a2 + 80) & 0xFFFFFFFFFFFFF000LL, a4 & 1, 0, v14);
    if ( v34 )
    {
      if ( (a4 & 1) != 0 )
        v119 = "map";
      else
        v119 = "unmap";
      v26 = v34;
      printk(&unk_3D6A91, "ipa3_wigig_smmu_map_channel");
      v120 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v121 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v121 )
        {
          ipc_log_string(
            v121,
            "ipa %s:%d failed to %s status_ring_HWAHEAD %d\n",
            "ipa3_wigig_smmu_map_channel",
            429,
            v119,
            v26);
          v120 = ipa3_ctx;
        }
        v122 = *(_QWORD *)(v120 + 34160);
        if ( v122 )
        {
          ipc_log_string(
            v122,
            "ipa %s:%d failed to %s status_ring_HWAHEAD %d\n",
            "ipa3_wigig_smmu_map_channel",
            429,
            v119,
            v26);
          return v26;
        }
      }
      return v26;
    }
    v36 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        if ( (a4 & 1) != 0 )
          v38 = "map";
        else
          v38 = "unmap";
        v35 = ipc_log_string(
                v37,
                "ipa %s:%d TX %s desc_ring_HWHEAD_pa %pa uC CB\n",
                "ipa3_wigig_smmu_map_channel",
                435,
                v38,
                a2 + 32);
        v36 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v36 + 34160);
      if ( v39 )
      {
        if ( (a4 & 1) != 0 )
          v40 = "map";
        else
          v40 = "unmap";
        v35 = ipc_log_string(
                v39,
                "ipa %s:%d TX %s desc_ring_HWHEAD_pa %pa uC CB\n",
                "ipa3_wigig_smmu_map_channel",
                435,
                v40,
                a2 + 32);
      }
    }
    v41 = ipa3_wigig_smmu_map_reg(*(_QWORD *)(a2 + 32) & 0xFFFFFFFFFFFFF000LL, a4 & 1, 3, v35);
    if ( v41 )
    {
      if ( (a4 & 1) != 0 )
        v123 = "map";
      else
        v123 = "unmap";
      v75 = v41;
      printk(&unk_3E75C6, "ipa3_wigig_smmu_map_channel");
      v124 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v125 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v125 )
        {
          v98 = ipc_log_string(
                  v125,
                  "ipa %s:%d failed to %s desc_ring_HWHEAD %d\n",
                  "ipa3_wigig_smmu_map_channel",
                  444,
                  v123,
                  v75);
          v124 = ipa3_ctx;
        }
        v126 = *(_QWORD *)(v124 + 34160);
        if ( v126 )
          v98 = ipc_log_string(
                  v126,
                  "ipa %s:%d failed to %s desc_ring_HWHEAD %d\n",
                  "ipa3_wigig_smmu_map_channel",
                  444,
                  v123,
                  v75);
      }
      goto LABEL_180;
    }
  }
  v42 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v43 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v43 )
    {
      if ( (a4 & 1) != 0 )
        v44 = "map";
      else
        v44 = "unmap";
      v24 = ipc_log_string(
              v43,
              "ipa %s:%d %s status_ring_HWTAIL_pa %pa AP CB\n",
              "ipa3_wigig_smmu_map_channel",
              451,
              v44,
              a2 + 88);
      v42 = ipa3_ctx;
    }
    v45 = *(_QWORD *)(v42 + 34160);
    if ( v45 )
    {
      if ( (a4 & 1) != 0 )
        v46 = "map";
      else
        v46 = "unmap";
      v24 = ipc_log_string(
              v45,
              "ipa %s:%d %s status_ring_HWTAIL_pa %pa AP CB\n",
              "ipa3_wigig_smmu_map_channel",
              451,
              v46,
              a2 + 88);
    }
  }
  v47 = ipa3_wigig_smmu_map_reg(*(_QWORD *)(a2 + 88) & 0xFFFFFFFFFFFFF000LL, a4 & 1, 0, v24);
  if ( v47 )
  {
    if ( (a4 & 1) != 0 )
      v97 = "map";
    else
      v97 = "unmap";
    v75 = v47;
    printk(&unk_3A4975, "ipa3_wigig_smmu_map_channel");
    v99 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v100 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v100 )
      {
        v98 = ipc_log_string(
                v100,
                "ipa %s:%d failed to %s status_ring_HWTAIL %d\n",
                "ipa3_wigig_smmu_map_channel",
                460,
                v97,
                v75);
        v99 = ipa3_ctx;
      }
      v101 = *(_QWORD *)(v99 + 34160);
      if ( v101 )
        v98 = ipc_log_string(
                v101,
                "ipa %s:%d failed to %s status_ring_HWTAIL %d\n",
                "ipa3_wigig_smmu_map_channel",
                460,
                v97,
                v75);
    }
    goto LABEL_177;
  }
  v49 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v50 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v50 )
    {
      if ( (a4 & 1) != 0 )
        v51 = "map";
      else
        v51 = "unmap";
      v48 = ipc_log_string(
              v50,
              "ipa %s:%d %s desc_ring_HWTAIL_pa %pa AP CB\n",
              "ipa3_wigig_smmu_map_channel",
              466,
              v51,
              a2 + 40);
      v49 = ipa3_ctx;
    }
    v52 = *(_QWORD *)(v49 + 34160);
    if ( v52 )
    {
      if ( (a4 & 1) != 0 )
        v53 = "map";
      else
        v53 = "unmap";
      v48 = ipc_log_string(
              v52,
              "ipa %s:%d %s desc_ring_HWTAIL_pa %pa AP CB\n",
              "ipa3_wigig_smmu_map_channel",
              466,
              v53,
              a2 + 40);
    }
  }
  v54 = ipa3_wigig_smmu_map_reg(*(_QWORD *)(a2 + 40) & 0xFFFFFFFFFFFFF000LL, a4 & 1, 0, v48);
  if ( v54 )
  {
    if ( (a4 & 1) != 0 )
      v102 = "map";
    else
      v102 = "unmap";
    v75 = v54;
    printk(&unk_3C1E66, "ipa3_wigig_smmu_map_channel");
    v104 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v105 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v105 )
      {
        v103 = ipc_log_string(
                 v105,
                 "ipa %s:%d failed to %s desc_ring_HWTAIL %d\n",
                 "ipa3_wigig_smmu_map_channel",
                 474,
                 v102,
                 v75);
        v104 = ipa3_ctx;
      }
      v106 = *(_QWORD *)(v104 + 34160);
      if ( v106 )
        v103 = ipc_log_string(
                 v106,
                 "ipa %s:%d failed to %s desc_ring_HWTAIL %d\n",
                 "ipa3_wigig_smmu_map_channel",
                 474,
                 v102,
                 v75);
    }
    goto LABEL_176;
  }
  v56 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v57 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v57 )
    {
      if ( (a4 & 1) != 0 )
        v58 = "map";
      else
        v58 = "unmap";
      v55 = ipc_log_string(
              v57,
              "ipa %s:%d %s desc_ring_base_iova %llX AP CB\n",
              "ipa3_wigig_smmu_map_channel",
              481,
              v58,
              *(_QWORD *)(a2 + 16));
      v56 = ipa3_ctx;
    }
    v59 = *(_QWORD *)(v56 + 34160);
    if ( v59 )
    {
      if ( (a4 & 1) != 0 )
        v60 = "map";
      else
        v60 = "unmap";
      v55 = ipc_log_string(
              v59,
              "ipa %s:%d %s desc_ring_base_iova %llX AP CB\n",
              "ipa3_wigig_smmu_map_channel",
              481,
              v60,
              *(_QWORD *)(a2 + 16));
    }
  }
  v61 = ipa3_wigig_smmu_map_ring(*(_QWORD *)(a2 + 16), *(unsigned __int16 *)(a2 + 24), a4 & 1, a2, v55);
  if ( v61 )
  {
    if ( (a4 & 1) != 0 )
      v107 = "map";
    else
      v107 = "unmap";
    v75 = v61;
    printk(&unk_3B5F49, "ipa3_wigig_smmu_map_channel");
    v109 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v110 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v110 )
      {
        v108 = ipc_log_string(
                 v110,
                 "ipa %s:%d failed to %s desc_ring_base %d\n",
                 "ipa3_wigig_smmu_map_channel",
                 491,
                 v107,
                 v75);
        v109 = ipa3_ctx;
      }
      v111 = *(_QWORD *)(v109 + 34160);
      if ( v111 )
        v108 = ipc_log_string(
                 v111,
                 "ipa %s:%d failed to %s desc_ring_base %d\n",
                 "ipa3_wigig_smmu_map_channel",
                 491,
                 v107,
                 v75);
    }
    goto LABEL_175;
  }
  v63 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v64 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v64 )
    {
      if ( (a4 & 1) != 0 )
        v65 = "map";
      else
        v65 = "unmap";
      v62 = ipc_log_string(
              v64,
              "ipa %s:%d %s status_ring_base_iova %llX AP CB\n",
              "ipa3_wigig_smmu_map_channel",
              497,
              v65,
              *(_QWORD *)(a2 + 64));
      v63 = ipa3_ctx;
    }
    v66 = *(_QWORD *)(v63 + 34160);
    if ( v66 )
    {
      if ( (a4 & 1) != 0 )
        v67 = "map";
      else
        v67 = "unmap";
      v62 = ipc_log_string(
              v66,
              "ipa %s:%d %s status_ring_base_iova %llX AP CB\n",
              "ipa3_wigig_smmu_map_channel",
              497,
              v67,
              *(_QWORD *)(a2 + 64));
    }
  }
  v68 = ipa3_wigig_smmu_map_ring(*(_QWORD *)(a2 + 64), *(unsigned __int16 *)(a2 + 72), a4 & 1, a2 + 48, v62);
  if ( v68 )
  {
    if ( (a4 & 1) != 0 )
      v112 = "map";
    else
      v112 = "unmap";
    v75 = v68;
    printk(&unk_3CA99C, "ipa3_wigig_smmu_map_channel");
    v113 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v114 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v114 )
      {
        v83 = ipc_log_string(
                v114,
                "ipa %s:%d failed to %s status_ring_base %d\n",
                "ipa3_wigig_smmu_map_channel",
                507,
                v112,
                v75);
        v113 = ipa3_ctx;
      }
      v115 = *(_QWORD *)(v113 + 34160);
      if ( v115 )
        v83 = ipc_log_string(
                v115,
                "ipa %s:%d failed to %s status_ring_base %d\n",
                "ipa3_wigig_smmu_map_channel",
                507,
                v112,
                v75);
    }
    goto LABEL_174;
  }
  if ( (smmu_ctx[52] & 1) == 0 )
  {
    v69 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v70 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v70 )
      {
        ipc_log_string(v70, "ipa %s:%d CB not shared - map buffers\n", "ipa3_wigig_smmu_map_channel", 512);
        v69 = ipa3_ctx;
      }
      v71 = *(_QWORD *)(v69 + 34160);
      if ( v71 )
        ipc_log_string(v71, "ipa %s:%d CB not shared - map buffers\n", "ipa3_wigig_smmu_map_channel", 512);
    }
    if ( (a1 & 1) != 0 )
    {
      v72 = *(unsigned __int16 *)(a2 + 24) >> 5;
      v73 = ipa3_smmu_map_peer_buff(*(_QWORD *)(a3 + 16), *(_DWORD *)(a3 + 24) * v72, a4 & 1, a3, 4u);
      if ( v73 )
      {
        if ( (a4 & 1) != 0 )
          v74 = "map";
        else
          v74 = "unmap";
        v75 = v73;
        printk(&unk_3B9171, "ipa3_wigig_smmu_map_buffers");
        v76 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v77 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v77 )
          {
            ipc_log_string(
              v77,
              "ipa %s:%d failed to %s rx data_buffer %d, num elem %d\n",
              "ipa3_wigig_smmu_map_buffers",
              200,
              v74,
              v75,
              v72);
            v76 = ipa3_ctx;
          }
          v78 = *(_QWORD *)(v76 + 34160);
          if ( v78 )
            ipc_log_string(
              v78,
              "ipa %s:%d failed to %s rx data_buffer %d, num elem %d\n",
              "ipa3_wigig_smmu_map_buffers",
              200,
              v74,
              v75,
              v72);
        }
LABEL_116:
        printk(&unk_3FC343, "ipa3_wigig_smmu_map_channel");
        v80 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v81 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v81 )
          {
            v79 = ipc_log_string(
                    v81,
                    "ipa %s:%d failed to %s buffers %d\n",
                    "ipa3_wigig_smmu_map_channel",
                    517,
                    v74,
                    v75);
            v80 = ipa3_ctx;
          }
          v82 = *(_QWORD *)(v80 + 34160);
          if ( v82 )
            v79 = ipc_log_string(
                    v82,
                    "ipa %s:%d failed to %s buffers %d\n",
                    "ipa3_wigig_smmu_map_channel",
                    517,
                    v74,
                    v75);
        }
        ipa3_wigig_smmu_map_ring(*(_QWORD *)(a2 + 64), *(unsigned __int16 *)(a2 + 72), (a4 & 1) == 0, a2 + 48, v79);
LABEL_174:
        ipa3_wigig_smmu_map_ring(*(_QWORD *)(a2 + 16), *(unsigned __int16 *)(a2 + 24), (a4 & 1) == 0, a2, v83);
LABEL_175:
        ipa3_wigig_smmu_map_reg(*(_QWORD *)(a2 + 40) & 0xFFFFFFFFFFFFF000LL, (a4 & 1) == 0, 0, v108);
LABEL_176:
        ipa3_wigig_smmu_map_reg(*(_QWORD *)(a2 + 88) & 0xFFFFFFFFFFFFF000LL, (a4 & 1) == 0, 0, v103);
LABEL_177:
        if ( (a1 & 1) != 0 )
        {
          v116 = (a4 ^ 1) & 1;
          v117 = 3;
          v118 = *(_QWORD *)(a2 + 80) & 0xFFFFFFFFFFFFF000LL;
LABEL_181:
          ipa3_wigig_smmu_map_reg(v118, v116, v117, v98);
          return v75;
        }
        ipa3_wigig_smmu_map_reg(*(_QWORD *)(a2 + 32) & 0xFFFFFFFFFFFFF000LL, (a4 ^ 1) & 1, 3, v98);
LABEL_180:
        v117 = 0;
        v116 = (a4 & 1) == 0;
        v118 = *(_QWORD *)(a2 + 80) & 0xFFFFFFFFFFFFF000LL;
        goto LABEL_181;
      }
    }
    else if ( *(_DWORD *)(a3 + 16) )
    {
      v84 = -1;
      while ( 1 )
      {
        v85 = v84 + 1;
        v86 = ipa3_smmu_map_peer_buff(
                *(_QWORD *)(*(_QWORD *)(a3 + 8) + 8LL * v85),
                *(_DWORD *)(a3 + 20),
                a4 & 1,
                *(_QWORD *)a3 + 16LL * v85,
                4u);
        if ( v86 )
          break;
        v87 = v84 + 2;
        ++v84;
        if ( v87 >= *(_DWORD *)(a3 + 16) )
          goto LABEL_126;
      }
      if ( (a4 & 1) != 0 )
        v74 = "map";
      else
        v74 = "unmap";
      v75 = v86;
      printk(&unk_3F01D4, "ipa3_wigig_smmu_map_buffers");
      v127 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v128 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v128 )
        {
          ipc_log_string(
            v128,
            "ipa %s:%d %d: failed to %s tx data buffer %d\n",
            "ipa3_wigig_smmu_map_buffers",
            220,
            v85,
            v74,
            v75);
          v127 = ipa3_ctx;
        }
        v129 = *(_QWORD *)(v127 + 34160);
        if ( v129 )
          ipc_log_string(
            v129,
            "ipa %s:%d %d: failed to %s tx data buffer %d\n",
            "ipa3_wigig_smmu_map_buffers",
            220,
            v85,
            v74,
            v75);
      }
      if ( (v84 & 0x80000000) != 0 )
        goto LABEL_116;
      v130 = 16LL * v84;
      v131 = 8LL * v84;
      do
      {
        v132 = ipa3_smmu_map_peer_buff(
                 *(_QWORD *)(*(_QWORD *)(a3 + 8) + v131),
                 *(_DWORD *)(a3 + 20),
                 (a4 ^ 1) & 1,
                 *(_QWORD *)a3 + v130,
                 4u);
        v130 -= 16;
        v131 -= 8;
      }
      while ( v130 != -16 );
      v75 = v132;
      if ( v132 )
        goto LABEL_116;
      goto LABEL_131;
    }
LABEL_126:
    v88 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 0;
    v89 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v89 )
    {
      ipc_log_string(v89, "ipa %s:%d exit\n", "ipa3_wigig_smmu_map_buffers", 236);
      v88 = ipa3_ctx;
    }
    v90 = *(_QWORD *)(v88 + 34160);
    if ( v90 )
      ipc_log_string(v90, "ipa %s:%d exit\n", "ipa3_wigig_smmu_map_buffers", 236);
  }
LABEL_131:
  v91 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v92 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v92 )
  {
    ipc_log_string(v92, "ipa %s:%d exit\n", "ipa3_wigig_smmu_map_channel", 522);
    v91 = ipa3_ctx;
  }
  result = *(_QWORD *)(v91 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_wigig_smmu_map_channel", 522);
    return 0;
  }
  return result;
}
