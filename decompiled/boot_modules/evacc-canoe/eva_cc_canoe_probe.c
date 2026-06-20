unsigned __int64 __fastcall eva_cc_canoe_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  const char *property; // x0
  unsigned int v6; // w20
  unsigned int v7; // w8
  unsigned int v14; // w10
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = qcom_cc_map(a1, &eva_cc_canoe_desc);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = result;
    result = qcom_cc_runtime_init(a1, &eva_cc_canoe_desc);
    if ( !(_DWORD)result )
    {
      result = _pm_runtime_resume(a1 + 16, 4);
      if ( (result & 0x80000000) != 0 )
      {
        v7 = *(_DWORD *)(a1 + 496);
        do
        {
          if ( !v7 )
            break;
          _X12 = (unsigned int *)(a1 + 496);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v14 = __ldxr(_X12);
            if ( v14 != v7 )
              break;
            if ( !__stlxr(v7 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v14 == v7;
          v7 = v14;
        }
        while ( !_ZF );
      }
      else
      {
        v4 = *(_QWORD *)(a1 + 760);
        v15 = 0;
        property = (const char *)of_get_property(v4, "compatible", &v15);
        if ( property && v15 >= 1 )
        {
          if ( !strcmp(property, "qcom,alor-evacc") )
            dword_118 = 176185568;
          clk_lucid_evo_pll_configure(&eva_cc_pll0, v3, &eva_cc_pll0_config);
          regmap_update_bits_base(v3, 32832, 65011712, 65011712, 0, 0, 0);
          regmap_update_bits_base(v3, 32884, 65011712, 65011712, 0, 0, 0);
          regmap_update_bits_base(v3, 32932, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 32996, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 32984, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 32980, 1, 1, 0, 0, 0);
          v6 = qcom_cc_really_probe(a1 + 16, &eva_cc_canoe_desc, v3);
          if ( v6 )
            dev_err_probe(a1 + 16, v6, "Failed to register EVA CC clocks\n");
          else
            dev_info(a1 + 16, "Registered EVA CC clocks\n");
          _pm_runtime_idle(a1 + 16, 4);
          result = v6;
        }
        else
        {
          result = 4294967274LL;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
