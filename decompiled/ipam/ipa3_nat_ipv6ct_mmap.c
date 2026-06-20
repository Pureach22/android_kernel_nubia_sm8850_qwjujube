__int64 __fastcall ipa3_nat_ipv6ct_mmap(
        __int64 a1,
        __int64 *a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        float a7)
{
  __int64 v7; // x21
  __int64 v8; // x24
  __int64 v10; // x19
  char *smmu_ctx; // x22
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x21
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w26
  __int64 v21; // x8
  __int64 v22; // x22
  unsigned __int64 v23; // x9
  __int64 *v24; // x24
  _QWORD *v25; // x25
  __int64 v26; // x9
  __int64 v27; // x0
  const char *v28; // x8
  const char *v29; // x4
  __int64 v30; // x0
  const char *v31; // x8
  const char *v32; // x4
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  unsigned int v36; // w0
  unsigned int v37; // w21
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  _QWORD *v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  unsigned int v46; // w0
  __int64 v47; // x8
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  unsigned int v65; // w0
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x8
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 v80; // x0

  v8 = *a2;
  v7 = a2[1];
  v10 = *(_QWORD *)(a1 + 32);
  smmu_ctx = ipa3_get_smmu_ctx(0, a3, a4, a5, a6, a7);
  v12 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d In\n", "ipa3_nat_ipv6ct_mmap", 141);
      v12 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v12 + 34160);
    if ( v14 )
      ipc_log_string(v14, "ipa %s:%d In\n", "ipa3_nat_ipv6ct_mmap", 141);
  }
  if ( (*(_BYTE *)(v10 + 222) & 1) != 0 )
  {
    v15 = v7 - v8;
    mutex_lock(v10 + 16);
    if ( smmu_ctx )
    {
      v16 = *((_QWORD *)smmu_ctx + 1);
      if ( v16 )
      {
        if ( *smmu_ctx != 1 || (*(_BYTE *)(v16 + 844) & 0x20) == 0 )
        {
          v17 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v18 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v18 )
            {
              ipc_log_string(
                v18,
                "ipa %s:%d Either smmu valid=%u and/or DMA coherent=%u false\n",
                "ipa3_nat_ipv6ct_mmap",
                158);
              v17 = ipa3_ctx;
            }
            v19 = *(_QWORD *)(v17 + 34160);
            if ( v19 )
              ipc_log_string(
                v19,
                "ipa %s:%d Either smmu valid=%u and/or DMA coherent=%u false\n",
                "ipa3_nat_ipv6ct_mmap",
                158,
                (unsigned __int8)*smmu_ctx,
                (*(_BYTE *)(*((_QWORD *)smmu_ctx + 1) + 844LL) & 0x20) == 0);
          }
          a2[3] = a2[3] & 0xFF9FFFFFFFFFFFE3LL | 0x6000000000000CLL;
        }
      }
    }
    if ( *(_BYTE *)(v10 + 220) != 1 )
    {
      v24 = (__int64 *)(v10 + 248);
      if ( *(_QWORD *)(v10 + 248) )
      {
        v22 = v10 + 224;
        if ( *(_BYTE *)(v10 + 224) != 1 )
        {
          v41 = (_QWORD *)ipa3_ctx;
          *(_QWORD *)(v10 + 264) = 0;
          if ( v41 )
          {
            v42 = v41[4269];
            if ( v42 )
            {
              ipc_log_string(v42, "ipa %s:%d Mapping V6 CT: %s\n", "ipa3_nat_ipv6ct_mmap", 272, "IPA_NAT_MEM_IN_DDR");
              v41 = (_QWORD *)ipa3_ctx;
            }
            v43 = v41[4270];
            if ( v43 )
            {
              ipc_log_string(v43, "ipa %s:%d Mapping V6 CT: %s\n", "ipa3_nat_ipv6ct_mmap", 272, "IPA_NAT_MEM_IN_DDR");
              v41 = (_QWORD *)ipa3_ctx;
            }
            if ( v41 )
            {
              v44 = v41[4269];
              if ( v44 )
              {
                ipc_log_string(
                  v44,
                  "ipa %s:%d map sz=0x%zx -> vma size=0x%08lx\n",
                  "ipa3_nat_ipv6ct_mmap",
                  276,
                  *(_QWORD *)(v10 + 240),
                  v15);
                v41 = (_QWORD *)ipa3_ctx;
              }
              v45 = v41[4270];
              if ( v45 )
              {
                ipc_log_string(
                  v45,
                  "ipa %s:%d map sz=0x%zx -> vma size=0x%08lx\n",
                  "ipa3_nat_ipv6ct_mmap",
                  276,
                  *(_QWORD *)(v10 + 240),
                  v15);
                v41 = (_QWORD *)ipa3_ctx;
              }
            }
          }
          v46 = dma_mmap_attrs(v41[4277], a2, *(_QWORD *)(v10 + 248), *(_QWORD *)(v10 + 256), *(_QWORD *)(v10 + 240), 0);
          if ( !v46 )
          {
            v25 = (_QWORD *)(v10 + 264);
            goto LABEL_67;
          }
          v37 = v46;
          printk(&unk_3D89B3, "ipa3_nat_ipv6ct_mmap");
          v75 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v76 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v76 )
            {
              ipc_log_string(v76, "ipa %s:%d dma_mmap_coherent failed. Err:%d\n", "ipa3_nat_ipv6ct_mmap", 287, v37);
              v75 = ipa3_ctx;
            }
            v77 = *(_QWORD *)(v75 + 34160);
            if ( v77 )
              ipc_log_string(v77, "ipa %s:%d dma_mmap_coherent failed. Err:%d\n", "ipa3_nat_ipv6ct_mmap", 287, v37);
          }
LABEL_87:
          mutex_unlock(v10 + 16);
          v57 = ipa3_ctx;
          if ( !ipa3_ctx )
            return v37;
          goto LABEL_88;
        }
        printk(&unk_3E9B99, "ipa3_nat_ipv6ct_mmap");
        v72 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_142;
        v73 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v73 )
        {
          ipc_log_string(
            v73,
            "ipa %s:%d %s already mapped, only 1 mapping supported\n",
            "ipa3_nat_ipv6ct_mmap",
            264,
            (const char *)v10);
          v72 = ipa3_ctx;
        }
        v74 = *(_QWORD *)(v72 + 34160);
        if ( !v74 )
          goto LABEL_142;
        ipc_log_string(v74, "ipa %s:%d %s already mapped, only 1 mapping supported\n", "ipa3_nat_ipv6ct_mmap", 264, v10);
        goto LABEL_138;
      }
      if ( (unsigned int)__ratelimit(&ipa3_nat_ipv6ct_mmap__rs_158, "ipa3_nat_ipv6ct_mmap") )
      {
        printk(&unk_3D2F0B, "ipa3_nat_ipv6ct_mmap");
        v51 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_86;
      }
      else
      {
        v51 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_86;
      }
      v52 = *(_QWORD *)(v51 + 34152);
      if ( v52 )
      {
        ipc_log_string(
          v52,
          "ipa %s:%d Attempt to mmap %s before the memory allocation\n",
          "ipa3_nat_ipv6ct_mmap",
          257,
          (const char *)v10);
        v51 = ipa3_ctx;
      }
      v53 = *(_QWORD *)(v51 + 34160);
      if ( v53 )
        ipc_log_string(
          v53,
          "ipa %s:%d Attempt to mmap %s before the memory allocation\n",
          "ipa3_nat_ipv6ct_mmap",
          257,
          v10);
      goto LABEL_86;
    }
    v20 = *(_DWORD *)(v10 + 340);
    if ( v20 < 2 )
    {
      v21 = v10 + 96LL * v20;
      if ( *(_QWORD *)(v21 + 376) )
      {
        v22 = v21 + 360;
        if ( *(_BYTE *)(v21 + 360) != 1 )
        {
          if ( v20 != 1 || (v23 = *(unsigned int *)(v10 + 228), (_DWORD)v23) && v15 >= v23 )
          {
            v24 = (__int64 *)(v21 + 376);
            *(_QWORD *)(v21 + 416) = 0;
            v25 = (_QWORD *)(v21 + 416);
            v26 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v27 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v27 )
              {
                if ( v20 == 1 )
                  v28 = "IPA_NAT_MEM_IN_SRAM";
                else
                  v28 = "INVALID_MEM_TYPE";
                if ( v20 )
                  v29 = v28;
                else
                  v29 = "IPA_NAT_MEM_IN_DDR";
                ipc_log_string(v27, "ipa %s:%d Mapping V4 NAT: %s\n", "ipa3_nat_ipv6ct_mmap", 206, v29);
                v26 = ipa3_ctx;
              }
              v30 = *(_QWORD *)(v26 + 34160);
              if ( v30 )
              {
                if ( v20 == 1 )
                  v31 = "IPA_NAT_MEM_IN_SRAM";
                else
                  v31 = "INVALID_MEM_TYPE";
                if ( v20 )
                  v32 = v31;
                else
                  v32 = "IPA_NAT_MEM_IN_DDR";
                ipc_log_string(v30, "ipa %s:%d Mapping V4 NAT: %s\n", "ipa3_nat_ipv6ct_mmap", 206, v32);
              }
            }
            v33 = ipa3_ctx;
            if ( v20 )
            {
              if ( ipa3_ctx )
              {
                v34 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v34 )
                {
                  ipc_log_string(
                    v34,
                    "ipa %s:%d map phys_mem_size(0x%08X) -> vma sz(0x%08lX)\n",
                    "ipa3_nat_ipv6ct_mmap",
                    234,
                    *(_DWORD *)(v10 + 228),
                    v15);
                  v33 = ipa3_ctx;
                }
                v35 = *(_QWORD *)(v33 + 34160);
                if ( v35 )
                  ipc_log_string(
                    v35,
                    "ipa %s:%d map phys_mem_size(0x%08X) -> vma sz(0x%08lX)\n",
                    "ipa3_nat_ipv6ct_mmap",
                    234,
                    *(_DWORD *)(v10 + 228),
                    v15);
              }
              a2[3] = a2[3] & 0xFF9FFFFFFFFFFFE3LL | 0x6000000000000CLL;
              v36 = vm_iomap_memory(a2, *(_QWORD *)(v22 + 32), *(unsigned int *)(v10 + 228));
              if ( v36 )
              {
                v37 = v36;
                printk(&unk_3B27E3, "ipa3_nat_ipv6ct_mmap");
                v38 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v39 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v39 )
                  {
                    ipc_log_string(v39, "ipa %s:%d vm_iomap_memory failed. Err:%d\n", "ipa3_nat_ipv6ct_mmap", 243, v37);
                    v38 = ipa3_ctx;
                  }
                  v40 = *(_QWORD *)(v38 + 34160);
                  if ( v40 )
                    ipc_log_string(v40, "ipa %s:%d vm_iomap_memory failed. Err:%d\n", "ipa3_nat_ipv6ct_mmap", 243, v37);
                }
                goto LABEL_87;
              }
