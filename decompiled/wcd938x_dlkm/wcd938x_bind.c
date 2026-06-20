__int64 __fastcall wcd938x_bind(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x25
  unsigned int v4; // w0
  unsigned int v5; // w21
  __int64 matching_swr_slave_device; // x0
  __int64 v7; // x0
  __int64 inited; // x0
  int v9; // w22
  __int64 v10; // x10
  unsigned int v11; // w0
  int v13; // w8
  unsigned int v14; // w22
  int v15; // w8
  unsigned int v16; // w23
  int v17; // w8
  unsigned int v18; // w24
  int v19; // w8
  unsigned int v20; // w25

  v2 = *(_QWORD *)(a1 + 144);
  v1 = *(_QWORD **)(a1 + 152);
  usleep_range_state(5000, 5010, 2);
  v4 = component_bind_all(a1, v1);
  if ( !v4 )
  {
    matching_swr_slave_device = get_matching_swr_slave_device(*(_QWORD *)(v2 + 8));
    v1[5] = matching_swr_slave_device;
    if ( matching_swr_slave_device )
    {
      v7 = get_matching_swr_slave_device(*(_QWORD *)(v2 + 16));
      v1[6] = v7;
      if ( v7 )
      {
        swr_init_port_params(v7, 4, v1 + 382);
        inited = _devm_regmap_init_swr(v1[6], &wcd938x_regmap_config, 0, 0);
        v1[4] = inited;
        if ( !inited )
        {
          if ( (unsigned int)__ratelimit(&wcd938x_bind__rs_98, "wcd938x_bind") )
            dev_err(a1, "%s: Regmap init failed\n", "wcd938x_bind");
          v5 = 0;
          goto LABEL_17;
        }
        if ( dword_8A0 >= 1 )
        {
          v9 = 0;
          do
          {
            regmap_write(v1[4], (unsigned int)(v9 + 13428), 0);
            ++v9;
          }
          while ( v9 < dword_8A0 );
        }
        qword_8E8 = (__int64)v1;
        v10 = v1[4];
        v1[38] = &wcd938x_regmap_irq_chip;
        v1[39] = "WCD938X";
        v1[42] = a1;
        v1[40] = v10;
        v11 = wcd_irq_init(v1 + 38, v1 + 37);
        if ( v11 )
        {
          v5 = v11;
          if ( (unsigned int)__ratelimit(&wcd938x_bind__rs_101, "wcd938x_bind") )
            dev_err(*v1, "%s: IRQ init failed: %d\n", "wcd938x_bind", v5);
          goto LABEL_17;
        }
        *(_QWORD *)(v1[6] + 1000LL) = v1[37];
        if ( v2 )
        {
          v13 = *(_DWORD *)(v2 + 32);
          if ( (unsigned int)(v13 - 2851) > 0xFFFFF8C4 )
          {
            v14 = (unsigned __int16)(v13 - 1000) / 0x32u;
          }
          else
          {
            if ( (unsigned int)__ratelimit(&wcd938x_get_micb_vout_ctl_val__rs, "wcd938x_get_micb_vout_ctl_val") )
              printk(&unk_124B2, "wcd938x_get_micb_vout_ctl_val");
            v14 = -22;
          }
          v15 = *(_DWORD *)(v2 + 36);
          if ( (unsigned int)(v15 - 2851) > 0xFFFFF8C4 )
          {
            v16 = (unsigned __int16)(v15 - 1000) / 0x32u;
          }
          else
          {
            if ( (unsigned int)__ratelimit(&wcd938x_get_micb_vout_ctl_val__rs, "wcd938x_get_micb_vout_ctl_val") )
              printk(&unk_124B2, "wcd938x_get_micb_vout_ctl_val");
            v16 = -22;
          }
          v17 = *(_DWORD *)(v2 + 40);
          if ( (unsigned int)(v17 - 2851) > 0xFFFFF8C4 )
          {
            v18 = (unsigned __int16)(v17 - 1000) / 0x32u;
          }
          else
          {
            if ( (unsigned int)__ratelimit(&wcd938x_get_micb_vout_ctl_val__rs, "wcd938x_get_micb_vout_ctl_val") )
              printk(&unk_124B2, "wcd938x_get_micb_vout_ctl_val");
            v18 = -22;
          }
          v19 = *(_DWORD *)(v2 + 44);
          if ( (unsigned int)(v19 - 2851) > 0xFFFFF8C4 )
          {
            v20 = (unsigned __int16)(v19 - 1000) / 0x32u;
            v5 = -22;
            if ( (v14 & 0x80000000) != 0 )
              goto LABEL_54;
          }
          else
          {
            if ( (unsigned int)__ratelimit(&wcd938x_get_micb_vout_ctl_val__rs, "wcd938x_get_micb_vout_ctl_val") )
              printk(&unk_124B2, "wcd938x_get_micb_vout_ctl_val");
            v20 = -22;
            v5 = -22;
            if ( (v14 & 0x80000000) != 0 )
              goto LABEL_54;
          }
          if ( (v16 & 0x80000000) == 0 && (v18 & 0x80000000) == 0 && (v20 & 0x80000000) == 0 )
          {
            regmap_update_bits_base(v1[4], 12322, 63, v14, 0, 0, 0);
            regmap_update_bits_base(v1[4], 12323, 63, v16, 0, 0, 0);
            regmap_update_bits_base(v1[4], 12325, 63, v18, 0, 0, 0);
            regmap_update_bits_base(v1[4], 12326, 63, v20, 0, 0, 0);
            wcd_request_irq(v1 + 38, 14, "HPHR PDM WD INT", wcd938x_wd_handle_irq, 0);
            wcd_request_irq(v1 + 38, 13, "HPHL PDM WD INT", wcd938x_wd_handle_irq, 0);
            wcd_request_irq(v1 + 38, 15, "AUX PDM WD INT", wcd938x_wd_handle_irq, 0);
            wcd_disable_irq(v1 + 38, 14);
            wcd_disable_irq(v1 + 38, 13);
            wcd_disable_irq(v1 + 38, 15);
            v5 = snd_soc_register_component(a1, &soc_codec_dev_wcd938x, &wcd938x_dai, 1);
            if ( !v5 )
            {
              *((_BYTE *)v1 + 3192) = 1;
              return v5;
            }
            if ( (unsigned int)__ratelimit(&wcd938x_bind__rs_108, "wcd938x_bind") )
              dev_err(a1, "%s: Codec registration failed\n", "wcd938x_bind");
            goto LABEL_56;
          }
        }
        else
        {
          dev_err(*v1, "%s: NULL pdata\n", "wcd938x_set_micbias_data");
          v5 = -19;
        }
LABEL_54:
        if ( (unsigned int)__ratelimit(&wcd938x_bind__rs_103, "wcd938x_bind") )
          dev_err(a1, "%s: bad micbias pdata\n", "wcd938x_bind");
LABEL_56:
        wcd_irq_exit(v1 + 38, v1[37]);
        goto LABEL_17;
      }
      if ( !(unsigned int)__ratelimit(&wcd938x_bind__rs_96, "wcd938x_bind") )
        goto LABEL_16;
      dev_err(a1, "%s: Could not find TX swr slave device\n", "wcd938x_bind");
    }
    else
    {
      if ( !(unsigned int)__ratelimit(&wcd938x_bind__rs_94, "wcd938x_bind") )
      {
LABEL_16:
        v5 = -19;
LABEL_17:
        component_unbind_all(a1, v1);
        return v5;
      }
      dev_err(a1, "%s: Could not find RX swr slave device\n", "wcd938x_bind");
    }
    v5 = -19;
    goto LABEL_17;
  }
  v5 = v4;
  if ( (unsigned int)__ratelimit(&wcd938x_bind__rs, "wcd938x_bind") )
    dev_err(a1, "%s: Slave bind failed, ret = %d\n", "wcd938x_bind", v5);
  return v5;
}
