__int64 __fastcall lt9611uxc_config(__int64 a1)
{
  __int64 v2; // x22
  _QWORD *v3; // x24
  __int64 v4; // x8
  __int16 v5; // w10
  __int16 v6; // w9
  __int64 v7; // x0
  __int64 result; // x0
  __int16 v9; // [xsp+8h] [xbp-18h] BYREF
  int v10; // [xsp+Ah] [xbp-16h]
  __int16 v11; // [xsp+Eh] [xbp-12h]
  _QWORD *v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v2 = 0;
  v3 = (_QWORD *)(a1 + 3760);
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  do
  {
    v4 = *(_QWORD *)(a1 + 3160);
    v5 = *(_WORD *)((char *)&unk_B5D8 + v2);
    v6 = *(_WORD *)(v4 + 2);
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    v3[4] = 0;
    v3[5] = 0;
    v3[6] = 0;
    v3[7] = 0;
    v3[8] = 0;
    v3[9] = 0;
    v3[10] = 0;
    v3[11] = 0;
    v3[12] = 0;
    v3[13] = 0;
    v3[14] = 0;
    v3[15] = 0;
    *(_WORD *)(a1 + 3760) = v5;
    v7 = *(_QWORD *)(v4 + 24);
    v10 = 0x20000;
    v9 = v6;
    v11 = 0;
    v12 = v3;
    result = i2c_transfer(v7, &v9, 1);
    if ( (int)result <= 0 )
      result = printk(&unk_A9C9, "lt9611uxc_write_byte");
    v2 += 2;
  }
  while ( v2 != 14 );
  _ReadStatusReg(SP_EL0);
  return result;
}
