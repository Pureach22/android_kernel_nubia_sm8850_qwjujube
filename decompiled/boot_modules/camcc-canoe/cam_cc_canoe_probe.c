unsigned __int64 __fastcall cam_cc_canoe_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  unsigned int v4; // w20
  unsigned int v5; // w8
  unsigned int v12; // w10

  result = qcom_cc_map(a1, &cam_cc_canoe_desc);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = result;
    result = qcom_cc_runtime_init(a1, &cam_cc_canoe_desc);
    if ( !(_DWORD)result )
    {
      result = _pm_runtime_resume(a1 + 16, 4);
      if ( (result & 0x80000000) != 0 )
      {
        v5 = *(_DWORD *)(a1 + 496);
        do
        {
          if ( !v5 )
            break;
          _X12 = (unsigned int *)(a1 + 496);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v12 = __ldxr(_X12);
            if ( v12 != v5 )
              break;
            if ( !__stlxr(v5 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v12 == v5;
          v5 = v12;
        }
        while ( !_ZF );
      }
      else
      {
        clk_lucid_evo_pll_configure(&cam_cc_pll0, v3, &cam_cc_pll0_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll1, v3, &cam_cc_pll1_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll2, v3, &cam_cc_pll2_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll3, v3, &cam_cc_pll3_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll4, v3, &cam_cc_pll4_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll5, v3, &cam_cc_pll5_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll6, v3, &cam_cc_pll6_config);
        clk_lucid_evo_pll_configure(&cam_cc_pll7, v3, &cam_cc_pll7_config);
        regmap_update_bits_base(v3, 135944, 1, 1, 0, 0, 0);
        regmap_update_bits_base(v3, 136088, 1, 1, 0, 0, 0);
        regmap_update_bits_base(v3, 136080, 1, 1, 0, 0, 0);
        regmap_update_bits_base(v3, 136036, 1, 1, 0, 0, 0);
        regmap_update_bits_base(v3, 136040, 1, 1, 0, 0, 0);
        regmap_write(v3, 135924, 193);
        v4 = qcom_cc_really_probe(a1 + 16, &cam_cc_canoe_desc, v3);
        if ( v4 )
          dev_err_probe(a1 + 16, v4, "Failed to register CAM CC clocks\n");
        else
          dev_info(a1 + 16, "Registered CAM CC clocks\n");
        _pm_runtime_idle(a1 + 16, 4);
        return v4;
      }
    }
  }
  return result;
}
