__int64 __fastcall icnss_power_on_chain1_reg(__int64 a1)
{
  __int64 *v2; // x20
  __int64 *v3; // x22
  __int64 result; // x0

  v3 = (__int64 *)(a1 + 216);
  v2 = *(__int64 **)(a1 + 216);
  if ( v2 == (__int64 *)(a1 + 216) )
  {
LABEL_7:
    result = 0;
  }
  else
  {
    while ( strcmp("vdd-3.3-ch1", (const char *)v2[3]) || *(_BYTE *)(a1 + 5640) != 1 )
    {
      v2 = (__int64 *)*v2;
      if ( v2 == v3 )
        goto LABEL_7;
    }
    *((_BYTE *)v2 + 53) = 1;
    result = icnss_vreg_on_single(v2);
  }
  *(_BYTE *)(a1 + 5640) = 0;
  return result;
}
