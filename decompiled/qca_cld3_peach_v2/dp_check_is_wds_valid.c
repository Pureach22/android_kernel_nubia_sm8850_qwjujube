__int64 __fastcall dp_check_is_wds_valid(
        __int64 result,
        unsigned __int16 a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        unsigned __int8 *a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x29
  __int64 v15; // x30
  int v16; // w11
  __int64 v17; // x7
  int v18; // w10
  int v19; // w12
  __int64 v20; // x0

  if ( a6 && (*(_BYTE *)(result + 22520) & 1) != 0 )
  {
    if ( a5 )
    {
      v17 = *a5;
      v18 = a5[1];
      v16 = a5[2];
      v19 = a5[5];
    }
    else
    {
      v16 = 0;
      v17 = 0;
      v18 = 0;
      v19 = 0;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: invalid peer_map_event (soc:%pK): peer_id %d, hw_peer_id %d, peer_mac %02x:%02x:%02x:**:**:%02x, vdev_id %d",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "dp_check_is_wds_valid",
      result,
      a2,
      a3,
      v17,
      v18,
      v16,
      v19,
      a4,
      v14,
      v15);
    v20 = printk(
            &unk_AAA255,
            "0",
            "dp_check_is_wds_valid",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c");
    return dump_stack(v20);
  }
  return result;
}
