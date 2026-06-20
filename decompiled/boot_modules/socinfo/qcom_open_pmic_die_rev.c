__int64 __fastcall qcom_open_pmic_die_rev(__int64 a1, __int64 a2)
{
  return single_open(a2, qcom_show_pmic_die_revision, *(_QWORD *)(a1 + 696));
}
