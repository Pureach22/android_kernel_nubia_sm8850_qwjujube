__int64 __fastcall qcom_pmic_get(__int64 a1)
{
  if ( of_match_device(&_mod_of__pmic_spmi_id_table_device_table, *(_QWORD *)(a1 + 96)) )
    return *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 8LL;
  else
    return -22;
}
