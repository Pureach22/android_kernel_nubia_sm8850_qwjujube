__int64 init_module()
{
  if ( SENSORS_SENS_LOG_LEVEL >= 2 )
    printk(&unk_77CA, "NUBIA_SENSORS_SENS", "sensors_sensitivity_init", 424);
  sensors_sensitivity_register();
  return 0;
}
