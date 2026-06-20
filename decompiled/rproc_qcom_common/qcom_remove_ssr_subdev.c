__int64 __fastcall qcom_remove_ssr_subdev(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = rproc_remove_subdev();
  *(_QWORD *)(a2 + 96) = 0;
  return result;
}
