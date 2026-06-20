__int64 __fastcall glink_spss_subdev_stop(__int64 a1)
{
  __int64 result; // x0

  result = qcom_glink_spss_unregister(*(_QWORD *)(a1 + 72));
  *(_QWORD *)(a1 + 72) = 0;
  return result;
}
