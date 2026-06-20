__int64 __fastcall dp_ssr_dump_srng_register(const char *a1, __int64 a2, int a3)
{
  __int64 result; // x0
  _QWORD v5[6]; // [xsp+0h] [xbp-60h] BYREF
  __int16 v6; // [xsp+30h] [xbp-30h]
  char s[8]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v8; // [xsp+40h] [xbp-20h]
  _WORD v9[7]; // [xsp+48h] [xbp-18h] BYREF
  __int64 v10; // [xsp+58h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  memset(v9, 0, sizeof(v9));
  *(_QWORD *)s = 0;
  v6 = 0;
  memset(v5, 0, sizeof(v5));
  if ( a3 < 0 )
    snprintf(s, 0x1Eu, "%s", a1);
  else
    snprintf(s, 0x1Eu, "%s%s%d", a1, "_", a3);
  snprintf((char *)v5, 0x32u, "%s%s", s, "_handle");
  ((void (__fastcall *)(_QWORD *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(v5, *(_QWORD *)a2, 312);
  result = ((__int64 (__fastcall *)(char *, _QWORD, _QWORD))qdf_ssr_driver_dump_register_region)(
             s,
             *(_QWORD *)(a2 + 16),
             *(unsigned int *)(a2 + 40));
  _ReadStatusReg(SP_EL0);
  return result;
}
