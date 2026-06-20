void zte_touch_pdev_unregister()
{
  __int64 v0; // x19
  void (__fastcall *v1)(__int64); // x8

  v0 = tpd_cdev;
  if ( !*(_QWORD *)(tpd_cdev + 3096) )
  {
    v1 = (void (__fastcall *)(__int64))off_338;
    if ( *((_DWORD *)off_338 - 1) != 1820440776 )
      __break(0x8228u);
    v1(16);
    platform_device_unregister(*(_QWORD *)(v0 + 3096));
  }
}
