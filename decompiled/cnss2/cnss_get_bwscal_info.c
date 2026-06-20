__int64 __fastcall cnss_get_bwscal_info(__int64 a1)
{
  __int64 result; // x0

  result = of_find_property(*(_QWORD *)(a1 + 7776), "qcom,no-bwscale", 0);
  *(_BYTE *)(a1 + 7840) = result != 0;
  return result;
}
