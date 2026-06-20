__int64 __fastcall zte_power_supply_get_by_phandle_array(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w8
  int v7; // w0
  __int64 v9; // [xsp+8h] [xbp-78h] BYREF
  __int64 v10; // [xsp+10h] [xbp-70h]
  __int64 v11; // [xsp+18h] [xbp-68h]
  __int64 v12; // [xsp+20h] [xbp-60h]
  _QWORD v13[11]; // [xsp+28h] [xbp-58h] BYREF

  v13[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = -22;
  if ( a3 )
  {
    if ( a4 )
    {
      v11 = 0;
      v12 = 0;
      v9 = 0;
      v10 = 0;
      memset(v13, 0, 80);
      v7 = _of_parse_phandle_with_args(a1, a2, 0, 0, 0, v13);
      v4 = -19;
      if ( !v7 )
      {
        if ( v13[0] )
        {
          v9 = v13[0];
          v10 = a3;
          v11 = a4;
          v12 = 0;
          class_for_each_device(zte_power_supply_class, 0, &v9, zte_power_supply_match_device_node_array);
          v4 = v12;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
