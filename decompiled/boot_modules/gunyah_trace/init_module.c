__int64 init_module()
{
  _QWORD *info; // x0
  __int64 v1; // x2
  __int64 v2; // x3
  _QWORD *v3; // x19
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 parent; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  unsigned int v12; // w1
  int v13; // w8
  int v14; // w9
  __int64 v15; // x2
  __int64 v16; // x3
  unsigned int v17; // w0
  __int64 v18; // x2
  __int64 v19; // x3
  unsigned int *v20; // x1
  __int64 v21; // x20
  unsigned __int64 v22; // x9
  unsigned int *v23; // x8
  __int64 v24; // x10
  __int64 v25; // x9
  int v26; // w13
  __int64 v27; // x11
  unsigned __int64 dir; // x0
  __int64 v29; // x1
  unsigned __int64 v30; // x2
  __int64 v31; // x3
  unsigned __int64 file; // x0
  unsigned __int64 v33; // x0
  unsigned __int64 v34; // x0
  unsigned int v35; // w20
  __int64 v36; // x1
  __int64 v37; // x2
  __int64 v38; // x3
  __int64 v40; // [xsp+0h] [xbp-60h] BYREF
  _QWORD s[11]; // [xsp+8h] [xbp-58h] BYREF

  s[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  memset(s, 0, 0x50u);
  info = (_QWORD *)gunyah_get_info(2, 1, &v40);
  v3 = info;
  if ( (unsigned __int64)info >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_790E, (unsigned int)info, v1, v2);
    v35 = 0;
    goto LABEL_54;
  }
  if ( v40 != 32 )
  {
    printk(&unk_7899, v40, 32, v2);
    v35 = -22;
    goto LABEL_54;
  }
  v4 = info[1];
  qword_7DD8 = v4;
  v5 = *info;
  if ( (unsigned int)pfn_is_map_memory(*info >> 12) )
  {
    gunyah_trace_data = (v5 - memstart_addr) | 0xFFFFFF8000000000LL;
  }
  else
  {
    if ( arm64_use_ng_mappings )
      v6 = 0x68000000000F03LL;
    else
      v6 = 0x68000000000703LL;
    gunyah_trace_data = ioremap_prot(v5, v4, v6);
    if ( !gunyah_trace_data )
    {
      printk(&unk_779B, *v3, qword_7DD8, v7);
      v35 = -6;
      goto LABEL_54;
    }
  }
  parent = of_irq_find_parent(of_root);
  if ( !parent )
  {
    printk(&unk_7851, v9, v10, v11);
LABEL_42:
    v35 = -19;
    goto LABEL_53;
  }
  qword_7E10 = parent + 24;
  v12 = *((_DWORD *)v3 + 5);
  s[0] = parent + 24;
  if ( v12 <= 0x1F )
    goto LABEL_46;
  if ( v12 < 0x3FC )
  {
    v13 = 0;
    v14 = -32;
    goto LABEL_16;
  }
  if ( v12 <= 0xFFF || v12 >> 10 >= 5 )
  {
LABEL_46:
    _warn_printk("Unexpected virq: %d\n", v12);
    __break(0x800u);
    v35 = -22;
    printk(&unk_7941, 4294967274LL, v37, v38);
    goto LABEL_53;
  }
  v14 = -4096;
  v13 = 2;
LABEL_16:
  LODWORD(s[1]) = 3;
  HIDWORD(s[1]) = v13;
  LODWORD(s[2]) = v12 + v14;
  HIDWORD(s[2]) = 1;
  dword_7DE0 = irq_create_fwspec_mapping(s);
  if ( dword_7DE0 < 0 )
  {
    printk(&unk_78DA, 0, v15, v16);
    v35 = 0;
    goto LABEL_53;
  }
  v17 = request_threaded_irq();
  if ( v17 )
  {
    printk(&unk_7585, (unsigned int)dword_7DE0, v17, v19);
    goto LABEL_42;
  }
  v20 = (unsigned int *)gunyah_trace_data;
  LODWORD(v21) = 0;
  v22 = gunyah_trace_data + qword_7DD8;
  do
  {
    if ( *v20 != 1179992630 )
    {
      printk(&unk_7974, *v20, v18, v19);
LABEL_45:
      v36 = 4294967274LL;
LABEL_51:
      printk(&unk_7635, v36, v18, v19);
      v35 = -22;
      goto LABEL_52;
    }
    v23 = &v20[16 * v20[1]];
    v20 = v23 + 16;
    if ( (unsigned __int64)(v23 + 16) > v22 )
    {
      printk(&unk_775B, v20, v18, v19);
      goto LABEL_45;
    }
    v21 = (unsigned int)(v21 + 1);
  }
  while ( (unsigned __int64)(v23 + 16) < v22 );
  if ( (v21 & 0x80000000) != 0 )
  {
    qword_7E38 = 0;
    goto LABEL_50;
  }
  qword_7E38 = _kmalloc_noprof(32LL * (unsigned int)v21, 3264);
  if ( !qword_7E38 )
  {
LABEL_50:
    v36 = 4294967284LL;
    goto LABEL_51;
  }
  word_7E0C = v21;
  if ( (unsigned int)(v21 - 1) <= 0x7FFFFFFE )
  {
    v24 = gunyah_trace_data;
    v25 = 0;
    do
    {
      --v21;
      *(_QWORD *)(qword_7E38 + v25 + 8) = v24;
      *(_QWORD *)(qword_7E38 + v25) = v24 + 64;
      v26 = *(_DWORD *)(v24 + 4);
      *(_DWORD *)(qword_7E38 + v25 + 24) = v26;
      v27 = qword_7E38 + v25;
      v25 += 32;
      *(_QWORD *)(v27 + 16) = (unsigned int)(v26 << 6);
      v24 += 64LL + (unsigned int)(*(_DWORD *)(v24 + 4) << 6);
    }
    while ( v21 );
  }
  _init_waitqueue_head(&unk_7DF0, "&gunyah_trace_data.poll_waiters", &gunyah_trace_init___key);
  dir = debugfs_create_dir("gunyah_trace", 0);
  qword_7E18 = dir;
  if ( dir )
  {
    v30 = dir;
    if ( dir <= 0xFFFFFFFFFFFFF000LL )
    {
      file = debugfs_create_file("trace", 288, dir, &gunyah_trace_data, &gunyah_trace_debugfs_fops);
      qword_7E20 = file;
      if ( file )
      {
        if ( file <= 0xFFFFFFFFFFFFF000LL )
        {
          v33 = debugfs_create_file("set_event", 416, qword_7E18, &gunyah_trace_data, &set_event_debugfs_fops);
          qword_7E28 = v33;
          if ( v33 )
          {
            if ( v33 <= 0xFFFFFFFFFFFFF000LL )
            {
              v34 = debugfs_create_file("available_event", 288, qword_7E18, &gunyah_trace_data, &available_debugfs_fops);
              qword_7E30 = v34;
              if ( v34 )
              {
                if ( v34 < 0xFFFFFFFFFFFFF001LL )
                {
                  v35 = 0;
                  dword_7E08 = 0;
                  goto LABEL_54;
                }
              }
            }
          }
        }
      }
    }
  }
  printk(&unk_75FD, v29, v30, v31);
  debugfs_remove(qword_7E18);
  kfree(qword_7E38);
  v35 = -2;
LABEL_52:
  free_irq((unsigned int)dword_7DE0, &gunyah_trace_data);
LABEL_53:
  iounmap(gunyah_trace_data);
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v35;
}
