__int64 __fastcall lt9611uxc_flash_write_en(_QWORD *a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x8
  __int16 v4; // w9
  __int64 v5; // x0
  __int64 v6; // x8
  __int16 v7; // w9
  __int64 v8; // x0
  __int64 v9; // x8
  __int16 v10; // w9
  __int64 v11; // x0
  __int64 v12; // x8
  __int16 v13; // w9
  __int64 v14; // x0
  __int64 v15; // x8
  __int16 v16; // w9
  __int64 v17; // x0
  __int64 v18; // x8
  __int16 v19; // w9
  __int64 v20; // x0
  __int64 result; // x0
  __int16 v22; // [xsp+8h] [xbp-18h] BYREF
  int v23; // [xsp+Ah] [xbp-16h]
  __int16 v24; // [xsp+Eh] [xbp-12h]
  _QWORD *v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v2 = a1 + 470;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[395];
  v4 = *(_WORD *)(v3 + 2);
  a1[470] = 0;
  a1[471] = 0;
  v22 = v4;
  a1[472] = 0;
  a1[473] = 0;
  a1[474] = 0;
  a1[475] = 0;
  a1[476] = 0;
  a1[477] = 0;
  a1[478] = 0;
  a1[479] = 0;
  a1[480] = 0;
  a1[481] = 0;
  a1[482] = 0;
  a1[483] = 0;
  a1[484] = 0;
  a1[485] = 0;
  *((_WORD *)a1 + 1880) = -32257;
  v5 = *(_QWORD *)(v3 + 24);
  v23 = 0x20000;
  v24 = 0;
  v25 = v2;
  if ( (int)i2c_transfer(v5, &v22, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v6 = a1[395];
  v7 = *(_WORD *)(v6 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v22 = v7;
  v2[4] = 0;
  v2[5] = 0;
  v2[6] = 0;
  v2[7] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[12] = 0;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = 0;
  *((_WORD *)a1 + 1880) = -16632;
  v8 = *(_QWORD *)(v6 + 24);
  v23 = 0x20000;
  v24 = 0;
  v25 = v2;
  if ( (int)i2c_transfer(v8, &v22, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  msleep(20);
  v9 = a1[395];
  v10 = *(_WORD *)(v9 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v22 = v10;
  v2[4] = 0;
  v2[5] = 0;
  v2[6] = 0;
  v2[7] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[12] = 0;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = 0;
  *((_WORD *)a1 + 1880) = -248;
  v11 = *(_QWORD *)(v9 + 24);
  v23 = 0x20000;
  v24 = 0;
  v25 = v2;
  if ( (int)i2c_transfer(v11, &v22, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  msleep(20);
  v12 = a1[395];
  v13 = *(_WORD *)(v12 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v22 = v13;
  v2[4] = 0;
  v2[5] = 0;
  v2[6] = 0;
  v2[7] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[12] = 0;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = 0;
  *((_WORD *)a1 + 1880) = -32513;
  v14 = *(_QWORD *)(v12 + 24);
  v23 = 0x20000;
  v24 = 0;
  v25 = v2;
  if ( (int)i2c_transfer(v14, &v22, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v15 = a1[395];
  v16 = *(_WORD *)(v15 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v22 = v16;
  v2[4] = 0;
  v2[5] = 0;
  v2[6] = 0;
  v2[7] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[12] = 0;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = 0;
  *((_WORD *)a1 + 1880) = 1114;
  v17 = *(_QWORD *)(v15 + 24);
  v23 = 0x20000;
  v24 = 0;
  v25 = v2;
  if ( (int)i2c_transfer(v17, &v22, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v18 = a1[395];
  v19 = *(_WORD *)(v18 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v22 = v19;
  v2[4] = 0;
  v2[5] = 0;
  v2[6] = 0;
  v2[7] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[12] = 0;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = 0;
  *((_BYTE *)a1 + 3760) = 90;
  v20 = *(_QWORD *)(v18 + 24);
  v23 = 0x20000;
  v24 = 0;
  v25 = v2;
  result = i2c_transfer(v20, &v22, 1);
  if ( (int)result <= 0 )
    result = printk(&unk_A9C9, "lt9611uxc_write_byte");
  _ReadStatusReg(SP_EL0);
  return result;
}
