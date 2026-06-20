__int64 __fastcall ipa_mhi_read_write_host(int a1, void *a2, unsigned __int64 a3, unsigned int a4)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 dma_dev; // x0
  unsigned __int64 v11; // x24
  __int64 v12; // x19
  __int64 v13; // x0
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned __int64 v16; // x19
  unsigned int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w20
  __int64 result; // x0
  __int64 v23; // x2
  void *v24; // x0
  const void *v25; // x1
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  void *src; // [xsp+0h] [xbp-20h]
  unsigned __int64 v43; // [xsp+8h] [xbp-18h] BYREF
  __int64 v44; // [xsp+10h] [xbp-10h]
  __int64 v45; // [xsp+18h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  v44 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_read_write_host", 192);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_read_write_host", 192);
  }
  if ( !*(_DWORD *)(ipa_mhi_client_ctx + 1300) )
  {
    if ( *(_BYTE *)(ipa_mhi_client_ctx + 1305) == 1 )
    {
      v16 = (a3 - memstart_addr) | 0xFFFFFF8000000000LL;
    }
    else
    {
      if ( arm64_use_ng_mappings )
        v23 = 0x68000000000F13LL;
      else
        v23 = 0x68000000000713LL;
      v16 = ioremap_prot(a3, a4, v23);
      if ( !v16 )
      {
        printk(&unk_3BF545, "ipa_mhi_read_write_host");
        if ( ipa3_get_ipc_logbuf() )
        {
          v40 = ipa3_get_ipc_logbuf();
          ipc_log_string(v40, "ipa_mhi_client %s:%d ioremap failed for 0x%llx\n", "ipa_mhi_read_write_host", 249, a3);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v41 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v41, "ipa_mhi_client %s:%d ioremap failed for 0x%llx\n", "ipa_mhi_read_write_host", 249, a3);
        }
        goto LABEL_69;
      }
    }
    if ( a1 == 1 )
    {
      v24 = a2;
      v25 = (const void *)v16;
    }
    else
    {
      v24 = (void *)v16;
      v25 = a2;
    }
    memcpy(v24, v25, a4);
    if ( (*(_BYTE *)(ipa_mhi_client_ctx + 1305) & 1) == 0 )
      iounmap(v16);
    if ( ipa3_get_ipc_logbuf() )
    {
      v26 = ipa3_get_ipc_logbuf();
      ipc_log_string(v26, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_read_write_host", 260);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v27 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v27, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_read_write_host", 260);
      result = 0;
    }
    goto LABEL_38;
  }
  dma_dev = ipa3_get_dma_dev();
  LODWORD(v44) = a4;
  if ( *(_BYTE *)(ipa_mhi_client_ctx + 1304) )
    v11 = a3 | 0x10000000000LL;
  else
    v11 = a3;
  if ( !dma_dev )
  {
    printk(&unk_3EACAF, "ipa_mhi_read_write_host");
    if ( ipa3_get_ipc_logbuf() )
    {
      v28 = ipa3_get_ipc_logbuf();
      ipc_log_string(v28, "ipa_mhi_client %s:%d platform dev is not valid", "ipa_mhi_read_write_host", 203);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v29 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v29, "ipa_mhi_client %s:%d platform dev is not valid", "ipa_mhi_read_write_host", 203);
      result = 4294967282LL;
      goto LABEL_38;
    }
LABEL_69:
    result = 4294967282LL;
    goto LABEL_38;
  }
  v12 = dma_dev;
  v13 = dma_alloc_attrs(dma_dev, a4, &v43, 3264, 0);
  src = (void *)v13;
  if ( v13 )
  {
    v14 = ipa_dma_enable(v13);
    if ( v14 )
    {
      v21 = v14;
      printk(&unk_3B97AC, "ipa_mhi_read_write_host");
      if ( ipa3_get_ipc_logbuf() )
      {
        v32 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v32,
          "ipa_mhi_client %s:%d failed to enable IPA DMA rc=%d\n",
          "ipa_mhi_read_write_host",
          215,
          v21);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v33 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v33,
          "ipa_mhi_client %s:%d failed to enable IPA DMA rc=%d\n",
          "ipa_mhi_read_write_host",
          215,
          v21);
      }
      goto LABEL_24;
    }
    if ( a1 == 1 )
    {
      v15 = ipa_dma_sync_memcpy(v43, v11, a4);
      if ( v15 )
      {
        v21 = v15;
        printk(&unk_3FF74B, "ipa_mhi_read_write_host");
        if ( ipa3_get_ipc_logbuf() )
        {
          v36 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v36,
            "ipa_mhi_client %s:%d ipa_dma_sync_memcpy from host fail%d\n",
            "ipa_mhi_read_write_host",
            225,
            v21);
        }
        v19 = ipa3_get_ipc_logbuf_low();
        if ( v19 )
        {
          v37 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v37,
            "ipa_mhi_client %s:%d ipa_dma_sync_memcpy from host fail%d\n",
            "ipa_mhi_read_write_host",
            225,
            v21);
        }
        goto LABEL_23;
      }
      memcpy(a2, src, a4);
    }
    else
    {
      memcpy(src, a2, a4);
      v17 = ipa_dma_sync_memcpy(v11, v43, a4);
      if ( v17 )
      {
        v21 = v17;
        printk(&unk_3C5914, "ipa_mhi_read_write_host");
        if ( ipa3_get_ipc_logbuf() )
        {
          v38 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v38,
            "ipa_mhi_client %s:%d ipa_dma_sync_memcpy to host fail %d\n",
            "ipa_mhi_read_write_host",
            236,
            v21);
        }
        v19 = ipa3_get_ipc_logbuf_low();
        if ( v19 )
        {
          v39 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v39,
            "ipa_mhi_client %s:%d ipa_dma_sync_memcpy to host fail %d\n",
            "ipa_mhi_read_write_host",
            236,
            v21);
        }
        goto LABEL_23;
      }
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(v18, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_read_write_host", 264);
    }
    v19 = ipa3_get_ipc_logbuf_low();
    if ( v19 )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_read_write_host", 264);
    }
    v21 = 0;
LABEL_23:
    if ( (unsigned int)ipa_dma_disable(v19) )
    {
      printk(&unk_3B0F7A, "ipa_mhi_read_write_host");
      if ( ipa3_get_ipc_logbuf() )
      {
        v34 = ipa3_get_ipc_logbuf();
        ipc_log_string(v34, "ipa_mhi_client %s:%d failed to disable IPA DMA\n", "ipa_mhi_read_write_host", 268);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v35 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v35, "ipa_mhi_client %s:%d failed to disable IPA DMA\n", "ipa_mhi_read_write_host", 268);
      }
    }
LABEL_24:
    dma_free_attrs(v12, (unsigned int)v44, src, v43, 0);
    result = v21;
    goto LABEL_38;
  }
  printk(&unk_3AE2BB, "ipa_mhi_read_write_host");
  if ( ipa3_get_ipc_logbuf() )
  {
    v30 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v30,
      "ipa_mhi_client %s:%d dma_alloc_coherent failed, DMA buff size %d\n",
      "ipa_mhi_read_write_host",
      209,
      v44);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v31 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v31,
      "ipa_mhi_client %s:%d dma_alloc_coherent failed, DMA buff size %d\n",
      "ipa_mhi_read_write_host",
      209,
      v44);
  }
  result = 4294967284LL;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
