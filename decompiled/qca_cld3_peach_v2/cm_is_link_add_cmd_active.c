__int64 __fastcall cm_is_link_add_cmd_active(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 cmpt_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v21; // x20

  if ( !a1 )
  {
    v21 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x68u, 2u, "%s:%u: vdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "cm_is_link_add_cmd_active", 474);
      cm_get_cm_ctx_fl___last_ticks = v21;
      return 0;
    }
    return 0;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
  {
    v19 = *(_QWORD *)(cmpt_obj + 512);
    if ( v19 )
      return (*(unsigned __int8 *)(v19 + 91) >> 5) & 1;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s:%u: vdev %d cm_ctx is NULL",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "cm_is_link_add_cmd_active",
    474,
    *(unsigned __int8 *)(a1 + 168));
  return 0;
}
