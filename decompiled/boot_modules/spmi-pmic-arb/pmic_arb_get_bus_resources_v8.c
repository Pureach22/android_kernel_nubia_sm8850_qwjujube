unsigned __int64 __fastcall pmic_arb_get_bus_resources_v8(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int matched; // w0
  unsigned __int64 result; // x0

  matched = of_property_match_string(a2, "reg-names", "chnl_owner");
  if ( (matched & 0x80000000) != 0 )
  {
    dev_err(a1 + 16, "chnl_owner reg region missing\n");
    return 4294967274LL;
  }
  else
  {
    result = devm_of_iomap(a1 + 16, a2, matched, 0);
    *(_QWORD *)(a3 + 32) = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
      return 0;
    else
      return (unsigned int)result;
  }
}
