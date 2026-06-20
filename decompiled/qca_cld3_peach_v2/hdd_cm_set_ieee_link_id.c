__int64 __fastcall hdd_cm_set_ieee_link_id(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  int v12; // w20
  const char *v14; // x4
  __int64 result; // x0

  if ( (a3 & 1) != 0 )
    v11 = 1672;
  else
    v11 = 976;
  v12 = a2;
  if ( (a3 & 1) != 0 )
    v14 = "cache_conn_info";
  else
    v14 = "conn_info";
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: %s: old_link_id:%d new_link_id:%d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "hdd_cm_set_ieee_link_id",
             v14,
             *(unsigned int *)(a1 + v11),
             a2);
  *(_DWORD *)(a1 + v11) = v12;
  return result;
}
