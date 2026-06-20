__int64 __fastcall wcd938x_mbhc_post_ssr_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w19

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    snd_soc_component_update_bits(a2, 12308, 32, 32);
    result = wcd_mbhc_init(a1, a2, &mbhc_cb, &intr_ids, &wcd_mbhc_registers, 1);
    if ( (_DWORD)result )
    {
      v5 = *(_QWORD *)(a2 + 24);
      v6 = result;
      dev_err(v5, "%s: mbhc initialization failed\n", "wcd938x_mbhc_post_ssr_init");
      return v6;
    }
  }
  return result;
}
