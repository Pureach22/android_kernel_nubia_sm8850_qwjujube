__int64 __fastcall lt9611uxc_fw_read_back(_QWORD *a1, __int64 a2, int a3)
{
  _QWORD *v4; // x21
  __int64 v6; // x8
  __int16 v7; // w9
  int v8; // w9
  int v9; // w9
  int v10; // w22
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
  __int64 v22; // x21
  _QWORD *v23; // x23
  __int64 v24; // x9
  __int64 v25; // x10
  __int16 v26; // [xsp+8h] [xbp-38h] BYREF
  int v27; // [xsp+Ah] [xbp-36h]
  __int16 v28; // [xsp+Eh] [xbp-32h]
  _QWORD *v29; // [xsp+10h] [xbp-30h]
  __int64 v30; // [xsp+18h] [xbp-28h] BYREF
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v4 = a1 + 470;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[395];
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v7 = *(_WORD *)(v6 + 2);
  a1[470] = 0;
  a1[471] = 0;
  v26 = v7;
  v8 = a3 + 31;
  a1[472] = 0;
  if ( a3 >= 0 )
    v8 = a3;
  a1[473] = 0;
  v9 = v8 >> 5;
  a1[474] = 0;
  a1[475] = 0;
  if ( (a3 & 0x1F) != 0 )
    v10 = v9 + 1;
  else
    v10 = v9;
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
  v11 = *(_QWORD *)(v6 + 24);
  v27 = 0x20000;
  v28 = 0;
  v29 = v4;
  if ( (int)i2c_transfer(v11, &v26, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v12 = a1[395];
  v13 = *(_WORD *)(v12 + 2);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v26 = v13;
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
  *((_WORD *)a1 + 1880) = 494;
  v14 = *(_QWORD *)(v12 + 24);
  v27 = 0x20000;
  v28 = 0;
  v29 = v4;
  if ( (int)i2c_transfer(v14, &v26, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v15 = a1[395];
  v16 = *(_WORD *)(v15 + 2);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v26 = v16;
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
  *((_WORD *)a1 + 1880) = -31654;
  v17 = *(_QWORD *)(v15 + 24);
  v27 = 0x20000;
  v28 = 0;
  v29 = v4;
  if ( (int)i2c_transfer(v17, &v26, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v18 = a1[395];
  v19 = *(_WORD *)(v18 + 2);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v26 = v19;
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
  *((_WORD *)a1 + 1880) = -32678;
  v20 = *(_QWORD *)(v18 + 24);
  v27 = 0x20000;
  v28 = 0;
  v29 = v4;
  result = i2c_transfer(v20, &v26, 1);
  if ( (int)result <= 0 )
  {
    result = printk(&unk_A9C9, "lt9611uxc_write_byte");
    if ( v10 < 1 )
      goto LABEL_16;
  }
  else if ( v10 < 1 )
  {
    goto LABEL_16;
  }
  v22 = 0;
  do
  {
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v23 = (_QWORD *)(a2 + v22);
    lt9611uxc_flash_read_addr_set((__int64)a1, v22);
    result = lt9611uxc_read(a1, 95, &v30, 0x20u);
    v24 = v31;
    --v10;
    v22 += 32;
    *v23 = v30;
    v23[1] = v24;
    v25 = v33;
    v23[2] = v32;
    v23[3] = v25;
  }
  while ( v10 );
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
