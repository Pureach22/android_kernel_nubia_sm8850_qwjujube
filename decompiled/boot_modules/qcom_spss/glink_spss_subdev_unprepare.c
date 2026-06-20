__int64 __fastcall glink_spss_subdev_unprepare(__int64 a1)
{
  return qcom_glink_ssr_notify(*(_QWORD *)(a1 + 48));
}
