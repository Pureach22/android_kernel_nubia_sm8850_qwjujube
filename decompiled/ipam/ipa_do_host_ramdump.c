__int64 __fastcall ipa_do_host_ramdump(__int64 a1, __int64 a2)
{
  _DWORD *v3; // x21
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x25
  __int64 v13; // x23
  _DWORD *v14; // x26
  _QWORD *v15; // x19
  __int64 v16; // x8
  __int64 v17; // x28
  _DWORD *v18; // x27
  int v19; // w7
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  _QWORD *v23; // x1
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  _DWORD *v27; // x22
  _QWORD *v28; // x19
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  _QWORD *v32; // x2
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  unsigned int v36; // w0
  __int64 v37; // x8
  unsigned int v38; // w20
  __int64 v39; // x0
  __int64 v40; // x0
  _QWORD *i; // x0
  _QWORD *v42; // x8
  __int64 v43; // x9
  _QWORD *v44; // x9
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v55; // x20
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v63; // [xsp+10h] [xbp-30h]
  _QWORD *v65; // [xsp+28h] [xbp-18h] BYREF
  _QWORD **v66; // [xsp+30h] [xbp-10h]
  __int64 v67; // [xsp+38h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = nullptr;
  v66 = nullptr;
  v3 = (_DWORD *)_kmalloc_cache_noprof(__ratelimit, 3520, 1816);
  if ( !v3 )
  {
LABEL_94:
    printk(&unk_3C3A2A, "ipa_do_host_ramdump");
    v56 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v57 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v57 )
      {
        ipc_log_string(v57, "ipa %s:%d Failed to alloc memory for meta info\n", "ipa_do_host_ramdump", 399);
        v56 = ipa3_ctx;
      }
      v58 = *(_QWORD *)(v56 + 34160);
      if ( v58 )
        ipc_log_string(v58, "ipa %s:%d Failed to alloc memory for meta info\n", "ipa_do_host_ramdump", 399);
    }
LABEL_104:
    v38 = -12;
    goto LABEL_105;
  }
  while ( 2 )
  {
    memset(v3, 0, 0x718u);
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d In host ramdump\n", "ipa_do_host_ramdump", 403);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d In host ramdump\n", "ipa_do_host_ramdump", 403);
    }
    v7 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 912);
    v8 = v7;
    if ( !v7 )
    {
      printk(&unk_3CF70B, "ipa_do_host_ramdump");
      v59 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v60 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v60 )
        {
          ipc_log_string(v60, "ipa %s:%d Failed to alloc device mem\n", "ipa_do_host_ramdump", 406);
          v59 = ipa3_ctx;
        }
        v61 = *(_QWORD *)(v59 + 34160);
        if ( v61 )
          ipc_log_string(v61, "ipa %s:%d Failed to alloc device mem\n", "ipa_do_host_ramdump", 406);
      }
      goto LABEL_104;
    }
    *(_QWORD *)(v7 + 808) = ipa_host_ramdump_dev_release;
    device_initialize(v7);
    dev_set_name(v8, "ipa_driver");
    if ( (unsigned int)device_add(v8) )
    {
      printk(&unk_3E6203, "ipa_do_host_ramdump");
      v48 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_89;
      v49 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v49 )
      {
        ipc_log_string(v49, "ipa %s:%d Failed to add new device\n", "ipa_do_host_ramdump", 415);
        v48 = ipa3_ctx;
      }
      v50 = *(_QWORD *)(v48 + 34160);
      if ( v50 )
      {
        ipc_log_string(v50, "ipa %s:%d Failed to add new device\n", "ipa_do_host_ramdump", 415);
        v38 = 0;
      }
      else
      {
LABEL_89:
        v38 = 0;
      }
      goto LABEL_73;
    }
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d new device added\n", "ipa_do_host_ramdump", 418);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d new device added\n", "ipa_do_host_ramdump", 418);
    }
    v63 = v8;
    v65 = &v65;
    v66 = &v65;
    if ( a2 )
    {
      v12 = 0;
      v13 = 0;
      v14 = v3 + 4;
      _ReadStatusReg(SP_EL0);
      while ( v12 != 450 )
      {
        v14[v12] = -1;
        v15 = (_QWORD *)_kmalloc_cache_noprof(ipc_log_string, 3520, 40);
        if ( !v15 )
        {
          v15 = (_QWORD *)_kmalloc_cache_noprof(ipc_log_string, 3520, 40);
          if ( !v15 )
          {
            printk(&unk_3E0BD9, "ipa_do_host_ramdump");
            v24 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v25 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v25 )
              {
                ipc_log_string(v25, "ipa %s:%d Failed to alloc seg entry %d\n", "ipa_do_host_ramdump", 426, v13);
                v24 = ipa3_ctx;
              }
              v26 = *(_QWORD *)(v24 + 34160);
              if ( v26 )
                ipc_log_string(v26, "ipa %s:%d Failed to alloc seg entry %d\n", "ipa_do_host_ramdump", 426, v13);
            }
            v8 = v63;
            v27 = v3;
            goto LABEL_88;
          }
        }
        v16 = *(_QWORD *)(a1 + 104);
        v15[2] = v16;
        v15[3] = v16;
        v17 = *(_QWORD *)(a1 + 112);
        v15[4] = v17;
        if ( !strcmp((const char *)a1, "ipa_ctx") )
          v14[v12] = 0;
        if ( !strcmp((const char *)a1, "gsi_ctx") )
          v14[v12] = 1;
        if ( !strcmp((const char *)a1, "ipc_logs") )
          v14[v12] = 2;
        if ( !strcmp((const char *)a1, "dmesg_logs") )
          v14[v12] = 3;
        if ( (unsigned __int64)(v12 * 4 - 1796) < 0xFFFFFFFFFFFFF8E8LL
          || (v18 = &v14[v12], v14[v12 + 1] = v13 + 1, (unsigned __int64)(v12 * 4 - 1792) < 0xFFFFFFFFFFFFF8E8LL) )
        {
LABEL_92:
          __break(1u);
          break;
        }
        v19 = *(unsigned __int8 *)(a1 + 120);
        v20 = ipa3_ctx;
        v18[2] = v19;
        if ( v20 )
        {
          v21 = *(_QWORD *)(v20 + 34152);
          if ( v21 )
          {
            ipc_log_string(
              v21,
              "ipa %s:%d meta_info.entry[%d].type:%d, size:%zu, entry_num %d\n",
              "ipa_do_host_ramdump",
              442,
              v13,
              v14[v12],
              v17,
              v19);
            v20 = ipa3_ctx;
          }
          v22 = *(_QWORD *)(v20 + 34160);
          if ( v22 )
          {
            if ( (unsigned __int64)(v12 * 4 - 1792) < 0xFFFFFFFFFFFFF8E8LL )
              goto LABEL_92;
            ipc_log_string(
              v22,
              "ipa %s:%d meta_info.entry[%d].type:%d, size:%zu, entry_num %d\n",
              "ipa_do_host_ramdump",
              442,
              v13,
              v14[v12],
              *(_QWORD *)(a1 + 112),
              v18[2]);
          }
        }
        v23 = v66;
        if ( v66 == v15 || *v66 != &v65 )
        {
          _list_add_valid_or_report(v15, v66);
        }
        else
        {
          v66 = (_QWORD **)v15;
          *v15 = &v65;
          v15[1] = v23;
          *v23 = v15;
        }
        ++v13;
        v12 += 3;
        a1 += 128;
        if ( a2 == v13 )
          goto LABEL_47;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v55 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ipa_do_host_ramdump__alloc_tag;
      v3 = (_DWORD *)_kmalloc_cache_noprof(__ratelimit, 3520, 1816);
      *(_QWORD *)(StatusReg + 80) = v55;
      if ( v3 )
        continue;
      goto LABEL_94;
    }
    break;
  }
