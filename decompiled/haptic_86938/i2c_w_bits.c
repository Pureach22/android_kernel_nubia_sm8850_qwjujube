__int64 __fastcall i2c_w_bits(__int64 a1, char a2, char a3, char a4)
{
  __int64 v8; // x8
  __int16 v9; // w10
  __int64 v10; // x0
  unsigned int v11; // w0
  unsigned int v12; // w0
  __int64 result; // x0
  unsigned int v14; // w19
  void *v15; // x0
  __int64 v16; // x2
  _BYTE v17[4]; // [xsp+0h] [xbp-30h] BYREF
  char v18; // [xsp+4h] [xbp-2Ch] BYREF
  __int16 v19; // [xsp+8h] [xbp-28h] BYREF
  int v20; // [xsp+Ah] [xbp-26h]
  __int16 v21; // [xsp+Eh] [xbp-22h]
  char *v22; // [xsp+10h] [xbp-20h]
  __int16 v23; // [xsp+18h] [xbp-18h]
  int v24; // [xsp+1Ah] [xbp-16h]
  __int16 v25; // [xsp+1Eh] [xbp-12h]
  _BYTE *v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 808);
  v18 = a2;
  v17[0] = 0;
  v9 = *(_WORD *)(v8 + 2);
  v20 = 0x10000;
  v22 = &v18;
  v26 = v17;
  v10 = *(_QWORD *)(v8 + 24);
  v21 = 0;
  v19 = v9;
  v23 = v9;
  v24 = 65537;
  v25 = 0;
  v11 = i2c_transfer(v10, &v19, 2);
  if ( (v11 & 0x80000000) != 0 )
  {
    v14 = v11;
    printk(&unk_147C9, "haptic_hv", 101, "i2c_r_bytes");
LABEL_8:
    v15 = &unk_15E20;
    v16 = 135;
LABEL_10:
    printk(v15, "haptic_hv", v16, "i2c_w_bits");
    result = v14;
    goto LABEL_5;
  }
  if ( v11 != 2 )
  {
    printk(&unk_154F2, "haptic_hv", 104, "i2c_r_bytes");
    v14 = -6;
    goto LABEL_8;
  }
  v17[0] = v17[0] & a3 | a4 & ~a3;
  v12 = i2c_w_bytes(a1, a2, v17, 1u);
  if ( (v12 & 0x80000000) != 0 )
  {
    v14 = v12;
    v15 = &unk_167A9;
    v16 = 142;
    goto LABEL_10;
  }
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
