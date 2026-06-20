__int64 __fastcall zte_power_supply_get_by_phandle(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 result; // x0
  unsigned int v10; // w9
  _QWORD v11[11]; // [xsp+8h] [xbp-58h] BYREF

  v11[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v11, 0, 80);
  v2 = _of_parse_phandle_with_args(a1, a2, 0, 0, 0, v11);
  result = -19;
  if ( !v2 )
  {
    if ( v11[0] )
    {
      result = class_find_device(zte_power_supply_class, 0, v11[0], zte_power_supply_match_device_node);
      if ( result )
      {
        result = *(_QWORD *)(result + 152);
        _X8 = (unsigned int *)(result + 1112);
        __asm { PRFM            #0x11, [X8] }
        do
          v10 = __ldxr(_X8);
        while ( __stxr(v10 + 1, _X8) );
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
