__int64 __fastcall dp_tx_mon_print_ring_stat_2_0(unsigned __int8 *a1)
{
  __int64 *v1; // x19
  unsigned int v2; // w21
  __int64 v3; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v1 = *((__int64 **)a1 + 1);
  v2 = *a1;
  v3 = v1[2507];
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v1[5]) )
  {
    if ( v2 )
    {
LABEL_6:
      __break(0x5512u);
      JUMPOUT(0x5F22A4);
    }
    v2 = *(unsigned __int8 *)(v1[9] + 1);
  }
  dp_print_ring_stat_from_hal((__int64)v1, v3 + 456, 0x18u, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( v2 >= 3 )
    goto LABEL_6;
  return dp_print_ring_stat_from_hal((__int64)v1, v3 + 80LL * v2 + 536, 0x19u, v12, v13, v14, v15, v16, v17, v18, v19);
}
