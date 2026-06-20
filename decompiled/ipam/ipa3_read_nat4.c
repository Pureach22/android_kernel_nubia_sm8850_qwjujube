__int64 __fastcall ipa3_read_nat4(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v3; // x27
  char v4; // w19
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x9
  _QWORD *v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  _QWORD *v14; // x19
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x20
  __int64 v22; // x1
  int v23; // w21
  void *v24; // x0
  __int64 is_entry_zeroed; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  int v31; // w8
  unsigned int *v32; // x21
  int *v33; // x20
  const char *v34; // x19
  __int64 v35; // x25
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  const char *v48; // [xsp+0h] [xbp-40h] BYREF
  char *v49; // [xsp+8h] [xbp-38h]
  __int64 v50; // [xsp+10h] [xbp-30h]
  int v51; // [xsp+1Ch] [xbp-24h] BYREF
  int v52; // [xsp+20h] [xbp-20h] BYREF
  unsigned int v53; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v54; // [xsp+28h] [xbp-18h] BYREF
  _BYTE v55[4]; // [xsp+30h] [xbp-10h] BYREF
  _BYTE v56[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+38h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v54 = 0;
  v53 = 0;
  v3 = ipa3_ctx + 28672;
  v51 = 0;
  v52 = 0;
  if ( (*(_BYTE *)(ipa3_ctx + 29884) & 1) != 0 )
    v4 = 1;
  else
    v4 = *(_BYTE *)(ipa3_ctx + 29885);
  printk(&unk_3BADB6, a2);
  if ( (*(_BYTE *)(v3 + 1078) & 1) != 0 )
  {
    mutex_lock(v2 + 29544);
    if ( (*(_BYTE *)(v3 + 1079) & (unsigned __int8)v4 & 1) == 0 )
    {
      printk(&unk_3D2650, v6);
      goto LABEL_79;
    }
    if ( *(_BYTE *)(v3 + 1213) == 1 )
    {
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d SRAM based table with client 0, enable clk\n", "ipa3_read_nat4", 2582);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(v9, "ipa %s:%d SRAM based table with client 0, enable clk\n", "ipa3_read_nat4", 2582);
      }
      v48 = "SRAM";
      v49 = "ipa_debugfs.c";
      v50 = 0x300000A17LL;
      ipa3_inc_client_enable_clks();
    }
    v10 = ipa3_ctx;
    if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
    {
      printk(&unk_3AF4C1, ipa3_ctx + 29832);
      goto LABEL_59;
    }
    v11 = nullptr;
    v48 = nullptr;
    v56[0] = 0;
    v55[0] = 0;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d In\n", "ipa3_read_pdn_table", 2480);
        v10 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v10 + 34160);
      v11 = (_QWORD *)v10;
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d In\n", "ipa3_read_pdn_table", 2480);
        v11 = (_QWORD *)ipa3_ctx;
      }
    }
    if ( !v11[3730] )
      goto LABEL_54;
    if ( (unsigned int)ipahal_nat_entry_size(2, &v48) )
    {
      printk(&unk_3C6A13, "ipa3_read_pdn_table");
      v11 = (_QWORD *)ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_59;
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d Failed to retrieve size of PDN entry", "ipa3_read_pdn_table", 2488);
        v11 = (_QWORD *)ipa3_ctx;
      }
      v20 = v11[4270];
      if ( !v20 )
      {
LABEL_54:
        if ( v11 )
        {
          v29 = v11[4269];
          if ( v29 )
          {
            ipc_log_string(v29, "ipa %s:%d Out\n", "ipa3_read_pdn_table", 2540);
            v11 = (_QWORD *)ipa3_ctx;
          }
          v30 = v11[4270];
          if ( v30 )
            ipc_log_string(v30, "ipa %s:%d Out\n", "ipa3_read_pdn_table", 2540);
        }
LABEL_59:
        ipa3_start_read_memory_device(v2 + 29528, 0, &v54, &v53);
        v31 = *(_DWORD *)(v3 + 1200);
        if ( v31 == 1 )
        {
          if ( *(_BYTE *)(v3 + 1213) != 1
            || (v32 = &v53, v33 = &v51, v34 = "SRAM based table", v35 = v2 + 29984, v2 == -29984) )
          {
LABEL_72:
            ipa3_finish_read_memory_device(v2 + 29528, (unsigned int)v54, v53);
            if ( *(_BYTE *)(v3 + 1213) == 1 )
            {
              v39 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v40 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v40 )
                {
                  ipc_log_string(v40, "ipa %s:%d SRAM based table with client 0, disable clk\n", "ipa3_read_nat4", 2649);
                  v39 = ipa3_ctx;
                }
                v41 = *(_QWORD *)(v39 + 34160);
                if ( v41 )
                  ipc_log_string(v41, "ipa %s:%d SRAM based table with client 0, disable clk\n", "ipa3_read_nat4", 2649);
              }
              v48 = "SRAM";
              v49 = "ipa_debugfs.c";
              v50 = 0x300000A5ALL;
              ipa3_dec_client_disable_clks();
            }
LABEL_79:
            printk(&unk_3C3903, v18);
            mutex_unlock(v2 + 29544);
            v17 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_84;
            goto LABEL_80;
          }
        }
        else
        {
          if ( v31 )
            goto LABEL_72;
          if ( (*(_BYTE *)(v3 + 1212) & 1) == 0 )
            goto LABEL_72;
          v32 = (unsigned int *)&v54;
          v33 = &v52;
          v34 = "DDR based table";
          v35 = v2 + 29888;
          if ( v2 == -29888 )
            goto LABEL_72;
        }
        printk(&unk_3EC0DE, v34);
        ipa3_read_table(*(_QWORD *)(v35 + 80), (unsigned int)(*(_DWORD *)(v35 + 48) + 1), v33, (char *)&v54 + 4, 1);
        printk(&unk_3E3738, v34);
        ipa3_read_table(*(_QWORD *)(v35 + 88), *(unsigned int *)(v35 + 52), v33, (char *)&v54 + 4, 1);
        if ( *v32 != *v33 )
        {
          printk(&unk_3B7C7D, "ipa3_read_nat4");
          v36 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v37 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v37 )
            {
              ipc_log_string(
                v37,
                "ipa %s:%d (%s) Base Table vs Index Table entry count differs (%u vs %u)\n",
                "ipa3_read_nat4",
                2640,
                v34,
                *v32,
                *v33);
              v36 = ipa3_ctx;
            }
            v38 = *(_QWORD *)(v36 + 34160);
            if ( v38 )
              ipc_log_string(
                v38,
                "ipa %s:%d (%s) Base Table vs Index Table entry count differs (%u vs %u)\n",
                "ipa3_read_nat4",
                2640,
                v34,
                *v32,
                *v33);
          }
        }
        goto LABEL_72;
      }
      ipc_log_string(v20, "ipa %s:%d Failed to retrieve size of PDN entry", "ipa3_read_pdn_table", 2488);
    }
    else
    {
      v14 = (_QWORD *)_kmalloc_cache_noprof(of_find_property, 3520, 128);
      if ( v14 )
      {
        v21 = *(_QWORD *)(ipa3_ctx + 29840);
        if ( (int)((__int64 (*)(void))ipa3_get_max_pdn)() < 1 )
        {
LABEL_51:
          printk(&unk_3C36C1, v22);
        }
        else
        {
          v23 = 0;
          while ( 1 )
          {
            is_entry_zeroed = ipahal_nat_is_entry_zeroed(2, v21, v56);
            if ( (_DWORD)is_entry_zeroed )
              break;
            if ( (v56[0] & 1) == 0 )
            {
              if ( (unsigned int)ipahal_nat_is_entry_valid(2, v21, v55) )
              {
                printk(&unk_3D8274, "ipa3_read_pdn_table");
                v26 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v27 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v27 )
                  {
                    ipc_log_string(
                      v27,
                      "ipa %s:%d Failed to determine whether the PDN entry is valid\n",
                      "ipa3_read_pdn_table",
                      2520);
                    v26 = ipa3_ctx;
                  }
                  v28 = *(_QWORD *)(v26 + 34160);
                  if ( v28 )
                    ipc_log_string(
                      v28,
                      "ipa %s:%d Failed to determine whether the PDN entry is valid\n",
                      "ipa3_read_pdn_table",
                      2520);
                }
                goto LABEL_52;
              }
              ipahal_nat_stringify_entry(2, v21, v14, 128);
              if ( v55[0] )
                v24 = &unk_3A6627;
              else
                v24 = &unk_3A9912;
              is_entry_zeroed = printk(v24, (unsigned int)v23);
              *v14 = 0;
              v14[1] = 0;
              v14[2] = 0;
              v14[3] = 0;
              v14[4] = 0;
              v14[5] = 0;
              v14[6] = 0;
              v14[7] = 0;
              v14[8] = 0;
              v14[9] = 0;
              v14[10] = 0;
              v14[11] = 0;
              v14[12] = 0;
              v14[13] = 0;
              v14[14] = 0;
              v14[15] = 0;
            }
            ++v23;
            v21 += (__int64)v48;
            if ( v23 >= (int)ipa3_get_max_pdn(is_entry_zeroed) )
              goto LABEL_51;
          }
          printk(&unk_3E92D7, "ipa3_read_pdn_table");
          v45 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v46 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v46 )
            {
              ipc_log_string(v46, "ipa %s:%d ipahal_nat_is_entry_zeroed() fail\n", "ipa3_read_pdn_table", 2507);
              v45 = ipa3_ctx;
            }
            v47 = *(_QWORD *)(v45 + 34160);
            if ( v47 )
              ipc_log_string(v47, "ipa %s:%d ipahal_nat_is_entry_zeroed() fail\n", "ipa3_read_pdn_table", 2507);
          }
        }
LABEL_52:
        kfree(v14);
      }
      else
      {
        printk(&unk_3A98CA, "ipa3_read_pdn_table");
        v11 = (_QWORD *)ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_59;
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d Out of memory\n", "ipa3_read_pdn_table", 2494);
          v11 = (_QWORD *)ipa3_ctx;
        }
        v16 = v11[4270];
        if ( !v16 )
          goto LABEL_54;
        ipc_log_string(v16, "ipa %s:%d Out of memory\n", "ipa3_read_pdn_table", 2494);
      }
    }
    v11 = (_QWORD *)ipa3_ctx;
    goto LABEL_54;
  }
  printk(&unk_3E92A2, v5);
  v17 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_84;
LABEL_80:
  v42 = *(_QWORD *)(v17 + 34152);
  if ( v42 )
  {
    ipc_log_string(v42, "ipa %s:%d Out\n", "ipa3_read_nat4", 2658);
    v17 = ipa3_ctx;
  }
  v43 = *(_QWORD *)(v17 + 34160);
  if ( v43 )
    ipc_log_string(v43, "ipa %s:%d Out\n", "ipa3_read_nat4", 2658);
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return 0;
}
