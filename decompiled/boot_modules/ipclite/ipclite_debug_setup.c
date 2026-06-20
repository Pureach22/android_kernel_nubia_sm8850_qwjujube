__int64 ipclite_debug_setup()
{
  __int64 v0; // x0
  __int64 v1; // x2
  __int64 v2; // x3
  __int64 v3; // x4
  __int64 v4; // x5
  __int64 v5; // x6
  __int64 v6; // x7
  __int64 result; // x0
  unsigned int v8; // w20
  const char *v9; // x0
  unsigned int v10; // w19
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x8
  int v14; // w8
  __int64 v15; // x10
  unsigned int v16; // w20
  unsigned int v17; // w21
  unsigned int v18; // w21
  unsigned int v19; // w21
  char vars0; // [xsp+0h] [xbp+0h]

  v0 = kobject_create_and_add("ipclite", kernel_kobj);
  sysfs_kobj = v0;
  if ( !v0 )
  {
    if ( (ipclite_debug_level & 1) == 0 )
    {
      result = 4294967284LL;
      goto LABEL_18;
    }
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_10E6F, "ipclite", "ipclite_debug_sysfs_setup");
      result = 4294967284LL;
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_18;
    }
    else
    {
      result = 4294967284LL;
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_18;
    }
    v8 = -12;
    v9 = "APPS:%s:Cannot create and add sysfs directory\n";
    goto LABEL_17;
  }
  result = sysfs_create_file_ns(v0, &sysfs_dbg_lvl, 0);
  if ( !(_DWORD)result )
  {
    result = sysfs_create_file_ns(sysfs_kobj, &sysfs_dbg_ctrl, 0);
    if ( (_DWORD)result )
    {
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_18;
      if ( (ipclite_debug_control & 1) != 0 )
      {
        v18 = result;
        printk(&unk_FC45, "ipclite", "ipclite_debug_sysfs_setup");
        result = v18;
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_18;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        goto LABEL_18;
      }
      v8 = result;
      v9 = "APPS:%s:Cannot create sysfs debug control file\n";
      goto LABEL_17;
    }
    result = sysfs_create_file_ns(sysfs_kobj, &sysfs_dbg_dump, 0);
    if ( (_DWORD)result )
    {
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_18;
      if ( (ipclite_debug_control & 1) != 0 )
      {
        v19 = result;
        printk(&unk_F746, "ipclite", "ipclite_debug_sysfs_setup");
        result = v19;
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_18;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        goto LABEL_18;
      }
      v8 = result;
      v9 = "APPS:%s:Cannot create sysfs debug dump file\n";
      goto LABEL_17;
    }
    v11 = *(_QWORD *)(ipclite + 6400);
    v12 = *(unsigned int *)(ipclite + 6408);
    v13 = v11 + v12;
    ipclite_dbg_info = v11 + v12 - 0x10000;
    if ( v11 + v12 != 0x10000 )
    {
      ipclite_dbg_struct = v13 - 65280;
      if ( v13 != 65280 )
      {
        ipclite_dbg_inmem = v13 - 60204;
        if ( v13 != 60204 )
        {
          v14 = ipclite_debug_control;
          debug_status = 1;
          if ( (ipclite_debug_level & 0x10) == 0 )
            goto LABEL_35;
          if ( (ipclite_debug_control & 1) != 0 )
          {
            printk(&unk_F92C, "ipclite", "ipclite_debug_mem_setup");
            v14 = ipclite_debug_control;
            if ( (ipclite_debug_control & 4) == 0 )
            {
LABEL_35:
              if ( (ipclite_debug_level & 0x10) != 0 )
              {
                if ( (v14 & 1) != 0 )
                {
                  printk(&unk_10DE9, "ipclite", "ipclite_debug_mem_setup");
                  v14 = ipclite_debug_control;
                  if ( (ipclite_debug_control & 4) == 0 )
                    goto LABEL_39;
                  goto LABEL_38;
                }
                if ( (v14 & 4) != 0 )
                {
LABEL_38:
                  ipclite_inmem_log(
                    "APPS:%s:dbg_info : %p dbg_struct : %p dbg_inmem : %p\n",
                    (__int64)"LOW",
                    ipclite_dbg_info,
                    ipclite_dbg_struct,
                    ipclite_dbg_inmem,
                    v12,
                    v5,
                    v6,
                    vars0);
                  v14 = ipclite_debug_control;
                }
              }
LABEL_39:
              v15 = ipclite_dbg_info;
              *(_DWORD *)(ipclite_dbg_info + 4) = ipclite_debug_level;
              *(_DWORD *)(v15 + 8) = v14;
              return 0;
            }
          }
          else if ( (ipclite_debug_control & 4) == 0 )
          {
            goto LABEL_35;
          }
          ipclite_inmem_log(
            "APPS:%s:virtual_base_ptr = %p total_size : %d debug_size : %d\n",
            (__int64)"LOW",
            *(_QWORD *)(ipclite + 6400),
            *(unsigned int *)(ipclite + 6408),
            0x10000,
            v12,
            v5,
            v6,
            vars0);
          v14 = ipclite_debug_control;
          goto LABEL_35;
        }
      }
    }
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_10214, "ipclite", "ipclite_debug_setup");
        if ( (ipclite_debug_control & 4) == 0 )
          return 4294967197LL;
        goto LABEL_45;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_45:
        ipclite_inmem_log(
          "APPS:%s:Failed to Set up IPCLite Debug Structures\n",
          (__int64)"ERR",
          v1,
          v2,
          v11,
          v12,
          v5,
          v6,
          vars0);
    }
    return 4294967197LL;
  }
  if ( (ipclite_debug_level & 1) == 0 )
    goto LABEL_18;
  if ( (ipclite_debug_control & 1) == 0 )
  {
    if ( (ipclite_debug_control & 4) == 0 )
      goto LABEL_18;
    goto LABEL_6;
  }
  v17 = result;
  printk(&unk_FD81, "ipclite", "ipclite_debug_sysfs_setup");
  result = v17;
  if ( (ipclite_debug_control & 4) != 0 )
  {
LABEL_6:
    v8 = result;
    v9 = "APPS:%s:Cannot create sysfs debug level file\n";
LABEL_17:
    ipclite_inmem_log(v9, (__int64)"ERR", v1, v2, v3, v4, v5, v6, vars0);
    result = v8;
  }
LABEL_18:
  if ( (ipclite_debug_level & 1) == 0 )
    return result;
  if ( (ipclite_debug_control & 1) == 0 )
  {
    if ( (ipclite_debug_control & 4) == 0 )
      return result;
    goto LABEL_21;
  }
  v16 = result;
  printk(&unk_F50E, "ipclite", "ipclite_debug_setup");
  result = v16;
  if ( (ipclite_debug_control & 4) != 0 )
  {
LABEL_21:
    v10 = result;
    ipclite_inmem_log("APPS:%s:Failed to Set up IPCLite Debug Sysfs\n", (__int64)"ERR", v1, v2, v3, v4, v5, v6, vars0);
    return v10;
  }
  return result;
}
