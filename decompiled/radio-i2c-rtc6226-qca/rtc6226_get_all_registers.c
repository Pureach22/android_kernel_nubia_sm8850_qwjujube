__int64 __fastcall rtc6226_get_all_registers(__int64 a1)
{
  __int64 v2; // x8
  __int16 v3; // w10
  __int64 v4; // x0
  __int64 result; // x0
  __int16 v6; // x9^2
  __int16 v7; // x10^2
  unsigned int v8; // w12
  __int16 v9; // x11^2
  unsigned int v10; // w8
  unsigned int v11; // w9
  unsigned int v12; // w12
  unsigned int v13; // w10
  unsigned int v14; // w9
  unsigned int v15; // w11
  unsigned int v16; // w10
  unsigned int v17; // w9
  unsigned int v18; // w11
  unsigned int v19; // w12
  char v20; // [xsp+4h] [xbp-4Ch] BYREF
  __int16 v21; // [xsp+8h] [xbp-48h] BYREF
  int v22; // [xsp+Ah] [xbp-46h]
  __int16 v23; // [xsp+Eh] [xbp-42h]
  __int64 *v24; // [xsp+10h] [xbp-40h]
  __int16 v25; // [xsp+18h] [xbp-38h] BYREF
  int v26; // [xsp+1Ah] [xbp-36h]
  __int16 v27; // [xsp+1Eh] [xbp-32h]
  char *v28; // [xsp+20h] [xbp-30h]
  __int64 v29; // [xsp+28h] [xbp-28h] BYREF
  __int64 v30; // [xsp+30h] [xbp-20h]
  __int64 v31; // [xsp+38h] [xbp-18h]
  __int64 v32; // [xsp+40h] [xbp-10h]
  __int64 v33; // [xsp+48h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3488);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v3 = *(_WORD *)(v2 + 2);
  v26 = 0x10000;
  v28 = &v20;
  v4 = *(_QWORD *)(v2 + 24);
  v20 = 0;
  v22 = 2097153;
  v27 = 0;
  v25 = v3;
  v21 = v3;
  v23 = 0;
  v24 = &v29;
  if ( (unsigned int)i2c_transfer(v4, &v25, 1) != 1
    || (i2c_transfer(*(_QWORD *)(*(_QWORD *)(a1 + 3488) + 24LL), &v21, 1) & 0x80000000) != 0 )
  {
    result = 4294967291LL;
  }
  else
  {
    result = 0;
    v6 = bswap32(WORD1(v29)) >> 16;
    v7 = bswap32(WORD2(v29)) >> 16;
    v8 = bswap32((unsigned __int16)v30);
    v9 = bswap32(HIWORD(v29)) >> 16;
    *(_WORD *)(a1 + 1762) = bswap32((unsigned __int16)v29) >> 16;
    v10 = WORD1(v30);
    *(_WORD *)(a1 + 1764) = v6;
    v11 = HIWORD(v8);
    v12 = WORD2(v31);
    *(_WORD *)(a1 + 1766) = v7;
    v13 = WORD2(v30);
    *(_WORD *)(a1 + 1770) = v11;
    v14 = HIWORD(v30);
    *(_WORD *)(a1 + 1768) = v9;
    v15 = WORD1(v31);
    *(_WORD *)(a1 + 1772) = bswap32(v10) >> 16;
    HIWORD(v10) = bswap32(v13) >> 16;
    HIWORD(v13) = bswap32((unsigned __int16)v31) >> 16;
    *(_WORD *)(a1 + 1774) = HIWORD(v10);
    *(_WORD *)(a1 + 1776) = bswap32(v14) >> 16;
    *(_WORD *)(a1 + 1778) = HIWORD(v13);
    v16 = HIWORD(v31);
    *(_WORD *)(a1 + 1780) = bswap32(v15) >> 16;
    v17 = (unsigned __int16)v32;
    v18 = WORD2(v32);
    *(_WORD *)(a1 + 1782) = bswap32(v12) >> 16;
    HIWORD(v10) = bswap32(v16) >> 16;
    v19 = HIWORD(v32);
    HIWORD(v16) = bswap32(WORD1(v32)) >> 16;
    *(_WORD *)(a1 + 1784) = HIWORD(v10);
    *(_WORD *)(a1 + 1786) = bswap32(v17) >> 16;
    *(_WORD *)(a1 + 1788) = HIWORD(v16);
    *(_WORD *)(a1 + 1790) = bswap32(v18) >> 16;
    *(_WORD *)(a1 + 1792) = bswap32(v19) >> 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
