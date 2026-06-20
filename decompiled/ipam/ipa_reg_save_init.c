__int64 __fastcall ipa_reg_save_init(int c)
{
  __int64 v1; // x22
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x0
  __int64 v7; // x8
  void *v8; // x0
  __int64 v9; // x20
  void *v10; // x0
  __int64 v11; // x20
  __int64 *v12; // x0
  __int64 v13; // x8
  void *v14; // x0
  __int64 v15; // x20
  void *v16; // x0
  __int64 v17; // x20
  void *v18; // x0
  __int64 v19; // x20
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0

  v1 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + 44860) == 1 )
  {
    memset(ipa_reg_save, c, 0x58D0u);
    qword_207070 = 0;
    if ( *(_BYTE *)(ipa3_ctx + 44861) == 1 )
    {
      memset(&ipa_testbus_mem, c, 0x198000u);
      qword_207070 = (__int64)&ipa_testbus_mem;
    }
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(
          v3,
          "ipa %s:%d Mapping 0x%x bytes starting at 0x%x\n",
          "ipa_reg_save_init",
          1759,
          *(_DWORD *)(ipa3_ctx + 44856),
          *(_DWORD *)(ipa3_ctx + 28640));
        v1 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v1 + 34160);
      if ( v4 )
      {
        ipc_log_string(
          v4,
          "ipa %s:%d Mapping 0x%x bytes starting at 0x%x\n",
          "ipa_reg_save_init",
          1759,
          *(_DWORD *)(v1 + 44856),
          *(_DWORD *)(v1 + 28640));
        v1 = ipa3_ctx;
      }
    }
    if ( arm64_use_ng_mappings )
      v5 = 0x68000000000F13LL;
    else
      v5 = 0x68000000000713LL;
    v6 = ioremap_prot(*(unsigned int *)(v1 + 28640), *(unsigned int *)(v1 + 44856), v5);
    v7 = ipa3_ctx + 40960;
    *(_QWORD *)(ipa3_ctx + 44872) = v6;
    if ( !v6 )
    {
      printk(&unk_3E5668, "ipa_reg_save_init");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d :register collection ioremap err\n", "ipa_reg_save_init", 1766);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d :register collection ioremap err\n", "ipa_reg_save_init", 1766);
      }
      return 4294967284LL;
    }
    qword_207E68 = 0;
    qword_207E70 = 0;
    qword_207E58 = 0;
    qword_207E60 = 0;
    qword_207E48 = 0;
    qword_207E50 = 0;
    if ( *(_BYTE *)(v7 + 3903) == 1 )
    {
      v8 = (void *)_kmalloc_large_noprof(40704, 3264);
      v9 = (__int64)v8;
      if ( v8 )
      {
        memset(v8, c, 0x9F00u);
        qword_207E48 = v9;
        v10 = (void *)_kmalloc_large_noprof(19232, 3264);
        v11 = (__int64)v10;
        if ( v10 )
        {
          memset(v10, c, 0x4B20u);
          qword_207E50 = v11;
          v12 = (__int64 *)_kmalloc_cache_noprof(raw_spin_lock_irqsave, 3264, 256);
          if ( v12 )
          {
            v13 = 0x101010101010101LL * (unsigned __int8)c;
            v12[30] = v13;
            v12[31] = v13;
            v12[28] = v13;
            v12[29] = v13;
            v12[26] = v13;
            v12[27] = v13;
            v12[24] = v13;
            v12[25] = v13;
            v12[22] = v13;
            v12[23] = v13;
            v12[20] = v13;
            v12[21] = v13;
            v12[18] = v13;
            v12[19] = v13;
            v12[16] = v13;
            v12[17] = v13;
            v12[14] = v13;
            v12[15] = v13;
            v12[12] = v13;
            v12[13] = v13;
            v12[10] = v13;
            v12[11] = v13;
            v12[8] = v13;
            v12[9] = v13;
            v12[6] = v13;
            v12[7] = v13;
            v12[4] = v13;
            v12[5] = v13;
            v12[2] = v13;
            v12[3] = v13;
            *v12 = v13;
            v12[1] = v13;
            qword_207E58 = (__int64)v12;
            v14 = (void *)_kmalloc_large_noprof(47536, 3264);
            v15 = (__int64)v14;
            if ( v14 )
            {
              memset(v14, c, 0xB9B0u);
              qword_207E60 = v15;
              v16 = (void *)_kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3264, 768);
              v17 = (__int64)v16;
              if ( v16 )
              {
                memset(v16, c, 0x300u);
                qword_207E68 = v17;
                v18 = (void *)_kmalloc_cache_noprof(dma_free_attrs, 3264, 5376);
                v19 = (__int64)v18;
                if ( v18 )
                {
                  memset(v18, c, 0x1500u);
                  qword_207E70 = v19;
                  return 0;
                }
                qword_207E70 = 0;
                printk(&unk_3FD2A3, "ipa_reg_save_init");
                v39 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v40 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v40 )
                  {
                    ipc_log_string(v40, "ipa %s:%d ipa_gsi_ptr memory alloc failed\n", "ipa_reg_save_init", 1826);
                    v39 = ipa3_ctx;
                  }
                  v41 = *(_QWORD *)(v39 + 34160);
                  if ( v41 )
                    ipc_log_string(v41, "ipa %s:%d ipa_gsi_ptr memory alloc failed\n", "ipa_reg_save_init", 1826);
                }
              }
              else
              {
                qword_207E68 = 0;
                printk(&unk_3B1534, "ipa_reg_save_init");
                v36 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v37 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v37 )
                  {
                    ipc_log_string(v37, "ipa %s:%d ipa_seq_ptr memory alloc failed\n", "ipa_reg_save_init", 1819);
                    v36 = ipa3_ctx;
                  }
                  v38 = *(_QWORD *)(v36 + 34160);
                  if ( v38 )
                    ipc_log_string(v38, "ipa %s:%d ipa_seq_ptr memory alloc failed\n", "ipa_reg_save_init", 1819);
                }
              }
            }
            else
            {
              qword_207E60 = 0;
              printk(&unk_3FD275, "ipa_reg_save_init");
              v33 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v34 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v34 )
                {
                  ipc_log_string(v34, "ipa %s:%d ipa_hram_ptr memory alloc failed\n", "ipa_reg_save_init", 1812);
                  v33 = ipa3_ctx;
                }
                v35 = *(_QWORD *)(v33 + 34160);
                if ( v35 )
                  ipc_log_string(v35, "ipa %s:%d ipa_hram_ptr memory alloc failed\n", "ipa_reg_save_init", 1812);
              }
            }
          }
          else
          {
            qword_207E58 = 0;
            printk(&unk_3DD71C, "ipa_reg_save_init");
            v30 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v31 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v31 )
              {
                ipc_log_string(v31, "ipa %s:%d ipa_mbox_ptr memory alloc failed\n", "ipa_reg_save_init", 1805);
                v30 = ipa3_ctx;
              }
              v32 = *(_QWORD *)(v30 + 34160);
              if ( v32 )
                ipc_log_string(v32, "ipa %s:%d ipa_mbox_ptr memory alloc failed\n", "ipa_reg_save_init", 1805);
            }
          }
        }
        else
        {
          qword_207E50 = 0;
          printk(&unk_3E2BA8, "ipa_reg_save_init");
          v27 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v28 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v28 )
            {
              ipc_log_string(v28, "ipa %s:%d ipa_sram_ptr memory alloc failed\n", "ipa_reg_save_init", 1798);
              v27 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v27 + 34160);
            if ( v29 )
              ipc_log_string(v29, "ipa %s:%d ipa_sram_ptr memory alloc failed\n", "ipa_reg_save_init", 1798);
          }
        }
      }
      else
      {
        qword_207E48 = 0;
        printk(&unk_3E2B7C, "ipa_reg_save_init");
        v24 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v25 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v25 )
          {
            ipc_log_string(v25, "ipa %s:%d ipa_iu_ptr memory alloc failed\n", "ipa_reg_save_init", 1791);
            v24 = ipa3_ctx;
          }
          v26 = *(_QWORD *)(v24 + 34160);
          if ( v26 )
            ipc_log_string(v26, "ipa %s:%d ipa_iu_ptr memory alloc failed\n", "ipa_reg_save_init", 1791);
        }
      }
      kfree(qword_207E68);
      kfree(qword_207E60);
      kfree(qword_207E58);
      kfree(qword_207E50);
      kfree(qword_207E48);
      iounmap(*(_QWORD *)(ipa3_ctx + 44872));
      return 4294967284LL;
    }
  }
  return 0;
}
