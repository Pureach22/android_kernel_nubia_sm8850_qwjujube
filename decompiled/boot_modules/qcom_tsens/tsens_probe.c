__int64 __fastcall tsens_probe(_QWORD *a1)
{
  _QWORD *v2; // x22
  __int64 v3; // x20
  __int64 matched; // x0
  _QWORD *v5; // x24
  unsigned int v6; // w23
  unsigned __int64 v7; // x21
  __int64 v8; // x0
  unsigned int v9; // w8
  _QWORD *v10; // x20
  __int64 v11; // x9
  unsigned int v12; // w9
  __int64 v13; // x10
  __int64 v14; // x13
  unsigned __int64 v15; // x14
  __int64 v16; // x8
  __int64 (*v17)(void); // x8
  unsigned int v18; // w0
  __int64 (__fastcall *v19)(_QWORD); // x8
  unsigned int v20; // w0
  __int64 v21; // x8
  int variable_le_u32; // w0
  int v23; // w9
  int v24; // w10
  bool v25; // w8
  __int64 result; // x0
  bool v28; // w11
  bool v29; // zf
  int v31; // w9
  unsigned int v32; // w22
  __int64 v33; // x19
  __int64 v35; // x27
  unsigned __int64 v36; // x0
  unsigned __int64 v37; // x26
  _DWORD *v38; // x8
  const char *v39; // x27
  size_t v40; // x0
  __int64 v41; // x8
  const char *v42; // x1
  __int64 (__fastcall *v43)(); // x2
  __int64 v44; // x2
  unsigned __int64 v45; // kr00_8
  __int64 v46; // x2
  unsigned __int64 v47; // kr08_8
  _QWORD *v48; // x20
  __int64 v49; // x1
  __int64 v50; // x0
  __int64 dir; // x0
  const char *v52; // x3
  __int64 v53; // x0
  const char *v54; // x3
  __int64 v55; // x0
  unsigned int v56; // w19
  _QWORD *v57; // [xsp+8h] [xbp-38h]
  unsigned int v58; // [xsp+14h] [xbp-2Ch] BYREF
  char s[8]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v60; // [xsp+20h] [xbp-20h]
  __int64 v61; // [xsp+28h] [xbp-18h]
  __int64 v62; // [xsp+30h] [xbp-10h]
  __int64 v63; // [xsp+38h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1[95] )
    v2 = a1 + 2;
  else
    v2 = (_QWORD *)a1[14];
  v3 = v2[93];
  v58 = 0;
  matched = of_match_node(&_mod_of__tsens_table_device_table, v3);
  if ( matched )
    v5 = *(_QWORD **)(matched + 192);
  else
    v5 = &data_8960;
  v6 = *(_DWORD *)v5;
  v58 = *(_DWORD *)v5;
  if ( v3 )
  {
    of_property_read_variable_u32_array(v3, "#qcom,sensors", &v58, 1, 0);
    v6 = v58;
  }
  if ( !v6 )
  {
    dev_err(v2, "%s: invalid number of sensors\n", "tsens_probe");
    result = 4294967274LL;
    goto LABEL_37;
  }
  v7 = 88LL * v6 + 2600;
  v8 = devm_kmalloc(v2, v7, 3520);
  if ( !v8 )
  {
    result = 4294967284LL;
    goto LABEL_37;
  }
  v9 = v58;
  *(_QWORD *)v8 = v2;
  v10 = (_QWORD *)v8;
  *(_DWORD *)(v8 + 8) = v9;
  v11 = v5[1];
  *(_QWORD *)(v8 + 2560) = v11;
  if ( v9 )
  {
    v12 = 0;
    v13 = v8 + 2600;
    do
    {
      v14 = v5[2];
      v15 = 88LL * (int)v12 + 2668;
      if ( v14 )
      {
        if ( v7 < v15 )
          goto LABEL_111;
        *(_DWORD *)(v13 + 88LL * (int)v12 + 68) = *(_DWORD *)(v14 + 4LL * (int)v12);
      }
      else
      {
        if ( v7 < v15 )
          goto LABEL_111;
        *(_DWORD *)(v13 + 88LL * (int)v12 + 68) = v12;
      }
      ++v12;
    }
    while ( v12 < v9 );
    v11 = *(_QWORD *)(v8 + 2560);
  }
  *(_QWORD *)(v8 + 2544) = v5[3];
  v16 = v5[4];
  a1[21] = v8;
  *(_QWORD *)(v8 + 2552) = v16;
  if ( !v11 || (v17 = *(__int64 (**)(void))v11) == nullptr || !*(_QWORD *)(v11 + 16) )
  {
    result = 4294967274LL;
    goto LABEL_37;
  }
  if ( *((_DWORD *)v17 - 1) != -1948242801 )
    __break(0x8228u);
  v18 = v17();
  if ( (v18 & 0x80000000) != 0 )
  {
    v56 = v18;
    dev_err(v2, "%s: init failed\n", "tsens_probe");
    result = v56;
    goto LABEL_37;
  }
  v19 = *(__int64 (__fastcall **)(_QWORD))(v10[320] + 8LL);
  if ( v19 )
  {
    if ( *((_DWORD *)v19 - 1) != -1948242801 )
      __break(0x8228u);
    v20 = v19(v10);
    if ( (v20 & 0x80000000) != 0 )
    {
      result = dev_err_probe(v2, v20, "%s: calibration failed\n", "tsens_probe");
      goto LABEL_37;
    }
  }
  v21 = *v10;
  *(_DWORD *)s = 0;
  v57 = a1;
  if ( of_find_property(*(_QWORD *)(v21 + 744), "nvmem-cells", 0) )
  {
    variable_le_u32 = nvmem_cell_read_variable_le_u32(*v10, "tsens_chipinfo", s);
    if ( variable_le_u32 )
    {
      dev_err(
        *v10,
        "%s: Not able to read tsens_chipinfo nvmem, ret:%d\n",
        "tsens_is_nvmem_trip_update_needed",
        variable_le_u32);
      v25 = 0;
    }
    else
    {
      v23 = *(_DWORD *)s & 0xFFFFF;
      v24 = (unsigned __int8)(*(_DWORD *)s >> 20);
      if ( (*(_DWORD *)s & 0xFFFFF) == 0x197 && v24 == 3 )
      {
        v25 = 1;
      }
      else
      {
        v28 = v23 == 526 && v24 == 3;
        v29 = v24 == 4 && v23 == 408;
        v25 = 1;
        if ( !v29 && !v28 )
          v25 = v23 == 527 && v24 == 2;
      }
    }
  }
  else
  {
    v25 = 0;
  }
  v31 = *((_DWORD *)v10 + 2);
  *((_BYTE *)v10 + 36) = v25;
  if ( v31 )
  {
    v32 = 0;
    while ( 1 )
    {
      v33 = 88LL * (int)v32;
      if ( v7 < v33 + 2600 || v6 == (__int64)(int)v32 )
        break;
      v35 = (__int64)&v10[11 * (int)v32 + 325];
      *(_QWORD *)v35 = v10;
      if ( v7 < v33 + 2668 )
        break;
      v36 = devm_thermal_of_zone_register(*v10, *(unsigned int *)(v35 + 68), &v10[11 * (int)v32 + 325], &tsens_of_ops);
      if ( v36 <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( v7 <= v33 + 2608 )
          break;
        *(_QWORD *)(v35 + 8) = v36;
        v37 = v36;
        v38 = *(_DWORD **)(v10[320] + 24LL);
        if ( v38 )
        {
          if ( *(v38 - 1) != -720312745 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, _QWORD))v38)(v10, v32);
        }
        if ( *((_BYTE *)v10 + 36) == 1 )
        {
          v39 = (const char *)thermal_zone_device_type(v37);
          v40 = strlen(v39);
          if ( !strnstr(v39, "mdmss", v40) )
            for_each_thermal_trip(v37, tsens_thermal_zone_trip_update, v37);
        }
      }
      if ( ++v32 >= *((_DWORD *)v10 + 2) )
        goto LABEL_75;
    }
