__int64 cam_flash_init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w19
  const char *v2; // x5
  __int64 v3; // x4

  v0 = _platform_driver_register(cam_flash_platform_driver, &_this_module);
  if ( (v0 & 0x80000000) != 0 )
  {
    v1 = v0;
    v2 = "platform probe failed rc: %d";
    v3 = 997;
    goto LABEL_5;
  }
  v1 = i2c_register_driver(&_this_module, &cam_flash_i2c_driver);
  if ( (v1 & 0x80000000) != 0 )
  {
    v2 = "i2c_add_driver failed rc: %d";
    v3 = 1003;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_init_module",
      v3,
      v2,
      v1);
  }
  return v1;
}
