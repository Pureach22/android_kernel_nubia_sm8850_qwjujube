unsigned __int64 __fastcall cam_cc_alor_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  unsigned int v4; // w8
  unsigned int v11; // w10
  int v12; // w0
  unsigned int v13; // w20

  result = qcom_cc_map(a1, &cam_cc_alor_desc);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = result;
    result = qcom_cc_runtime_init(a1, &cam_cc_alor_desc);
    if ( !(_DWORD)result )
    {
      result = _pm_runtime_resume(a1 + 16, 4);
      if ( (result & 0x80000000) != 0 )
      {
        v4 = *(_DWORD *)(a1 + 496);
        do
        {
          if ( !v4 )
            break;
          _X12 = (unsigned int *)(a1 + 496);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v11 = __ldxr(_X12);
            if ( v11 != v4 )
              break;
            if ( !__stlxr(v4 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v11 == v4;
          v4 = v11;
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
        v12 = qcom_cc_really_probe(a1 + 16, &cam_cc_alor_desc, v3);
        if ( v12 )
        {
          v13 = v12;
          dev_err(a1 + 16, "Failed to register CAM CC clocks ret=%d\n", v12);
          return v13;
        }
        else
        {
          _pm_runtime_idle(a1 + 16, 4);
          dev_info(a1 + 16, "Registered CAM CC clocks\n");
          return 0;
        }
      }
    }
  }
  return result;
}
