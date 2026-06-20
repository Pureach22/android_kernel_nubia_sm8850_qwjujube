unsigned __int64 init_module()
{
  unsigned __int64 result; // x0

  result = class_create("zte_power_supply");
  zte_power_supply_class = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(result + 24) = zte_power_supply_uevent;
    ((void (__fastcall *)(void *))zte_power_supply_init_attrs)(&zte_power_supply_dev_type);
    return 0;
  }
  return result;
}
