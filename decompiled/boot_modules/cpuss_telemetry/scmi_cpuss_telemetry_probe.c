__int64 __fastcall scmi_cpuss_telemetry_probe(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8
  unsigned __int64 v3; // x0
  _DWORD *v4; // x9
  __int64 v5; // x0
  unsigned __int64 v6; // x20
  unsigned __int64 v7; // x0
  __int64 v8; // x2
  unsigned __int64 v9; // x20
  int v10; // w22
  __int64 v11; // x2
  unsigned __int64 v12; // x20
  int v13; // w22
  __int64 v14; // x2
  __int64 v15; // x20
  __int64 dir; // x0
  __int64 v17; // x20
  __int64 v18; // x0
  char *v19; // x23
  const char *v20; // x21
  __int64 v21; // x28
  __int64 file; // x24
  __int64 *v23; // x8
  const char *v24; // x25
  size_t v25; // x0
  unsigned __int64 v26; // x2
  char *v27; // x0
  char *v28; // x25
  char *v29; // x0
  char v30; // w25
  unsigned __int8 v31; // w0
  unsigned __int64 v32; // x26
  unsigned __int64 v33; // x8
  bool v34; // cc
  char v35; // w0
  __int64 v36; // x9
  __int64 result; // x0
  const char *v38; // x1
  const char *v39; // x2
  __int64 v40; // x0
  unsigned __int64 v42; // [xsp+10h] [xbp-40h] BYREF
  unsigned int v43; // [xsp+1Ch] [xbp-34h] BYREF
  char *stringp; // [xsp+20h] [xbp-30h] BYREF
  __int64 v45; // [xsp+28h] [xbp-28h] BYREF
  __int64 v46; // [xsp+30h] [xbp-20h]
  char s[8]; // [xsp+38h] [xbp-18h] BYREF
  __int64 v48; // [xsp+40h] [xbp-10h]
  __int64 v49; // [xsp+48h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 928);
  v42 = 0;
  v2 = *(__int64 (**)(void))(v1 + 24);
  if ( *((_DWORD *)v2 - 1) != -1171826031 )
    __break(0x8228u);
  v3 = v2();
  vendor_ops = v3;
  if ( v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1 + 16, "Cannot access protocol:0x%X - err:%ld\n", *(unsigned __int8 *)(a1 + 4), v3);
    result = (unsigned int)vendor_ops;
    goto LABEL_86;
  }
  v4 = *(_DWORD **)(v3 + 8);
  v5 = ph_telemetry;
  if ( *(v4 - 1) != 1134762728 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(__int64, unsigned __int64 *, __int64, _QWORD, _QWORD, __int64))v4)(
         v5,
         &v42,
         0x454C454D45545259LL,
         0,
         0,
         8) )
  {
    printk(&unk_6F73, "scmi_cpuss_telemetry_probe", "scmi_cpuss_telemetry_probe");
    result = 4294967277LL;
    goto LABEL_86;
  }
  v6 = v42;
  if ( (unsigned int)pfn_is_map_memory(v42 >> 12) )
  {
    v7 = (v6 - memstart_addr) | 0xFFFFFF8000000000LL;
    telemetry = v7;
  }
  else
  {
    if ( arm64_use_ng_mappings )
      v8 = 0x68000000000F03LL;
    else
      v8 = 0x68000000000703LL;
    v7 = ioremap_prot(v6, 8, v8);
    telemetry = v7;
    if ( !v7 )
    {
      dev_err(a1 + 16, "Failed to map memory for telemetry\n");
      goto LABEL_85;
    }
  }
  v9 = *(_QWORD *)(v7 + 32);
  v10 = *(_DWORD *)(v7 + 28);
  if ( (unsigned int)pfn_is_map_memory(v9 >> 12) )
  {
    pname = (v9 - memstart_addr) | 0xFFFFFF8000000000LL;
  }
  else
  {
    if ( arm64_use_ng_mappings )
      v11 = 0x68000000000F03LL;
    else
      v11 = 0x68000000000703LL;
    pname = ioremap_prot(v9, (unsigned int)(8 * v10), v11);
    if ( !pname )
    {
      v40 = dev_err(a1 + 16, "Failed to map memory for telemetry counter names\n");
      goto LABEL_84;
    }
  }
  v12 = *(_QWORD *)(telemetry + 40);
  v13 = *(_DWORD *)(telemetry + 28);
  if ( (unsigned int)pfn_is_map_memory(v12 >> 12) )
  {
    pvalue = (v12 - memstart_addr) | 0xFFFFFF8000000000LL;
  }
  else
  {
    if ( arm64_use_ng_mappings )
      v14 = 0x68000000000F03LL;
    else
      v14 = 0x68000000000703LL;
    pvalue = ioremap_prot(v12, (unsigned int)(8 * v13), v14);
    if ( !pvalue )
    {
      v40 = dev_err(a1 + 16, "Failed to map memory for telemetry counter values\n");
      goto LABEL_84;
    }
  }
  *(_QWORD *)s = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  stringp = nullptr;
  v43 = 0;
  fid = _kmalloc_noprof(8LL * *(unsigned int *)(telemetry + 28), 3520);
  if ( !fid )
    goto LABEL_83;
  ::dir = debugfs_create_dir("cpuss_telemetry", 0);
  if ( !::dir )
  {
    v38 = "Debugfs directory %s creation failed\n";
    v39 = "cpuss_telemetry";
    goto LABEL_82;
  }
  cluster_dir = _kmalloc_noprof(8LL * *(unsigned __int16 *)(telemetry + 26), 3520);
  if ( !cluster_dir )
    goto LABEL_83;
  if ( *(_WORD *)(telemetry + 26) )
  {
    v15 = 0;
    while ( 1 )
    {
      snprintf(s, 0x10u, "cluster_%d", v15);
      dir = debugfs_create_dir(s, ::dir);
      *(_QWORD *)(cluster_dir + 8 * v15) = dir;
      if ( !dir )
        break;
      if ( ++v15 >= (unsigned __int64)*(unsigned __int16 *)(telemetry + 26) )
        goto LABEL_32;
    }
LABEL_72:
    dev_err(a1 + 16, "Debugfs sub directory cluster %s creation failed\n", s);
    goto LABEL_83;
  }
