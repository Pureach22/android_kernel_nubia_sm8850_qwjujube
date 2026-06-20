__int64 __fastcall lt9611uxc_get_version(_QWORD *a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x8
  __int16 v4; // w9
  __int64 v5; // x0
  __int64 v6; // x8
  __int16 v7; // w9
  __int64 v8; // x0
  __int64 v9; // x8
  __int16 v10; // w10
  __int64 v11; // x0
  __int64 v12; // x8
  __int16 v13; // w9
  __int64 v14; // x0
  __int64 v15; // x8
  __int16 v16; // w9
  __int64 v17; // x0
  _BYTE v19[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int16 v20; // [xsp+8h] [xbp-18h] BYREF
  int v21; // [xsp+Ah] [xbp-16h]
  __int16 v22; // [xsp+Eh] [xbp-12h]
  _QWORD *v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v2 = a1 + 470;
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[395];
  v19[0] = 0;
  v4 = *(_WORD *)(v3 + 2);
  a1[470] = 0;
  a1[471] = 0;
  v20 = v4;
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
  v5 = *(_QWORD *)(v3 + 24);
  v21 = 0x20000;
  v22 = 0;
  v23 = v2;
  if ( (int)i2c_transfer(v5, &v20, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v6 = a1[395];
  v7 = *(_WORD *)(v6 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v20 = v7;
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
  *((_WORD *)a1 + 1880) = 494;
  v8 = *(_QWORD *)(v6 + 24);
  v21 = 0x20000;
  v22 = 0;
  v23 = v2;
  if ( (int)i2c_transfer(v8, &v20, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v9 = a1[395];
  v10 = *(_WORD *)(v9 + 2);
  v21 = 0x20000;
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
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
  *((_WORD *)a1 + 1880) = -20225;
  v11 = *(_QWORD *)(v9 + 24);
  v20 = v10;
  v22 = 0;
  v23 = v2;
  if ( (int)i2c_transfer(v11, &v20, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  if ( (unsigned int)lt9611uxc_read(a1, 33, v19, 1) )
    printk(&unk_AC3A, "lt9611uxc_get_version");
  else
    printk(&unk_A98E, "lt9611uxc_get_version");
  v12 = a1[395];
  v13 = *(_WORD *)(v12 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v20 = v13;
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
  v21 = 0x20000;
  v22 = 0;
  v23 = v2;
  if ( (int)i2c_transfer(v14, &v20, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v15 = a1[395];
  v16 = *(_WORD *)(v15 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v20 = v16;
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
  *((_BYTE *)a1 + 3760) = -18;
  v17 = *(_QWORD *)(v15 + 24);
  v21 = 0x20000;
  v22 = 0;
  v23 = v2;
  if ( (int)i2c_transfer(v17, &v20, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  msleep(50);
  _ReadStatusReg(SP_EL0);
  return v19[0];
}
