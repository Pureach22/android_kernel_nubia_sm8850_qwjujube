__int64 __fastcall iommu_debug_functional_fast_dma_api_show(__int64 a1)
{
  __int64 v1; // x21
  __int64 *v2; // x8
  int v4; // w23
  const char *v5; // x2
  __int64 v6; // x21
  int v7; // w19
  const char *v8; // x2
  __int64 v9; // x19
  __int64 *v10; // x8
  __int64 v11; // x0
  __int64 v12; // x28
  int v13; // w19
  __int64 result; // x0
  __int64 v15; // x1
  __int64 v16; // x23
  __int64 v17; // x8
  __int64 v18; // x22
  const char *v19; // x20
  const char *v20; // x24
  unsigned __int64 v21; // x19
  __int64 v22; // x8
  const char *v23; // x2
  __int64 free_pages_noprof; // x25
  __int64 v25; // x27
  __int64 v26; // x28
  void *v27; // x0
  const char *v28; // x27
  int v29; // w28
  const char *v30; // x2
  char v31; // w0
  char *v32; // x8
  __int64 v33; // x21
  int v34; // w19
  const char *v35; // x2
  const char *v36; // x20
  void *v37; // x0
  __int64 v38; // x27
  __int64 *v39; // x20
  __int64 v40; // x8
  __int64 v41; // x8
  const char *v42; // x2
  __int64 v43; // x28
  __int64 v44; // x20
  const char *v45; // x2
  void *v46; // x21
  const char **v47; // x21
  unsigned int v48; // w9
  __int64 v49; // x1
  __int64 v50; // x26
  const char *v51; // x2
  int v52; // w24
  int v53; // w21
  unsigned __int64 v54; // x23
  char v55; // w0
  char v56; // w25
  __int64 v57; // x0
  const char *v58; // x0
  const char *v59; // x2
  unsigned __int64 v60; // x1
  int v61; // w23
  int v62; // w25
  int v63; // w22
  int v64; // w8
  unsigned __int64 v65; // x19
  __int64 v66; // x24
  int v67; // w24
  char v68; // w0
  char v69; // w22
  const char *v70; // x0
  const char *v71; // x2
  char v72; // w0
  char v73; // w24
  __int64 v74; // x24
  int v75; // w19
  __int64 v76; // x23
  __int64 v77; // x8
  unsigned int v78; // w9
  __int64 v79; // x1
  const char *v80; // x20
  void *v81; // x0
  int v82; // w21
  unsigned __int64 v83; // x27
  bool v84; // cf
  char v85; // w0
  __int64 v86; // x0
  const char *v87; // x0
  const char *v88; // x2
  void *v89; // x0
  char v90; // w0
  __int64 v91; // x20
  int v92; // w26
  const char *v93; // x21
  char v94; // w21
  const char *v95; // x0
  const char *v96; // x2
  char v97; // w21
  const char *v98; // x0
  const char *v99; // x2
  char v100; // w0
  int v101; // w22
  unsigned __int64 v102; // x8
  __int64 v103; // x20
  int v104; // w21
  const char *v105; // x2
  const char *v106; // x20
  void *v107; // x0
  char v108; // w21
  const char *v109; // x0
  const char *v110; // x2
  char v111; // w0
  char v112; // w21
  const char *v113; // x0
  const char *v114; // x2
  int v115; // [xsp+Ch] [xbp-84h]
  int v116; // [xsp+10h] [xbp-80h]
  unsigned int v117; // [xsp+14h] [xbp-7Ch]
  __int64 v118; // [xsp+28h] [xbp-68h]
  __int64 *v119; // [xsp+30h] [xbp-60h]
  __int64 v120; // [xsp+38h] [xbp-58h]
  const char **v121; // [xsp+48h] [xbp-48h]
  char v122; // [xsp+48h] [xbp-48h]
  __int64 v123; // [xsp+50h] [xbp-40h] BYREF
  __int64 v124; // [xsp+58h] [xbp-38h] BYREF
  _QWORD v125[6]; // [xsp+60h] [xbp-30h] BYREF

  v125[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 128);
  v2 = *(__int64 **)(v1 + 32);
  if ( !v2 )
  {
    printk(&unk_D248, "iommu_debug_functional_fast_dma_api_show");
    result = 4294967274LL;
    goto LABEL_20;
  }
  if ( (*(_BYTE *)(v1 + 52) & 1) == 0 )
  {
    v15 = v2[14];
    if ( !v15 )
      v15 = *v2;
    printk(&unk_C998, v15);
    seq_printf(a1, "Not a fastmap usecase\n");
    result = 0;
    goto LABEL_20;
  }
  mutex_lock(v1 + 56);
  if ( iommu_debug_usecase_reset(v1) )
  {
    v4 = _functional_dma_api_alloc_test(*(__int64 **)(v1 + 32), a1);
    mutex_unlock(v1 + 56);
    if ( v4 )
      v5 = "FAIL";
    else
      v5 = "SUCCESS";
  }
  else
  {
    mutex_unlock(v1 + 56);
    v5 = "FAIL";
    v4 = -22;
  }
  seq_printf(a1, "%s\n", v5);
  v6 = *(_QWORD *)(a1 + 128);
  mutex_lock(v6 + 56);
  if ( iommu_debug_usecase_reset(v6) )
  {
    v7 = _functional_dma_api_basic_test(*(const char ***)(v6 + 32), a1);
    mutex_unlock(v6 + 56);
    v116 = v7;
    if ( v7 )
      v8 = "FAIL";
    else
      v8 = "SUCCESS";
  }
  else
  {
    mutex_unlock(v6 + 56);
    v8 = "FAIL";
    v116 = -22;
  }
  seq_printf(a1, "%s\n", v8);
  v9 = *(_QWORD *)(a1 + 128);
  v125[0] = 4096;
  v125[1] = 0x2000;
  v125[2] = 0x4000;
  v125[3] = 0x10000;
  v125[4] = 0;
  mutex_lock(v9 + 56);
  v10 = *(__int64 **)(v9 + 32);
  if ( !v10 )
  {
    mutex_unlock(v9 + 56);
    v13 = -19;
    goto LABEL_19;
  }
  v11 = v10[14];
  if ( !v11 )
    v11 = *v10;
  v12 = kstrdup(v11, 3264);
  mutex_unlock(v9 + 56);
  if ( !v12 )
  {
    v13 = -12;
    goto LABEL_19;
  }
  v115 = v4;
  v16 = 0;
  v17 = 4096;
  v118 = a1;
  v18 = 0;
  v19 = "Full VA sweep @%s:";
  v20 = "%s\n";
  v21 = (unsigned __int64)v125;
  v120 = v12;
LABEL_72:
  if ( v17 >= 0x4000 )
  {
    if ( v17 != 0x4000 && v17 != 0x10000 && v17 != 0x100000 )
LABEL_26:
      printk(&unk_D4EA, "_size_to_string");
    while ( 1 )
    {
LABEL_27:
      printk(&unk_D6C4, v12);
      v22 = *(_QWORD *)((char *)v125 + v18);
      if ( v22 >= 0x200000 )
      {
        if ( v22 <= 20971519 )
        {
          if ( v22 == 0x200000 )
          {
            v23 = (const char *)&unk_D4E7;
            goto LABEL_50;
          }
          if ( v22 == 12582912 )
          {
            v23 = "12M";
            goto LABEL_50;
          }
        }
        else
        {
          switch ( v22 )
          {
            case 0x1400000LL:
              v23 = (const char *)&unk_D811;
              goto LABEL_50;
            case 0x1800000LL:
              v23 = (const char *)&unk_CCCB;
              goto LABEL_50;
            case 0x2000000LL:
              v23 = "32M";
              goto LABEL_50;
          }
        }
      }
      else if ( v22 < 0x4000 )
      {
        v23 = "4K";
        if ( v22 == 4096 )
          goto LABEL_50;
        if ( v22 == 0x2000 )
        {
          v23 = "8K";
          goto LABEL_50;
        }
      }
      else
      {
        switch ( v22 )
        {
          case 0x4000LL:
            v23 = "16K";
            goto LABEL_50;
          case 0x10000LL:
            v23 = (const char *)&unk_D68A;
            goto LABEL_50;
          case 0x100000LL:
            v23 = (const char *)&unk_D80E;
            goto LABEL_50;
        }
      }
      printk(&unk_D4EA, "_size_to_string");
      v23 = "unknown size";
LABEL_50:
      free_pages_noprof = v118;
      seq_printf(v118, "Full VA sweep @%s:", v23);
      v25 = *(_QWORD *)(v118 + 128);
      v26 = *(_QWORD *)((char *)v125 + v18);
      mutex_lock(v25 + 56);
      if ( iommu_debug_usecase_reset(v25) )
      {
        v29 = _full_va_sweep(*(_QWORD *)(v25 + 32), *(_QWORD *)(v25 + 40), v26);
        mutex_unlock(v25 + 56);
        if ( v29 )
          v30 = "FAIL";
        else
          v30 = "SUCCESS";
        seq_printf(v118, "%s\n", v30);
        if ( v29 )
        {
          v16 = 4294967274LL;
          v27 = &unk_D054;
          v28 = "  -> FAILED\n";
        }
        else
        {
          v27 = &unk_CFA4;
          v28 = "  -> SUCCEEDED\n";
        }
        free_pages_noprof = v118;
      }
      else
      {
        mutex_unlock(v25 + 56);
        seq_printf(v118, "%s\n", "FAIL");
        v16 = 4294967274LL;
        v27 = &unk_D054;
        v28 = "  -> FAILED\n";
      }
      v12 = v120;
      printk(v27, v120);
      v31 = seq_printf(free_pages_noprof, v28);
      if ( (unsigned __int64)(v18 - 32) < 0xFFFFFFFFFFFFFFD8LL )
        goto LABEL_259;
      v32 = (char *)v125 + v18;
      v18 += 8;
      v17 = *((_QWORD *)v32 + 1);
      if ( v17 < 0x200000 )
        goto LABEL_72;
      if ( v17 <= 20971519 )
      {
        if ( v17 != 0x200000 && v17 != 12582912 )
          goto LABEL_26;
      }
      else if ( v17 != 20971520 && v17 != 25165824 && v17 != 0x2000000 )
      {
        goto LABEL_26;
      }
    }
  }
  if ( v17 == 4096 || v17 == 0x2000 )
    goto LABEL_27;
  if ( v17 )
    goto LABEL_26;
  printk(&unk_C9B5, v12);
  v18 = v118;
  seq_printf(v118, "bonus map:");
  v33 = *(_QWORD *)(v118 + 128);
  mutex_lock(v33 + 56);
  if ( !iommu_debug_usecase_reset(v33) )
  {
    mutex_unlock(v33 + 56);
    seq_printf(v118, "%s\n", "FAIL");
    goto LABEL_90;
  }
  v34 = _full_va_sweep(*(_QWORD *)(v33 + 32), *(_QWORD *)(v33 + 40), 4096);
  mutex_unlock(v33 + 56);
  if ( v34 )
    v35 = "FAIL";
  else
    v35 = "SUCCESS";
  seq_printf(v118, "%s\n", v35);
  if ( v34 )
  {
LABEL_90:
    v36 = "  -> FAILED\n";
    v16 = 4294967274LL;
    v37 = &unk_D054;
  }
  else
  {
    v36 = "  -> SUCCEEDED\n";
    v37 = &unk_CFA4;
  }
  printk(v37, v12);
  seq_printf(v118, v36);
  v38 = 0;
  v20 = (const char *)&unk_D26A;
  free_pages_noprof = (__int64)"FAIL";
  v39 = v125;
  v40 = 4096;
  v21 = (unsigned __int64)"ecting DMA map of vmalloc memory\n";
  _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    if ( v40 >= 0x4000 )
    {
      if ( v40 == 0x4000 || v40 == 0x10000 || v40 == 0x100000 )
        goto LABEL_115;
LABEL_114:
      printk(&unk_D4EA, "_size_to_string");
      goto LABEL_115;
    }
    if ( v40 != 4096 && v40 != 0x2000 )
    {
      if ( v40 )
        goto LABEL_114;
      v117 = v16;
      printk(&unk_D6DD, v12);
      seq_printf(v18, "TLB stress sweep:");
      v16 = *(_QWORD *)(v18 + 128);
      mutex_lock(v16 + 56);
      if ( !iommu_debug_usecase_reset(v16) )
      {
        mutex_unlock(v16 + 56);
        seq_printf(v18, "%s\n", "FAIL");
        v80 = "  -> FAILED\n";
        v13 = -22;
        v81 = &unk_D054;
        goto LABEL_289;
      }
      v20 = *(const char **)(v16 + 32);
      v124 = 0;
      free_pages_noprof = get_free_pages_noprof(3264, 1);
      v82 = 0;
      LODWORD(v18) = 0;
      v83 = 0;
      v21 = 4294959103LL;
      v19 = (const char *)(((unsigned __int64)((free_pages_noprof << 8 >> 8) + 0x8000000000LL) >> 12 << 6)
                         - 0x140000000LL);
      do
      {
        if ( v83 == 0x8000000 )
        {
          v83 = 135258112;
        }
        else
        {
          v85 = is_vmalloc_addr(free_pages_noprof);
          if ( (v85 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
          {
            v122 = v85;
            dma_map_single_attrs___already_done = 1;
            v87 = (const char *)dev_driver_string(v20);
            v88 = *((const char **)v20 + 14);
            if ( !v88 )
              v88 = *(const char **)v20;
            _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v87, v88);
            __break(0x800u);
            if ( (v122 & 1) != 0 )
            {
LABEL_242:
              v124 = -1;
LABEL_243:
              v89 = &_tlb_stress_sweep__rs;
LABEL_253:
              if ( (unsigned int)__ratelimit(v89, "__tlb_stress_sweep") )
                dev_err(v20, "Failed map on iter %d\n", v82);
              v12 = v120;
              goto LABEL_256;
            }
          }
          else if ( (v85 & 1) != 0 )
          {
            goto LABEL_242;
          }
          v86 = dma_map_page_attrs(v20, v19, free_pages_noprof & 0xFFF, 0x2000, 1, 0);
          v124 = v86;
          if ( v86 == -1 )
            goto LABEL_243;
          if ( v86 != v83 )
          {
            dma_unmap_page_attrs(v20, v86, 0x2000, 1, 0);
            v89 = &_tlb_stress_sweep__rs_121;
            goto LABEL_253;
          }
          LODWORD(v18) = v18 + 1;
        }
        v84 = v83 >= 0xFFFFDFFF;
        v83 += 0x2000LL;
        ++v82;
      }
      while ( !v84 );
      v31 = is_vmalloc_addr(free_pages_noprof);
      if ( (v31 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
        goto LABEL_260;
      v12 = v120;
      if ( (v31 & 1) == 0 )
        goto LABEL_247;
LABEL_248:
      dma_unmap_page_attrs(v20, 0, 4096, 1, 0);
      dma_unmap_page_attrs(v20, 0x2000, 4096, 1, 0);
      dma_unmap_page_attrs(v20, 12288, 4096, 1, 0);
      v90 = is_vmalloc_addr(free_pages_noprof);
      if ( (v90 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v97 = v90;
        dma_map_single_attrs___already_done = 1;
        v98 = (const char *)dev_driver_string(v20);
        v99 = *((const char **)v20 + 14);
        if ( !v99 )
          v99 = *(const char **)v20;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v98, v99);
        __break(0x800u);
        v12 = v120;
        if ( (v97 & 1) != 0 )
          goto LABEL_251;
      }
      else if ( (v90 & 1) != 0 )
      {
LABEL_251:
        v124 = -1;
LABEL_272:
        v123 = 0x2000;
        if ( (unsigned int)__ratelimit(&_tlb_stress_sweep__rs_124, "__tlb_stress_sweep") )
          dev_err(v20, "Unexpected dma_addr. got: %pa expected: %pa\n", &v124, &v123);
        dma_unmap_page_attrs(v20, 4096, 4096, 1, 0);
        dma_unmap_page_attrs(v20, 12288, 4096, 1, 0);
        v92 = 0;
        LODWORD(v18) = v18 - 2;
        v93 = "FAIL";
        v91 = 0x4000;
        goto LABEL_275;
      }
      v124 = dma_map_page_attrs(v20, v19, free_pages_noprof & 0xFFF, 0x2000, 1, 0);
      if ( v124 != 0x2000 )
        goto LABEL_272;
      v100 = is_vmalloc_addr(free_pages_noprof);
      if ( (v100 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v108 = v100;
        dma_map_single_attrs___already_done = 1;
        v109 = (const char *)dev_driver_string(v20);
        v110 = *((const char **)v20 + 14);
        if ( !v110 )
          v110 = *(const char **)v20;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v109, v110);
        __break(0x800u);
        v12 = v120;
        if ( (v108 & 1) != 0 )
          goto LABEL_271;
      }
      else if ( (v100 & 1) != 0 )
      {
LABEL_271:
        v124 = -1;
LABEL_306:
        v123 = 0;
        if ( (unsigned int)__ratelimit(&_tlb_stress_sweep__rs_126, "__tlb_stress_sweep") )
          dev_err(v20, "Unexpected dma_addr. got: %pa expected: %pa\n", &v124, &v123);
        dma_unmap_page_attrs(v20, 4096, 4096, 1, 0);
        v92 = 0;
        LODWORD(v18) = v18 - 1;
        v93 = "FAIL";
        v91 = 0x2000;
        goto LABEL_275;
      }
      v124 = dma_map_page_attrs(v20, v19, free_pages_noprof & 0xFFF, 4096, 1, 0);
      if ( v124 )
        goto LABEL_306;
      v111 = is_vmalloc_addr(free_pages_noprof);
      if ( (v111 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v112 = v111;
        dma_map_single_attrs___already_done = 1;
        v113 = (const char *)dev_driver_string(v20);
        v114 = *((const char **)v20 + 14);
        if ( !v114 )
          v114 = *(const char **)v20;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v113, v114);
        __break(0x800u);
        v12 = v120;
        if ( (v112 & 1) != 0 )
          goto LABEL_305;
      }
      else if ( (v111 & 1) != 0 )
      {
LABEL_305:
        v91 = 0;
        v92 = 1;
LABEL_314:
        v93 = "SUCCESS";
        goto LABEL_275;
      }
      v92 = 1;
      if ( dma_map_page_attrs(v20, v19, free_pages_noprof & 0xFFF, 4096, 1, 0) != -1 )
      {
        if ( (unsigned int)__ratelimit(&_tlb_stress_sweep__rs_127, "__tlb_stress_sweep") )
          dev_err(v20, "dma_map_single unexpectedly after remaps (VA should have been exhausted)\n");
        goto LABEL_256;
      }
      v91 = 0;
      goto LABEL_314;
    }
LABEL_115:
    printk(&unk_D26A, v12);
    v41 = *v39;
    if ( *v39 >= 0x200000 )
    {
      if ( v41 <= 20971519 )
      {
        if ( v41 == 0x200000 )
        {
          v42 = (const char *)&unk_D4E7;
        }
        else
        {
          if ( v41 != 12582912 )
            goto LABEL_137;
          v42 = "12M";
        }
      }
      else
      {
        switch ( v41 )
        {
          case 0x1400000LL:
            v42 = (const char *)&unk_D811;
            break;
          case 0x1800000LL:
            v42 = (const char *)&unk_CCCB;
            break;
          case 0x2000000LL:
            v42 = "32M";
            break;
          default:
            goto LABEL_137;
        }
      }
    }
    else if ( v41 < 0x4000 )
    {
      v42 = "4K";
      if ( v41 != 4096 )
      {
        if ( v41 != 0x2000 )
          goto LABEL_137;
        v42 = "8K";
      }
    }
    else
    {
      switch ( v41 )
      {
        case 0x4000LL:
          v42 = "16K";
          break;
        case 0x10000LL:
          v42 = (const char *)&unk_D68A;
          break;
        case 0x100000LL:
          v42 = (const char *)&unk_D80E;
          break;
        default:
LABEL_137:
          printk(&unk_D4EA, "_size_to_string");
          v42 = "unknown size";
          break;
      }
    }
    seq_printf(v18, "Rand VA sweep @%s:", v42);
    v119 = v39;
    v43 = *v39;
    v44 = *(_QWORD *)(v18 + 128);
    mutex_lock(v44 + 56);
    if ( !iommu_debug_usecase_reset(v44) )
    {
LABEL_139:
      mutex_unlock(v44 + 56);
      v12 = v120;
      v16 = 4294967274LL;
      v45 = "FAIL";
      v46 = &unk_D054;
      v19 = "  -> FAILED\n";
      goto LABEL_220;
    }
    v47 = *(const char ***)(v44 + 32);
    v48 = 64 - __clz((unsigned __int64)(v43 - 1) >> 12);
    if ( (unsigned __int64)(v43 - 1) >= 0x1000 )
      v49 = v48;
    else
      v49 = 0;
    v50 = get_free_pages_noprof(3264, v49);
    if ( !v50 )
    {
      if ( (unsigned __int64)v43 <= 0x2000 )
        goto LABEL_139;
      if ( (unsigned int)__ratelimit(&_rand_va_sweep__rs, "__rand_va_sweep") )
      {
        if ( v43 >= 0x200000 )
        {
          if ( v43 <= 20971519 )
          {
            if ( v43 == 0x200000 )
            {
              v51 = (const char *)&unk_D4E7;
            }
            else
            {
              if ( v43 != 12582912 )
                goto LABEL_166;
              v51 = "12M";
            }
          }
          else
          {
            switch ( v43 )
            {
              case 0x1400000LL:
                v51 = (const char *)&unk_D811;
                break;
              case 0x1800000LL:
                v51 = (const char *)&unk_CCCB;
                break;
              case 0x2000000LL:
                v51 = "32M";
                break;
              default:
                goto LABEL_166;
            }
          }
        }
        else
        {
          if ( v43 < 0x4000 )
            goto LABEL_166;
          switch ( v43 )
          {
            case 0x4000LL:
              v51 = "16K";
              break;
            case 0x10000LL:
              v51 = (const char *)&unk_D68A;
              break;
            case 0x100000LL:
              v51 = (const char *)&unk_D80E;
              break;
            default:
LABEL_166:
              printk(&unk_D4EA, "_size_to_string");
              v51 = "unknown size";
              break;
          }
        }
        dev_err(v47, "Failed to allocate %s of memory, which is a lot. Skipping test for this size\n", v51);
      }
      mutex_unlock(v44 + 56);
      v12 = v120;
LABEL_217:
      v45 = "SUCCESS";
      v46 = &unk_CFA4;
      v19 = "  -> SUCCEEDED\n";
      goto LABEL_219;
    }
    v121 = v47;
    v52 = 0;
    v53 = 0;
    v117 = v16;
    v54 = 0;
    while ( 2 )
    {
      if ( v54 == 0x8000000 )
      {
        v54 = 135266304 - v43;
      }
      else
      {
        v55 = is_vmalloc_addr(v50);
        v56 = v55;
        if ( (v55 & 1) == 0 || (dma_map_single_attrs___already_done & 1) != 0 )
        {
          if ( (v55 & 1) == 0 )
            goto LABEL_176;
LABEL_182:
          if ( (unsigned int)__ratelimit(&_rand_va_sweep__rs_113, "__rand_va_sweep") )
            dev_err(v121, "Failed map on iter %d\n", v52);
LABEL_206:
          v73 = 0;
LABEL_207:
          free_pages_noprof = (__int64)"FAIL";
          goto LABEL_208;
        }
        dma_map_single_attrs___already_done = 1;
        v58 = (const char *)dev_driver_string(v121);
        v59 = v121[14];
        if ( !v59 )
          v59 = *v121;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v58, v59);
        __break(0x800u);
        if ( (v56 & 1) != 0 )
          goto LABEL_182;
LABEL_176:
        v57 = dma_map_page_attrs(
                v121,
                ((unsigned __int64)((v50 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v50 & 0xFFF,
                v43,
                1,
                0);
        if ( v57 == -1 )
          goto LABEL_182;
        if ( v57 != v54 )
        {
          v74 = v57;
          dma_unmap_page_attrs(v121, v57, v43, 1, 0);
          if ( (unsigned int)__ratelimit(&_rand_va_sweep__rs_115, "__rand_va_sweep") )
            dev_err(v121, "Unexpected dma_addr. got: %lx, expected: %lx\n", v74, v54);
          goto LABEL_206;
        }
        ++v53;
      }
      v54 += v43;
      ++v52;
      if ( v54 < 0xFFFFFFFF )
        continue;
      break;
    }
    v60 = 2 * v43;
    if ( 2 * v43 >= (unsigned __int64)(0xFFFFFFFFLL - v43) )
    {
      v61 = 0;
    }
    else
    {
      v61 = 0;
      v62 = 1;
      v63 = 2;
      do
      {
        v65 = v60 + v43;
        v66 = 0x100000000LL - (v60 + v43);
        if ( v60 == v66 )
        {
          _warn_printk(
            "%s test needs update! The random number sequence is folding in on itself and should be changed.\n",
            "__rand_va_sweep");
          __break(0x800u);
          v18 = v118;
          free_pages_noprof = (__int64)"FAIL";
          v21 = (unsigned __int64)"ecting DMA map of vmalloc memory\n";
          v20 = (const char *)&unk_D26A;
          goto LABEL_139;
        }
        if ( v60 >> 20 != 128 )
          dma_unmap_page_attrs(v121, v60, v43, 1, 0);
        if ( v65 - 4159700993u >= 0x100000 )
          dma_unmap_page_attrs(v121, v66, v43, 1, 0);
        v64 = v63 + v62;
        v62 = v63;
        v61 += 2;
        v60 = v64 * v43;
        v63 = v64;
      }
      while ( v60 < 0xFFFFFFFFLL - v43 );
    }
    v18 = v118;
    v67 = 0;
    while ( 2 )
    {
      v68 = is_vmalloc_addr(v50);
      if ( (v68 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v69 = v68;
        dma_map_single_attrs___already_done = 1;
        v70 = (const char *)dev_driver_string(v121);
        v71 = v121[14];
        if ( !v71 )
          v71 = *v121;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v70, v71);
        __break(0x800u);
        v72 = v69;
        v18 = v118;
        if ( (v72 & 1) == 0 )
          goto LABEL_197;
      }
      else if ( (v68 & 1) == 0 )
      {
LABEL_197:
        if ( dma_map_page_attrs(
               v121,
               ((unsigned __int64)((v50 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
               v50 & 0xFFF,
               v43,
               1,
               0) != -1 )
        {
          ++v67;
          continue;
        }
      }
      break;
    }
    if ( v61 == v67 )
    {
      v73 = 1;
      goto LABEL_207;
    }
    free_pages_noprof = (__int64)"FAIL";
    if ( (unsigned int)__ratelimit(&_rand_va_sweep__rs_118, "__rand_va_sweep") )
      dev_err(v121, "Unexpected random remap count! Unmapped %d but remapped %d\n", v61, v67);
    v73 = 0;
LABEL_208:
    v75 = v53 + 1;
    v76 = 0;
    do
    {
      if ( !--v75 )
        break;
      v77 = 135266304 - v43;
      if ( v76 != 0x8000000 )
      {
        dma_unmap_page_attrs(v121, v76, v43, 1, 0);
        v77 = v76;
      }
      v76 = v77 + v43;
    }
    while ( (unsigned __int64)(v77 + v43) < 0xFFFFFFFF );
    v78 = 64 - __clz((unsigned __int64)(v43 - 1) >> 12);
    if ( (unsigned __int64)(v43 - 1) >= 0x1000 )
      v79 = v78;
    else
      v79 = 0;
    free_pages(v50, v79);
    mutex_unlock(v44 + 56);
    v12 = v120;
    v16 = v117;
    v21 = (unsigned __int64)"ecting DMA map of vmalloc memory\n";
    if ( (v73 & 1) != 0 )
      goto LABEL_217;
    v16 = 4294967274LL;
    v45 = "FAIL";
    v46 = &unk_D054;
    v19 = "  -> FAILED\n";
LABEL_219:
    v20 = (const char *)&unk_D26A;
LABEL_220:
    seq_printf(v18, "%s\n", v45);
    printk(v46, v12);
    v31 = seq_printf(v18, v19);
    if ( (unsigned __int64)(v38 - 32) >= 0xFFFFFFFFFFFFFFD8LL )
    {
      v38 += 8;
      v39 = v119 + 1;
      v40 = v119[1];
      if ( v40 < 0x200000 )
        continue;
      if ( v40 <= 20971519 )
      {
        if ( v40 == 0x200000 || v40 == 12582912 )
          goto LABEL_115;
      }
      else if ( v40 == 20971520 || v40 == 25165824 || v40 == 0x2000000 )
      {
        goto LABEL_115;
      }
      goto LABEL_114;
    }
    break;
  }
LABEL_259:
  __break(1u);
LABEL_260:
  v94 = v31;
  dma_map_single_attrs___already_done = 1;
  v95 = (const char *)dev_driver_string(v20);
  v96 = *((const char **)v20 + 14);
  if ( !v96 )
    v96 = *(const char **)v20;
  _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v95, v96);
  __break(0x800u);
  v12 = v120;
  if ( (v94 & 1) != 0 )
    goto LABEL_248;
LABEL_247:
  if ( dma_map_page_attrs(v20, v19, free_pages_noprof & 0xFFF, 4096, 1, 0) == -1 )
    goto LABEL_248;
  if ( (unsigned int)__ratelimit(&_tlb_stress_sweep__rs_122, "__tlb_stress_sweep") )
    dev_err(v20, "dma_map_single unexpectedly (VA should have been exhausted)\n");
LABEL_256:
  v91 = 0;
  v92 = 0;
  v93 = "FAIL";
LABEL_275:
  v101 = v18 + 1;
  do
  {
    if ( !--v101 )
      break;
    v102 = 135258112;
    if ( v91 != 0x8000000 )
    {
      dma_unmap_page_attrs(v20, v91, 0x2000, 1, 0);
      v102 = v91;
    }
    v91 = v102 + 0x2000;
  }
  while ( v102 < v21 );
  free_pages(free_pages_noprof, 1);
  mutex_unlock(v16 + 56);
  v18 = v118;
  seq_printf(v118, "%s\n", v93);
  if ( v92 )
    v80 = "  -> SUCCEEDED\n";
  else
    v80 = "  -> FAILED\n";
  if ( v92 )
    v81 = &unk_CFA4;
  else
    v81 = &unk_D054;
  if ( v92 )
    v13 = v117;
  else
    v13 = -22;
LABEL_289:
  printk(v81, v12);
  seq_printf(v18, v80);
  printk(&unk_D4CF, v12);
  seq_printf(v18, "second bonus map:");
  v103 = *(_QWORD *)(v18 + 128);
  mutex_lock(v103 + 56);
  v4 = v115;
  if ( !iommu_debug_usecase_reset(v103) )
  {
    mutex_unlock(v103 + 56);
    seq_printf(v18, "%s\n", "FAIL");
    goto LABEL_296;
  }
  v104 = _full_va_sweep(*(_QWORD *)(v103 + 32), *(_QWORD *)(v103 + 40), 4096);
  mutex_unlock(v103 + 56);
  if ( v104 )
    v105 = "FAIL";
  else
    v105 = "SUCCESS";
  seq_printf(v18, "%s\n", v105);
  if ( v104 )
  {
LABEL_296:
    v106 = "  -> FAILED\n";
    v13 = -22;
    v107 = &unk_D054;
  }
  else
  {
    v106 = "  -> SUCCEEDED\n";
    v107 = &unk_CFA4;
  }
  printk(v107, v12);
  seq_printf(v18, v106);
  kfree(v12);
LABEL_19:
  result = v116 | v4 | (unsigned int)v13;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
