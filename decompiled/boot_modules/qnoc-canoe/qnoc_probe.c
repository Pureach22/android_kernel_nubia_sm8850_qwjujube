__int64 __fastcall qnoc_probe(__int64 a1)
{
  unsigned int v2; // w0

  v2 = qcom_icc_rpmh_probe();
  if ( v2 )
    return dev_err_probe(a1 + 16, v2, "failed to register ICC provider\n");
  dev_info(a1 + 16, "Registered ICC provider\n");
  return 0;
}
