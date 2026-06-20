__int64 __fastcall mem_offline_driver_probe(__int64 a1)
{
  __int64 v1; // x20
  unsigned int *property; // x0
  unsigned int v4; // w9
  unsigned int v5; // w8
  unsigned __int64 v6; // x0
  __int64 result; // x0
  __int64 node_by_name; // x0
  __int64 v9; // x21
  int v10; // w19
  int v11; // w20
  __int64 v12; // x0
  int v13; // w24
  __int64 v14; // x25
  __int64 v15; // x22
  int v16; // w23
  __int64 v17; // x0
  unsigned __int64 v18; // x21
  unsigned __int64 v19; // x9
  __int64 v20; // x8
  int v21; // w14
  __int64 v22; // x16
  __int64 v23; // x16
  unsigned __int64 v24; // x15
  unsigned int v25; // w17
  unsigned __int64 v26; // x16
  __int64 v27; // x17
  unsigned int v28; // w1
  __int64 v29; // x25
  __int64 v30; // x9
  unsigned __int64 v31; // x8
  unsigned int v32; // w10
  __int64 v33; // x9
  __int64 v34; // x10
  int v35; // w11
  unsigned int v36; // w12
  unsigned __int64 v37; // x9
  unsigned __int64 v38; // x0
  __int64 v39; // x20
  unsigned __int64 v40; // x21
  __int64 v41; // x0
  unsigned __int64 v42; // x19
  unsigned __int64 v43; // x0
  unsigned __int64 v44; // x0
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x19
  char v47; // w23
  void *v48; // x0
  __int64 v49; // x0
  __int64 v50; // x19
  int v51; // w20
  int v52; // w0
  int v53; // w20
  __int64 v54; // x21
  unsigned int v55; // w22
  __int64 v56; // x28
  __int64 v57; // x27
  __int64 v58; // x8
  __int64 v59; // x9
  unsigned __int64 v60; // x10
  __int64 v61; // x9
  __int64 v62; // x8
  __int64 v63; // x0
  unsigned int *v64; // x9
  unsigned __int64 v65; // x11
  int v66; // w8
  unsigned int *v67; // x10
  unsigned int v68; // t1
  unsigned __int64 v69; // x10
  int v70; // w11
  unsigned int *v71; // x13
  unsigned int v72; // t1
  unsigned __int64 v73; // x11
  int v74; // w10
  unsigned int *v75; // x13
  unsigned int v76; // t1
  __int64 v77; // x13
  unsigned int v78; // w14
  unsigned int *v79; // x9
  int v80; // w11
  unsigned int v81; // t1
  void *v82; // x0
  __int64 v83; // x21
  __int64 v84; // x19
  unsigned int v85; // w9
  unsigned __int8 v86; // w10
  __int64 *v87; // x14
  __int64 v88; // x15
  __int64 v89; // x16
  __int64 v90; // x0
  unsigned __int64 v91; // x14
  unsigned __int64 v92; // x16
  __int64 v93; // x15
  unsigned __int64 v94; // x17
  bool v95; // cf
  unsigned __int64 v96; // x19
  unsigned __int64 v97; // x0
  __int64 v98; // x9
  unsigned __int64 v99; // x8
  unsigned __int64 v100; // x11
  int v101; // w8
  unsigned __int8 v102; // w22
  int v103; // w26
  __int64 v104; // x27
  __int64 *v105; // x9
  unsigned __int64 v106; // x19
  __int64 v107; // x10
  __int64 v108; // x11
  __int64 v109; // x9
  unsigned __int64 v110; // x23
  unsigned __int64 v111; // x28
  __int64 v112; // x8
  __int64 v113; // x10
  __int64 v114; // x9
  unsigned __int64 v115; // x24
  unsigned __int64 v116; // x21
  __int64 v117; // x0
  __int64 v118; // x8
  unsigned int v119; // w9
  int v120; // w10
  int v121; // w12
  __int64 v122; // x13
  __int64 v123; // x11
  unsigned __int64 v124; // x19
  __int64 v125; // x0
  unsigned __int64 v126; // x9
  unsigned __int64 v127; // x8
  unsigned int v128; // w8
  signed int v129; // w8
  unsigned int v130; // w19
  unsigned __int64 v131; // x9
  int v132; // w10
  int v133; // w10
  __int64 v134; // x9
  __int64 v135; // x8
  void *v136; // x0
  int v137; // [xsp+0h] [xbp-40h] BYREF
  int v138; // [xsp+4h] [xbp-3Ch] BYREF
  char v139[8]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v140; // [xsp+10h] [xbp-30h]
  int v141; // [xsp+18h] [xbp-28h]
  char s[8]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v143; // [xsp+28h] [xbp-18h]
  int v144; // [xsp+30h] [xbp-10h]
  __int64 v145; // [xsp+38h] [xbp-8h]

  v145 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( nopasr )
  {
    printk(&unk_A110);
    result = 0;
    goto LABEL_149;
  }
  v1 = *(_QWORD *)(a1 + 760);
  property = (unsigned int *)of_get_property(v1, "granule", 0);
  if ( !property )
  {
    v82 = &unk_9DCA;
    goto LABEL_147;
  }
  v4 = *property;
  if ( !*property
    || (v5 = bswap32(v4), offline_granule = v5, (v4 & (v4 - 1)) != 0)
    || ((v5 >> 7) & 0x1F) == 0 && 0x8000000 % (v5 << 20) )
  {
    v82 = &unk_9FF8;
LABEL_147:
    printk(v82);
LABEL_148:
    result = 4294967274LL;
    goto LABEL_149;
  }
  if ( of_find_property(v1, "qcom,qmp", 0) )
  {
    v6 = qmp_get(a1 + 16);
    qmp = v6;
    if ( v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( v6 == -517 )
      {
        result = 4294966779LL;
        goto LABEL_149;
      }
      printk(&unk_99B4);
      result = (unsigned int)qmp;
      if ( (_DWORD)qmp )
        goto LABEL_149;
    }
  }
  else
  {
    is_rpm_controller = 1;
  }
  *(_DWORD *)s = 0;
  node_by_name = of_find_node_by_name(of_root, "memory");
  if ( !node_by_name )
  {
    v82 = &unk_9D30;
    goto LABEL_147;
  }
  v9 = node_by_name;
  v10 = of_n_addr_cells(of_root);
  v11 = of_n_size_cells(of_root);
  v12 = of_find_property(v9, "reg", s);
  if ( !v12 )
  {
    v82 = &unk_9659;
    goto LABEL_147;
  }
  v13 = v11 + v10;
  v14 = *(_QWORD *)(v12 + 16);
  v15 = v12;
  v16 = (*(int *)s >> 2) / (v11 + v10);
  v17 = ((__int64 (*)(void))memblock_end_of_DRAM)();
  if ( v16 )
  {
    v18 = v17;
    v19 = 0;
    v20 = 0;
    v21 = v16;
    while ( !v10 )
    {
      v24 = 0;
      v26 = 0;
      if ( v11 )
        goto LABEL_25;
LABEL_16:
      v22 = v26 + v24;
      --v21;
      if ( v24 > v19 )
      {
        v20 = v22;
        v19 = v24;
      }
      v14 += 4LL * v13;
      if ( !v21 )
      {
        v29 = *(_QWORD *)(v15 + 16);
        bootmem_dram_end_addr = v20;
        while ( !v10 )
        {
          v31 = 0;
          v33 = 0;
          if ( v11 )
            goto LABEL_36;
LABEL_38:
          v37 = v33 + v31;
          if ( v37 > v18 )
          {
            if ( v31 <= v18 )
              v31 = v18;
            v17 = _bitmap_set(&movable_bitmap, (v31 - v18) >> 27, (v37 - v31) >> 27);
          }
          --v16;
          v29 += 4LL * v13;
          if ( !v16 )
            goto LABEL_43;
        }
        v30 = 0;
        v31 = 0;
        do
        {
          v32 = *(_DWORD *)(v29 + 4 * v30++);
          v31 = bswap32(v32) | (v31 << 32);
        }
        while ( v10 != (_DWORD)v30 );
        v33 = 0;
        if ( !v11 )
          goto LABEL_38;
LABEL_36:
        v34 = 4LL * v10;
        v35 = v11;
        do
        {
          v36 = *(_DWORD *)(v29 + v34);
          --v35;
          v34 += 4;
          v33 = bswap32(v36) | (unsigned __int64)(v33 << 32);
        }
        while ( v35 );
        goto LABEL_38;
      }
    }
    v23 = 0;
    v24 = 0;
    do
    {
      v25 = *(_DWORD *)(v14 + 4 * v23++);
      v24 = bswap32(v25) | (v24 << 32);
    }
    while ( v10 != (_DWORD)v23 );
    v26 = 0;
    if ( !v11 )
      goto LABEL_16;
LABEL_25:
    v27 = 4LL * v10;
    LODWORD(v17) = v11;
    do
    {
      v28 = *(_DWORD *)(v14 + v27);
      v17 = (unsigned int)(v17 - 1);
      v27 += 4;
      v26 = bswap32(v28) | (v26 << 32);
    }
    while ( (_DWORD)v17 );
    goto LABEL_16;
  }
  bootmem_dram_end_addr = 0;
LABEL_43:
  v38 = memblock_end_of_DRAM(v17);
  v39 = v38 >> 27;
  v40 = (unsigned __int64)(bootmem_dram_end_addr - 1) >> 27;
  v41 = memblock_end_of_DRAM(v38);
  v42 = memory_block_size_bytes(v41);
  start_section_nr = v39;
  sections_per_block = v42 >> 27;
  end_section_nr = v40;
  v43 = memblock_end_of_DRAM(v42);
  if ( v43 >= bootmem_dram_end_addr )
  {
    printk(&unk_A2EA);
    result = 4294967277LL;
    goto LABEL_149;
  }
  v44 = memblock_end_of_DRAM(v43);
  if ( v44 % v42 )
  {
    memblock_end_of_DRAM(v44);
    printk(&unk_A144);
    printk(&unk_9855);
    ++start_section_nr;
  }
  if ( bootmem_dram_end_addr % v42 )
  {
    printk(&unk_9ED1);
    printk(&unk_9B2E);
    v45 = --end_section_nr;
  }
  else
  {
    v45 = end_section_nr;
  }
  v46 = start_section_nr;
  offlinable_region_start_addr = start_section_nr << 27;
  if ( start_section_nr <= v45 )
  {
    v47 = 1;
    while ( 1 )
    {
      if ( ((*(_QWORD *)((char *)&movable_bitmap + (((v46 - start_section_nr) >> 3) & 0x1FFFFFFFFFFFFFF8LL)) >> ((unsigned __int8)v46 - (unsigned __int8)start_section_nr))
          & 1) == 0 )
        goto LABEL_50;
      if ( ((((unsigned __int64)(unsigned int)sections_per_block << 27) - 1) & (v46 << 27)) != 0 )
      {
        v48 = &unk_9A95;
        goto LABEL_56;
      }
      if ( (unsigned int)add_memory(0) )
      {
        v48 = &unk_A020;
LABEL_56:
        printk(v48);
        v47 = 0;
        v46 += (unsigned int)sections_per_block;
        if ( v46 > end_section_nr )
          break;
      }
      else
      {
LABEL_50:
        v46 += (unsigned int)sections_per_block;
        if ( v46 > end_section_nr )
        {
          if ( (v47 & 1) != 0 )
            goto LABEL_59;
          break;
        }
      }
    }
  }
  printk(&unk_9E6F);
LABEL_59:
  v137 = 0;
  v141 = 0;
  *(_QWORD *)v139 = 0;
  v140 = 0;
  v49 = of_find_node_by_name(of_root, "ddr-regions");
  if ( !v49 )
  {
    v82 = &unk_9AF4;
    goto LABEL_147;
  }
  v50 = v49;
  v138 = 0;
  v144 = 0;
  *(_QWORD *)s = 0;
  v143 = 0;
  snprintf(s, 0x14u, "region%d", 0);
  if ( !of_find_property(v50, s, &v138) )
  {
    num_ddr_regions = 0;
    printk(&unk_9F8D);
    goto LABEL_148;
  }
  v51 = 1;
  snprintf(s, 0x14u, "region%d", 1);
  if ( of_find_property(v50, s, &v138) )
  {
    v51 = 2;
    snprintf(s, 0x14u, "region%d", 2);
    if ( of_find_property(v50, s, &v138) )
    {
      v51 = 3;
      snprintf(s, 0x14u, "region%d", 3);
      if ( of_find_property(v50, s, &v138) )
      {
        v51 = 4;
        snprintf(s, 0x14u, "region%d", 4);
        if ( of_find_property(v50, s, &v138) )
        {
          v51 = 5;
          snprintf(s, 0x14u, "region%d", 5);
          if ( of_find_property(v50, s, &v138) )
          {
            v51 = 6;
            snprintf(s, 0x14u, "region%d", 6);
            if ( of_find_property(v50, s, &v138) )
            {
              v51 = 7;
              snprintf(s, 0x14u, "region%d", 7);
              if ( of_find_property(v50, s, &v138) )
              {
                v51 = 8;
                snprintf(s, 0x14u, "region%d", 8);
                if ( of_find_property(v50, s, &v138) )
                {
                  snprintf(s, 0x14u, "region%d", 9);
                  if ( of_find_property(v50, s, &v138) )
                    v51 = 10;
                  else
                    v51 = 9;
                }
              }
            }
          }
        }
      }
    }
  }
  num_ddr_regions = v51;
  if ( !is_mul_ok(v51, 0x28u) )
  {
    result = 4294967284LL;
    ddr_regions = 0;
    goto LABEL_149;
  }
  ddr_regions = _kmalloc_noprof(40LL * v51, 3520);
  if ( !ddr_regions )
    goto LABEL_141;
  v52 = of_n_addr_cells(of_root);
  if ( num_ddr_regions < 1 )
    goto LABEL_108;
  v53 = v52;
  v54 = 0;
  v55 = v52 - 1;
  v56 = v52;
  v57 = 3LL * v52;
  do
  {
    snprintf(v139, 0x14u, "region%d", v54);
    v63 = of_find_property(v50, v139, &v137);
    if ( !v63 || (v137 & 0xFFFFFFFC) != 0x28 )
      goto LABEL_148;
    if ( v53 )
    {
      v64 = *(unsigned int **)(v63 + 16);
      v65 = 0;
      v66 = v53;
      v67 = v64;
      do
      {
        v68 = *v67++;
        --v66;
        v65 = bswap32(v68) | (v65 << 32);
      }
      while ( v66 );
      v58 = ddr_regions;
      v69 = 0;
      *(_QWORD *)(ddr_regions + 40 * v54) = v65;
      v70 = v53;
      v71 = &v64[v56];
      do
      {
        v72 = *v71++;
        --v70;
        v69 = bswap32(v72) | (v69 << 32);
      }
      while ( v70 );
      v73 = 0;
      *(_QWORD *)(v58 + 40 * v54 + 8) = v69;
      v74 = v53;
      v75 = &v64[v56 + v56];
      do
      {
        v76 = *v75++;
        --v74;
        v73 = bswap32(v76) | (v73 << 32);
      }
      while ( v74 );
      v77 = v58 + 40 * v54;
      v60 = 0;
      *(_QWORD *)(v77 + 32) = v73;
      v78 = bswap32(v64[v57 + v55]);
      v79 = &v64[v56 + v56 + v56 + v56];
      v80 = v53;
      *(_DWORD *)(v77 + 24) = v78;
      do
      {
        v81 = *v79++;
        --v80;
        v60 = bswap32(v81) | (v60 << 32);
      }
      while ( v80 );
    }
    else
    {
      v58 = ddr_regions;
      v59 = ddr_regions + 40 * v54;
      v60 = 0;
      *(_QWORD *)(v59 + 32) = 0;
      *(_DWORD *)(v59 + 24) = 0;
      *(_QWORD *)v59 = 0;
      *(_QWORD *)(v59 + 8) = 0;
    }
    v61 = v58 + 40 * v54;
    v62 = num_ddr_regions;
    ++v54;
    *(_QWORD *)(v61 + 16) = v60;
  }
  while ( v54 < v62 );
  if ( (int)v62 < 1 )
    goto LABEL_108;
  v83 = 0;
  v84 = 0;
  do
  {
    printk(&unk_96FD);
    ++v84;
    v83 += 40;
  }
  while ( v84 < num_ddr_regions );
  if ( num_ddr_regions < 1 )
  {
LABEL_108:
    v85 = 0;
  }
  else
  {
    v85 = 0;
    v86 = 0;
    do
    {
      v87 = (__int64 *)(ddr_regions + 40LL * v86);
      v88 = v87[2];
      if ( v88 )
      {
        v89 = *v87;
        v90 = v87[4];
        v91 = v87[1] + *v87;
        v92 = v90 + v89;
        if ( v92 < v91 )
        {
          v93 = v88 << 20;
          do
          {
            v94 = v92 + v93;
            if ( v92 + v93 > v91 )
              break;
            v95 = v92 >= offlinable_region_start_addr;
            v92 += v93;
            if ( v95 )
              ++v85;
          }
          while ( v94 < v91 );
        }
      }
      ++v86;
    }
    while ( num_ddr_regions > v86 );
  }
  num_segments = v85;
  if ( (v85 & 0x80000000) != 0 )
  {
    result = 4294967284LL;
    segment_infos = 0;
    goto LABEL_149;
  }
  v96 = 32LL * v85;
  v97 = _kmalloc_noprof(v96, 3520);
  segment_infos = v97;
  if ( !v97 )
    goto LABEL_141;
  if ( num_segments >= 1 )
  {
    v98 = 32LL * (unsigned int)num_segments;
    v99 = 0;
    v100 = v96;
    while ( v96 >= v99 && v100 >= 8 && (v99 & 0x8000000000000000LL) == 0 && v96 >= v99 )
    {
      *(_QWORD *)(v97 + v99) = -1;
      v99 += 32LL;
      v100 -= 32LL;
      if ( v98 == v99 )
        goto LABEL_118;
    }
LABEL_187:
    __break(1u);
  }
LABEL_118:
  v101 = num_ddr_regions;
  if ( num_ddr_regions >= 1 )
  {
    v102 = 0;
    v103 = 0;
    v104 = *(_QWORD *)(ddr_regions + 16) << 20;
    do
    {
      v105 = (__int64 *)(ddr_regions + 40LL * v102);
      v106 = v105[2] << 20;
      if ( v106 )
      {
        if ( v104 != v106 )
          differing_segment_sizes = 1;
        v107 = *v105;
        v108 = v105[1];
        v109 = v105[4];
        v110 = v108 + v107;
        v111 = v109 + v107;
        if ( v109 + v107 < (unsigned __int64)(v108 + v107) )
        {
          do
          {
            v115 = v111 + v106;
            if ( v111 + v106 > v110 )
              break;
            if ( v111 >= offlinable_region_start_addr )
            {
              v97 = memory_block_size_bytes(v97);
              if ( v106 > v97 )
              {
                v97 = memory_block_size_bytes(v97);
                v112 = v106 / v97;
              }
              else
              {
                v112 = 1;
              }
              v113 = v103++;
              v114 = segment_infos + 32 * v113;
              *(_QWORD *)v114 = v111;
              *(_QWORD *)(v114 + 8) = v106;
              *(_QWORD *)(v114 + 16) = v112;
              *(_DWORD *)(v114 + 24) = 0xFFFFFFFFFFFFFFFFLL >> -(char)v112;
            }
            v111 += v106;
          }
          while ( v115 < v110 );
          v101 = num_ddr_regions;
        }
      }
      ++v102;
    }
    while ( v101 > v102 );
  }
  if ( differing_segment_sizes == 1 )
    printk(&unk_99E2);
  result = check_segment_granule_alignment();
  if ( (_DWORD)result )
    goto LABEL_149;
  printk(&unk_9A2D);
  v116 = (end_section_nr - start_section_nr + 1) / (unsigned __int64)(unsigned int)sections_per_block;
  mem_info = _kmalloc_noprof(72LL * (unsigned int)(2 * v116), 3520);
  if ( !mem_info )
  {
LABEL_141:
    result = 4294967284LL;
    goto LABEL_149;
  }
  v117 = ktime_get();
  if ( (_DWORD)v116 )
  {
    v118 = mem_info;
    if ( (unsigned int)(v116 + 0x7FFFFFFF) >= 0x80000001 )
    {
      v120 = 0;
      v119 = v116 & 0xFFFFFFFE;
      do
      {
        v121 = v120 + 1;
        v122 = v118 + 72LL * v120;
        v120 += 2;
        *(_QWORD *)(v122 + 64) = v117;
        *(_QWORD *)(v118 + 72LL * v121 + 64) = v117;
      }
      while ( v119 != v120 );
      if ( v119 == (_DWORD)v116 )
        goto LABEL_157;
    }
    else
    {
      v119 = 0;
    }
    do
    {
      v123 = v118 + 72LL * (int)v119++;
      *(_QWORD *)(v123 + 64) = v117;
    }
    while ( v119 < (unsigned int)v116 );
  }
LABEL_157:
  v124 = 4LL * (unsigned int)v116;
  v125 = _kmalloc_noprof(v124, 3520);
  mem_sec_state = v125;
  if ( !v125 )
  {
    v130 = -12;
LABEL_177:
    kfree(mem_info);
    result = v130;
    goto LABEL_149;
  }
  if ( (_DWORD)v116 )
  {
    v126 = v124 >> 2;
    v127 = (unsigned int)(v116 - 1);
    if ( v127 >= v124 >> 2 )
      v127 = v124 >> 2;
    v128 = v127 + 1;
    if ( v128 >= 3 )
    {
      if ( (unsigned int)(v116 - 1) < v126 )
        v126 = (unsigned int)(v116 - 1);
      v131 = v126 >> 31;
      if ( v131 )
      {
        v129 = 0;
      }
      else
      {
        v132 = v128 & 1;
        if ( (v128 & 1) == 0 )
          v132 = 2;
        v129 = v128 - v132;
        do
        {
          v133 = v131 + 1;
          *(_DWORD *)(v125 + 4LL * (int)v131) = 0;
          LODWORD(v131) = v131 + 2;
          *(_DWORD *)(v125 + 4LL * v133) = 0;
        }
        while ( v129 != (_DWORD)v131 );
      }
    }
    else
    {
      v129 = 0;
    }
    while ( v124 > 4LL * v129 )
    {
      v134 = v129++;
      *(_DWORD *)(v125 + 4 * v134) = 0;
      if ( v129 >= (unsigned int)v116 )
        goto LABEL_174;
    }
    goto LABEL_187;
  }
LABEL_174:
  if ( (unsigned int)mem_sysfs_init() )
  {
    v130 = -19;
LABEL_176:
    kfree(mem_sec_state);
    goto LABEL_177;
  }
  if ( (unsigned int)register_memory_notifier(&hotplug_memory_callback_nb) )
  {
    v130 = -19;
    v136 = &unk_9C11;
    goto LABEL_186;
  }
  printk(&unk_9940);
  if ( bypass_send_msg == 1 )
    printk(&unk_94F8);
  v135 = alloc_workqueue("reverse_migrate_wq", 6, 0);
  result = 0;
  migrate_wq = v135;
  if ( !v135 )
  {
    v130 = -12;
    v136 = &unk_9A60;
LABEL_186:
    printk(v136);
    sysfs_remove_group(kobj, &mem_attr_group);
    kobject_put(kobj);
    goto LABEL_176;
  }
LABEL_149:
  _ReadStatusReg(SP_EL0);
  return result;
}
