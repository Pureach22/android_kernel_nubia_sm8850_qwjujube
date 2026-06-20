__int64 __fastcall sdhci_msm_dt_get_array(__int64 a1, const char *a2, __int64 *a3, int *a4)
{
  __int64 v4; // x23
  int v9; // w8
  __int64 v10; // x25
  __int64 v11; // x0
  __int64 v12; // x24
  int variable_u32_array; // w0
  __int64 result; // x0
  unsigned int v15; // w22

  v4 = *(_QWORD *)(a1 + 744);
  if ( of_get_property(v4, a2, a4) )
  {
    v9 = *a4;
    *a4 >>= 2;
    if ( (unsigned int)v9 <= 3 )
    {
      dev_err(a1, "%s invalid size\n", a2);
      result = 4294967274LL;
    }
    else
    {
      v10 = (__int64)v9 >> 2;
      v11 = devm_kmalloc(a1, 4 * v10, 3520);
      if ( v11 )
      {
        v12 = v11;
        variable_u32_array = of_property_read_variable_u32_array(v4, a2, v11, v10, 0);
        if ( (variable_u32_array & 0x80000000) == 0 )
        {
          *a3 = v12;
          return 0;
        }
        v15 = variable_u32_array;
        dev_err(a1, "%s failed reading array %d\n", a2, variable_u32_array);
        result = v15;
      }
      else
      {
        result = 4294967284LL;
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  *a4 = 0;
  return result;
}
