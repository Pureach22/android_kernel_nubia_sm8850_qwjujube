__int64 __fastcall qcom_show_pmic_model(__int64 a1)
{
  __int64 v1; // x2

  v1 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 128) + 68LL);
  if ( (unsigned int)v1 <= 0x53 && pmic_models[v1] )
    seq_printf(a1, "%s\n", pmic_models[v1]);
  else
    seq_printf(a1, "unknown (%d)\n", v1);
  return 0;
}
