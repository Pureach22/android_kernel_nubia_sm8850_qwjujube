__int64 __fastcall mhi_bdf_to_controller(int a1, int a2, int a3, int a4)
{
  __int64 *v4; // x21
  __int64 v5; // x19
  const char *v6; // x1
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v9; // [xsp+10h] [xbp-20h]
  __int64 v10; // [xsp+18h] [xbp-18h]
  __int64 v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11 = 0;
  *(_QWORD *)s = 0;
  v9 = 0;
  snprintf(s, 0x20u, "mhi_%04x_%02u.%02u.%02u", a4, a1, a2, a3);
  v4 = (__int64 *)mhi_bus;
  while ( v4 != &mhi_bus )
  {
    v5 = v4[2];
    v4 = (__int64 *)*v4;
    v6 = *(const char **)(*(_QWORD *)(v5 + 16) + 8LL);
    if ( v6 && !strcmp(s, v6) )
      goto LABEL_7;
  }
  v5 = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v5;
}
