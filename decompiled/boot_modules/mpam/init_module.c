__int64 init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w19

  v0 = _platform_driver_register(qcom_mpam_driver, &_this_module);
  if ( v0 )
  {
    v1 = v0;
    printk(&unk_6D4D, v0);
  }
  else
  {
    return (unsigned int)qcom_mpam_rpmsg_init();
  }
  return v1;
}
