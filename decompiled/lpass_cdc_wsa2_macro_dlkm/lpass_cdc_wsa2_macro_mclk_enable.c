__int64 __fastcall lpass_cdc_wsa2_macro_mclk_enable(_QWORD *a1, char a2)
{
  __int64 regmap; // x0
  __int64 v5; // x21
  __int16 v6; // w8
  unsigned int v7; // w20
  __int16 v8; // w8

  regmap = dev_get_regmap(*(_QWORD *)(*a1 + 96LL), 0);
  if ( regmap )
  {
    v5 = regmap;
    mutex_lock(a1 + 6);
    v6 = *((_WORD *)a1 + 18);
    if ( (a2 & 1) == 0 )
    {
      if ( *((_WORD *)a1 + 18) )
      {
        v8 = v6 - 1;
        *((_WORD *)a1 + 18) = v8;
        if ( !v8 )
        {
          regmap_update_bits_base(v5, 16388, 1, 0, 0, 0, 0);
          regmap_update_bits_base(v5, 0x4000, 1, 0, 0, 0, 0);
          lpass_cdc_clk_rsc_fs_gen_request(*a1, 0);
          lpass_cdc_clk_rsc_request_clock(*a1, *((unsigned __int16 *)a1 + 252), *((unsigned __int16 *)a1 + 252), 0);
        }
        v7 = 0;
      }
      else
      {
        if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_mclk_enable__rs_55, "lpass_cdc_wsa2_macro_mclk_enable") )
          dev_err(*a1, "%s: clock already disabled\n", "lpass_cdc_wsa2_macro_mclk_enable");
        v7 = 0;
        *((_WORD *)a1 + 18) = 0;
      }
      goto LABEL_27;
    }
    if ( *((_WORD *)a1 + 18) )
    {
      v7 = 0;
    }
    else
    {
      v7 = lpass_cdc_clk_rsc_request_clock(*a1, *((unsigned __int16 *)a1 + 252), *((unsigned __int16 *)a1 + 252), 1);
      if ( (v7 & 0x80000000) != 0 )
      {
        if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_mclk_enable__rs_52, "lpass_cdc_wsa2_macro_mclk_enable") )
          dev_err(*a1, "%s: wsa2 request clock enable failed\n", "lpass_cdc_wsa2_macro_mclk_enable");
        goto LABEL_27;
      }
      lpass_cdc_clk_rsc_fs_gen_request(*a1, 1);
      regcache_mark_dirty(v5);
      regcache_sync_region(v5, 0x4000, 19428);
      if ( *((_BYTE *)a1 + 666) == 1 )
      {
        if ( a1[82] )
        {
          if ( (unsigned int)readl() != 22 )
            writel(22, a1[82]);
        }
        else if ( (unsigned int)__ratelimit(
                                  &lpass_cdc_wsa2_macro_mclk_enable__rs_53,
                                  "lpass_cdc_wsa2_macro_mclk_enable") )
        {
          dev_err(*a1, "%s: Failed to read LPASS_AUDIO_WSA_DATA_FS_CTL", "lpass_cdc_wsa2_macro_mclk_enable");
        }
        regmap_update_bits_base(v5, 16608, 64, 64, 0, 0, 0);
      }
      regmap_update_bits_base(v5, 16520, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v5, 0x4000, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v5, 16388, 2, 2, 0, 0, 0);
      regmap_update_bits_base(v5, 16388, 2, 0, 0, 0, 0);
      regmap_update_bits_base(v5, 16388, 1, 1, 0, 0, 0);
      v6 = *((_WORD *)a1 + 18);
    }
    *((_WORD *)a1 + 18) = v6 + 1;
LABEL_27:
    mutex_unlock(a1 + 6);
    return v7;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_mclk_enable__rs, "lpass_cdc_wsa2_macro_mclk_enable") )
    dev_err(*a1, "%s: regmap is NULL\n", "lpass_cdc_wsa2_macro_mclk_enable");
  return (unsigned int)-22;
}
