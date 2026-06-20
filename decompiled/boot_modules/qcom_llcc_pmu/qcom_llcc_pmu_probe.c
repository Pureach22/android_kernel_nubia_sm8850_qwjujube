__int64 __fastcall qcom_llcc_pmu_probe(__int64 a1)
{
  int match_data; // w0
  _QWORD *v3; // x8
  const void *resource_byname; // x20
  unsigned __int64 v5; // x8
  int v6; // w20
  unsigned __int64 v7; // x21
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x22
  int variable_u32_array; // w0
  char v12; // w11
  int v13; // w8
  int v14; // w12
  bool v15; // zf
  unsigned __int64 v16; // x11
  unsigned __int64 v17; // x11
  bool v18; // cf
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( llccpmu )
  {
    dev_err(a1 + 16, "Only one LLCC PMU allowed!\n");
    result = 4294967277LL;
    goto LABEL_11;
  }
  llccpmu = devm_kmalloc(a1 + 16, 1464, 3520);
  if ( llccpmu )
  {
    match_data = of_device_get_match_data(a1 + 16);
    v3 = (_QWORD *)llccpmu;
    *(_DWORD *)(llccpmu + 1456) = match_data;
    if ( !match_data )
    {
      printk(&unk_6EDB);
      result = 4294967277LL;
      goto LABEL_11;
    }
    v3[12] = 0xFFFFFFFF00000000LL;
    v3[13] = 0;
    v3[16] = qcom_llcc_event_init;
    v3[17] = 0;
    v3[18] = 0;
    v3[19] = qcom_llcc_event_add;
    v3[20] = qcom_llcc_event_del;
    v3[21] = qcom_llcc_event_start;
    v3[10] = 0;
    v3[11] = 0;
    v3[8] = 0;
    v3[9] = 0;
    v3[6] = 0;
    v3[7] = 0;
    v3[4] = 0;
    v3[5] = 0;
    v3[2] = 0;
    v3[3] = 0;
    *v3 = 0;
    v3[1] = 0;
    v3[14] = 0;
    v3[15] = 0;
    v3[22] = qcom_llcc_event_stop;
    v3[23] = qcom_llcc_event_read;
    v3[24] = 0;
    v3[25] = 0;
    v3[26] = 0;
    v3[27] = 0;
    v3[28] = 0;
    v3[29] = 0;
    v3[30] = 0;
    v3[31] = 0;
    v3[32] = 0;
    v3[33] = 0;
    v3[34] = 0;
    v3[35] = 0;
    v3[36] = 0;
    v3[37] = 0;
    v3[38] = 0;
    resource_byname = (const void *)platform_get_resource_byname(a1, 512, "lagg-base");
    v5 = devm_ioremap_resource(a1 + 16, resource_byname);
    *(_QWORD *)(llccpmu + 328) = v5;
    if ( v5 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(a1 + 16, "Can't map PMU lagg base: @%pa\n", resource_byname);
      result = *(unsigned int *)(llccpmu + 328);
      goto LABEL_11;
    }
    counter_lock = 0;
    users_lock = 0;
    v6 = perf_pmu_register();
    if ( v6 < 0 )
      dev_err(a1 + 16, "Failed to register LLCC PMU (%d)\n", v6);
    if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,idx-tbl", &v19) )
    {
      v19 >>= 2;
      if ( v19 < 0 )
        goto LABEL_10;
      v7 = 4LL * (unsigned int)v19;
      v8 = _kmalloc_noprof(v7, 3520);
      if ( !v8 )
        goto LABEL_10;
      v10 = v8;
      variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,idx-tbl");
      if ( variable_u32_array < 0 )
      {
        v6 = variable_u32_array;
        dev_err(a1 + 16, "error reading idx table: %d\n", variable_u32_array);
LABEL_32:
        kfree(v10);
        result = v6 & (unsigned int)(v6 >> 31);
        goto LABEL_11;
      }
      v6 = 0;
    }
    else
    {
      v7 = 0;
      v10 = 0;
    }
    v12 = 0;
    v13 = _cpu_possible_mask;
    do
    {
      v16 = (unsigned int)(-1LL << v12) & v13;
      if ( !(_DWORD)v16 )
        break;
      v17 = __clz(__rbit64(v16));
      if ( v10 )
      {
        v18 = v7 >= 4 * v17 && v7 - 4 * v17 >= 4;
        if ( !v18 || (v14 = *(_DWORD *)(v10 + 4 * v17), v17 > 0x1F) )
        {
LABEL_30:
          __break(1u);
          break;
        }
      }
      else
      {
        v14 = v17;
        if ( v17 > 0x1F )
          goto LABEL_30;
      }
      v15 = v17 == 31;
      phys_cpu[v17] = v14;
      v12 = v17 + 1;
    }
    while ( !v15 );
    dev_info(a1 + 16, "Registered llcc_pmu, type: %d\n", *(_DWORD *)(llccpmu + 64));
    goto LABEL_32;
  }
LABEL_10:
  result = 4294967284LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
