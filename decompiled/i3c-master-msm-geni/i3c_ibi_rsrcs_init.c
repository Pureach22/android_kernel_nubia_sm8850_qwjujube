unsigned __int64 __fastcall i3c_ibi_rsrcs_init(__int64 a1, _QWORD *a2)
{
  __int64 resource; // x0
  unsigned __int64 result; // x0
  char v6; // w0
  __int64 v7; // x8
  int v8; // w8
  __int64 v9; // x0
  unsigned int irq; // w0
  __int64 v11; // x5
  __int64 v12; // x0
  unsigned __int64 v13; // x20
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int v19; // w0
  __int64 v20; // x5
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x0
  __int64 v26; // x3
  __int64 v27; // x0
  __int64 v28; // x2
  __int64 v29; // x0
  int v30; // w0
  unsigned int v31; // w21
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x0

  if ( (of_property_read_variable_u32_array(a2[95], "qcom,ibi-ctrl-id", a1 + 21444, 1, 0) & 0x80000000) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "IBI controller instance id is not defined\n");
    v17 = *(_QWORD *)(a1 + 8);
    if ( v17 )
    {
      dev_err(v17, "IBI controller instance id is not defined\n");
      if ( !*(_QWORD *)(a1 + 8) )
        return 4294967290LL;
    }
    else
    {
      printk(&unk_13DB5, v14, v15, v16);
      if ( !*(_QWORD *)(a1 + 8) )
        return 4294967290LL;
    }
    i3c_trace_log();
    return 4294967290LL;
  }
  if ( of_find_property(a2[95], "qcom,ibic-naon", 0) )
  {
    *(_BYTE *)(a1 + 21460) = 1;
    dev_info(a2 + 2, "%s:I3C IBI is NAON cntrl\n", "i3c_ibi_rsrcs_init");
    if ( (unsigned int)i3c_naon_ibi_clk_init(a1) || (unsigned int)geni_i3c_enable_naon_ibi_clks(a1, 1) )
      return 4294967274LL;
  }
  msm_qup_write(*(unsigned int *)(a1 + 21444), 36);
  resource = platform_get_resource(a2, 512, 1);
  if ( !resource )
    return 4294967274LL;
  result = devm_ioremap_resource(a2 + 2, resource);
  *(_QWORD *)(a1 + 21328) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  v6 = readl_relaxed((unsigned int *)(*(_QWORD *)a1 + 3620LL));
  *(_BYTE *)(a1 + 21320) = v6 < 0;
  if ( (v6 & 0x80) == 0 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "IBI controller support not present\n");
    v25 = *(_QWORD *)(a1 + 8);
    if ( v25 )
      dev_err(v25, "IBI controller support not present\n");
    else
      printk(&unk_1428E, v22, v23, v24);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    return 4294967277LL;
  }
  *(_DWORD *)(a1 + 21360) = 0;
  _init_swait_queue_head(a1 + 21368, "&x->wait", &init_completion___key);
  v7 = *(_QWORD *)(a1 + 21328);
  *(_DWORD *)(a1 + 21352) = 0;
  v8 = readl_relaxed((unsigned int *)(v7 + 28)) & 0x1F;
  *(_DWORD *)(a1 + 21336) = v8;
  if ( !v8 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "Invalid num_slots:%d\n", 0);
    v27 = *(_QWORD *)(a1 + 8);
    v28 = *(unsigned int *)(a1 + 21336);
    if ( v27 )
      dev_err(v27, "Invalid num_slots:%d\n", v28);
    else
      printk(&unk_13894, (unsigned int)v28, v28, v26);
    if ( *(_QWORD *)(a1 + 8) )
    {
      i3c_trace_log();
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v9 = devm_kmalloc(a2 + 2, (unsigned int)(8 * v8), 3520);
  *(_QWORD *)(a1 + 21344) = v9;
  if ( !v9 )
    return 4294967284LL;
  if ( of_find_property(a2[95], "qcom,ibic-naon", 0) )
  {
    *(_BYTE *)(a1 + 21460) = 1;
    dev_info(a2 + 2, "IBI is NAON controller\n");
    v30 = i3c_naon_ibi_clk_init(a1);
    if ( v30 )
    {
      v31 = v30;
      ipc_log_string(*(_QWORD *)(a1 + 2528), "NAON IBI clock failed to init:%d\n", v30);
      v34 = *(_QWORD *)(a1 + 8);
      if ( v34 )
        dev_err(v34, "NAON IBI clock failed to init:%d\n", v31);
      else
        printk(&unk_12D17, v31, v32, v33);
      if ( *(_QWORD *)(a1 + 8) )
        i3c_trace_log();
    }
  }
  irq = platform_get_irq(a2, 1);
  *(_DWORD *)(a1 + 21356) = irq;
  if ( (irq & 0x80000000) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "IRQ error for ibi_c manager\n");
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    return *(unsigned int *)(a1 + 21356);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 21654) == 1 )
    {
      v11 = a2[16];
      if ( !v11 )
        v11 = a2[2];
      v12 = devm_request_threaded_irq(a2 + 2, irq, geni_i3c_ibi_irq, 0, 4, v11, a1);
      if ( (_DWORD)v12 )
      {
        v13 = v12;
        ipc_log_string(*(_QWORD *)(a1 + 2528), "Request_irq:%d: err:%d\n", *(_DWORD *)(a1 + 21356), v12);
        if ( !*(_QWORD *)(a1 + 8) )
          goto LABEL_39;
        goto LABEL_38;
      }
      if ( (*(_BYTE *)(a1 + 21460) & 1) == 0 )
      {
        v18 = irq_set_irq_wake(*(unsigned int *)(a1 + 21356), 1);
        if ( (_DWORD)v18 )
        {
          v13 = v18;
          ipc_log_string(
            *(_QWORD *)(a1 + 2528),
            "Failed to set mngr IRQ(%d) wake: err:%d\n",
            *(_DWORD *)(a1 + 21356),
            v18);
          if ( !*(_QWORD *)(a1 + 8) )
            goto LABEL_39;
          goto LABEL_38;
        }
      }
    }
    v19 = platform_get_irq(a2, 2);
    *(_DWORD *)(a1 + 21392) = v19;
    if ( (v19 & 0x80000000) == 0 )
    {
      v20 = a2[16];
      if ( !v20 )
        v20 = a2[2];
      v21 = devm_request_threaded_irq(a2 + 2, v19, geni_i3c_ibi_irq, 0, 4, v20, a1);
      if ( (_DWORD)v21 )
      {
        v13 = v21;
        ipc_log_string(*(_QWORD *)(a1 + 2528), "Request_irq failed:%d: err:%d\n", *(_DWORD *)(a1 + 21392), v21);
        if ( !*(_QWORD *)(a1 + 8) )
          goto LABEL_39;
      }
      else
      {
        if ( (*(_BYTE *)(a1 + 21460) & 1) != 0 )
          goto LABEL_53;
        v29 = irq_set_irq_wake(*(unsigned int *)(a1 + 21392), 1);
        if ( !(_DWORD)v29 )
          goto LABEL_53;
        v13 = v29;
        ipc_log_string(
          *(_QWORD *)(a1 + 2528),
          "Failed to set gpii IRQ(%d) wake: err:%d\n",
          *(_DWORD *)(a1 + 21392),
          v29);
        if ( !*(_QWORD *)(a1 + 8) )
        {
LABEL_39:
          result = v13;
          if ( (v13 & 0x80000000) != 0 )
            return result;
LABEL_53:
          qcom_geni_i3c_ibi_conf(a1);
          return 0;
        }
      }
LABEL_38:
      i3c_trace_log();
      goto LABEL_39;
    }
    ipc_log_string(*(_QWORD *)(a1 + 2528), "IRQ error for ibi_c gpii\n");
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    result = *(unsigned int *)(a1 + 21392);
    if ( (result & 0x80000000) == 0 )
      goto LABEL_53;
  }
  return result;
}
