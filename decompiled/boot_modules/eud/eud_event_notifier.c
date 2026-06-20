__int64 __fastcall eud_event_notifier(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8

  v1 = result;
  _ReadStatusReg(SP_EL0);
  v2 = *(_DWORD *)(result - 568);
  if ( v2 == 8 )
  {
    result = *(_QWORD *)(result + 32);
    if ( result || (result = power_supply_get_by_name("usb"), (*(_QWORD *)(v1 + 32) = result) != 0) )
    {
      result = power_supply_set_property(result, 38);
      if ( (result & 0x80000000) != 0 )
        result = dev_err(*(_QWORD *)(v1 - 584), "Failed to set the powersupply property: %d\n", result);
    }
  }
  else if ( v2 == 4 )
  {
    extcon_set_state(*(_QWORD *)(result - 552), 61, 1);
    result = extcon_set_state_sync(*(_QWORD *)(v1 - 552), *(unsigned int *)(v1 - 572), *(unsigned __int8 *)(v1 - 564));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
