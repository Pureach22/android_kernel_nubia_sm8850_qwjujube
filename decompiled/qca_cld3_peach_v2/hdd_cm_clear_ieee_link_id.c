__int64 __fastcall hdd_cm_clear_ieee_link_id(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  const char *v12; // x4
  __int64 result; // x0

  if ( (a2 & 1) != 0 )
    v10 = 1672;
  else
    v10 = 976;
  if ( (a2 & 1) != 0 )
    v12 = "cache_conn_info";
  else
    v12 = "conn_info";
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: %s: clear link id:%d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_cm_clear_ieee_link_id",
             v12,
             *(unsigned int *)(a1 + v10));
  *(_DWORD *)(a1 + v10) = 255;
  return result;
}
