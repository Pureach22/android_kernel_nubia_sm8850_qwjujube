__int64 init_module()
{
  unsigned int v0; // w19

  v0 = _platform_driver_register(this_driver, &_this_module);
  if ( v0 )
    printk(&unk_6FB1, "msm_ext_disp_init");
  return v0;
}
