__int64 __fastcall wcd9378_bind(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v2; // x22
  unsigned int v4; // w0
  __int64 matching_swr_slave_device; // x0
  unsigned int v6; // w21
  __int64 v7; // x0
  __int64 inited; // x0
  __int64 v10; // x10
  __int64 v11; // x0

  v2 = *(_QWORD *)(a1 + 144);
  v1 = *(__int64 **)(a1 + 152);
  usleep_range_state(5000, 5010, 2);
  v4 = component_bind_all(a1, v1);
  if ( !v4 )
  {
    matching_swr_slave_device = get_matching_swr_slave_device(*(_QWORD *)(v2 + 8));
    v1[7] = matching_swr_slave_device;
    if ( matching_swr_slave_device )
    {
      *(_BYTE *)(matching_swr_slave_device + 993) = 1;
      v7 = get_matching_swr_slave_device(*(_QWORD *)(v2 + 16));
      v1[8] = v7;
      if ( v7 )
      {
        *(_BYTE *)(v7 + 993) = 1;
        swr_init_port_params(v1[8], 4, v1 + 395);
        inited = _devm_regmap_init_swr(v1[8], &wcd9378_regmap_config, 0, 0);
        v1[6] = inited;
        if ( inited )
        {
          regmap_write(inited, 244, 255);
          regmap_write(v1[6], 248, 11);
          regmap_write(v1[6], 252, 255);
          qword_508 = (__int64)v1;
          v10 = v1[6];
          v1[51] = (__int64)&wcd9378_regmap_irq_chip;
          v1[52] = (__int64)"WCD9378";
          v1[55] = a1;
          v1[53] = v10;
          v6 = wcd_irq_init(v1 + 51, v1 + 50);
          v11 = *v1;
          if ( v6 )
          {
            dev_err(v11, "%s: IRQ init failed: %d\n", "wcd9378_bind", v6);
          }
          else
          {
            dev_err(v11, "%s: wcd irq init done\n", "wcd9378_bind");
            *(_QWORD *)(v1[8] + 1000) = v1[50];
            wcd_request_irq(v1 + 51, 14, "HPHR PDM WD INT", wcd9378_wd_handle_irq, 0);
            wcd_request_irq(v1 + 51, 13, "HPHL PDM WD INT", wcd9378_wd_handle_irq, 0);
            wcd_request_irq(v1 + 51, 15, "AUX PDM WD INT", wcd9378_wd_handle_irq, 0);
            wcd_disable_irq(v1 + 51, 14);
            wcd_disable_irq(v1 + 51, 13);
            wcd_disable_irq(v1 + 51, 15);
            v6 = snd_soc_register_component(a1, &soc_codec_dev_wcd9378, &wcd9378_dai, 1);
            if ( !v6 )
              return v6;
            dev_err(a1, "%s: Codec registration failed\n", "wcd9378_bind");
            wcd_irq_exit(v1 + 51, v1[50]);
          }
        }
        else
        {
          dev_err(a1, "%s: Regmap init failed\n", "wcd9378_bind");
          v6 = 0;
        }
        goto LABEL_8;
      }
      dev_err(a1, "%s: Could not find TX swr slave device\n", "wcd9378_bind");
    }
    else
    {
      dev_err(a1, "%s: Could not find RX swr slave device\n", "wcd9378_bind");
    }
    v6 = -19;
LABEL_8:
    component_unbind_all(a1, v1);
    return v6;
  }
  v6 = v4;
  dev_err(a1, "%s: Slave bind failed, ret = %d\n", "wcd9378_bind", v4);
  return v6;
}