LABEL_32:
  core_dir = _kmalloc_noprof(8LL * *(unsigned __int16 *)(telemetry + 24), 3520);
  if ( !core_dir )
    goto LABEL_83;
  if ( *(_WORD *)(telemetry + 24) )
  {
    v17 = 0;
    do
    {
      snprintf(s, 0x10u, "core_%d", v17);
      v18 = debugfs_create_dir(s, ::dir);
      *(_QWORD *)(core_dir + 8 * v17) = v18;
      if ( !v18 )
        goto LABEL_72;
    }
    while ( ++v17 < (unsigned __int64)*(unsigned __int16 *)(telemetry + 24) );
  }
  cpuss_telemetry_create_fs_entries_soc_dir = debugfs_create_dir("soc", ::dir);
  if ( !cpuss_telemetry_create_fs_entries_soc_dir )
  {
    dev_err(a1 + 16, "Debugfs directory 'soc' creation failed\n");
    goto LABEL_83;
  }
  if ( !*(_DWORD *)(telemetry + 28) )
  {
LABEL_67:
    if ( !debugfs_create_file("stat_update", 416, ::dir, 0, &telemetry_stat_request_update) )
    {
      v38 = "Failed to create file %s\n";
      v39 = "stat_update";
      goto LABEL_82;
    }
    if ( !debugfs_create_file("counter_info", 416, ::dir, 0, &counter_info_file_fops) )
    {
      v38 = "Failed to create file %s\n";
      v39 = "counter_info";
      goto LABEL_82;
    }
    result = 0;
    goto LABEL_86;
  }
  v19 = nullptr;
  v20 = nullptr;
  v21 = 0;
  file = 0;
  while ( 1 )
  {
    v45 = 0;
    v46 = 0;
    v24 = (const char *)(pname + 16 * v21);
    stringp = (char *)&v45;
    v25 = strnlen(v24, 0x10u);
    if ( v25 >= 0x11 )
      goto LABEL_88;
    if ( v25 == 16 )
      v26 = 16;
    else
      v26 = v25 + 1;
    if ( v26 >= 0x11 )
    {
      _fortify_panic(7, 16);
LABEL_88:
      _fortify_panic(2, 16);
LABEL_89:
      __break(0x5512u);
    }
    sized_strscpy(&v45, v24);
    v27 = strsep(&stringp, "_");
    if ( v27 )
    {
      v28 = v27;
      v29 = strsep(&stringp, "_");
      if ( v29 )
      {
        v19 = v28;
        v20 = v29;
        if ( strsep(&stringp, "_") )
          goto LABEL_89;
      }
      else
      {
        v19 = v28;
      }
    }
    *(_QWORD *)(fid + 8 * v21) = v21;
    if ( (unsigned int)kstrtouint(v20, 0, &v43) )
      goto LABEL_83;
    v30 = v43;
    v31 = strlen(v20);
    if ( (v43 & 0x80000000) == 0 )
      break;
LABEL_43:
    if ( ++v21 >= (unsigned __int64)*(unsigned int *)(telemetry + 28) )
      goto LABEL_67;
  }
  v32 = v43;
  if ( v43 >= 0xAuLL )
  {
    v33 = v43;
    do
    {
      v34 = v33 > 0x63;
      v32 = v33 / 0xA;
      v33 /= 0xAu;
    }
    while ( v34 );
  }
  v35 = int_pow(10, (unsigned int)v31 - 1);
  if ( !v32 )
  {
    v23 = &cpuss_telemetry_create_fs_entries_soc_dir;
LABEL_41:
    file = debugfs_create_file(v19, 288, *v23, fid + 8 * v21, &telemetry_stats_fops);
    goto LABEL_42;
  }
  if ( v32 == 2 )
  {
    if ( *(_QWORD *)(pvalue + 8 * v21) != -1 )
    {
      v36 = core_dir;
      goto LABEL_66;
    }
  }
  else if ( v32 == 1 && *(_QWORD *)(pvalue + 8 * v21) != -1 )
  {
    v36 = cluster_dir;
LABEL_66:
    v23 = (__int64 *)(v36 + 8LL * (unsigned __int8)(v30 - v35 * v32));
    goto LABEL_41;
  }
LABEL_42:
  if ( file )
    goto LABEL_43;
  v38 = "Failed to create file %s\n";
  v39 = (const char *)(pname + 16 * v21);
LABEL_82:
  dev_err(a1 + 16, v38, v39);
LABEL_83:
  dev_err(a1 + 16, "Failed to create FS entries\n");
  v40 = debugfs_remove(::dir);
LABEL_84:
  telemetry_memory_deallocation(v40);
LABEL_85:
  result = 4294967284LL;
LABEL_86:
  _ReadStatusReg(SP_EL0);
  return result;
}