LABEL_67:
              v47 = *v24;
              v37 = 0;
              *(_BYTE *)v22 = 1;
              *v25 = v47;
              a2[9] = (__int64)&ipa3_nat_ipv6ct_remap_vm_ops;
              goto LABEL_87;
            }
            if ( ipa3_ctx )
            {
              v63 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v63 )
              {
                ipc_log_string(
                  v63,
                  "ipa %s:%d map sz=0x%zx -> vma size=0x%08lx\n",
                  "ipa3_nat_ipv6ct_mmap",
                  212,
                  *(_QWORD *)(v22 + 40),
                  v15);
                v33 = ipa3_ctx;
              }
              v64 = *(_QWORD *)(v33 + 34160);
              if ( v64 )
              {
                ipc_log_string(
                  v64,
                  "ipa %s:%d map sz=0x%zx -> vma size=0x%08lx\n",
                  "ipa3_nat_ipv6ct_mmap",
                  212,
                  *(_QWORD *)(v22 + 40),
                  v15);
                v33 = ipa3_ctx;
              }
            }
            v65 = dma_mmap_attrs(
                    *(_QWORD *)(v33 + 34216),
                    a2,
                    *(_QWORD *)(v22 + 16),
                    *(_QWORD *)(v22 + 24),
                    *(_QWORD *)(v22 + 40),
                    0);
            if ( !v65 )
              goto LABEL_67;
            v37 = v65;
            printk(&unk_3D89B3, "ipa3_nat_ipv6ct_mmap");
            v66 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v67 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v67 )
              {
                ipc_log_string(v67, "ipa %s:%d dma_mmap_coherent failed. Err:%d\n", "ipa3_nat_ipv6ct_mmap", 225, v37);
                v66 = ipa3_ctx;
              }
              v68 = *(_QWORD *)(v66 + 34160);
              if ( v68 )
                ipc_log_string(v68, "ipa %s:%d dma_mmap_coherent failed. Err:%d\n", "ipa3_nat_ipv6ct_mmap", 225, v37);
            }
            goto LABEL_87;
          }
          if ( (unsigned int)__ratelimit(&ipa3_nat_ipv6ct_mmap__rs_148, "ipa3_nat_ipv6ct_mmap") )
          {
            printk(&unk_3E3DCF, "ipa3_nat_ipv6ct_mmap");
            v69 = ipa3_ctx;
            if ( ipa3_ctx )
            {
LABEL_112:
              v70 = *(_QWORD *)(v69 + 34152);
              if ( v70 )
              {
                ipc_log_string(
                  v70,
                  "ipa %s:%d %s err vsize(0x%lX) phys_mem_size(0x%X)\n",
                  "ipa3_nat_ipv6ct_mmap",
                  197,
                  (const char *)v10,
                  v15,
                  *(_DWORD *)(v10 + 228));
                v69 = ipa3_ctx;
              }
              v71 = *(_QWORD *)(v69 + 34160);
              if ( v71 )
              {
                ipc_log_string(
                  v71,
                  "ipa %s:%d %s err vsize(0x%lX) phys_mem_size(0x%X)\n",
                  "ipa3_nat_ipv6ct_mmap",
                  197,
                  (const char *)v10,
                  v15,
                  *(_DWORD *)(v10 + 228));
                v37 = -22;
                goto LABEL_87;
              }
            }
          }
          else
          {
            v69 = ipa3_ctx;
            if ( ipa3_ctx )
              goto LABEL_112;
          }