LABEL_111:
    __break(1u);
  }
LABEL_75:
  v41 = v10[318];
  if ( *(_DWORD *)v41 )
  {
    if ( (*(_BYTE *)(v41 + 4) & 2) == 0 )
      goto LABEL_77;
LABEL_90:
    v42 = "combined";
    v43 = tsens_combined_irq_thread;
    goto LABEL_91;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v10[325] + 2544LL) + 4LL) & 4) != 0 )
  {
    v45 = *((int *)v10 + 666) + 120LL * *((int *)v10 + 668);
    if ( v45 <= 0xF9C17 )
      v44 = (unsigned int)(v45 / 0x3E8);
    else
      v44 = 1023;
  }
  else
  {
    v44 = 1200;
  }
  regmap_field_update_bits_base(v10[255], 0xFFFFFFFFLL, v44, 0, 0, 0);
  v46 = 0;
  if ( (*(_BYTE *)(*(_QWORD *)(v10[325] + 2544LL) + 4LL) & 4) != 0 )
  {
    v47 = *((int *)v10 + 666);
    if ( (unsigned int)v47 <= 0xF9C17 )
      v46 = (unsigned int)(v47 / 0x3E8);
    else
      v46 = 1023;
  }
  regmap_field_update_bits_base(v10[256], 0xFFFFFFFFLL, v46, 0, 0, 0);
  if ( (*(_BYTE *)(v10[318] + 4LL) & 2) != 0 )
    goto LABEL_90;
