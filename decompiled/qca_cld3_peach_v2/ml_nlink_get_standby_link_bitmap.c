__int64 __fastcall ml_nlink_get_standby_link_bitmap(__int64 a1, __int64 a2)
{
  unsigned int v3; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v4[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int16 v5; // [xsp+10h] [xbp-20h] BYREF
  char v6; // [xsp+12h] [xbp-1Eh]
  __int16 v7; // [xsp+14h] [xbp-1Ch] BYREF
  char v8; // [xsp+16h] [xbp-1Ah]
  __int64 v9; // [xsp+18h] [xbp-18h] BYREF
  int v10; // [xsp+20h] [xbp-10h]
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  v3 = 0;
  v8 = 0;
  v7 = 0;
  v10 = 0;
  v9 = 0;
  v6 = 0;
  v5 = 0;
  ml_nlink_get_standby_link_info(a2, 16, 3, &v9, &v7, &v5, v4, &v3);
  _ReadStatusReg(SP_EL0);
  return v3;
}
