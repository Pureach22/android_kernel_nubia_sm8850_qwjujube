__int64 __fastcall haptic_i2c_read(__int64 a1, char a2, _WORD *a3)
{
  unsigned int v6; // w22
  __int64 v7; // x8
  __int16 v8; // w9
  __int64 v9; // x0
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  unsigned int v13; // w23
  __int64 v14; // x6
  char v16; // [xsp+0h] [xbp-30h] BYREF
  unsigned __int16 v17; // [xsp+4h] [xbp-2Ch] BYREF
  __int16 v18; // [xsp+8h] [xbp-28h] BYREF
  int v19; // [xsp+Ah] [xbp-26h]
  __int16 v20; // [xsp+Eh] [xbp-22h]
  char *v21; // [xsp+10h] [xbp-20h]
  __int16 v22; // [xsp+18h] [xbp-18h]
  int v23; // [xsp+1Ah] [xbp-16h]
  __int16 v24; // [xsp+1Eh] [xbp-12h]
  unsigned __int16 *v25; // [xsp+20h] [xbp-10h]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v6 = 0;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  while ( 1 )
  {
    v7 = *(_QWORD *)(a1 + 488);
    v16 = a2;
    v8 = *(_WORD *)(v7 + 2);
    v25 = &v17;
    v9 = *(_QWORD *)(v7 + 24);
    v19 = 0x10000;
    v20 = 0;
    v21 = &v16;
    v18 = v8;
    v22 = v8;
    v23 = 131073;
    v24 = 0;
    v13 = i2c_transfer(v9, &v18, 2);
    if ( (v13 & 0x80000000) != 0 )
    {
      printk(&unk_9A3E, "aw86320", 134, "i2c_reads", v10, v11, v12);
      goto LABEL_5;
    }
    if ( v13 == 2 )
      break;
    printk(&unk_9E7F, "aw86320", 137, "i2c_reads", v10, v11, v12);
    v13 = -6;
LABEL_5:
    printk(&unk_95EA, "aw86320", 153, "haptic_i2c_read", v6++, v13, v14);
    if ( v6 == 5 )
      goto LABEL_9;
  }
  *a3 = bswap32(v17) >> 16;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v13;
}
