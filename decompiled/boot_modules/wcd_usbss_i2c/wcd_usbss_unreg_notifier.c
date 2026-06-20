__int64 __fastcall wcd_usbss_unreg_notifier(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 device_by_fwnode; // x0
  __int64 v5; // x8

  if ( a2 )
    v3 = a2 + 24;
  else
    v3 = 0;
  device_by_fwnode = i2c_find_device_by_fwnode(v3);
  if ( device_by_fwnode && (v5 = *(_QWORD *)(device_by_fwnode + 184)) != 0 )
    return blocking_notifier_chain_unregister(v5 + 72, a1);
  else
    return 4294967274LL;
}
