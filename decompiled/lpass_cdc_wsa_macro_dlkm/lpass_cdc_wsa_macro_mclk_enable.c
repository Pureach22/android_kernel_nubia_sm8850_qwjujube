__int64 __fastcall lpass_cdc_wsa_macro_mclk_enable(_QWORD *a1, char a2)
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
    mutex_lock(a1 + 20);
    v6 = *((_WORD *)a1 + 18);
    if ( (a2 & 1) == 0 )
    {
      if ( *((_WORD *)a1 + 18) )
      {
        v8 = v6 - 1;
        *((_WORD *)a1 + 18) = v8;
        if ( !v8 )
        {
          regmap_update_bits_base(v5, 8196, 1, 0, 0, 0, 0);
          regmap_update_bits_base(v5, 0x2000, 1, 0, 0, 0, 0);
          lpass_cdc_clk_rsc_fs_gen_request(*a1, 0);
          lpass_cdc_clk_rsc_request_clock(*a1, *((unsigned __int16 *)a1 + 316), *((unsigned __int16 *)a1 + 316), 0);
        }
        v7 = 0;
      }
      else
      {
        if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_mclk_enable__rs_53, "lpass_cdc_wsa_macro_mclk_enable") )
          dev_err(*a1, "%s: clock already disabled\n", "lpass_cdc_wsa_macro_mclk_enable");
        v7 = 0;
        *((_WORD *)a1 + 18) = 0;
      }
      goto LABEL_20;
    }
    if ( *((_WORD *)a1 + 18) )
    {
      v7 = 0;
    }
    else
    {
      v7 = lpass_cdc_clk_rsc_request_clock(*a1, *((unsigned __int16 *)a1 + 316), *((unsigned __int16 *)a1 + 316), 1);
      if ( (v7 & 0x80000000) != 0 )
      {
        if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_mclk_enable__rs_52, "lpass_cdc_wsa_macro_mclk_enable") )
          dev_err(*a1, "%s: wsa request clock enable failed\n", "lpass_cdc_wsa_macro_mclk_enable");
        goto LABEL_20;
      }
      lpass_cdc_clk_rsc_fs_gen_request(*a1, 1);
      regcache_mark_dirty(v5);
      regcache_sync_region(v5, 0x2000, 11236);
      regmap_update_bits_base(v5, 8328, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v5, 0x2000, 1, 1, 0, 0, 0);
      regmap_update_bits_base(v5, 8196, 2, 2, 0, 0, 0);
      regmap_update_bits_base(v5, 8196, 2, 0, 0, 0, 0);
      regmap_update_bits_base(v5, 8196, 1, 1, 0, 0, 0);
      v6 = *((_WORD *)a1 + 18);
    }
    *((_WORD *)a1 + 18) = v6 + 1;
LABEL_20:
    mutex_unlock(a1 + 20);
    return v7;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_mclk_enable__rs, "lpass_cdc_wsa_macro_mclk_enable") )
    dev_err(*a1, "%s: regmap is NULL\n", "lpass_cdc_wsa_macro_mclk_enable");
  return (unsigned int)-22;
}
