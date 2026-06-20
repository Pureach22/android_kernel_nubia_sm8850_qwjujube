__int64 __fastcall emulator_load_fws(_QWORD *a1, int a2)
{
  _UNKNOWN **v2; // x28
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x20
  _DWORD *v9; // x20
  unsigned int v10; // w22
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w22
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  int reg_n; // w4
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  unsigned int v40; // w22
  unsigned __int64 v41; // x8
  __int64 v42; // x26
  unsigned __int64 v43; // x23
  _BYTE *v44; // x8
  int v45; // w9
  unsigned __int64 v46; // x25
  unsigned __int64 v47; // x23
  _DWORD *v48; // x27
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x3
  unsigned int v53; // w9
  unsigned int i; // w22
  unsigned int v55; // w9
  unsigned __int64 v56; // x8
  _UNKNOWN **v57; // x26
  unsigned __int64 v58; // x28
  __int64 v59; // x23
  __int64 v60; // x3
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  unsigned int v64; // w23
  unsigned int v65; // w9
  unsigned __int64 v66; // x8
  __int64 v67; // x22
  unsigned __int64 v68; // x25
  unsigned int v69; // w22
  unsigned __int64 v70; // x8
  unsigned __int64 v71; // x28
  __int64 v72; // x23
  _QWORD *v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  _QWORD *v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x8
  __int64 v81; // x0
  __int64 v82; // x0
  _QWORD *v83; // x8
  __int64 v84; // x0
  __int64 v85; // x0
  int v86; // [xsp+18h] [xbp-38h]
  __int64 v87; // [xsp+20h] [xbp-30h] BYREF
  __int64 v88; // [xsp+28h] [xbp-28h]
  unsigned __int64 v89; // [xsp+30h] [xbp-20h] BYREF
  __int64 v90; // [xsp+38h] [xbp-18h] BYREF
  int v91; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v92; // [xsp+48h] [xbp-8h]

  v2 = &off_1F7000;
  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = ipa3_ctx;
  v89 = 0;
  v90 = 0;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Loading firmware(%pK)\n", "emulator_load_fws", 13573, a1);
      v5 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v5 + 34160);
    if ( v7 )
      ipc_log_string(v7, "ipa %s:%d Loading firmware(%pK)\n", "emulator_load_fws", 13573, a1);
  }
  if ( !a1 )
  {
    printk(&unk_3F32D6, "emulator_load_fws");
    v28 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v29 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v29 )
      {
        ipc_log_string(v29, "ipa %s:%d firmware pointer passed to function is NULL\n", "emulator_load_fws", 13576);
        v28 = ipa3_ctx;
      }
      v30 = *(_QWORD *)(v28 + 34160);
      if ( v30 )
        ipc_log_string(v30, "ipa %s:%d firmware pointer passed to function is NULL\n", "emulator_load_fws", 13576);
    }
    goto LABEL_175;
  }
  if ( *a1 <= 0x93u )
  {
    printk(&unk_3C1BF0, "emulator_load_fws");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(
          v32,
          "ipa %s:%d Missing ELF and Program headers firmware size=%zu\n",
          "emulator_load_fws",
          13584,
          *a1);
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
        ipc_log_string(
          v33,
          "ipa %s:%d Missing ELF and Program headers firmware size=%zu\n",
          "emulator_load_fws",
          13584,
          *a1);
    }
    goto LABEL_175;
  }
  v8 = a1[1];
  if ( !v8 )
    ((void (*)(void))ipa_assert)();
  if ( *(_WORD *)(v8 + 44) != 3 )
  {
    printk(&unk_3C1C2F, "emulator_load_fws");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d Unexpected number of ELF program headers\n", "emulator_load_fws", 13593);
        v34 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v34 + 34160);
      if ( v36 )
        ipc_log_string(v36, "ipa %s:%d Unexpected number of ELF program headers\n", "emulator_load_fws", 13593);
    }
    goto LABEL_175;
  }
  v87 = 0;
  v88 = 0;
  ipa3_get_hps_dps_areas_absolute_addr_and_sz(&v87);
  v9 = (_DWORD *)a1[1];
  v10 = HIDWORD(v88);
  if ( v9[34] > HIDWORD(v88) )
  {
    printk(&unk_3C1C65, "emulator_load_fws");
    v61 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v62 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v62 )
      {
        ipc_log_string(
          v62,
          "ipa %s:%d Invalid IPA HPS img size memsz=%d hps_size=%u\n",
          "emulator_load_fws",
          13623,
          v9[34],
          v10);
        v61 = ipa3_ctx;
      }
      v63 = *(_QWORD *)(v61 + 34160);
      if ( v63 )
        ipc_log_string(
          v63,
          "ipa %s:%d Invalid IPA HPS img size memsz=%d hps_size=%u\n",
          "emulator_load_fws",
          13623,
          (unsigned int)v9[34],
          v10);
    }
    goto LABEL_175;
  }
  v11 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d Loading HPS FW\n", "emulator_load_fws", 13626);
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
      ipc_log_string(v13, "ipa %s:%d Loading HPS FW\n", "emulator_load_fws", 13626);
  }
  result = emulator_load_single_fw(a1, v9 + 29, (unsigned int)v88, v10);
  if ( (_DWORD)result )
    goto LABEL_176;
  v15 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d Loading HPS FW complete\n", "emulator_load_fws", 13632);
      v15 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v15 + 34160);
    if ( v17 )
      ipc_log_string(v17, "ipa %s:%d Loading HPS FW complete\n", "emulator_load_fws", 13632);
  }
  v18 = HIDWORD(v87);
  if ( v9[26] > HIDWORD(v87) )
  {
    printk(&unk_3A478C, "emulator_load_fws");
    v80 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v81 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v81 )
      {
        ipc_log_string(
          v81,
          "ipa %s:%d Invalid IPA DPS img size memsz=%d dps_size=%u\n",
          "emulator_load_fws",
          13641,
          v9[26],
          v18);
        v80 = ipa3_ctx;
      }
      v82 = *(_QWORD *)(v80 + 34160);
      if ( v82 )
        ipc_log_string(
          v82,
          "ipa %s:%d Invalid IPA DPS img size memsz=%d dps_size=%u\n",
          "emulator_load_fws",
          13641,
          (unsigned int)v9[26],
          v18);
    }
    goto LABEL_175;
  }
  v19 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v20 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v20 )
    {
      ipc_log_string(v20, "ipa %s:%d Loading DPS FW\n", "emulator_load_fws", 13644);
      v19 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v19 + 34160);
    if ( v21 )
      ipc_log_string(v21, "ipa %s:%d Loading DPS FW\n", "emulator_load_fws", 13644);
  }
  result = emulator_load_single_fw(a1, v9 + 21, (unsigned int)v87, v18);
  if ( (_DWORD)result )
    goto LABEL_176;
  v22 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v23 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v23 )
    {
      ipc_log_string(v23, "ipa %s:%d Loading DPS FW complete\n", "emulator_load_fws", 13650);
      v22 = ipa3_ctx;
    }
    v24 = *(_QWORD *)(v22 + 34160);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d Loading DPS FW complete\n", "emulator_load_fws", 13650);
      v22 = ipa3_ctx;
    }
    if ( v22 )
    {
      v25 = *(_QWORD *)(v22 + 34152);
      if ( v25 )
      {
        ipc_log_string(
          v25,
          "ipa %s:%d Setting up registers in preparation for firmware download\n",
          "ipa_gsi_setup_reg",
          13493);
        v22 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v22 + 34160);
      if ( v26 )
      {
        ipc_log_string(
          v26,
          "ipa %s:%d Setting up registers in preparation for firmware download\n",
          "ipa_gsi_setup_reg",
          13493);
        v22 = ipa3_ctx;
      }
    }
  }
  if ( *(_DWORD *)(v22 + 32240) < 0x15u )
  {
    reg_n = ipahal_read_reg_n(11, 0);
  }
  else
  {
    v91 = 0;
    ipahal_read_reg_n_fields(130, 0, &v91);
    reg_n = (unsigned __int8)v91;
  }
  v37 = ipa3_ctx;
  *(_DWORD *)(ipa3_ctx + 34308) = reg_n;
  if ( v37 )
  {
    v38 = *(_QWORD *)(v37 + 34152);
    if ( v38 )
    {
      ipc_log_string(v38, "ipa %s:%d ipa_num_pipes=%u\n", "ipa_gsi_setup_reg", 13498, reg_n);
      v37 = ipa3_ctx;
    }
    v39 = *(_QWORD *)(v37 + 34160);
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d ipa_num_pipes=%u\n", "ipa_gsi_setup_reg", 13498, *(_DWORD *)(v37 + 34308));
      v37 = ipa3_ctx;
    }
  }
  if ( !*(_DWORD *)(v37 + 34308) )
    goto LABEL_152;
  v40 = 0;
  v86 = 0;
  do
  {
    v41 = *(unsigned __int8 *)(v37 + 32244);
    if ( v41 > 0x17 )
      goto LABEL_183;
    v42 = 0;
    v43 = 6968LL * (unsigned int)v41;
    while ( 1 )
    {
      if ( v43 > 0x28D3F )
        goto LABEL_182;
      if ( (ipa3_ep_mapping[v43] & 1) != 0 )
      {
        if ( v43 > 0x28D2B )
          goto LABEL_182;
        if ( *(_DWORD *)&ipa3_ep_mapping[v43 + 20] == v40 )
          break;
      }
      ++v42;
      v43 += 52LL;
      if ( v42 == 134 )
      {
        if ( (unsigned int)ipa_get_ep_mapping(134) != -1 )
          goto LABEL_183;
        goto LABEL_84;
      }
    }
    if ( (unsigned int)ipa_get_ep_mapping((unsigned int)v42) == -1 )
    {
LABEL_84:
      v46 = 0;
      v47 = 0;
      v48 = nullptr;
      goto LABEL_85;
    }
    if ( (unsigned int)v42 >= 0x86 )
      goto LABEL_183;
    v44 = &ipa3_ep_mapping[v43 + 20];
    v45 = (unsigned __int8)ipa3_ep_mapping[v43];
    if ( ipa3_ep_mapping[v43] )
      v46 = 167232;
    else
      v46 = 0;
    if ( ipa3_ep_mapping[v43] )
      v47 = v43 + 20;
    else
      v47 = 0;
    if ( v45 )
      v48 = v44;
    else
      v48 = nullptr;
LABEL_85:
    printk(&unk_3B326C, "ipa_gsi_setup_reg");
    v49 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v50 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v50 )
      {
        ipc_log_string(
          v50,
          "ipa %s:%d for ep %d client is %d gsi_ep_info_cfg=%pK\n",
          "ipa_gsi_setup_reg",
          13504,
          v40,
          v42,
          v48);
        v49 = ipa3_ctx;
      }
      v51 = *(_QWORD *)(v49 + 34160);
      if ( v51 )
        ipc_log_string(
          v51,
          "ipa %s:%d for ep %d client is %d gsi_ep_info_cfg=%pK\n",
          "ipa_gsi_setup_reg",
          13504,
          v40,
          v42,
          v48);
    }
    if ( v48 )
    {
      if ( v46 < v47 + 8 || v46 - (v47 + 8) < 4 || v46 < v47 + 8 || v46 - (v47 + 8) < 4 )
        goto LABEL_182;
      v52 = (unsigned __int16)v86 | ((unsigned __int8)v48[2] << 16);
      v86 += v48[2];
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(127, 0, v40, v52);
    }
    v37 = ipa3_ctx;
    ++v40;
    v53 = *(_DWORD *)(ipa3_ctx + 34308);
  }
  while ( v40 < v53 );
  if ( !v53 )
    goto LABEL_152;
  for ( i = 0; i < v55; ++i )
  {
    v56 = *(unsigned __int8 *)(v37 + 32244);
    if ( v56 > 0x17 )
      goto LABEL_183;
    v57 = v2;
    v58 = 6968LL * (unsigned int)v56;
    v59 = 0;
    while ( 1 )
    {
      if ( v58 > 0x28D3F )
        goto LABEL_182;
      if ( (ipa3_ep_mapping[v58] & 1) != 0 )
      {
        if ( v58 > 0x28D2B )
          goto LABEL_182;
        if ( *(_DWORD *)&ipa3_ep_mapping[v58 + 20] == i )
          break;
      }
      ++v59;
      v58 += 52LL;
      if ( v59 == 134 )
      {
        if ( (unsigned int)ipa_get_ep_mapping(134) != -1 )
          goto LABEL_183;
        goto LABEL_100;
      }
    }
    if ( (unsigned int)ipa_get_ep_mapping((unsigned int)v59) != -1 )
    {
      if ( (unsigned int)v59 >= 0x86 )
        goto LABEL_183;
      if ( ipa3_ep_mapping[v58] == 1 && &ipa3_ep_mapping[v58] != (_BYTE *)-20LL )
      {
        if ( v58 <= 0x28D1F )
        {
          v60 = (unsigned __int16)v86 | ((unsigned __int8)*(_DWORD *)&ipa3_ep_mapping[v58 + 32] << 16);
          v86 += *(_DWORD *)&ipa3_ep_mapping[v58 + 32];
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(126, 0, i, v60);
          goto LABEL_100;
        }
LABEL_182:
        __break(1u);
        goto LABEL_183;
      }
    }
LABEL_100:
    v37 = (__int64)v57[257];
    v2 = v57;
    v55 = *(_DWORD *)(v37 + 34308);
  }
  if ( !v55 )
    goto LABEL_152;
  v64 = 0;
  while ( 2 )
  {
    v66 = *(unsigned __int8 *)(v37 + 32244);
    if ( v66 > 0x17 )
      goto LABEL_183;
    v67 = 0;
    v68 = 6968LL * (unsigned int)v66;
    while ( 1 )
    {
      if ( v68 > 0x28D3F )
        goto LABEL_182;
      if ( (ipa3_ep_mapping[v68] & 1) != 0 )
      {
        if ( v68 > 0x28D2B )
          goto LABEL_182;
        if ( *(_DWORD *)&ipa3_ep_mapping[v68 + 20] == v64 )
          break;
      }
      ++v67;
      v68 += 52LL;
      if ( v67 == 134 )
      {
        if ( (unsigned int)ipa_get_ep_mapping(134) != -1 )
          goto LABEL_183;
        goto LABEL_122;
      }
    }
    if ( (unsigned int)ipa_get_ep_mapping((unsigned int)v67) != -1 )
    {
      if ( (unsigned int)v67 >= 0x86 )
        goto LABEL_183;
      if ( ipa3_ep_mapping[v68] == 1 && &ipa3_ep_mapping[v68] != (_BYTE *)-20LL )
      {
        if ( v68 <= 0x28D1B )
        {
          gsi_map_virtual_ch_to_per_ep(
            *(unsigned int *)&ipa3_ep_mapping[v68 + 36],
            *(unsigned int *)&ipa3_ep_mapping[v68 + 24],
            (unsigned __int8)v64);
          goto LABEL_122;
        }
        goto LABEL_182;
      }
    }
LABEL_122:
    v37 = (__int64)v57[257];
    ++v64;
    v65 = *(_DWORD *)(v37 + 34308);
    if ( v64 < v65 )
      continue;
    break;
  }
  if ( v65 )
  {
    v69 = 0;
    do
    {
      v70 = *(unsigned __int8 *)(v37 + 32244);
      if ( v70 > 0x17 )
        goto LABEL_183;
      v71 = 6968LL * (unsigned int)v70;
      v72 = 0;
      while ( 1 )
      {
        if ( v71 > 0x28D3F )
          goto LABEL_182;
        if ( (ipa3_ep_mapping[v71] & 1) != 0 )
        {
          if ( v71 > 0x28D2B )
            goto LABEL_182;
          if ( *(_DWORD *)&ipa3_ep_mapping[v71 + 20] == v69 )
            break;
        }
        ++v72;
        v71 += 52LL;
        if ( v72 == 134 )
        {
          if ( (unsigned int)ipa_get_ep_mapping(134) == -1 )
            goto LABEL_139;
LABEL_183:
          __break(0x5512u);
        }
      }
      if ( (unsigned int)ipa_get_ep_mapping((unsigned int)v72) != -1 )
      {
        if ( (unsigned int)v72 >= 0x86 )
          goto LABEL_183;
        if ( ipa3_ep_mapping[v71] == 1 && &ipa3_ep_mapping[v71] != (_BYTE *)-20LL )
        {
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(125, 0, v69, 0x10000);
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(125, 0, v69, 2147549184LL);
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(125, 0, v69, 0x10000);
        }
      }
LABEL_139:
      v37 = (__int64)v57[257];
      ++v69;
      v2 = v57;
    }
    while ( v69 < *(_DWORD *)(v37 + 34308) );
  }
