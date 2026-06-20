__int64 __fastcall qcom_open_pmic_model(__int64 a1, __int64 a2)
{
  return single_open(a2, qcom_show_pmic_model, *(_QWORD *)(a1 + 696));
}
