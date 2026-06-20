__int64 __fastcall cm_get_cm_ctx_fl(
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  __int64 v24; // x20

  if ( !a1 )
  {
    v24 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x68u, 2u, "%s:%u: vdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, a2, a3);
      cm_get_cm_ctx_fl___last_ticks = v24;
      return 0;
    }
    return 0;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( !cmpt_obj || (result = *(_QWORD *)(cmpt_obj + 496)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s:%u: vdev %d cm_ctx is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      a2,
      a3,
      *(unsigned __int8 *)(a1 + 104));
    return 0;
  }
  return result;
}
