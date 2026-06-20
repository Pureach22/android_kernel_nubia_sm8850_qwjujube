__int64 __fastcall rtc6226_set_register(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x8
  __int16 v3; // w10
  __int64 v4; // x9
  __int64 v5; // x0
  int v6; // w0
  unsigned __int8 v8; // [xsp+4h] [xbp-1Ch] BYREF
  __int16 v9; // [xsp+5h] [xbp-1Bh]
  __int16 v10; // [xsp+8h] [xbp-18h] BYREF
  int v11; // [xsp+Ah] [xbp-16h]
  __int16 v12; // [xsp+Eh] [xbp-12h]
  char *v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3488);
  v9 = 0;
  v8 = a2;
  v3 = *(_WORD *)(v2 + 2);
  v11 = 196608;
  v13 = (char *)&v8;
  v10 = v3;
  v12 = 0;
  if ( a2 >= 0x20u )
    __break(0x5512u);
  v4 = a1 + 2LL * a2;
  v5 = *(_QWORD *)(v2 + 24);
  v9 = bswap32(*(unsigned __int16 *)(v4 + 1762)) >> 16;
  v6 = i2c_transfer(v5, &v10, 1);
  _ReadStatusReg(SP_EL0);
  if ( v6 == 1 )
    return 0;
  else
    return 4294967291LL;
}
