__int64 __fastcall lt9611uxc_ctl_disable(_QWORD *a1)
{
  _QWORD *v2; // x21
  __int64 v3; // x8
  __int16 v4; // w9
  __int64 v5; // x0
  __int64 v6; // x8
  __int16 v7; // w9
  __int64 v8; // x0
  __int64 result; // x0
  __int16 v10; // [xsp+8h] [xbp-18h] BYREF
  int v11; // [xsp+Ah] [xbp-16h]
  __int16 v12; // [xsp+Eh] [xbp-12h]
  _QWORD *v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v2 = a1 + 470;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[395];
  v4 = *(_WORD *)(v3 + 2);
  a1[470] = 0;
  a1[471] = 0;
  v10 = v4;
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
  v11 = 0x20000;
  v12 = 0;
  v13 = v2;
  if ( (int)i2c_transfer(v5, &v10, 1) <= 0 )
    printk(&unk_A9C9, "lt9611uxc_write_byte");
  v6 = a1[395];
  v7 = *(_WORD *)(v6 + 2);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v10 = v7;
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
  v8 = *(_QWORD *)(v6 + 24);
  v11 = 0x20000;
  v12 = 0;
  v13 = v2;
  result = i2c_transfer(v8, &v10, 1);
  if ( (int)result <= 0 )
    result = printk(&unk_A9C9, "lt9611uxc_write_byte");
  _ReadStatusReg(SP_EL0);
  return result;
}
