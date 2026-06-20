__int64 __fastcall spi_geni_probe(_QWORD *a1)
{
  __int64 v2; // x19
  __int64 property; // x21
  __int64 v4; // x0
  unsigned int file_ns; // w23
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x0
  bool v9; // w8
  __int64 v10; // x0
  int v11; // w3
  __int64 *resource_byname; // x0
  const char *v13; // x1
  __int64 v15; // x8
  __int64 v16; // x0
  char v17; // w9
  _DWORD *v18; // x22
  __int64 v19; // x24
  unsigned int v20; // w0
  char v21; // w9
  unsigned int v22; // w0
  unsigned int v23; // w0
  unsigned int v24; // w0
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x0
  unsigned int v28; // w0
  unsigned __int64 v29; // x0
  unsigned int v30; // w0
  unsigned int v31; // w0
  unsigned __int64 v32; // x0
  unsigned __int64 v33; // x0
  int irq; // w0
  unsigned int v35; // w0

  v2 = (__int64)(a1 + 2);
  property = of_find_property(a1[95], "qcom,slv-ctrl", 0);
  v4 = _spi_alloc_controller(a1 + 2, 584, property != 0);
  if ( !v4 )
  {
    dev_err(a1 + 2, "Failed to alloc spi struct\n");
    file_ns = -12;
    dev_info(a1 + 2, "%s: ret:%d\n", "spi_geni_probe", -12);
    return file_ns;
  }
  v6 = v4;
  if ( property )
    *(_QWORD *)(v4 + 1448) = spi_slv_abort;
  printk(&unk_F30E);
  a1[21] = v6;
  v7 = *(_QWORD *)(v6 + 152);
  *(_QWORD *)(v7 + 200) = v2;
  *(_QWORD *)(v7 + 8) = v2;
  *(_QWORD *)(v7 + 16) = *(_QWORD *)(a1[14] + 152LL);
  v8 = a1[95];
  *(_QWORD *)(v6 + 744) = v8;
  if ( !*(_QWORD *)(v7 + 16) )
  {
    dev_err(a1 + 2, "SE Wrapper is NULL, deferring probe\n");
    return (unsigned int)-517;
  }
  if ( of_find_property(v8, "qcom,le-vm", 0) )
  {
    *(_BYTE *)(v7 + 503) = 1;
    dev_info(a1 + 2, "LE-VM usecase\n");
  }
  if ( of_find_property(a1[95], "qcom,la-vm", 0) )
  {
    *(_BYTE *)(v7 + 504) = 1;
    dev_info(a1 + 2, "LA-VM usecase\n");
  }
  *(_BYTE *)(v6 + 1324) = of_find_property(a1[95], "qcom,rt", 0) != 0;
  *(_BYTE *)(v7 + 505) = of_find_property(a1[95], "qcom,disable-autosuspend", 0) != 0;
  if ( of_find_property(a1[95], "qcom,shared_se", 0) )
  {
    v9 = 1;
    *(_BYTE *)(v7 + 502) = 1;
  }
  else
  {
    v9 = of_find_property(a1[95], "qcom,shared_ee", 0) != 0;
  }
  *(_BYTE *)(v7 + 501) = v9;
  v10 = of_find_property(a1[95], "qcom,set-miso-sampling", 0);
  *(_BYTE *)(v7 + 507) = v10 != 0;
  if ( v10
    && (of_property_read_variable_u32_array(a1[95], "qcom,miso-sampling-ctrl-val", v7 + 508, 1, 0) & 0x80000000) == 0 )
  {
    dev_info(a1 + 2, "MISO_SAMPLING_SET: %d\n", *(_DWORD *)(v7 + 508));
  }
  *(_BYTE *)(v7 + 513) = of_find_property(a1[95], "qcom,disable-dma", 0) != 0;
  of_property_read_variable_u32_array(a1[95], "qcom,xfer-timeout-offset", v7 + 520, 1, 0);
  v11 = *(_DWORD *)(v7 + 520);
  if ( v11 )
    dev_info(a1 + 2, "%s: DT based xfer timeout offset: %d\n", "spi_get_dt_property", v11);
  if ( of_find_property(a1[95], "qcom,master-cross-connect", 0) )
    *(_BYTE *)(v7 + 517) = 1;
  *(_BYTE *)(v7 + 516) = of_find_property(a1[95], "slv-cross-connected", 0) != 0;
  if ( (of_property_read_variable_u32_array(a1[95], "spi-max-frequency", v6 + 952, 1, 0) & 0x80000000) != 0 )
  {
    file_ns = -6;
    v13 = "Max frequency not specified.\n";
    goto LABEL_27;
  }
  if ( of_find_property(a1[95], "qcom,split-tx-dma-tre", 0) )
    *(_BYTE *)(v7 + 536) = 1;
  resource_byname = (__int64 *)platform_get_resource_byname(a1, 512, "se_phys");
  if ( !resource_byname )
  {
    file_ns = -6;
    v13 = "Err getting IO region\n";
LABEL_27:
    dev_err(v2, v13);
LABEL_28:
    dev_info(v2, "%s: ret:%d\n", "spi_geni_probe", file_ns);
    put_device(v6);
    return file_ns;
  }
  v15 = *resource_byname;
  *(_QWORD *)(v7 + 168) = *resource_byname;
  *(_QWORD *)(v7 + 176) = resource_byname[1] - v15 + 1;
  v16 = devm_ioremap(a1 + 2);
  *(_QWORD *)(v7 + 184) = v16;
  if ( !v16 )
  {
    file_ns = -12;
    v13 = "Err IO mapping iomem\n";
    goto LABEL_27;
  }
  v17 = *(_BYTE *)(v7 + 503);
  *(_QWORD *)(v7 + 288) = a1[14];
  if ( (v17 & 1) != 0 )
  {
    v18 = nullptr;
    goto LABEL_34;
  }
  v22 = geni_icc_get(v7, "qup-memory");
  if ( v22 )
  {
    file_ns = v22;
    v13 = "Error geni_se_resources_init\n";
    goto LABEL_27;
  }
  *(_DWORD *)(v7 + 56) = 51000;
  *(_DWORD *)(v7 + 72) = 140000;
  *(_DWORD *)(v7 + 88) = 76800;
  v23 = geni_icc_set_bw(v7);
  if ( v23 )
  {
    file_ns = v23;
    dev_err(a1 + 2, "%s: icc set bw failed ret:%d\n", "geni_spi_resources_init", v23);
    goto LABEL_28;
  }
  v24 = geni_icc_enable(v7);
  if ( v24 )
  {
    file_ns = v24;
    dev_err(a1 + 2, "%s: icc enable failed ret:%d\n", "geni_spi_resources_init", v24);
    goto LABEL_28;
  }
  v25 = devm_pinctrl_get(a1 + 2);
  *(_QWORD *)(v7 + 136) = v25;
  if ( v25 && v25 < 0xFFFFFFFFFFFFF001LL )
  {
    v26 = ((__int64 (*)(void))pinctrl_lookup_state)();
    *(_QWORD *)(v7 + 144) = v26;
    if ( v26 && v26 < 0xFFFFFFFFFFFFF001LL )
    {
      v27 = pinctrl_lookup_state(*(_QWORD *)(v7 + 136), "sleep");
      *(_QWORD *)(v7 + 152) = v27;
      if ( v27 && v27 < 0xFFFFFFFFFFFFF001LL )
      {
        v28 = pinctrl_select_state(*(_QWORD *)(v7 + 136), v27);
        if ( v28 )
        {
          file_ns = v28;
          v13 = "Failed to set sleep configuration\n";
          goto LABEL_27;
        }
        v29 = devm_clk_get(a1 + 2, "se-clk");
        *(_QWORD *)(v7 + 24) = v29;
        if ( v29 < 0xFFFFFFFFFFFFF001LL )
        {
          v32 = devm_clk_get(a1[14], "m-ahb");
          *(_QWORD *)(v7 + 120) = v32;
          if ( v32 < 0xFFFFFFFFFFFFF001LL )
          {
            v33 = devm_clk_get(a1[14], "s-ahb");
            *(_QWORD *)(v7 + 128) = v33;
            if ( v33 < 0xFFFFFFFFFFFFF001LL )
            {
              irq = platform_get_irq(a1, 0);
              *(_DWORD *)(v7 + 192) = irq;
              if ( (irq & 0x80000000) == 0 )
              {
                irq_modify_status();
                v35 = devm_request_threaded_irq(a1 + 2, *(unsigned int *)(v7 + 192), geni_spi_irq, 0, 4, "spi_geni", v7);
                v18 = (_DWORD *)v7;
                if ( v35 )
                {
                  file_ns = v35;
                  dev_err(v2, "Request_irq failed:%d: err:%d\n", *(_DWORD *)(v7 + 192), v35);
                  goto LABEL_28;
                }
                goto LABEL_34;
              }
              dev_err(a1 + 2, "Err getting IRQ\n");
              file_ns = *(_DWORD *)(v7 + 192);
            }
            else
            {
              file_ns = v33;
              dev_err(a1 + 2, "Err getting S AHB clk %d\n", (unsigned int)v33);
            }
          }
          else
          {
            file_ns = v32;
            dev_err(a1 + 2, "Err getting M AHB clk %d\n", (unsigned int)v32);
          }
        }
        else
        {
          file_ns = v29;
          dev_err(a1 + 2, "Err getting SE Core clk %d\n", v29);
        }
      }
      else
      {
        dev_err(a1 + 2, "No sleep config specified!\n");
        file_ns = *(_DWORD *)(v7 + 152);
      }
    }
    else
    {
      dev_err(a1 + 2, "No default config specified!\n");
      file_ns = *(_DWORD *)(v7 + 144);
    }
  }
  else
  {
    dev_err(a1 + 2, "No pinctrl config specified!\n");
    file_ns = *(_DWORD *)(v7 + 136);
  }
  v18 = (_DWORD *)v7;
  if ( file_ns )
    goto LABEL_28;
LABEL_34:
  *(_DWORD *)(v7 + 160) = 0;
  v19 = -1;
  if ( (unsigned int)dma_set_mask(v2, -1) )
  {
    v19 = 0xFFFFFFFFLL;
    v20 = dma_set_mask(v2, 0xFFFFFFFFLL);
    if ( v20 )
    {
      file_ns = v20;
      v13 = "could not set DMA mask\n";
      goto LABEL_27;
    }
  }
  dma_set_coherent_mask(v2, v19);
  v21 = *(_BYTE *)(v7 + 503);
  *(_QWORD *)v7 = *(_QWORD *)(v7 + 184);
  if ( (v21 & 1) == 0 )
  {
    file_ns = spi_verify_proto(v7);
    if ( file_ns )
      goto LABEL_28;
  }
  if ( *(_DWORD *)(v7 + 528) == 9 )
  {
    *(_DWORD *)(v6 + 936) = 3847;
    *(_BYTE *)(v7 + 532) = 0;
  }
  else
  {
    *(_DWORD *)(v6 + 936) = 39;
  }
  *(_BYTE *)(v7 + 580) = 0;
  *(_DWORD *)(v6 + 944) = -8;
  *(_WORD *)(v6 + 930) = 4;
  *(_QWORD *)(v6 + 1408) = spi_geni_prepare_transfer_hardware;
  *(_QWORD *)(v6 + 1432) = spi_geni_prepare_message;
  *(_QWORD *)(v6 + 1440) = spi_geni_unprepare_message;
  *(_QWORD *)(v6 + 1464) = spi_geni_transfer_one;
  *(_QWORD *)(v6 + 1424) = spi_geni_unprepare_transfer_hardware;
  *(_BYTE *)(v6 + 1325) = 0;
  *(_DWORD *)(v7 + 256) = 0;
  _init_swait_queue_head(v7 + 264, "&x->wait", &init_completion___key);
  *(_DWORD *)(v7 + 384) = 0;
  _init_swait_queue_head(v7 + 392, "&x->wait", &init_completion___key);
  *(_DWORD *)(v7 + 416) = 0;
  _init_swait_queue_head(v7 + 424, "&x->wait", &init_completion___key);
  _pm_runtime_set_status(v2, 2);
  if ( (*(_BYTE *)(v7 + 503) & 1) == 0 && (*(_BYTE *)(v7 + 505) & 1) == 0 )
  {
    pm_runtime_set_autosuspend_delay(v2, 250);
    _pm_runtime_use_autosuspend(v2, 1);
  }
  pm_runtime_enable(v2);
  if ( (*(_BYTE *)(v7 + 503) & 1) == 0 )
  {
    ipc_log_string(
      *(_QWORD *)(v7 + 472),
      "%s: GENI_TO_CORE:%d CPU_TO_GENI:%d GENI_TO_DDR:%d\n",
      "spi_geni_probe",
      v18[14],
      v18[18],
      v18[22]);
    if ( *(_QWORD *)(v7 + 200) )
      spi_trace_log();
  }
  if ( (*(_BYTE *)(v7 + 503) & 1) == 0 )
  {
    v30 = geni_icc_disable(v18);
    if ( v30 )
    {
      file_ns = v30;
      dev_err(v2, "%s: icc disable failed ret:%d\n", "spi_geni_probe", v30);
      return file_ns;
    }
  }
  v31 = spi_register_controller(v6);
  if ( v31 )
  {
    file_ns = v31;
    v13 = "Failed to register SPI master\n";
    goto LABEL_27;
  }
  if ( (unsigned int)device_create_file(*(_QWORD *)(v7 + 200), &dev_attr_spi_max_dump_size) )
    dev_err(v2, "Unable to create device file for max_dump_size\n");
  *(_DWORD *)(v7 + 524) = 16;
  create_ipc_context((_QWORD *)v7, v2);
  file_ns = sysfs_create_file_ns(*(_QWORD *)(v7 + 200), &dev_attr_spi_slave_state, 0);
  device_create_file(*(_QWORD *)(v7 + 200), &dev_attr_capture_kpi);
  *(_BYTE *)(v7 + 518) = 0;
  dev_info(v2, "%s: completed %d\n", "spi_geni_probe", file_ns);
  printk(&unk_EE3D);
  return file_ns;
}
