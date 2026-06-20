__int64 __fastcall cm_reset_active_cm_id(
        __int64 result,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x20

  if ( result )
  {
    if ( (*(_DWORD *)(result + 16) & 0xFFFFFFFD) == 0 )
    {
      v11 = result;
      result = wlan_vdev_mlme_get_cmpt_obj(result);
      if ( result && (v20 = *(_QWORD *)(result + 512)) != 0 )
      {
        if ( *(_DWORD *)(v20 + 88) == a2 )
          *(_DWORD *)(v20 + 88) = -1;
      }
      else
      {
        return qdf_trace_msg(
                 0x68u,
                 2u,
                 "%s:%u: vdev %d cm_ctx is NULL",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "cm_reset_active_cm_id",
                 123,
                 *(unsigned __int8 *)(v11 + 168));
      }
    }
  }
  else
  {
    v21 = jiffies;
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
                 "cm_reset_active_cm_id",
                 123);
      cm_get_cm_ctx_fl___last_ticks = v21;
    }
  }
  return result;
}
