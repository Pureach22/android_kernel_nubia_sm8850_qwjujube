__int64 __fastcall secure_etr_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  _QWORD *v3; // x0
  _QWORD *v4; // x20
  unsigned __int64 platform_data; // x21
  unsigned int v6; // w0
  unsigned int string; // w23
  unsigned __int64 v8; // x0
  unsigned int variable_u32_array; // w0
  unsigned __int64 v10; // x0
  __int64 v11; // x22
  __int64 v12; // x0
  unsigned int v13; // w0
  unsigned __int64 v14; // x0
  _QWORD v16[2]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 (__fastcall ***v17)(); // [xsp+18h] [xbp-98h]
  unsigned __int64 v18; // [xsp+20h] [xbp-90h]
  _QWORD *v19; // [xsp+28h] [xbp-88h]
  _UNKNOWN **v20; // [xsp+30h] [xbp-80h]
  __int64 v21; // [xsp+38h] [xbp-78h]
  __int64 v22; // [xsp+40h] [xbp-70h]
  __int64 v23; // [xsp+48h] [xbp-68h]
  __int64 v24; // [xsp+50h] [xbp-60h]
  _QWORD v25[11]; // [xsp+58h] [xbp-58h] BYREF

  v1 = a1 + 2;
  v25[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = nullptr;
  v20 = nullptr;
  v17 = nullptr;
  v18 = 0;
  v16[0] = 0;
  v16[1] = 0;
  v3 = (_QWORD *)devm_kmalloc(a1 + 2, 288, 3520);
  if ( !v3 )
    goto LABEL_19;
  v4 = v3;
  *v3 = v1;
  a1[21] = v3;
  platform_data = coresight_get_platform_data(v1);
  v6 = dma_set_mask(v1, -1);
  if ( v6 )
  {
    string = v6;
    if ( (v6 & 0x80000000) != 0 )
      goto LABEL_20;
    if ( platform_data >= 0xFFFFFFFFFFFFF001LL )
    {
LABEL_5:
      string = platform_data;
      goto LABEL_20;
    }
  }
  else
  {
    dma_set_coherent_mask(v1, -1);
    if ( platform_data >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_5;
  }
  a1[20] = platform_data;
  *((_DWORD *)v4 + 60) = 0;
  _mutex_init(v4 + 24, "&drvdata->mem_lock", &secure_etr_probe___key);
  v8 = devm_clk_get(v1, "apb_pclk");
  v4[35] = v8;
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
    dev_err(v1, "not config clk\n");
  string = of_property_read_string(a1[95], "real-name", v4 + 21);
  if ( !string )
  {
    variable_u32_array = of_property_read_variable_u32_array(a1[95], "qdss,buffer-size", (char *)v4 + 276, 1, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      string = variable_u32_array;
      goto LABEL_20;
    }
    if ( (unsigned int)of_get_coresight_csr_name(a1[95], v4 + 33) )
    {
      dev_err(v1, "No csr data\n");
    }
    else
    {
      v10 = coresight_csr_get(v4[33]);
      v4[32] = v10;
      if ( v10 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(v1, "failed to get csr, defer probe\n");
        string = -517;
        goto LABEL_20;
      }
    }
    of_property_read_variable_u32_array(a1[95], "csr-atid-offset", v4 + 34, 1, 0);
    v11 = *v4;
    v12 = *(_QWORD *)(*v4 + 744LL);
    memset(v25, 0, 80);
    if ( !(unsigned int)_of_parse_phandle_with_args(v12, "memory-region", 0, 0, 0, v25) )
    {
      if ( v25[0] )
      {
        v13 = of_reserved_mem_device_init_by_idx(v11, *(_QWORD *)(v11 + 744), 0);
        if ( v13 )
        {
          string = v13;
          dev_err(v11, "Failed to initialize reserved mem, ret %d\n", v13);
          goto LABEL_20;
        }
      }
    }
    v21 = coresight_alloc_device_name(&secure_etr_devs, v1);
    if ( v21 )
    {
      v16[0] = 0x300000000LL;
      v18 = platform_data;
      v19 = v1;
      v17 = &secure_etr_cs_ops;
      v20 = &coresight_secure_etr_groups;
      v14 = coresight_register(v16);
      v4[1] = v14;
      if ( v14 < 0xFFFFFFFFFFFFF001LL )
      {
        v4[2] = v21;
        string = sec_etr_sram_dev_register(v4);
        if ( string )
          coresight_unregister(v4[1]);
        else
          pm_runtime_enable(v1);
      }
      else
      {
        string = v14;
      }
      goto LABEL_20;
    }
LABEL_19:
    string = -12;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return string;
}
