__int64 __fastcall a6xx_rgmu_bind(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x22
  unsigned int all; // w21
  __int64 *v7; // x23
  __int64 v8; // x24
  __int64 v9; // x26
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w0
  __int64 v13; // x0
  __int64 v14; // x8
  int v15; // w8
  unsigned __int64 v22; // x9

  v2 = *(_QWORD **)(a2 + 152);
  v3 = a1 - 16;
  *(v2 - 11) = a1 - 16;
  all = kgsl_pwrctrl_probe_gdscs(v2, a1 - 16);
  if ( all )
    return all;
  v7 = v2 - 7;
  all = devm_clk_bulk_get_all(*(v2 - 11) + 16LL, v2 - 7);
  if ( (all & 0x80000000) != 0 )
    return all;
  v8 = *v7;
  if ( all )
  {
    v9 = 0;
    while ( strcmp(*(const char **)(v8 + v9), "apb_pclk") )
    {
      v9 += 16;
      if ( 16LL * all == v9 )
        goto LABEL_10;
    }
    *(_QWORD *)(v8 + v9 + 8) = 0;
    v8 = *v7;
  }
LABEL_10:
  *((_DWORD *)v2 - 12) = all;
  v10 = kgsl_of_clk_by_name(v8, all, "core");
  *(v2 - 5) = v10;
  if ( !v10 )
  {
    dev_err(*(v2 - 11) + 16LL, "The GPU clock isn't defined\n");
    return (unsigned int)-19;
  }
  v11 = kgsl_of_clk_by_name(*(v2 - 7), all, "gmu");
  *(v2 - 4) = v11;
  if ( !v11 )
  {
    dev_err(*(v2 - 11) + 16LL, "The RGMU clock isn't defined\n");
    return (unsigned int)-19;
  }
  v12 = kgsl_regmap_add_region(v2 + 1650, v3, "kgsl_rgmu", 0, 0);
  if ( v12 )
  {
    all = v12;
    dev_err(a1, "Unable to map the RGMU registers\n");
  }
  else
  {
    all = kgsl_request_irq(*(v2 - 11), "kgsl_oob", a6xx_oob_irq_handler, v2);
    if ( (all & 0x80000000) == 0 )
    {
      v13 = *(v2 - 11);
      *((_DWORD *)v2 - 19) = all;
      all = kgsl_request_irq(v13, "kgsl_rgmu", a6xx_rgmu_irq_handler, v2);
      if ( (all & 0x80000000) == 0 )
      {
        v14 = v2[1783];
        *((_DWORD *)v2 - 20) = all;
        if ( (*(_BYTE *)(v14 + 32) & 0x40) != 0 )
        {
          *(_QWORD *)((char *)v2 + 24036) = 0xF0000001680LL;
          v15 = 3;
        }
        else
        {
          v15 = 0;
        }
        *((_DWORD *)v2 - 6) = v15;
        _X8 = v2 + 191;
        __asm { PRFM            #0x11, [X8] }
        do
          v22 = __ldxr(_X8);
        while ( __stxr(v22 | 0x10, _X8) );
        all = 0;
        v2[190] = a6xx_rgmudev;
      }
    }
  }
  return all;
}
