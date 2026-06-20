__int64 __fastcall ipa3_nat_ipv6ct_allocate_mem(__int64 a1, unsigned __int64 *a2, unsigned int a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int64 v9; // x4
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned __int64 v13; // x1
  __int64 v14; // x8
  __int64 v15; // x0
  unsigned int v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x20
  const char *v27; // x22
  const char *v28; // x0
  __int64 v29; // x20
  const char *v30; // x22
  const char *v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  int v34; // w21
  int v35; // w22
  __int64 v36; // x0
  __int64 v37; // x2
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  _QWORD v54[2]; // [xsp+0h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  v54[0] = 0;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(
        v7,
        "ipa %s:%d In: Requested alloc size %zu for %s\n",
        "ipa3_nat_ipv6ct_allocate_mem",
        556,
        *a2,
        (const char *)a1);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(
        v8,
        "ipa %s:%d In: Requested alloc size %zu for %s\n",
        "ipa3_nat_ipv6ct_allocate_mem",
        556,
        *a2,
        (const char *)a1);
  }
  if ( !*a2 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_ipv6ct_allocate_mem__rs, "ipa3_nat_ipv6ct_allocate_mem") )
    {
      printk(&unk_3EC70C, "ipa3_nat_ipv6ct_allocate_mem");
      v17 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_99;
    }
    else
    {
      v17 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_99;
    }
    v18 = *(_QWORD *)(v17 + 34152);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d Invalid Parameters\n", "ipa3_nat_ipv6ct_allocate_mem", 559);
      v17 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v17 + 34160);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d Invalid Parameters\n", "ipa3_nat_ipv6ct_allocate_mem", 559);
LABEL_31:
      v16 = -1;
      goto LABEL_39;
    }
LABEL_101:
    v16 = -1;
    goto LABEL_40;
  }
  if ( (*(_BYTE *)(a1 + 222) & 1) == 0 )
  {
    printk(&unk_3E124D, "ipa3_nat_ipv6ct_allocate_mem");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v39 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v39 )
      {
        ipc_log_string(
          v39,
          "ipa %s:%d %s hasn't been initialized\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          565,
          (const char *)a1);
        v17 = ipa3_ctx;
      }
      v40 = *(_QWORD *)(v17 + 34160);
      if ( v40 )
      {
        ipc_log_string(
          v40,
          "ipa %s:%d %s hasn't been initialized\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          565,
          (const char *)a1);
        v16 = -1;
        goto LABEL_39;
      }
      goto LABEL_101;
    }
    goto LABEL_99;
  }
  if ( a3 && (*(_BYTE *)(a1 + 220) & 1) != 0 || a3 != 3 && (*(_BYTE *)(a1 + 221) & 1) != 0 )
  {
    ipahal_nat_type_str(a3);
    printk(&unk_3DB9BC, "ipa3_nat_ipv6ct_allocate_mem");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        if ( *(_BYTE *)(a1 + 220) )
          v27 = "V4";
        else
          v27 = "V6";
        v28 = (const char *)ipahal_nat_type_str(a3);
        ipc_log_string(
          v26,
          "ipa %s:%d %s dev type(%s) and nat_type(%s) mismatch\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          575,
          (const char *)a1,
          v27,
          v28);
        v17 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v17 + 34160);
      if ( v29 )
      {
        if ( *(_BYTE *)(a1 + 220) )
          v30 = "V4";
        else
          v30 = "V6";
        v31 = (const char *)ipahal_nat_type_str(a3);
        ipc_log_string(
          v29,
          "ipa %s:%d %s dev type(%s) and nat_type(%s) mismatch\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          575,
          (const char *)a1,
          v30,
          v31);
        v16 = -1;
        goto LABEL_39;
      }
      goto LABEL_101;
    }
    goto LABEL_99;
  }
  ipahal_nat_entry_size(a3, v54);
  v9 = *a2;
  if ( *a2 > v54[0] << 13 )
  {
    printk(&unk_3A3B80, "ipa3_nat_ipv6ct_allocate_mem");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v41 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v41 )
      {
        ipc_log_string(
          v41,
          "ipa %s:%d Trying allocate more size = %zu, Max allowed = %zu\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          585,
          *a2,
          v54[0] << 13);
        v17 = ipa3_ctx;
      }
      v42 = *(_QWORD *)(v17 + 34160);
      if ( v42 )
      {
        ipc_log_string(
          v42,
          "ipa %s:%d Trying allocate more size = %zu, Max allowed = %zu\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          585,
          *a2,
          v54[0] << 13);
        v16 = -1;
        goto LABEL_39;
      }
      goto LABEL_101;
    }
    goto LABEL_99;
  }
  if ( a3 == 3 )
  {
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(
          v21,
          "ipa %s:%d V6 CT with size 0x%08lX will reside in: %s\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          677,
          v9,
          "IPA_NAT_MEM_IN_DDR");
        v20 = ipa3_ctx;
        v9 = *a2;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
      {
        ipc_log_string(
          v22,
          "ipa %s:%d V6 CT with size 0x%08lX will reside in: %s\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          677,
          v9,
          "IPA_NAT_MEM_IN_DDR");
        v9 = *a2;
        v20 = ipa3_ctx;
      }
    }
    *(_QWORD *)(a1 + 240) = v9;
    v23 = dma_alloc_attrs(*(_QWORD *)(v20 + 34216), v9, a1 + 256, 3520, 0);
    *(_QWORD *)(a1 + 248) = v23;
    if ( !v23 )
    {
      printk(&unk_3D2F48, "ipa3_nat_ipv6ct_allocate_mem");
      v17 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v43 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v43 )
        {
          ipc_log_string(v43, "ipa %s:%d memory alloc failed\n", "ipa3_nat_ipv6ct_allocate_mem", 689);
          v17 = ipa3_ctx;
        }
        v44 = *(_QWORD *)(v17 + 34160);
        if ( v44 )
        {
          ipc_log_string(v44, "ipa %s:%d memory alloc failed\n", "ipa3_nat_ipv6ct_allocate_mem", 689);
LABEL_107:
          v16 = -12;
          goto LABEL_39;
        }
        goto LABEL_109;
      }
      goto LABEL_108;
    }
