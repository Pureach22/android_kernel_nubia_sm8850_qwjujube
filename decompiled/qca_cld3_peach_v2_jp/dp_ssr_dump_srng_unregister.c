__int64 __fastcall dp_ssr_dump_srng_unregister(const char *a1, int a2)
{
  __int64 result; // x0
  _QWORD v3[6]; // [xsp+0h] [xbp-60h] BYREF
  __int16 v4; // [xsp+30h] [xbp-30h]
  char s[8]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v6; // [xsp+40h] [xbp-20h]
  _WORD v7[7]; // [xsp+48h] [xbp-18h] BYREF
  __int64 v8; // [xsp+58h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  memset(v7, 0, sizeof(v7));
  *(_QWORD *)s = 0;
  v4 = 0;
  memset(v3, 0, sizeof(v3));
  if ( a2 < 0 )
    snprintf(s, 0x1Eu, "%s", a1);
  else
    snprintf(s, 0x1Eu, "%s%s%d", a1, "_", a2);
  snprintf((char *)v3, 0x32u, "%s%s", s, "_handle");
  qdf_ssr_driver_dump_unregister_region(s);
  result = qdf_ssr_driver_dump_unregister_region(v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
