__int64 __fastcall swr_hap_disable_hpwr_vreg(_QWORD *a1)
{
  __int64 result; // x0
  unsigned int v3; // w0
  unsigned int v4; // w0
  unsigned int v5; // w20

  result = a1[8];
  if ( result )
  {
    if ( *((_BYTE *)a1 + 182) == 1 )
    {
      v3 = regulator_disable(result);
      if ( (v3 & 0x80000000) != 0 )
      {
        v5 = v3;
        if ( (unsigned int)__ratelimit(&swr_hap_disable_hpwr_vreg__rs, "swr_hap_disable_hpwr_vreg") )
          dev_err(*a1, "%s: Disable hpwr failed, rc=%d\n", "swr_hap_disable_hpwr_vreg", v5);
      }
      else
      {
        v4 = regulator_set_voltage(a1[8], 0, 0x7FFFFFFF);
        if ( (v4 & 0x80000000) == 0 )
        {
          *((_BYTE *)a1 + 182) = 0;
          return 0;
        }
        v5 = v4;
        if ( (unsigned int)__ratelimit(&swr_hap_disable_hpwr_vreg__rs_51, "swr_hap_disable_hpwr_vreg") )
          dev_err(*a1, "%s: Set hpwr voltage failed, rc=%d\n", "swr_hap_disable_hpwr_vreg", v5);
      }
      return v5;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
