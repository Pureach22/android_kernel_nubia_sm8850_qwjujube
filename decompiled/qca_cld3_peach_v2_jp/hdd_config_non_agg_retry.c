__int64 __fastcall hdd_config_non_agg_retry(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w8
  unsigned int v12; // w20

  if ( *(unsigned __int8 *)(a2 + 4) <= 5u )
    v11 = 5;
  else
    v11 = *(unsigned __int8 *)(a2 + 4);
  if ( v11 >= 0x40 )
    v12 = 64;
  else
    v12 = v11;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: sending Non-Agg Retry Th: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_non_agg_retry",
    v12);
  return sme_set_vdev_sw_retry(*(unsigned __int8 *)(a1 + 8), v12, 0);
}
