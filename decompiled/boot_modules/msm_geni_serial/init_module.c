__int64 init_module()
{
  __int64 v0; // x8
  _DWORD *v1; // x9
  unsigned int v2; // w19

  v0 = 0;
  v1 = &unk_16CEC;
  do
  {
    *v1 = v0++;
    *((_BYTE *)v1 - 122) = 2;
    *(_QWORD *)(v1 - 3) = msm_geni_serial_pops;
    *(_QWORD *)(v1 - 11) = 0x10000000;
    v1 += 510;
  }
  while ( v0 != 6 );
  byte_19C42 = 2;
  qword_19CB0 = (__int64)msm_geni_console_pops;
  qword_19C90 = 0x10000000;
  dword_19CBC = 0;
  v2 = uart_register_driver(&msm_geni_serial_hs_driver);
  if ( !v2 )
  {
    v2 = _platform_driver_register(msm_geni_serial_platform_driver, &_this_module);
    if ( v2 )
      uart_unregister_driver(&msm_geni_serial_hs_driver);
  }
  return v2;
}
