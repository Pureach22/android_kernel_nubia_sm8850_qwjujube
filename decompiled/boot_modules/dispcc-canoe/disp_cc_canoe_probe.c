unsigned __int64 __fastcall disp_cc_canoe_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  const char *property; // x0
  unsigned int v6; // w0
  unsigned int v7; // w20
  unsigned int v8; // w8
  unsigned int v15; // w10
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = qcom_cc_map(a1, &disp_cc_canoe_desc);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = result;
    result = qcom_cc_runtime_init(a1, &disp_cc_canoe_desc);
    if ( !(_DWORD)result )
    {
      result = _pm_runtime_resume(a1 + 16, 4);
      if ( (result & 0x80000000) != 0 )
      {
        v8 = *(_DWORD *)(a1 + 496);
        do
        {
          if ( !v8 )
            break;
          _X12 = (unsigned int *)(a1 + 496);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v15 = __ldxr(_X12);
            if ( v15 != v8 )
              break;
            if ( !__stlxr(v8 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v15 == v8;
          v8 = v15;
        }
        while ( !_ZF );
      }
      else
      {
        v4 = *(_QWORD *)(a1 + 760);
        v16 = 0;
        property = (const char *)of_get_property(v4, "compatible", &v16);
        if ( property && v16 >= 1 )
        {
          if ( !strcmp(property, "qcom,alor-dispcc") )
          {
            dword_118 = 176185568;
            dword_1A0 = 176185568;
          }
          clk_lucid_evo_pll_configure(&disp_cc_pll0, v3, &disp_cc_pll0_config);
          clk_lucid_evo_pll_configure(&disp_cc_pll1, v3, &disp_cc_pll1_config);
          regmap_update_bits_base(v3, 61440, 16, 16, 0, 0, 0);
          regmap_update_bits_base(v3, 57444, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 57436, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 49164, 1, 1, 0, 0, 0);
          regmap_update_bits_base(v3, 49160, 1, 1, 0, 0, 0);
          v6 = qcom_cc_really_probe(a1 + 16, &disp_cc_canoe_desc, v3);
          if ( v6 )
            dev_err_probe(a1 + 16, v6, "Failed to register DISP CC clocks\n");
          else
            dev_info(a1 + 16, "Registered DISP CC clocks\n");
          v7 = devm_of_platform_populate(a1 + 16);
          _pm_runtime_idle(a1 + 16, 4);
          result = v7;
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
