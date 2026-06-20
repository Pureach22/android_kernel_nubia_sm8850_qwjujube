__int64 __fastcall ml_nlink_get_standby_link_freq(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  int v5; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v6[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int16 v7; // [xsp+10h] [xbp-20h] BYREF
  char v8; // [xsp+12h] [xbp-1Eh]
  __int16 v9; // [xsp+14h] [xbp-1Ch] BYREF
  char v10; // [xsp+16h] [xbp-1Ah]
  __int64 v11; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  v5 = 0;
  v10 = 0;
  v9 = 0;
  v12 = 0;
  v11 = 0;
  v8 = 0;
  v7 = 0;
  ml_nlink_get_standby_link_info(a2, 0, 3u, (__int64)&v11, (__int64)&v9, (__int64)&v7, v6, &v5);
  if ( !v6[0] )
  {
LABEL_5:
    result = 0;
    goto LABEL_6;
  }
  if ( ((a3 >> v7) & 1) == 0 )
  {
    if ( v6[0] != 1 )
    {
      if ( ((a3 >> SHIBYTE(v7)) & 1) != 0 )
      {
        result = HIDWORD(v11);
        goto LABEL_6;
      }
      if ( v6[0] != 2 )
      {
        if ( ((a3 >> v8) & 1) != 0 )
        {
          result = v12;
          goto LABEL_6;
        }
        if ( v6[0] != 3 )
          __break(0x5512u);
      }
    }
    goto LABEL_5;
  }
  result = (unsigned int)v11;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
