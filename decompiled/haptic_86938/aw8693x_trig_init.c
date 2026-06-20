__int64 __fastcall aw8693x_trig_init(__int64 a1)
{
  int v2; // w8
  char v3; // w10
  int v4; // w9
  char v5; // w12
  int v6; // w8
  char v7; // w10
  unsigned int v8; // w13
  unsigned int v9; // w11
  int v10; // w8
  bool v11; // zf
  char v12; // w9
  unsigned int v13; // w10
  int v14; // w11
  unsigned int v15; // w9
  __int64 v16; // x3
  int v17; // w8
  int v18; // w9
  char v19; // w11
  _BOOL4 v20; // w10
  char v21; // w8
  int v22; // w12
  int v23; // w13
  char v24; // w10
  char v25; // w9
  char v26; // w11
  char v27; // w10
  int v28; // w8
  char v29; // w11
  char v30; // w9
  int v31; // w10
  unsigned int v32; // w9
  __int16 v33; // w11
  char v34; // w8
  __int64 v35; // x3
  unsigned int v36; // w9
  __int64 v37; // x3
  __int64 result; // x0
  _BYTE v39[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v40[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v41[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v42[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_14A18, "haptic_hv", 1561, "aw8693x_trig_init");
  if ( *(_BYTE *)(a1 + 1215) == 1 )
  {
    printk(&unk_14D34, "haptic_hv", 1563, "aw8693x_trig_init");
    printk(&unk_14A18, "haptic_hv", 779, "aw8693x_one_wire_init");
    v39[0] = 108;
    i2c_w_bytes(a1, 62, v39, 1);
    v39[0] = 117;
    i2c_w_bytes(a1, 60, v39, 1);
    i2c_w_bits(a1, 58, 4294967287LL, 8);
  }
  else
  {
    v2 = *(unsigned __int8 *)(a1 + 1189);
    v3 = *(_BYTE *)(a1 + 1191);
    v4 = *(unsigned __int8 *)(a1 + 1190);
    v5 = *(_BYTE *)(a1 + 1193);
    *(_BYTE *)(a1 + 1511) = v2;
    v6 = v2 != 0;
    *(_BYTE *)(a1 + 1513) = v3;
    v7 = *(_BYTE *)(a1 + 1192);
    v8 = v6 << 6;
    v9 = ((v6 & 1) << 6) | 0xFFFFFF80;
    v10 = *(unsigned __int8 *)(a1 + 1195);
    v11 = v4 == 0;
    *(_BYTE *)(a1 + 1512) = v4;
    v12 = *(_BYTE *)(a1 + 1194);
    *(_BYTE *)(a1 + 1515) = v7;
    if ( v11 )
      v13 = v8;
    else
      v13 = v9;
    v14 = *(unsigned __int8 *)(a1 + 1196);
    *(_BYTE *)(a1 + 1514) = v5;
    *(_BYTE *)(a1 + 1516) = v12;
    if ( v10 )
      v15 = v13 | 0x20;
    else
      v15 = v13;
    *(_BYTE *)(a1 + 1509) = v10;
    if ( v14 )
      v16 = v15 | 0x10;
    else
      v16 = v15;
    *(_BYTE *)(a1 + 1510) = v14;
    i2c_w_bits(a1, 57, 4294967055LL, v16);
    v40[0] = *(_BYTE *)(a1 + 1515) | ((*(_BYTE *)(a1 + 1513) != 0) << 7);
    i2c_w_bytes(a1, 51, v40, 1);
    v40[0] = *(_BYTE *)(a1 + 1516) | ((*(_BYTE *)(a1 + 1514) != 0) << 7);
    i2c_w_bytes(a1, 54, v40, 1);
  }
  v17 = *(unsigned __int8 *)(a1 + 1197);
  v18 = *(unsigned __int8 *)(a1 + 1198);
  v19 = *(_BYTE *)(a1 + 1200);
  *(_BYTE *)(a1 + 1526) = *(_BYTE *)(a1 + 1199);
  v20 = v17 != 0;
  *(_BYTE *)(a1 + 1524) = v17;
  v21 = *(_BYTE *)(a1 + 1201);
  v22 = 4 * v20;
  v23 = (4 * v20) | 8;
  v24 = *(_BYTE *)(a1 + 1206);
  *(_BYTE *)(a1 + 1525) = v18;
  v11 = v18 == 0;
  v25 = *(_BYTE *)(a1 + 1207);
  *(_BYTE *)(a1 + 1528) = v19;
  v26 = *(_BYTE *)(a1 + 1202);
  if ( !v11 )
    v22 = v23;
  *(_BYTE *)(a1 + 1538) = v24;
  v27 = *(_BYTE *)(a1 + 1208);
  *(_BYTE *)(a1 + 1527) = v21;
  v28 = *(unsigned __int8 *)(a1 + 1203);
  *(_BYTE *)(a1 + 1529) = v26;
  v29 = *(_BYTE *)(a1 + 1205);
  *(_BYTE *)(a1 + 1539) = v25;
  v30 = *(_BYTE *)(a1 + 1209);
  v11 = v28 == 0;
  *(_BYTE *)(a1 + 1541) = v27;
  v31 = *(unsigned __int8 *)(a1 + 1204);
  *(_BYTE *)(a1 + 1537) = v29;
  *(_BYTE *)(a1 + 1540) = v30;
  v32 = v22 | 2;
  v33 = *(_WORD *)(a1 + 1211);
  *(_BYTE *)(a1 + 1522) = v28;
  v34 = *(_BYTE *)(a1 + 1210);
  if ( v11 )
    v32 = v22;
  *(_BYTE *)(a1 + 1523) = v31;
  if ( v31 )
    v35 = v32 + 1;
  else
    v35 = v32;
  *(_BYTE *)(a1 + 1542) = v34;
  *(_WORD *)(a1 + 1535) = v33;
  i2c_w_bits(a1, 57, 4294967280LL, v35);
  v41[0] = *(_BYTE *)(a1 + 1528) | ((*(_BYTE *)(a1 + 1526) != 0) << 7);
  i2c_w_bytes(a1, 52, v41, 1);
  v41[0] = *(_BYTE *)(a1 + 1529) | ((*(_BYTE *)(a1 + 1527) != 0) << 7);
  i2c_w_bytes(a1, 55, v41, 1);
  if ( *(_BYTE *)(a1 + 1538) )
    v36 = ((*(_BYTE *)(a1 + 1537) != 0) << 6) | 0xFFFFFF80;
  else
    v36 = (*(_BYTE *)(a1 + 1537) != 0) << 6;
  if ( *(_BYTE *)(a1 + 1535) )
    v36 |= 0x20u;
  if ( *(_BYTE *)(a1 + 1536) )
    v37 = v36 | 0x10;
  else
    v37 = v36;
  i2c_w_bits(a1, 58, 4294967055LL, v37);
  v42[0] = *(_BYTE *)(a1 + 1541) | ((*(_BYTE *)(a1 + 1539) != 0) << 7);
  i2c_w_bytes(a1, 53, v42, 1);
  v42[0] = *(_BYTE *)(a1 + 1542) | ((*(_BYTE *)(a1 + 1540) != 0) << 7);
  result = i2c_w_bytes(a1, 56, v42, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
