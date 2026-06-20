__int64 __fastcall rdbg_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w21
  _BYTE *v4; // x22
  char *v5; // x24
  size_t v6; // x20
  _QWORD *v7; // x23
  _QWORD *v8; // x25
  __int64 v9; // x8
  unsigned int v10; // w22
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x9
  int v14; // w0
  const char *v15; // x1
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x8
  size_t v20; // x8
  __int64 v21; // x9
  void *v22; // x0
  __int64 v23; // x8
  _DWORD *v24; // x8
  int v25; // w8
  char *v26; // x8
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x11
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x10
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x8
  __int64 v33; // x9
  _DWORD *v34; // x9
  int v35; // w8
  unsigned int v37; // w19
  unsigned __int64 StatusReg; // x25
  __int64 v39; // x26
  int v40; // w8
  int v41; // w8

  if ( !a1 || (v5 = (char *)&unk_0, !qword_108) )
  {
    printk(&unk_76C8);
    return 4294967277LL;
  }
  v6 = *(_DWORD *)(a1 + 76) & 0xFFFFF;
  v7 = (_QWORD *)(qword_108 + 456LL * (unsigned int)v6);
  if ( *((_BYTE *)v7 + 96) == 1 )
  {
    dev_err(*v7, "%s: Device already opened\n", "rdbg_open");
    return 4294967279LL;
  }
  if ( (unsigned int)v6 >= 0x10 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v39 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &smq_blockmap_ctor__alloc_tag;
    v22 = (void *)_kmalloc_noprof(v6, 3520);
    *(_QWORD *)(StatusReg + 80) = v39;
    v7[23] = v22;
    if ( v22 )
      goto LABEL_20;
LABEL_44:
    v15 = "%s: smq producer allocation failed\n";
    goto LABEL_45;
  }
  v8 = (_QWORD *)((char *)&proc_info + 24 * (unsigned int)v6);
  v9 = v8[2];
  v7[14] = v9;
  if ( !v9 )
  {
    dev_err(*v7, "%s: smem not initialized\n", "rdbg_open");
    return 4294967284LL;
  }
  v10 = *((_DWORD *)v8 + 2);
  v2 = a2;
  v11 = qcom_smem_get(0xFFFFFFFFLL, v10, v7 + 14);
  v7[13] = v11;
  if ( v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_76E4);
    v11 = v7[13];
    if ( v11 == -2 )
    {
      v11 = qcom_smem_get((unsigned int)v6, v10, v7 + 14);
      v7[13] = v11;
    }
  }
  if ( !v11 )
  {
    dev_err(*v7, "%s: Could not allocate smem memory\n", "rdbg_open");
    printk(&unk_768C);
    return 4294967284LL;
  }
  v12 = (v11 + 9) & 0xFFFFFFFFFFFFFFF8LL;
  v13 = ((int)(v11 - v12 + (v7[14] >> 1)) - 32LL) / 0x88uLL;
  if ( (int)v13 < 1 )
  {
LABEL_40:
    dev_err(*v7, "%s: Subsystem %s is not debug enabled\n", "rdbg_open", (const char *)*v8);
    printk(&unk_7A61);
    return 4294967226LL;
  }
  v3 = -16711936;
  if ( *(_DWORD *)(v12 + (int)((_DWORD)v13 << 7) + 4 * (v13 & 0x7FFFFFFF) + 16) != -16711934 )
  {
    printk(&unk_789F);
    goto LABEL_40;
  }
  *((_DWORD *)v7 + 2) = 0;
  _init_swait_queue_head(v7 + 2, "&x->wait", &init_completion___key);
  v14 = request_threaded_irq(
          *((unsigned int *)v7 + 11),
          0,
          on_interrupt_from,
          8195,
          *v8,
          qword_108 + 456LL * (unsigned int)v6);
  if ( v14 )
  {
    v37 = v14;
    dev_err(*v7, "%s: Failed to register interrupt.Err=%d,irqid=%d.\n", "rdbg_open", v14, *((_DWORD *)v7 + 11));
    printk(&unk_77D7);
    return v37;
  }
  _mutex_init(v7 + 35, "&rdbgdata->write_mutex", &rdbg_open___key);
  if ( *((_DWORD *)v7 + 42) == -16711936 )
    goto LABEL_44;
  v4 = (_BYTE *)v7[13];
  v15 = "%s: smq producer allocation failed\n";
  if ( !v4 )
    goto LABEL_45;
  v16 = v7[14];
  if ( (v16 & 0x1FFFFFFFELL) == 0 )
    goto LABEL_45;
  v5 = (char *)(v16 >> 1);
  v17 = (unsigned __int64)(v4 + 9) & 0xFFFFFFFFFFFFFFF8LL;
  v7[20] = v7 + 35;
  v7[15] = v4;
  v18 = ((int)v5 + (int)v4 - (int)v17 - 32LL) / 0x88uLL;
  if ( (int)v18 < 1 )
    goto LABEL_45;
  v7[18] = v17;
  *((_DWORD *)v7 + 38) = v18;
  v19 = v17 + (int)((_DWORD)v18 << 7);
  *((_DWORD *)v7 + 48) = 1;
  v7[16] = v19;
  v7[17] = v19 + 4 * (v18 & 0x7FFFFFFF) + 16;
  *v4 = 1;
  if ( !*((_DWORD *)v7 + 38) )
    goto LABEL_45;
  v20 = 0;
  v21 = 16;
  do
  {
    ++v20;
    *(_WORD *)(v7[16] + v21) = -1;
    v21 += 4;
    v6 = *((unsigned int *)v7 + 38);
  }
  while ( v20 < v6 );
  if ( (unsigned int)v6 < 2 )
    goto LABEL_44;
  v22 = (void *)_kmalloc_noprof(*((unsigned int *)v7 + 38), 3520);
  v7[23] = v22;
  if ( !v22 )
    goto LABEL_44;