LABEL_142:
          v37 = -22;
          goto LABEL_87;
        }
        printk(&unk_3E9B99, "ipa3_nat_ipv6ct_mmap");
        v78 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_142;
        v79 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v79 )
        {
          ipc_log_string(
            v79,
            "ipa %s:%d %s already mapped, only 1 mapping supported\n",
            "ipa3_nat_ipv6ct_mmap",
            187,
            (const char *)v10);
          v78 = ipa3_ctx;
        }
        v80 = *(_QWORD *)(v78 + 34160);
        if ( !v80 )
          goto LABEL_142;
        ipc_log_string(v80, "ipa %s:%d %s already mapped, only 1 mapping supported\n", "ipa3_nat_ipv6ct_mmap", 187, v10);
LABEL_138:
        v37 = -22;
        goto LABEL_87;
      }
      if ( (unsigned int)__ratelimit(&ipa3_nat_ipv6ct_mmap__rs_143, "ipa3_nat_ipv6ct_mmap") )
      {
        printk(&unk_3D2F0B, "ipa3_nat_ipv6ct_mmap");
        v54 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_82;
      }
      else
      {
        v54 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_82:
          v55 = *(_QWORD *)(v54 + 34152);
          if ( v55 )
          {
            ipc_log_string(
              v55,
              "ipa %s:%d Attempt to mmap %s before the memory allocation\n",
              "ipa3_nat_ipv6ct_mmap",
              180,
              (const char *)v10);
            v54 = ipa3_ctx;
          }
          v56 = *(_QWORD *)(v54 + 34160);
          if ( v56 )
            ipc_log_string(
              v56,
              "ipa %s:%d Attempt to mmap %s before the memory allocation\n",
              "ipa3_nat_ipv6ct_mmap",
              180,
              v10);
        }
      }