LABEL_38:
    v16 = 0;
    goto LABEL_39;
  }
  if ( a3 )
    goto LABEL_38;
  v10 = ipa3_ctx;
  if ( sram_compatible != 1 || v9 > *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 184LL) )
  {
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d V4 NAT with size 0x%08lX will reside in: %s\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          644,
          v9,
          "IPA_NAT_MEM_IN_DDR");
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(
          v12,
          "ipa %s:%d V4 NAT with size 0x%08lX will reside in: %s\n",
          "ipa3_nat_ipv6ct_allocate_mem",
          644,
          *a2,
          "IPA_NAT_MEM_IN_DDR");
    }
    if ( *(_BYTE *)(a1 + 356) != 1 )
    {
      v13 = *a2;
      v14 = ipa3_ctx;
      *(_QWORD *)(a1 + 400) = *a2;
      v15 = dma_alloc_attrs(*(_QWORD *)(v14 + 34216), v13, a1 + 384, 3520, 0);
      *(_QWORD *)(a1 + 376) = v15;
      if ( v15 )
      {
        v16 = 0;
        *(_DWORD *)(a1 + 340) = 0;
        *(_BYTE *)(a1 + 356) = 1;
LABEL_39:
        v17 = ipa3_ctx;
        goto LABEL_40;
      }
      printk(&unk_3D2F48, "ipa3_nat_ipv6ct_allocate_mem");
      v17 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v47 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v47 )
        {
          ipc_log_string(v47, "ipa %s:%d memory alloc failed\n", "ipa3_nat_ipv6ct_allocate_mem", 664);
          v17 = ipa3_ctx;
        }
        v48 = *(_QWORD *)(v17 + 34160);
        if ( v48 )
        {
          ipc_log_string(v48, "ipa %s:%d memory alloc failed\n", "ipa3_nat_ipv6ct_allocate_mem", 664);
          goto LABEL_107;
        }
        goto LABEL_109;
      }
