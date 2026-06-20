__int64 __fastcall lt9611uxc_flash_write_config(_QWORD *a1)
{
  __int64 v2; // x8
  _QWORD *v3; // x20
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
  __int16 v16; // w10
  __int64 v17; // x0
  __int64 result; // x0
  __int16 v19; // [xsp+8h] [xbp-18h] BYREF
  int v20; // [xsp+Ah] [xbp-16h]
  __int16 v21; // [xsp+Eh] [xbp-12h]
  _QWORD *v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  lt9611uxc_flash_write_en(a1);
  v2 = a1[395];
  v3 = a1 + 470;
  v4 = *(_WORD *)(v2 + 2);
  a1[470] = 0;
  a1[471] = 0;
  v19 = v4;
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
  *((_WORD *)a1 + 1880) = -32513;
  v5 = *(_QWORD *)(v2 + 24);
  v20 = 0x20000;
  v21 = 0;
  v22 = a1 + 470;
  if ( (int)i2c_transfer(v5, &v19, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v6 = a1[395];
  v7 = *(_WORD *)(v6 + 2);
  *v3 = 0;
  a1[471] = 0;
  a1[472] = 0;
  a1[473] = 0;
  v19 = v7;
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
  *((_WORD *)a1 + 1880) = -8354;
  v8 = *(_QWORD *)(v6 + 24);
  v20 = 0x20000;
  v21 = 0;
  v22 = a1 + 470;
  if ( (int)i2c_transfer(v8, &v19, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v9 = a1[395];
  v10 = *(_WORD *)(v9 + 2);
  *v3 = 0;
  a1[471] = 0;
  a1[472] = 0;
  a1[473] = 0;
  v19 = v10;
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
  *((_WORD *)a1 + 1880) = 8282;
  v11 = *(_QWORD *)(v9 + 24);
  v20 = 0x20000;
  v21 = 0;
  v22 = a1 + 470;
  if ( (int)i2c_transfer(v11, &v19, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v12 = a1[395];
  v13 = *(_WORD *)(v12 + 2);
  *v3 = 0;
  a1[471] = 0;
  a1[472] = 0;
  a1[473] = 0;
  v19 = v13;
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
  *((_BYTE *)a1 + 3760) = 90;
  v14 = *(_QWORD *)(v12 + 24);
  v20 = 0x20000;
  v21 = 0;
  v22 = a1 + 470;
  if ( (int)i2c_transfer(v14, &v19, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v15 = a1[395];
  v16 = *(_WORD *)(v15 + 2);
  v20 = 0x20000;
  *v3 = 0;
  a1[471] = 0;
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
  *((_WORD *)a1 + 1880) = 8536;
  v17 = *(_QWORD *)(v15 + 24);
  v19 = v16;
  v21 = 0;
  v22 = a1 + 470;
  result = i2c_transfer(v17, &v19, 1);
  if ( (int)result <= 0 )
    result = printk(&unk_A9C9, "lt9611uxc_write_byte");
  _ReadStatusReg(SP_EL0);
  return result;
}
