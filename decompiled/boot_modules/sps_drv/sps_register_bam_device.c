__int64 __fastcall sps_register_bam_device(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x8
  _QWORD *v5; // x20
  __int64 result; // x0
  int v7; // w8
  _QWORD *v8; // x24
  __int64 v9; // x2
  __int64 v10; // x21
  __int64 v11; // x8
  _QWORD *v12; // x25
  unsigned int v13; // w19
  __int64 v14; // x21
  _QWORD *v15; // x0
  _QWORD *v16; // x20
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  int v22; // w8
  int v23; // w19
  __int64 v24; // x2
  _QWORD *v25; // x20
  _QWORD *v26; // x20
  int v27; // w0
  char s[8]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v29; // [xsp+10h] [xbp-50h]
  __int64 v30; // [xsp+18h] [xbp-48h]
  __int64 v31; // [xsp+20h] [xbp-40h]
  __int64 v32; // [xsp+28h] [xbp-38h]
  __int64 v33; // [xsp+30h] [xbp-30h]
  __int64 v34; // [xsp+38h] [xbp-28h]
  __int64 v35; // [xsp+40h] [xbp-20h]
  __int64 v36; // [xsp+48h] [xbp-18h]
  __int64 v37; // [xsp+50h] [xbp-10h]
  __int64 v38; // [xsp+58h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  *(_QWORD *)s = 0;
  v29 = 0;
  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs, "sps_register_bam_device")) )
    {
      printk(&unk_24F8F, "sps_register_bam_device", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: bam_props is NULL\n", "sps_register_bam_device");
    goto LABEL_44;
  }
  if ( !a2 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_158, "sps_register_bam_device")) )
    {
      printk(&unk_245DF, "sps_register_bam_device", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: device handle is NULL\n", "sps_register_bam_device");
    goto LABEL_44;
  }
  v3 = sps;
  if ( !sps )
  {
    printk(&unk_28084, a2, a3);
    result = 4294966779LL;
    goto LABEL_45;
  }
  if ( (unsigned __int8)logging_option < 2u )
    goto LABEL_5;
  if ( debug_level_option )
  {
    if ( !print_limit_option
      || (v26 = a2, v27 = __ratelimit(&sps_register_bam_device__rs_162, "sps_register_bam_device"), a2 = v26, v27) )
    {
      v25 = a2;
      printk(&unk_280A4, "sps_register_bam_device", a1 + 8);
      a2 = v25;
    }
  }
  v3 = sps;
  if ( sps )
  {
LABEL_5:
    if ( *(_DWORD *)(v3 + 288) <= 3u )
    {
      v5 = a2;
      ipc_log_string(
        *(_QWORD *)(v3 + 272),
        "%s: sps: Client requests to register BAM %pa\n",
        "sps_register_bam_device",
        (const void *)(a1 + 8));
      v3 = sps;
      a2 = v5;
    }
  }
  if ( !*(_DWORD *)(v3 + 48) && (*(_BYTE *)a1 & 4) == 0 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_165, "sps_register_bam_device")) )
    {
      printk(&unk_22D69, "sps_register_bam_device", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver not ready\n", "sps_register_bam_device");
    result = 4294967285LL;
    goto LABEL_45;
  }
  v7 = *(_DWORD *)(a1 + 104);
  if ( (~v7 & 0x1D) != 0 && !*(_QWORD *)(a1 + 16) && !*(_DWORD *)(a1 + 24) )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_166, "sps_register_bam_device")) )
    {
      printk(&unk_2ADD9, "sps_register_bam_device", a1 + 8);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:Invalid properties for BAM: %pa\n",
        "sps_register_bam_device",
        a1 + 8);
    goto LABEL_44;
  }
  if ( (v7 & 1) == 0 && !*(_DWORD *)(a1 + 36) )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_169, "sps_register_bam_device")) )
    {
      printk(&unk_28D7C, "sps_register_bam_device", a1 + 8);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:Invalid device ctrl properties for BAM: %pa\n",
        "sps_register_bam_device",
        a1 + 8);
    goto LABEL_44;
  }
  *a2 = 0;
  v8 = a2;
  mutex_lock(sps + 112);
  v10 = *(_QWORD *)(a1 + 8);
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 2u
    && (!print_limit_option || (unsigned int)__ratelimit(&phy2bam__rs, "phy2bam")) )
  {
    printk(&unk_26A3F, "phy2bam", v9);
  }
  v11 = sps;
  if ( sps && *(_DWORD *)(sps + 288) <= 2u )
  {
    ipc_log_string(*(_QWORD *)(sps + 264), "%s: Enter\n", "phy2bam");
    v11 = sps;
  }
  v12 = (_QWORD *)(v11 + 160);
  do
  {
    v12 = (_QWORD *)*v12;
    if ( v12 == (_QWORD *)(v11 + 160) )
      goto LABEL_46;
  }
  while ( v12[3] != v10 );
  if ( v12 )
  {
    mutex_unlock(v11 + 112);
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_172, "sps_register_bam_device")) )
    {
      printk(&unk_26F47, "sps_register_bam_device", v12 + 3);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:BAM is already registered: %pa\n",
        "sps_register_bam_device",
        v12 + 3);
    v13 = -17;
    goto LABEL_110;
  }
