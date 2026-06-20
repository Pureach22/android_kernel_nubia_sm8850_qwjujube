__int64 __fastcall adc_tm5_gen3_configure(__int64 a1)
{
  _QWORD *v2; // x19
  __int64 v3; // x1
  __int64 result; // x0
  unsigned int v5; // w0
  char v6; // w13
  char v7; // w11
  char v8; // w8
  char v9; // w12
  char v10; // w13
  char v11; // w9
  char v12; // w10
  char v13; // w8
  int v14; // w11
  int v15; // w12
  char v16; // w9
  char v17; // w8
  unsigned int v18; // w10
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x10
  __int64 v23; // x0
  __int64 v24; // x8
  void *v25; // x8
  unsigned int v26; // w19
  void *v27; // x0
  __int64 v28; // x1
  __int64 v29; // x2
  char v30[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-18h] BYREF
  int v32; // [xsp+10h] [xbp-10h]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 56);
  v3 = *(unsigned int *)(a1 + 28);
  v32 = 0;
  v31 = 0;
  result = adc5_gen3_poll_wait_hs(v2, v3);
  if ( (result & 0x80000000) == 0 )
  {
    v5 = regmap_bulk_read(
           *v2,
           (unsigned int)*(unsigned __int16 *)(v2[3] + 24LL * *(unsigned int *)(a1 + 28)) + 79,
           &v31,
           12);
    if ( (v5 & 0x80000000) != 0 )
    {
      v25 = &unk_9458;
    }
    else
    {
      v6 = *(_BYTE *)(a1 + 4);
      v7 = *(_DWORD *)(a1 + 80);
      v8 = *(_BYTE *)(a1 + 12) & 0x1F | (32 * (*(_BYTE *)(a1 + 32) & 3));
      BYTE1(v31) = *(_BYTE *)(a1 + 76) | 0x80;
      v9 = BYTE3(v31) & 0xC3 | (16 * v6);
      v10 = *(_BYTE *)(a1 + 8);
      v11 = BYTE4(v31) & 0x78 | *(_BYTE *)(a1 + 24);
      LOBYTE(v31) = v8;
      v12 = *(_BYTE *)(a1 + 20);
      v13 = v9 | (4 * v10);
      BYTE2(v31) = v7;
      v14 = *(_DWORD *)(a1 + 96);
      v15 = *(_DWORD *)(a1 + 100);
      BYTE4(v31) = v11 | 0x80;
      v16 = *(_DWORD *)a1;
      BYTE3(v31) = v13;
      BYTE5(v31) = v16;
      v17 = BYTE6(v31) & 0xF0 | v12;
      v18 = *(_DWORD *)(a1 + 28);
      HIBYTE(v31) = v15 | (2 * v14);
      BYTE6(v31) = v17;
      v19 = *(_QWORD *)(a1 + 112);
      v20 = 24LL * v18;
      v21 = v2[3];
      LOWORD(v32) = *(_QWORD *)(a1 + 120);
      HIWORD(v32) = v19;
      v5 = regmap_bulk_write(*v2, (unsigned int)*(unsigned __int16 *)(v21 + v20) + 79, &v31, 12);
      if ( (v5 & 0x80000000) == 0 )
      {
        v22 = v2[3];
        v23 = *v2;
        v24 = 24LL * *(unsigned int *)(a1 + 28);
        v30[0] = 1;
        result = regmap_bulk_write(v23, (unsigned int)*(unsigned __int16 *)(v22 + v24) + 229, v30, 1);
        if ( (result & 0x80000000) == 0 )
          goto LABEL_5;
        v26 = result;
        v27 = &unk_95F2;
        v28 = 229;
        v29 = 1;
LABEL_10:
        printk(v27, v28, v29);
        result = v26;
        goto LABEL_5;
      }
      v25 = &unk_95F2;
    }
    v26 = v5;
    v27 = v25;
    v28 = 79;
    v29 = 12;
    goto LABEL_10;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
