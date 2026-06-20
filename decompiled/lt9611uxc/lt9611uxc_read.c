__int64 __fastcall lt9611uxc_read(_QWORD *a1, char a2, void *a3, unsigned int a4)
{
  const void *v4; // x21
  __int64 v7; // x8
  __int16 v8; // w10
  _QWORD *v9; // x9
  __int64 v10; // x0
  __int64 result; // x0
  __int16 v12; // [xsp+8h] [xbp-28h] BYREF
  int v13; // [xsp+Ah] [xbp-26h]
  __int16 v14; // [xsp+Eh] [xbp-22h]
  _QWORD *v15; // [xsp+10h] [xbp-20h]
  __int16 v16; // [xsp+18h] [xbp-18h]
  __int16 v17; // [xsp+1Ah] [xbp-16h]
  __int16 v18; // [xsp+1Ch] [xbp-14h]
  __int16 v19; // [xsp+1Eh] [xbp-12h]
  _QWORD *v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v4 = a1 + 486;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a1[395];
  v8 = *(_WORD *)(v7 + 2);
  v20 = a1 + 486;
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
  a1[501] = 0;
  a1[500] = 0;
  a1[499] = 0;
  a1[498] = 0;
  a1[497] = 0;
  a1[496] = 0;
  a1[495] = 0;
  a1[494] = 0;
  a1[493] = 0;
  a1[492] = 0;
  a1[491] = 0;
  a1[490] = 0;
  a1[489] = 0;
  a1[488] = 0;
  a1[487] = 0;
  a1[486] = 0;
  *((_BYTE *)a1 + 3760) = a2;
  v13 = 0x10000;
  v9 = a1 + 470;
  v10 = *(_QWORD *)(v7 + 24);
  v15 = v9;
  v17 = 1;
  v14 = 0;
  v12 = v8;
  v16 = v8;
  v18 = a4;
  v19 = 0;
  if ( (unsigned int)i2c_transfer(v10, &v12, 2) == 2 )
  {
    memcpy(a3, v4, a4);
    result = 0;
  }
  else
  {
    printk(&unk_ADE4, "lt9611uxc_read");
    result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
