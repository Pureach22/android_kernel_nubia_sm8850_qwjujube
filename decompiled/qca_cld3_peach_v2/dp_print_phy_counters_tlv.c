__int64 __fastcall dp_print_phy_counters_tlv(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned __int16 v11; // w23
  __int16 v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  _BYTE v22[1000]; // [xsp+0h] [xbp-3F0h] BYREF
  __int64 v23; // [xsp+3E8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v22, 0, sizeof(v22));
  DP_PRINT_STATS("HTT_PHY_COUNTERS_TLV", v2, v3, v4, v5, v6, v7, v8, v9);
  v10 = 0;
  v11 = 0;
  do
  {
    if ( v11 >= 0x3E9u )
      __break(0x5512u);
    v12 = snprintf(&v22[v11], 1000LL - v11, " %u:%u,", v10, *(_DWORD *)(a1 + 104 + 4 * v10));
    ++v10;
    v11 += v12;
  }
  while ( v10 != 20 );
  result = DP_PRINT_STATS("per_blk_err_cnt: %s\n", v13, v14, v15, v16, v17, v18, v19, v20, v22);
  _ReadStatusReg(SP_EL0);
  return result;
}
