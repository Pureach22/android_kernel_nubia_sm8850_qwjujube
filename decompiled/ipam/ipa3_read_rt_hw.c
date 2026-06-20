__int64 __fastcall ipa3_read_rt_hw(__int64 a1)
{
  unsigned int v1; // w20
  __int64 v2; // x9
  const char *v3; // x28
  __int64 v4; // x8
  int v5; // w21
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x19
  char *v9; // x27
  const char *v10; // x26
  unsigned int v11; // w22
  void *v12; // x0
  __int64 v13; // x1
  __int64 v14; // x24
  unsigned __int64 v15; // x23
  unsigned __int64 v16; // x25
  __int64 v17; // x24
  unsigned __int64 v18; // x23
  unsigned __int64 v19; // x25
  unsigned int v20; // w21
  const char *v21; // x22
  char *v22; // x26
  unsigned __int64 v23; // x27
  int v24; // w24
  _QWORD *v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 result; // x0
  _QWORD *v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  _QWORD *v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  _QWORD *v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  int v44; // [xsp+4h] [xbp-2Ch]
  int v45; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+28h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 32);
  v45 = 0;
  if ( v1 )
  {
    if ( v1 != 1 )
    {
      printk(&unk_3EEB0B, "ipa3_read_rt_hw");
      v32 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_79;
      v33 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d ip type error %d\n", "ipa3_read_rt_hw", 1192, v1);
        v32 = ipa3_ctx;
      }
      v34 = *(_QWORD *)(v32 + 34160);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d ip type error %d\n", "ipa3_read_rt_hw", 1192, v1);
        result = -22;
      }
      else
      {
LABEL_79:
        result = -22;
      }
      goto LABEL_65;
    }
    v2 = 96;
  }
  else
  {
    v2 = 52;
  }
  v3 = (const char *)&off_1F7000;
  v4 = ipa3_ctx;
  v5 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + v2);
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Tring to parse %d H/W routing tables - IP=%d\n", "ipa3_read_rt_hw", 1196, v5, v1);
      v4 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v4 + 34160);
    if ( v7 )
      ipc_log_string(v7, "ipa %s:%d Tring to parse %d H/W routing tables - IP=%d\n", "ipa3_read_rt_hw", 1196, v5, v1);
  }
  v8 = _kmalloc_large_noprof(28672, 3520);
  if ( !v8 )
  {
    printk(&unk_3E0A3D, "ipa3_read_rt_hw");
    v41 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v42 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v42 )
      {
        ipc_log_string(v42, "ipa %s:%d failed to allocate mem for tbl rules\n", "ipa3_read_rt_hw", 1200);
        v41 = ipa3_ctx;
      }
      v43 = *(_QWORD *)(v41 + 34160);
      if ( v43 )
        ipc_log_string(v43, "ipa %s:%d failed to allocate mem for tbl rules\n", "ipa3_read_rt_hw", 1200);
    }
    result = -12;
    goto LABEL_65;
  }
  v9 = "ipa_debugfs.c";
  v10 = "ipa3_read_rt_hw";
  ipa3_inc_client_enable_clks();
  mutex_lock(ipa3_ctx + 29472);
  if ( v5 < 1 )
  {
    v24 = 0;
    goto LABEL_64;
  }
  v11 = 0;
  while ( 1 )
  {
    printk(&unk_3C9739, v11);
    v45 = 128;
    LODWORD(v12) = ipa3_rt_read_tbl_from_hw(v11, v1, 1, v8, &v45);
    if ( (_DWORD)v12 )
    {
      v24 = (int)v12;
      printk(&unk_3F4CB7, v13);
      printk(&unk_3A97DF, "ipa3_read_rt_hw");
      v35 = *((_QWORD **)v3 + 257);
      if ( v35 )
      {
        v36 = v35[4269];
        if ( v36 )
        {
          ipc_log_string(v36, "ipa %s:%d failed reading tbl from hw\n", "ipa3_read_rt_hw", 1214);
          v35 = *((_QWORD **)v3 + 257);
        }
        v37 = v35[4270];
        if ( v37 )
          ipc_log_string(v37, "ipa %s:%d failed reading tbl from hw\n", "ipa3_read_rt_hw", 1214);
      }
      goto LABEL_64;
    }
    if ( !v45 )
    {
      LODWORD(v12) = printk(&unk_3EEB29, v13);
      if ( v45 < 1 )
        goto LABEL_33;
LABEL_16:
      v14 = 0;
      v15 = 20;
      while ( 1 )
      {
        v16 = v15 - 20;
        if ( (v15 - 20) >> 12 > 6 || v15 - 16 > 0x7000 )
          goto LABEL_87;
        LODWORD(v12) = printk(&unk_3AF416, (unsigned int)v14);
        if ( *(_DWORD *)(*((_QWORD *)v3 + 257) + 32240LL) >= 0x15u )
        {
          if ( v15 + 9 > 0x7000 )
            goto LABEL_87;
          LODWORD(v12) = printk(&unk_3FAD90, *(unsigned __int8 *)(v8 + v15 + 9));
        }
        if ( v15 - 8 > 0x7000 )
          goto LABEL_87;
        if ( *(_DWORD *)(v8 + v15 - 8) == 2 )
        {
          v12 = &unk_3C0957;
          if ( v16 > 0x6FDC )
            goto LABEL_87;
        }
        else
        {
          v12 = &unk_3D8243;
          if ( v16 > 0x6FDC )
            goto LABEL_87;
        }
        LODWORD(v12) = printk(v12, *(unsigned int *)(v8 + v15 - 12));
        if ( v15 + 4 > 0x7000 || v15 + 8 > 0x7000 || v15 - 4 > 0x7000 || v15 > 0x7000 )
          goto LABEL_87;
        printk(&unk_3B4A28, *(unsigned int *)(v8 + v15 + 4));
        LODWORD(v12) = ipa3_attrib_dump_eq(v8 + v15 + 16);
        if ( (_DWORD)v12 )
          break;
        ++v14;
        v15 += 224LL;
        if ( v14 >= v45 )
          goto LABEL_33;
      }
      if ( (unsigned int)__ratelimit(&ipa3_read_rt_hw__rs, "ipa3_read_rt_hw") )
      {
        printk(&unk_3B1E01, "ipa3_read_rt_hw");
        v25 = *((_QWORD **)v3 + 257);
        if ( v25 )
          goto LABEL_58;
      }
      else
      {
        v25 = *((_QWORD **)v3 + 257);
        if ( v25 )
        {
LABEL_58:
          v26 = v25[4269];
          if ( v26 )
          {
            ipc_log_string(v26, "ipa %s:%d failed read attrib eq\n", "ipa3_read_rt_hw", 1242);
            v25 = *((_QWORD **)v3 + 257);
          }
          v27 = v25[4270];
          if ( v27 )
            ipc_log_string(v27, "ipa %s:%d failed read attrib eq\n", "ipa3_read_rt_hw", 1242);
        }
      }
LABEL_62:
      v24 = -1;
      goto LABEL_64;
    }
    if ( v45 >= 1 )
      goto LABEL_16;
LABEL_33:
    printk(&unk_3FD962, v11);
    v45 = 128;
    LODWORD(v12) = ipa3_rt_read_tbl_from_hw(v11, v1, 0, v8, &v45);
    if ( (_DWORD)v12 )
      goto LABEL_88;
    v44 = v5;
    if ( v45 )
    {
      if ( v45 >= 1 )
        break;
      goto LABEL_50;
    }
    LODWORD(v12) = printk(&unk_3EEB29, v13);
    if ( v45 >= 1 )
      break;
LABEL_50:
    printk(&unk_3C36C1, v13);
    v5 = v44;
    ++v11;
    v24 = 0;
    if ( v11 == v44 )
      goto LABEL_64;
  }
  v17 = 0;
  v18 = 20;
  while ( 1 )
  {
    v19 = v18 - 20;
    if ( (v18 - 20) >> 12 > 6 )
      break;
    if ( v18 - 16 > 0x7000 )
      break;
    v20 = v11;
    v21 = v3;
    v3 = v10;
    v22 = v9;
    v23 = v8 + v18;
    LODWORD(v12) = printk(&unk_3AF416, (unsigned int)v17);
    if ( v18 - 8 > 0x7000 )
      break;
    if ( *(_DWORD *)(v23 - 8) == 2 )
    {
      v12 = &unk_3C0957;
      if ( v19 > 0x6FDC )
        break;
    }
    else
    {
      v12 = &unk_3D8243;
      if ( v19 > 0x6FDC )
        break;
    }
    LODWORD(v12) = printk(v12, *(unsigned int *)(v23 - 12));
    if ( v18 + 4 > 0x7000 || v18 + 8 > 0x7000 || v18 - 4 > 0x7000 || v18 > 0x7000 )
      break;
    v9 = v22;
    v10 = v3;
    v3 = v21;
    printk(&unk_3B4A28, *(unsigned int *)(v8 + v18 + 4));
    LODWORD(v12) = ipa3_attrib_dump_eq(v8 + v18 + 16);
    if ( (_DWORD)v12 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_read_rt_hw__rs_271, "ipa3_read_rt_hw") )
      {
        printk(&unk_3B1E01, "ipa3_read_rt_hw");
        v29 = *((_QWORD **)v21 + 257);
        if ( !v29 )
          goto LABEL_62;
      }
      else
      {
        v29 = *((_QWORD **)v21 + 257);
        if ( !v29 )
          goto LABEL_62;
      }
      v30 = v29[4269];
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d failed read attrib eq\n", "ipa3_read_rt_hw", 1277);
        v29 = *((_QWORD **)v21 + 257);
      }
      v31 = v29[4270];
      if ( v31 )
        ipc_log_string(v31, "ipa %s:%d failed read attrib eq\n", "ipa3_read_rt_hw", 1277);
      goto LABEL_62;
    }
    ++v17;
    v11 = v20;
    v18 += 224LL;
    if ( v17 >= v45 )
      goto LABEL_50;
  }
LABEL_87:
  __break(1u);
LABEL_88:
  v24 = (int)v12;
  printk(&unk_3F4CB7, v13);
  printk(&unk_3A97DF, "ipa3_read_rt_hw");
  v38 = *((_QWORD **)v3 + 257);
  if ( v38 )
  {
    v39 = v38[4269];
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d failed reading tbl from hw\n", "ipa3_read_rt_hw", 1253);
      v38 = *((_QWORD **)v3 + 257);
    }
    v40 = v38[4270];
    if ( v40 )
      ipc_log_string(v40, "ipa %s:%d failed reading tbl from hw\n", "ipa3_read_rt_hw", 1253);
  }
LABEL_64:
  mutex_unlock(*((_QWORD *)v3 + 257) + 29472LL);
  ipa3_dec_client_disable_clks();
  kfree(v8);
  result = v24;
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
