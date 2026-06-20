__int64 __fastcall aw882xx_i2c_read(__int64 a1, char a2, _DWORD *a3)
{
  int v6; // w22
  __int16 v7; // w8
  __int64 v8; // x0
  unsigned int v9; // w28
  __int64 v10; // x1
  __int64 v11; // x1
  __int64 v12; // x1
  __int64 v14; // x1
  char v15; // [xsp+0h] [xbp-30h] BYREF
  unsigned __int16 v16; // [xsp+4h] [xbp-2Ch] BYREF
  __int16 v17; // [xsp+8h] [xbp-28h] BYREF
  int v18; // [xsp+Ah] [xbp-26h]
  __int16 v19; // [xsp+Eh] [xbp-22h]
  char *v20; // [xsp+10h] [xbp-20h]
  __int16 v21; // [xsp+18h] [xbp-18h]
  int v22; // [xsp+1Ah] [xbp-16h]
  __int16 v23; // [xsp+1Eh] [xbp-12h]
  unsigned __int16 *v24; // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v6 = 0;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  while ( 1 )
  {
    v7 = *(_WORD *)(a1 + 2);
    v8 = *(_QWORD *)(a1 + 24);
    v15 = a2;
    v18 = 0x10000;
    v17 = v7;
    v19 = 0;
    v20 = &v15;
    v21 = v7;
    v22 = 131073;
    v23 = 0;
    v24 = &v16;
    v9 = i2c_transfer(v8, &v17, 2);
    if ( (v9 & 0x80000000) == 0 )
      break;
    v12 = *(_QWORD *)(a1 + 144);
    if ( !v12 )
      v12 = *(_QWORD *)(a1 + 32);
    printk(&unk_253AA, v12, "aw882xx_i2c_reads");
    v11 = *(_QWORD *)(a1 + 144);
    if ( v11 )
      goto LABEL_2;
LABEL_8:
    v11 = *(_QWORD *)(a1 + 32);
LABEL_2:
    printk(&unk_23CF2, v11, "aw882xx_i2c_read");
    if ( ++v6 == 5 )
      goto LABEL_15;
  }
  if ( v9 != 2 )
  {
    v10 = *(_QWORD *)(a1 + 144);
    if ( !v10 )
      v10 = *(_QWORD *)(a1 + 32);
    printk(&unk_23D54, v10, "aw882xx_i2c_reads");
    v9 = -6;
    v11 = *(_QWORD *)(a1 + 144);
    if ( v11 )
      goto LABEL_2;
    goto LABEL_8;
  }
  *a3 = __rev16(v16);
  if ( g_print_dbg )
  {
    v14 = *(_QWORD *)(a1 + 144);
    if ( !v14 )
      v14 = *(_QWORD *)(a1 + 32);
    printk(&unk_23D1E, v14, "aw882xx_i2c_read");
  }
  v9 = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v9;
}
