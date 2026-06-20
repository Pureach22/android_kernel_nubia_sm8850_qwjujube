__int64 __fastcall eusb2_repeater_register_tune_unregister(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( result )
  {
    v1 = result;
    dev_info(*(_QWORD *)(result + 16), "Unregistering Register Tune driver\n");
    v2 = *(_QWORD *)(v1 + 24);
    if ( v2 )
    {
      sysfs_remove_group(v2, &diagram_tune_attr_group);
      device_destroy(repeater_tune_class, 0);
      *(_QWORD *)(v1 + 24) = 0;
    }
    result = repeater_tune_class;
    if ( repeater_tune_class )
    {
      result = class_destroy();
      repeater_tune_class = 0;
    }
  }
  return result;
}
