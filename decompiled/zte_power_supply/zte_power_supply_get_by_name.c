__int64 __fastcall zte_power_supply_get_by_name(__int64 a1)
{
  __int64 result; // x0
  unsigned int v8; // w9

  result = class_find_device(zte_power_supply_class, 0, a1, zte_power_supply_match_device_by_name);
  if ( result )
  {
    result = *(_QWORD *)(result + 152);
    _X8 = (unsigned int *)(result + 1112);
    __asm { PRFM            #0x11, [X8] }
    do
      v8 = __ldxr(_X8);
    while ( __stxr(v8 + 1, _X8) );
  }
  return result;
}