LABEL_152:
  gsi_get_inst_ram_offset_and_size(&v90, &v89);
  if ( v89 < (unsigned int)v9[18] )
  {
    printk(&unk_3A7A40, "emulator_load_fws");
    v83 = v2[257];
    if ( v83 )
    {
      v84 = v83[4269];
      if ( v84 )
      {
        ipc_log_string(
          v84,
          "ipa %s:%d Invalid GSI FW img size memsz=%d gsi_ram_size=%lu\n",
          "emulator_load_fws",
          13668,
          v9[18],
          v89);
        v83 = v2[257];
      }
      v85 = v83[4270];
      if ( v85 )
        ipc_log_string(
          v85,
          "ipa %s:%d Invalid GSI FW img size memsz=%d gsi_ram_size=%lu\n",
          "emulator_load_fws",
          13668,
          v9[18],
          v89);
    }
LABEL_175:
    result = 4294967274LL;
    goto LABEL_176;
  }
  v73 = v2[257];
  if ( v73 )
  {
    v74 = v73[4269];
    if ( v74 )
    {
      ipc_log_string(v74, "ipa %s:%d Loading GSI FW\n", "emulator_load_fws", 13671);
      v73 = v2[257];
    }
    v75 = v73[4270];
    if ( v75 )
      ipc_log_string(v75, "ipa %s:%d Loading GSI FW\n", "emulator_load_fws", 13671);
  }
  result = emulator_load_single_fw(a1, v9 + 13, (unsigned int)(v90 + a2), (unsigned int)v89);
  if ( !(_DWORD)result )
  {
    v76 = v2[257];
    if ( !v76 )
      goto LABEL_169;
    v77 = v76[4269];
    if ( v77 )
    {
      ipc_log_string(v77, "ipa %s:%d Loading GSI FW complete\n", "emulator_load_fws", 13677);
      v76 = v2[257];
    }
    v78 = v76[4270];
    if ( v78 )
    {
      ipc_log_string(v78, "ipa %s:%d Loading GSI FW complete\n", "emulator_load_fws", 13677);
      v76 = v2[257];
    }
    if ( v76 )
    {
      v79 = v76[4269];
      if ( v79 )
      {
        ipc_log_string(v79, "ipa %s:%d IPA FWs (GSI FW, DPS and HPS) loaded successfully\n", "emulator_load_fws", 13679);
        v76 = v2[257];
      }
      result = v76[4270];
      if ( result )
      {
        ipc_log_string(
          result,
          "ipa %s:%d IPA FWs (GSI FW, DPS and HPS) loaded successfully\n",
          "emulator_load_fws",
          13679);
        goto LABEL_169;
      }
    }
    else
    {
LABEL_169:
      result = 0;
    }
  }
LABEL_176:
  _ReadStatusReg(SP_EL0);
  return result;
}
