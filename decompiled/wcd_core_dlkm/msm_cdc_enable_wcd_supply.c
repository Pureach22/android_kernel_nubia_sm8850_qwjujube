__int64 __fastcall msm_cdc_enable_wcd_supply(_QWORD *a1, char a2)
{
  __int64 v2; // x19
  __int64 v4; // x1
  char v6; // w20
  __int64 v7; // x0
  unsigned int v8; // w0
  unsigned int v9; // w22
  const char *v11; // x4

  v2 = a1[2];
  if ( v2 )
  {
    v4 = *a1;
    v6 = a2;
    v7 = v2 + 208;
    if ( (a2 & 1) != 0 )
    {
      v8 = snd_soc_dapm_force_enable_pin(v7, v4);
      if ( v8 )
      {
LABEL_4:
        v9 = v8;
        if ( (unsigned int)__ratelimit(&msm_cdc_enable_wcd_supply__rs_34, "msm_cdc_enable_wcd_supply") )
        {
          if ( (v6 & 1) != 0 )
            v11 = "enable";
          else
            v11 = "disable";
          dev_err(*(_QWORD *)(v2 + 24), "%s: micbias %s force %s pin failed\n", "msm_cdc_enable_wcd_supply", *a1, v11);
        }
        return v9;
      }
    }
    else
    {
      v8 = snd_soc_dapm_disable_pin(v7, v4);
      if ( v8 )
        goto LABEL_4;
    }
    snd_soc_dapm_sync(v2 + 208);
    return 0;
  }
  if ( (unsigned int)__ratelimit(&msm_cdc_enable_wcd_supply__rs, "msm_cdc_enable_wcd_supply") )
    printk(&unk_9DD3, "msm_cdc_enable_wcd_supply");
  return 4294967274LL;
}
