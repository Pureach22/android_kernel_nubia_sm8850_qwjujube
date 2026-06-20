__int64 __fastcall lt9611uxc_block_erase(_QWORD *a1)
{
  __int64 i; // x22
  __int64 v3; // x8
  __int16 v4; // w10
  __int16 v5; // w9
  __int64 v6; // x0
  __int64 result; // x0
  __int16 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+Ah] [xbp-16h]
  __int16 v10; // [xsp+Eh] [xbp-12h]
  _QWORD *v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_AC7B, "lt9611uxc_block_erase");
  for ( i = 0; i != 18; i += 2 )
  {
    v3 = a1[395];
    v4 = *(_WORD *)((char *)&unk_B5E6 + i);
    v5 = *(_WORD *)(v3 + 2);
    a1[470] = 0;
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
    *((_WORD *)a1 + 1880) = v4;
    v6 = *(_QWORD *)(v3 + 24);
    v9 = 0x20000;
    v8 = v5;
    v10 = 0;
    v11 = a1 + 470;
    if ( (int)i2c_transfer(v6, &v8, 1) <= 0 )
      printk(&unk_A9C9, "lt9611uxc_write_byte");
  }
  result = msleep(3000);
  _ReadStatusReg(SP_EL0);
  return result;
}
