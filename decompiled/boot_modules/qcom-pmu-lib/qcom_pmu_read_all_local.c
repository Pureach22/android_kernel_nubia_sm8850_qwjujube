__int64 __fastcall qcom_pmu_read_all_local(__int64 a1)
{
  return _qcom_pmu_read_all(*(_DWORD *)(_ReadStatusReg(SP_EL0) + 40), a1);
}