LABEL_46:
  if ( (~*(_DWORD *)(a1 + 104) & 0x1D) != 0 && !*(_QWORD *)(a1 + 16) )
  {
    if ( arm64_use_ng_mappings )
      v24 = 0x68000000000F13LL;
    else
      v24 = 0x68000000000713LL;
    v14 = ioremap_prot(*(_QWORD *)(a1 + 8), *(unsigned int *)(a1 + 24), v24);
    if ( !v14 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_register_bam_device__rs_175, "sps_register_bam_device")) )
      {
        printk(&unk_231BB, "sps_register_bam_device", a1 + 8);
      }
      if ( sps )
        ipc_log_string(
          *(_QWORD *)(sps + 272),
          "%s: sps:Unable to map BAM IO mem:%pa size:0x%x\n",
          "sps_register_bam_device",
          (const void *)(a1 + 8),
          *(_DWORD *)(a1 + 24));
      goto LABEL_109;
    }
  }
  else
  {
    v14 = 0;
  }
  v15 = (_QWORD *)_kmalloc_cache_noprof(ipc_log_context_destroy, 3520, 832);
  v16 = v15;
  if ( !v15 )
  {
LABEL_109:
    v13 = -1;
LABEL_110:
    mutex_unlock(sps + 112);
    result = v13;
    goto LABEL_45;
  }
  memset(v15, 0, 0x340u);
  _mutex_init(v16 + 21, "&bam->lock", &sps_register_bam_device___key);
  mutex_lock(v16 + 21);
  memcpy(v16 + 2, (const void *)a1, 0x90u);
  if ( v14 )
    v16[4] = v14;
  snprintf(s, 0x50u, "sps_bam_%pa_0", v16 + 3);
  v17 = ipc_log_context_create(10, s, 0);
  v16[66] = v17;
  if ( !v17 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_182, "sps_register_bam_device")) )
    {
      printk(&unk_22918, "sps_register_bam_device", v16 + 3);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: unable to create IPC Log 0 for bam %pa\n",
        "sps_register_bam_device",
        v16 + 3);
  }
  snprintf(s, 0x50u, "sps_bam_%pa_1", v16 + 3);
  v18 = ipc_log_context_create(10, s, 0);
  v16[67] = v18;
  if ( !v18 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_186, "sps_register_bam_device")) )
    {
      printk(&unk_25D93, "sps_register_bam_device", v16 + 3);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: unable to create IPC Log 1 for bam %pa\n",
        "sps_register_bam_device",
        v16 + 3);
  }
  snprintf(s, 0x50u, "sps_bam_%pa_2", v16 + 3);
  v19 = ipc_log_context_create(10, s, 0);
  v16[68] = v19;
  if ( !v19 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_190, "sps_register_bam_device")) )
    {
      printk(&unk_23CEF, "sps_register_bam_device", v16 + 3);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: unable to create IPC Log 2 for bam %pa\n",
        "sps_register_bam_device",
        v16 + 3);
  }
  snprintf(s, 0x50u, "sps_bam_%pa_3", v16 + 3);
  v20 = ipc_log_context_create(10, s, 0);
  v16[69] = v20;
  if ( !v20 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_194, "sps_register_bam_device")) )
    {
      printk(&unk_27D24, "sps_register_bam_device", v16 + 3);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: unable to create IPC Log 3 for bam %pa\n",
        "sps_register_bam_device",
        v16 + 3);
  }
  snprintf(s, 0x50u, "sps_bam_%pa_4", v16 + 3);
  v21 = ipc_log_context_create(10, s, 0);
  v16[70] = v21;
  if ( !v21 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_198, "sps_register_bam_device")) )
    {
      printk(&unk_26F71, "sps_register_bam_device", v16 + 3);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: unable to create IPC Log 4 for bam %pa\n",
        "sps_register_bam_device",
        v16 + 3);
  }
  v22 = *(_DWORD *)(a1 + 116);
  if ( !v22 )
    v22 = 3;
  *((_DWORD *)v16 + 142) = v22;
  v23 = sps_bam_device_init(v16);
  mutex_unlock(v16 + 21);
  if ( v23 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_bam_device__rs_201, "sps_register_bam_device")) )
    {
      printk(&unk_2421E, "sps_register_bam_device", v16 + 3);
    }
    ipc_log_string(v16[69], "%s: sps:Fail to init BAM device: phys %pa\n", "sps_register_bam_device", v16 + 3);
    mutex_unlock(sps + 112);
    if ( v14 )
      iounmap(v16[4]);
    kfree(v16);
LABEL_44:
    result = 0xFFFFFFFFLL;
    goto LABEL_45;
  }
  list_add_tail(v16, sps + 160);
  *v8 = v16;
  mutex_unlock(sps + 112);
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 2u
     || (unsigned int)__ratelimit(&sps_register_bam_device__rs_204, "sps_register_bam_device")) )
  {
    printk(&unk_24601, "sps_register_bam_device", v16 + 3);
  }
  ipc_log_string(v16[69], "%s: sps:BAM %pa is registered\n", "sps_register_bam_device", v16 + 3);
  result = 0;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
