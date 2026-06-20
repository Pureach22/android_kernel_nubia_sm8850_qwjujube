__int64 __fastcall qcom_cc_runtime_init(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x0
  int v8; // w0

  v4 = clk_get(a1 + 16, "iface");
  if ( v4 == -2 )
    v5 = 0;
  else
    v5 = v4;
  if ( v5 < 0xFFFFFFFFFFFFF001LL )
  {
    clk_put(v5);
    LODWORD(v5) = clk_regulator_init(a1 + 16, a2);
    if ( !(_DWORD)v5 )
    {
      v6 = of_icc_get(a1 + 16, 0);
      *(_QWORD *)(a2 + 104) = v6;
      if ( v6 < 0xFFFFFFFFFFFFF001LL )
      {
        *(_QWORD *)(a1 + 168) = a2;
        LODWORD(v5) = devm_pm_runtime_enable(a1 + 16);
        if ( !(_DWORD)v5 )
        {
          LODWORD(v5) = pm_clk_create(a1 + 16);
          if ( !(_DWORD)v5 )
          {
            v8 = pm_clk_add(a1 + 16, "iface");
            if ( (v8 & 0x80000000) == 0 )
            {
              LODWORD(v5) = 0;
              return (unsigned int)v5;
            }
            LODWORD(v5) = v8;
            dev_err(a1 + 16, "failed to acquire iface clock\n");
            pm_clk_destroy(a1 + 16);
          }
        }
        icc_put(*(_QWORD *)(a2 + 104));
      }
      else if ( v6 == -517 )
      {
        LODWORD(v5) = -517;
      }
      else
      {
        dev_err(a1 + 16, "error getting path\n");
        LODWORD(v5) = *(_DWORD *)(a2 + 104);
      }
      clk_regulator_deinit(a2);
    }
  }
  else if ( v5 != -517 )
  {
    dev_err(a1 + 16, "unable to get iface clock\n");
  }
  return (unsigned int)v5;
}
