__int64 usb_switch_dp_remove()
{
  __int64 result; // x0

  if ( dp_switch )
    return sysfs_remove_group(*(_QWORD *)(dp_switch + 8), &usb_switch_dp_attribute_group);
  return result;
}