LABEL_77:
  result = tsens_register_irq(v10, "uplow", tsens_irq_thread);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_37;
  if ( (*(_BYTE *)(v10[318] + 4LL) & 1) != 0 )
  {
    v42 = "critical";
    v43 = tsens_critical_irq_thread;
LABEL_91:
    result = tsens_register_irq(v10, v42, v43);
  }
  if ( (_DWORD)result )
    goto LABEL_37;
  v48 = (_QWORD *)v57[21];
  v61 = 0;
  v62 = 0;
  *(_QWORD *)s = 0;
  v60 = 0;
  v49 = debugfs_lookup("tsens", 0);
  v48[321] = v49;
  if ( !v49 )
    v48[321] = debugfs_create_dir("tsens");
  v50 = v57[16];
  if ( !v50 )
    v50 = v57[2];
  dir = debugfs_create_dir(v50);
  v48[322] = dir;
  debugfs_create_file("version", 292, dir, v57, &dbg_version_fops);
  debugfs_create_file("sensors", 292, v48[322], v57, &dbg_sensors_fops);
  if ( (*(_BYTE *)(v48[318] + 12LL) & 1) != 0 )
    debugfs_create_file("persist_max_min", 292, v48[322], v57, &dbg_persist_max_min_fops);
  v52 = (const char *)v57[16];
  if ( !v52 )
    v52 = (const char *)v57[2];
  snprintf(s, 0x20u, "%s_0", v52);
  v53 = ipc_log_context_create(10, s, 0);
  v48[323] = v53;
  if ( !v53 )
  {
    dev_err(v57 + 2, "%s: unable to create IPC Logging for %s\n", "tsens_debug_init", s);
    v54 = (const char *)v57[16];
    if ( v54 )
      goto LABEL_104;
    goto LABEL_103;
  }
  v54 = (const char *)v57[16];
  if ( !v54 )
LABEL_103:
    v54 = (const char *)v57[2];
LABEL_104:
  snprintf(s, 0x20u, "%s_1", v54);
  v55 = ipc_log_context_create(10, s, 0);
  v48[324] = v55;
  if ( !v55 )
    dev_err(v57 + 2, "%s: unable to create IPC Logging for %s\n", "tsens_debug_init", s);
  result = 0;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