LABEL_47:
  v28 = (_QWORD *)_kmalloc_cache_noprof(ipc_log_string, 3520, 40);
  v8 = v63;
  v27 = v3;
  v29 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v30 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v30 )
    {
      ipc_log_string(v30, "ipa %s:%d Segment list prepared\n", "ipa_do_host_ramdump", 447);
      v29 = ipa3_ctx;
    }
    v31 = *(_QWORD *)(v29 + 34160);
    if ( v31 )
      ipc_log_string(v31, "ipa %s:%d Segment list prepared\n", "ipa_do_host_ramdump", 447);
  }
  if ( !v28 )
  {
    printk(&unk_3B7D10, "ipa_do_host_ramdump");
    v51 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v52 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v52 )
      {
        ipc_log_string(v52, "ipa %s:%d Failed to allocate mem for host dump seg\n", "ipa_do_host_ramdump", 450);
        v51 = ipa3_ctx;
      }
      v53 = *(_QWORD *)(v51 + 34160);
      if ( v53 )
        ipc_log_string(v53, "ipa %s:%d Failed to allocate mem for host dump seg\n", "ipa_do_host_ramdump", 450);
    }
LABEL_88:
    v38 = 0;
    goto LABEL_65;
  }
  v32 = v65;
  v28[2] = v3;
  v28[3] = v3;
  *(_QWORD *)v3 = 4804673;
  v3[2] = 3728;
  v3[3] = a2;
  v28[4] = 1816;
  if ( v32 == v28 || (_QWORD **)v32[1] != &v65 )
  {
    _list_add_valid_or_report(v28, &v65);
    v33 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_56;
  }
  else
  {
    v32[1] = v28;
    *v28 = v32;
    v28[1] = &v65;
    v65 = v28;
    v33 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_56:
      v34 = *(_QWORD *)(v33 + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d before elf dump\n", "ipa_do_host_ramdump", 462);
        v33 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v33 + 34160);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d before elf dump\n", "ipa_do_host_ramdump", 462);
    }
  }
  v36 = qcom_elf_dump(&v65, v63, 2);
  v37 = ipa3_ctx;
  v38 = v36;
  if ( ipa3_ctx )
  {
    v39 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d after elf dump\n", "ipa_do_host_ramdump", 464);
      v37 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v37 + 34160);
    if ( v40 )
      ipc_log_string(v40, "ipa %s:%d after elf dump\n", "ipa_do_host_ramdump", 464);
  }
LABEL_65:
  for ( i = v65; v65 != &v65; i = v65 )
  {
    v42 = (_QWORD *)i[1];
    if ( (_QWORD *)*v42 == i && (v43 = *i, *(_QWORD **)(*i + 8LL) == i) )
    {
      *(_QWORD *)(v43 + 8) = v42;
      *v42 = v43;
    }
    else
    {
      _list_del_entry_valid_or_report(i);
      i = v44;
    }
    *i = 0xDEAD000000000100LL;
    i[1] = 0xDEAD000000000122LL;
    kfree(i);
  }
  kfree(v27);
  device_del(v8);
LABEL_73:
  put_device(v8);
  v45 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v46 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v46 )
    {
      ipc_log_string(v46, "ipa %s:%d host ramdump result %d\n", "ipa_do_host_ramdump", 475, v38);
      v45 = ipa3_ctx;
    }
    v47 = *(_QWORD *)(v45 + 34160);
    if ( v47 )
      ipc_log_string(v47, "ipa %s:%d host ramdump result %d\n", "ipa_do_host_ramdump", 475, v38);
  }
LABEL_105:
  _ReadStatusReg(SP_EL0);
  return v38;
}
