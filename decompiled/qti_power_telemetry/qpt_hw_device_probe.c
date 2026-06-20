__int64 __fastcall qpt_hw_device_probe(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v3; // x0
  _QWORD *v4; // x20
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 *v7; // x22
  __int64 v8; // x24
  __int64 device_by_node; // x0
  __int64 v10; // x23
  __int64 v11; // x0
  unsigned int string_helper; // w25
  __int64 v13; // x0
  _DWORD *v14; // x0
  __int64 v15; // x26
  __int64 v16; // x27
  unsigned __int64 v17; // x0
  __int64 v18; // x26
  __int64 v19; // x27
  unsigned __int64 v20; // x0
  __int64 v21; // x26
  __int64 v22; // x27
  unsigned __int64 v23; // x0
  unsigned int v24; // w0
  unsigned int variable_u16_array; // w0
  int irq; // w0
  __int64 v27; // x2
  int v28; // w0
  unsigned int v29; // w0
  unsigned int v30; // w0
  __int64 v31; // x23
  __int64 v32; // x28
  unsigned int v33; // w27
  unsigned __int64 v34; // x0
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  __int64 v37; // x25
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x26
  char v41; // w9
  int v42; // w8
  unsigned int v43; // w8
  int v44; // w9
  unsigned int v45; // w8
  unsigned int v46; // w8
  __int64 v47; // x2
  unsigned int v48; // w0
  __int64 v49; // x0
  __int64 v50; // x1
  __int64 v51; // x4
  __int64 v52; // x5
  __int64 v53; // x8
  _QWORD v55[2]; // [xsp+0h] [xbp-20h] BYREF
  int v56; // [xsp+10h] [xbp-10h]
  __int64 v57; // [xsp+18h] [xbp-8h]

  v1 = a1 + 16;
  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 272, 3520);
  if ( !v3 )
  {
    string_helper = -12;
    goto LABEL_123;
  }
  v4 = v3;
  *v3 = v1;
  v5 = ipc_log_context_create(10, "qpt_data", 0);
  v4[13] = v5;
  if ( !v5 )
    dev_err(*v4, "%s: unable to create IPC Logging for %s\n", "qpt_hw_device_probe", "qpt_data");
  v6 = ipc_log_context_create(10, "qpt_event", 0);
  v4[14] = v6;
  if ( v6 )
  {
    if ( (*((_BYTE *)v4 + 85) & 1) != 0 )
      goto LABEL_122;
  }
  else
  {
    dev_err(*v4, "%s: unable to create IPC Logging for %s\n", "qpt_hw_device_probe", "qpt_event");
    if ( (*((_BYTE *)v4 + 85) & 1) != 0 )
      goto LABEL_122;
  }
  _mutex_init(v4 + 25, "&qpt->hw_read_lock", &qti_qpt_hw_init___key);
  v7 = v4 + 23;
  v4[23] = v4 + 23;
  v4[24] = v4 + 23;
  v8 = *(_QWORD *)(*v4 + 744LL);
  device_by_node = of_find_device_by_node(v8);
  if ( !device_by_node )
  {
    dev_err(*v4, "Invalid pdev\n");
    string_helper = -19;
LABEL_46:
    dev_err(*v4, "Failed to parse qpt rc=%d\n", string_helper);
LABEL_47:
    dev_err(v1, "%s: init failed\n", "qpt_hw_device_probe");
    goto LABEL_123;
  }
  v10 = device_by_node;
  v11 = *(_QWORD *)(*v4 + 744LL);
  v56 = 0;
  v55[0] = 0;
  v55[1] = 0;
  string_helper = of_property_read_string_helper(v11, "nvmem-names", 0, 0, 0);
  if ( (string_helper & 0x80000000) != 0 )
  {
    dev_err(*v4, "Could not find nvmem device\n");
    goto LABEL_46;
  }
  if ( string_helper != 3 )
  {
    dev_err(*v4, "Invalid num of SDAMs:%d\n", string_helper);
    goto LABEL_29;
  }
  v13 = *v4;
  *((_DWORD *)v4 + 6) = 3;
  v14 = (_DWORD *)devm_kmalloc(v13, 432, 3520);
  v4[1] = v14;
  if ( !v14 )
  {
    string_helper = -12;
    goto LABEL_46;
  }
  *v14 = 0;
  scnprintf(v55, 20, "qpt-config-sdam");
  _mutex_init(v4[1] + 16LL, "&qpt->sdam[0].lock", &qpt_parse_sdam_data___key);
  v15 = *v4;
  v16 = v4[1];
  v17 = devm_nvmem_device_get(*v4, v55);
  *(_QWORD *)(v16 + 8) = v17;
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
    string_helper = v17;
    if ( (_DWORD)v17 == -517 )
    {
      *(_QWORD *)(v16 + 8) = 0;
      string_helper = -517;
      goto LABEL_46;
    }
    dev_err(v15, "Failed to get nvmem device, rc=%d\n", v17);
    *(_QWORD *)(v16 + 8) = 0;
    if ( (string_helper & 0x80000000) != 0 )
      goto LABEL_46;
  }
  *(_DWORD *)(v4[1] + 144LL) = 1;
  _mutex_init(v4[1] + 160LL, "&qpt->sdam[1].lock", &qpt_parse_sdam_data___key_36);
  scnprintf(v55, 20, "qpt-frac-sdam");
  v18 = *v4;
  v19 = v4[1];
  v20 = devm_nvmem_device_get(*v4, v55);
  *(_QWORD *)(v19 + 152) = v20;
  if ( v20 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (_DWORD)v20 == -517 )
    {
      *(_QWORD *)(v19 + 152) = 0;
      string_helper = -517;
      goto LABEL_46;
    }
    string_helper = v20;
    dev_err(v18, "Failed to get nvmem device, rc=%d\n", v20);
    *(_QWORD *)(v19 + 152) = 0;
    if ( (string_helper & 0x80000000) != 0 )
      goto LABEL_46;
  }
  *(_DWORD *)(v4[1] + 288LL) = 2;
  _mutex_init(v4[1] + 304LL, "&qpt->sdam[2].lock", &qpt_parse_sdam_data___key_39);
  scnprintf(v55, 20, "qpt-data-sdam");
  v21 = *v4;
  v22 = v4[1];
  v23 = devm_nvmem_device_get(*v4, v55);
  *(_QWORD *)(v22 + 296) = v23;
  if ( v23 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (_DWORD)v23 == -517 )
    {
      *(_QWORD *)(v22 + 296) = 0;
      string_helper = -517;
      goto LABEL_46;
    }
    string_helper = v23;
    dev_err(v21, "Failed to get nvmem device, rc=%d\n", v23);
    *(_QWORD *)(v22 + 296) = 0;
    if ( (string_helper & 0x80000000) != 0 )
      goto LABEL_46;
  }
  v24 = of_property_count_elems_of_size(v8, "bob-channels", 2);
  if ( v24 - 1 <= 0x15 )
  {
    *((_BYTE *)v4 + 78) = v24;
    variable_u16_array = of_property_read_variable_u16_array(v8, "bob-channels", v4 + 4, v24, 0);
    if ( (variable_u16_array & 0x80000000) != 0 )
    {
      string_helper = variable_u16_array;
      dev_err(*v4, "Failed to read ppid mapping array, rc = %d\n", variable_u16_array);
      goto LABEL_46;
    }
  }
  irq = platform_get_irq(v10, 0);
  v27 = (unsigned int)irq;
  if ( irq <= 0 || (*((_DWORD *)v4 + 4) = irq, v28 = platform_get_irq(v10, 1), v27 = (unsigned int)v28, v28 <= 0) )
  {
    dev_err(*v4, "Failed to get qpt irq, rc=%d\n", v27);
LABEL_29:
    string_helper = -22;
    goto LABEL_46;
  }
  *((_DWORD *)v4 + 5) = v28;
  if ( of_find_property(v8, "power-domains", 0) )
  {
    if ( *(_QWORD *)(v10 + 608) )
    {
      pm_runtime_enable(v10 + 16);
      v4[31] = qpt_pd_callback;
      *((_DWORD *)v4 + 66) = 0x80000000;
      v29 = dev_pm_genpd_add_notifier(v10 + 16);
      if ( v29 )
      {
        string_helper = v29;
        _pm_runtime_disable(v10 + 16, 1);
        dev_err(*v4, "Failed to register for pd notifier\n");
        if ( (string_helper & 0x80000000) != 0 )
          goto LABEL_46;
      }
    }
  }
  v30 = qti_qpt_sync_common_telemetry_config(v4);
  if ( (v30 & 0x80000000) != 0 )
  {
    string_helper = v30;
LABEL_38:
    dev_err(*v4, "Failed to parse config sdam rc=%d\n", string_helper);
    goto LABEL_47;
  }
  v31 = v4[12];
  v32 = 0;
  v33 = 0;
  *((_BYTE *)v4 + 80) = -1;
  while ( 1 )
  {
    v37 = v31 + v32;
    if ( *(char *)(v31 + v32 + 8) < 0 && (*(_BYTE *)(v37 + 10) & 8) != 0 )
      break;
LABEL_55:
    v36 = v32 + 8;
    v32 += 3;
    v33 += 5;
    if ( v36 >= 0x48 )
      goto LABEL_117;
  }
  v38 = *v4;
  ++*((_DWORD *)v4 + 7);
  v39 = devm_kmalloc(v38, 152, 3520);
  if ( !v39 )
  {
    string_helper = -12;
    goto LABEL_38;
  }
  *(_BYTE *)(v39 + 36) = 1;
  v40 = v39;
  v41 = *(_BYTE *)(v37 + 8);
  *(_BYTE *)(v39 + 37) = v41 & 0x1F;
  v42 = *(unsigned __int8 *)(v31 + v32 + 9);
  *(_QWORD *)(v39 + 16) = v4;
  *(_BYTE *)(v39 + 42) = v33;
  *(_BYTE *)(v39 + 38) = v42;
  v43 = v42 & 0xFFFFE0FF | ((v41 & 0x1F) << 8);
  v44 = *((unsigned __int8 *)v4 + 78);
  *(_WORD *)(v39 + 40) = v43;
  if ( !v44 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 16) == v43 )
  {
LABEL_61:
    v45 = *((unsigned __int8 *)v4 + 81);
    *(_DWORD *)(v39 + 32) = 1;
    if ( v33 > v45 )
      *((_BYTE *)v4 + 81) = v33;
    if ( v33 < *((unsigned __int8 *)v4 + 80) )
      *((_BYTE *)v4 + 80) = v33;
LABEL_68:
    _mutex_init(v39 + 104, "&qpt_dev->lock", &qti_qpt_config_sdam_initialize___key);
    v47 = *v7;
    if ( *(__int64 **)(*v7 + 8) != v7 || (__int64 *)v40 == v7 || v47 == v40 )
    {
      _list_add_valid_or_report(v40, v4 + 23);
    }
    else
    {
      *(_QWORD *)(v47 + 8) = v40;
      *(_QWORD *)v40 = v47;
      *(_QWORD *)(v40 + 8) = v7;
      *v7 = v40;
    }
    v34 = qptm_channel_register(*v4, *(unsigned __int16 *)(v40 + 40), qpt_ops, v40);
    if ( v34 <= 0xFFFFFFFFFFFFF000LL )
      v35 = v34;
    else
      v35 = 0;
    *(_QWORD *)(v40 + 24) = v35;
    goto LABEL_55;
  }
  if ( v44 == 1 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 17) == v43 )
    goto LABEL_61;
  if ( v44 == 2 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 18) == v43 )
    goto LABEL_61;
  if ( v44 == 3 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 19) == v43 )
    goto LABEL_61;
  if ( v44 == 4 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 20) == v43 )
    goto LABEL_61;
  if ( v44 == 5 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 21) == v43 )
    goto LABEL_61;
  if ( v44 == 6 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 22) == v43 )
    goto LABEL_61;
  if ( v44 == 7 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 23) == v43 )
    goto LABEL_61;
  if ( v44 == 8 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 24) == v43 )
    goto LABEL_61;
  if ( v44 == 9 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 25) == v43 )
    goto LABEL_61;
  if ( v44 == 10 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 26) == v43 )
    goto LABEL_61;
  if ( v44 == 11 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 27) == v43 )
    goto LABEL_61;
  if ( v44 == 12 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 28) == v43 )
    goto LABEL_61;
  if ( v44 == 13 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 29) == v43 )
    goto LABEL_61;
  if ( v44 == 14 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 30) == v43 )
    goto LABEL_61;
  if ( v44 == 15 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 31) == v43 )
    goto LABEL_61;
  if ( v44 == 16 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 32) == v43 )
    goto LABEL_61;
  if ( v44 == 17 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 33) == v43 )
    goto LABEL_61;
  if ( v44 == 18 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 34) == v43 )
    goto LABEL_61;
  if ( v44 == 19 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 35) == v43 )
    goto LABEL_61;
  if ( v44 == 20 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 36) == v43 )
    goto LABEL_61;
  if ( v44 == 21 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 37) == v43 )
    goto LABEL_61;
  if ( v44 == 22 )
    goto LABEL_66;
  if ( *((unsigned __int16 *)v4 + 38) == v43 )
    goto LABEL_61;
  if ( v44 == 23 )
  {
LABEL_66:
    v46 = *((unsigned __int8 *)v4 + 79);
    *(_DWORD *)(v39 + 32) = 0;
    if ( v33 > v46 )
      *((_BYTE *)v4 + 79) = v33;
    goto LABEL_68;
  }
  __break(0x5512u);
