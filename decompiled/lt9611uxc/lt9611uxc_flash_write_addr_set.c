__int64 __fastcall lt9611uxc_flash_write_addr_set(__int64 a1, int a2)
{
  _QWORD *v3; // x21
  __int16 v4; // w20
  __int64 v5; // x8
  __int16 v6; // w9
  __int64 v7; // x0
  __int64 v8; // x8
  __int16 v9; // w9
  __int64 v10; // x0
  __int64 v11; // x8
  __int16 v12; // w9
  __int64 v13; // x0
  __int64 v14; // x8
  __int16 v15; // w9
  __int64 v16; // x0
  __int64 v17; // x8
  __int16 v18; // w10
  __int64 v19; // x0
  __int64 result; // x0
  __int16 v21; // [xsp+8h] [xbp-18h] BYREF
  int v22; // [xsp+Ah] [xbp-16h]
  __int16 v23; // [xsp+Eh] [xbp-12h]
  _QWORD *v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v3 = (_QWORD *)(a1 + 3760);
  v4 = a2;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 3160);
  v6 = *(_WORD *)(v5 + 2);
  *(_QWORD *)(a1 + 3760) = 0;
  *(_QWORD *)(a1 + 3768) = 0;
  v21 = v6;
  *(_QWORD *)(a1 + 3776) = 0;
  *(_QWORD *)(a1 + 3784) = 0;
  *(_QWORD *)(a1 + 3792) = 0;
  *(_QWORD *)(a1 + 3800) = 0;
  *(_QWORD *)(a1 + 3808) = 0;
  *(_QWORD *)(a1 + 3816) = 0;
  *(_QWORD *)(a1 + 3824) = 0;
  *(_QWORD *)(a1 + 3832) = 0;
  *(_QWORD *)(a1 + 3840) = 0;
  *(_QWORD *)(a1 + 3848) = 0;
  *(_QWORD *)(a1 + 3856) = 0;
  *(_QWORD *)(a1 + 3864) = 0;
  *(_QWORD *)(a1 + 3872) = 0;
  *(_QWORD *)(a1 + 3880) = 0;
  *(_BYTE *)(a1 + 3760) = 91;
  *(_BYTE *)(a1 + 3761) = BYTE2(a2);
  v7 = *(_QWORD *)(v5 + 24);
  v22 = 0x20000;
  v23 = 0;
  v24 = v3;
  if ( (int)i2c_transfer(v7, &v21, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v8 = *(_QWORD *)(a1 + 3160);
  v9 = *(_WORD *)(v8 + 2);
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v21 = v9;
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
  *(_BYTE *)(a1 + 3760) = 92;
  *(_BYTE *)(a1 + 3761) = HIBYTE(v4);
  v10 = *(_QWORD *)(v8 + 24);
  v22 = 0x20000;
  v23 = 0;
  v24 = v3;
  if ( (int)i2c_transfer(v10, &v21, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v11 = *(_QWORD *)(a1 + 3160);
  v12 = *(_WORD *)(v11 + 2);
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v21 = v12;
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
  *(_BYTE *)(a1 + 3760) = 93;
  *(_BYTE *)(a1 + 3761) = v4;
  v13 = *(_QWORD *)(v11 + 24);
  v22 = 0x20000;
  v23 = 0;
  v24 = v3;
  if ( (int)i2c_transfer(v13, &v21, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v14 = *(_QWORD *)(a1 + 3160);
  v15 = *(_WORD *)(v14 + 2);
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v21 = v15;
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
  *(_WORD *)(a1 + 3760) = 4186;
  v16 = *(_QWORD *)(v14 + 24);
  v22 = 0x20000;
  v23 = 0;
  v24 = v3;
  if ( (int)i2c_transfer(v16, &v21, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v17 = *(_QWORD *)(a1 + 3160);
  v18 = *(_WORD *)(v17 + 2);
  v22 = 0x20000;
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
  *(_BYTE *)(a1 + 3760) = 90;
  v19 = *(_QWORD *)(v17 + 24);
  v21 = v18;
  v23 = 0;
  v24 = v3;
  result = i2c_transfer(v19, &v21, 1);
  if ( (int)result <= 0 )
    result = printk(&unk_A9C9, "lt9611uxc_write_byte");
  _ReadStatusReg(SP_EL0);
  return result;
}
