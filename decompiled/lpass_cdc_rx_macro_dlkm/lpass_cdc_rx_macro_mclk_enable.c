__int64 __fastcall lpass_cdc_rx_macro_mclk_enable(int *a1, char a2)
{
  __int64 regmap; // x0
  __int64 v5; // x21
  int v6; // w8
  unsigned int v7; // w20
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x21

  regmap = dev_get_regmap(*(_QWORD *)(*(_QWORD *)a1 + 96LL), 0);
  if ( regmap )
  {
    v5 = regmap;
    mutex_lock(a1 + 26);
    v6 = a1[16];
    if ( (a2 & 1) != 0 )
    {
      if ( v6 )
      {
        v7 = 0;
LABEL_5:
        a1[16] = v6 + 1;
LABEL_43:
        mutex_unlock(a1 + 26);
        return v7;
      }
      if ( *((_BYTE *)a1 + 86) == 1 )
        *((_WORD *)a1 + 1168) = 1;
      if ( a1 )
      {
        if ( *((_BYTE *)a1 + 95) == 1 )
        {
          _pm_runtime_resume(*(_QWORD *)a1, 4);
          if ( (lpass_cdc_check_core_votes(*(_QWORD *)a1) & 1) != 0 )
          {
            v7 = lpass_cdc_clk_rsc_request_clock(
                   *(_QWORD *)a1,
                   *((unsigned __int16 *)a1 + 1169),
                   *((unsigned __int16 *)a1 + 1168),
                   1);
            v9 = _pm_runtime_suspend(*(_QWORD *)a1, 13);
            v10 = *(_QWORD *)a1;
            *(_QWORD *)(v10 + 520) = ktime_get_mono_fast_ns(v9);
            if ( (v7 & 0x80000000) != 0 )
            {
              if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_mclk_enable__rs_47, "lpass_cdc_rx_macro_mclk_enable") )
                dev_err(*(_QWORD *)a1, "%s: rx request clock enable failed\n", "lpass_cdc_rx_macro_mclk_enable");
              goto LABEL_43;
            }
            lpass_cdc_clk_rsc_fs_gen_request(*(_QWORD *)a1, 1);
            regcache_mark_dirty(v5);
            regcache_sync_region(v5, 4096, 8076);
            regmap_update_bits_base(v5, 4352, 1, 1, 0, 0, 0);
            regmap_update_bits_base(v5, 4352, 2, 2, 0, 0, 0);
            regmap_update_bits_base(v5, 4356, 2, 0, 0, 0, 0);
            regmap_update_bits_base(v5, 4356, 1, 1, 0, 0, 0);
            v6 = a1[16];
            goto LABEL_5;
          }
          v7 = -522;
LABEL_28:
          if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_mclk_enable__rs_45, "lpass_cdc_rx_macro_mclk_enable") )
            dev_err(*(_QWORD *)a1, "%s: rx request core vote failed\n", "lpass_cdc_rx_macro_mclk_enable");
          goto LABEL_43;
        }
      }
      else if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_core_vote__rs, "lpass_cdc_rx_macro_core_vote") )
      {
        printk(&unk_F527, "lpass_cdc_rx_macro_core_vote");
        v7 = -22;
        goto LABEL_28;
      }
      v7 = -22;
      goto LABEL_28;
    }
    if ( v6 <= 0 )
    {
      if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_mclk_enable__rs_48, "lpass_cdc_rx_macro_mclk_enable") )
        dev_err(*(_QWORD *)a1, "%s: clock already disabled\n", "lpass_cdc_rx_macro_mclk_enable");
      v7 = 0;
      a1[16] = 0;
      goto LABEL_43;
    }
    v8 = v6 - 1;
    a1[16] = v8;
    if ( v8 )
    {
      v7 = 0;
      goto LABEL_43;
    }
    regmap_update_bits_base(v5, 4356, 1, 0, 0, 0, 0);
    regmap_update_bits_base(v5, 4356, 2, 2, 0, 0, 0);
    regmap_update_bits_base(v5, 4352, 2, 0, 0, 0, 0);
    regmap_update_bits_base(v5, 4352, 1, 0, 0, 0, 0);
    lpass_cdc_clk_rsc_fs_gen_request(*(_QWORD *)a1, 0);
    if ( a1 )
    {
      if ( *((_BYTE *)a1 + 95) == 1 )
      {
        _pm_runtime_resume(*(_QWORD *)a1, 4);
        if ( (lpass_cdc_check_core_votes(*(_QWORD *)a1) & 1) != 0 )
        {
          v7 = 0;
LABEL_35:
          lpass_cdc_clk_rsc_request_clock(
            *(_QWORD *)a1,
            *((unsigned __int16 *)a1 + 1169),
            *((unsigned __int16 *)a1 + 1168),
            0);
          if ( !v7 )
          {
            if ( a1 )
            {
              v11 = _pm_runtime_suspend(*(_QWORD *)a1, 13);
              v12 = *(_QWORD *)a1;
              *(_QWORD *)(v12 + 520) = ktime_get_mono_fast_ns(v11);
            }
            else if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_core_vote__rs, "lpass_cdc_rx_macro_core_vote") )
            {
              printk(&unk_F527, "lpass_cdc_rx_macro_core_vote");
            }
          }
          *((_WORD *)a1 + 1168) = *((_WORD *)a1 + 1169);
          goto LABEL_43;
        }
        v7 = -522;
LABEL_33:
        if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_mclk_enable__rs_50, "lpass_cdc_rx_macro_mclk_enable") )
          dev_err(*(_QWORD *)a1, "%s: rx request core vote failed\n", "lpass_cdc_rx_macro_mclk_enable");
        goto LABEL_35;
      }
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_core_vote__rs, "lpass_cdc_rx_macro_core_vote") )
    {
      printk(&unk_F527, "lpass_cdc_rx_macro_core_vote");
    }
    v7 = -22;
    goto LABEL_33;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_mclk_enable__rs, "lpass_cdc_rx_macro_mclk_enable") )
    dev_err(*(_QWORD *)a1, "%s: regmap is NULL\n", "lpass_cdc_rx_macro_mclk_enable");
  return (unsigned int)-22;
}
