__int64 __fastcall dp_print_rx_pdev_fw_stats_phy_err_tlv(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x19
  unsigned __int16 v27; // w23
  __int16 v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  _BYTE v38[1000]; // [xsp+0h] [xbp-3F0h] BYREF
  __int64 v39; // [xsp+3E8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v38, 0, sizeof(v38));
  DP_PRINT_STATS("HTT_RX_PDEV_FW_STATS_PHY_ERR_TLV", v2, v3, v4, v5, v6, v7, v8, v9);
  DP_PRINT_STATS("mac_id_word() - %u", v10, v11, v12, v13, v14, v15, v16, v17, *(unsigned int *)(a1 + 4));
  DP_PRINT_STATS("total_phy_err_cnt: %u", v18, v19, v20, v21, v22, v23, v24, v25, *(unsigned int *)(a1 + 8));
  v26 = 0;
  v27 = 0;
  do
  {
    if ( v27 >= 0x3E9u )
      __break(0x5512u);
    v28 = snprintf(&v38[v27], 1000LL - v27, " %u:%u,", v26, *(_DWORD *)(a1 + 12 + 4 * v26));
    ++v26;
    v27 += v28;
  }
  while ( v26 != 43 );
  result = DP_PRINT_STATS("phy_errs: %s\n", v29, v30, v31, v32, v33, v34, v35, v36, v38);
  _ReadStatusReg(SP_EL0);
  return result;
}
