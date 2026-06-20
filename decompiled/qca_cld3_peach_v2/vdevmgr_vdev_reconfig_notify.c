__int64 __fastcall vdevmgr_vdev_reconfig_notify(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  int v12; // w21
  int v15; // w8
  __int64 result; // x0

  v11 = *(_QWORD *)(a1 + 520);
  if ( v11 )
  {
    v12 = a3;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d link removal notify tbtt %d bcn_int %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "vdevmgr_vdev_reconfig_notify",
      *(unsigned __int8 *)(v11 + 168),
      *a2,
      a3);
    v15 = *a2;
    if ( v15 * v12 > 1000 )
    {
      result = 0;
      if ( a3 )
        *a2 = v15 - 0x3E8u / a3;
    }
    else
    {
      *a2 = 0;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: invalid vdev", a4, a5, a6, a7, a8, a9, a10, a11, "vdevmgr_vdev_reconfig_notify");
    return 4;
  }
  return result;
}
