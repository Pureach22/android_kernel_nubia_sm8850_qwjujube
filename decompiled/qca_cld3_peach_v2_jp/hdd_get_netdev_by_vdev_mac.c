__int64 __fastcall hdd_get_netdev_by_vdev_mac(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 adapter_by_macaddr; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7

  context = _cds_get_context(51, (__int64)"hdd_get_netdev_by_vdev_mac", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    adapter_by_macaddr = hdd_get_adapter_by_macaddr((__int64)context, a1);
    if ( adapter_by_macaddr )
      return *(_QWORD *)(adapter_by_macaddr + 32);
    if ( a1 )
    {
      v29 = *a1;
      v30 = a1[1];
      v31 = a1[2];
      v32 = a1[5];
    }
    else
    {
      v31 = 0;
      v29 = 0;
      v30 = 0;
      v32 = 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Adapter not foud for MAC %02x:%02x:%02x:**:**:%02x",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "hdd_get_netdev_by_vdev_mac",
      v29,
      v30,
      v31,
      v32);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid HDD context",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "hdd_get_netdev_by_vdev_mac");
  }
  return 0;
}
