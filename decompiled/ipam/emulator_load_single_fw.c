__int64 __fastcall emulator_load_single_fw(unsigned __int64 *a1, unsigned int *a2, unsigned int a3, unsigned int a4)
{
  __int64 v6; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned __int64 v11; // x3
  unsigned __int64 v12; // x5
  unsigned int v13; // w4
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x2
  __int64 v18; // x0
  __int64 v19; // x8
  char *v20; // x23
  __int64 v21; // x0
  __int64 v22; // x0
  unsigned int v23; // w21
  int v24; // w8
  int v25; // w22
  __int64 v26; // x21
  int v27; // w8
  unsigned __int64 v28; // x20
  int v29; // w22
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0

  v6 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(
        v9,
        "ipa %s:%d firmware(%pK) phdr(%pK) loc_to_map(0x%X) size_to_map(%u)\n",
        "emulator_load_single_fw",
        13300,
        a1,
        a2,
        a3,
        a4);
      v6 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v6 + 34160);
    if ( v10 )
      ipc_log_string(
        v10,
        "ipa %s:%d firmware(%pK) phdr(%pK) loc_to_map(0x%X) size_to_map(%u)\n",
        "emulator_load_single_fw",
        13300,
        a1,
        a2,
        a3,
        a4);
  }
  v11 = a2[1];
  if ( *a1 < v11 )
  {
    printk(&unk_3FEE39, "emulator_load_single_fw");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(
          v32,
          "ipa %s:%d Invalid ELF: offset=%u is beyond elf_size=%zu\n",
          "emulator_load_single_fw",
          13304,
          a2[1],
          *a1);
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
      {
        ipc_log_string(
          v33,
          "ipa %s:%d Invalid ELF: offset=%u is beyond elf_size=%zu\n",
          "emulator_load_single_fw",
          13304,
          a2[1],
          *a1);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  v12 = a2[4];
  if ( *a1 - v11 < v12 )
  {
    printk(&unk_3BED82, "emulator_load_single_fw");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(
          v35,
          "ipa %s:%d Invalid ELF: offset=%u filesz=%u elf_size=%zu\n",
          "emulator_load_single_fw",
          13309,
          a2[1],
          a2[4],
          *a1);
        v34 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v34 + 34160);
      if ( v36 )
      {
        ipc_log_string(
          v36,
          "ipa %s:%d Invalid ELF: offset=%u filesz=%u elf_size=%zu\n",
          "emulator_load_single_fw",
          13309,
          a2[1],
          a2[4],
          *a1);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  v13 = a2[5];
  if ( (v13 & 3) != 0 )
  {
    printk(&unk_3A484F, "emulator_load_single_fw");
    v37 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v38 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v38 )
      {
        ipc_log_string(
          v38,
          "ipa %s:%d FW mem size %u doesn't align to 32bit\n",
          "emulator_load_single_fw",
          13315,
          a2[5]);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
      {
        ipc_log_string(
          v39,
          "ipa %s:%d FW mem size %u doesn't align to 32bit\n",
          "emulator_load_single_fw",
          13315,
          a2[5]);
        return 4294967282LL;
      }
    }
    return 4294967282LL;
  }
  if ( (unsigned int)v12 > v13 )
  {
    printk(&unk_3BC073, "emulator_load_single_fw");
    v40 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v41 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v41 )
      {
        ipc_log_string(
          v41,
          "ipa %s:%d FW image too big src_size=%u dst_size=%u\n",
          "emulator_load_single_fw",
          13321,
          a2[4],
          a2[5]);
        v40 = ipa3_ctx;
      }
      v42 = *(_QWORD *)(v40 + 34160);
      if ( v42 )
      {
        ipc_log_string(
          v42,
          "ipa %s:%d FW image too big src_size=%u dst_size=%u\n",
          "emulator_load_single_fw",
          13321,
          a2[4],
          a2[5]);
        return 4294967282LL;
      }
    }
    return 4294967282LL;
  }
  v14 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v15 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d ELF: p_memsz(0x%x) p_filesz(0x%x) p_filesz/4(0x%x)\n",
        "emulator_load_single_fw",
        13328,
        v13,
        v12,
        (unsigned int)v12 >> 2);
      v14 = ipa3_ctx;
    }
    v16 = *(_QWORD *)(v14 + 34160);
    if ( v16 )
      ipc_log_string(
        v16,
        "ipa %s:%d ELF: p_memsz(0x%x) p_filesz(0x%x) p_filesz/4(0x%x)\n",
        "emulator_load_single_fw",
        13328,
        a2[5],
        a2[4],
        a2[4] >> 2);
  }
  if ( arm64_use_ng_mappings )
    v17 = 0x68000000000F13LL;
  else
    v17 = 0x68000000000713LL;
  v18 = ioremap_prot(a3, a4, v17);
  if ( v18 )
  {
    v19 = ipa3_ctx;
    v20 = (char *)v18;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(
          v21,
          "ipa %s:%d Physical base(0x%X) mapped to virtual (%pK) with len (%u)\n",
          "emulator_load_single_fw",
          13340,
          a3,
          v20,
          a4);
        v19 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v19 + 34160);
      if ( v22 )
        ipc_log_string(
          v22,
          "ipa %s:%d Physical base(0x%X) mapped to virtual (%pK) with len (%u)\n",
          "emulator_load_single_fw",
          13340,
          a3,
          v20,
          a4);
    }
    if ( a2[5] >= 4 )
    {
      v23 = 0;
      v24 = 0;
      do
      {
        v25 = v24;
        writel_relaxed(0, &v20[v24]);
        ++v23;
        v24 = v25 + 4;
      }
      while ( v23 < a2[5] >> 2 );
    }
    if ( a2[4] >= 4 )
    {
      v26 = 0;
      v27 = 0;
      v28 = a1[1] + a2[1];
      do
      {
        v29 = v27;
        writel_relaxed(*(unsigned int *)(v28 + 4 * v26++), &v20[v27]);
        v27 = v29 + 4;
      }
      while ( (unsigned int)v26 < a2[4] >> 2 );
    }
    iounmap(v20);
    return 0;
  }
  else
  {
    printk(&unk_3ADB22, "emulator_load_single_fw");
    v43 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967284LL;
    v44 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v44 )
    {
      ipc_log_string(v44, "ipa %s:%d Failed to map 0x%X for the size of %u\n", "emulator_load_single_fw", 13333, a3, a4);
      v43 = ipa3_ctx;
    }
    v45 = *(_QWORD *)(v43 + 34160);
    if ( v45 )
    {
      ipc_log_string(v45, "ipa %s:%d Failed to map 0x%X for the size of %u\n", "emulator_load_single_fw", 13333, a3, a4);
      return 4294967284LL;
    }
    else
    {
      return 4294967284LL;
    }
  }
}
