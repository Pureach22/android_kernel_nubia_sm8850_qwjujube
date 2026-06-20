__int64 __fastcall dp_rx_pdev_mon_buf_desc_pool_alloc(
        unsigned __int8 *a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x19
  __int64 v15; // x22
  __int64 v16; // x21
  unsigned int v17; // w20
  int dp_soc_rx_sw_desc_weight; // w21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  if ( (unsigned int)a2 >= 3 )
  {
    __break(0x5512u);
    return dp_mon_dest_srng_drop_for_mac(a1, a2, a3, a4);
  }
  else
  {
    v14 = *((_QWORD *)a1 + 1);
    v15 = v14 + 120LL * (unsigned int)a2;
    v16 = *(_QWORD *)(v14 + 40);
    v17 = *(_DWORD *)(v14 + 80LL * (unsigned int)a2 + 532);
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: Mon RX Desc Pool[%d] entries=%u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "dp_rx_pdev_mon_buf_desc_pool_alloc",
      *a1,
      v17,
      v12,
      v13);
    dp_soc_rx_sw_desc_weight = wlan_cfg_get_dp_soc_rx_sw_desc_weight(v16);
    result = dp_rx_desc_pool_is_allocated((unsigned int *)(v15 + 11456), v19, v20, v21, v22, v23, v24, v25, v26);
    if ( (_DWORD)result )
      return dp_rx_desc_pool_alloc(
               v14,
               dp_soc_rx_sw_desc_weight * v17,
               v15 + 11456,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35);
  }
  return result;
}
