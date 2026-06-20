__int64 __fastcall qcom_wdt_ppi_bark(__int64 a1, __int64 a2)
{
  qcom_wdt_bark_handler(a1, *(_QWORD *)(_ReadStatusReg(TPIDR_EL1) + a2));
  return 1;
}
