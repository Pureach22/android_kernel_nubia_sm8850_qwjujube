__int64 __fastcall cm_set_max_connect_attempts(
        __int64 result,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  char v22; // w5
  __int64 v23; // x20

  if ( result )
  {
    if ( (*(_DWORD *)(result + 16) & 0xFFFFFFFD) == 0 )
    {
      v11 = result;
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(result);
      if ( cmpt_obj && (v21 = *(_QWORD *)(cmpt_obj + 512)) != 0 )
      {
        if ( a2 >= 0xAu )
          v22 = 10;
        else
          v22 = a2;
        *(_BYTE *)(v21 + 192) = v22;
        return qdf_trace_msg(
                 0x68u,
                 8u,
                 "%s: vdev %d max connect attempts set to %d, requested %d",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "cm_set_max_connect_attempts",
                 *(unsigned __int8 *)(v11 + 168));
      }
      else
      {
        return qdf_trace_msg(
                 0x68u,
                 2u,
                 "%s:%u: vdev %d cm_ctx is NULL",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "cm_set_max_connect_attempts",
                 1251,
                 *(unsigned __int8 *)(v11 + 168));
      }
    }
  }
  else
  {
    v23 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x68u,
                 2u,
                 "%s:%u: vdev is NULL",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "cm_set_max_connect_attempts",
                 1251);
      cm_get_cm_ctx_fl___last_ticks = v23;
    }
  }
  return result;
}
