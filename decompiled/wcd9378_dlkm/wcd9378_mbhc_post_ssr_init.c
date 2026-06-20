__int64 __fastcall wcd9378_mbhc_post_ssr_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  unsigned int v6; // w0
  __int64 v7; // x8
  unsigned int v8; // w19

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 152LL);
    if ( v5 )
    {
      snd_soc_component_update_bits(a2, 1075314708, 32, 32);
      v6 = wcd_mbhc_init(a1, a2, &mbhc_cb, &intr_ids, &wcd_mbhc_registers, 1);
      if ( v6 )
      {
        v7 = *(_QWORD *)(a2 + 24);
        v8 = v6;
        dev_err(v7, "%s: mbhc initialization failed\n", "wcd9378_mbhc_post_ssr_init");
        return v8;
      }
      else
      {
        wcd_disable_irq(v5 + 408, 2);
        wcd_disable_irq(v5 + 408, 3);
        wcd_disable_irq(v5 + 408, 10);
        wcd_disable_irq(v5 + 408, 12);
        return 0;
      }
    }
    else
    {
      printk(&unk_131C3, "wcd9378_mbhc_post_ssr_init");
      return 4294967274LL;
    }
  }
  return result;
}
