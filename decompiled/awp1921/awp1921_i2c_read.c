__int64 __fastcall awp1921_i2c_read(__int64 *a1, char a2, _WORD *a3)
{
  int v5; // w21
  __int64 v6; // x8
  __int16 v7; // w9
  __int64 v8; // x0
  __int64 result; // x0
  char v10; // [xsp+0h] [xbp-30h] BYREF
  unsigned __int16 v11; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-28h] BYREF
  char *v13; // [xsp+10h] [xbp-20h]
  __int64 v14; // [xsp+18h] [xbp-18h]
  unsigned __int16 *v15; // [xsp+20h] [xbp-10h]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v5 = 5;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v10 = a2;
  while ( 1 )
  {
    v6 = *a1;
    v13 = nullptr;
    v14 = 0;
    v12 = 0;
    v7 = *(_WORD *)(v6 + 2);
    v15 = &v11;
    v8 = *(_QWORD *)(v6 + 24);
    WORD2(v12) = 1;
    LOWORD(v12) = v7;
    v13 = &v10;
    LOWORD(v14) = v7;
    *(_DWORD *)((char *)&v14 + 2) = 131073;
    if ( (i2c_transfer(v8, &v12, 2) & 0x80000000) == 0 )
      break;
    printk(&unk_84FA, "awp1921_i2c_read", 164);
    usleep_range_state(2000, 3000, 2);
    if ( --v5 == -1 )
      goto LABEL_8;
  }
  if ( (v5 & 0x80) == 0 )
  {
    result = 0;
    *a3 = bswap32(v11) >> 16;
    goto LABEL_7;
  }
LABEL_8:
  printk(&unk_7F6A, "awp1921_i2c_read", 171);
  result = 0xFFFFFFFFLL;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
