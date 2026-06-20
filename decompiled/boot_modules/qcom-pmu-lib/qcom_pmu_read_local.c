__int64 __fastcall qcom_pmu_read_local(unsigned int a1, __int64 *a2)
{
  return _qcom_pmu_read(*(_DWORD *)(_ReadStatusReg(SP_EL0) + 40), a1, a2, 1);
}