LABEL_86:
      v37 = -1;
      goto LABEL_87;
    }
    if ( (unsigned int)__ratelimit(&ipa3_nat_ipv6ct_mmap__rs, "ipa3_nat_ipv6ct_mmap") )
    {
      printk(&unk_3A3A99, "ipa3_nat_ipv6ct_mmap");
      v48 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_86;
    }
    else
    {
      v48 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_86;
    }
    v49 = *(_QWORD *)(v48 + 34152);
    if ( v49 )
    {
      ipc_log_string(v49, "ipa %s:%d Bad ipa3_nat_mem_in type\n", "ipa3_nat_ipv6ct_mmap", 170);
      v48 = ipa3_ctx;
    }
    v50 = *(_QWORD *)(v48 + 34160);
    if ( v50 )
      ipc_log_string(v50, "ipa %s:%d Bad ipa3_nat_mem_in type\n", "ipa3_nat_ipv6ct_mmap", 170);
    goto LABEL_86;
  }
  printk(&unk_3C1120, "ipa3_nat_ipv6ct_mmap");
  v57 = ipa3_ctx;
  if ( !ipa3_ctx )
    return (unsigned int)-1;
  v61 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v61 )
  {
    ipc_log_string(
      v61,
      "ipa %s:%d Attempt to mmap %s before dev init\n",
      "ipa3_nat_ipv6ct_mmap",
      145,
      (const char *)v10);
    v57 = ipa3_ctx;
  }
  v62 = *(_QWORD *)(v57 + 34160);
  if ( v62 )
  {
    ipc_log_string(
      v62,
      "ipa %s:%d Attempt to mmap %s before dev init\n",
      "ipa3_nat_ipv6ct_mmap",
      145,
      (const char *)v10);
    v37 = -1;
    v57 = ipa3_ctx;
    if ( !ipa3_ctx )
      return v37;
  }
  else
  {
    v37 = -1;
    if ( !v57 )
      return v37;
  }
LABEL_88:
  v58 = *(_QWORD *)(v57 + 34152);
  if ( v58 )
  {
    ipc_log_string(v58, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_mmap", 302);
    v57 = ipa3_ctx;
  }
  v59 = *(_QWORD *)(v57 + 34160);
  if ( v59 )
    ipc_log_string(v59, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_mmap", 302);
  return v37;
}
