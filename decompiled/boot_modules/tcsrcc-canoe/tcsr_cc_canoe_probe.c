__int64 __fastcall tcsr_cc_canoe_probe(__int64 a1)
{
  unsigned __int64 v2; // x2
  unsigned int v3; // w0

  v2 = qcom_cc_map(a1, &tcsr_cc_canoe_desc);
  if ( v2 < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = qcom_cc_really_probe(a1 + 16, &tcsr_cc_canoe_desc, v2);
    if ( v3 )
    {
      LODWORD(v2) = dev_err_probe(a1 + 16, v3, "Failed to register TCSR CC clocks\n");
    }
    else
    {
      dev_info(a1 + 16, "Registered TCSR CC clocks\n");
      LODWORD(v2) = 0;
    }
  }
  return (unsigned int)v2;
}
