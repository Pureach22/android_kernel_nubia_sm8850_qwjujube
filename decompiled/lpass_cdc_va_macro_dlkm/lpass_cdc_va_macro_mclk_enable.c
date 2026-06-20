__int64 __fastcall lpass_cdc_va_macro_mclk_enable(_QWORD *a1, char a2)
{
  __int64 regmap; // x0
  __int64 v5; // x21
  unsigned int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x22
  __int16 v9; // w8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x21
  void *v14; // x0
  void *v15; // x0

  regmap = dev_get_regmap(*(_QWORD *)(*a1 + 96LL), 0);
  if ( regmap )
  {
    v5 = regmap;
    mutex_lock(a1 + 3);
    if ( (a2 & 1) != 0 )
    {
      if ( a1 )
      {
        if ( *((_BYTE *)a1 + 1579) == 1 )
        {
          _pm_runtime_resume(*a1, 4);
          if ( (lpass_cdc_check_core_votes(*a1) & 1) != 0 )
          {
            v6 = lpass_cdc_clk_rsc_request_clock(
                   *a1,
                   *((unsigned __int16 *)a1 + 766),
                   *((unsigned __int16 *)a1 + 767),
                   1);
            v7 = _pm_runtime_suspend(*a1, 13);
            v8 = *a1;
            *(_QWORD *)(v8 + 520) = ktime_get_mono_fast_ns(v7);
            if ( (v6 & 0x80000000) != 0 )
            {
              if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_mclk_enable__rs_48, "lpass_cdc_va_macro_mclk_enable") )
                dev_err(*a1, "%s: va request clock en failed\n", "lpass_cdc_va_macro_mclk_enable");
            }
            else
            {
              lpass_cdc_clk_rsc_fs_gen_request(*a1, 1);
              v9 = *((_WORD *)a1 + 668);
              if ( !v9 )
              {
                regcache_mark_dirty(v5);
                regcache_sync_region(v5, 12288, 13736);
                v9 = *((_WORD *)a1 + 668);
              }
              *((_WORD *)a1 + 668) = v9 + 1;
            }
LABEL_39:
            mutex_unlock(a1 + 3);
            return v6;
          }
          v6 = -522;
LABEL_24:
          if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_mclk_enable__rs_46, "lpass_cdc_va_macro_mclk_enable") )
            dev_err(*a1, "%s: va request core vote failed\n", "lpass_cdc_va_macro_mclk_enable");
          goto LABEL_39;
        }
        v14 = &unk_11E98;
      }
      else
      {
        if ( !(unsigned int)__ratelimit(&lpass_cdc_va_macro_core_vote__rs, "lpass_cdc_va_macro_core_vote") )
        {
LABEL_19:
          v6 = -22;
          goto LABEL_24;
        }
        v14 = &unk_11F26;
      }
      printk(v14, "lpass_cdc_va_macro_core_vote");
      goto LABEL_19;
    }
    if ( !*((_WORD *)a1 + 668) )
    {
      if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_mclk_enable__rs_50, "lpass_cdc_va_macro_mclk_enable") )
        dev_err(*a1, "%s: clock already disabled\n", "lpass_cdc_va_macro_mclk_enable");
      v6 = 0;
      *((_WORD *)a1 + 668) = 0;
      goto LABEL_39;
    }
    v10 = *a1;
    --*((_WORD *)a1 + 668);
    lpass_cdc_clk_rsc_fs_gen_request(v10, 0);
    if ( a1 )
    {
      if ( *((_BYTE *)a1 + 1579) == 1 )
      {
        _pm_runtime_resume(*a1, 4);
        if ( (lpass_cdc_check_core_votes(*a1) & 1) != 0 )
        {
          v6 = 0;
LABEL_31:
          lpass_cdc_clk_rsc_request_clock(*a1, *((unsigned __int16 *)a1 + 766), *((unsigned __int16 *)a1 + 767), 0);
          if ( !v6 )
          {
            if ( a1 )
            {
              v11 = _pm_runtime_suspend(*a1, 13);
              v12 = *a1;
              v6 = 0;
              *(_QWORD *)(v12 + 520) = ktime_get_mono_fast_ns(v11);
            }
            else
            {
              if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_core_vote__rs, "lpass_cdc_va_macro_core_vote") )
                printk(&unk_11F26, "lpass_cdc_va_macro_core_vote");
              v6 = 0;
            }
          }
          goto LABEL_39;
        }
        v6 = -522;
LABEL_29:
        if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_mclk_enable__rs_52, "lpass_cdc_va_macro_mclk_enable") )
          dev_err(*a1, "%s: va request core vote failed\n", "lpass_cdc_va_macro_mclk_enable");
        goto LABEL_31;
      }
      v15 = &unk_11E98;
    }
    else
    {
      if ( !(unsigned int)__ratelimit(&lpass_cdc_va_macro_core_vote__rs, "lpass_cdc_va_macro_core_vote") )
      {
LABEL_27:
        v6 = -22;
        goto LABEL_29;
      }
      v15 = &unk_11F26;
    }
    printk(v15, "lpass_cdc_va_macro_core_vote");
    goto LABEL_27;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_mclk_enable__rs, "lpass_cdc_va_macro_mclk_enable") )
    dev_err(*a1, "%s: regmap is NULL\n", "lpass_cdc_va_macro_mclk_enable");
  return (unsigned int)-22;
}
