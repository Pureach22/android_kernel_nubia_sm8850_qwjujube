__int64 __fastcall dp_print_rx_soc_fw_refill_ring_num_rxdma_err_tlv(_DWORD *a1)
{
  unsigned int v2; // w24
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w20
  unsigned __int16 v20; // w23
  __int64 v21; // x19
  _DWORD *v22; // x25
  __int16 v23; // w0
  __int64 v24; // x8
  _BYTE v26[1000]; // [xsp+0h] [xbp-3F0h] BYREF
  __int64 v27; // [xsp+3E8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v26, 0, sizeof(v26));
  v2 = (*a1 >> 14) & 0x3FF;
  DP_PRINT_STATS("HTT_RX_SOC_FW_REFILL_RING_NUM_RXDMA_ERR_TLV_V", v3, v4, v5, v6, v7, v8, v9, v10);
  if ( v2 )
  {
    v19 = 0;
    v20 = 0;
    v21 = 0;
    if ( v2 >= 0x10 )
      v2 = 16;
    v22 = a1 + 1;
    do
    {
      if ( v20 >= 0x3E9u )
        __break(0x5512u);
      v23 = snprintf(&v26[v20], 1000LL - v20, " %u() -%u,", v19, v22[(unsigned __int8)v19]);
      v24 = (unsigned int)v22[(unsigned __int8)v19++];
      v20 += v23;
      v21 += v24;
    }
    while ( v2 > (unsigned __int8)v19 );
  }
  else
  {
    v21 = 0;
  }
  DP_PRINT_STATS("rxdma_err = %s\n", v11, v12, v13, v14, v15, v16, v17, v18, v26);
  _ReadStatusReg(SP_EL0);
  return v21;
}
