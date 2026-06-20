__int64 __fastcall glink_subdev_unprepare(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v2; // x1

  v1 = *(__int64 **)(*(_QWORD *)(a1 + 56) + 96LL);
  v2 = v1[14];
  if ( !v2 )
    v2 = *v1;
  return qcom_glink_ssr_notify(*(_QWORD *)(a1 + 48), v2);
}