LABEL_117:
  *((_DWORD *)v4 + 22) = 0;
  v48 = devm_request_threaded_irq(*v4, *((unsigned int *)v4 + 4), 0, qpt_sdam_irq_handler, 0x2000, "qpt_data_irq", v4);
  if ( (v48 & 0x80000000) != 0
    || (irq_modify_status(*((unsigned int *)v4 + 4), 0, 0x80000),
        v49 = *v4,
        v50 = *((unsigned int *)v4 + 5),
        *((_BYTE *)v4 + 86) = 1,
        v48 = devm_request_threaded_irq(v49, v50, 0, qpt_sdam_overflow_irq_handler, 0x2000, "qpt_overflow_irq", v4),
        (v48 & 0x80000000) != 0) )
  {
    string_helper = v48;
    dev_err(*v4, "Failed to request IRQ for qpt, rc=%d\n", v48);
    goto LABEL_47;
  }
  irq_set_irq_wake(*((unsigned int *)v4 + 5), 1);
  mutex_lock(v4 + 25);
  qti_qpt_read_all_data(v4, &print_fmt_qpt_update_channel_data[5], *((unsigned __int8 *)v4 + 79) + 5, 0, v51, v52);
  if ( *((_BYTE *)v4 + 78) )
    qti_qpt_read_all_data(
      v4,
      (const char *)((unsigned int)*((unsigned __int8 *)v4 + 80) + 69),
      *((unsigned __int8 *)v4 + 81) + 5LL,
      1);
  mutex_unlock(v4 + 25);
LABEL_122:
  v53 = *v4;
  string_helper = 0;
  *(_QWORD *)(a1 + 168) = v4;
  *(_QWORD *)(v53 + 152) = v4;
LABEL_123:
  _ReadStatusReg(SP_EL0);
  return string_helper;
}
