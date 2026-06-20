__int64 init_module()
{
  unsigned int v0; // w19

  v0 = audio_ref_clk_platform_init();
  if ( v0 )
    printk(&unk_8A35, "wcd9xxx_soc_init");
  return v0;
}
