__int64 __fastcall lt9611uxc_firmware_write(__int64 a1, char *src, int a3)
{
  int v3; // w9
  __int64 v4; // x8
  size_t v7; // x20
  __int64 v8; // x23
  int v9; // w19
  __int64 v10; // x8
  __int16 v11; // w9
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x9
  __int64 v15; // x12
  __int64 v16; // x0
  __int64 v17; // x8
  __int16 v18; // w11
  __int64 v19; // x10
  __int64 v20; // x10
  __int64 v21; // x0
  __int64 result; // x0
  size_t v23; // [xsp+8h] [xbp-48h]
  __int16 v24; // [xsp+18h] [xbp-38h] BYREF
  int v25; // [xsp+1Ah] [xbp-36h]
  __int16 v26; // [xsp+1Eh] [xbp-32h]
  __int64 v27; // [xsp+20h] [xbp-30h]
  __int64 dest; // [xsp+28h] [xbp-28h] BYREF
  __int64 v29; // [xsp+30h] [xbp-20h]
  __int64 v30; // [xsp+38h] [xbp-18h]
  __int64 v31; // [xsp+40h] [xbp-10h]
  __int64 v32; // [xsp+48h] [xbp-8h]

  v3 = a3 + 31;
  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 0 )
    v3 = a3;
  v32 = v4;
  v7 = a3 - (v3 & 0xFFFFFFE0);
  if ( a3 < 32 )
  {
    LODWORD(v8) = 0;
    if ( (int)v7 < 1 )
      goto LABEL_15;
    goto LABEL_11;
  }
  v23 = a3 - (v3 & 0xFFFFFFE0);
  v8 = 0;
  v9 = v3 >> 5;
  do
  {
    lt9611uxc_flash_write_config((_QWORD *)a1);
    v10 = *(_QWORD *)(a1 + 3160);
    v11 = *(_WORD *)(v10 + 2);
    *(_BYTE *)(a1 + 3760) = 89;
    v13 = *(_QWORD *)&src[v8 + 16];
    v12 = *(_QWORD *)&src[v8 + 24];
    *(_DWORD *)((char *)&dest + 2) = 2162688;
    LOWORD(dest) = v11;
    v14 = *(_QWORD *)&src[v8];
    v15 = *(_QWORD *)&src[v8 + 8];
    HIWORD(dest) = 0;
    *(_QWORD *)(a1 + 3777) = v13;
    *(_QWORD *)(a1 + 3785) = v12;
    *(_QWORD *)(a1 + 3761) = v14;
    *(_QWORD *)(a1 + 3769) = v15;
    v16 = *(_QWORD *)(v10 + 24);
    v29 = a1 + 3760;
    if ( (int)i2c_transfer(v16, &dest, 1) <= 0 )
      printk(&unk_A9C9, "lt9611uxc_write");
    lt9611uxc_flash_write_addr_set(a1, v8);
    msleep(20);
    --v9;
    v8 += 32;
  }
  while ( v9 );
  v7 = v23;
  src += v8;
  if ( (int)v23 >= 1 )
  {
LABEL_11:
    v30 = -1;
    v31 = -1;
    dest = -1;
    v29 = -1;
    if ( (unsigned int)v7 >= 0x21 )
      _fortify_panic(17, 32, v7);
    memcpy(&dest, src, v7);
    lt9611uxc_flash_write_config((_QWORD *)a1);
    v17 = *(_QWORD *)(a1 + 3160);
    v18 = *(_WORD *)(v17 + 2);
    v25 = 2162688;
    *(_BYTE *)(a1 + 3760) = 89;
    v19 = v29;
    v24 = v18;
    v26 = 0;
    *(_QWORD *)(a1 + 3761) = dest;
    *(_QWORD *)(a1 + 3769) = v19;
    v20 = v31;
    *(_QWORD *)(a1 + 3777) = v30;
    *(_QWORD *)(a1 + 3785) = v20;
    v21 = *(_QWORD *)(v17 + 24);
    v27 = a1 + 3760;
    if ( (int)i2c_transfer(v21, &v24, 1) <= 0 )
      printk(&unk_A9C9, "lt9611uxc_write");
    lt9611uxc_flash_write_addr_set(a1, v8);
    msleep(20);
  }
LABEL_15:
  msleep(20);
  result = printk(&unk_B237, "lt9611uxc_firmware_write");
  _ReadStatusReg(SP_EL0);
  return result;
}
