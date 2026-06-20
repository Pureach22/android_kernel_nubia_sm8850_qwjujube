__int64 __fastcall dp_rx_buffers_replenish_on_demand(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x8
  __int64 v14; // x21
  unsigned int free_desc_list; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v26; // [xsp+18h] [xbp-18h] BYREF
  unsigned int *v27[2]; // [xsp+20h] [xbp-10h] BYREF

  v27[1] = *(unsigned int **)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = nullptr;
  v26 = 0;
  if ( a3 >= 5 )
    goto LABEL_9;
  v12 = a1 + 120LL * a3;
  v14 = v12 + 12416;
  if ( v12 == -12416 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Rx descriptor pool not initialized pool_id:%u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_rx_buffers_replenish_on_demand",
      a3);
    free_desc_list = 4;
    goto LABEL_8;
  }
  free_desc_list = (unsigned __int16)dp_rx_get_free_desc_list(a1, a3, v12 + 12416, a2, v27, &v26);
  if ( !free_desc_list )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to allocate DP rx descriptors",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_rx_buffers_replenish_on_demand");
    goto LABEL_8;
  }
  if ( a3 > 1 )
LABEL_9:
    __break(0x5512u);
  _dp_rx_buffers_replenish(a1, a3, (__int64 *)(a1 + 80LL * a3 + 80), v14, free_desc_list, v27, (__int64)&v26, 0, 0);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return free_desc_list;
}
