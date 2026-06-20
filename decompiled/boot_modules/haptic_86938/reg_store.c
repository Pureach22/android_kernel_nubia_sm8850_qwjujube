__int64 __fastcall reg_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  _BYTE v7[4]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v8; // [xsp+10h] [xbp-10h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( sscanf(s, "%x %x", &v8, (char *)&v8 + 4) == 2 )
  {
    v7[0] = BYTE4(v8);
    i2c_w_bytes(v5 - 168, v8, v7, 1u);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
