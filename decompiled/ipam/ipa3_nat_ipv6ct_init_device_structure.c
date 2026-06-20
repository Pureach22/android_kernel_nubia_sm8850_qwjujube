__int64 __fastcall ipa3_nat_ipv6ct_init_device_structure(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int16 a5,
        unsigned __int16 a6,
        unsigned int a7,
        unsigned int a8,
        char a9)
{
  __int64 v11; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  const char *v19; // x8
  const char *v20; // x6
  __int64 v21; // x0
  const char *v22; // x8
  const char *v23; // x6
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  const void *v27; // x5
  __int64 v28; // x0
  __int64 v29; // x0
  const void *v30; // x5
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  const void *v41; // x5
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  const void *v45; // x5
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  const void *v54; // x4
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  const void *v58; // x4
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x20
  unsigned int v63; // w21
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v68; // x8
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // [xsp+0h] [xbp-30h]
  __int64 v72; // [xsp+8h] [xbp-28h]
  __int64 v73; // [xsp+10h] [xbp-20h]
  __int64 v74; // [xsp+18h] [xbp-18h]
  __int64 v75; // [xsp+20h] [xbp-10h]

  v11 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d In\n", "ipa3_nat_ipv6ct_init_device_structure", 1010);
      v11 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v11 + 34160);
    if ( v17 )
    {
      ipc_log_string(v17, "ipa %s:%d In\n", "ipa3_nat_ipv6ct_init_device_structure", 1010);
      v11 = ipa3_ctx;
    }
    if ( v11 )
    {
      v18 = *(_QWORD *)(v11 + 34152);
      if ( v18 )
      {
        if ( a2 == 1 )
          v19 = "IPA_NAT_MEM_IN_SRAM";
        else
          v19 = "INVALID_MEM_TYPE";
        if ( a2 )
          v20 = v19;
        else
          v20 = "IPA_NAT_MEM_IN_DDR";
        ipc_log_string(
          v18,
          "ipa %s:%d v4(%u) v6(%u) nmi(%s) bto(%u) eto(%u) t_ents(%u) et_ents(%u) io(%u) ieo(%u)\n",
          "ipa3_nat_ipv6ct_init_device_structure",
          1022,
          *(unsigned __int8 *)(a1 + 220),
          *(unsigned __int8 *)(a1 + 221),
          v20,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8);
        v11 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v11 + 34160);
      if ( v21 )
      {
        if ( a2 == 1 )
          v22 = "IPA_NAT_MEM_IN_SRAM";
        else
          v22 = "INVALID_MEM_TYPE";
        if ( a2 )
          v23 = v22;
        else
          v23 = "IPA_NAT_MEM_IN_DDR";
        LODWORD(v75) = a8;
        LODWORD(v74) = a7;
        LODWORD(v73) = a6;
        LODWORD(v72) = a5;
        LODWORD(v71) = a4;
        ipc_log_string(
          v21,
          "ipa %s:%d v4(%u) v6(%u) nmi(%s) bto(%u) eto(%u) t_ents(%u) et_ents(%u) io(%u) ieo(%u)\n",
          "ipa3_nat_ipv6ct_init_device_structure",
          1022,
          *(unsigned __int8 *)(a1 + 220),
          *(unsigned __int8 *)(a1 + 221),
          v23,
          a3,
          v71,
          v72,
          v73,
          v74,
          v75);
      }
    }
  }
  if ( *(_BYTE *)(a1 + 221) == 1 )
  {
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d v6\n", "ipa3_nat_ipv6ct_init_device_structure", 1026);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d v6\n", "ipa3_nat_ipv6ct_init_device_structure", 1026);
        v24 = ipa3_ctx;
      }
      v27 = (const void *)(*(_QWORD *)(a1 + 264) + a3);
      *(_QWORD *)(a1 + 272) = v27;
      if ( v24 )
      {
        v28 = *(_QWORD *)(v24 + 34152);
        if ( v28 )
        {
          ipc_log_string(
            v28,
            "ipa %s:%d %s base_table_addr: 0x%pK\n",
            "ipa3_nat_ipv6ct_init_device_structure",
            1032,
            (const char *)a1,
            v27);
          v24 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v24 + 34160);
        if ( v29 )
        {
          ipc_log_string(
            v29,
            "ipa %s:%d %s base_table_addr: 0x%pK\n",
            "ipa3_nat_ipv6ct_init_device_structure",
            1032,
            (const char *)a1,
            *(const void **)(a1 + 272));
          v24 = ipa3_ctx;
        }
        v30 = (const void *)(*(_QWORD *)(a1 + 264) + a4);
        *(_QWORD *)(a1 + 280) = v30;
        if ( v24 )
        {
          v31 = *(_QWORD *)(v24 + 34152);
          if ( v31 )
          {
            ipc_log_string(
              v31,
              "ipa %s:%d %s expansion_table_addr: 0x%pK\n",
              "ipa3_nat_ipv6ct_init_device_structure",
              1038,
              (const char *)a1,
              v30);
            v24 = ipa3_ctx;
          }
          v32 = *(_QWORD *)(v24 + 34160);
          if ( v32 )
          {
            ipc_log_string(
              v32,
              "ipa %s:%d %s expansion_table_addr: 0x%pK\n",
              "ipa3_nat_ipv6ct_init_device_structure",
              1038,
              (const char *)a1,
              *(const void **)(a1 + 280));
            v24 = ipa3_ctx;
          }
          if ( v24 )
          {
            v33 = *(_QWORD *)(v24 + 34152);
            if ( v33 )
            {
              ipc_log_string(
                v33,
                "ipa %s:%d %s table_entries: %d\n",
                "ipa3_nat_ipv6ct_init_device_structure",
                1041,
                (const char *)a1,
                a5);
              v24 = ipa3_ctx;
            }
            v34 = *(_QWORD *)(v24 + 34160);
            if ( v34 )
            {
              ipc_log_string(
                v34,
                "ipa %s:%d %s table_entries: %d\n",
                "ipa3_nat_ipv6ct_init_device_structure",
                1041,
                (const char *)a1,
                a5);
              v24 = ipa3_ctx;
            }
            *(_DWORD *)(a1 + 288) = a5;
            if ( v24 )
            {
              v35 = *(_QWORD *)(v24 + 34152);
              if ( v35 )
              {
                ipc_log_string(
                  v35,
                  "ipa %s:%d %s expn_table_entries: %d\n",
                  "ipa3_nat_ipv6ct_init_device_structure",
                  1046,
                  (const char *)a1,
                  a6);
                v24 = ipa3_ctx;
              }
              v36 = *(_QWORD *)(v24 + 34160);
              if ( v36 )
                ipc_log_string(
                  v36,
                  "ipa %s:%d %s expn_table_entries: %d\n",
                  "ipa3_nat_ipv6ct_init_device_structure",
                  1046,
                  (const char *)a1,
                  a6);
            }
            goto LABEL_95;
          }
        }
LABEL_94:
        *(_DWORD *)(a1 + 288) = a5;
LABEL_95:
        v63 = 0;
        *(_DWORD *)(a1 + 292) = a6;
        goto LABEL_99;
      }
    }
    else
    {
      *(_QWORD *)(a1 + 272) = *(_QWORD *)(a1 + 264) + a3;
    }
    *(_QWORD *)(a1 + 280) = *(_QWORD *)(a1 + 264) + a4;
    goto LABEL_94;
  }
  if ( *(_BYTE *)(a1 + 220) != 1 )
    goto LABEL_98;
  v37 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v38 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v38 )
    {
      ipc_log_string(v38, "ipa %s:%d v4\n", "ipa3_nat_ipv6ct_init_device_structure", 1056);
      v37 = ipa3_ctx;
    }
    v39 = *(_QWORD *)(v37 + 34160);
    if ( v39 )
      ipc_log_string(v39, "ipa %s:%d v4\n", "ipa3_nat_ipv6ct_init_device_structure", 1056);
  }
  v40 = *(_QWORD *)(a1 + 96LL * a2 + 416);
  *(_DWORD *)(a1 + 344) = a2;
  v41 = (const void *)(v40 + a3);
  *(_QWORD *)(a1 + 96LL * a2 + 424) = v41;
  v42 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v43 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v43 )
    {
      ipc_log_string(
        v43,
        "ipa %s:%d %s base_table_addr: 0x%pK\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1064,
        (const char *)a1,
        v41);
      v42 = ipa3_ctx;
    }
    v44 = *(_QWORD *)(v42 + 34160);
    if ( v44 )
      ipc_log_string(
        v44,
        "ipa %s:%d %s base_table_addr: 0x%pK\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1064,
        (const char *)a1,
        *(const void **)(a1 + 96LL * a2 + 424));
  }
  v45 = (const void *)(*(_QWORD *)(a1 + 96LL * a2 + 416) + a4);
  *(_QWORD *)(a1 + 96LL * a2 + 432) = v45;
  v46 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v47 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v47 )
    {
      ipc_log_string(
        v47,
        "ipa %s:%d %s expansion_table_addr: 0x%pK\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1070,
        (const char *)a1,
        v45);
      v46 = ipa3_ctx;
    }
    v48 = *(_QWORD *)(v46 + 34160);
    if ( v48 )
    {
      ipc_log_string(
        v48,
        "ipa %s:%d %s expansion_table_addr: 0x%pK\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1070,
        (const char *)a1,
        *(const void **)(a1 + 96LL * a2 + 432));
      v46 = ipa3_ctx;
    }
    if ( v46 )
    {
      v49 = *(_QWORD *)(v46 + 34152);
      if ( v49 )
      {
        ipc_log_string(
          v49,
          "ipa %s:%d %s table_entries: %d\n",
          "ipa3_nat_ipv6ct_init_device_structure",
          1073,
          (const char *)a1,
          a5);
        v46 = ipa3_ctx;
      }
      v50 = *(_QWORD *)(v46 + 34160);
      if ( v50 )
        ipc_log_string(
          v50,
          "ipa %s:%d %s table_entries: %d\n",
          "ipa3_nat_ipv6ct_init_device_structure",
          1073,
          (const char *)a1,
          a5);
    }
  }
  *(_DWORD *)(a1 + 96LL * a2 + 408) = a5;
  v51 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v52 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v52 )
    {
      ipc_log_string(
        v52,
        "ipa %s:%d %s expn_table_entries: %d\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1078,
        (const char *)a1,
        a6);
      v51 = ipa3_ctx;
    }
    v53 = *(_QWORD *)(v51 + 34160);
    if ( v53 )
      ipc_log_string(
        v53,
        "ipa %s:%d %s expn_table_entries: %d\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1078,
        (const char *)a1,
        a6);
  }
  v54 = (const void *)(*(_QWORD *)(a1 + 96LL * a2 + 416) + a7);
  *(_DWORD *)(a1 + 96LL * a2 + 412) = a6;
  *(_QWORD *)(a1 + 96LL * a2 + 440) = v54;
  v55 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v56 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v56 )
    {
      ipc_log_string(v56, "ipa %s:%d index_table_addr: 0x%pK\n", "ipa3_nat_ipv6ct_init_device_structure", 1086, v54);
      v55 = ipa3_ctx;
    }
    v57 = *(_QWORD *)(v55 + 34160);
    if ( v57 )
      ipc_log_string(
        v57,
        "ipa %s:%d index_table_addr: 0x%pK\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1086,
        *(const void **)(a1 + 96LL * a2 + 440));
  }
  v58 = (const void *)(*(_QWORD *)(a1 + 96LL * a2 + 416) + a8);
  *(_QWORD *)(a1 + 96LL * a2 + 448) = v58;
  v59 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v60 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v60 )
    {
      ipc_log_string(
        v60,
        "ipa %s:%d index_table_expansion_addr: 0x%pK\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1092,
        v58);
      v59 = ipa3_ctx;
    }
    v61 = *(_QWORD *)(v59 + 34160);
    if ( v61 )
      ipc_log_string(
        v61,
        "ipa %s:%d index_table_expansion_addr: 0x%pK\n",
        "ipa3_nat_ipv6ct_init_device_structure",
        1092,
        *(const void **)(a1 + 96LL * a2 + 448));
  }
  if ( !a2 )
  {
    if ( a9 )
    {
      v63 = 0;
      ++*(_DWORD *)(a1 + 348);
      goto LABEL_99;
    }
    goto LABEL_98;
  }
  v62 = *(_QWORD *)(a1 + 96LL * a2 + 424);
  if ( (v62 & 0x1F) != 0
    || (v62 = *(_QWORD *)(a1 + 96LL * a2 + 432), (v62 & 0x1F) != 0)
    || (v62 = *(_QWORD *)(a1 + 96LL * a2 + 440), (v62 & 3) != 0) )
  {
    printk(&unk_3E9BD2, "chk_sram_offset_alignment");
    v68 = ipa3_ctx;
    if ( !ipa3_ctx )
      return (unsigned int)-19;
    v69 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v69 )
    {
      ipc_log_string(v69, "ipa %s:%d sram addr(%luK) is not properly aligned\n", "chk_sram_offset_alignment", 991, v62);
      v68 = ipa3_ctx;
    }
    v70 = *(_QWORD *)(v68 + 34160);
    if ( v70 )
    {
      ipc_log_string(v70, "ipa %s:%d sram addr(%luK) is not properly aligned\n", "chk_sram_offset_alignment", 991, v62);
      v63 = -19;
      goto LABEL_99;
    }
  }
  else if ( (chk_sram_offset_alignment(*(_QWORD *)(a1 + 96LL * a2 + 448), 3) & 1) != 0 )
  {
    if ( a9 )
    {
      v63 = 0;
      ++*(_DWORD *)(a1 + 352);
      goto LABEL_99;
    }
LABEL_98:
    v63 = 0;
    goto LABEL_99;
  }
  v63 = -19;
LABEL_99:
  v64 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v65 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v65 )
    {
      ipc_log_string(v65, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_init_device_structure", 1125);
      v64 = ipa3_ctx;
    }
    v66 = *(_QWORD *)(v64 + 34160);
    if ( v66 )
      ipc_log_string(v66, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_init_device_structure", 1125);
  }
  return v63;
}
