__int64 __fastcall wsa883x_pa_on_err_handle_irq(__int64 a1, __int64 a2)
{
  __int64 v2; // x19

  if ( !a2 )
    return 0;
  v2 = *(_QWORD *)(a2 + 24);
  if ( !v2 )
    return 0;
  if ( (snd_soc_component_read(*(_QWORD *)(a2 + 24), 13331) & 0x70) != 0 )
    snd_soc_component_read(v2, 13332);
  if ( (unsigned int)__ratelimit(&wsa883x_pa_on_err_handle_irq__rs, "wsa883x_pa_on_err_handle_irq") )
    printk(&unk_A6AE, "wsa883x_pa_on_err_handle_irq");
  snd_soc_component_update_bits(v2, 13328, 16, 0);
  snd_soc_component_update_bits(v2, 13328, 16, 16);
  snd_soc_component_update_bits(v2, 13328, 16, 0);
  return 1;
}
