__int64 __fastcall cm_get_ext_hdl_fl(
        __int64 a1,
        __int64 a2,
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
  __int64 cmpt_obj; // x0
  __int64 v15; // x8
  __int64 result; // x0
  __int64 v17; // x23

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 0 )
    {
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
      if ( cmpt_obj && (v15 = *(_QWORD *)(cmpt_obj + 512)) != 0 )
      {
        result = *(_QWORD *)(v15 + 248);
        if ( result )
          return result;
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s:%u: vdev %d cm_ctx is NULL",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a2,
          a3,
          *(unsigned __int8 *)(a1 + 168));
      }
    }
  }
  else
  {
    v17 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x68u, 2u, "%s:%u: vdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, a2, a3);
      cm_get_cm_ctx_fl___last_ticks = v17;
    }
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s:%u: vdev %d cm ext ctx is NULL",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a2,
    a3,
    *(unsigned __int8 *)(a1 + 168));
  return 0;
}
