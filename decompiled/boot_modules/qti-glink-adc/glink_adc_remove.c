__int64 __fastcall glink_adc_remove(__int64 a1)
{
  return pmic_glink_unregister_client(**(_QWORD **)(a1 + 168));
}