LABEL_20:
  *((_DWORD *)v7 + 45) = v6 - 1;
  memset(v22, 0, v6);
  v23 = v7[16];
  *((_DWORD *)v7 + 44) = 0;
  *(_DWORD *)(v23 + 8) = 0;
  *(_DWORD *)(v7[16] + 12LL) = 0;
  v24 = (_DWORD *)v7[16];
  if ( *v24 == v3 + 1 )
  {
    ++v24[1];
  }
  else
  {
    v24[1] = 1;
    *(_DWORD *)v7[16] = v3 + 1;
  }
  v25 = *((_DWORD *)v7 + 62);
  *((_DWORD *)v7 + 42) = v3;
  if ( v25 == v3 )
  {
    dev_err(*v7, "%s: smq consumer allocation failed\n", "initialize_smq");
LABEL_46:
    dev_err(*v7, "Error initializing smq. Err=%d\n", -12);
    printk(&unk_7AD2);
    if ( *((_DWORD *)v7 + 42) == v3 )
    {
      v40 = *((_DWORD *)v7 + 48);
      if ( v40 == 2 )
      {
        *(_DWORD *)v7[17] = 0;
      }
      else if ( v40 == 1 )
      {
        *(_DWORD *)v7[16] = 0;
        kfree(v7[23]);
        v7[23] = 0;
      }
      *((_DWORD *)v7 + 42) = 0;
    }
    if ( *((_DWORD *)v7 + 62) == v3 )
    {
      v41 = *((_DWORD *)v7 + 68);
      if ( v41 == 2 )
      {
        *(_DWORD *)v7[27] = 0;
      }
      else if ( v41 == 1 )
      {
        *(_DWORD *)v7[26] = 0;
        kfree(v7[33]);
        v7[33] = 0;
      }
      *((_DWORD *)v7 + 62) = 0;
    }
    return 4294967284LL;
  }
  v26 = &v5[(_QWORD)v4];
  v15 = "%s: smq consumer allocation failed\n";
  if ( !&v5[(_QWORD)v4]
    || (v27 = v7[14], (v27 & 0x1FFFFFFFELL) == 0)
    || (v28 = v27 >> 1,
        v7[25] = v26,
        v29 = (unsigned __int64)(v26 + 9) & 0xFFFFFFFFFFFFFFF8LL,
        v30 = ((int)v26 - (int)v29 + (int)v28 - 32LL) / 0x88uLL,
        (int)v30 < 1) )
  {
LABEL_45:
    dev_err(*v7, v15, "initialize_smq");
    goto LABEL_46;
  }
  v7[28] = v29;
  *((_DWORD *)v7 + 58) = v30;
  v31 = v29 + (int)((_DWORD)v30 << 7);
  *((_DWORD *)v7 + 68) = 2;
  v7[26] = v31;
  v7[27] = v31 + 4 * (v30 & 0x7FFFFFFF) + 16;
  v26[1] = 1;
  if ( *((_DWORD *)v7 + 58) )
  {
    v32 = 0;
    v33 = 16;
    do
    {
      ++v32;
      *(_WORD *)(v7[27] + v33) = -1;
      v33 += 4;
    }
    while ( v32 < *((unsigned int *)v7 + 58) );
  }
  *(_DWORD *)(v7[27] + 8LL) = 0;
  *(_DWORD *)(v7[27] + 12LL) = 0;
  v34 = (_DWORD *)v7[26];
  v35 = 0;
  if ( *v34 == v3 + 1 )
    v35 = v34[1];
  *(_DWORD *)(v7[27] + 4LL) = v35;
  *(_DWORD *)v7[27] = v3 + 2;
  *((_DWORD *)v7 + 62) = v3;
  *((_BYTE *)v7 + 96) = 1;
  *(_QWORD *)(v2 + 32) = v7;
  return 0;
}
