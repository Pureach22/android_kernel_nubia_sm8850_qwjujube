__int64 __fastcall ipa3_load_fws(_QWORD *a1, __int64 a2, int a3)
{
  __int64 v5; // x19
  int v6; // w8
  bool v7; // zf
  __int64 v8; // x8
  _DWORD *v9; // x19
  __int64 result; // x0
  unsigned int v11; // w21
  unsigned int v12; // w21
  unsigned int v13; // w21
  unsigned int v14; // w21
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // [xsp+0h] [xbp-30h] BYREF
  __int64 v48; // [xsp+8h] [xbp-28h]
  unsigned __int64 v49; // [xsp+10h] [xbp-20h] BYREF
  __int64 v50; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v51[2]; // [xsp+20h] [xbp-10h] BYREF

  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = a2;
  v49 = 0;
  v50 = 0;
  if ( !a3 )
  {
    printk(&unk_3E7315, "ipa3_load_fws");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d Invalid GSI Version\n", "ipa3_load_fws", 13385);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d Invalid GSI Version\n", "ipa3_load_fws", 13385);
    }
    goto LABEL_77;
  }
  if ( !a2 )
  {
    printk(&unk_3F5F0A, "ipa3_load_fws");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d Invalid GSI base address\n", "ipa3_load_fws", 13390);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d Invalid GSI base address\n", "ipa3_load_fws", 13390);
    }
    goto LABEL_77;
  }
  if ( !a1 )
    ((void (*)(void))ipa_assert)();
  if ( *a1 <= 0x93u )
  {
    printk(&unk_3C1BF0, "ipa3_load_fws");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(
          v24,
          "ipa %s:%d Missing ELF and Program headers firmware size=%zu\n",
          "ipa3_load_fws",
          13398,
          *a1);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
        ipc_log_string(
          v25,
          "ipa %s:%d Missing ELF and Program headers firmware size=%zu\n",
          "ipa3_load_fws",
          13398,
          *a1);
    }
    goto LABEL_77;
  }
  v5 = a1[1];
  if ( !v5 )
    ((void (*)(void))ipa_assert)();
  v6 = *(unsigned __int16 *)(v5 + 44);
  if ( v6 != 3 && v6 != 5 )
  {
    printk(&unk_3C1C2F, "ipa3_load_fws");
    v32 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v33 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d Unexpected number of ELF program headers\n", "ipa3_load_fws", 13405);
        v32 = ipa3_ctx;
      }
      v34 = *(_QWORD *)(v32 + 34160);
      if ( v34 )
        ipc_log_string(v34, "ipa %s:%d Unexpected number of ELF program headers\n", "ipa3_load_fws", 13405);
    }
    goto LABEL_77;
  }
  v7 = v6 == 5;
  v8 = 52;
  if ( v7 )
    v8 = 116;
  v9 = (_DWORD *)(a1[1] + v8);
  gsi_get_inst_ram_offset_and_size(&v50, &v49);
  if ( v50 + a2 != v9[2] )
  {
    printk(&unk_3CD869, "ipa3_load_fws");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(
          v27,
          "ipa %s:%d Invalid GSI FW img load addr vaddr=0x%x gsi_mem_base=%pa gsi_iram_ofst=0x%lx\n",
          "ipa3_load_fws",
          13427,
          v9[2],
          v51,
          v50);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(
          v28,
          "ipa %s:%d Invalid GSI FW img load addr vaddr=0x%x gsi_mem_base=%pa gsi_iram_ofst=0x%lx\n",
          "ipa3_load_fws",
          13427,
          v9[2],
          v51,
          v50);
    }
    goto LABEL_77;
  }
  if ( v49 < (unsigned int)v9[5] )
  {
    printk(&unk_3D0886, "ipa3_load_fws");
    v29 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v30 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v30 )
      {
        ipc_log_string(
          v30,
          "ipa %s:%d Invalid GSI FW img size memsz=%d gsi_iram_size=%lu\n",
          "ipa3_load_fws",
          13432,
          v9[5],
          v49);
        v29 = ipa3_ctx;
      }
      v31 = *(_QWORD *)(v29 + 34160);
      if ( v31 )
        ipc_log_string(
          v31,
          "ipa %s:%d Invalid GSI FW img size memsz=%d gsi_iram_size=%lu\n",
          "ipa3_load_fws",
          13432,
          v9[5],
          v49);
    }
    goto LABEL_77;
  }
  result = ipa3_load_single_fw(a1, v9);
  if ( (_DWORD)result )
    goto LABEL_78;
  v47 = 0;
  v48 = 0;
  ipa3_get_hps_dps_areas_absolute_addr_and_sz(&v47);
  v11 = v47;
  if ( v9[10] != (_DWORD)v47 )
  {
    printk(&unk_3BEC55, "ipa3_load_fws");
    v35 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v36 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v36 )
      {
        ipc_log_string(
          v36,
          "ipa %s:%d Invalid IPA DPS img load addr vaddr=0x%x dps_abs_addr=0x%x\n",
          "ipa3_load_fws",
          13446,
          v9[10],
          v11);
        v35 = ipa3_ctx;
      }
      v37 = *(_QWORD *)(v35 + 34160);
      if ( v37 )
        ipc_log_string(
          v37,
          "ipa %s:%d Invalid IPA DPS img load addr vaddr=0x%x dps_abs_addr=0x%x\n",
          "ipa3_load_fws",
          13446,
          (unsigned int)v9[10],
          v11);
    }
    goto LABEL_77;
  }
  v12 = HIDWORD(v47);
  if ( v9[13] > HIDWORD(v47) )
  {
    printk(&unk_3B8E3C, "ipa3_load_fws");
    v38 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v39 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v39 )
      {
        ipc_log_string(
          v39,
          "ipa %s:%d Invalid IPA DPS img size memsz=%d dps_area_size=%u\n",
          "ipa3_load_fws",
          13451,
          v9[13],
          v12);
        v38 = ipa3_ctx;
      }
      v40 = *(_QWORD *)(v38 + 34160);
      if ( v40 )
        ipc_log_string(
          v40,
          "ipa %s:%d Invalid IPA DPS img size memsz=%d dps_area_size=%u\n",
          "ipa3_load_fws",
          13451,
          (unsigned int)v9[13],
          v12);
    }
    goto LABEL_77;
  }
  result = ipa3_load_single_fw(a1, v9 + 8);
  if ( (_DWORD)result )
    goto LABEL_78;
  v13 = v48;
  if ( v9[18] != (_DWORD)v48 )
  {
    printk(&unk_3BEC9D, "ipa3_load_fws");
    v41 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v42 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v42 )
      {
        ipc_log_string(
          v42,
          "ipa %s:%d Invalid IPA HPS img load addr vaddr=0x%x hps_abs_addr=0x%x\n",
          "ipa3_load_fws",
          13464,
          v9[18],
          v13);
        v41 = ipa3_ctx;
      }
      v43 = *(_QWORD *)(v41 + 34160);
      if ( v43 )
        ipc_log_string(
          v43,
          "ipa %s:%d Invalid IPA HPS img load addr vaddr=0x%x hps_abs_addr=0x%x\n",
          "ipa3_load_fws",
          13464,
          (unsigned int)v9[18],
          v13);
    }
    goto LABEL_77;
  }
  v14 = HIDWORD(v48);
  if ( v9[21] > HIDWORD(v48) )
  {
    printk(&unk_3C7E5B, "ipa3_load_fws");
    v44 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v45 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v45 )
      {
        ipc_log_string(
          v45,
          "ipa %s:%d Invalid IPA HPS img size memsz=%d hps_area_size=%u\n",
          "ipa3_load_fws",
          13469,
          v9[21],
          v14);
        v44 = ipa3_ctx;
      }
      v46 = *(_QWORD *)(v44 + 34160);
      if ( v46 )
        ipc_log_string(
          v46,
          "ipa %s:%d Invalid IPA HPS img size memsz=%d hps_area_size=%u\n",
          "ipa3_load_fws",
          13469,
          (unsigned int)v9[21],
          v14);
    }
LABEL_77:
    result = 4294967274LL;
    goto LABEL_78;
  }
  result = ipa3_load_single_fw(a1, v9 + 16);
  if ( !(_DWORD)result )
  {
    v15 = ipa3_ctx;
    if ( !ipa3_ctx )
    {
LABEL_26:
      result = 0;
      goto LABEL_78;
    }
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d IPA FWs (GSI FW, DPS and HPS) loaded successfully\n", "ipa3_load_fws", 13476);
      v15 = ipa3_ctx;
    }
    result = *(_QWORD *)(v15 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d IPA FWs (GSI FW, DPS and HPS) loaded successfully\n", "ipa3_load_fws", 13476);
      goto LABEL_26;
    }
  }
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return result;
}
