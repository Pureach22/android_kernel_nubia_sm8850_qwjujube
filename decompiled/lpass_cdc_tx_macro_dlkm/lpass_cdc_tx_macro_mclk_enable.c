__int64 __fastcall lpass_cdc_tx_macro_mclk_enable(_QWORD *a1, char a2)
{
  __int64 regmap; // x0
  __int64 v5; // x21
  unsigned int v6; // w20
  int v7; // w8
  int v8; // w8
  int v9; // w8

  regmap = dev_get_regmap(*(_QWORD *)(*a1 + 96LL), 0);
  if ( regmap )
  {
    v5 = regmap;
    mutex_lock(a1 + 3);
    if ( (a2 & 1) != 0 )
    {
      v6 = lpass_cdc_clk_rsc_request_clock(*a1, 0, 0, 1);
      if ( (v6 & 0x80000000) != 0 )
      {
        if ( (unsigned int)__ratelimit(&lpass_cdc_tx_macro_mclk_enable__rs_207, "lpass_cdc_tx_macro_mclk_enable") )
          dev_err(*a1, "%s: request clock enable failed\n", "lpass_cdc_tx_macro_mclk_enable");
      }
      else
      {
        lpass_cdc_clk_rsc_fs_gen_request(*a1, 1);
        regcache_mark_dirty(v5);
        regcache_sync_region(v5, 0, 3004);
        v7 = *((_DWORD *)a1 + 4);
        if ( !v7 )
        {
          regmap_update_bits_base(v5, 0, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v5, 4, 1, 1, 0, 0, 0);
          v7 = *((_DWORD *)a1 + 4);
        }
        *((_DWORD *)a1 + 4) = v7 + 1;
      }
    }
    else
    {
      v8 = *((_DWORD *)a1 + 4);
      if ( v8 <= 0 )
      {
        if ( (unsigned int)__ratelimit(&lpass_cdc_tx_macro_mclk_enable__rs_209, "lpass_cdc_tx_macro_mclk_enable") )
          dev_err(*a1, "%s: clock already disabled\n", "lpass_cdc_tx_macro_mclk_enable");
        v6 = 0;
        *((_DWORD *)a1 + 4) = 0;
      }
      else
      {
        v9 = v8 - 1;
        *((_DWORD *)a1 + 4) = v9;
        if ( !v9 )
        {
          regmap_update_bits_base(v5, 4, 1, 0, 0, 0, 0);
          regmap_update_bits_base(v5, 0, 1, 0, 0, 0, 0);
        }
        lpass_cdc_clk_rsc_fs_gen_request(*a1, 0);
        lpass_cdc_clk_rsc_request_clock(*a1, 0, 0, 0);
        v6 = 0;
      }
    }
    mutex_unlock(a1 + 3);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_tx_macro_mclk_enable__rs, "lpass_cdc_tx_macro_mclk_enable") )
      dev_err(*a1, "%s: regmap is NULL\n", "lpass_cdc_tx_macro_mclk_enable");
    return (unsigned int)-22;
  }
  return v6;
}
