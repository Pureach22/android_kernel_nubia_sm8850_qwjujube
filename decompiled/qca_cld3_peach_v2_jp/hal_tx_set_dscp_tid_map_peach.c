__int64 __fastcall hal_tx_set_dscp_tid_map_peach(__int64 result, __int64 a2, unsigned __int8 a3)
{
  __int64 v4; // x19
  int v5; // w21
  int v6; // w0
  unsigned __int64 v7; // x25
  __int64 v8; // x24
  __int64 v9; // x20
  bool v10; // cf
  int v11; // w0
  int v12; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v13; // [xsp+10h] [xbp-20h] BYREF
  __int64 v14; // [xsp+18h] [xbp-18h]
  __int64 v15; // [xsp+20h] [xbp-10h]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 <= 0x1Fu )
  {
    v4 = result;
    v14 = 0;
    v15 = 0;
    v13 = 0;
    v5 = 8 * ((3 * a3) & 0x7F);
    v6 = hal_read32_mb_1(result, 10764320);
    hal_write32_mb_1(v4, 10764320, v6 | 0x800000u);
    v7 = 0;
    v8 = 0;
    v9 = a2 + 3;
    do
    {
      v12 = *(unsigned __int8 *)(v9 + v7 - 3)
          | (8 * *(unsigned __int8 *)(v9 + v7 - 2))
          | (*(unsigned __int8 *)(v9 + v7 - 1) << 6)
          | (*(unsigned __int8 *)(v9 + v7) << 9)
          | (*(unsigned __int8 *)(v9 + v7 + 1) << 12)
          | (*(unsigned __int8 *)(v9 + v7 + 2) << 15)
          | (*(unsigned __int8 *)(v9 + v7 + 3) << 18)
          | (*(unsigned __int8 *)(v9 + v7 + 4) << 21);
      qdf_mem_copy((char *)&v13 + v8, &v12, 3u);
      v10 = v7 >= 0x38;
      v7 += 8LL;
      v8 += 3;
    }
    while ( !v10 );
    hal_write32_mb_1(v4, (unsigned int)(v5 + 10764864), (unsigned int)v13);
    hal_write32_mb_1(v4, (unsigned int)(v5 + 10764868), HIDWORD(v13));
    hal_write32_mb_1(v4, (unsigned int)(v5 + 10764872), (unsigned int)v14);
    hal_write32_mb_1(v4, (unsigned int)(v5 + 10764876), HIDWORD(v14));
    hal_write32_mb_1(v4, (unsigned int)(v5 + 10764880), (unsigned int)v15);
    hal_write32_mb_1(v4, (unsigned int)(v5 + 10764884), HIDWORD(v15));
    v11 = hal_read32_mb_1(v4, 10764320);
    result = hal_write32_mb_1(v4, 10764320, v11 & 0xFF7FFFFF);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
