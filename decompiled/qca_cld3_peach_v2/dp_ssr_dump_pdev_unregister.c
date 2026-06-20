__int64 __fastcall dp_ssr_dump_pdev_unregister(unsigned __int8 a1)
{
  __int64 result; // x0
  _QWORD v2[6]; // [xsp+0h] [xbp-40h] BYREF
  __int16 v3; // [xsp+30h] [xbp-10h]
  __int64 v4; // [xsp+38h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  memset(v2, 0, sizeof(v2));
  snprintf((char *)v2, 0x32u, "%s%s%d", "dp_pdev", "_", a1);
  result = qdf_ssr_driver_dump_unregister_region(v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
