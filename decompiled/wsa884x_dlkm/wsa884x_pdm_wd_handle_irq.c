__int64 __fastcall wsa884x_pdm_wd_handle_irq(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned int v3; // w20

  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 24);
    v3 = 1;
    snd_soc_component_update_bits(v2, 13451, 1, 0);
    snd_soc_component_update_bits(v2, 13451, 1, 1);
    if ( (unsigned int)__ratelimit(&wsa884x_pdm_wd_handle_irq__rs, "wsa884x_pdm_wd_handle_irq") )
      printk(&unk_CF14, "wsa884x_pdm_wd_handle_irq");
  }
  else
  {
    return 0;
  }
  return v3;
}
