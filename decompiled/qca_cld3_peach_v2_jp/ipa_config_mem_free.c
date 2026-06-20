void __fastcall ipa_config_mem_free(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x29
  __int64 v9; // x30

  if ( !g_instances_added )
  {
    if ( g_ipa_config )
    {
      _qdf_mem_free(g_ipa_config);
      g_ipa_config = 0;
    }
    else
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: IPA config already freed",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "ipa_config_mem_free",
        v8,
        v9);
    }
  }
}
