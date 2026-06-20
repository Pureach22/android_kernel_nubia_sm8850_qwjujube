__int64 __fastcall qcom_add_glink_subdev(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 result; // x0

  result = of_get_child_by_name(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 744LL), "glink-edge");
  a2[8] = result;
  if ( result )
  {
    result = kstrdup_const(a3, 3264);
    a2[6] = result;
    if ( result )
    {
      a2[7] = a1 + 56;
      a2[3] = glink_subdev_start;
      a2[4] = glink_subdev_stop;
      a2[5] = glink_subdev_unprepare;
      return rproc_add_subdev(a1, a2);
    }
  }
  return result;
}
