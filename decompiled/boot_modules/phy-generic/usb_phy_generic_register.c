__int64 usb_phy_generic_register()
{
  __int64 result; // x0
  _QWORD v1[4]; // [xsp+8h] [xbp-68h] BYREF
  int v2; // [xsp+28h] [xbp-48h]
  __int64 v3; // [xsp+2Ch] [xbp-44h]
  __int64 v4; // [xsp+34h] [xbp-3Ch]
  __int64 v5; // [xsp+3Ch] [xbp-34h]
  __int64 v6; // [xsp+44h] [xbp-2Ch]
  __int64 v7; // [xsp+4Ch] [xbp-24h]
  __int64 v8; // [xsp+54h] [xbp-1Ch]
  __int64 v9; // [xsp+5Ch] [xbp-14h]
  int v10; // [xsp+64h] [xbp-Ch]
  __int64 v11; // [xsp+68h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1[3] = "usb_phy_generic";
  memset(v1, 0, 24);
  v2 = -2;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  result = platform_device_register_full(v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