LABEL_108:
      v16 = -12;
      goto LABEL_100;
    }
    printk(&unk_3A9F3F, "ipa3_nat_ipv6ct_allocate_mem");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v45 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v45 )
      {
        ipc_log_string(v45, "ipa %s:%d Memory already allocated\n", "ipa3_nat_ipv6ct_allocate_mem", 647);
        v17 = ipa3_ctx;
      }
      v46 = *(_QWORD *)(v17 + 34160);
      if ( v46 )
      {
        ipc_log_string(v46, "ipa %s:%d Memory already allocated\n", "ipa3_nat_ipv6ct_allocate_mem", 647);
        goto LABEL_31;
      }
      goto LABEL_101;
    }
LABEL_99:
    v16 = -1;
    goto LABEL_100;
  }
  if ( ipa3_ctx )
  {
    v32 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v32 )
    {
      ipc_log_string(
        v32,
        "ipa %s:%d V4 NAT with size 0x%08lX will reside in: %s\n",
        "ipa3_nat_ipv6ct_allocate_mem",
        601,
        v9,
        "IPA_NAT_MEM_IN_SRAM");
      v10 = ipa3_ctx;
    }
    v33 = *(_QWORD *)(v10 + 34160);
    if ( v33 )
      ipc_log_string(
        v33,
        "ipa %s:%d V4 NAT with size 0x%08lX will reside in: %s\n",
        "ipa3_nat_ipv6ct_allocate_mem",
        601,
        *a2,
        "IPA_NAT_MEM_IN_SRAM");
  }
  if ( *(_BYTE *)(a1 + 357) == 1 )
  {
    printk(&unk_3A9F3F, "ipa3_nat_ipv6ct_allocate_mem");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v49 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v49 )
      {
        ipc_log_string(v49, "ipa %s:%d Memory already allocated\n", "ipa3_nat_ipv6ct_allocate_mem", 604);
        v17 = ipa3_ctx;
      }
      v50 = *(_QWORD *)(v17 + 34160);
      if ( v50 )
      {
        ipc_log_string(v50, "ipa %s:%d Memory already allocated\n", "ipa3_nat_ipv6ct_allocate_mem", 604);
        goto LABEL_31;
      }
      goto LABEL_101;
    }
    goto LABEL_99;
  }
  *(_QWORD *)(a1 + 496) = *a2;
  v34 = *(_DWORD *)(ipa3_ctx + 28640);
  v35 = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 36LL);
  v36 = v35
      + v34
      + (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(64, 0, 0)
      + *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 180LL);
  *(_QWORD *)(a1 + 488) = v36;
  if ( arm64_use_ng_mappings )
    v37 = 0x68000000000F13LL;
  else
    v37 = 0x68000000000713LL;
  v38 = ioremap_prot(v36, *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 184LL), v37);
  *(_QWORD *)(a1 + 464) = v38;
  if ( v38 )
  {
    v16 = 0;
    *(_QWORD *)(a1 + 472) = v38;
    *(_BYTE *)(a1 + 357) = 1;
    *(_DWORD *)(a1 + 340) = 1;
    goto LABEL_39;
  }
  printk(&unk_3B7FAF, "ipa3_nat_ipv6ct_allocate_mem");
  v17 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_108;
  v52 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v52 )
  {
    ipc_log_string(v52, "ipa %s:%d ioremap failed\n", "ipa3_nat_ipv6ct_allocate_mem", 625);
    v17 = ipa3_ctx;
  }
  v53 = *(_QWORD *)(v17 + 34160);
  if ( v53 )
  {
    ipc_log_string(v53, "ipa %s:%d ioremap failed\n", "ipa3_nat_ipv6ct_allocate_mem", 625);
    goto LABEL_107;
  }
LABEL_109:
  v16 = -12;
LABEL_40:
  if ( v17 )
  {
    v24 = *(_QWORD *)(v17 + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_allocate_mem", 697);
      v17 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v17 + 34160);
    if ( v25 )
      ipc_log_string(v25, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_allocate_mem", 697);
  }
LABEL_100:
  _ReadStatusReg(SP_EL0);
  return v16;
}
