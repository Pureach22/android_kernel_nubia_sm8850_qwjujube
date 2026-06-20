__int64 __fastcall dp_ssr_dump_pdev_register(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  _QWORD v4[6]; // [xsp+0h] [xbp-40h] BYREF
  __int16 v5; // [xsp+30h] [xbp-10h]
  __int64 v6; // [xsp+38h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  memset(v4, 0, sizeof(v4));
  snprintf((char *)v4, 0x32u, "%s%s%d", "dp_pdev", "_", a2);
  result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))qdf_ssr_driver_dump_register_region)(v4, a1, 95608);
  _ReadStatusReg(SP_EL0);
  return result;
}
