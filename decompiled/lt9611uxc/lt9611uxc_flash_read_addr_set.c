__int64 __fastcall lt9611uxc_flash_read_addr_set(__int64 a1, int a2)
{
  __int64 v3; // x22
  _QWORD *v4; // x23
  __int64 v5; // x8
  __int16 v6; // w9
  __int16 v7; // w9
  __int64 v8; // x0
  __int64 result; // x0
  __int16 v10; // [xsp+0h] [xbp-30h] BYREF
  int v11; // [xsp+2h] [xbp-2Eh]
  __int16 v12; // [xsp+6h] [xbp-2Ah]
  _QWORD *v13; // [xsp+8h] [xbp-28h]
  int v14; // [xsp+14h] [xbp-1Ch]
  __int16 v15; // [xsp+18h] [xbp-18h]
  char v16; // [xsp+1Ah] [xbp-16h]
  char v17; // [xsp+1Bh] [xbp-15h]
  char v18; // [xsp+1Ch] [xbp-14h]
  char v19; // [xsp+1Dh] [xbp-13h]
  char v20; // [xsp+1Eh] [xbp-12h]
  char v21; // [xsp+1Fh] [xbp-11h]
  int v22; // [xsp+20h] [xbp-10h]
  __int16 v23; // [xsp+24h] [xbp-Ch]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v3 = 0;
  v4 = (_QWORD *)(a1 + 3760);
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = -1604690082;
  v15 = -32678;
  v16 = 91;
  v18 = 92;
  v20 = 93;
  v19 = BYTE1(a2);
  v17 = BYTE2(a2);
  v21 = a2;
  v22 = -2141548454;
  v23 = 8536;
  do
  {
    v5 = *(_QWORD *)(a1 + 3160);
    v6 = *(_WORD *)(v5 + 2);
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    v4[3] = 0;
    v10 = v6;
    v7 = *(_WORD *)((char *)&v14 + v3);
    v4[4] = 0;
    v4[5] = 0;
    v4[6] = 0;
    v4[7] = 0;
    v4[8] = 0;
    v4[9] = 0;
    v4[10] = 0;
    v4[11] = 0;
    v4[12] = 0;
    v4[13] = 0;
    v4[14] = 0;
    v4[15] = 0;
    *(_WORD *)(a1 + 3760) = v7;
    v8 = *(_QWORD *)(v5 + 24);
    v11 = 0x20000;
    v12 = 0;
    v13 = v4;
    result = i2c_transfer(v8, &v10, 1);
    if ( (int)result <= 0 )
      result = printk(&unk_A9C9, "lt9611uxc_write_byte");
    v3 += 2;
  }
  while ( v3 != 18 );
  _ReadStatusReg(SP_EL0);
  return result;
}
