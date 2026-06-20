__int64 __fastcall swr_dmic_remove(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0

  if ( a1 && (v2 = *(_QWORD *)(a1 + 224)) != 0 )
  {
    if ( *(_DWORD *)(v2 + 68) == 1 )
    {
      v3 = *(_QWORD *)(v2 + 40);
      if ( v3 )
      {
        wcd939x_codec_force_enable_micbias_v2(v3, 8, *(unsigned int *)(v2 + 48));
      }
      else if ( (unsigned int)__ratelimit(&enable_wcd_codec_supply__rs, "enable_wcd_codec_supply") )
      {
        printk(&unk_7DE9, "enable_wcd_codec_supply");
      }
      --*(_DWORD *)(v2 + 68);
    }
    snd_soc_unregister_component(a1 + 72);
    *(_QWORD *)(a1 + 224) = 0;
    return 0;
  }
  else
  {
    dev_err(a1 + 72, "%s: swr_dmic is NULL\n", "swr_dmic_remove");
    return 4294967274LL;
  }
}
