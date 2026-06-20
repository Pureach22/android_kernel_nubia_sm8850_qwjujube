__int64 __fastcall coresight_get_device_name(__int64 a1)
{
  unsigned __int64 v2; // x9
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 752);
  result = 0;
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *(_UNKNOWN **)(v2 + 8) == &of_fwnode_ops )
    {
      result = *(_QWORD *)(a1 + 744);
      v4[0] = 0;
      if ( result )
      {
        of_property_read_string(result, "device-name", v4);
        result = v4[0];
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
