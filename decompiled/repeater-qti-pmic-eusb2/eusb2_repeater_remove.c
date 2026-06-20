__int64 __fastcall eusb2_repeater_remove(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 176) )
    {
      eusb2_repeater_register_tune_unregister();
      *(_QWORD *)(v1 + 176) = 0;
    }
    debugfs_remove(*(_QWORD *)(v1 + 128));
    usb_remove_repeater_dev(v1);
    return eusb2_repeater_power(v1, 0);
  }
  return result;
}
