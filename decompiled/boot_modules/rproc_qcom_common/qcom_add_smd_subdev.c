__int64 __fastcall qcom_add_smd_subdev(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0

  result = of_get_child_by_name(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 744LL), "smd-edge");
  a2[7] = result;
  if ( result )
  {
    a2[6] = a1 + 56;
    a2[3] = smd_subdev_start;
    a2[4] = smd_subdev_stop;
    return rproc_add_subdev(a1, a2);
  }
  return result;
}
