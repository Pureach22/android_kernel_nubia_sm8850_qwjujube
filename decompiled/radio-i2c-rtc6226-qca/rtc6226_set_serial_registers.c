__int64 __fastcall rtc6226_set_serial_registers(__int64 a1, unsigned __int16 *a2, char a3)
{
  __int64 v3; // x8
  unsigned int v4; // w11
  __int16 v5; // w10
  __int64 v6; // x0
  int v7; // w0
  char v9; // [xsp+4h] [xbp-1Ch] BYREF
  __int16 v10; // [xsp+5h] [xbp-1Bh]
  __int16 v11; // [xsp+8h] [xbp-18h] BYREF
  int v12; // [xsp+Ah] [xbp-16h]
  __int16 v13; // [xsp+Eh] [xbp-12h]
  char *v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 3488);
  v4 = *a2;
  v9 = a3;
  v5 = *(_WORD *)(v3 + 2);
  v12 = 196608;
  v14 = &v9;
  v6 = *(_QWORD *)(v3 + 24);
  v13 = 0;
  v11 = v5;
  v10 = bswap32(v4) >> 16;
  v7 = i2c_transfer(v6, &v11, 1);
  _ReadStatusReg(SP_EL0);
  if ( v7 == 1 )
    return 0;
  else
    return 4294967291LL;
}
