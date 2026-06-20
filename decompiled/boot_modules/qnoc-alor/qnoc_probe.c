__int64 __fastcall qnoc_probe(__int64 a1)
{
  unsigned int v2; // w19

  v2 = qcom_icc_rpmh_probe();
  if ( v2 )
    dev_err(a1 + 16, "failed to register ICC provider: %d\n", v2);
  else
    dev_info(a1 + 16, "Registered Alor ICC provider\n");
  return v2;
}
