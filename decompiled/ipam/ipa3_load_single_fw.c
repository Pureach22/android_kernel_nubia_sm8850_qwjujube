__int64 __fastcall ipa3_load_single_fw(unsigned __int64 *a1, unsigned int *a2)
{
  unsigned __int64 v2; // x3
  unsigned __int64 v5; // x4
  __int64 v6; // x1
  __int64 v7; // x2
  char *v8; // x0
  char *v9; // x21
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x22
  char *v12; // x20
  unsigned __int64 v13; // x23
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0

  v2 = a2[1];
  if ( *a1 < v2 )
  {
    printk(&unk_3FEE39, "ipa3_load_single_fw");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d Invalid ELF: offset=%u is beyond elf_size=%zu\n",
          "ipa3_load_single_fw",
          13188,
          a2[1],
          *a1);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d Invalid ELF: offset=%u is beyond elf_size=%zu\n",
          "ipa3_load_single_fw",
          13188,
          a2[1],
          *a1);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  v5 = a2[4];
  if ( *a1 - v2 < v5 )
  {
    printk(&unk_3BED82, "ipa3_load_single_fw");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d Invalid ELF: offset=%u filesz=%u elf_size=%zu\n",
          "ipa3_load_single_fw",
          13193,
          a2[1],
          a2[4],
          *a1);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
      {
        ipc_log_string(
          v20,
          "ipa %s:%d Invalid ELF: offset=%u filesz=%u elf_size=%zu\n",
          "ipa3_load_single_fw",
          13193,
          a2[1],
          a2[4],
          *a1);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  v6 = a2[5];
  if ( (v6 & 3) != 0 )
  {
    printk(&unk_3A484F, "ipa3_load_single_fw");
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d FW mem size %u doesn't align to 32bit\n", "ipa3_load_single_fw", 13199, a2[5]);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d FW mem size %u doesn't align to 32bit\n", "ipa3_load_single_fw", 13199, a2[5]);
        return 4294967282LL;
      }
    }
    return 4294967282LL;
  }
  if ( (unsigned int)v5 > (unsigned int)v6 )
  {
    printk(&unk_3BC073, "ipa3_load_single_fw");
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(
          v25,
          "ipa %s:%d FW image too big src_size=%u dst_size=%u\n",
          "ipa3_load_single_fw",
          13205,
          a2[4],
          a2[5]);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
      {
        ipc_log_string(
          v26,
          "ipa %s:%d FW image too big src_size=%u dst_size=%u\n",
          "ipa3_load_single_fw",
          13205,
          a2[4],
          a2[5]);
        return 4294967282LL;
      }
    }
    return 4294967282LL;
  }
  if ( arm64_use_ng_mappings )
    v7 = 0x68000000000F13LL;
  else
    v7 = 0x68000000000713LL;
  v8 = (char *)ioremap_prot(a2[2], v6, v7);
  if ( v8 )
  {
    v9 = v8;
    memset(v8, 0, a2[5]);
    if ( a2[4] >= 4 )
    {
      v10 = a1[1];
      v11 = 0;
      v12 = v9;
      v13 = v10 + a2[1];
      do
      {
        writel_relaxed(*(unsigned int *)(v13 + 4 * v11++), v12);
        v12 += 4;
      }
      while ( v11 < (unsigned __int64)a2[4] >> 2 );
    }
    iounmap(v9);
    return 0;
  }
  else
  {
    printk(&unk_3A4882, "ipa3_load_single_fw");
    v27 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967284LL;
    v28 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v28 )
    {
      ipc_log_string(
        v28,
        "ipa %s:%d Failed to map 0x%x for the size of %u\n",
        "ipa3_load_single_fw",
        13212,
        a2[2],
        a2[5]);
      v27 = ipa3_ctx;
    }
    v29 = *(_QWORD *)(v27 + 34160);
    if ( v29 )
    {
      ipc_log_string(
        v29,
        "ipa %s:%d Failed to map 0x%x for the size of %u\n",
        "ipa3_load_single_fw",
        13212,
        a2[2],
        a2[5]);
      return 4294967284LL;
    }
    else
    {
      return 4294967284LL;
    }
  }
}
