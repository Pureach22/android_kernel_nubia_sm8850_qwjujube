__int64 __fastcall coresight_get_enabled_sink_from_bus(char a1)
{
  __int64 device; // x0
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = a1;
  device = bus_find_device(&coresight_bustype, 0, v3, coresight_enabled_sink);
  _ReadStatusReg(SP_EL0);
  if ( device )
    return device - 56;
  else
    return 0;
}
